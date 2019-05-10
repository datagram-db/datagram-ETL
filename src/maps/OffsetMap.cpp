/*
 * OffsetMap.cpp
 * This file is part of GatorLAND_ETL
 *
 * Copyright (C) 2019 - Giacomo Bergami
 *
 * GatorLAND_ETL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * GatorLAND_ETL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GatorLAND_ETL. If not, see <http://www.gnu.org/licenses/>.
 */

 
//
// Created by giacomo on 06/05/19.
//

#include "OffsetMap.h"

#define ACTUAL_SERIALIZE(id, offset, vertx_hash) do {\
    struct vertex_id_index pix{id, vertx_hash, offset};\
    fwrite(&pix, sizeof(struct vertex_id_index), 1, vertex_id_index);\
} while(0)


OffsetMap::OffsetMap(bool isStrategyPrimaryMemory, std::string vertexIdFile)
        : is_strategy_primary_memory(isStrategyPrimaryMemory), isFinished{false}, vertex_id_file(vertexIdFile),
        secondary_memory{{sizeof(vertex_id_index)}, isStrategyPrimaryMemory ? vertexIdFile : std::tmpnam(NULL)} {
    // I need to open the file only once
    if (isStrategyPrimaryMemory) {
        secondary_memory.doclose();
        vertex_id_index = fopen64(vertex_id_file.c_str(), "w");
    }

}

OffsetMap::~OffsetMap() {
    close();
}

void OffsetMap::close() {
    if (vertex_id_index) {
        fclose(vertex_id_index);
        vertex_id_index = nullptr;
    }
}

void OffsetMap::put(LONG_NUMERIC &id, LONG_NUMERIC &offset, LONG_NUMERIC &vertex_hash) {
    if (is_strategy_primary_memory) {
        primary_memory_map.emplace(id, std::make_pair(vertex_hash, offset));
    } else {
        struct vertex_id_index pix{id, vertex_hash, offset};
        secondary_memory.insert((void*)&pix, sizeof(struct vertex_id_index));
        ACTUAL_SERIALIZE(id, offset, vertex_hash);
    }
}

void OffsetMap::serialize() {
    if (vertex_id_index) {
        if (is_strategy_primary_memory) {
            // I need to explicitely serialize only if I did not sorted the data in primary memory using the primary memory strategy.
            for (std::map<LONG_NUMERIC, std::pair<LONG_NUMERIC, LONG_NUMERIC>>::iterator beg = primary_memory_map.begin(), en = primary_memory_map.end();
                 beg != en; beg++) {
                ACTUAL_SERIALIZE(beg->first, beg->second.second, beg->second.first);
            }
        } else {
            // In this case, I just sort the already-serialized data.
            secondary_memory.sortPair();
        }
    }
}
