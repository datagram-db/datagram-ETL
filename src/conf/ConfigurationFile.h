//
// Created by giacomo on 07/05/19.
// Pattern used from https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
//

#ifndef ETL_CONFIGURATIONFILE_H
#define ETL_CONFIGURATIONFILE_H

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "../etl.h"


class ConfigurationFile
{
public:
    static ConfigurationFile& getInstance();
private:
    ConfigurationFile();

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
public:
    ConfigurationFile(ConfigurationFile const&)               = delete;
    void operator=(ConfigurationFile const&)  = delete;


    bool adj_list_strategy, vertex_hash_strategy, vset_primary_memory, load_offset_map_strategy;
    std::string sorting_strategy, load_adj_list_file, load_vertex_offset_file;
    LONG_NUMERIC big_number_sort_limit;
};


#endif //ETL_CONFIGURATIONFILE_H
