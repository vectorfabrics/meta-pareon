# require this in your local.conf
# require conf/distro/include/pareon.inc

DESCRIPTION = "Pareon Verify shared library"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

# Sabotage the default dependencies to avoid dependency loops trying to build lowlevel recipes with pareon
INHIBIT_DEFAULT_DEPS = "1"

# Hide QA warning: "No GNU_HASH in the elf binary"
INSANE_SKIP_${PN} += "ldflags"

RDEPENDS_${PN} = "libstdc++ glibc libgcc"

SRC_URI += "file://pareon_run.sh.template"

FILES_${PN} += "${PAREON_LIBDIR}/libpareon.so.* ${PAREON_LIBDIR}/libstdc++.so.*"
FILES_${PN}-dbg += "${PAREON_LIBDIR}/.debug"

do_compile() {
    awk -v PAREON_LIBDIR=${PAREON_LIBDIR} '{gsub(/@@PAREON_LIBDIR@@/, PAREON_LIBDIR); print}' < ${WORKDIR}/pareon_run.sh.template > ${WORKDIR}/pareon_run.sh
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/pareon_run.sh ${D}${bindir}

    # copy libpareon and libstdc++
    install -d ${D}${PAREON_LIBDIR}
    cp -a ${PAREON_LIBDIR}/libpareon.so.* ${D}${PAREON_LIBDIR}
    cp -a ${PAREON_CXXDIR}/libstdc++.so.* ${D}${PAREON_LIBDIR}
}

