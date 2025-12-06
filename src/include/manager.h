#pragma once

#include <iostream>
#include <unordered_set>

#include "persistence.h"

namespace manager {
class Manager
{
private:
    const char* HELP_MESSAGE = R"(
Available commands:

help, h      Show this help message
list, l      List all tasks
add, a       Add a new task
done, d      Mark a task as completed
exit, e      Exit the program
quit, q      Exit the program
)";
    std::unordered_set<std::string> mTasks{};
    u_int32_t mNumOfTasks;
    persistence::Persistence mPersist{};
public:
    Manager();
    ~Manager();

    void printHelp() const;
    void listTasks() const;
    void addTask();
    void removeTask();
};

} // namespace manager