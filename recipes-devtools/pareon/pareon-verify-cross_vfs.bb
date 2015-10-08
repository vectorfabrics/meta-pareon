PAREON_PRODUCT = "verify"

require pareon-cross.inc

DESCRIPTION = "Wrapper script for the Pareon Verify compiler"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

do_install_append() {
    ln -s verify-vfcc ${D}${bindir}/vfcc
    ln -s verify-vf++ ${D}${bindir}/vf++
}
