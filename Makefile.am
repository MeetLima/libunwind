include_HEADERS = include/libunwind-dynamic.h \
    include/libunwind-ptrace.h \
    include/libunwind-coredump.h

if ARCH_ARM
include_HEADERS += include/libunwind-arm.h
endif
if ARCH_IA64
include_HEADERS += include/libunwind-ia64.h
endif
if ARCH_HPPA
include_HEADERS += include/libunwind-hppa.h
endif
if ARCH_MIPS
include_HEADERS += include/libunwind-mips.h
endif
if ARCH_X86
include_HEADERS += include/libunwind-x86.h
endif
if ARCH_X86_64
include_HEADERS += include/libunwind-x86_64.h
endif
if ARCH_PPC32
include_HEADERS += include/libunwind-ppc32.h
endif
if ARCH_PPC64
include_HEADERS += include/libunwind-ppc64.h
endif
if ARCH_SH
include_HEADERS += include/libunwind-sh.h
endif

if !REMOTE_ONLY
include_HEADERS += include/libunwind.h include/unwind.h
endif

nodist_include_HEADERS = include/libunwind-common.h

SUBDIRS = src tests

noinst_HEADERS = include/dwarf.h include/dwarf_i.h include/dwarf-eh.h	\
	include/compiler.h include/libunwind_i.h include/mempool.h	\
	include/remote.h						\
	include/tdep-arm/dwarf-config.h	include/tdep-arm/ex_tables.h	\
	include/tdep-arm/jmpbuf.h include/tdep-arm/libunwind_i.h	\
	include/tdep-ia64/jmpbuf.h include/tdep-ia64/rse.h 		\
	include/tdep-ia64/libunwind_i.h	include/tdep-ia64/script.h	\
	include/tdep-hppa/libunwind_i.h					\
	include/tdep-hppa/jmpbuf.h include/tdep-hppa/dwarf-config.h	\
	include/tdep-mips/libunwind_i.h					\
	include/tdep-mips/jmpbuf.h include/tdep-mips/dwarf-config.h	\
	include/tdep-x86/libunwind_i.h					\
	include/tdep-x86/jmpbuf.h include/tdep-x86/dwarf-config.h	\
	include/tdep-x86_64/libunwind_i.h				\
	include/tdep-x86_64/jmpbuf.h include/tdep-x86_64/dwarf-config.h \
	include/tdep-ppc32/dwarf-config.h				\
	include/tdep-ppc32/jmpbuf.h include/tdep-ppc32/libunwind_i.h	\
	include/tdep-ppc64/dwarf-config.h				\
	include/tdep-ppc64/jmpbuf.h include/tdep-ppc64/libunwind_i.h	\
	include/tdep-sh/dwarf-config.h					\
	include/tdep-sh/jmpbuf.h include/tdep-sh/libunwind_i.h		\
	include/tdep/libunwind_i.h					\
	include/tdep/jmpbuf.h include/tdep/dwarf-config.h

EXTRA_DIST = include/libunwind-common.h.in

MAINTAINERCLEANFILES = \
	Makefile.in \
	INSTALL \
	aclocal.m4 \
	configure \
	config/compile \
	config/config.guess \
	config/config.sub \
	config/depcomp \
	config/install-sh \
	config/ltmain.sh \
	config/missing \
	include/config.h.in \
	include/config.h.in~
