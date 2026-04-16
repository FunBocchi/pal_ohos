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

#ifndef pal_ohos_PLAY_H
#define pal_ohos_PLAY_H

#include "util/common.h"

namespace PalGame {

void update(bool f_trigger);
void userItem();
void equipItem();
void startFrame();
void waitForKey(uint16_t w_time_out);
void waitForAnyKey(uint16_t w_time_out);

} // namespace PalGame

#endif // pal_ohos_PLAY_H
