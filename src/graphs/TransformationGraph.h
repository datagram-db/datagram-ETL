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


#include "../maps/TransformationGraphAdjacencyList.h"
#include "../maps/VertexHash.h"

/**
 * Representing a graph in the Transformation phase. That is, this graph is a decomposed serialization of different
 * parts, that will be then serialized into one unique data structure in a second step, that is after the loading phase
 */
struct TransformationGraph {
    // TODO: database connection to store eventually the properties associated to that, or to perform fast entrypoint
    //       adjacency list resolution... ?
    VertexHash vertexHash;

public:
    TransformationGraphAdjacencyList in_edges, out_edges;
    LONG_NUMERIC nextEdgeId;

    TransformationGraph(bool adj_list_strategy, bool vertex_hash_strategy);

    LONG_NUMERIC getSingleVertexHash(const LONG_NUMERIC& id) {
        LONG_NUMERIC k = id;
        return vertexHash[k];
    }

    void insertUniqueVertex(LONG_NUMERIC& id, LONG_NUMERIC& hash) {
        vertexHash.put(id, hash);
    }

    LONG_NUMERIC insertUniqueEdge(LONG_NUMERIC& src, LONG_NUMERIC& edge_hash, LONG_NUMERIC& dst) {
        out_edges.insert(src, edge_hash, dst, nextEdgeId);
        in_edges.insert(dst, edge_hash, src, nextEdgeId);
        return nextEdgeId++;
    }

};


#endif //ETL_TRANSFORMATIONGRAPH_H
