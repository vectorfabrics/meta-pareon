PAREON_PRODUCT = "verify"

require libpareon.inc

FILES_${PN} += "${PAREON_INSTALLDIR}/libstdc++.so.*"

do_install_append() {
    ln -s pareon_verify_run.sh ${D}${bindir}/pareon_run.sh
    install -m 0755 ${PAREON_CXXDIR}/libstdc++.so.* ${D}${PAREON_INSTALLDIR}
}
