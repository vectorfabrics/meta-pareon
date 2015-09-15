#!/bin/sh

echo "require conf/distro/include/pareon.inc"
echo

for PN in $* ; do
	echo "DEPENDS_append_pn-${PN} = \" libpareon-verify\""
	echo "CC_pn-${PN}  = \"vfcc\""
	echo "CXX_pn-${PN} = \"vf++\""
	echo "LD_pn-${PN}  = \"vfld\""
	echo
done
