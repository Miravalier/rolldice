# Kbuild compatibility check
ifneq ($(KERNELRELEASE),)
include Kbuild
else

KDIR ?= /lib/modules/`uname -r`/build

all:
	$(MAKE) -C $(KDIR) M=$$PWD modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

endif
