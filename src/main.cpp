#include "main.h"
#include "manager.h"

Commands processCommand(const std::string& command){
    if (command.empty()) return Commands::help;

    auto cmd = commandMapping.find(command);
    return cmd->second;
}

int main(){
    manager::Manager man{};
    std::string commandIn;
    commandIn.reserve(4);
    Commands commandOut;

    while (true) // run until quit is pressed
    {
        std::getline(std::cin, commandIn);
        commandOut = processCommand(commandIn);

        switch (commandOut)
        {
        case Commands::help:
            man.printHelp();
            break;
        case Commands::quit:
            return 0;
        
        default:
            man.printHelp();
            break;
        }
    }    

    // read list from persist

    // unordered set to manage tasks

    // write to a file for persistence

}