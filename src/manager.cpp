#include "manager.h"
#include "helper.h"

namespace manager {

Manager::Manager() : mNumOfTasks(0)
{
    printHelp();
    mTasks = mPersist.loadTasks();
    mNumOfTasks = mTasks.size();
}

Manager::~Manager()
{
    mPersist.saveTasks(mTasks);
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
        std::cout << task.first << ": " << task.second << std::endl;
    }
}
void Manager::addTask(){
    mNumOfTasks++;
    std::string task{};
    task.reserve(50);
    std::cout << "Enter new task: ";
    std::getline(std::cin, task);
    mTasks.emplace(mNumOfTasks, task);
}
void Manager::removeTask(){
    // TODO add filters and functionality
    std::string task{};
    task.reserve(4);
    std::cout << "Enter task to mark as done: ";
    std::getline(std::cin, task);
    std::optional<u_int16_t> id = helper::getID(task);
    if (!id.has_value()){
        std::cout << "Please enter a valid ID to mark a task as done\n";
        return;
    }
    mTasks.erase(id.value());
    mNumOfTasks--;
}

} // namespace manager