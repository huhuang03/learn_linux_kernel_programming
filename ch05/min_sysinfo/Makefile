ifeq ($(ARCH),arm)
	KDIR ?= ../../rpi_work/kernel_rpi/linux
else
	KDIR ?= /lib/modules/$(shell uname -r)/build
endif

PWD := $(shell pwd)
obj-m += min_sysinfo.o
EXTAR_CFLAGS += -DDEBUG

all:
	@echo
	@echo '--- Building : KDIR=${KDIR} ARCH=${ARCH} CROSS_COMPILE=${CROSS_COMPILE} EXTAR_CFLAGS=${EXTAR_CFLAGS}'
	@echo
	make -C $(KDIR) M=$(PWD) modules

install:
	@echo
	@echo "--- instaling ---"
	@echo " [First, invoke the 'make' ]"
	make
	@echo
	@echo " [Now for the 'sudo make install' ]"
	sudo make -C $(KDIR) M=$(PWD) modules_install
	sudo depmod

clean:
	echo $(KDIR)
	make -C $(KDIR) M=$(PWD) clean