/*
 * VertexHash.cpp
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

#include "VertexHash.h"

VertexHash::VertexHash(bool isPrimaryMemory) :
        is_primary_memory(isPrimaryMemory)/*,
        secondary_memory_map{
            ConfigurationFile::getInstance().vertex_hash_sm_no_block_cache,
            ConfigurationFile::getInstance().vertex_hash_sm_no_leaf_block_cache
        }*/
{

}

void VertexHash::put(LONG_NUMERIC &vertexId, LONG_NUMERIC &hash) {
    if (is_primary_memory) {
        primary_memory_map.emplace(vertexId, hash);
    } else {
        // Inserting the data as an array of two elements
        LONG_NUMERIC memo[2];
        memo[0] = vertexId;
        memo[1] = hash;
        secondary_memory_map.insert((void*)memo, sizeof(LONG_NUMERIC)*2);
    }
}

LONG_NUMERIC VertexHash::operator[](LONG_NUMERIC &vertexId) {
    if (is_primary_memory) {
        return primary_memory_map[vertexId];
    } else {
        // 1) Returning the actual object having
        // 2) Accessing to the second, that is the value, field
        return ((LONG_NUMERIC*)((struct iovec*)secondary_memory_map[vertexId]))[1];
    }
}