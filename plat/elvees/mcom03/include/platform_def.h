/*
 * Copyright 2019-2022 RnD Center "ELVEES", JSC
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef PLATFORM_DEF_H
#define PLATFORM_DEF_H

#include <arch.h>
#include <lib/utils_def.h>
#include <plat/common/common_def.h>

/* CPU topology */
#define PLAT_MAX_CORES_PER_CLUSTER	U(4)
#define PLAT_CLUSTER_COUNT		U(1)
#define PLATFORM_CORE_COUNT		(PLAT_CLUSTER_COUNT * \
					 PLAT_MAX_CORES_PER_CLUSTER)

#define MCOM03_PRIMARY_CORE		U(0)

#define PLAT_MAX_PWR_LVL		(MPIDR_AFFLVL1)
#define PLAT_NUM_PWR_DOMAINS		(PLAT_CLUSTER_COUNT + \
					 PLATFORM_CORE_COUNT)

/*
 * This macro defines the deepest retention state possible. A higher state
 * id will represent an invalid or a power down state.
 */
#define PLAT_MAX_RET_STATE		U(1)

/*
 * This macro defines the deepest power down states possible. Any state ID
 * higher than this is invalid.
 */
#define PLAT_MAX_OFF_STATE		U(2)

/* Local power state for power domains in Run state. */
#define PLAT_LOCAL_STATE_RUN		U(0)
/* Local power state for retention. Valid only for CPU power domains */
#define PLAT_LOCAL_STATE_RET		U(1)
/* Local power state for power-down. Valid for CPU and cluster power domains. */
#define PLAT_LOCAL_STATE_OFF		U(2)

/* Size of cacheable stacks */
#define PLATFORM_STACK_SIZE		UL(0x1000)

/*
 * Some data must be aligned on the biggest cache line size in the platform.
 * This is known only to the platform as it might have a combination of
 * integrated and external caches.
 */
#define CACHE_WRITEBACK_SHIFT		U(6)
#define CACHE_WRITEBACK_GRANULE		(U(1) << CACHE_WRITEBACK_SHIFT)

/* Memory-related defines */
#define PLAT_PHY_ADDR_SPACE_SIZE	(ULL(1) << 40)
#define PLAT_VIRT_ADDR_SPACE_SIZE	(ULL(1) << 39)

#define MAX_MMAP_REGIONS		16
#define MAX_XLAT_TABLES			8

/*
 * BL3-1 specific defines.
 */
#define BL31_BASE			0x880300000
#define BL31_SIZE			0x00080000
#define BL31_LIMIT			(BL31_BASE + BL31_SIZE - 1)

/*
 * BL3-2 specific defines.
 */
#define BL32_BASE			(BL31_BASE + BL31_SIZE)
#define BL32_SIZE			0x00080000
#define BL32_LIMIT			(BL32_BASE + BL32_SIZE - 1)

/*
 * BL3-3 specific defines.
 */
#define BL33_BASE			0x882480000

/* TIMER related constants */
#ifdef PLAT_MCOM03_HAPS
#define PLAT_TIMER_CLK			5000000
#else
#define PLAT_TIMER_CLK			27000000
#endif

/* UART related constants */
#ifdef PLAT_MCOM03_HAPS
#define PLAT_BOOT_UART_BASE		0x1640000
#define PLAT_BOOT_UART_CLK_IN_HZ	14750000
#define PLAT_BOOT_CONSOLE_BAUDRATE	115200
#else
#define PLAT_BOOT_UART_BASE		0x1750000
#define PLAT_BOOT_UART_CLK_IN_HZ	27000000
#define PLAT_BOOT_CONSOLE_BAUDRATE	115200
#endif

/* Base MCom-03 platform compatible GIC memory map */
#define PLAT_GICD_BASE			0x1100000
#define PLAT_GICR_BASE			0x1180000

/* SGI, PPI */
#define PLAT_IRQ_SEC_PHY_TIMER		29U

#define PLAT_IRQ_SEC_SGI_0		8
#define PLAT_IRQ_SEC_SGI_1		9
#define PLAT_IRQ_SEC_SGI_2		10
#define PLAT_IRQ_SEC_SGI_3		11
#define PLAT_IRQ_SEC_SGI_4		12
#define PLAT_IRQ_SEC_SGI_5		13
#define PLAT_IRQ_SEC_SGI_6		14
#define PLAT_IRQ_SEC_SGI_7		15

#define MAX_INTR_EL3			159

#define PLAT_URB_BASE			0x1000000

#define XTI_CLOCK			27000000
#define PLAT_SERVICE_SUBS_BASE		0x1f000000
#define PLAT_SERVICE_SUBS_PLLCFG	(PLAT_SERVICE_SUBS_BASE + 0x1000)
#define PLAT_SERVICE_SUBS_UCG1		(PLAT_SERVICE_SUBS_BASE + 0x20000)

#define UCG_CTR_REG(i, j)		(i + j * 0x4)
#define UCG_BP_CTR_REG(i)		(i + 0x40)
#define UCG_CTR_DIV_COEFF		GENMASK(29, 10)
#define UCG_CTR_DIV_LOCK		BIT(30)

#define PLL_CFG_SEL			GENMASK(7, 0)
#define PLL_CFG_MAN			BIT(9)
#define PLL_CFG_OD			GENMASK(13, 10)
#define PLL_CFG_NF			GENMASK(26, 14)
#define PLL_CFG_NR			GENMASK(30, 27)
#define PLL_CFG_LOCK			BIT(31)

#define PLAT_WDT0_BASE			0x1f080000

#define PPOLICY_OFF			0x1
#define PPOLICY_WARM_RST		0x8
#define PPOLICY_ON			0x10

/*
 * TSP  specific defines.
 */
#define TSP_SEC_MEM_BASE		BL32_BASE
#define TSP_SEC_MEM_SIZE		BL32_SIZE

/* ID of the secure physical generic timer interrupt used by the TSP */
#define TSP_IRQ_SEC_PHY_TIMER		29U

/* UART related constants */
#ifdef PLAT_MCOM03_HAPS
#define PLAT_TSP_UART_BASE		0x1750000
#define PLAT_TSP_UART_CLK_IN_HZ		14750000
#define PLAT_TSP_CONSOLE_BAUDRATE	115200
#else
#define PLAT_TSP_UART_BASE		0x1750000
#define PLAT_TSP_UART_CLK_IN_HZ		27000000
#define PLAT_TSP_CONSOLE_BAUDRATE	115200
#endif

#endif /* PLATFORM_DEF_H */
