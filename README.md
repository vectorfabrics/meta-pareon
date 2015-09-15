Meta-pareon
================================

Introduction
-------------------------

The official OpenEmbedded/Yocto BSP layer for the VectorFabrics pareon compiler.

The meta-pareon layer depends on:

	URI: git://git.openembedded.org/openembedded-core
	layers: meta
	branch: dizzy

Please follow the recommended setup procedures of your OE distribution. For Angstrom that is http://www.angstrom-distribution.org/building-angstrom, other distros should have similar online resources.

Usage
-------------------------

Add this layer to your layerstack the way you usually do, this differs between projects using OpenEmbedded. The steps should include updating conf/bblayers.conf. Please refer to the documenation of your project for the exact steps.

To prepare for (re)building recipes with the pareon compiler add the following to your conf/local.conf file:

	require conf/distro/include/pareon.inc

Because this updates $PATH it will invalidate existing sstate-cache and associated build checksums. This means a full rebuild of all the dependencies is needed, so make sure you do this step before starting.

To (re)build recipes with the pareon compiler run the generator script:

	user@ubuntu-vm:/OE/sources/meta-pareon$ ./scripts/generate-conf.sh helloworld
	require conf/distro/include/pareon.inc

	DEPENDS_append_pn-helloworld = " libpareon-verify"
	CC_pn-helloworld        = "vfcc"
	CXX_pn-helloworld       = "vf++"
	LD_pn-helloworld        = "vfld"


The script accepts multiple recipe names:

	user@ubuntu-vm:/OE/sources/meta-pareon$ ./scripts/generate-conf.sh helloworld bash
	require conf/distro/include/pareon.inc

	DEPENDS_append_pn-helloworld = " libpareon-verify"
	CC_pn-helloworld        = "vfcc"
	CXX_pn-helloworld       = "vf++"
	LD_pn-helloworld        = "vfld"

	DEPENDS_append_pn-bash = " libpareon-verify"
	CC_pn-bash      = "vfcc"
	CXX_pn-bash     = "vf++"
	LD_pn-bash      = "vfld"

Copy/paste the output into conf/local.conf. Only a single 'require conf/distro/include/pareon.inc' entry is needed, so leave that out if you have added that already.

Building cmake projects
-------------------------

Due to the way cmake tries to find the binutils executables, it is necessary to manually set the `_CMAKE_TOOLCHAIN_PREFIX` variable when building a project with the pareon compiler. You must add the following to your local.conf (replacing synergy with your cmake project):

    EXTRA_OECMAKE_append_pn-synergy = " -D_CMAKE_TOOLCHAIN_PREFIX=${HOST_PREFIX} "


Maintainers
-------------------------

Lessandro Mariano <lessandro@vectorfabrics.com>

Klaas van Gend <klaas@vectorfabrics.com>
