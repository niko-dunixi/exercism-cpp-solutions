//
// Created by Paul Baker on 6/24/17.
//

#ifndef SERIES_SERIES_H
#define SERIES_SERIES_H

#include<algorithm>
#include<iterator>
#include<string>
#include<vector>

namespace series {

    std::vector<int> digits(std::string);

    std::vector<std::vector<int>> slice(std::string, int);

};


#endif //SERIES_SERIES_H
