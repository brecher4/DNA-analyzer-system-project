#include "terminal.h"
#include "../Controller/parser_params.h"
#include "../Controller/commands/i_command.h"
#include "../View/i_reader.h"
#include "../Controller/commands/command_factory.h"
#include <iostream>


void Terminal::run(IReader* input, IWriter* output, DBDNASequence* database)
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
            std::cout << "ERROR: " << e.what() << "\n\n";
            delete pCommand;
        }

        catch (std::out_of_range& e)
        {
            std::cout << "ERROR: "  << e.what() << "\n\n";
            delete pCommand;
        }

        catch (std::runtime_error& e)
        {
            std::cout << "ERROR: "  << e.what() << "\n\n";
            delete pCommand;
        }
    }
}
