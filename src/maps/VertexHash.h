/*
 * VertexHash.h
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

#ifndef ETL_VERTEXHASH_H
#define ETL_VERTEXHASH_H

#include <stxxl.h>
#include "../etl.h"

struct VertexHashComparator
{
    bool operator () (const LONG_NUMERIC & a, const LONG_NUMERIC & b) const
    { return a > b; }
    static int max_value()
    { return std::numeric_limits<LONG_NUMERIC>::max(); }
};


class VertexHash {
    bool is_primary_memory;
    std::unordered_map<LONG_NUMERIC, LONG_NUMERIC> primary_memory_map;
    stxxl::map<LONG_NUMERIC, LONG_NUMERIC, VertexHashComparator, 4096, 4096> secondary_memory_map;

public:
    VertexHash(bool isPrimaryMemory);
    void put(LONG_NUMERIC& vertexId, LONG_NUMERIC& hash);
    LONG_NUMERIC operator[](const LONG_NUMERIC& vertexId);
};


#endif //ETL_VERTEXHASH_H
