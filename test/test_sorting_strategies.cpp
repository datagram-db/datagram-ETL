//
// Created by giacomo on 07/05/19.
//

#include "test_sorting_strategies.h"
#include "../src/sorting/SortingStrategyFactory.h"
#include "../src/etl.h"
#include "../src/graphs/utils/secondary_memory/header.h"
#include "../src/utils/old_code/mmapFile.h"

void test_sorting_strategies(std::string name) {
    {
        LoadingGraph loadingGraph{};
        AbstractSortingStrategy* test = SortingStrategyFactory::getStrategy(name, loadingGraph);
        {
            LONG_NUMERIC id = 2, hash = 20;
            test->insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC id = 0, hash = 20;
            test->insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC id = 1, hash = 10;
            test->insertUniqueVertex(id, hash);
        }
        {
            LONG_NUMERIC src = 1, hash = 00, dst = 0;
            test->insertUniqueEdge(src, hash, dst);
        }
        {
            LONG_NUMERIC src = 2, hash = 00, dst = 0;
            test->insertUniqueEdge(src, hash, dst);
        }
        test->loadGraph();
    }

    int fd_values;
    LONG_NUMERIC size_values;
    header* begin_vertices = (header*)mmapFile(ConfigurationFile::getInstance().load_adj_list_file, &size_values, &fd_values);
    header* end_vertices = (header*)(((char*)begin_vertices) + size_values);
    header *v = begin_vertices;
    for (; v < end_vertices; v = vertex_next(v)) {
        std::cout << "vertex id = " << v->id << " hash = " << v->hash << std::endl;
        {
            struct edges_in_vertices *f_out_edges = vertex_outgoing_edges_vec(v);
            LONG_NUMERIC size_f = vertex_outgoing_edges_len(v);
            std::cout << " Outgoing Edges " << std::endl;
            for (int i = 0; i < size_f; i++) {
                std::cout << "adj id= " << f_out_edges[i].vertexId << " adj hash = " <<  f_out_edges[i].vertexHash <<
                          "edge id= " << f_out_edges[i].edgeId << " edge hash = " <<  f_out_edges[i].edgeHash <<std::endl;

            }
        }
        {
            struct edges_in_vertices *f_out_edges = vertex_ingoing_edges_vec(v);
            LONG_NUMERIC size_f = vertex_ingoing_edges_len(v);
            std::cout << " Ingoing Edges " << std::endl;
            for (int i = 0; i < size_f; i++) {
                std::cout << "adj id= " << f_out_edges[i].vertexId << " adj hash = " <<  f_out_edges[i].vertexHash <<
                          "edge id= " << f_out_edges[i].edgeId << " edge hash = " <<  f_out_edges[i].edgeHash <<std::endl;

            }
        }
    }
}
