DESCRIPTION = "VFrun shared library"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREONDIR}/${PAREON_ARCH}/lib/libvfrun.so.1.0.1;md5=1b247206afed4c7a1333f0e2ceb609d4"

PAREONPV ?= "${PV}"

PAREONDIR ?= "/opt/vectorfabrics/pareon-${PAREONPV}"

PAREON_ARCH_arm = "arm-linux-gnueabi"
PAREON_ARCH_x86 = "i686-linux-gnu"
PAREON_ARCH_x86-64 = "x86_64-linux-gnu"
PAREON_ARCH ?= "invalid"

# Sabotage the default dependencies to avoid dependency loops trying to build lowlevel recipes with pareon
INHIBIT_DEFAULT_DEPS = "1"

do_install() {
	install -d ${D}${libdir}
	cp -a ${PAREONDIR}/${PAREON_ARCH}/lib/lib* ${D}${libdir}
}


