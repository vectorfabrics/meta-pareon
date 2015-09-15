DESCRIPTION = "Minimal Hello world!"
LICENSE = "GPL"
LIC_FILES_CHKSUM = "file://helloworld.c;md5=5251979965bb2281b6a6dc1eb7fd64bc"

do_fetch () {
	mkdir -p ${S}
	cd ${S}
	printf "#include <stdio.h>\nint main(void)\n{\n\tprintf(\"Hello world!\\\n\");\twhile(1);\n\treturn 0;\n}\n" >helloworld.c
}

do_compile () {
	${CC} ${CFLAGS} -c -o helloworld.o helloworld.c
	${CC} ${LDFLAGS} -o helloworld helloworld.o 
}

do_install () {
	install -d ${D}${bindir}
	install -m 0755 helloworld ${D}${bindir}/
}
