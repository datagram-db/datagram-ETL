/*
 * AbstractSortingStrategy.h
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

#ifndef ETL_ABSTRACTSORTINGSTRATEGY_H
#define ETL_ABSTRACTSORTINGSTRATEGY_H

#include "../graphs/TransformationGraph.h"
#include "../graphs/LoadingGraph.h"


/**
 * The actual sorting strategy must be implemented by the user itself.
 *
 * Please note that each SortingStrategy has to implement its own TransformGraph,
 * because one strategy might contain more than one single TransformGraph (e.g., 
 * the one for the topological sort)
 */
ABSTRACT_STRUCT AbstractSortingStrategy {
    /**
     * This will be the graph that will be sorted according to different sorting strategies.
     */
    LoadingGraph& finalGraph;

    /**
     * Associating the reference to the transformation graph representation
     * @param graph
     */
    AbstractSortingStrategy(LoadingGraph &finalGraph);

    /**
     * Each strategy will implement a different way to (eventually) sort the graph for the transformation phase
     */
    ABSTRACT void doSort() AS_ABSTRACT;

    /**
     * Serializing the final graph in secondary memory, and also writing the nested graph.
     * This is the final phase, which is the loading of the graph as we know it.
     *
     */
    void loadGraph();

protected:
    /**
     * For each possible vertex, it calls the serialize_single_vertex function. Called by doSerialize
     */
    ABSTRACT void doStrategySerialize() AS_ABSTRACT;

    /**
     * Iteration for serializing one single vertex at a time.
     *
     * @param vertexId
     * @param vertexHash
     */
    void serialize_single_vertex(const LONG_NUMERIC& vertexId,const  LONG_NUMERIC& vertexHash);

    /**
     * Function that needs to iteratively call finalGraph.swc_add_sorted_ingoing for each ingoing edge of the vertex
     * passed via parameters
     *
     * @param vertexId
     * @param vertexHash
     */
    ABSTRACT void serializeIngoingEdges(const LONG_NUMERIC& vertexId, const LONG_NUMERIC& vertexHash, ERvertex& v) AS_ABSTRACT;

    /**
     * Function that needs to iteratively call finalGraph.swc_add_sorted_ingoing for each ingoing edge of the vertex
     * passed via parameters
     *
     * @param vertexId
     * @param vertexHash
     */
    ABSTRACT void serializeOutgoingEdges(const LONG_NUMERIC& vertexId, const LONG_NUMERIC& vertexHash, ERvertex& v) AS_ABSTRACT;

    // TODO: add also the part where I load the properties to database
    /**
     * TODO: add also the part where I load the properties to database
     *
     * @param id
     * @param hash
     */
    ABSTRACT void insertUniqueVertex(LONG_NUMERIC& id, LONG_NUMERIC& hash) AS_ABSTRACT;

    // TODO: add also the part where I load the properties to database
    /**
     * TODO: add also the part where I load the properties to database
     *
     * @param src
     * @param edge_hash
     * @param dst
     * @return
     */
    ABSTRACT LONG_NUMERIC insertUniqueEdge(LONG_NUMERIC& src, LONG_NUMERIC& edge_hash, LONG_NUMERIC& dst) AS_ABSTRACT;
};

#endif //ETL_ABSTRACTSORTINGSTRATEGY_H
