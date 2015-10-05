# Paths and triplets for the pareon compiler

# soft-float arm target
#PAREON_ARCH_arm = "arm-linux-gnueabi"

PAREON_ARCH_arm = "arm-linux-gnueabihf"
PAREON_ARCH_x86 = "i686-linux-gnu"
PAREON_ARCH_x86-64 = "x86_64-linux-gnu"
PAREON_ARCH ?= "invalid"

PAREON_VERSION ?= "2.24"
PAREON_PRODUCT ?= "verify"

PAREON_DIR = "/opt/vectorfabrics/pareon-${PAREON_VERSION}/${PAREON_PRODUCT}"
PAREON_BINDIR = "${PAREON_DIR}/${PAREON_ARCH}/bin"
PAREON_LIBDIR = "${PAREON_DIR}/${PAREON_ARCH}/lib"
PAREON_CXXDIR = "${PAREON_DIR}/c++/${PAREON_ARCH}/lib"

PATH_append = ":${PAREON_BINDIR}"

export ARM_TOOLCHAIN="${STAGING_DIR_HOST}${prefix}"
export ARM_SYSROOT="${STAGING_DIR_HOST}"
export ARM_HF_TOOLCHAIN="${STAGING_DIR_HOST}${prefix}"
export ARM_HF_SYSROOT="${STAGING_DIR_HOST}"
export VF_TARGET_TRIPLE="${TARGET_SYS}"
export VFCC_CONFIG="${PAREON_DIR}/tools/config/c++.conf"

