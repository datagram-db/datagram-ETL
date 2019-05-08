//
// Created by giacomo on 07/05/19.
//

#include "ConfigurationFile.h"

ConfigurationFile &ConfigurationFile::getInstance() {
    static ConfigurationFile    instance; // Guaranteed to be destroyed.
    // Instantiated on first use.
    return instance;
}

/**
 * Returns a boolean from the json configuration file
 */
#define getBoolean(end, strarg, final) do {\
nlohmann::json::iterator x = j.find(strarg);\
if ((x != end) && (x.value().is_boolean())) {\
(final) = x.value();\
std::cout << strarg << ": " << std::boolalpha << final << std::endl;\
} else {\
    (final) = false;\
    std::cout << strarg << " (missing): " << std::boolalpha << final << std::endl;\
}\
} while(0)

/**
 * Returns a string from the json configuration file
 */
#define getString(end, strarg, final) do {\
nlohmann::json::iterator x = j.find(strarg);\
if ((x != end) && (x.value().is_string())) {\
(final) = x.value();\
std::cout << strarg << ": `" << final << "`" << std::endl;\
} else {\
    (final) = "";\
    std::cout << strarg << " (missing): `" << final << "`" << std::endl ;\
}\
} while(0)

#define getUnsigned(end, strarg, final) do {\
nlohmann::json::iterator x = j.find(strarg);\
if ((x != end) && (x.value().is_number_unsigned())) {\
(final) = x.value();\
std::cout << strarg << ": `" << final << "`" << std::endl;\
} else {\
    (final) = 0L;\
    std::cout << strarg << " (missing): `" << final << "`" << std::endl ;\
}\
} while(0)

ConfigurationFile::ConfigurationFile() {
    std::ifstream infile("etl_conf.json");
    if (infile.good()) {
        nlohmann::json j;
        infile >> j;
        nlohmann::json::iterator end = j.end();
        getBoolean(end, "sort_adj_list_strategy", this->adj_list_strategy);
        getBoolean(end, "sort_vertex_hash_strategy", this->vertex_hash_strategy);
        getBoolean(end, "sort_vset_primary_memory", this->vset_primary_memory);
        getBoolean(end, "load_offset_map_strategy", this->load_offset_map_strategy);

        getString(end, "sort_strategy", this->sorting_strategy);
        getString(end, "load_adj_list_file", this->load_adj_list_file);
        getString(end, "load_vertex_offset_file", this->load_vertex_offset_file);

        getUnsigned(end, "big_number_sort_limit", this->big_number_sort_limit);
    } else {
        std::cerr << "Error: the ETL requires a `etl_conf.json` for configurating the ETL loader for GatorLAND. Please create an empty file" << std::endl;
        exit(1);
    }
}
