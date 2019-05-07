/*
 * AdjacencyList.cpp
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

#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(bool isStrategyPrimaryMemory) : is_strategy_primary_memory(isStrategyPrimaryMemory) {}

AdjacencyList::~AdjacencyList() {
    if (!is_strategy_primary_memory) {
        // TODO
    }
}

void AdjacencyList::insert(LONG_NUMERIC &src, LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst, LONG_NUMERIC &edge_id) {
    if (is_strategy_primary_memory) {
        primary_memory_strategy[src][edge_hash].emplace_back(dst, edge_id);
    } else {
        // TODO:
    }
}

void AdjacencyList::initIteration(LONG_NUMERIC &vertex_id) {
    if (is_strategy_primary_memory) {
        thereIsNoElement = false;
        auto it = primary_memory_strategy.find(vertex_id);
        if (it == primary_memory_strategy.end()) {
            thereIsNoElement = true;
        } else {
            pm_beg.it = it->second.begin();
            pm_end.it = it->second.end();
            while (pm_beg.it != pm_end.it) {
                pm_beg.begin = pm_beg.it->second.begin();
                pm_beg.end = pm_beg.it->second.end();
                if (pm_beg.begin == pm_beg.end) {
                    pm_beg.it++;
                } else {
                    break;
                }
            }
            if (pm_beg.it == pm_end.it)
                thereIsNoElement = false;
        }

    } else {
        // TODO: secondary memory
    }
}

bool AdjacencyList::hasNext() {
    if (is_strategy_primary_memory) {
        if (thereIsNoElement) return false;
        while (pm_beg.it != pm_end.it) {
            if (pm_beg.begin == pm_beg.end) {
                pm_beg.it++;
                pm_beg.begin = pm_beg.it->second.begin();
                pm_beg.end = pm_beg.it->second.end();
            }
        }
        thereIsNoElement = true;
        return false;
    } else {
        // TODO: implement strategy
        assert(false);
        return false;
    }
}

void AdjacencyList::get(LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst, LONG_NUMERIC &edge_id) {
    if (is_strategy_primary_memory) {
        edge_hash = pm_beg.it->first;
        dst = pm_beg.begin->first;
        edge_id = pm_beg.begin->second;
        pm_beg.it++;
    } else {
        // TODO: implement strategy
        assert(false);
    }
}

