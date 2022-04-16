# Kbuild compatibility check
ifneq ($(KERNELRELEASE),)
include Kbuild
else


KDIR ?= /lib/modules/`uname -r`/build

all: test
	$(MAKE) -C $(KDIR) M=$$PWD modules

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
	$(RM) test.o test

test.o: test.c
test: test.o


endif
