/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright (c) 2015 Terry Cain <terrys-home.co.uk>
 */

#ifndef DRIVER_RAZERCHROMACOMMON_H_
#define DRIVER_RAZERCHROMACOMMON_H_

#include "razercommon.h"

/*
 * Standard Device Functions
 */
struct razer_report razer_chroma_standard_set_device_mode(unsigned char mode, unsigned char param);
struct razer_report razer_chroma_standard_get_device_mode(void);

struct razer_report razer_chroma_standard_get_serial(void);

struct razer_report razer_chroma_standard_get_firmware_version(void);

/*
 * Standard LED Functions
 */
struct razer_report razer_chroma_standard_set_led_state(unsigned char variable_storage, unsigned char led_id, unsigned char led_state);
struct razer_report razer_chroma_standard_get_led_state(unsigned char variable_storage, unsigned char led_id);

struct razer_report razer_chroma_standard_set_led_blinking(unsigned char variable_storage, unsigned char led_id);

struct razer_report razer_chroma_standard_set_led_rgb(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1);
struct razer_report razer_chroma_standard_get_led_rgb(unsigned char variable_storage, unsigned char led_id);

struct razer_report razer_chroma_standard_set_led_effect(unsigned char variable_storage, unsigned char led_id, unsigned char led_effect);
struct razer_report razer_chroma_standard_get_led_effect(unsigned char variable_storage, unsigned char led_id);

struct razer_report razer_chroma_standard_set_led_brightness(unsigned char variable_storage, unsigned char led_id, unsigned char brightness);
struct razer_report razer_chroma_standard_get_led_brightness(unsigned char variable_storage, unsigned char led_id);

/*
 * Standard Matrix Effects Functions
 */
struct razer_report razer_chroma_standard_matrix_effect_none(void);
struct razer_report razer_chroma_standard_matrix_effect_wave(unsigned char wave_direction);
struct razer_report razer_chroma_standard_matrix_effect_spectrum(void);
struct razer_report razer_chroma_standard_matrix_effect_reactive(unsigned char speed, struct razer_rgb *rgb1);
struct razer_report razer_chroma_standard_matrix_effect_static(struct razer_rgb *rgb1);
struct razer_report razer_chroma_standard_matrix_effect_starlight_single(unsigned char speed, struct razer_rgb *rgb1);
struct razer_report razer_chroma_standard_matrix_effect_starlight_dual(unsigned char speed, struct razer_rgb *rgb1, struct razer_rgb *rgb2);
struct razer_report razer_chroma_standard_matrix_effect_starlight_random(unsigned char speed);

struct razer_report razer_chroma_standard_matrix_effect_breathing_random(void);
struct razer_report razer_chroma_standard_matrix_effect_breathing_single(struct razer_rgb *rgb1);
struct razer_report razer_chroma_standard_matrix_effect_breathing_dual(struct razer_rgb *rgb1, struct razer_rgb *rgb2);
struct razer_report razer_chroma_standard_matrix_effect_custom_frame(unsigned char variable_storage);
struct razer_report razer_chroma_standard_matrix_set_custom_frame(unsigned char row_index, unsigned char start_col, unsigned char stop_col, unsigned char *rgb_data);

/*
 * Extended Matrix Effects Functions
 *
 * Class 0x0F
 * Trans 0x3F (Dev 0b001 Game Controller 1, Trans 0b11111)
 */
struct razer_report razer_chroma_extended_matrix_effect_none(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_extended_matrix_effect_static(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb);
struct razer_report razer_chroma_extended_matrix_effect_wave(unsigned char variable_storage, unsigned char led_id, unsigned char direction);
struct razer_report razer_chroma_extended_matrix_effect_starlight_random(unsigned char variable_storage, unsigned char led_id, unsigned char speed);
struct razer_report razer_chroma_extended_matrix_effect_starlight_single(unsigned char variable_storage, unsigned char led_id, unsigned char speed, struct razer_rgb *rgb1);
struct razer_report razer_chroma_extended_matrix_effect_starlight_dual(unsigned char variable_storage, unsigned char led_id, unsigned char speed, struct razer_rgb *rgb1, struct razer_rgb *rgb2);
struct razer_report razer_chroma_extended_matrix_effect_spectrum(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_extended_matrix_effect_wheel(unsigned char variable_storage, unsigned char led_id, unsigned char direction);
struct razer_report razer_chroma_extended_matrix_effect_reactive(unsigned char variable_storage, unsigned char led_id, unsigned char speed, struct razer_rgb *rgb1);
struct razer_report razer_chroma_extended_matrix_effect_breathing_random(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_extended_matrix_effect_breathing_single(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1);
struct razer_report razer_chroma_extended_matrix_effect_breathing_dual(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1, struct razer_rgb *rgb2);
struct razer_report razer_chroma_extended_matrix_effect_custom_frame(void);
struct razer_report razer_chroma_extended_matrix_brightness(unsigned char variable_storage, unsigned char led_id, unsigned char brightness);
struct razer_report razer_chroma_extended_matrix_get_brightness(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_extended_matrix_set_custom_frame(unsigned char row_index, unsigned char start_col, unsigned char stop_col, unsigned char *rgb_data);
struct razer_report razer_chroma_extended_matrix_set_custom_frame2(unsigned char row_index, unsigned char start_col, unsigned char stop_col, unsigned char *rgb_data, size_t packetLength);

/*
 * Extended Matrix Effects (Mouse) Functions
 *
 * Class 0x0D
 * Trans 0x3F (not set) (Dev 0b001 Game Controller 1, Trans 0b11111)
 */
struct razer_report razer_chroma_mouse_extended_matrix_effect_none(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_mouse_extended_matrix_effect_static(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1);
struct razer_report razer_chroma_mouse_extended_matrix_effect_spectrum(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_mouse_extended_matrix_effect_reactive(unsigned char variable_storage, unsigned char led_id, unsigned char speed, struct razer_rgb *rgb1);
struct razer_report razer_chroma_mouse_extended_matrix_effect_breathing_random(unsigned char variable_storage, unsigned char led_id);
struct razer_report razer_chroma_mouse_extended_matrix_effect_breathing_single(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1);
struct razer_report razer_chroma_mouse_extended_matrix_effect_breathing_dual(unsigned char variable_storage, unsigned char led_id, struct razer_rgb *rgb1, struct razer_rgb *rgb2);

/*
 * Misc Functions
 */
struct razer_report razer_chroma_misc_fn_key_toggle(unsigned char state);

struct razer_report razer_chroma_misc_set_keyswitch_optimization_command1(unsigned char optimization_mode);
struct razer_report razer_chroma_misc_set_keyswitch_optimization_command2(unsigned char optimization_mode);
struct razer_report razer_chroma_misc_get_keyswitch_optimization(void);

struct razer_report razer_chroma_misc_set_blade_brightness(unsigned char brightness);
struct razer_report razer_chroma_misc_get_blade_brightness(void);

struct razer_report razer_chroma_misc_one_row_set_custom_frame(unsigned char start_col, unsigned char stop_col, unsigned char *rgb_data);
struct razer_report razer_chroma_misc_matrix_reactive_trigger(void);

struct razer_report razer_chroma_misc_get_battery_level(void);
struct razer_report razer_chroma_misc_get_charging_status(void);

struct razer_report razer_chroma_misc_set_dock_charge_type(unsigned char charge_type);

struct razer_report razer_chroma_misc_get_polling_rate(void);
struct razer_report razer_chroma_misc_set_polling_rate(unsigned short polling_rate);

struct razer_report razer_chroma_misc_get_polling_rate2(void);
struct razer_report razer_chroma_misc_set_polling_rate2(unsigned short polling_rate, unsigned short argument);

struct razer_report razer_chroma_misc_get_dock_brightness(void);
struct razer_report razer_chroma_misc_set_dock_brightness(unsigned char brightness);

struct razer_report razer_chroma_misc_set_dpi_xy(unsigned char variable_storage, unsigned short dpi_x,unsigned short dpi_y);
struct razer_report razer_chroma_misc_get_dpi_xy(unsigned char variable_storage);

struct razer_report razer_chroma_misc_set_dpi_xy_byte(unsigned char dpi_x,unsigned char dpi_y);
struct razer_report razer_chroma_misc_get_dpi_xy_byte(void);

struct razer_report razer_chroma_misc_set_dpi_stages(unsigned char variable_storage, unsigned char count, unsigned char active_stage, const unsigned short *dpi);
struct razer_report razer_chroma_misc_get_dpi_stages(unsigned char variable_storage);

struct razer_report razer_chroma_misc_get_idle_time(void);
struct razer_report razer_chroma_misc_set_idle_time(unsigned short idle_time);

struct razer_report razer_chroma_misc_get_low_battery_threshold(void);
struct razer_report razer_chroma_misc_set_low_battery_threshold(unsigned char battery_threshold);

struct razer_report razer_chroma_misc_set_orochi2011_led(unsigned char led_bitfield);
struct razer_report razer_chroma_misc_set_orochi2011_poll_dpi(unsigned short poll_rate, unsigned char dpi_x, unsigned char dpi_y);

struct razer_report razer_naga_trinity_effect_static(struct razer_rgb* rgb);

struct razer_report razer_chroma_misc_set_scroll_mode(unsigned int scroll_mode);
struct razer_report razer_chroma_misc_get_scroll_mode(void);

struct razer_report razer_chroma_misc_set_scroll_acceleration(bool acceleration);
struct razer_report razer_chroma_misc_get_scroll_acceleration(void);

struct razer_report razer_chroma_misc_set_scroll_smart_reel(bool smart_reel);
struct razer_report razer_chroma_misc_get_scroll_smart_reel(void);

struct razer_report razer_chroma_misc_set_hyperpolling_wireless_dongle_indicator_led_mode(unsigned char mode);
struct razer_report razer_chroma_misc_set_hyperpolling_wireless_dongle_pair_step1(unsigned short pid);
struct razer_report razer_chroma_misc_set_hyperpolling_wireless_dongle_pair_step2(unsigned short pid);
struct razer_report razer_chroma_misc_set_hyperpolling_wireless_dongle_unpair(unsigned short pid);

struct razer_report razer_chroma_set_power_mode(unsigned char mode, unsigned char zone, unsigned char fan_rpm);
struct razer_report razer_chroma_get_power_mode(unsigned char zone);

struct razer_report razer_chroma_set_boost(unsigned char zone, unsigned char boost);
struct razer_report razer_chroma_get_boost(unsigned char zone);

struct razer_report razer_chroma_set_fan_speed(unsigned char zone, unsigned char fan_rpm);
struct razer_report razer_chroma_get_fan_speed(unsigned char zone);

struct razer_report razer_chroma_set_bho(unsigned char threshold);
struct razer_report razer_chroma_get_bho(void);

#endif
