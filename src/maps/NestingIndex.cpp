/*
 * NestingIndex.cpp
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

#include "NestingIndex.h"

NestingIndex::NestingIndex(bool isPrimaryMemory) : isPrimaryMemory(isPrimaryMemory) {}

void NestingIndex::put(LONG_NUMERIC &key, LONG_NUMERIC &value) {
    if (isPrimaryMemory) {
        primary_memory[key].emplace_back(value);
    } else {
        assert(false);
    }
}

void NestingIndex::sort() {
    if (!isPrimaryMemory) {
        //
    }
}

void NestingIndex::initIterator() {
    if (isPrimaryMemory) {
        beg = primary_memory.begin();
        end = primary_memory.end();
    } else {
        // explicitely sorting at this stage
        sm_internalBeg = secondary_memory.begin();
        sm_internalEnd = secondary_memory.end();
        if (sm_internalBeg != sm_internalEnd) {
            ptr = *sm_internalBeg;
            currentKey = ((LONG_NUMERIC*)ptr)[0];
        }
    }
}

bool NestingIndex::hasNextKey() {
    if (isPrimaryMemory) {
        return (beg != end);
    } else {
        return (sm_internalBeg != sm_internalEnd);
    }
}

LONG_NUMERIC NestingIndex::getCurrentKey() {
    if (isPrimaryMemory) {
        if (beg != end) {
            internalBeg = beg->second.begin();
            internalEnd = beg->second.end();
            return beg->first;
        }
    } else {
        return (currentKey = ((LONG_NUMERIC*)ptr)[0]);
    }
    return 0;
}

bool NestingIndex::hasCurrentKeyContent() {
    if (isPrimaryMemory) {
        bool toret =  (internalBeg != internalEnd);
        if (!toret) beg++;
        return toret;
    } else {
        // Checking whether the next pointed data will contain the same key or not
        return ((sm_internalBeg != sm_internalEnd) && (currentKey == ((LONG_NUMERIC*)ptr)[0]));
    }
}

LONG_NUMERIC NestingIndex::getCurrentKeyContent() {
    if (isPrimaryMemory) {
        return *internalBeg++;
    } else {
        LONG_NUMERIC toret = ((LONG_NUMERIC*)ptr)[0];
        sm_internalBeg++;
        if (sm_internalBeg != sm_internalEnd) {
            ptr = *sm_internalBeg;
        }
        return toret;
    }
}
