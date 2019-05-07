/*
 * LoadingGraph.cpp
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

#include "LoadingGraph.h"

void LoadingGraph::close() {
    if (adjacency_list) {
        adjacency_list_file.clear();
        fclose(adjacency_list);
        adjacency_list = nullptr;
    }
    offsetMap.serialize();
    offsetMap.close();
}

LoadingGraph::~LoadingGraph() {
    close();
}

LoadingGraph::LoadingGraph() : LoadingGraph(
        ConfigurationFile::getInstance().load_adj_list_file,
        ConfigurationFile::getInstance().load_offset_map_strategy,
        ConfigurationFile::getInstance().load_vertex_offset_file) {

}

LoadingGraph::LoadingGraph(std::string adj_list_file, bool offset_map_strategy, std::string offset_map_file) :
        adjacency_list_file{adj_list_file},
        offsetMap{offset_map_strategy, offset_map_file} {
    adjacency_list = fopen64(adjacency_list_file.c_str(), "w");
    offsetValues = 0;
}
