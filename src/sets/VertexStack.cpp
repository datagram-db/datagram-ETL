/*
 * VertexStack.cpp
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

#include "VertexStack.h"

struct VertexStackSTXXLSorter
{
    // comparison function
    bool operator () (const LONG_NUMERIC & a, const LONG_NUMERIC& b) const {
        return a < b;
    }
    // min sentinel = value which is strictly smaller that any input element
    static LONG_NUMERIC min_value() {
        return std::numeric_limits<LONG_NUMERIC>::min();
    }
    // max sentinel = value which is strictly larger that any input element
    static LONG_NUMERIC max_value() {
        return std::numeric_limits<LONG_NUMERIC>::max();
    }
};

VertexStack::VertexStack(bool isPrimaryMemory, LONG_NUMERIC secondaryMemoryLimit)
        : is_primary_memory(isPrimaryMemory), secondary_memory_limit(secondaryMemoryLimit) {}

void VertexStack::put(LONG_NUMERIC &vertex_id) {
    if (is_primary_memory) {
        primary_memory.emplace_back(vertex_id);
    } else {
        secondary_memory.push_back(vertex_id);
    }
    size++;
}

void VertexStack::sort() {
    if (is_primary_memory) {
        std::sort(primary_memory.begin(), primary_memory.end());
    } else {
        stxxl::sort(secondary_memory.begin(), secondary_memory.end(), VertexStackSTXXLSorter(), this->secondary_memory_limit);
    }
}

void VertexStack::initIteration() {
    if (is_primary_memory) {
        pm_begin = primary_memory.begin();
        pm_end = primary_memory.end();
    } else {
        sm_begin = secondary_memory.begin();
        sm_end = secondary_memory.end();
    }
}

bool VertexStack::hasNextVertex() {
    if (is_primary_memory) {
        return pm_begin != pm_end;
    } else {
        return sm_begin != sm_end;
    }
}

LONG_NUMERIC VertexStack::next() {
    if (is_primary_memory) {
        return *pm_begin++;
    } else {
        return *sm_begin++;
    }
}
