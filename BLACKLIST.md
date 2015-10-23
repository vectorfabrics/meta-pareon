Blacklisted Packages for meta-pareon
================================

Introduction
-------------------------

The meta-pareon layer works with the majority of recipes available in the
OpenEmbedded repositories. Note that only packages meant to appear on the
target make sense to be instrumented.


Not instrumented recipes
-------------------------

A few recipes cannot be instrumented using the meta-pareon layer.
If you need one of these packages instrumented, please talk to the meta-pareon
maintainers.

Below is a list, accurate as of Pareon 2.24:

    alsa-lib
    binutils
    e2fsprogs
    gcc
    gcc-runtime
    glibc
    glibc-initial
    glibc-locale
    libgcc
    libgcc-initial
    lmbench
    mozjs
    rt-tests
    systemd
    util-linux


Partially instrumented recipes
-------------------------

Some recipes when instrumented will create packages that are not fully
instrumented, i.e. only some of the binaries are instrumented, some are not:

Below is a list, accurate as of Pareon 2.24:

    cpufrequtils
    dosfstools
    gnome-panel
    iptables
    libcap
    ncurses
