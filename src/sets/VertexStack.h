/*
 * VertexStack.h
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

#ifndef ETL_VERTEXSTACK_H
#define ETL_VERTEXSTACK_H

#include "../etl.h"
#include <algorithm>
#include <vector>
#include <cassert>

#include <stxxl.h>

struct VertexStack {
    stxxl::vector<LONG_NUMERIC> secondary_memory;
    stxxl::vector<LONG_NUMERIC>::iterator sm_begin, sm_end;

    std::vector<LONG_NUMERIC> primary_memory;
    std::vector<LONG_NUMERIC>::iterator pm_begin, pm_end;
    bool is_primary_memory;
    LONG_NUMERIC secondary_memory_limit;

    LONG_NUMERIC size;

    /**
     * Initializes a vertex stack, that is an ordering over the vertices
     * As a rule of thumb, use isPrimaryMemory only up to 100M nodes.
     *
     * @param isPrimaryMemory
     */
    VertexStack(bool isPrimaryMemory, LONG_NUMERIC secondaryMemoryLimit);

    /**
     * Inserts a new vertex
     * @param vertex_id
     */
    void put(LONG_NUMERIC& vertex_id);

    /**
     * Sorting the vertices by id
     */
    void sort();

    /**
     * Initializing the iteration over the sorted stack
     */
    void initIteration();

    /**
     * Checking whether we can continue the iteration
     * @return  returns yes if we can continue to iterate, and false otherwise
     */
    bool hasNextVertex();

    /**
     * Returns the current element in the iteration, and evaluate the next step
     * @return Current vertex
     */
    LONG_NUMERIC next();
};


#endif //ETL_VERTEXSTACK_H
