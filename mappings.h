// Copyright (c) 2001 Peter Karlsson
//
// This file is auto-generated by makemappings.pl
// $Id: mappings.h,v 1.3 2001/06/11 16:12:03 peterk Exp $
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __MAPPINGS_H
#define __MAPPINGS_H

/** Structure used to represent a mapping from Unicode. */
struct reversemap
{
    unsigned short unicode; ///< Unicode code point.
    char legacy;            ///< Value in legacy encoding.
};

/** Structure used to represent the fallback mapping table. */
struct fallbackmap
{
    unsigned short unicode; ///< Unicode code point.
    const char *fallback;   ///< Fallback string representing codepoint.
};

/** Incoming conversion table for ISO 8859-1 */
extern const unsigned short iso_8859_1[256];
/** Outgoing conversion table for ISO 8859-1 */
extern const struct reversemap iso_8859_1_rev[128];
/** Length of mapping table for ISO 8859-1 */
const unsigned short iso_8859_1_rev_len = 128;

/** Incoming conversion table for ISO 8859-10 */
extern const unsigned short iso_8859_10[256];
/** Outgoing conversion table for ISO 8859-10 */
extern const struct reversemap iso_8859_10_rev[128];
/** Length of mapping table for ISO 8859-10 */
const unsigned short iso_8859_10_rev_len = 128;

/** Incoming conversion table for ISO 8859-13 */
extern const unsigned short iso_8859_13[256];
/** Outgoing conversion table for ISO 8859-13 */
extern const struct reversemap iso_8859_13_rev[128];
/** Length of mapping table for ISO 8859-13 */
const unsigned short iso_8859_13_rev_len = 128;

/** Incoming conversion table for ISO 8859-14 */
extern const unsigned short iso_8859_14[256];
/** Outgoing conversion table for ISO 8859-14 */
extern const struct reversemap iso_8859_14_rev[128];
/** Length of mapping table for ISO 8859-14 */
const unsigned short iso_8859_14_rev_len = 128;

/** Incoming conversion table for ISO 8859-15 */
extern const unsigned short iso_8859_15[256];
/** Outgoing conversion table for ISO 8859-15 */
extern const struct reversemap iso_8859_15_rev[128];
/** Length of mapping table for ISO 8859-15 */
const unsigned short iso_8859_15_rev_len = 128;

/** Incoming conversion table for ISO 8859-2 */
extern const unsigned short iso_8859_2[256];
/** Outgoing conversion table for ISO 8859-2 */
extern const struct reversemap iso_8859_2_rev[128];
/** Length of mapping table for ISO 8859-2 */
const unsigned short iso_8859_2_rev_len = 128;

/** Incoming conversion table for ISO 8859-3 */
extern const unsigned short iso_8859_3[256];
/** Outgoing conversion table for ISO 8859-3 */
extern const struct reversemap iso_8859_3_rev[121];
/** Length of mapping table for ISO 8859-3 */
const unsigned short iso_8859_3_rev_len = 121;

/** Incoming conversion table for ISO 8859-4 */
extern const unsigned short iso_8859_4[256];
/** Outgoing conversion table for ISO 8859-4 */
extern const struct reversemap iso_8859_4_rev[128];
/** Length of mapping table for ISO 8859-4 */
const unsigned short iso_8859_4_rev_len = 128;

/** Incoming conversion table for ISO 8859-5 */
extern const unsigned short iso_8859_5[256];
/** Outgoing conversion table for ISO 8859-5 */
extern const struct reversemap iso_8859_5_rev[128];
/** Length of mapping table for ISO 8859-5 */
const unsigned short iso_8859_5_rev_len = 128;

/** Incoming conversion table for ISO 8859-6 */
extern const unsigned short iso_8859_6[256];
/** Outgoing conversion table for ISO 8859-6 */
extern const struct reversemap iso_8859_6_rev[83];
/** Length of mapping table for ISO 8859-6 */
const unsigned short iso_8859_6_rev_len = 83;

/** Incoming conversion table for ISO 8859-7 */
extern const unsigned short iso_8859_7[256];
/** Outgoing conversion table for ISO 8859-7 */
extern const struct reversemap iso_8859_7_rev[122];
/** Length of mapping table for ISO 8859-7 */
const unsigned short iso_8859_7_rev_len = 122;

/** Incoming conversion table for ISO 8859-8 */
extern const unsigned short iso_8859_8[256];
/** Outgoing conversion table for ISO 8859-8 */
extern const struct reversemap iso_8859_8_rev[92];
/** Length of mapping table for ISO 8859-8 */
const unsigned short iso_8859_8_rev_len = 92;

/** Incoming conversion table for ISO 8859-9 */
extern const unsigned short iso_8859_9[256];
/** Outgoing conversion table for ISO 8859-9 */
extern const struct reversemap iso_8859_9_rev[128];
/** Length of mapping table for ISO 8859-9 */
const unsigned short iso_8859_9_rev_len = 128;

/** Incoming conversion table for Windows codepage 10000 (MacRoman) */
extern const unsigned short cp_10000[256];
/** Outgoing conversion table for Windows codepage 10000 (MacRoman) */
extern const struct reversemap cp_10000_rev[127];
/** Length of mapping table for Windows codepage 10000 (MacRoman) */
const unsigned short cp_10000_rev_len = 127;

/** Incoming conversion table for Windows codepage 1250 */
extern const unsigned short cp_1250[256];
/** Outgoing conversion table for Windows codepage 1250 */
extern const struct reversemap cp_1250_rev[128];
/** Length of mapping table for Windows codepage 1250 */
const unsigned short cp_1250_rev_len = 128;

/** Incoming conversion table for Windows codepage 1251 */
extern const unsigned short cp_1251[256];
/** Outgoing conversion table for Windows codepage 1251 */
extern const struct reversemap cp_1251_rev[128];
/** Length of mapping table for Windows codepage 1251 */
const unsigned short cp_1251_rev_len = 128;

/** Incoming conversion table for Windows codepage 1252 */
extern const unsigned short cp_1252[256];
/** Outgoing conversion table for Windows codepage 1252 */
extern const struct reversemap cp_1252_rev[128];
/** Length of mapping table for Windows codepage 1252 */
const unsigned short cp_1252_rev_len = 128;

/** Incoming conversion table for Windows codepage 1253 */
extern const unsigned short cp_1253[256];
/** Outgoing conversion table for Windows codepage 1253 */
extern const struct reversemap cp_1253_rev[125];
/** Length of mapping table for Windows codepage 1253 */
const unsigned short cp_1253_rev_len = 125;

/** Incoming conversion table for Windows codepage 1254 */
extern const unsigned short cp_1254[256];
/** Outgoing conversion table for Windows codepage 1254 */
extern const struct reversemap cp_1254_rev[128];
/** Length of mapping table for Windows codepage 1254 */
const unsigned short cp_1254_rev_len = 128;

/** Incoming conversion table for Windows codepage 1255 */
extern const unsigned short cp_1255[256];
/** Outgoing conversion table for Windows codepage 1255 */
extern const struct reversemap cp_1255_rev[117];
/** Length of mapping table for Windows codepage 1255 */
const unsigned short cp_1255_rev_len = 117;

/** Incoming conversion table for Windows codepage 1256 */
extern const unsigned short cp_1256[256];
/** Outgoing conversion table for Windows codepage 1256 */
extern const struct reversemap cp_1256_rev[128];
/** Length of mapping table for Windows codepage 1256 */
const unsigned short cp_1256_rev_len = 128;

/** Incoming conversion table for Windows codepage 1257 */
extern const unsigned short cp_1257[256];
/** Outgoing conversion table for Windows codepage 1257 */
extern const struct reversemap cp_1257_rev[126];
/** Length of mapping table for Windows codepage 1257 */
const unsigned short cp_1257_rev_len = 126;

/** Incoming conversion table for Windows codepage 1258 */
extern const unsigned short cp_1258[256];
/** Outgoing conversion table for Windows codepage 1258 */
extern const struct reversemap cp_1258_rev[128];
/** Length of mapping table for Windows codepage 1258 */
const unsigned short cp_1258_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 437 */
extern const unsigned short cp_437[256];
/** Outgoing conversion table for MS-DOS codepage 437 */
extern const struct reversemap cp_437_rev[128];
/** Length of mapping table for MS-DOS codepage 437 */
const unsigned short cp_437_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 737 */
extern const unsigned short cp_737[256];
/** Outgoing conversion table for MS-DOS codepage 737 */
extern const struct reversemap cp_737_rev[128];
/** Length of mapping table for MS-DOS codepage 737 */
const unsigned short cp_737_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 775 */
extern const unsigned short cp_775[256];
/** Outgoing conversion table for MS-DOS codepage 775 */
extern const struct reversemap cp_775_rev[128];
/** Length of mapping table for MS-DOS codepage 775 */
const unsigned short cp_775_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 850 */
extern const unsigned short cp_850[256];
/** Outgoing conversion table for MS-DOS codepage 850 */
extern const struct reversemap cp_850_rev[128];
/** Length of mapping table for MS-DOS codepage 850 */
const unsigned short cp_850_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 852 */
extern const unsigned short cp_852[256];
/** Outgoing conversion table for MS-DOS codepage 852 */
extern const struct reversemap cp_852_rev[128];
/** Length of mapping table for MS-DOS codepage 852 */
const unsigned short cp_852_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 857 */
extern const unsigned short cp_857[256];
/** Outgoing conversion table for MS-DOS codepage 857 */
extern const struct reversemap cp_857_rev[125];
/** Length of mapping table for MS-DOS codepage 857 */
const unsigned short cp_857_rev_len = 125;

/** Incoming conversion table for MS-DOS codepage 860 */
extern const unsigned short cp_860[256];
/** Outgoing conversion table for MS-DOS codepage 860 */
extern const struct reversemap cp_860_rev[128];
/** Length of mapping table for MS-DOS codepage 860 */
const unsigned short cp_860_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 861 */
extern const unsigned short cp_861[256];
/** Outgoing conversion table for MS-DOS codepage 861 */
extern const struct reversemap cp_861_rev[128];
/** Length of mapping table for MS-DOS codepage 861 */
const unsigned short cp_861_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 862 */
extern const unsigned short cp_862[256];
/** Outgoing conversion table for MS-DOS codepage 862 */
extern const struct reversemap cp_862_rev[128];
/** Length of mapping table for MS-DOS codepage 862 */
const unsigned short cp_862_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 863 */
extern const unsigned short cp_863[256];
/** Outgoing conversion table for MS-DOS codepage 863 */
extern const struct reversemap cp_863_rev[128];
/** Length of mapping table for MS-DOS codepage 863 */
const unsigned short cp_863_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 864 */
extern const unsigned short cp_864[256];
/** Outgoing conversion table for MS-DOS codepage 864 */
extern const struct reversemap cp_864_rev[126];
/** Length of mapping table for MS-DOS codepage 864 */
const unsigned short cp_864_rev_len = 126;

/** Incoming conversion table for MS-DOS codepage 865 */
extern const unsigned short cp_865[256];
/** Outgoing conversion table for MS-DOS codepage 865 */
extern const struct reversemap cp_865_rev[128];
/** Length of mapping table for MS-DOS codepage 865 */
const unsigned short cp_865_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 866 */
extern const unsigned short cp_866[256];
/** Outgoing conversion table for MS-DOS codepage 866 */
extern const struct reversemap cp_866_rev[128];
/** Length of mapping table for MS-DOS codepage 866 */
const unsigned short cp_866_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 869 */
extern const unsigned short cp_869[256];
/** Outgoing conversion table for MS-DOS codepage 869 */
extern const struct reversemap cp_869_rev[128];
/** Length of mapping table for MS-DOS codepage 869 */
const unsigned short cp_869_rev_len = 128;

/** Incoming conversion table for MS-DOS codepage 874 */
extern const unsigned short cp_874[256];
/** Outgoing conversion table for MS-DOS codepage 874 */
extern const struct reversemap cp_874_rev[120];
/** Length of mapping table for MS-DOS codepage 874 */
const unsigned short cp_874_rev_len = 120;

/** Incoming conversion table for ISO-IR-11 (Swedish/Finnish 7-bit) */
extern const unsigned short iso_ir_11[256];
/** Outgoing conversion table for ISO-IR-11 (Swedish/Finnish 7-bit) */
extern const struct reversemap iso_ir_11_rev[10];
/** Length of mapping table for ISO-IR-11 (Swedish/Finnish 7-bit) */
const unsigned short iso_ir_11_rev_len = 10;

/** Incoming conversion table for ISO-IR-60 (Norwegian/Danish 7-bit) */
extern const unsigned short iso_ir_60[256];
/** Outgoing conversion table for ISO-IR-60 (Norwegian/Danish 7-bit) */
extern const struct reversemap iso_ir_60_rev[6];
/** Length of mapping table for ISO-IR-60 (Norwegian/Danish 7-bit) */
const unsigned short iso_ir_60_rev_len = 6;

/** Incoming conversion table for KOI8-R */
extern const unsigned short koi8r[256];
/** Outgoing conversion table for KOI8-R */
extern const struct reversemap koi8r_rev[128];
/** Length of mapping table for KOI8-R */
const unsigned short koi8r_rev_len = 128;

/** Incoming conversion table for KOI8-U */
extern const unsigned short koi8u[256];
/** Outgoing conversion table for KOI8-U */
extern const struct reversemap koi8u_rev[128];
/** Length of mapping table for KOI8-U */
const unsigned short koi8u_rev_len = 128;

/** Incoming conversion table for MacRoman */
extern const unsigned short macroman[256];
/** Outgoing conversion table for MacRoman */
extern const struct reversemap macroman_rev[128];
/** Length of mapping table for MacRoman */
const unsigned short macroman_rev_len = 128;

/** Fallback mapping table */
extern const struct fallbackmap fallback[1765];
/** Length of fallback mapping */
const unsigned short fallbackmap_len = 1765;

#endif