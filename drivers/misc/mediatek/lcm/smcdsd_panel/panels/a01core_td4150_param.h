/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __TD4150_PARAM_H__
#define __TD4150_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>

#define LCD_TYPE_VENDOR		"BOE"

#define EXTEND_BRIGHTNESS	306
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128

#define LDI_REG_BRIGHTNESS	0x51
#define LDI_REG_ID		0xDA
#define LDI_LEN_BRIGHTNESS	((u16)ARRAY_SIZE(SEQ_TD4150_BRIGHTNESS))

/* len is read length */
#define LDI_LEN_ID		3

#define TYPE_WRITE		I2C_SMBUS_WRITE
#define TYPE_DELAY		U8_MAX

static u8 LM36274_INIT[] = {
	TYPE_WRITE, 0x0C, 0x2C,
	TYPE_WRITE, 0x0D, 0x26,
	TYPE_WRITE, 0x0E, 0x26,
	TYPE_WRITE, 0x09, 0xBE,
	TYPE_WRITE, 0x02, 0x49,
	TYPE_WRITE, 0x03, 0x0D,
	TYPE_WRITE, 0x11, 0x74,
	TYPE_WRITE, 0x04, 0x05,
	TYPE_WRITE, 0x05, 0xCC,
	TYPE_WRITE, 0x10, 0x67,
	TYPE_WRITE, 0x08, 0x13,
};

static u8 LM36274_EXIT[] = {
	TYPE_WRITE, 0x09, 0x18,
	TYPE_WRITE, 0x08, 0x00,
};

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_TD4150_BRIGHTNESS[] = {
	0x51,
	0x00,
};

static u8 SEQ_SLEEP_OUT[] = { 0x11 };
static u8 SEQ_SLEEP_IN[] = { 0x10 };
static u8 SEQ_DISPLAY_OFF[] = { 0x28 };
static u8 SEQ_DISPLAY_ON[] = { 0x29 };

static u8 SEQ_BRIGHTNESS_MODE[] = {
	0x53,
	0x0C,
};

static u8 SEQ_CABC_ON[] = {
	0x55,
	0x03,
};

static u8 SEQ_CMB_ON[] = {
	0x5E,
	0x30,
};

static u8 SEQ_TD4150_PV_B0_OPEN[] = {
	0xB0, 0x04,
};

static u8 SEQ_TD4150_PV_B6[] = {
	0xB6,
	0x30, 0x62, 0x00, 0x06, 0xC3, 0x03,
};

static u8 SEQ_TD4150_PV_B7[] = {
	0xB7,
	0x31, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_B8[] = {
	0xB8,
	0x00, 0x78, 0x64, 0x10, 0x64, 0xB4,
};

static u8 SEQ_TD4150_PV_B9[] = {
	0xB9,
	0x00, 0x78, 0x64, 0x10, 0x64, 0xB4,
};

static u8 SEQ_TD4150_PV_BA[] = {
	0xBA,
	0x03, 0x6A, 0x5D, 0x0E, 0x45, 0x44,
};

static u8 SEQ_TD4150_PV_BB[] = {
	0xBB,
	0x00, 0xB4, 0xA0,
};

static u8 SEQ_TD4150_PV_BC[] = {
	0xBC,
	0x00, 0xB4, 0xA0,
};

static u8 SEQ_TD4150_PV_BD[] = {
	0xBD,
	0x00, 0xB4, 0xA0,
};

static u8 SEQ_TD4150_PV_BE[] = {
	0xBE,
	0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_C0[] = {
	0xC0,
	0x00, 0x8F, 0x11, 0x05, 0xC8, 0x00, 0x0B, 0x06, 0xB3, 0x00,
	0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_C1[] = {
	0xC1,
	0x30, 0x11, 0x50, 0xFA, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00
};

static u8 SEQ_TD4150_PV_C2[] = {
	0xC2,
	0x00, 0x20, 0x5A, 0x22, 0x05, 0x00, 0x06, 0x12, 0x00, 0x04,
	0xF0, 0x0F, 0x22, 0x06, 0x00, 0x06, 0x11, 0x00, 0x02, 0x30,
	0x7C, 0x01, 0x05, 0x00, 0x01, 0x00, 0x00, 0x00, 0x20, 0x5A,
	0x01, 0x05, 0x05, 0xDC, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x30, 0x36, 0x08, 0x08, 0x04, 0x05, 0x05,
	0x00, 0xA5, 0xD8, 0x03, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00,
	0x00, 0x11, 0x00, 0xA5, 0xD8, 0x08, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x04, 0xA0, 0x7D, 0x08, 0x08, 0x04,
	0x05, 0x05, 0x00, 0xA5, 0xD8, 0x03, 0x00, 0x10, 0x08, 0x00,
	0x00, 0x00, 0x00, 0x11, 0x00, 0xA5, 0xD8, 0x08, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00,
	0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_C3[] = {
	0xC3,
	0x00, 0x40, 0x01, 0x01, 0x5E, 0x10, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x23, 0x00, 0x07, 0x10, 0x3B, 0x01, 0x65, 0x10,
	0x0A, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_C4[] = {
	0xC4,
	0x00, 0x57, 0x0B, 0x00, 0x03, 0x04, 0x61, 0x55, 0x1A, 0x19,
	0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x02, 0x02, 0x02, 0x02,
	0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
	0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x55, 0x61,
	0x08, 0x07, 0x00, 0x0B, 0x57, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x7F, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00,
	0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F,
	0x3F, 0x3F, 0x3F, 0x55, 0x55, 0x55, 0xD5, 0xFF, 0xFF, 0xFF,
	0x57, 0x55, 0x55, 0x55,
};

static u8 SEQ_TD4150_PV_C5[] = {
	0xC5,
	0x08, 0x00, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_C6[] = {
	0xC6,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x04, 0x00,
	0x40, 0x2C, 0x00, 0x00, 0x04, 0x00, 0x40, 0x3C, 0x0F, 0x05,
	0x01, 0x19, 0x01, 0x35, 0xFF, 0x8F, 0x06, 0x05, 0x01, 0xC0,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 0xC0, 0x11,
	0x1F, 0x00, 0x00, 0x10, 0x10, 0x00, 0x01, 0xF0, 0x01, 0x00,
	0x50, 0x00, 0x33, 0x03,
};

static u8 SEQ_TD4150_PV_C7[] = {
	0xC7,
	0x00, 0x00, 0x00, 0x68, 0x00, 0xA7, 0x00, 0xBA, 0x00, 0xCF,
	0x00, 0xD9, 0x00, 0xE3, 0x00, 0xE3, 0x00, 0xF8, 0x00, 0xB1,
	0x01, 0x15, 0x00, 0x8D, 0x00, 0xFA, 0x00, 0xC7, 0x01, 0x35,
	0x01, 0x73, 0x02, 0x13, 0x02, 0x96, 0x02, 0xA0, 0x00, 0x00,
	0x00, 0x68, 0x00, 0xA7, 0x00, 0xBA, 0x00, 0xCF, 0x00, 0xD9,
	0x00, 0xE3, 0x00, 0xE3, 0x01, 0x08, 0x00, 0xF1, 0x01, 0x35,
	0x01, 0x3D, 0x01, 0x5A, 0x01, 0x07, 0x01, 0x75, 0x01, 0x73,
	0x02, 0x13, 0x02, 0x96, 0x02, 0xA0,
};

static u8 SEQ_TD4150_PV_C8[] = {
	0xC8,
	0x40, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00,
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0xFC,
};

static u8 SEQ_TD4150_PV_C9[] = {
	0xC9,
	0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x00, 0x24, 0x8B,
	0x4D, 0x8B, 0x4D, 0x8B, 0x4D,
};

static u8 SEQ_TD4150_PV_CA[] = {
	0xCA,
	0x1C, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00
};

static u8 SEQ_TD4150_PV_CB[] = {
	0xCB,
	0x12, 0xD0, 0x09, 0xC1, 0xB9, 0x65, 0x30, 0xA8, 0x74, 0x21,
	0xB8, 0x75, 0x21, 0xA9, 0x64, 0x30, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x70, 0x00, 0x24, 0x00, 0x00, 0x00, 0xFF
};

static u8 SEQ_TD4150_PV_CE[] = {
	0xCE,
	0x7D, 0x40, 0x60, 0x80, 0x9C, 0xAF, 0xBE, 0xCE, 0xD9, 0xE5,
	0xEB, 0xF1, 0xF5, 0xF8, 0xFB, 0xFD, 0xFF, 0x0A, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_CF[] = {
	0xCF,
	0x00,
};

static u8 SEQ_TD4150_PV_D0[] = {
	0xD0,
	0xC2, 0x32, 0x81, 0x66, 0x09, 0x90, 0x00, 0xC0, 0x92, 0x80,
	0x12, 0x46, 0x06, 0x7E, 0x09, 0x08, 0xD0, 0x00,
};

static u8 SEQ_TD4150_PV_D1[] = {
	0xD1,
	0xD0, 0xD8, 0x1B, 0x33, 0x33, 0x17, 0x07, 0x3B, 0x55, 0x74,
	0x55, 0x74, 0x00, 0x33, 0x77, 0x07, 0x33, 0x30, 0x06, 0x72,
	0x13, 0x13, 0x00
};

static u8 SEQ_TD4150_PV_D2[] = {
	0xD2,
	0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_D3[] = {
	0xD3,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF,
	0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7,
	0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF, 0xFF, 0xF7, 0xFF,
	0xFF, 0xF7, 0xFF,
};

static u8 SEQ_TD4150_PV_E5[] = {
	0xE5,
	0x03, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_D6[] = {
	0xD6,
	0x00,
};

static u8 SEQ_TD4150_PV_D7[] = {
	0xD7,
	0x21, 0x00, 0x12, 0x12, 0x00, 0x70, 0x08, 0x58, 0x00, 0x70,
	0x08, 0x58, 0x00, 0x83, 0x80, 0x85, 0x85, 0x85, 0x87, 0x84,
	0x45, 0x86, 0x87, 0x80, 0x82, 0x80, 0x80, 0x83, 0x83, 0x88,
	0x84, 0x08, 0x0C, 0x0C, 0x0B, 0x0A, 0x0A, 0x0A, 0x07, 0x07,
	0x06, 0x06, 0x0C, 0x08,
};

static u8 SEQ_TD4150_PV_D9[] = {
	0xD9,
	0x00, 0x02, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_DD[] = {
	0xDD,
	0x30, 0x06, 0x23, 0x65,
};

static u8 SEQ_TD4150_PV_DE[] = {
	0xDE,
	0x00, 0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x10,
	0x00, 0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_E3[] = {
	0xE3,
	0xFF,
};

static u8 SEQ_TD4150_PV_E9[] = {
	0xE9,
	0x80, 0x11, 0x17, 0x00, 0x00, 0x00, 0x5C, 0x00, 0xFF, 0xBF,
	0x05, 0xFF, 0x9F, 0x04, 0xFF, 0x7F, 0x06, 0xFF, 0x3F, 0x05,
	0xFF, 0x9F, 0x04, 0xFF, 0xCF, 0x07, 0xFF, 0xE7, 0x07, 0xFF,
	0xF3, 0x07, 0xFF, 0xF9, 0x07, 0xCD, 0xFF, 0x07, 0xE4, 0xFF,
	0x07, 0xF3, 0xFF, 0x07, 0xE9, 0xFF, 0x07, 0xE4, 0xFC, 0x07,
	0x7F, 0xFE, 0x07, 0x3F, 0xFF, 0x07, 0x9F, 0xFF, 0x07, 0xDF,
	0xFF, 0x07, 0x0C,
};

static u8 SEQ_TD4150_PV_EA[] = {
	0xEA,
	0x02, 0x0A, 0x14, 0x08, 0xE1, 0x0A, 0x20, 0xA2, 0x00, 0x00,
	0x00, 0x0A, 0x23, 0x00, 0x03, 0x01, 0x16, 0x01, 0x16, 0x01,
	0x16, 0x01, 0x28, 0x01, 0x28, 0x00, 0x70, 0x00, 0x00, 0x00,
	0x7F, 0x00, 0x34, 0x00,
};

static u8 SEQ_TD4150_PV_EB[] = {
	0xEB,
	0x0A, 0xB0, 0x9D, 0x04, 0x71, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_EC[] = {
	0xEC,
	0x01, 0xC0, 0x00, 0x10, 0x9B, 0x0A, 0x20, 0xA2, 0x00, 0x00,
	0x00, 0x01, 0x2B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00,
};

static u8 SEQ_TD4150_PV_ED[] = {
	0xED,
	0x01, 0x02, 0x06, 0x07, 0x00, 0x00, 0x02, 0x01, 0x5E, 0x20,
	0x00, 0x00, 0x08, 0x00, 0x80, 0x08, 0x00, 0x00, 0x00, 0x01,
	0x0F, 0x00, 0x01, 0x30, 0x01, 0x01, 0x0F, 0x00, 0x00, 0x10,
	0x81, 0x10, 0x01,
};

static u8 SEQ_TD4150_PV_EE[] = {
	0xEE,
	0x05, 0x40, 0x05, 0x00, 0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00,
	0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00, 0xC0, 0x0F, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xC0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xFF, 0x3F, 0x00, 0xC0, 0x0F, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x02,
};

static u8 SEQ_TD4150_PV_B0_CLOSE[] = {
	0xB0,
	0x03,
};

static struct lcd_seq_info LCD_SEQ_INIT_1[] = {
	{SEQ_TD4150_PV_B0_OPEN, ARRAY_SIZE(SEQ_TD4150_PV_B0_OPEN), 0, },
	{SEQ_TD4150_PV_B6, ARRAY_SIZE(SEQ_TD4150_PV_B6), 0, },
	{SEQ_TD4150_PV_B7, ARRAY_SIZE(SEQ_TD4150_PV_B7), 0, },
	{SEQ_TD4150_PV_B8, ARRAY_SIZE(SEQ_TD4150_PV_B8), 0, },
	{SEQ_TD4150_PV_B9, ARRAY_SIZE(SEQ_TD4150_PV_B9), 0, },
	{SEQ_TD4150_PV_BA, ARRAY_SIZE(SEQ_TD4150_PV_BA), 0, },
	{SEQ_TD4150_PV_BB, ARRAY_SIZE(SEQ_TD4150_PV_BB), 0, },
	{SEQ_TD4150_PV_BC, ARRAY_SIZE(SEQ_TD4150_PV_BC), 0, },
	{SEQ_TD4150_PV_BD, ARRAY_SIZE(SEQ_TD4150_PV_BD), 0, },
	{SEQ_TD4150_PV_BE, ARRAY_SIZE(SEQ_TD4150_PV_BE), 0, },
	{SEQ_TD4150_PV_C0, ARRAY_SIZE(SEQ_TD4150_PV_C0), 0, },
	{SEQ_TD4150_PV_C1, ARRAY_SIZE(SEQ_TD4150_PV_C1), 0, },
	{SEQ_TD4150_PV_C2, ARRAY_SIZE(SEQ_TD4150_PV_C2), 0, },
	{SEQ_TD4150_PV_C3, ARRAY_SIZE(SEQ_TD4150_PV_C3), 0, },
	{SEQ_TD4150_PV_C4, ARRAY_SIZE(SEQ_TD4150_PV_C4), 0, },
	{SEQ_TD4150_PV_C5, ARRAY_SIZE(SEQ_TD4150_PV_C5), 0, },
	{SEQ_TD4150_PV_C6, ARRAY_SIZE(SEQ_TD4150_PV_C6), 0, },
	{SEQ_TD4150_PV_C7, ARRAY_SIZE(SEQ_TD4150_PV_C7), 0, },
	{SEQ_TD4150_PV_C8, ARRAY_SIZE(SEQ_TD4150_PV_C8), 0, },
	{SEQ_TD4150_PV_C9, ARRAY_SIZE(SEQ_TD4150_PV_C9), 0, },
	{SEQ_TD4150_PV_CA, ARRAY_SIZE(SEQ_TD4150_PV_CA), 0, },
	{SEQ_TD4150_PV_CB, ARRAY_SIZE(SEQ_TD4150_PV_CB), 0, },
	{SEQ_TD4150_PV_CE, ARRAY_SIZE(SEQ_TD4150_PV_CE), 0, },
	{SEQ_TD4150_PV_CF, ARRAY_SIZE(SEQ_TD4150_PV_CF), 0, },
	{SEQ_TD4150_PV_D0, ARRAY_SIZE(SEQ_TD4150_PV_D0), 0, },
	{SEQ_TD4150_PV_D1, ARRAY_SIZE(SEQ_TD4150_PV_D1), 0, },
	{SEQ_TD4150_PV_D2, ARRAY_SIZE(SEQ_TD4150_PV_D2), 0, },
	{SEQ_TD4150_PV_D3, ARRAY_SIZE(SEQ_TD4150_PV_D3), 0, },
	{SEQ_TD4150_PV_E5, ARRAY_SIZE(SEQ_TD4150_PV_E5), 0, },
	{SEQ_TD4150_PV_D6, ARRAY_SIZE(SEQ_TD4150_PV_D6), 0, },
	{SEQ_TD4150_PV_D7, ARRAY_SIZE(SEQ_TD4150_PV_D7), 0, },
	{SEQ_TD4150_PV_D9, ARRAY_SIZE(SEQ_TD4150_PV_D9), 0, },
	{SEQ_TD4150_PV_DD, ARRAY_SIZE(SEQ_TD4150_PV_DD), 0, },
	{SEQ_TD4150_PV_DE, ARRAY_SIZE(SEQ_TD4150_PV_DE), 0, },
	{SEQ_TD4150_PV_E3, ARRAY_SIZE(SEQ_TD4150_PV_E3), 0, },
	{SEQ_TD4150_PV_E9, ARRAY_SIZE(SEQ_TD4150_PV_E9), 0, },
	{SEQ_TD4150_PV_EA, ARRAY_SIZE(SEQ_TD4150_PV_EA), 0, },
	{SEQ_TD4150_PV_EB, ARRAY_SIZE(SEQ_TD4150_PV_EB), 0, },
	{SEQ_TD4150_PV_EC, ARRAY_SIZE(SEQ_TD4150_PV_EC), 0, },
	{SEQ_TD4150_PV_ED, ARRAY_SIZE(SEQ_TD4150_PV_ED), 0, },
	{SEQ_TD4150_PV_EE, ARRAY_SIZE(SEQ_TD4150_PV_EE), 0, },
	{SEQ_TD4150_PV_B0_CLOSE, ARRAY_SIZE(SEQ_TD4150_PV_B0_CLOSE), 0, },
	{SEQ_DISPLAY_ON, ARRAY_SIZE(SEQ_DISPLAY_ON), 0, },

	{SEQ_SLEEP_OUT, ARRAY_SIZE(SEQ_SLEEP_OUT), 70*1000, },
	//msleep(70);/* wait 4 frame */
	{SEQ_BRIGHTNESS_MODE, ARRAY_SIZE(SEQ_BRIGHTNESS_MODE), 0, },
	{SEQ_CABC_ON, ARRAY_SIZE(SEQ_CABC_ON), 0, },
	{SEQ_CMB_ON, ARRAY_SIZE(SEQ_CMB_ON), 0, },
};

static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	0,
	2, 2, 3, 3, 4, 5, 5, 6, 6, 7, /* 1: 2 */
	8, 8, 9, 10, 10, 11, 11, 12, 13, 13,
	14, 15, 15, 16, 16, 17, 18, 18, 19, 20,
	20, 21, 21, 22, 23, 23, 24, 25, 25, 26,
	26, 27, 28, 28, 29, 29, 30, 31, 31, 32,
	33, 33, 34, 34, 35, 36, 36, 37, 38, 38,
	39, 39, 40, 41, 41, 42, 43, 43, 44, 44,
	45, 46, 46, 47, 48, 48, 49, 49, 50, 51,
	51, 52, 53, 53, 54, 54, 55, 56, 56, 57,
	57, 58, 59, 59, 60, 61, 61, 62, 62, 63,
	64, 64, 65, 66, 66, 67, 67, 68, 69, 69,
	70, 71, 71, 72, 72, 73, 74, 74, 75, 76,
	76, 77, 77, 78, 79, 79, 80, 81, 81, 82, /* 128: 81 */
	83, 84, 85, 86, 87, 88, 88, 89, 90, 91,
	92, 93, 94, 95, 95, 96, 97, 98, 99, 100,
	101, 102, 103, 103, 104, 105, 106, 107, 108, 109,
	110, 110, 111, 112, 113, 114, 115, 116, 117, 118,
	118, 119, 120, 121, 122, 123, 124, 125, 125, 126,
	127, 128, 129, 130, 131, 132, 133, 133, 134, 135,
	136, 137, 138, 139, 140, 140, 141, 142, 143, 144,
	145, 146, 147, 148, 148, 149, 150, 151, 152, 153,
	154, 155, 155, 156, 157, 158, 159, 160, 161, 162,
	163, 163, 164, 165, 166, 167, 168, 169, 170, 170,
	171, 172, 173, 174, 175, 176, 177, 178, 178, 179,
	180, 181, 182, 183, 184, 185, 185, 186, 187, 188,
	189, 190, 191, 192, 193, 193, 193, 193, 193, 193, /* 255: 193 */
	193, 193, 193, 193, 193, 193, 193, 193, 193, 193,
	193, 193, 193, 193, 193, 193, 193, 193, 193, 193,
	193, 193, 193, 193, 193, 193, 193, 193, 193, 193,
	193, 193, 193, 193, 193, 193, 193, 193, 193, 193,
	193, 193, 193, 193, 193, 232,
};

#endif /* __TD4150_PARAM_H__ */
