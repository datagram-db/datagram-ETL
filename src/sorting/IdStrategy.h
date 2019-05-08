/*
 * IdStrategy.h
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

#ifndef ETL_IDSTRATEGY_H
#define ETL_IDSTRATEGY_H

#include "AbstractSortingStrategy.h"
#include "../sets/VertexStack.h"

/**
 * Implementing the strategy that serializes the graph in secondary memory according to the id order of the nodes.
 */
struct IdStrategy : public AbstractSortingStrategy {
    bool is_primary_memory;
    TransformationGraph graph;
    VertexStack vertex_set;

public:
    IdStrategy(LoadingGraph &finalGraph, bool adj_list_strategy, bool vertex_hash_strategy, bool vset_primary_memory, LONG_NUMERIC vset_max_primary);
    // TODO: add properties
    void insertUniqueVertex(LONG_NUMERIC &id, LONG_NUMERIC &hash) override;
    LONG_NUMERIC insertUniqueEdge(LONG_NUMERIC &src, LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst) override;

protected:
    void doSort() override;
    void doStrategySerialize() override;
    void serializeIngoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) override;
    void serializeOutgoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) override;

};


#endif //ETL_IDSTRATEGY_H
