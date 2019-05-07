/*
 * etl.h
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

#ifndef ETL_ETL_H
#define ETL_ETL_H

#include <cstdint>
typedef     uint_fast64_t                                       LONG_NUMERIC;

#include <vector>
#include "conf/ConfigurationFile.h"

typedef     std::vector<LONG_NUMERIC>                           NUMERIC_VECTOR;
typedef std::vector<std::pair<LONG_NUMERIC, LONG_NUMERIC>>      PAIR_NUMERIC_VECTOR;

#define     ABSTRACT_STRUCT     struct
#define     ABSTRACT_CLASS      class
#define     ABSTRACT            virtual
#define     AS_ABSTRACT         = 0

#endif //ETL_ETL_H
