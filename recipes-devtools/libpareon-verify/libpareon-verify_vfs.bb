require conf/distro/include/pareon.inc

DESCRIPTION = "Pareon Verify shared library"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

# Sabotage the default dependencies to avoid dependency loops trying to build lowlevel recipes with pareon
INHIBIT_DEFAULT_DEPS = "1"

SRC_URI += "file://pareon_run.in"

do_compile() {
    awk -v PAREON_LIBDIR=${PAREON_LIBDIR} '{gsub(/@@PAREON_LIBDIR@@/, PAREON_LIBDIR); print}' < ${WORKDIR}/pareon_run.in > ${WORKDIR}/pareon_run
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/pareon_run ${D}${bindir}

    # copy libpareon_verify and libstdc++
    install -d ${D}${PAREON_LIBDIR}
    cp -a ${PAREON_LIBDIR}/* ${D}${PAREON_LIBDIR}
    cp -a ${PAREON_CXXDIR}/* ${D}${PAREON_LIBDIR}
}
