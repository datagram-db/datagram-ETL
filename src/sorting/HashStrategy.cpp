/*
 * HashStrategy.cpp
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

#include "HashStrategy.h"

HashStrategy::HashStrategy(LoadingGraph &finalGraph, bool adj_list_strategy, bool vertex_hash_strategy, bool vset_primary_memory)
        : AbstractSortingStrategy(finalGraph), graph(adj_list_strategy,vertex_hash_strategy ),
           vertex_set{vset_primary_memory} {}

void HashStrategy::doSort() {
    vertex_set.sort();
}

void HashStrategy::doStrategySerialize() {
    vertex_set.initIterator();
    while (vertex_set.hasNextKey()) {
        LONG_NUMERIC hash = vertex_set.getCurrentKey();
        while (vertex_set.hasCurrentKeyContent()) {
            LONG_NUMERIC vertex_id = vertex_set.getCurrentKeyContent();
            serialize_single_vertex((vertex_id), (hash));
        }
    }
}

void HashStrategy::serializeIngoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) {
    graph.in_edges.initIteration(const_cast<LONG_NUMERIC &>(vertexId));
    LONG_NUMERIC edge_hash, edge_id, dst_id, dst_hash;
    while (graph.in_edges.hasNext()) {
        graph.in_edges.get(edge_hash, dst_id, edge_id);
        dst_hash = graph.vertexHash[dst_id];
        finalGraph.swc_add_sorted_ingoing(edge_id, edge_hash, dst_id, dst_hash, v);
    }
}

void HashStrategy::serializeOutgoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) {
    graph.out_edges.initIteration(const_cast<LONG_NUMERIC &>(vertexId));
    LONG_NUMERIC edge_hash, edge_id, dst_id, dst_hash;
    while (graph.out_edges.hasNext()) {
        graph.out_edges.get(edge_hash, dst_id, edge_id);
        dst_hash = graph.vertexHash[dst_id];
        finalGraph.swc_add_sorted_outgoing(edge_id, edge_hash, dst_id, dst_hash, v);
    }
}

void HashStrategy::insertUniqueVertex(LONG_NUMERIC &id, LONG_NUMERIC &hash) {
    vertex_set.put(hash, id);
    graph.insertUniqueVertex(id, hash);
}

LONG_NUMERIC HashStrategy::insertUniqueEdge(LONG_NUMERIC &src, LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst) {
    return graph.insertUniqueEdge(src, edge_hash, dst);
}
