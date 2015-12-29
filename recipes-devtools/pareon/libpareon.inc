DESCRIPTION = "Pareon shared library"

require pareon.inc

# Sabotage the default dependencies to avoid dependency loops trying to build lowlevel recipes with pareon
INHIBIT_DEFAULT_DEPS = "1"

# Supress QA warning: "No GNU_HASH in the elf binary"
INSANE_SKIP_${PN} += "ldflags"

# libpareon.so dependencies
RDEPENDS_${PN} = "libstdc++ glibc libgcc"

SRC_URI += "file://pareon_run.sh.template"

FILES_${PN} += "${PAREON_INSTALLDIR}/libpareon*.so.*"
FILES_${PN}-dbg += "${PAREON_INSTALLDIR}/.debug"

do_compile() {
    awk -v PAREON_INSTALLDIR=${PAREON_INSTALLDIR} \
        '{gsub(/@@PAREON_INSTALLDIR@@/, PAREON_INSTALLDIR); print}' \
        < ${WORKDIR}/pareon_run.sh.template > ${WORKDIR}/pareon_${PAREON_PRODUCT}_run.sh
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/pareon_${PAREON_PRODUCT}_run.sh ${D}${bindir}

    # copy libpareon
    install -d ${D}${PAREON_INSTALLDIR}
    cp -a ${PAREON_LIBDIR}/libpareon*.so.* ${D}${PAREON_INSTALLDIR}
}
