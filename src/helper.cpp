#include "helper.h"

#include <algorithm>

namespace helper {

std::optional<u_int16_t> getID(const std::string& str){
    if (str.empty()) return {};
    if (!std::all_of(str.begin(), str.end(), [](char c){return std::isdigit(c);})) return {};

    return std::stoi(str);
}

} // namespace helper