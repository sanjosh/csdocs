
# CPU levels

CPU privilege levels (exception level)
* user level EL0
* kernel levels EL1
* virtualization EL2

Software running in EL2 can configure the hardware to support VMs.

The VM will then execute normally in EL0 and EL1 until some condition 
is reached that requires intervention of the hypervisor. 
At this point, the hardware traps into EL2 giving control to the hypervisor

# memory virtualization

software in EL2 points to a set of page tables, Stage-2 page tables, 
used to translate the VM’s view of physical addresses to machine addresses. 

When Stage-2 translation is enabled, the ARM architecture defines three address spaces: 
1. Virtual Addresses (VA), 
2. Intermediate Physical Addresses (IPA), and 
3. Physical Addresses (PA). 

Stage-2 translation, configured in EL2, translates from IPAs to PAs

# interrupt virtualization

virtualization extensions to the ARM Generic Interrupt Controller (GIC) architecture,

enabling and disabling virtual interrupts must be done in EL2. 

Furthermore, all physical interrupts are taken to EL2 when running in a VM, and therefore must be handled
by the hypervisor.

# virutal timer

configured by the VM without trapping to the hypervisor.

raises physical interrupt which must be handled by hypervisor

# type 1 (Xen) vs type 2 (Kvm) hypervisors

key differences in how ARM support Type 1 and Type 2 hypervisors

While ARM virtualization extensions are centered around a separate CPU
mode, x86 support provides a mode switch, root vs. non-root
mode, completely orthogonal from the CPU privilege rings.

While ARM’s EL2 is a strictly different CPU mode with its
own set of features, x86 root mode supports the same full
range of user and kernel mode functionality as its non-root
mode. 

Both ARM and x86 trap into their respective EL2 and root modes, 
but transitions between root and non-root mode on x86 are implemented 
with a VM Control Structure (VMCS) residing in normal memory, 
to and from which hardware state is automatically saved and 
restored when switching to and from root mode, for example when the
hardware traps from a VM to the hypervisor. 

ARM, being a RISC-style architecture, instead has a simpler hardware
mechanism to transition between EL1 and EL2 but leaves it
up to software to decide which state needs to be saved and
restored.

# experiments

1. hypercall
2. Interrupt controller trap
3. virtual IPI
4. Virtual IRQ completion
5. VM switch
6. IO latency out/in

2016 paper
https://www.cs.columbia.edu/~nieh/pubs/isca2016_armvirt.pdf
