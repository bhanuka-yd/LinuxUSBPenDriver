#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>


//probe function
//called on devie insertion if and only if no other driver has beat us to the punch
static int pen_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
	printk(KERN_INFO "USB-Stick (%04X:%04X) plugged in\n",id->idVendor,id->idProduct);
	return 0;//return 0 indicates that this driver will manage this device.
}

//disconnect function
static void pen_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "USB-Stick Removed");
}

//USB device ID
static struct usb_device_id pen_table[] = {
	//0951:16a1
	{USB_DEVICE(0x0951,0x16a1)},
	{}
	// {} Terminates the Query
};

MODULE_DEVICE_TABLE(usb,pen_table);
//usb driver
static struct usb_driver pen_driver = 
{
	.name = "USB-Stick Driver",
	.id_table = pen_table,//Supported usb Device IDS
	.probe = pen_probe,
	.disconnect = pen_disconnect,
};

static int __init pen_init(void){

	int ret=-1;
	printk(KERN_INFO "USB-Stick Constructor of the Driver");
	printk(KERN_INFO "\tRegistering Driver with Kernel");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "\tRegistration is Complete");
	return ret;

}

static void __exit pen_exit(void){

	//deregister
	printk(KERN_INFO "USB-Stick Destructor of the Driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tUnregistration Complete");
}

module_init(pen_init);
module_exit(pen_exit);

MODULE_LICENSE("GPL");
