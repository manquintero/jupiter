SUBDIRS = modules/hithere

bin_PROGRAMS = jupiter
jupiter_SOURCES = main.c module.h
jupiter_CPPFLAGS = -I$(top_srcdir)/include
jupiter_LDADD = ../libjup/libjupiter.la

check_SCRIPTS = greptests.sh
TESTS = $(check_SCRIPTS)

greptests.sh:
	echo './jupiter | grep ".* from .*jupiter!"' > greptests.sh
	chmod +x greptests.sh

CLEANFILES = greptests.sh
