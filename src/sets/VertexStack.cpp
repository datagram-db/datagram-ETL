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

VertexStack::VertexStack(bool isPrimaryMemory) : is_primary_memory(isPrimaryMemory) {}

void VertexStack::put(LONG_NUMERIC &vertex_id) {
    if (is_primary_memory) {
        primary_memory.emplace_back(vertex_id);
    } else {
        // TODO: implement vertex insertion in secondary memory
    }
    size++;
}

void VertexStack::sort() {
    if (is_primary_memory) {
        std::sort(primary_memory.begin(), primary_memory.end());
    } else {
        // TODO:: sort the secondary memory by id
    }
}

void VertexStack::initIteration() {
    if (is_primary_memory) {
        pm_begin = primary_memory.begin();
        pm_end = primary_memory.end();
    } else {
        // TODO. iteration for secondary memory
    }
}

bool VertexStack::hasNextVertex() {
    if (is_primary_memory) {
        return pm_begin != pm_end;
    } else {
        assert(false);
    }
}

LONG_NUMERIC VertexStack::next() {
    if (is_primary_memory) {
        return *pm_begin++;
    } else {
        return 0;
    }
}
