ifneq ($(KERNELRELEASE),)
	obj-m := panic_test.o
else
	KERN_DIR ?= /usr/src/linux-headers-$(shell uname -r)/
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
endif
clean:
	rm -rf *.o *.o.d *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order *.mod Module.symvers