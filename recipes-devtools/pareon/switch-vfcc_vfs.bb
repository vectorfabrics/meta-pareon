DESCRIPTION = "Pareon cross-compilation script"
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_DIR}/EULA.exec;md5=1c43b59db6eab4e68de95551563c708b"

inherit cross

SRC_URI += "file://switch_vfcc.template"

do_compile() {
    awk -v  CC="${TARGET_SYS}-gcc ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        -v CXX="${TARGET_SYS}-g++ ${TUNE_CCARGS} --sysroot=${STAGING_DIR_TARGET}" \
        '{gsub(/@@CC@@/, CC); gsub(/@@CXX@@/, CXX); print}' < ${WORKDIR}/switch_vfcc.template > ${WORKDIR}/switch_vfcc
}

do_install() {
    # copy wrapper script
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/switch_vfcc ${D}${bindir}
    ln -s ${D}${bindir}/switch_vfcc ${D}${bindir}/switch_vf++
}

