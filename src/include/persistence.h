#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <map>

using taskMap = std::map<u_int16_t, std::string>;

namespace persistence {
    
class Persistence
{
private:
    const std::string FILENAME{"todoList.txt"};

public:
    Persistence();
    ~Persistence();
    taskMap loadTasks();
    void saveTasks(const taskMap& tasks); 
};

} // namespace persistence