#include <iostream>
#include "terminal.h"
#include "../../Controller/parser_params.h"
#include "../../Controller/commands/i_command.h"


void Terminal::run(IReader* input, IWriter* output, DBDNASequence* database, Callback<SystemManager>& callback)
{
    ParserParams params;
    const ICommand* pCommand = NULL;

    while(true)
    {
        try
        {
            std::cout << "> cmd >>> ";
            input->initInput();
            callback(params, input, output);
        }

        catch (std::invalid_argument& e)
        {
            std::cout << "ERROR: " << e.what() << "\n\n";
        }

        catch (std::out_of_range& e)
        {
            std::cout << "ERROR: "  << e.what() << "\n\n";
        }

        catch (std::runtime_error& e)
        {
            std::cout << "ERROR: "  << e.what() << "\n\n";
        }

        catch (std::logic_error& e)
        {
            break;
        }
    }
}
