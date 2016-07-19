# LinuxUSBPenDriver
This is a Hello World Linux USB Driver for a Pen Drive

#How to Make the Module

Run "sudo make -C /lib/modules/$(uname -r)/build/ M=$(pwd)" to make the module
Then use "insmod" and "rmmod" commands to add and remove the module to the kernel
