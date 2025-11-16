#pragma once

#include <iostream>
#include <vector>

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
    std::vector<std::string> mTasks{};
public:
    Manager();
    ~Manager();

    const void printHelp() const;
    const void listTasks() const;
};

} // namespace manager