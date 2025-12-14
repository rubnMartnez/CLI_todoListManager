#include "persistence.h"

#include <fstream>

namespace persistence {

Persistence::Persistence()
{
}

Persistence::~Persistence()
{
}

taskVec Persistence::loadTasks(){
    std::ifstream ifstr (FILENAME);
    if (!ifstr.is_open()){
        std::cout << "There was a problem opening the tasks file, try loading the " << FILENAME << ".bak\n";
        return {};
    }

    taskVec tasks{};
    std::string line;
    
    while (getline(ifstr, line))
    {
        tasks.emplace_back(line);
    }
    ifstr.close();
    return tasks;
}

void Persistence::saveTasks(const taskVec& tasks) {
    std::ofstream ofstr (FILENAME);
    // fallback in case default file couldn't be opened
    if (!ofstr.is_open()){
        std::cout << "There was a problem opening the tasks file, so they'll be saved to " << FILENAME << ".bak\n";
        ofstr.open(FILENAME + ".bak");

        if (!ofstr.is_open()){
            std::cout << "There was a problem opening the tasks file .bak, so the tasks won't be saved\n";
            return;
        }
    }
    
    for (auto task : tasks){
        ofstr << task << std::endl;
    }
    ofstr.close();
}

} // namespace persistence

