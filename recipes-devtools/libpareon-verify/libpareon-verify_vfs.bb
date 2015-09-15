require conf/distro/include/pareon.inc

DESCRIPTION = "Pareon Verify shared library"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

# Sabotage the default dependencies to avoid dependency loops trying to build lowlevel recipes with pareon
INHIBIT_DEFAULT_DEPS = "1"

do_install() {
	install -d ${D}${libdir}
	cp -a ${PAREON_LIBDIR}/* ${D}${libdir}
}
