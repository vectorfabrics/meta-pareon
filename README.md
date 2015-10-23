Meta-pareon
================================

Introduction
-------------------------

The official OpenEmbedded/Yocto BSP layer for the VectorFabrics Pareon compiler.

The meta-pareon layer depends on:

    URI: git://git.openembedded.org/openembedded-core
    layers: meta
    branch: dizzy

Please follow the recommended setup procedures of your OE distribution. For Angstrom that is http://www.angstrom-distribution.org/building-angstrom, other distros should have similar online resources.


Usage
-------------------------

Add this layer to your layerstack the way you usually do, this differs between projects using OpenEmbedded. The steps should include updating conf/bblayers.conf. Please refer to the documenation of your project for the exact steps.

To (re)build recipes with the pareon compiler run the generator script:

    user@ubuntu-vm:/OE/sources/meta-pareon$ ./scripts/generate-conf.sh helloworld
    DEPENDS_append_pn-helloworld = " libpareon-verify"
    CC_pn-helloworld             = "vfcc"
    CXX_pn-helloworld            = "vf++"

The script accepts multiple recipe names:

    user@ubuntu-vm:/OE/sources/meta-pareon$ ./scripts/generate-conf.sh helloworld bash
    DEPENDS_append_pn-helloworld = " libpareon-verify"
    CC_pn-helloworld             = "vfcc"
    CXX_pn-helloworld            = "vf++"

    DEPENDS_append_pn-bash = " libpareon-verify"
    CC_pn-bash             = "vfcc"
    CXX_pn-bash            = "vf++"

Copy/paste the output into conf/local.conf.


Building cmake projects
-------------------------

Due to the way cmake tries to find the binutils executables, it is necessary to manually set the `_CMAKE_TOOLCHAIN_PREFIX` variable when building a project with the pareon compiler. You must add the following to your local.conf (replacing synergy with your cmake project):

    EXTRA_OECMAKE_append_pn-synergy = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "


Packages that do not work with Pareon
-------------------------

Several packages are known to refuse instrumentation. They are listed in the file BLACKLIST.md.


Analyzing programs on the target
-------------------------

Use the `pareon_run.sh` wrapper script to setup the necessary environment variables when analyzing programs on the target.

    pareon_run.sh program_name arguments


Using Pareon Profile
-------------------------

Default for the meta-pareon layer is to compile for Pareon Verify.
To use the Pareon Profile compiler and libraries, add `libpareon-profile` to your project's DEPENDS and change the compilers to `profile-vfcc` and `profile-vf++`:

    DEPENDS_append_pn-helloworld = " libpareon-profile"
    CC_pn-helloworld             = "profile-vfcc"
    CXX_pn-helloworld            = "profile-vf++"

Analyze the program on the target with:

    pareon_profile_run.sh program_name arguments


Changing the Pareon version
-------------------------

You may also specify the Pareon version through the `PAREON_VERSION` variable, like so:

    PAREON_VERSION = "2.23"

This will use the compiler and libraries from the `/opt/vectorfabrics/pareon-2.23/` folder.


Maintainers
-------------------------

Lessandro Mariano <lessandro@vectorfabrics.com>

Klaas van Gend <klaas@vectorfabrics.com>
