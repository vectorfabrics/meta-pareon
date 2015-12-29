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

To (re)build recipes with the Pareon compiler, add the following to your conf/local.conf:

    TOOLCHAIN_pn-<recipe> = "pareon-verify"

Alternatively, run the generator script. The script accepts multiple recipe names:

    user@ubuntu-vm:/OE/sources/meta-pareon$ ./scripts/generate-conf.sh helloworld bash
    TOOLCHAIN_pn-helloworld = "pareon-verify"
    TOOLCHAIN_pn-bash = "pareon-verify"

Copy/paste the output into conf/local.conf.


Available toolchains
-------------------------

* pareon-verify
* pareon-profile
* pareon-verify-with-fallback
* pareon-profile-with-fallback

The last two toolchains fallback to GCC for any specific file that fails to compile with vfcc.


Packages that do not work with Pareon
-------------------------

Several packages are known to refuse instrumentation. They are listed in the file BLACKLIST.md.


Analyzing programs on the target
-------------------------

Use the `pareon_run.sh` wrapper script to setup the necessary environment variables when analyzing programs on the target.

    pareon_run.sh program_name arguments

For Pareon Profile, use `pareon_profile_run.sh`:

    pareon_profile_run.sh program_name arguments


Using a different version of Pareon
-------------------------

You may also specify the Pareon version through the `PAREON_VERSION` variable, like so:

    PAREON_VERSION = "2.26"

This will use the compiler and libraries from the `/opt/vectorfabrics/pareon-2.26/` folder.

By default meta-pareon will use the latest Pareon installed.


Maintainers
-------------------------

Lessandro Mariano <lessandro@vectorfabrics.com>

Klaas van Gend <klaas@vectorfabrics.com>
