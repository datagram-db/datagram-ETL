cmake_minimum_required(VERSION 3.10)
project(ETL)

set(CMAKE_CXX_STANDARD 17)

add_executable(ETL main.cpp src/maps/AdjacencyList.cpp src/maps/AdjacencyList.h src/graphs/TransformationGraph.cpp src/graphs/TransformationGraph.h src/sorting/SortingStrategy.cpp src/sorting/SortingStrategy.h src/graphs/LoadingGraph.cpp src/graphs/LoadingGraph.h src/graphs/utils/primary_memory/element.cpp src/graphs/utils/primary_memory/element.h src/graphs/utils/primary_memory/value.cpp src/graphs/utils/primary_memory/value.h src/graphs/utils/primary_memory/ERVertex.cpp src/graphs/utils/primary_memory/ERVertex.h src/maps/OffsetMap.h src/maps/OffsetMap.cpp src/graphs/utils/secondary_memory/vertex_id_index.cpp src/graphs/utils/secondary_memory/vertex_id_index.h src/graphs/utils/secondary_memory/hashIndex.cpp src/graphs/utils/secondary_memory/hashIndex.h src/utils/old_code/Serialize.cpp src/utils/old_code/Serialize.h src/graphs/utils/secondary_memory/header.cpp src/graphs/utils/secondary_memory/header.h)