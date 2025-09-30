#pragma once

#include <iostream>

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
public:
    Manager();
    ~Manager();

    const void printHelp() const;
};

} // namespace manager