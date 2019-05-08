cmake_minimum_required(VERSION 3.10)
project(ETL)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories("third_party/json/single_include")
add_subdirectory(third_party/backward-cpp)
add_subdirectory(third_party/varsorter)

add_subdirectory(third_party/stxxl)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${STXXL_CXX_FLAGS}")
include_directories(${STXXL_INCLUDE_DIRS})

#[[set(PTHREAD_LIB pthread)
set(LIBM m)
set(LIBZ z)
set(LIBZ4 lz4)
set(LIBZSTD zstd)
set(LIBDL dl)
set(LIBSNAPPY snappy)
set(LIBBZ2 bz2)
set(LIBFDB forestdb)
set(LIBLDB leveldb)
set(LIBRDB rocksdb)
set(LIBCOUCH couchstore)
set(LIBWT wiredtiger)
set(LIBTCM tcmalloc)
find_package(snappy)
include_directories(${SNAPPY_INCLUDE_DIR})
find_package(LZ4)
include_directories(${LZ4_INCLUDE_DIR})
find_package(RocksDB)
LINK_DIRECTORIES(${LZ4_LIBRARY})]]

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
        src/sorting/SortingStrategyFactory.cpp
        src/sorting/SortingStrategyFactory.h

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
        test/test_hashstrategy_class.h
        test/test_sorting_strategies.cpp
        test/test_sorting_strategies.h

        src/conf/ConfigurationFile.cpp
        src/conf/ConfigurationFile.h

        ${BACKWARD_ENABLE})

# This will add libraries, definitions and include directories needed by backward
# by setting each property on the target.
add_backward(ETL)
target_link_libraries(ETL libvarsorter  stxxl)

