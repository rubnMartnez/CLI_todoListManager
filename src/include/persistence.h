#pragma once

#include <string>

namespace persistence {

    
class Persistence
{
private:
    const std::string FILENAME{"todoList.txt"};
public:
    Persistence();
    ~Persistence();
};

} // namespace persistence