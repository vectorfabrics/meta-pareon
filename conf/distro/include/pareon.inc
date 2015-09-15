# Paths and triplets for the pareon compiler

PAREON_ARCH_arm = "arm-linux-gnueabi"
PAREON_ARCH_x86 = "i686-linux-gnu"
PAREON_ARCH_x86-64 = "x86_64-linux-gnu"

PAREON_ARCH ?= "invalid"

PAREONPV ?= "2.20"
PAREONDIR = "/opt/vectorfabrics/pareon-${PAREONPV}"

PATH_append = ":${PAREONDIR}/${PAREON_ARCH}/bin"

export ARM_TOOLCHAIN="${STAGING_DIR_HOST}${prefix}"
export ARM_SYSROOT="${STAGING_DIR_HOST}"
export VF_TARGET_TRIPLE="${TARGET_SYS}"

# export CFLAGS += "-B${STAGING_BINDIR_TOOLCHAIN}"
