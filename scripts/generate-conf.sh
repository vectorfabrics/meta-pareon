#!/bin/sh

for PN in $* ; do
	echo "DEPENDS_append_pn-${PN} = \" libpareon-verify\""
	echo "CC_pn-${PN}  = \"vfcc\""
	echo "CXX_pn-${PN} = \"vf++\""
	echo
done
