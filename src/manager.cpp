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

    u_int16_t index = 1;
    for (auto task : mTasks){
        std::cout << index << ": " << task << std::endl;
        index++;
    }
}
void Manager::addTask(){
    mNumOfTasks++;
    std::string task{};
    task.reserve(50);
    std::cout << "Enter new task: ";
    std::getline(std::cin, task);
    mTasks.emplace_back(task);
}
void Manager::removeTask(){
    if (mTasks.empty()){
        std::cout << "There are no tasks to mark as done\n";
        printHelp();
        return;
    }

    std::string task{};
    task.reserve(4);
    std::cout << "Enter task to mark as done: ";
    std::getline(std::cin, task);
    std::optional<u_int16_t> optId = helper::getID(task);
    if (!optId.has_value()){
        std::cout << "Invalid ID, no task marked as done\n";
        return;
    }
    u_int16_t id = optId.value() - 1;
    if (id >= mTasks.size()){
        std::cout << "ID out of bounds, no task marked as done\n";
        return;
    }
    mTasks.erase(mTasks.begin() + id);
    mNumOfTasks--;
}

} // namespace manager