/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2000-2006
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 */

#ifndef	__VERSION_H__
#define	__VERSION_H__

#ifndef DO_DEPS_ONLY
#include "generated/version_autogenerated.h"
#endif

#define U_BOOT_VERSION_STRING U_BOOT_VERSION " (" U_BOOT_DATE " - " \
	U_BOOT_TIME " " U_BOOT_TZ ")" CONFIG_IDENT_STRING

#endif	/* __VERSION_H__ */
