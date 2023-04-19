/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) ASPEED Technology Inc.
 *
 * Copyright 2016 IBM Corporation
 * (C) Copyright 2016 Google, Inc
 */

#ifndef __ASPEED_COMMON_CONFIG_H
#define __ASPEED_COMMON_CONFIG_H

#include <asm/arch/platform.h>

#define CONFIG_BOOTFILE		"all.bin"

#define CONFIG_GATEWAYIP	192.168.0.1
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.0.45
#define CONFIG_SERVERIP		192.168.0.81

#define CONFIG_STANDALONE_LOAD_ADDR 0x83000000

/* Misc CPU related */
#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

#define CONFIG_SYS_SDRAM_BASE		(ASPEED_DRAM_BASE + CONFIG_ASPEED_SSP_RERV_MEM)

#ifdef CONFIG_PRE_CON_BUF_SZ
#define CONFIG_SYS_INIT_RAM_ADDR	(ASPEED_SRAM_BASE + CONFIG_PRE_CON_BUF_SZ)
#define CONFIG_SYS_INIT_RAM_SIZE	(ASPEED_SRAM_SIZE - CONFIG_PRE_CON_BUF_SZ)
#else
#define CONFIG_SYS_INIT_RAM_ADDR	(ASPEED_SRAM_BASE)
#define CONFIG_SYS_INIT_RAM_SIZE	(ASPEED_SRAM_SIZE)
#endif

#define SYS_INIT_RAM_END \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_RAM_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(SYS_INIT_RAM_END - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_BOOTMAPSZ		(256 * 1024 * 1024)
#define CONFIG_SYS_MALLOC_LEN		(32 << 20)

/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_BOOTM_LEN 		(0x800000 * 2)

#define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=yes\0"	\
	""

/* Environment */
#ifdef CONFIG_ASPEED_PALLADIUM
#define CONFIG_ENV_IS_NOWHERE
#endif

#ifndef CONFIG_ENV_SIZE
#define CONFIG_ENV_SIZE			0x10000
#endif

#ifndef CONFIG_ENV_OFFSET
#define CONFIG_ENV_OFFSET		0xF0000
#endif

#define CONFIG_ENV_SECT_SIZE	(4 << 10)

/*
 * Ethernet related
 */
#define PHY_ANEG_TIMEOUT		800

/* Uboot size */
#define CONFIG_SYS_MONITOR_LEN ((1024 - 64) * 1024)

#ifdef CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV		0
#define CONFIG_SYS_MMC_ENV_PART		0
#define CONFIG_ENV_OFFSET_REDUND	(CONFIG_ENV_OFFSET + CONFIG_ENV_SIZE)
#endif

#endif	/* __ASPEED_COMMON_CONFIG_H */
