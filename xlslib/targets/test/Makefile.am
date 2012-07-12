
AM_CPPFLAGS		=  \
-I$(top_srcdir)/src


noinst_PROGRAMS	  = testCPP testC PR2859188 PR3076678
testCPP_SOURCES	  = mainCPP.cpp md5.c
testCPP_LDADD	  = $(top_builddir)/src/libxls.la 
testCPP_LDFLAGS   = -static -lstdc++
testC_SOURCES	  = mainC.c md5.c
if TARGET_OS_MINGW32		
# MingW: Dummy C++ source to cause C++ linking. Fix for MingW link errors.
# See also:  http://www.qtforum.org/article/29890/qt-4-6-linking-problem.html?s=f3b28924bedf0be5f571e2d5be8ba7b49ee7debe#post103340
testC_SOURCES    += dummy.cpp
endif
testC_LDADD       = $(top_builddir)/src/libxls.la 
testC_LDFLAGS     = -static -lstdc++
PR2859188_SOURCES = PR2859188.cpp md5.c
PR2859188_LDADD   = $(top_builddir)/src/libxls.la 
PR2859188_LDFLAGS = -static -lstdc++
PR3076678_SOURCES = PR3076678.cpp md5.c
PR3076678_LDADD   = $(top_builddir)/src/libxls.la 
PR3076678_LDFLAGS = -static -lstdc++

check_PROGRAMS = testCPP testC PR2859188 PR3076678

TESTS = testCPP testC PR2859188 PR3076678

clean-local:
	-rm -rf *.xls


