Blacklisted Packages for meta-pareon
================================

Introduction
-------------------------

The meta-pareon layer works with the majority of recipes available in the OpenEmbedded repositories.
Note that only packages meant to appear on the target make sense to be instrumented.

A few packages cannot be instrumented using the meta-pareon layer.
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

If you need one of the above packages instrumented, please talk to the meta-pareon maintainers.
