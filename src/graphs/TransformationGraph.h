/*
 * TransformationGraph.h
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

#ifndef ETL_TRANSFORMATIONGRAPH_H
#define ETL_TRANSFORMATIONGRAPH_H


#include "../maps/AdjacencyList.h"

/**
 * Representing a graph in the Transformation phase. That is, this graph is a decomposed serialization of different
 * parts, that will be then serialized into one unique data structure in a second step, that is after the loading phase
 */
class TransformationGraph {
    AdjacencyList in_edges, out_edges;
    bool is_strategy_primary_memory;


public:
    TransformationGraph(bool primary_memory);

    void insert(LONG_NUMERIC& src, LONG_NUMERIC& edge_hash, LONG_NUMERIC& dst, LONG_NUMERIC& edge_id) {
        out_edges.insert(src, edge_hash, dst, edge_id);
        in_edges.insert(dst, edge_hash, src, edge_id);
    }

};


#endif //ETL_TRANSFORMATIONGRAPH_H
