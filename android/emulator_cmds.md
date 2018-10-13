
# create AVD
android create avd -n <name> -t <targetID>

# AVDs stored in ~/.avd directory
# https://blahti.wordpress.com/2011/08/24/how-to-export-and-import-android-virtual-device-avd-files/

# list avds
emulator -list-avds

# run emulator
# https://developer.android.com/studio/run/emulator-commandline.html
emulator -wipe-data  -avd <name>

# list running devices
adb devices

# wait for device to start
adb wait-for -device 

# Install apk on emulator
adb -s emulator-5556 install -r <helloWorld.apk>

# start app using Activity Manager
adb shell am start -n <com.world.hello/com.world.hello.MainActivity>

# force stop app
adb shell am force-stop <com.world.hello>

# uninstall app using Package Manager
adb -s emulator-5556 shell pm uninstall <com.world.hello>
