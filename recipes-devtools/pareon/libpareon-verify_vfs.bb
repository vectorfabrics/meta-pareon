PAREON_PRODUCT = "verify"

require libpareon.inc

DESCRIPTION = "Pareon Verify shared library"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

FILES_${PN} += "${PAREON_LIBDIR}/libstdc++.so.*"

do_install_append() {
    ln -s pareon_verify_run.sh ${D}${bindir}/pareon_run.sh
    cp -a ${PAREON_CXXDIR}/libstdc++.so.* ${D}${PAREON_LIBDIR}
}
