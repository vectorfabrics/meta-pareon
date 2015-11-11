DESCRIPTION = "Wrapper script for the Pareon compiler"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

require pareon.inc

inherit cross

SRC_URI += "file://vfcc.template"

do_compile() {
    # common variables
    awk -v LOG="${PAREON_LOGFILE}" \
        -v ERR="${PAREON_ERRFILE}" \
        -v TOOLCHAIN="${STAGING_DIR_TARGET}${target_prefix}" \
        -v SYSROOT="${STAGING_DIR_TARGET}" \
        -v TRIPLE="${TARGET_SYS}" \
        -v CONFIG="${PAREON_DIR}/tools/config/c++.conf" \
        '{gsub(/@@LOG@@/, LOG); gsub(/@@ERR@@/, ERR); \
          gsub(/@@TOOLCHAIN@@/, TOOLCHAIN); gsub(/@@SYSROOT@@/, SYSROOT); \
          gsub(/@@TRIPLE@@/, TRIPLE); gsub(/@@CONFIG@@/, CONFIG); print}' \
        < ${WORKDIR}/vfcc.template > ${WORKDIR}/vfcc.template2

    # C compiler
    awk -v GCC="" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vfcc ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vfcc

    # C compiler with GCC fallback
    awk -v GCC="${TARGET_SYS}-gcc ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vfcc ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/try-vfcc

    # C++ compiler
    awk -v GCC="" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vf++ ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vf++

    # C++ compiler with GCC fallback
    awk -v GCC="${TARGET_SYS}-g++ ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vf++ ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/try-vf++
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    cp -a ${WORKDIR}/vfcc ${D}${bindir}/${PAREON_PRODUCT}-vfcc
    cp -a ${WORKDIR}/vf++ ${D}${bindir}/${PAREON_PRODUCT}-vf++
    cp -a ${WORKDIR}/try-vfcc ${D}${bindir}/try-${PAREON_PRODUCT}-vfcc
    cp -a ${WORKDIR}/try-vf++ ${D}${bindir}/try-${PAREON_PRODUCT}-vf++
    chmod +x ${D}${bindir}/${PAREON_PRODUCT}-vfcc
    chmod +x ${D}${bindir}/${PAREON_PRODUCT}-vf++
    chmod +x ${D}${bindir}/try-${PAREON_PRODUCT}-vfcc
    chmod +x ${D}${bindir}/try-${PAREON_PRODUCT}-vf++
}
