/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __QCOM_STATS_H__
#define __QCOM_STATS_H__

struct ddr_freq_residency {
	uint32_t freq;
	uint64_t residency;
};

struct ddr_stats_ss_vote_info {
	u32 ab; /* vote_x */
	u32 ib; /* vote_y */
};

#if IS_ENABLED(CONFIG_QCOM_STATS)

int ddr_stats_get_ss_count(void);
int ddr_stats_get_ss_vote_info(int ss_count,
			       struct ddr_stats_ss_vote_info *vote_info);

int ddr_stats_get_freq_count(void);
int ddr_stats_get_residency(int freq_count, struct ddr_freq_residency *data);

bool has_system_slept(void);
bool has_subsystem_slept(void);
void subsystem_sleep_debug_enable(bool enable);

#else

static inline int ddr_stats_get_ss_count(void)
{ return -ENODEV; }
static inline int ddr_stats_get_ss_vote_info(int ss_count,
					     struct ddr_stats_ss_vote_info *vote_info)
{ return -ENODEV; }
static inline int ddr_stats_get_freq_count(void)
{ return -ENODEV; }
int ddr_stats_get_residency(int freq_count, struct ddr_freq_residency *data)
{ return -ENODEV; }

bool has_system_slept(void)
{ return false; }
bool has_subsystem_slept(void)
{ return false; }
void subsystem_sleep_debug_enable(bool enable)
{ return; }

#endif
#endif /*__QCOM_STATS_H__ */
