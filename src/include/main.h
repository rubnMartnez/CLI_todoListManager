#pragma once

#include <map>
#include <string>

enum Commands{
    help,
    list,
    add,
    done,
    quit
};

static const std::map<std::string, Commands> commandMapping {
    {"help", Commands::help},
    {"h", Commands::help},
    {"list", Commands::list},
    {"l", Commands::list},
    {"add", Commands::add},
    {"a", Commands::add},
    {"done", Commands::done},
    {"d", Commands::done},
    {"exit", Commands::quit},
    {"e", Commands::quit},
    {"quit", Commands::quit},
    {"q", Commands::quit},
};

Commands processCommand(const std::string& command);