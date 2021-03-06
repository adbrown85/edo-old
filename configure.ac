# Initialize
AC_PREREQ([2.65])
AC_INIT([EDO], [0.96], [adb1413@rit.edu], , [http://gander.sourceforge.net])
AC_CONFIG_SRCDIR([src/edo_common.h])
AC_CONFIG_HEADERS([config.h:config.in])
AC_CANONICAL_SYSTEM
AC_PROG_CXX
AC_LANG([C++])
AC_PROG_INSTALL
AC_PROG_SED
if test -z $SED; then
	echo "--------------------------------------------------"
	echo " Sed is required to build EDO.                    "
	echo "--------------------------------------------------"
fi
PKG_PROG_PKG_CONFIG

# Check for GNU Make
echo -n "Checking for GNU Make..."
make_command=""
for i in "$MAKE" make gmake gnumake; do
	if (sh -c "$i --version" 2>/dev/null | grep GNU >/dev/null); then
		make_command=$i;
		break;
	fi
done
if test -z $make_command; then
	echo " no"
	echo "-------------------------------------------------------"
	echo " GNU Make is required to build EDO.                    "
	echo " Please visit http://www.gnu.org/software/make/        "
	echo "-------------------------------------------------------"
	(exit 1); exit 1;
else
	echo " yes"
fi

# Checks for libraries
AC_C_INLINE
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# OS-specific compiler switches
if test $build_os = "mingw32"; then
	extra_ldflags="-Wl,--enable-auto-import"
	if test -z "$LDFLAGS"; then
		LDFLAGS="$extra_ldflags"
	else
		LDFLAGS="$LDFLAGS $extra_ldflags"
	fi
fi

# Prefixes
baseprefix=`basename $prefix`
baseprefix_low=`echo $baseprefix | tr '[[:upper:]]' '[[:lower:]]'`
if test $baseprefix_low = $PACKAGE_TARNAME; then
	datadir='${datarootdir}'
	docdir='${prefix}'/doc
else
	datadir='${datarootdir}'/$PACKAGE_TARNAME
	docdir='${datarootdir}'/doc/$PACKAGE_TARNAME
fi
htmldir='${docdir}'/html

# Finish
AC_CONFIG_FILES([edo.pc Makefile doc/Makefile])
AC_OUTPUT

echo \
"--------------------------------------------------------------
 ${PACKAGE_NAME} ${PACKAGE_VERSION}

 prefix      ${prefix}
 datarootdir ${datarootdir}
 datadir     ${datadir}
 docdir      ${docdir}
 htmldir     ${htmldir}
 CXX         ${CXX}
 CXXFLAGS    ${CXXFLAGS}
 LDFLAGS     ${LDFLAGS}
 LIBS        ${LIBS}
 DEFS        ${DEFS}
 
 Now type 'make' then 'sudo make install'
--------------------------------------------------------------"
