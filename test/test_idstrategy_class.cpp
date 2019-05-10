/*
 * test_idstrategy_class.cpp
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
// Created by giacomo on 07/05/19.
//

#include "test_idstrategy_class.h"
#include "../src/graphs/LoadingGraph.h"
#include "../src/sorting/IdStrategy.h"
#include <serializers/commons/secondary_memory/header.h>
#include "../src/utils/old_code/mmapFile.h"
#include "../src/sorting/SortingStrategyFactory.h"
#include "test_sorting_strategies.h"
#include <string>
#include <iostream>

void test_idstrategy_class() {
    test_sorting_strategies("id");
}
