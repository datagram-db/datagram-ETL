/*
 * ERVertex.h
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
// Created by giacomo on 15/07/17.
//

#ifndef JINGOLOBA_INMEMORY_H
#define JINGOLOBA_INMEMORY_H

#include <string>
#include "value.h"
#include "element.h"

#define VERTEX      (0)
#define EDGE        (1)
#define VALUE       (2)

#define edges_record_entry_size(entry)  ((sizeof(struct edges_in_vertices))*(((entry).size()))+sizeof(LONG_NUMERIC))

struct entity_relationship {
    LONG_NUMERIC                            id;
    LONG_NUMERIC                            hash;
    NUMERIC_VECTOR                          vertex_containment;
    NUMERIC_VECTOR                          edge_containment;
    std::vector<struct value>               properties;
    std::vector<struct entity_relationship> outgoingEdges;                  /**< Assumption that edges are sorted by hash and then id value */
    PAIR_NUMERIC_VECTOR                     outgoingEdges_vertices;     /**< Outgoing edge information associated to each edge */
    std::vector<struct entity_relationship> ingoingEdges;                  /**< Assumption that edges are sorted by hash and then id value */
    PAIR_NUMERIC_VECTOR                     ingoingEdges_vertices;     /**< Outgoing edge information associated to each edge */

    entity_relationship();
    entity_relationship(LONG_NUMERIC id, LONG_NUMERIC hash);
};

typedef struct entity_relationship ERvertex;

#endif //JINGOLOBA_INMEMORY_H
