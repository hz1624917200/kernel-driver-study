ifneq ($(KERNELRELEASE),)
	obj-m := panic_test.o
else
	KERN_DIR ?= /home/zheng/Temp/osFuzz/4.19.90-24.4.v2101.ky10.x86_64
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
endif
clean:
	rm -rf *.o *.o.d *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order *.mod Module.symvers