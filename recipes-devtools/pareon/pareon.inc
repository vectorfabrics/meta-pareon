# soft-float arm target
#PAREON_ARCH_arm = "arm-linux-gnueabi"

PAREON_ARCH_arm = "arm-linux-gnueabihf"
PAREON_ARCH_x86 = "i686-linux-gnu"
PAREON_ARCH_x86-64 = "x86_64-linux-gnu"
PAREON_ARCH ?= "invalid"

PAREON_VERSION ?= "2.24"
PAREON_LOGFILE ?= ""

PAREON_DIR = "/opt/vectorfabrics/pareon-${PAREON_VERSION}/${PAREON_PRODUCT}"
PAREON_BINDIR = "${PAREON_DIR}/bin"
PAREON_LIBDIR = "${PAREON_DIR}/${PAREON_ARCH}/lib"
PAREON_CXXDIR = "${PAREON_DIR}/c++/${PAREON_ARCH}/lib"