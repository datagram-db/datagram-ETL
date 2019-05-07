/*
 * test_idstrategy_class.cpp
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
// Created by giacomo on 07/05/19.
//

#include "test_idstrategy_class.h"
#include "../src/graphs/LoadingGraph.h"
#include "../src/sorting/IdStrategy.h"
#include "../src/graphs/utils/secondary_memory/header.h"
#include "../src/utils/old_code/mmapFile.h"
#include <string>
#include <iostream>

void test_idstrategy_class() {
    std::string adj_list_file{"final_adjacency_list.bin"};
    bool offset_map_strategy{true};
    std::string offset_map_file{"offset_map_file.tmp"};

    {
        LoadingGraph loadingGraph{adj_list_file, offset_map_strategy, offset_map_file};

        bool adj_list_strategy = true;
        bool vertex_hash_strategy = true;
        bool vset_primary_memory = true;
        IdStrategy test{loadingGraph, adj_list_strategy, vertex_hash_strategy, vset_primary_memory};

        {
            LONG_NUMERIC id = 2, hash = 20;
            test.insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC id = 0, hash = 20;
            test.insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC id = 1, hash = 10;
            test.insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC src = 1, hash = 00, dst = 0;
            test.insertUniqueEdge(src, hash, dst);
        }
        {
            LONG_NUMERIC src = 2, hash = 00, dst = 0;
            test.insertUniqueEdge(src, hash, dst);
        }
        test.loadGraph();
    }

    int fd_values;
    LONG_NUMERIC size_values;
    header* begin_vertices = (header*)mmapFile(adj_list_file, &size_values, &fd_values);
    header* end_vertices = (header*)(((char*)begin_vertices) + size_values);
    header *v = begin_vertices;
    for (; v < end_vertices; v = vertex_next(v)) {
        std::cout << "vertex id = " << v->id << " hash = " << v->hash << std::endl;
        {
            struct edges_in_vertices *f_out_edges = vertex_outgoing_edges_vec(v);
            LONG_NUMERIC size_f = vertex_outgoing_edges_len(v);
            std::cout << " Outgoing Edges " << std::endl;
            for (int i = 0; i < size_f; i++) {
                std::cout << "adj id= " << f_out_edges[i].vertexId << " adj hash = " <<  f_out_edges[i].vertexHash <<
                          "edge id= " << f_out_edges[i].edgeId << " edge hash = " <<  f_out_edges[i].edgeHash <<std::endl;

            }
        }
        {
            struct edges_in_vertices *f_out_edges = vertex_ingoing_edges_vec(v);
            LONG_NUMERIC size_f = vertex_ingoing_edges_len(v);
            std::cout << " Ingoing Edges " << std::endl;
            for (int i = 0; i < size_f; i++) {
                std::cout << "adj id= " << f_out_edges[i].vertexId << " adj hash = " <<  f_out_edges[i].vertexHash <<
                          "edge id= " << f_out_edges[i].edgeId << " edge hash = " <<  f_out_edges[i].edgeHash <<std::endl;

            }
        }
    }
}
