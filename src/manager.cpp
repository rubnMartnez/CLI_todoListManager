#include "manager.h"
#include "persistence.h"

namespace manager {

Manager::Manager()
{
    printHelp();
    persistence::Persistence persist{};
}

Manager::~Manager()
{
}

const void Manager::printHelp() const {
    std::cout << HELP_MESSAGE << std::endl;
}
const void Manager::listTasks() const {
    for (auto task : mTasks){
        std::cout << task << std::endl;
    }
}
const void Manager::addTask(){
    std::string task{};
    task.reserve(50);
    std::getline(std::cin, task);
    mTasks.emplace(task);
}
const void Manager::removeTask(){
    std::string task{};
    task.reserve(50);
    std::getline(std::cin, task);
    mTasks.erase(task);
}

} // namespace manager