#include "terminal.h"
#include "parser_params.h"
#include "i_command.h"
#include "i_reader.h"
#include "command_factory.h"
#include <iostream>


void Terminal::start(IReader* input, IWriter* output, DBDNASequence* database)
{
    ParserParams params;
    const ICommand* pCommand = NULL;

    while(1)
    {
        try
        {
            std::cout << "> cmd >>> ";
            input->initInput();
            params.parseInput(*input);

            if("quit" == params[0])
            {
                break;
            }

            pCommand = CommandFactory::getCommand(params);
            pCommand->execute(output, database);

            delete pCommand;
            pCommand = NULL;
        }

        catch (std::invalid_argument& e)
        {
            std::cout << e.what() << "\n\n";
            delete pCommand;
        }

        catch (std::out_of_range& e)
        {
            std::cout << e.what() << "\n\n";
            delete pCommand;
        }
    }
}
