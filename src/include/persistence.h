#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

namespace persistence {

    
class Persistence
{
private:
    const std::string FILENAME{"todoList.txt"};
    std::fstream mFileStream{};

    void fileOpeningFallback();
public:
    Persistence();
    ~Persistence();
    std::unordered_set<std::string> loadTasks();
    void saveTasks(const std::unordered_set<std::string>& tasks); 
};

} // namespace persistence