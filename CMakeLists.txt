cmake_minimum_required(VERSION 3.10)
project(ETL)

set(CMAKE_CXX_STANDARD 17)

add_executable(ETL main.cpp src/maps/AdjacencyList.cpp
                            src/maps/AdjacencyList.h
                            src/maps/OffsetMap.h
                            src/maps/OffsetMap.cpp
                            src/maps/VertexHash.cpp
                            src/maps/VertexHash.h
                            src/maps/NestingIndex.cpp
                            src/maps/NestingIndex.h

        src/sets/VertexStack.h
        src/sets/VertexStack.cpp

                            src/graphs/TransformationGraph.cpp
                            src/graphs/TransformationGraph.h
                            src/graphs/LoadingGraph.cpp
                            src/graphs/LoadingGraph.h

        src/sorting/AbstractSortingStrategy.cpp
        src/sorting/AbstractSortingStrategy.h
        src/sorting/IdStrategy.cpp
        src/sorting/IdStrategy.h
        src/sorting/HashStrategy.cpp
        src/sorting/HashStrategy.h

        src/graphs/utils/primary_memory/element.cpp
        src/graphs/utils/primary_memory/element.h
        src/graphs/utils/primary_memory/value.cpp
        src/graphs/utils/primary_memory/value.h
        src/graphs/utils/primary_memory/ERVertex.cpp
        src/graphs/utils/primary_memory/ERVertex.h

        src/graphs/utils/secondary_memory/vertex_id_index.cpp
        src/graphs/utils/secondary_memory/vertex_id_index.h
        src/graphs/utils/secondary_memory/hashIndex.cpp
        src/graphs/utils/secondary_memory/hashIndex.h
        src/graphs/utils/secondary_memory/header.cpp
        src/graphs/utils/secondary_memory/header.h

        src/utils/old_code/Serialize.cpp
        src/utils/old_code/Serialize.h
        src/utils/old_code/mmapFile.cpp
        src/utils/old_code/mmapFile.h

        test/test_idstrategy_class.cpp
        test/test_idstrategy_class.h
        test/test_hashstrategy_class.cpp
        test/test_hashstrategy_class.h)