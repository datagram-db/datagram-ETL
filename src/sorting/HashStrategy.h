/*
 * HashStrategy.h
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

#ifndef ETL_HashStrategy_H
#define ETL_HashStrategy_H

#include "AbstractSortingStrategy.h"
#include "../maps/NestingIndex.h"

/**
 * Implementing the strategy that serializes the graph in secondary memory according to the id order of the nodes.
 *
 * @Deprecated: for testing purposes only.
 */
struct HashStrategy : public AbstractSortingStrategy {
    /**
     * Graph containing the final representation of the overall dataset
     */
    TransformationGraph graph;

    /**
     * This index associates to each vertex hash an unique value that has it.
     */
    NestingIndex vertex_set;

    HashStrategy(LoadingGraph &finalGraph, bool adj_list_strategy, bool vertex_hash_strategy, bool vset_primary_memory);
    void insertUniqueVertex(LONG_NUMERIC &id, LONG_NUMERIC &hash) override;
    LONG_NUMERIC insertUniqueEdge(LONG_NUMERIC &src, LONG_NUMERIC &edge_hash, LONG_NUMERIC &dst) override;

protected:
    void doSort() override;
    void doStrategySerialize() override;
    void serializeIngoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) override;
    void serializeOutgoingEdges(const LONG_NUMERIC &vertexId, const LONG_NUMERIC &vertexHash, ERvertex& v) override;

    // TODO: add properties
};


#endif //ETL_HashStrategy_H
