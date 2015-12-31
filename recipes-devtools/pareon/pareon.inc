LICENSE          = "Proprietary"
LIC_FILES_CHKSUM = "file://${PAREON_LICENSE};md5=1c43b59db6eab4e68de95551563c708b"

PAREON_ARCH_arm       = "arm-linux-gnueabi${ARMPKGSFX_EABI}"
PAREON_ARCH_x86       = "i686-linux-gnu"
PAREON_ARCH_x86-64    = "x86_64-linux-gnu"
PAREON_ARCH          ?= "invalid"

PAREON_FLAVOR_arm     = "libc221"
PAREON_FLAVOR_x86     = "libc215"
PAREON_FLAVOR_x86-64  = "libc215"
PAREON_FLAVOR        ?= "invalid"

PAREON_LOGFILE ?= ""
PAREON_ERRFILE ?= ""

# Install type:
#   opt for /opt/vectorfabrics/pareon-x.xx
#   dev for the development build install tree
PAREON_INSTALL_TYPE ?= "opt"

OVERRIDES .= ":pareon-${PAREON_INSTALL_TYPE}"

def get_latest_pareon():
    from os import listdir
    pareon_base_dir = "/opt/vectorfabrics"
    pareon_versions = [v.split("-")[1] for v in listdir(pareon_base_dir) if "pareon-" in v]
    return sorted(pareon_versions, key=float)[-1]

PAREON_VERSION_pareon-opt   ?= "${@get_latest_pareon()}"
PAREON_DIR_pareon-opt        = "/opt/vectorfabrics/pareon-${PAREON_VERSION}/${PAREON_PRODUCT}"
PAREON_LIBDIR_pareon-opt     = "${PAREON_DIR}/${PAREON_ARCH}/${PAREON_FLAVOR}/lib"
PAREON_CXXDIR_pareon-opt     = "${PAREON_DIR}/c++/${PAREON_FLAVOR}/${PAREON_ARCH}/lib"
PAREON_LICENSE_pareon-opt    = "${PAREON_DIR}/EULA.exec"
PAREON_INSTALLDIR_pareon-opt = "${PAREON_DIR}"

#PAREON_DIR_pareon-dev       = must be defined in local.conf
PAREON_LIBDIR_pareon-dev     = "${PAREON_DIR}/vfexec/${PAREON_PRODUCT}/${PAREON_ARCH}/${PAREON_FLAVOR}/lib"
PAREON_CXXDIR_pareon-dev     = "${PAREON_DIR}/vfcxx/${PAREON_PRODUCT}/c++/${PAREON_FLAVOR}/${PAREON_ARCH}/lib"
# The license is not in the install tree, so we use any one from a packaged version
PAREON_LICENSE_pareon-dev    = "/opt/vectorfabrics/pareon-2.25/verify/EULA.exec"
PAREON_INSTALLDIR_pareon-dev = "/opt/vectorfabrics/pareon-0.0/${PAREON_PRODUCT}"
