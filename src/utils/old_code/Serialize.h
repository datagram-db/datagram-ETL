/*
 * Serialize.h
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
// Created by giacomo on 17/07/17.
//

#ifndef JINGOLOBA_SERIALIZE_H
#define JINGOLOBA_SERIALIZE_H

#include "../../etl.h"
#include <serializers/commons/primary_memory/entity_relationship.h>



#define NUMERIC_MEMORY_OCCUPATION  \
        (sizeof(LONG_NUMERIC))

#define VECTOR_SIZE(v) \
        ((v).size())

#define VECTOR_MEMORY_OCCUPATION(v)\
        (((VECTOR_SIZE(v))+1)*(NUMERIC_MEMORY_OCCUPATION))


LONG_NUMERIC serialize(ERvertex* v, FILE* file);


#endif //JINGOLOBA_SERIALIZE_H
