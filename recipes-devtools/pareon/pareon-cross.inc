DESCRIPTION = "Wrapper script for the Pareon compiler"

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
        -v TUNE="${TUNE_CCARGS}" \
        -v GCCDIR="${STAGING_BINDIR_TOOLCHAIN}" \
        -v INSTALLTYPE="${PAREON_INSTALL_TYPE}" \
        -v PRODUCT="${PAREON_PRODUCT}" \
        -v ARCH="${PAREON_ARCH}" \
        -v FLAVOR="${PAREON_FLAVOR}" \
        -v DIR="${PAREON_DIR}" \
        '{ \
          gsub(/@@LOG@@/, LOG); \
          gsub(/@@ERR@@/, ERR); \
          gsub(/@@TOOLCHAIN@@/, TOOLCHAIN); \
          gsub(/@@SYSROOT@@/, SYSROOT); \
          gsub(/@@TRIPLE@@/, TRIPLE); \
          gsub(/@@CONFIG@@/, CONFIG); \
          gsub(/@@TUNE@@/, TUNE); \
          gsub(/@@GCCDIR@@/, GCCDIR); \
          gsub(/@@INSTALLTYPE@@/, INSTALLTYPE); \
          gsub(/@@PRODUCT@@/, PRODUCT); \
          gsub(/@@ARCH@@/, ARCH); \
          gsub(/@@FLAVOR@@/, FLAVOR); \
          gsub(/@@DIR@@/, DIR); \
          print \
         }' \
        < ${WORKDIR}/vfcc.template > ${WORKDIR}/vfcc.template2

    # C compiler
    awk -v SUFFIX="cc" \
        -v FALLBACK="" \
        '{ \
          gsub(/@@SUFFIX@@/, SUFFIX); \
          gsub(/@@FALLBACK@@/, FALLBACK); \
          print \
         }' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vfcc

    # C compiler with GCC fallback
    awk -v SUFFIX="cc" \
        -v FALLBACK="1" \
        '{ \
          gsub(/@@SUFFIX@@/, SUFFIX); \
          gsub(/@@FALLBACK@@/, FALLBACK); \
          print \
         }' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/try-vfcc

    # C++ compiler
    awk -v SUFFIX="++" \
        -v FALLBACK="" \
        '{ \
          gsub(/@@SUFFIX@@/, SUFFIX); \
          gsub(/@@FALLBACK@@/, FALLBACK); \
          print \
         }' \
        < ${WORKDIR}/vfcc.template2 > ${WORKDIR}/vf++

    # C++ compiler with GCC fallback
    awk -v SUFFIX="++" \
        -v FALLBACK="1" \
        '{ \
          gsub(/@@SUFFIX@@/, SUFFIX); \
          gsub(/@@FALLBACK@@/, FALLBACK); \
          print \
         }' \
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
