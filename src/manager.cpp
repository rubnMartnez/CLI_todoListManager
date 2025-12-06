#include "manager.h"

namespace manager {

Manager::Manager() : mNumOfTasks(0)
{
    printHelp();
}

Manager::~Manager()
{
}

void Manager::printHelp() const {
    std::cout << HELP_MESSAGE << std::endl;
}
void Manager::listTasks() const {
    std::cout << "List of current tasks: \n";

    if (mTasks.empty()){
        std::cout << "Empty \n";
        return;
    }

    for (auto task : mTasks){
        std::cout << task << std::endl;
    }
}
void Manager::addTask(){
    mNumOfTasks++;
    std::string task{};
    task.reserve(50);
    std::cout << "Enter new task: ";
    std::getline(std::cin, task);
    mTasks.emplace(task);
}
void Manager::removeTask(){
    std::string task{};
    task.reserve(50);
    std::getline(std::cin, task);
    mTasks.erase(task);
    mNumOfTasks--;
}

} // namespace manager