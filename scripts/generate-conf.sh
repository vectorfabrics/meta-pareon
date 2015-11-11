#!/bin/sh

for PN in $* ; do
	echo "TOOLCHAIN_pn-${PN} = \"pareon-verify\""
done
