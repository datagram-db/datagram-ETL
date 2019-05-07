//
// Created by giacomo on 07/05/19.
//

#ifndef ETL_SORTINGSTRATEGYFACTORY_H
#define ETL_SORTINGSTRATEGYFACTORY_H

#include <string>
#include <unordered_map>
#include "AbstractSortingStrategy.h"
#include "IdStrategy.h"
#include "HashStrategy.h"

struct SortingStrategyFactory {
    static AbstractSortingStrategy* getStrategy(std::string strategyName, LoadingGraph& lg) {
        ConfigurationFile& conf = ConfigurationFile::getInstance();
        if (strategyName == "hashing") {
            return new HashStrategy(lg, conf.adj_list_strategy, conf.vertex_hash_strategy, conf.vset_primary_memory);
        } else {
            if (!(strategyName == "id"))
                std::cerr << "Sorting strategy `" << strategyName << "` not recognized: using `id` instead" << std::endl;
            return new IdStrategy(lg, conf.adj_list_strategy, conf.vertex_hash_strategy, conf.vset_primary_memory);
        }
    }

    /**
     * Uses the configuration file
     * @param lg
     * @return
     */
    static AbstractSortingStrategy* getStrategy(LoadingGraph& lg) {
        return getStrategy(ConfigurationFile::getInstance().sorting_strategy, lg);
    }

};


#endif //ETL_SORTINGSTRATEGYFACTORY_H
