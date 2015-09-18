DESCRIPTION = "Minimal Hello world!"
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://helloworld.cpp;md5=de811edd261316b128ee9a142ae0d250"

do_fetch () {
    mkdir -p ${S}
    cd ${S}
    printf "#include <iostream>\nint main(void)\n{\n\tstd::cout<<\"Hello world!\\\n\";\n\treturn 0;\n}\n" >helloworld.cpp
}

do_compile () {
    ${CXX} ${CFLAGS} -c -o helloworld.o helloworld.cpp
    ${CXX} ${LDFLAGS} -o helloworld-cpp helloworld.o
}

do_install () {
    install -d ${D}${bindir}
    install -m 0755 helloworld-cpp ${D}${bindir}/
}
