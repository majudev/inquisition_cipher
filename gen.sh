#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR
TMPDIR=/tmp
while [ -e $TMPDIR ]; do
	TMPDIR=/tmp/inquisition-$RANDOM
done
mkdir $TMPDIR
cd $TMPDIR
$DIR/make32.sh
mkdir -p $TMPDIR/32/DEBIAN
mkdir -p $TMPDIR/32/usr/lib/i386-linux-gnu
mkdir -p $TMPDIR/32/usr/share/doc/libinquisition
cp $DIR/misc/control-32 $TMPDIR/32/DEBIAN/control
cp $DIR/lib/libinquisition.so $TMPDIR/32/usr/lib/i386-linux-gnu
cp $DIR/misc/copyright $TMPDIR/32/usr/share/doc/libinquisition/copyright32
fakeroot dpkg -b 32
cp $TMPDIR/32.deb $DIR
dpkg-name $DIR/32.deb
$DIR/make.sh
mkdir -p $TMPDIR/64/DEBIAN
mkdir -p $TMPDIR/64/usr/lib/x86_64-linux-gnu
mkdir -p $TMPDIR/64/usr/share/doc/libinquisition
cp $DIR/misc/control-64 $TMPDIR/64/DEBIAN/control
cp $DIR/lib/libinquisition.so $TMPDIR/64/usr/lib/x86_64-linux-gnu
cp $DIR/misc/copyright $TMPDIR/64/usr/share/doc/libinquisition/copyright64
fakeroot dpkg -b 64
cp $TMPDIR/64.deb $DIR
dpkg-name $DIR/64.deb
mkdir -p $TMPDIR/dev/DEBIAN
mkdir -p $TMPDIR/dev/usr/include
mkdir -p $TMPDIR/dev/usr/share/doc/libinquisition
cp $DIR/misc/control-dev $TMPDIR/dev/DEBIAN/control
cp $DIR/include/inquisition_cipher.hpp $TMPDIR/dev/usr/include
cp $DIR/include/inquisition.hpp $TMPDIR/dev/usr/include
cp $DIR/misc/copyright $TMPDIR/dev/usr/share/doc/libinquisition/copyright-dev
fakeroot dpkg -b dev
cp $TMPDIR/dev.deb $DIR
dpkg-name $DIR/dev.deb
cd $DIR
rm -r $TMPDIR
