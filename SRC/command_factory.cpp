#include <stdexcept>
#include "command_factory.h"
#include "new_command.h"


const ICommand* CommandFactory::getCommand(const ParserParams& params)
{
    if(params[0].empty())
    {
        throw std::invalid_argument("MISSING COMMAND");
    }

    if("new" == params[0])
    {
        return new NewCommand(params);
    }

    throw std::invalid_argument("COMMAND NOT FOUND");
}
