/** -*- mode: c; tab-width: 4; c-basic-offset: 4; c-file-style: "linux" -*-
 *
 * Copyright (c) 2009-2011, Wei Mingzhi <whistler_wmz@users.sf.net>.
 * Copyright (c) 2011-2024, SDLPAL development team.
 * All rights reserved.
 *
 * C++ port and optimizations Copyright (c) 2025-2026, FunBocchi <lzx13735999188@petalmail.com>
 *
 *
 * This file is part of SDLPAL.
 *
 * SDLPAL is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

// 该文件用于统一存放一些公共引用的头文件，例如stdint

#ifndef pal_ohos_COMMON_H
#define pal_ohos_COMMON_H

#include <stdint.h>

#include <rawfile/raw_file.h>

/**
 * 以下是针对各种类型的别名设置
 * 同等于源项目中同名文件的定位
 **/
using SHORT = short;
using WORD = unsigned short;
using USHORT = unsigned short;

// 以下为额外添加的别名（区别于源项目）
using LPRAWFILE = RawFile *;//用于替代FILE用以读取文件
#endif // pal_ohos_COMMON_H
