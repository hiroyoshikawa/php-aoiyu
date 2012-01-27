dnl $Id: config.m4,v 1.2 2004/01/09 19:22:36 andrey Exp $
dnl config.m4 for extension stats

PHP_ARG_ENABLE(aoiyu, whether to enable stats support,
[  --enable-aoiyu           Enable statistics support])

if test "$PHP_STATS" != "no"; then
  PHP_NEW_EXTENSION(aoiyu, aoiyu.c, $ext_shared)
fi
