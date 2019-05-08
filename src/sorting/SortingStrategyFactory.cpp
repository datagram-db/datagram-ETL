//
// Created by giacomo on 07/05/19.
//

#include "SortingStrategyFactory.h"

AbstractSortingStrategy *SortingStrategyFactory::getStrategy(LoadingGraph &lg) {
    return getStrategy(ConfigurationFile::getInstance().sorting_strategy, lg);
}

AbstractSortingStrategy *SortingStrategyFactory::getStrategy(std::string strategyName, LoadingGraph &lg) {
    ConfigurationFile& conf = ConfigurationFile::getInstance();
    if (strategyName == "hashing") {
        return new HashStrategy(lg, conf.adj_list_strategy, conf.vertex_hash_strategy, conf.vset_primary_memory);
    } else {
        if (!(strategyName == "id"))
            std::cerr << "Sorting strategy `" << strategyName << "` not recognized: using `id` instead" << std::endl;
        return new IdStrategy(lg, conf.adj_list_strategy, conf.vertex_hash_strategy, conf.vset_primary_memory, conf.big_number_sort_limit);
    }
}
