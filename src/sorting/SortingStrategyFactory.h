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
    /**
     * Creates the predefinite strategy with @strategyName, and initialises the remaining arguments using the default configuration file
     * @param strategyName
     * @param lg
     * @return
     */
    static AbstractSortingStrategy* getStrategy(std::string strategyName, LoadingGraph& lg);

    /**
     * Uses the configuration file to get the preferred strategy
     * @param lg
     * @return
     */
    static AbstractSortingStrategy* getStrategy(LoadingGraph& lg);

};


#endif //ETL_SORTINGSTRATEGYFACTORY_H
