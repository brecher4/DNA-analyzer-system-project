#include "system_manager.h"
#include "db_dna_sequences.h"
#include "keyboard_reader.h"
#include "parser_params.h"
#include "i_command.h"
#include "command_factory.h"
#include <iostream>


void SystemManager::start()
{
    DBDNASequence dbDNASequence;
    KeyboardReader userInput;
    ParserParams params;
    const ICommand* pCommand;

    while(1)
    {
        std::cout << "cmd >>> ";
        userInput.initInputFromKeyboard();
        params.parseInput(userInput);

        pCommand = CommandFactory::getCommand(params);
        pCommand->execute();

        delete pCommand;

        if("quit" == params[0])
        {
            break;
        }
    }
}