#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using taskVec = std::vector<std::string>;

namespace persistence {
    
class Persistence
{
private:
    const std::string FILENAME{"todoList.txt"};

public:
    Persistence();
    ~Persistence();
    taskVec loadTasks();
    void saveTasks(const taskVec& tasks); 
};

} // namespace persistence