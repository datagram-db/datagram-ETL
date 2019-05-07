/*
 * AbstractSortingStrategy.cpp
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

#include "AbstractSortingStrategy.h"

AbstractSortingStrategy::AbstractSortingStrategy(LoadingGraph &finalGraph)
        : finalGraph(finalGraph) {}

void AbstractSortingStrategy::serialize_single_vertex(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash) {
    ERvertex currentVertex{vertexId, vertexHash};
    finalGraph.swc_init_structure(const_cast<LONG_NUMERIC &>(vertexId), const_cast<LONG_NUMERIC &>(vertexHash), currentVertex);
    serializeIngoingEdges(vertexId, vertexHash, currentVertex);
    serializeOutgoingEdges(vertexId, vertexHash, currentVertex);
    finalGraph.swc_serialize_close(currentVertex);
}

void AbstractSortingStrategy::loadGraph() {
    doStrategySerialize();
    finalGraph.close();
}
