#!/bin/sh

echo -e "require conf/distro/include/pareon.inc"
echo

for PN in $* ; do
	echo -e "DEPENDS_append_pn-${PN} = \" libvfrun\""
	echo -e "CC_pn-${PN} \t= \"vfcc -B\${STAGING_BINDIR_TOOLCHAIN}\""
	echo -e "CXX_pn-${PN} \t= \"vf++ -B\${STAGING_BINDIR_TOOLCHAIN}\""
	echo -e "LD_pn-${PN} \t= \"vfld -B\${STAGING_BINDIR_TOOLCHAIN}\""
	echo
done
