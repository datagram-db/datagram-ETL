/*
 * NestingIndex.h
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

#ifndef ETL_NESTINGINDEX_H
#define ETL_NESTINGINDEX_H

#include <map>
#include <vector>
#include <cassert>
#include "../etl.h"

/**
 * This class implements the hashing of a set of vertices.
 */
class NestingIndex {
    std::map<LONG_NUMERIC, std::vector<LONG_NUMERIC >> primary_memory;
    std::map<LONG_NUMERIC, std::vector<LONG_NUMERIC >>::iterator beg, end;
    std::vector<LONG_NUMERIC>::iterator internalBeg, internalEnd;

    bool isPrimaryMemory;

public:
    NestingIndex(bool isPrimaryMemory);
    void put(LONG_NUMERIC& key, LONG_NUMERIC& value);
    void sort();
    void initIterator();
    bool hasNextKey();
    LONG_NUMERIC getCurrentKey();
    bool hasCurrentKeyContent();
    LONG_NUMERIC getCurrentKeyContent();

    void serialize() {  /* TODO */ assert(false); }
};


#endif //ETL_NESTINGINDEX_H
