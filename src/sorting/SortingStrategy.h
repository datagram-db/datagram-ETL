/*
 * SortingStrategy.h
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

#ifndef ETL_SORTINGSTRATEGY_H
#define ETL_SORTINGSTRATEGY_H

#include "../graphs/TransformationGraph.h"

ABSTRACT_STRUCT SortingStrategy {
    /**
     * This will be the graph that will be sorted according to different sorting strategies.
     */
    TransformationGraph& graphToSort;

    /**
     * Associating the reference to the transformation graph representation
     * @param graph
     */
    SortingStrategy(TransformationGraph& graph);

    /**
     * Each strategy will implement a different way to (eventually) sort the graph for the transformation phase
     */
    ABSTRACT void doSort() AS_ABSTRACT;

    // TODO: strategy to return the elements to serialize

};

#endif //ETL_SORTINGSTRATEGY_H
