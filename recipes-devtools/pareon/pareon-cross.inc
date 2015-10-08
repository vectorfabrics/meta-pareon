require pareon.inc

inherit cross

SRC_URI += "file://vfcc.template"

do_compile() {
    # common variables
    awk -v LOG="${PAREON_LOGFILE}" \
        -v ERR="${PAREON_ERRFILE}" \
        -v TIMEOUT="${PAREON_TIMEOUT}" \
        -v TOOLCHAIN="${STAGING_DIR_TARGET}${target_prefix}" \
        -v SYSROOT="${STAGING_DIR_TARGET}" \
        -v TRIPLE="${TARGET_SYS}" \
        -v CONFIG="${PAREON_DIR}/tools/config/c++.conf" \
        '{gsub(/@@LOG@@/, LOG); gsub(/@@ERR@@/, ERR); gsub(/@@TIMEOUT@@/, TIMEOUT); \
          gsub(/@@TOOLCHAIN@@/, TOOLCHAIN); gsub(/@@SYSROOT@@/, SYSROOT); \
          gsub(/@@TRIPLE@@/, TRIPLE); gsub(/@@CONFIG@@/, CONFIG); print}' \
        < ${WORKDIR}/vfcc.template > ${WORKDIR}/vfcc.template2

    # C compiler
    awk -v GCC="${TARGET_SYS}-gcc ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vfcc ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vfcc

    # C++ compiler
    awk -v GCC="${TARGET_SYS}-g++ ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        -v VFCC="${PAREON_BINDIR}/${PAREON_ARCH}-vf++ ${TUNE_CCARGS}" \
        '{gsub(/@@GCC@@/, GCC); gsub(/@@VFCC@@/, VFCC); print}' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vf++
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    cp -a ${WORKDIR}/vfcc ${D}${bindir}/${PAREON_PRODUCT}-vfcc
    cp -a ${WORKDIR}/vf++ ${D}${bindir}/${PAREON_PRODUCT}-vf++
    chmod +x ${D}${bindir}/${PAREON_PRODUCT}-vfcc
    chmod +x ${D}${bindir}/${PAREON_PRODUCT}-vf++
}
