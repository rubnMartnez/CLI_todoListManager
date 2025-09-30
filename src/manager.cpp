#include "manager.h"
#include "persistence.h"

namespace manager {

Manager::Manager()
{
    printHelp();
}

Manager::~Manager()
{
}

const void Manager::printHelp() const {
    std::cout << HELP_MESSAGE << std::endl;
}

} // namespace manager