bin_PROGRAMS = jupiter
jupiter_SOURCES = main.c

check_SCRIPTS = greptests.sh
TESTS = $(check_SCRIPTS)

greptests.sh:
	echo './jupiter | grep "Hello from .*jupiter!"' > greptests.sh
	chmod +x greptests.sh

CLEANFILES = greptests.sh
