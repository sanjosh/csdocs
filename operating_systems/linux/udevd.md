
# Down The udev Rabbit Hole

(https://timocharis.com/help/udev.html)

The current method of device node management, udev, is part of the "new linux" that just works, except when it doesn't. Mostly it does, and if you're a casual linux user there will generally be no need for you to mess with it or -- more to the point -- to let it mess with you.

But if you're more inclined to do things your way, or wish to run a small-footprint fast system without Gnome or KDE, you'll probably have to come to terms with udev. The primary issue will be setting up persistent storage and net rules so you can reliably mount removable storage and predictably use multiple net devices from the same computer.

You might also be one of the unlucky few that have problems with a whitebread install of your favorite distro. If so, and if you hate fussing, consider trying a different distro as an alternative to confronting this mess. It's highly unlikely that any two setups will behave in the same way, so if Ubuntu doesn't work, Fedora just might. Testing and analysis for this document was mostly done on Ubuntu Lucid, with some supplemental comparison to Debians Lenny and Squeeze. Do not assume it will behave the same on any other system, since it probably won't.

Diving into udev should not be done lightly. Documentation is generally incomplete and out of date, so you'll probably be spending some time fussing with it. Hopefully, we can cut that time down a bit.

This is not a blanket indictment of udev, which does offer some improvements over previous setups. To some extent, the poor documentation can be excused: udev interoperates with various other subsystems such as hal (deprecated) or udisks (not yet ready for prime time), dbus, autofs, etc... often in unpredictable ways. It's not clear anyone knows exactly what it's going to do at any given time. Usually, I don't.

There has been at least one notable change: udevinfo is no longer available. It's replace by "udevadm info" with similar (if not identical) options. So if you're looking through other documentation and see udevinfo, just make the subsitution and it should still work as expected.

You will interact with udev mostly by writing rules. Before you can start, you'll need to know where they go and how to name them.

## Rule Location, File Names and "Lexical Order"

Your system-specific rules should be placed in /etc/udev/rules.d/ with the suffix ".rules" -- my sample is called "cardreader.rules" for example. If you carefully decipher man udev, you'll find they suggest using a format such as 75-cardreader.rules with the number in front. This is because rules are parsed in "lexical order" regardless of their location. The distro-installed rules will be in /lib/udev/rules.d normally, and will be parsed according to the numbers in the filename. "Lexical order" is a somewhat meaningless phrase. It implies alphanumeric order without saying so explicitly, and means literally any recursive algorithmic sorting order.

Exactly which lexical order is not defined, though it is implied that the numbers are read from lower to higher, and the last rule executed wins if there is a conflict. If two rules have the same number, the one in /etc/udev should override the one in /lib/udev. Names should be unique. You're unlikely to accidentally duplicate a name from /lib/udev/rules.d/ but if you do, you'll simply override it completely. (Everything in this paragraph has been confirmed by testing on real systems).

The most important thing to remember: in any conflict, the last rule wins.

Testing also shows that the lexical order is numbers from lower to higher, then capital letters in alphabetic order, then lower-case letters from a to z. That means if you wish to guarantee your rule is handled last, you can simply skip the number portion of the name to win over all system rules. It's probably best to avoid any non-alphanumeric symbols as the first character; dotfiles will not be parsed at all, for example, and no other symbols have been tested here.

## Testing Your Rules

There is only one certain way to test your rules, and that's to reboot.

You can try "udevadm control --reload rules" but it doesn't work on my system. Actually, the man page says udev should spot any changes you make to files and implement them without any prompting, but that doesn't work in practice.

You can also try "udevadm trigger" (the optional flag --verbose is a good idea) but it will yeild unpredictable results. In particular, it will not eliminate any device nodes that were previously created, so your /dev can end up in a very strange state.

You might get some useful information from "udevadm test [path to device in sys]" but it's not all that simple to analyze the spew.

In the end, only a reboot is reliable.

## udev, Persistent Storage & Multi-card Readers

For anyone who joined the game late, there is a unique problem regarding multicard readers and udev: they don't generate an OS event when you plug in a card. From the computer's point of view, nothing happened. Therefore, without polling the reader's slots to see if there's a card present, udev has no way to know if there's a need for a new device file in /dev. This was previously handled by hald-addon-storage which would start a daemon to poll each device (a separate daemon for each slot of a multicard reader, for example). If it spotted something, it would signal udev to create the appropriate device.

## Creating Device Nodes With udev

An easy solution is to just create the devices before they're needed and manually mount the cards when you insert them.

You can force udev to create device nodes at bootup by placing special files in the /lib/udev/devices/ directory. You'll do this by using the mknod utility. In general, card readers will be mounted as scsi devices such as /dev/sdb, /dev/sdc etc. You can home in on which devices are your card reader using dmesg; they will generally be listed as "Attached SCSI removable disk". So, you should be able to run "dmesg | grep SCSI" and get a workable list. In my case, they are listed as [sdb][sdc][sdd] and [sde]. If you check your /dev directory, you'll see these devices all exist as /dev/sdb etc. So what's the problem?

There are no partition nodes for any of those devices. At the very least, your SD card or memory stick or whatever will have one partition you want to address. On device /dev/sdb, that would show up as /dev/sdb1 -- and that's what you want to put in your /etc/fstab. So you need to make it.

The mknod utility requires a name (sdb1) a type (b for block) and a major and minor device number. You can optionally specify a permissions mode with the -m option plus a four-number mode such as 0644. In this case, the command would be:

mknod sdb1 b 8 17 (note you don't need to name it /dev/sdb1)

So where did I get the major and minor numbers? You'll find them in your kernel source directory under Documentation/devices.txt -- you have a recent kernel source handy, right? If not, you can score at http://www.kernel.org/pub/linux/docs/device-list/

A caution: the device itself will be the first number listed. So if you search the device list for /dev/sd and find sdb, you'll note its major number is block 8 (that's fine) and the minor numbers are 16-31 (because sdc starts with 32). However, the device itself (/dev/sdb) has the minor number 16; the first partition (dev/sdb1) gets the minor number 17. The second partition (dev/sdb2) gets 18, etc. An off-by-one error is entirely too possible here.

You can then make however many nodes you wish in the /lib/udev/devices directory and after a reboot, they will all be present in /dev. At that point, you can mount the various SD cards they represent using the appropriate mount command, or even place the entry in fstab.

But it can't be that easy, can it? Nope. There's a problem.

Without intervention from Hal or any other automated setup, I've been using a set of udev rules to create the devices for a multicard reader for years:

KERNEL=="sd[b-g]", SUBSYSTEMS=="scsi", ATTRS{model}=="*SD*", NAME{all_partitions}="sdx"
KERNEL=="sd[b-g]", SUBSYSTEMS=="scsi", ATTRS{model}=="*MS*", NAME{all_partitions}="stk"
KERNEL=="sd[b-g]", SUBSYSTEMS=="scsi", ATTRS{model}=="*CF*", NAME{all_partitions}="scf"
KERNEL=="sd[b-g]", SUBSYSTEMS=="scsi", ATTRS{model}=="*SM*XD*", NAME{all_partitions}="smx"
KERNEL=="sd[b-g]", SUBSYSTEMS=="usb", ATTRS{idVendor}=="04fc", ATTRS{idProduct}=="0171", NAME{all_partitions}="vid"

All five lines do basically the same thing, so let's just go through the first as a sort of tour of udev rules. But we can't just dive in without explaining where this rule goes and how it's named.

Each rule has two basic parts: first, home in on a device by matching various attributes, then do something. Each statement is delineated by a comma, and each rule goes entirely on one line. More than one rule can apply to a single device.

The two parts of the rule can be distinguished by the operator used. The double equal (==) means "compare for equality" and bang equal (!=) "compare for inequality."

Actions will be shown by the symbols = (set this value), += (add this value), or := (set this value and no further values. It's a lock, basically). Some keynames can only be used for comparisons (KERNEL, for example) while others can be used both to compare or to assign (NAME, for example). For the list on your system, see man udev. Don't be surprised if you see others somewhere -- man udev is certainly syntactically incomplete so it would not be surprising if some keynames are missing.

So, the first comparison (KERNEL=="sd[b-g]") means find a device that the kernel thinks is /dev/sdb, sdc, sdd, sde, sdf or sdg, which is consistent with typical regexp rules. There's no sda because that's always the single main hard drive on this system, which should be left alone. It's unlikely the card readers will ever appear above sdg, but you could just as easily use sd* rather than sd[b-g] and get a good result. It's just not as careful.

SUBSYSTEMS=="scsi" works in the same way as the previous test, and is probably redundant. In other words, if it's sd(a-g) it's a scsi device. But this does delimit the device a little more in mysterious ways that will be explained later.

The next match, ATTRS, takes a parameter {model}. A device can have any number of ATTRS (attributes) so you'll have to home in on which one(s) you want to use. In this case, something unique to that particular slot of my multicard reader: it's the SD card slot. Note that typical regexps can be used for any of these matches. In testing, they've turned out to be a little unpredictable, so you might have to mess with this a bit to find an exact match. Or, sometimes, it may just fail -- udev works in mysterious ways.

At this point, udev should know which hardware device (as the kernel sees it) is to be fussed with. The last section describes the change to make, and is by far the most interesting.

NAME{all_partitions}="sdx" is literally descriptive. It takes the located device, which could be any of the sd[b-g] group, and renames it as sdx. It will also create all possible partitions for that device (1-15) and name them appropriately (sdx1, sdx2 ...) Here's the important part: it will do that no matter what the initial device's name was: sdb, sdc, whatever. The first partition (your most likely candidate on a memory card) will be sdx1, and you can make an fstab entry to that effect. It will work every time, even if the scsi device minor numbers shift around at boot.

Way cool, right? Can it be that simple?

Of course not. This is udev. However, for the moment, it does work on some systems -- but there's no telling when it will stop.

## NAME Is Deprecated

First, if you peruse man udev, you'll soon note there's absolutely nothing that implies you can use the NAME function with a parameter such as {all_partitions}. In fact, it describes all_partitions as being one of the OPTIONS, not addressable by the NAME function. Actually, man udev does nothing to explain syntax or how to build a rule. That would be "telling." This is part of the "new linux" where, you know, if you tell users how things work, they might actually use them.

If you follow the party line, you would instead replace that simple statement with something like OPTIONS="all_partitions", SYMLINK="sdx%n" and in theory you might get sd(kernelname)1-15 and symlinks from sdx(1-15) to sd(kernelname)1-15. (kernelname refers to the letter and number the kernel would use for the device, such as /dev/sdb1, not the name of the kernel you're running). The %n is an allowable subsitution for the partition number. What you do get, though, is sd(whatever)1-15 and a single symlink from sdx to sd(kernelname) with no partition symlinks at all. If you try to get clever and put in another rule matching KERNEL="sd[b-g]%n, that also fails. We'll get to that.

So it's useless for our purposes.

Why do you care? Because, according to rumor, the NAME function is deprecated in later versions of udev, and you never know when the practical jokes department will decide it just has to update udev. Second, because many a newer version of udev will fall flat on its face when you try to use NAME{all_partitions). It basically fails the same way SYMLINK does elsewhere. So the future is: all methods are futile except for simply creating the partitions yourself.

## NAME vs SYMLINK

What's the difference between NAME and SYMLINK? When you NAME all the partitions, it creates all the device nodes for /dev/sdx(1-15) but does not create device nodes called sd(kernelname). When you use the latter setup with OPTIONS and SYMLINK, it creates the kernelname devices, and symlinks to those device nodes. Or rather, in reality, only links to the device itself and ignores the partitions. This behavior, like any other udev characteristic, can change at any moment.

However, NAME is not what it seems. Though your /dev directory will look quite different when you use NAME vs OPTIONS="all_partitions" your /sys directory will be the same either way. So if you NAME the partitions sdx, when you go to /sys you won't find any sdx under /sys/block. Clearly, NAME simply creates a pointer at some lower level than the /dev directory. The kernel can mount it, but does not export sdx to the sys directory, at least nowhere that "find" can locate it.

Even more fun, whether you use the NAME function or the SYMLINK, you still get the sd(kernelname) in the /sys directory, and in neither case will it have any partitions assigned to it until you actually put a card in. You can observe this if you cd /sys/block and ls sda; you'll see all the partitions on your main disk listed. But if you ls sd(your card reader slot) you won't see any partitions, even though the device nodes have been created by either NAME or OPTIONS="all_partitions". The /sys directory doesn't seem to care what udev hath wrought.

In some way, that probably relates to the inability of udev to SYMLINK to the card reader partitions; /sys doesn't know they are there. The miracle is that NAME{all_partitions} works at all. Enjoy it while you have it.

## An Easier Problem: A USB Drive

When you plug in any typical USB device, including a portable USB flash drive, an event is generated that the kernel can see. A flurry of activity happens and, if all goes well, udev creates the necessary nodes for the device and any partitions found. Even better, this will show up in dmesg.

Using the same general technique, you can create rules for all your typical devices so you can generate workable fstab entries. The fourth rule shown in the list near the beginning is for such a device -- a video camera that acts like a USB storage device. In this case the ATTRS{idVendor}=="04fc" and ATTRS{idProduct} values identify the device, and we simply NAME all the partitions again.

Why not use SYMLINK here instead? Even though a partition is created, and even though sd(kernelname)1 is created, it still would only make a symlink to the device. There may be some way around this, but the solution is currently opaque. Meanwhile, NAME{all_devices} works quite well here too.

Ultimately, it would be simpler if the kernel and/or udev could be instructed somehow to reserve a device slot for a particular device and make static nodes at boot, but that facility is not apparent.

Nevertheless, for now, this will work fine. And the same technique can be used for just about any hotpluggable device.

## What About Network Devices?

Ethernet cards and other networking devices are a special case. You may, for example, know your primary ethernet device is eth0. So you try to get info on /dev/eth0 and, oops, there isn't any.

If you really want to write a custom rule for an ethernet device, don't despair because there's no device node. You can just use the path in from the /sys directory to trigger a udevadm search. Use something like this:

udevadm info -a -p /sys/class/net/eth0

...where -p means path and can also be written as --path=/sys/class/net/yourdevice.

Of course, you should use the current name of the device you want to write a rule for, and you might have to cast about a bit in /sys/class/net/ to find it.

Fortunately udev handles networking in a fairly predictable fashion and you're not likely to run into many problems that require a new rule. Typically, your problems will boil down to two things.

First, you might not like the order or name udev chooses for devices; you may for some reason (legacy scripts for example) wish to have a particular device on eth0 or whatever. You can do this by editing a file in /etc/udev/rules.d/ that's usually called 70-persistent-net.rules. Find the culprit in that file and change the NAME key to eth0. Make sure to reassign whatever was eth0 at the same time.

Second, you might have a laptop or other device that only addresses one ethernet device at a time, and you wish it to always appear as eth0 (or whatever). Whenever you plug in a new device it will add another entry and increment the eth(n) by one, and your networking might fail on the new device if you have assigned a fixed IP in /etc/networking. The simple solution is to edit every entry that appears in 70-persistent-net.rules to have the NAME eth0. This will cause no trouble at all as long as you only run one device at a time.

You might run into the same problem after copying a system from one partition to another, or using some kinds of upgrade, or copying a file from one system to the other. The attributes of the device are not necessarily locked, and udev might decide it's not the same device. In that case, it will reassign it as eth1 and your networking fails. Of course, you can just eliminate the old eth0 entry that no longer works and edit the new one to have NAME="eth0" and your problem is solved.

The persistent-net-rules file is therefore something you should habitually check any time your network mysteriously fails. You never know for sure when udev will impishly decide to reassign the device.

## How Do You Find Attributes To Match?

So you want to write your own rules and would like to know how to find ATTRS{idVendor} or whatever. Right now in Lucid this is very simple. Use:

udevadm info --attribute-walk --name=/dev/

If you're a little lazy and don't mind using undocumented flags, this variant does the same thing:

udevadm info -a -n /dev/

Part of the charm of man udev is it's blithe disregard for including short options. Fortunately, programmers tend to be unimaginative and the variants are fairly easy to guess. It would also be possible to peruse the source for them.

After you do this, you'll be presented with quite a load of information. There will be one block for each level in the /sys heirarchy, with different information in each. This is where "SUBSYTEMS" can come in handy: note the entry in any block that has information you think unique enough to be your identifier, and use that SUBSYSTEMS value in your rule, along with the unique information. This seems to work well; it's impossible to predict what udev will do so it's also impossible to say if this is the best approach or not. But it does work.

There is a significant bonus here -- note that the syntax used in the output from "udevadm info" is the same as that used in generating rules. You can just copy stuff, insert commas between them, and you're done!

## KERNEL/KERNELS and SUBSYSTEM/SUBSYSTEMS or Walking The Walk

By now you've probably glanced at man udev and you may have noticed that there are singular and plural variants of the match keys KERNEL(S) and SUBSYSTEM(S). Cryptically it says the singular variant will match "the name" of the device while the plural will search the "devpath upwards" for a matching device name.

Considering that udevadm -info will list quite a few names for any given device, it's not clear what "the name" would be, though a crude guess woud be the name the kernel assigns. Further, we have no real clue what the "devpath" is or which way is "upward." Again, educated guesses are possible, but for simplicity's sake it's easer to use a tautology instead: the output of udevadm -info.

If you use KERNEL or SUBSYSTEM, udev will only match against the first or top block of text it outputs. Conveniently, you'll note the listing in that block includes only the singular variants of each key.

If you use KERNELS or SUBSYSTEMS, udev will match against any of the subsequent blocks (that conveniently use the plural variant of the keys). But: it will only do this once. If you subsequently attempt another key match, it must be from blocks chosen by the value you included. For example, if you search on SUBSYSTEMS="scsi", all subsequent searches must be in blocks that were chosen by that search even though they are not the key SUBSYSTEMS. That will include the most popular key, ATTR{}. This is somewhat logical, but can be surprising if you simply choose attributes willy-nilly. The order within those chosen blocks does not appear to matter; if you have two blocks with SUBSYSTEMS="usb" it will match against either.

On the other hand, the singular variants KERNEL and SUBSYSTEM do not delimit any further searches within the udevadm --info output for any specific device. Delimitation within that heirarchy only starts with the first "plural" entry.

One other undocumented feature: searches against plural entries will not match information in the first output block (the one with singular entries). The reverse is also true, but since the plural is supposed to walk the heirarchy, it's easy enough to incorrectly presume this means all blocks. It does not. It means all but the first, and gives us a solid clue about which way is "upward": down, as you view the text.

## Another Common Way To Find Attributes

If you search the web, you'll probably run into this somewhat more complex method of finding device attributes. First you would use:

udevadm info -q path -n /dev/

...to tell you where a particular device is hiding in the /sys directory. Given that information, you can get its attributes by using:

udevadm info -a -p There's really no reason to go through all that. Some more creative folks recreated the method originally suggested by combining those two commands into:

udevadm info -a -p (udevadm info -q path -n /dev/)

...but at least on my system that no longer works. There's no obvious reason to use any of this any more, but it's included just in case you run into this technique and it fails for you: don't feel bad. It's a waste of time anyway.

## A Note About Device Node Names

When renaming a device node (or even creating a symlink) it's probably a good idea to avoid using names that might collide with a device you could add later. There's probably no completely safe way to do this, but there's an easy way that ought to work well enough: search the same "devices.txt" file that we used earlier to figure out the major and minor numbers for a node. It's normally located in your kernel source tree under the "Documentation" directory.

If you're using more, less, view, or any similar utility, just search using /dev/ and you should find something available fairly quickly. It's true that most utilities initiate a search using the / character, but don't worry about making sure it's in your search. Using dev/ will work fine. 

