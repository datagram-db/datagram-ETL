/*
 * element.h
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

#ifndef GRAPHSAMPLER_ELEMENT_H
#define GRAPHSAMPLER_ELEMENT_H

#include "../../../etl.h"

/**! An element describing a list of elements associated to a value
 */
struct element {
    LONG_NUMERIC value_type;
    LONG_NUMERIC id;
    element(LONG_NUMERIC f, LONG_NUMERIC s);;
};

#endif //GRAPHSAMPLER_ELEMENT_H
