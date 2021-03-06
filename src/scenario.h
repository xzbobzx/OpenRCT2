/*****************************************************************************
 * Copyright (c) 2014 Ted John
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * This file is part of OpenRCT2.
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef _SCENARIO_H_
#define _SCENARIO_H_

#include "rct2.h"
#include "object.h"

/**
 * SV6/SC6 header chunk
 * size: 0x20
 */
typedef struct {
	uint16 type;				// 0x00
	uint16 num_packed_objects;	// 0x02
	uint32 version;				// 0x04
	uint32 magic_number;		// 0x08
	uint8 pad_0C[0x14];
} rct_s6_header;

/**
 * SC6 information chunk
 * size: 0x198
 */
typedef struct {
	uint8 var_000;
	uint8 category;				// 0x01
	uint8 objective_type;		// 0x02
	uint8 objective_arg_1;		// 0x03
	sint32 objective_arg_2;		// 0x04
	sint16 objective_arg_3;		// 0x08
	uint8 pad_00A[0x3E];
	char name[64];				// 0x48
	char details[256];			// 0x88
	rct_object_entry entry;		// 0x188
} rct_s6_info;

/*
 * Scenario scores file header.
 * size: 0x10
 */
typedef struct {
	uint32 var_0;
	uint32 var_4;
	uint32 var_8;
	uint32 scenario_count;		// 0x0C
} rct_scenario_scores_header;

/**
 * Scenario basic structure, mainly for scenario select
 * size: 0x02B0
 */
typedef struct {
	char path[256];				// 0x0000
	uint8 category;				// 0x0100
	uint8 pad_0101[0x1F];
	sint8 objective_type;		// 0x0120
	sint8 objective_arg_1;		// 0x0121
	sint32 objective_arg_2;		// 0x0122
	sint16 objective_arg_3;		// 0x0126
	char name[64];				// 0x0128
	char details[256];			// 0x0168
	sint32 flags;				// 0x0268
	uint32 company_value;		// 0x026C
	char completed_by[64];		// 0x0270
} rct_scenario_basic;

/* This will be useful for backwards compatibility
typedef struct {
	// SC6[0]
	rct_s6_header header;

	// SC6[1]
	rct_s6_info info;

	// SC6[2]
	// packed objects

	// SC6[3]
	rct_object_entry objects[721];

	// SC6[4]
	uint16 elapsed_months;
	uint16 current_day;
	uint32 dword_F663AC;
	uint32 scenario_srand_0;
	uint32 scenario_srand_1;

	// SC6[5]
	rct_map_element map_elements[0x30000];

	// SC6[6]
	uint32 dword_010E63B8;
	rct_sprite sprites[10000];
	uint16 sprites_next_index;
	uint16 sprites_start_vehicle;
	uint16 sprites_start_peep;
	uint16 sprites_start_textfx;
	uint16 sprites_start_litter;
	uint8 pad_013573C6[2];
	uint16 word_013573C8;
	uint8 pad_013573CA[4];
	uint16 word_013573CE;
	uint16 word_013573D0;
	uint8 pad_013573D2[2];
	uint16 word_013573D4;
	uint8 pad_013573D6[4];
	uint32 dword_013573D8;
	uint32 dword_013573DC;
	money32 current_loan;
	uint32 park_flags;
	money16 park_entrance_fee;
	uint16 word_013573EA;
	uint16 word_013573EC;
	uint8 pad_013573EE[16];
	uint8 byte_013573F0;
	uint8 pad_013573F1[2];
	rct2_peep_spawn peep_spawns[2];
	uint8 guest_count_change_modifier;
	uint8 byte_013573FF;
	uint8 pad_01357400[4];
	uint32 dword_01357404;
	uint32 dword_01357408;
	uint32 dword_0135740C;
	uint32 dword_01357410[5];
	uint32 dword_01357424[8];
	uint32 dword_01357444[128];
	uint32 dword_01357644[128];

	// SC6[7]
	uint16 guests_in_park;
	uint16 guests_heading_for_park;

	// Ignored in scenario
	money32 expenditure_table[14];
	uint32 dword_01357880[5];
	uint32 dword_01357894;
	uint32 dword_01357898;
	uint32 dword_0135789C;
	uint32 dword_013578A0;
	uint32 dword_013578A4[201];
	
	// SC6[8]
	uint16 last_guests_in_park;
	uint8 pad_01357BCA[3];
	uint8 handyman_colour;
	uint8 mechanic_colour;
	uint8 security_colour;

	// Ignored in scenario
	uint32 dword_01357BD0[56];

	// SC6[9]
	uint16 park_rating;

	// Ignored in scenario
	uint8 park_rating_history[32];
	uint8 guests_in_park_history[32];

	// SC6[10]
	uint16 word_01357CF2;
	uint32 word_01357CF4;
	uint8 byte_01357CF8[1000];
	uint32 dword_013580E0[32];
	uint16 word_013580E4[16];
	uint8 byte_013580E6;
	uint8 byte_013580E7;
	uint8 byte_013580E8;
	uint8 byte_013580E9;
	uint16 park_size;
	uint16 guest_generation_probability;
	uint16 total_ride_value;
	uint32 dword_013580F0;
	uint16 dword_013580F4;
	uint8 dword_013580F6;
	uint8 dword_013580F7;
	uint8 objective_type;
	uint8 objective_year;
	uint8 pad_013580FA[4];
	money32 objective_currency;
	uint16 objective_guests;
	uint8 campaign_weeks_left[20];
	uint8 campaign_ride_index[22];

	// Ignored in scenario
	money32 balance_history[128];

	// SC6[11]
	uint32 dword_0135832C;
	uint32 current_profit;
	uint32 dword_01358334;
	uint16 word_01358338;
	uint8 pad_0135833A[2];

	// Ignored in scenario
	uint8 pad_0135833C[2];
	money32 park_value;
	money32 park_value_history[128];

	// SC6[12]
	money32 completed_company_value;
	uint32 total_admissions;
	money32 income_from_admissions;
	money32 company_value;
	uint8 byte_01358750[16];
	rct_award awards[4];
	uint16 word_01358770;
	uint16 word_01358772;
	uint16 word_01358774;
	uint8 pad_01358776[4];
	uint32 dword_01358778[17];
	uint32 dword_013587BC;
	uint32 dword_013587C0;
	uint32 dword_013587C4;
	uint16 dword_013587C8;
	uint8 pad_013587CA[16];
	uint32 dword_013587D0;
	uint8 pad_013587D4[8];
	uint16 word_013587D8[16];
	money32 cash;
	uint8 pad_013587FC[50];
	uint16 word_0135882E;
	uint16 word_01358830;
	uint16 word_01358832;
	uint16 map_size;
	uint16 word_01358836;
	uint32 word_01358838;
	uint16 suggested_max_guests;
	uint16 word_0135883E;
	uint8 word_01358840;
	uint8 word_01358841;
	uint8 pad_01358842[4];
	uint32 dword_01358844;
	uint8 pad_01358848;
	uint32 dword_01358849;
	uint8 pad_0135884D[2];
	uint8 dword_0135884E[622];
	uint8 pad_01359206[2];
	uint16 word_01359208;
	char scenario_name[64];
	char scenario_description[255];
	uint8 byte_01359349;
	uint8 byte_0135934A;
	uint8 pad_0135934B[3];
	uint32 dword_0135934C;
	uint16 park_entrance_x[4];
	uint16 park_entrance_y[4];
	uint16 park_entrance_z[4];
	uint8 byte_01359368;
	uint8 pad_01359369[3];
	uint8 byte_0135936C[256];
	uint8 byte_0135946C[3256];
	uint8 byte_0135A124;
	uint8 byte_0135A125;
	uint16 word_0135A126;
	uint8 byte_0135A128;
	uint8 byte_0135A129;
	uint8 byte_0135A12A;
	uint8 byte_0135A12B[793];
	uint8 byte_0135A444[1200];
	char custom_strings[0x8000];
	uint32 game_ticks_1;
	rct_ride rides[255];
	uint16 word_01388698;
	uint16 saved_view_x;
	uint16 saved_view_y;
	uint16 saved_view_zoom_and_rotation;
	uint8 byte_013886A0[6000];
	uint8 byte_01389E10[6000];
	uint16 word_0138B580;
	uint8 pad_0138B580[2];
	uint16 word_0138B584;
	uint16 word_0138B586;
	uint16 word_0138B588;
	uint16 word_0138B58A;
	uint16 word_0138B58C;
	uint16 word_0138B58E;
	uint8 byte_0138B590;
	uint8 byte_0138B591;
	uint8 byte_0138B592;
	uint8 byte_0138B593;
	uint16 word_0138B594;
	uint16 word_0138B596;
	uint16 word_0138B598;
	uint16 word_0138B59A;
	uint16 word_0138B59C;
	uint16 word_0138B59E;
	uint16 word_0138B5A0;
	uint16 word_0138B5A2;
	uint16 word_0138B5A4;
	uint16 word_0138B5A6;
	uint16 word_0138B5A8;
	uint16 word_0138B5AA;
	uint16 word_0138B5AC;
	uint16 word_0138B5AE;
	uint16 word_0138B5B0;
	uint16 word_0138B5B2;
	uint16 word_0138B5B4;
	uint16 word_0138B5B6;
	uint16 word_0138B5B8;
	uint16 word_0138B5BA;
	uint16 word_0138B5BC;
	uint16 word_0138B5BE;
	uint16 word_0138B5C0;
	uint16 word_0138B5C2;
	uint16 word_0138B5C4;
	uint16 word_0138B5C6;
	uint16 word_0138B5C8;
	uint16 word_0138B5CA;
	uint16 word_0138B5CC;
	uint16 word_0138B5CE[31];
	uint8 ride_measurements[0x25860];
	uint32 dword_13B0E6C;
	uint16 word_13B0E70;
	uint32 dword_13B0E72[0x6600];
	uint8 byte_13CA672[116];
	uint8 byte_13CA6E6[84];
	uint8 byte_13CA73A[4];
	uint8 unk_13CA73E;
	uint8 pad_13CA73E;
	uint8 byte_13CA740;
	uint8 byte_13CA741;
	uint8 byte_13CA7424[4];
	uint8 climate;
	uint8 pad_013CA747;
	uint16 climate_update_timer;
	uint8 current_weather;
	uint8 next_weather;
	uint8 temperature;
	uint8 next_temperature;
	uint8 current_weather_effect;
	uint8 next_weather_effect;
	uint8 current_weather_gloom;
	uint8 next_weather_gloom;
	uint8 current_rain_level;
	uint8 next_rain_level;
	rct_news_item news_items[61];
	uint8 byte_13CE730[64];
	uint32 dword_13CE770;
	uint16 word_13CE774;
	uint16 word_13CE776[217];
} rct_s6_data;
*/

enum {
	SCENARIO_FLAGS_VISIBLE = (1 << 0),
	SCENARIO_FLAGS_COMPLETED = (1 << 1),
	SCENARIO_FLAGS_SIXFLAGS = (1 << 2)
};

enum {
	S6_TYPE_SAVEDGAME,
	S6_TYPE_SCENARIO
};

enum {
	SCENARIO_CATEGORY_BEGINNER,
	SCENARIO_CATEGORY_CHALLENGING,
	SCENARIO_CATEGORY_EXPERT,
	SCENARIO_CATEGORY_REAL,
	SCENARIO_CATEGORY_BUILDYOUROWN
};

enum {
	OBJECTIVE_NONE,
	OBJECTIVE_GUESTS_BY,
	OBJECTIVE_PARK_VALUE_BY,
	OBJECTIVE_HAVE_FUN,
	OBJECTIVE_BUILD_THE_BEST,
	OBJECTIVE_10_ROLLERCOASTERS,
	OBJECTIVE_GUESTS_AND_RATING,
	OBJECTIVE_MONTHLY_RIDE_INCOME,
	OBJECTIVE_10_ROLLERCOASTERS_LENGTH,
	OBJECTIVE_FINISH_5_ROLLERCOASTERS,
	OBJECTIVE_REPLAY_LOAN_AND_PARK_VALUE,
	OBJECTIVE_MONTHLY_FOOD_INCOME
};

// Scenario list
extern int gScenarioListCount;
extern int gScenarioListCapacity;
extern rct_scenario_basic *gScenarioList;

int scenario_scores_save();
void scenario_load_list();
int scenario_load_basic(const char *path);
void scenario_load(const char *path);
void scenario_load_and_play(const rct_scenario_basic *scenario);
void scenario_update();
int scenario_rand();

#endif
