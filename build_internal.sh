#!/bin/sh
set -e
echo if this does not run, try doing "source build.sh" instead of ./build.sh


echo Configuring EDK2....

export PATH=~/bin/bin:$PWD/userland/sdk/usr/bin:$PATH
export WORKSPACE=`pwd`/../edk2
export PACKAGES_PATH=$WORKSPACE:$PWD
pushd $PWD
cd $WORKSPACE
. edksetup.sh
popd

echo Configuring and compiling zoidberg kernel

./genversion.sh
build -a X64 -p kernel.dsc

cp -Rv $WORKSPACE/build/* build/

echo Building userland

make -C userland -j

echo Building bootable image

dd if=/dev/zero of=boot.img bs=1M count=33
/sbin/mkfs.vfat boot.img -F 32
mmd -i boot.img ::/EFI
mmd -i boot.img ::/EFI/BOOT
mcopy -i boot.img build/zoidberg/DEBUG_GCC46/X64/kernel.efi ::/EFI/BOOT
mcopy -i boot.img $WORKSPACE/Build/OvmfX64/DEBUG_GCC46/X64/Shell.efi ::/EFI/BOOT/BOOTX64.EFI
mcopy -i boot.img build/zoidberg/DEBUG_GCC46/X64/SimpleThread.efi ::/EFI/BOOT
mcopy -i boot.img startup.nsh ::/

echo Building initrd
dd if=/dev/zero of=initrd.img bs=1M count=33
/sbin/mkfs.vfat initrd.img -F 32
mmd -i initrd.img ::/sbin
mcopy -i initrd.img userland/build/* ::/
