/*
 * AdjacencyList.h
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

#ifndef ETL_ADJACENCYLIST_H
#define ETL_ADJACENCYLIST_H

#include "../etl.h"

#include <unordered_map>
#include <vector>
#include <cassert>

#define VECTOR_OF_PAIRS \
std::vector<std::pair<LONG_NUMERIC, LONG_NUMERIC>>

#define ITERATOR_OF_PAIRS \
VECTOR_OF_PAIRS::iterator

/**
 * [edgeLabel].emplace_back(dst/src, edgeId)
 * .
 * This map represents an indexed adjacency list for a given vertex, for either the ingoing or the outgoing edges.
 * In particular, each key represents a label associated to at least one edge in the (in/out)going edges. Then, each
 * the value is a set of pairs (vector for efficiency) associating the adjacent vertex (pair::first) and the edge id
 * (pair::second).
 */
#define PRIMARY_MEMORY_ADJACENCY_LIST \
std::unordered_map<LONG_NUMERIC, VECTOR_OF_PAIRS>

/**
 * Iterator over the adjacency list for a given vertex.
 */
#define PRIMARY_MEMORY_ADJACENCY_LIST_ITERATOR \
PRIMARY_MEMORY_ADJACENCY_LIST::iterator


/**
 * [src/dst][edgeLabel].emplace_back(dst/src, edgeId)
 * .
 * This map represents the adjacency list for each given vertex in the graph. It could represent the ingoing edges as ù
 * well as the outgoing edges. See ADJACENCY_LIST for the values associated to the keys (each vertex in the graph)
 */
#define PRIMARY_MEMORY_ADJACENCY_MAP \
std::unordered_map<LONG_NUMERIC, PRIMARY_MEMORY_ADJACENCY_LIST>

/**
 * Iterator over the adjacency map
 */
#define PRIMARY_MEMORY_ADJACENCY_MAP_ITERATOR \
PRIMARY_MEMORY_ADJACENCY_MAP::iterator

/**
 * This class represents both the ingoing and the outgoing edges
 */
class AdjacencyList {
    bool is_strategy_primary_memory;
    bool thereIsNoElement;
    PRIMARY_MEMORY_ADJACENCY_MAP primary_memory_strategy;

    struct primary_memory_find_iterator {
        PRIMARY_MEMORY_ADJACENCY_LIST_ITERATOR it;
        ITERATOR_OF_PAIRS begin, end;
    };
    struct primary_memory_find_iterator pm_beg, pm_end;

public:
    AdjacencyList(bool isStrategyPrimaryMemory);
    ~AdjacencyList();
    void insert(LONG_NUMERIC& src, LONG_NUMERIC& edge_hash, LONG_NUMERIC& dst, LONG_NUMERIC& edge_id);

    /**
     * Initializes the iteration over one vertex of the adjacency list
     * @param vertex_id
     */
    void initIteration(LONG_NUMERIC& vertex_id);

    /**
     * Checks whether there is a new element to scan within the adjacency list of the current element
     * @return
     */
    bool hasNext();

    void get(LONG_NUMERIC& edge_hash, LONG_NUMERIC& dst, LONG_NUMERIC& edge_id);
};


#endif //ETL_ADJACENCYLIST_H
