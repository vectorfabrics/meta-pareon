TOOLCHAIN ??= "gcc"

# Change the compilers
CC_toolchain-pareon-verify   = "verify-vfcc"
CXX_toolchain-pareon-verify  = "verify-vf++"
CC_toolchain-pareon-profile  = "profile-vfcc"
CXX_toolchain-pareon-profile = "profile-vf++"

# These fallback to GCC if compilation fails.
CC_toolchain-pareon-verify-with-fallback   = "try-verify-vfcc"
CXX_toolchain-pareon-verify-with-fallback  = "try-verify-vf++"
CC_toolchain-pareon-profile-with-fallback  = "try-profile-vfcc"
CXX_toolchain-pareon-profile-with-fallback = "try-profile-vf++"

# We need to manually specify the GCC toolchain prefix otherwise cmake will not find the binutils programs.
EXTRA_OECMAKE_append_toolchain-pareon-verify                = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "
EXTRA_OECMAKE_append_toolchain-pareon-profile               = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "
EXTRA_OECMAKE_append_toolchain-pareon-verify-with-fallback  = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "
EXTRA_OECMAKE_append_toolchain-pareon-profile-with-fallback = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "

# Depend on the cross compiler and on libpareon
DEPENDS_prepend_toolchain-pareon-verify                 = "pareon-verify-cross libpareon-verify "
DEPENDS_prepend_toolchain-pareon-profile                = "pareon-profile-cross libpareon-profile "
DEPENDS_prepend_toolchain-pareon-verify-with-fallback   = "pareon-verify-cross libpareon-verify "
DEPENDS_prepend_toolchain-pareon-profile-with-fallback  = "pareon-profile-cross libpareon-profile "

OVERRIDES .= "${@['', ':toolchain-${TOOLCHAIN}']['${TOOLCHAIN}' != '']}"
OVERRIDES[vardepsexclude] += "TOOLCHAIN"
