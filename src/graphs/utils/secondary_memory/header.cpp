/*
 * header.cpp
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

#include "header.h"

edges_in_vertices::edges_in_vertices() {
    edgeId = edgeHash = vertexHash = vertexId = 0;
}

edges_in_vertices::edges_in_vertices(LONG_NUMERIC edgeId, LONG_NUMERIC edgeHash, LONG_NUMERIC vertexId,
                                     LONG_NUMERIC vertexHash) {
    this->edgeId = edgeId;
    this->edgeHash = edgeHash;
    this->vertexId = vertexId;
    this->vertexHash = vertexHash;
}
