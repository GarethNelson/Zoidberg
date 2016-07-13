OVMFPATH=/home/gareth/edk2/Build/OvmfX64/DEBUG_GCC46/FV
INCLUDES=-Inewlib/newlib/libc/include -Iefilibc/efi/inc -Iefilibc/efi/inc/protocol -Iefilibc/efi/inc/x86_64 -Ilwip/src/include/
ROMPATH=/usr/lib/ipxe/qemu/efi-e1000.rom

LWIPDIR=lwip/src

CC=x86_64-w64-mingw32-gcc
CFLAGS=-ffreestanding ${INCLUDES}

include lwip/src/Filelists.mk

all: BOOTX64.EFI boot.img lwip

LWIPFILES=${COREFILES} ${CORE4FILES} ${APIFILES} ${NETIFFILES} ${LWIPDIR}/netif/ethernetif.c

LWIPOBJS = $(patsubst %.c,%.o,$(LWIPFILES))


lwip: ${LWIPOBJS}

genversion:
	./genversion.sh

k_thread.o: k_thread.c cr.c cr.h
	x86_64-w64-mingw32-gcc -ffreestanding ${INCLUDES} -c $< -o $@

k_network.o: k_network.c
	x86_64-w64-mingw32-gcc -ffreestanding ${INCLUDES} -c $< -o $@

k_heap.o: k_heap.c
	x86_64-w64-mingw32-gcc -ffreestanding ${INCLUDES} -c $< -o $@

k_main.o: k_main.c genversion
	x86_64-w64-mingw32-gcc -ffreestanding ${INCLUDES} -c $< -o $@

kmsg.o: kmsg.c
	x86_64-w64-mingw32-gcc -ffreestanding ${INCLUDES} -c $< -o $@

efilibc/efilibc.a:
	make -C efilibc


newlib/build/x86_64-zoidberg/newlib/libc.a:
	mkdir -p newlib/build
	cd newlib/build; ../configure --target=x86_64-zoidberg
	CFLAGS=-nostdinc make -C newlib/build

BOOTX64.EFI:newlib/build/x86_64-zoidberg/newlib/libc.a  k_main.o kmsg.o k_heap.o k_network.o k_thread.o
	x86_64-w64-mingw32-gcc -nostdlib -Wl,-dll -shared -Wl,--subsystem,10 -e efi_main -o $@ kmsg.o k_thread.o k_heap.o k_network.o k_main.o newlib/build/x86_64-zoidberg/newlib/libc.a  -lgcc

boot.img: BOOTX64.EFI
	dd if=/dev/zero of=$@ bs=1M count=33
	/sbin/mkfs.vfat $@ -F 32
	mmd -i $@ ::/EFI
	mmd -i $@ ::/EFI/BOOT
	mcopy -i $@ BOOTX64.EFI ::/EFI/BOOT

boot_hdd.img: boot.img
	mkgpt -o boot_hdd.img --image-size 4096 --part $^ --type system

boot.iso: boot.img
	cp $^ iso
	xorriso -as mkisofs -R -f -e boot.img -no-emul-boot -o boot.iso iso

run-qemu:
	qemu-system-x86_64 -bios ${OVMFPATH}/OVMF.fd -usb -usbdevice disk::boot.img -netdev user,id=mynet0,net=192.168.76.0/24,dhcpstart=192.168.76.9 -device e1000,netdev=mynet0,mac=DE:AD:BE:EF:FC:E6  -m 1G -net dump,file=./dump.pcap -nographic -serial stdio 
