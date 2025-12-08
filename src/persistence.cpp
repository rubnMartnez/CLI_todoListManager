#include "persistence.h"
#include <istream>

namespace persistence {

Persistence::Persistence()
{
    mFileStream.open(FILENAME, std::ios::in | std::ios::out | std::ios::app);
}

Persistence::~Persistence()
{
    if (mFileStream.is_open())
        mFileStream.close();
}

std::unordered_set<std::string> Persistence::loadTasks(){
    if (!mFileStream.is_open()){
        std::cout << "There was a problem opening the tasks file, try loading the " << FILENAME << ".bak\n";
        return {};
    }
    std::unordered_set<std::string> tasks{};
    std::string line;
    char* a;
    
    while (getline(mFileStream, line))
    {
        tasks.emplace(line);
    }
    return tasks;
}

void Persistence::saveTasks(const std::unordered_set<std::string>& tasks) {
    fileOpeningFallback();
        
    for (auto task : tasks){
        mFileStream << task << std::endl;
    }
}

void Persistence::fileOpeningFallback(){
    if (mFileStream.is_open()) return;
    // open a different file in case the other one is blocked
    mFileStream.open(FILENAME + ".bak", std::ios::in | std::ios::out | std::ios::app);
    std::cout << "There was a problem opening the tasks file, so they'll be saved to " << FILENAME << ".bak\n";
}

} // namespace persistence

