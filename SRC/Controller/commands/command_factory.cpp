#include <stdexcept>
#include "command_factory.h"
#include "creation_commands/new_command.h"
#include "creation_commands/load_command.h"
#include "mannagement_commands/save_command.h"
#include "creation_commands/dup_command.h"


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

    if("load" == params[0])
    {
        return new LoadCommand(params);
    }

    if("save" == params[0])
    {
        return new SaveCommand(params);
    }

    if("dup" == params[0])
    {
        return new DupCommand(params);
    }

    throw std::invalid_argument("COMMAND NOT FOUND");
}
