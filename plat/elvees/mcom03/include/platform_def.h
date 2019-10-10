/*
 * Copyright 2019 RnD Center "ELVEES", JSC
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLATFORM_DEF_H
#define PLATFORM_DEF_H

#include <arch.h>
#include <lib/utils_def.h>
#include <plat/common/common_def.h>

/* CPU topology */
#define PLAT_MAX_CORES_PER_CLUSTER	4
#define PLAT_CLUSTER_COUNT		1
#define PLATFORM_CORE_COUNT		(PLAT_CLUSTER_COUNT *	\
					 PLAT_MAX_CORES_PER_CLUSTER)

#define PLAT_MAX_PWR_LVL		MPIDR_AFFLVL1
#define PLAT_MAX_RET_STATE		MPIDR_AFFLVL1
#define PLAT_MAX_OFF_STATE		MPIDR_AFFLVL2

#define PLAT_LOCAL_STATE_RUN		0
#define PLAT_LOCAL_STATE_RET		1
#define PLAT_LOCAL_STATE_OFF		2

#define CACHE_WRITEBACK_SHIFT		6
#define CACHE_WRITEBACK_GRANULE		(1 << CACHE_WRITEBACK_SHIFT)

#define PLAT_PHY_ADDR_SPACE_SIZE	(1ULL << 40)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ULL << 39)
#define MAX_XLAT_TABLES			8
#define MAX_MMAP_REGIONS		8

#define PLATFORM_STACK_SIZE		0x400

#define BL31_BASE			0xC0000000
#define BL31_SIZE			0x00080000
#define BL31_LIMIT			(BL31_BASE + BL31_SIZE)

#define BL33_BASE			BL31_LIMIT

#define PLAT_GICD_BASE			0x1100000
#define PLAT_GICR_BASE			0x1180000

#endif /* PLATFORM_DEF_H */
