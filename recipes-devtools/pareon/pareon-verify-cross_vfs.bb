PAREON_PRODUCT = "verify"

require pareon-cross.inc

do_install_append() {
    ln -s verify-vfcc ${D}${bindir}/vfcc
    ln -s verify-vf++ ${D}${bindir}/vf++
    ln -s try-verify-vfcc ${D}${bindir}/try-vfcc
    ln -s try-verify-vf++ ${D}${bindir}/try-vf++
}
