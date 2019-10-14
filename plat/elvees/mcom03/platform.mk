#
# Copyright 2019 RnD Center "ELVEES", JSC
#
# SPDX-License-Identifier: BSD-3-Clause
#

RESET_TO_BL31			:= 1
PROGRAMMABLE_RESET_ADDRESS	:= 1
USE_COHERENT_MEM		:= 1
SEPARATE_CODE_AND_RODATA	:= 1
ENABLE_SVE_FOR_NS		:= 0
# explicit disable Secure Partition support
ENABLE_SPM			:= 0

# Enable workarounds for selected Cortex-A53 erratas.
ERRATA_A53_855873		:= 1

# Libraries
include lib/xlat_tables_v2/xlat_tables.mk

PLAT_PATH		:=	plat/elvees/mcom03
PLAT_INCLUDES		:=	-I$(PLAT_PATH)/include

PLAT_BL_COMMON_SOURCES	+=	$(PLAT_PATH)/helpers.S			\
				drivers/ti/uart/aarch64/16550_console.S \
				drivers/delay_timer/delay_timer.c	\
				drivers/delay_timer/generic_delay_timer.c \
				${XLAT_TABLES_LIB_SRCS}

BL31_SOURCES		+=	drivers/arm/gic/common/gic_common.c	\
				drivers/arm/gic/v3/gicv3_helpers.c	\
				drivers/arm/gic/v3/gicv3_main.c		\
				lib/cpus/aarch64/cortex_a53.S		\
				plat/common/plat_gicv3.c		\
				plat/common/plat_psci_common.c		\
				$(PLAT_PATH)/bl31_setup.c		\
				$(PLAT_PATH)/topology.c			\
				$(PLAT_PATH)/psci.c			\
				$(PLAT_PATH)/gicv3.c			\
				$(PLAT_PATH)/xlat_setup.c
