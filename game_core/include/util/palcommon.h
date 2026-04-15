/* -*- mode: c; tab-width: 4; c-basic-offset: 4; c-file-style: "linux" -*- */
//
// Copyright (c) 2009-2011, Wei Mingzhi <whistler_wmz@users.sf.net>.
// Copyright (c) 2011-2024, SDLPAL development team.
// All rights reserved.
// C++ port and optimizations Copyright (c) 2025-2026 funbocchi <lzx13735999188@petalmail.com>
// Based on the C version by Wei Mingzhi and SDLPAL development team.
//
// This file is part of SDLPAL.
//
// SDLPAL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License, version 3
// as published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef pal_ohos_PALCOMMON_H
#define pal_ohos_PALCOMMON_H

#include "util/common.h"

typedef enum tagPALFILE {
    PALFILE_ABC = 0x00000001,
    PALFILE_BALL = 0x00000002,
    PALFILE_DATA = 0x00000004,
    PALFILE_F = 0x00000008,
    PALFILE_FBP = 0x00000010,
    PALFILE_FIRE = 0x00000020,
    PALFILE_GOP = 0x00000040,
    PALFILE_MAP = 0x00000080,
    PALFILE_MGO = 0x00000100,
    PALFILE_PAT = 0x00000200,
    PALFILE_RGM = 0x00000400,
    PALFILE_RNG = 0x00000800,
    PALFILE_SSS = 0x00001000,
    PALFILE_MSG = 0x00002000,
    PALFILE_M = 0x00004000,
    PALFILE_WORD = 0x00008000,
    PALFILE_REQUIRED_MASK = 0x0000ffff,
    PALFILE_VOC = 0x00010000,
    PALFILE_SOUNDS = 0x00020000,
    PALFILE_SOUND_MASK = 0x00030000,
    PALFILE_MIDI = 0x00040000,
    PALFILE_MUS = 0x00080000,
    PALFILE_MUSIC_MASK = 0x000c0000,
} PALFILE;

#endif // pal_ohos_PALCOMMON_H
