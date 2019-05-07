/*
 * LoadingGraph.h
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

#ifndef ETL_LOADINGGRAPH_H
#define ETL_LOADINGGRAPH_H

#include <string>
#include "../etl.h"
#include "../maps/OffsetMap.h"
#include "utils/primary_memory/ERVertex.h"
#include "../utils/old_code/Serialize.h"

/**
 * This class provides an implementation of the serialization in secondary memory of the graph data structure. This
 * structure won't create sorting-based additional indices, such as the hashing index. That must be a responsability
 * of the sorting order itself
 */
class LoadingGraph {
    std::string adjacency_list_file;
    FILE* adjacency_list = nullptr;
    LONG_NUMERIC offsetValues;
    OffsetMap offsetMap;

public:
    /**
     *
     * @param adj_list_file         File where to store the adjacency list, already sorted by the sorting approach
     * @param offset_map_strategy   Whether the offset_map strategy (that keeps in memory which vertex is serialized
     *                              where) has to be sorted in primary memory or in secondary memory
     * @param offset_map_file       File where to serialize the VertexOffset index.
     */
    LoadingGraph(std::string adj_list_file, bool offset_map_strategy, std::string offset_map_file) :
        adjacency_list_file{adj_list_file},
        offsetMap{offset_map_strategy, offset_map_file} {
        adjacency_list = fopen64(adjacency_list_file.c_str(), "w");
        offsetValues = 0;
    }

    void swc_init_structure(LONG_NUMERIC &vertex_id, LONG_NUMERIC &vertex_hash, ERvertex &tmp_structure) {
        offsetMap.put(vertex_id, offsetValues, vertex_hash);
        tmp_structure.id = vertex_id;
        tmp_structure.hash = vertex_hash;
    }

    void swc_add_sorted_outgoing(LONG_NUMERIC &edge_id, LONG_NUMERIC &edge_hash, LONG_NUMERIC &adj_vertex_id,
                                 LONG_NUMERIC &adj_vertex_hash, ERvertex &tmp_structure) {
        tmp_structure.outgoingEdges.emplace_back(edge_id, edge_hash);
        tmp_structure.outgoingEdges_vertices.emplace_back(adj_vertex_id, adj_vertex_hash);
    }

    void swc_add_sorted_ingoing(LONG_NUMERIC &edge_id, LONG_NUMERIC &edge_hash, LONG_NUMERIC &adj_vertex_id,
                                LONG_NUMERIC &adj_vertex_hash, ERvertex &tmp_structure) {
        tmp_structure.ingoingEdges.emplace_back(edge_id, edge_hash);
        tmp_structure.ingoingEdges_vertices.emplace_back(adj_vertex_id, adj_vertex_hash);
    }

    void swc_serialize_close(ERvertex &tmp_structure) {
        offsetValues += serialize(&tmp_structure, adjacency_list);
    }

    void close() {
        if (adjacency_list) {
            adjacency_list_file.clear();
            fclose(adjacency_list);
            adjacency_list = nullptr;
        }
        offsetMap.serialize();
        offsetMap.close();
    }

    ~LoadingGraph() {
        close();
    }

};


#endif //ETL_LOADINGGRAPH_H
