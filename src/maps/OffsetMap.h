/*
 * OffsetMap.h
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

#ifndef ETL_OFFSETMAP_H
#define ETL_OFFSETMAP_H

#include "../etl.h"
#include "../graphs/utils/secondary_memory/vertex_id_index.h"
#include <map>
#include <utility>
#include <cstdio>


/**
 * This map provides a strategy for keeping track of the offsets associated to each vertex id. Depending on the size of
 * the graph and on the size of the current computer main memory, it would keep it either in primary memory or in
 * secondary memory.
 */
class OffsetMap {
    // id -> {hash, offset}
    std::map<LONG_NUMERIC, std::pair<LONG_NUMERIC,LONG_NUMERIC>> primary_memory_map;

    std::string vertex_id_file;
    FILE* vertex_id_index;
    bool isFinished;
    bool is_strategy_primary_memory;

public:
    OffsetMap(bool isStrategyPrimaryMemory, std::string vertexIdFile);

    /**
     * Inserts the value for the indexing of the vertex offset
     *
     * @param id            Id of the vertex to serialize
     * @param offset        Offset of the vertex to serialize
     */
    void put(LONG_NUMERIC& id, LONG_NUMERIC& offset, LONG_NUMERIC& vertex_hash);

    /**
     * Finalising the writing of the vertex offset index
     *
     * In particular, if the strategy is in primary memory, then the primary memory already sorted the file by id, and
     * hence I'm serializing the already-sorted data. Otherwise, I've already serialized the data in secondary memory
     * without ordering it, and I'm forcing it to sort the data in there.
     */
    void serialize();

    void close();
    ~OffsetMap();

};


#endif //ETL_OFFSETMAP_H
