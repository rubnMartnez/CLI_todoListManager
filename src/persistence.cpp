#include "persistence.h"
#include "helper.h"

#include <fstream>

namespace persistence {

Persistence::Persistence()
{
}

Persistence::~Persistence()
{
}

taskMap Persistence::loadTasks(){
    std::ifstream ifstr (FILENAME);
    if (!ifstr.is_open()){
        std::cout << "There was a problem opening the tasks file, try loading the " << FILENAME << ".bak\n";
        return {};
    }

    taskMap tasks{};
    std::string line;
    
    while (getline(ifstr, line))
    {
        u_int8_t separatorPos = line.find(":");
        std::string textID = line.substr(0, separatorPos);
        std::optional<u_int16_t> id = helper::getID(textID);
        if (!id.has_value()) continue;
        std::string task = line.substr(separatorPos + 1, line.size());
        tasks.emplace(id.value(), task);
    }
    ifstr.close();
    return tasks;
}

void Persistence::saveTasks(const taskMap& tasks) {
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
        ofstr << task.first << ": " << task.second << std::endl;
    }
    ofstr.close();
}

} // namespace persistence

