#include "Ejercicio02.h"
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>>* Ejercicio02::groupAnagrams(std::vector<std::string>& strings) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (std::string& s : strings) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        map[key].push_back(s);
    }

    auto* result = new std::vector<std::vector<std::string>>();
    for (auto& pair : map) {
        result->push_back(pair.second);
    }

    return result;
}