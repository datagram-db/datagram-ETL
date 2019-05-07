/*
 * IdStrategy.cpp
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

#include "IdStrategy.h"

IdStrategy::IdStrategy(LoadingGraph &finalGraph, bool adj_list_strategy, bool vertex_hash_strategy, bool vset_primary_memory)
        : AbstractSortingStrategy(finalGraph), graph(adj_list_strategy), vertexHash{vertex_hash_strategy},
           vertex_set{vset_primary_memory} {}

void IdStrategy::doSort() {
    vertex_set.sort();
}

void IdStrategy::doStrategySerialize() {
    vertex_set.initIteration();
    while (vertex_set.hasNextVertex()) {
        const LONG_NUMERIC& vertex_id = vertex_set.next();
        const LONG_NUMERIC& hash = vertexHash[vertex_id];
        serialize_single_vertex(const_cast<LONG_NUMERIC &>(vertex_id), const_cast<LONG_NUMERIC &>(hash));
    }
}

void IdStrategy::serializeIngoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) {
    graph.in_edges.initIteration(const_cast<LONG_NUMERIC &>(vertexId));
    LONG_NUMERIC edge_hash, edge_id, dst_id, dst_hash;
    while (graph.in_edges.hasNext()) {
        graph.in_edges.get(edge_hash, dst_id, edge_id);
        dst_hash = this->vertexHash[dst_id];
        finalGraph.swc_add_sorted_ingoing(edge_id, edge_hash, dst_id, dst_hash, v);
    }
}

void IdStrategy::serializeOutgoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) {
    graph.out_edges.initIteration(const_cast<LONG_NUMERIC &>(vertexId));
    LONG_NUMERIC edge_hash, edge_id, dst_id, dst_hash;
    while (graph.in_edges.hasNext()) {
        graph.in_edges.get(edge_hash, dst_id, edge_id);
        dst_hash = this->vertexHash[dst_id];
        finalGraph.swc_add_sorted_ingoing(edge_id, edge_hash, dst_id, dst_hash, v);
    }
}

void IdStrategy::insertUniqueVertex(LONG_NUMERIC &id, LONG_NUMERIC &hash) {
    graph.insertUniqueVertex(id, hash);
}

LONG_NUMERIC IdStrategy::insertUniqueEdge(LONG_NUMERIC &src, LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst) {
    return graph.insertUniqueEdge(src, edge_hash, dst);
}
