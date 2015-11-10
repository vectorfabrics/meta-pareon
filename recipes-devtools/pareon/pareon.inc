# soft-float arm target
#PAREON_ARCH_arm = "arm-linux-gnueabi"

PAREON_ARCH_arm = "arm-linux-gnueabihf"
PAREON_ARCH ?= "invalid"

PAREON_VERSION ?= "2.25"
PAREON_LOGFILE ?= ""
PAREON_ERRFILE ?= ""
PAREON_TIMEOUT ?= "5m"

PAREON_DIR = "/opt/vectorfabrics/pareon-${PAREON_VERSION}/${PAREON_PRODUCT}"
PAREON_BINDIR = "${PAREON_DIR}/bin"
PAREON_LIBDIR = "${PAREON_DIR}/${PAREON_ARCH}/lib"
PAREON_CXXDIR = "${PAREON_DIR}/c++/${PAREON_ARCH}/lib"
