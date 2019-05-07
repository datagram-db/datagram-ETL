/*
 * value.h
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
// Created by giacomo on 09/11/17.
//

#include "element.h"
#include <string>
#include <vector>

#ifndef GRAPHSAMPLER_VALUE_H
#define GRAPHSAMPLER_VALUE_H

/**! Properties associated to each vertex and edge
 */
struct value {
    std::string property; /**< describing the attribute in some human readdable format.
                           *   I assume that each field within the struct value is sorted by its property value,
                           *   and that all the properties belonging to the whole graph are represented. When a
                           *   vertex misses that specific value, the value is set to an empty string
                           **/

    std::string val;    /**< value description. It could be either a constant or an expression (TODO) */
    std::vector<struct element> contents; /**< I assume that they are already sorted by type, and then by id */

    value(std::string prop, std::string val);;
    value();;
};

#endif //GRAPHSAMPLER_VALUE_H
