#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "City.h"

namespace reader { //ver esto del namespace
    std::vector<City *> readCsv(std::string nameCsv);
}
