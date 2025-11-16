#include "manager.h"
#include "persistence.h"

namespace manager {

Manager::Manager()
{
    printHelp();
    mTasks.emplace_back("task1");
    mTasks.emplace_back("task2");
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

} // namespace manager