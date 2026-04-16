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

#ifndef pal_ohos_PLAYERS_H
#define pal_ohos_PLAYERS_H

#include "util/common.h"

/**
 * 音频播放器抽象基类
 * 对应C代码中的AUDIOPLAYER_COMMONS宏
 * 改写成了C++的基类形式
 **/

class AudioPlayer {
public:
    virtual ~AudioPlayer() = default;

    virtual void shutdown();
    virtual bool play(int music_index, bool loop, float volume);
    virtual void fillBuffer(uint8_t *buffer, int size);

    // 成员变量访问器
    int getCurrentMusic() const { return m_iMusic; }
    void setCurrentMusic(int music) { m_iMusic = music; }

    bool isLooping() const { return m_floop; }
    void setLooping(bool loop) { m_floop = loop; }

protected:
    int m_iMusic = 0;
    bool m_floop = false;
};

// 对于生成不同播放器的函数，后续将按照需求进行实现

#endif // pal_ohos_PLAYER_H
