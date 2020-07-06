#include "command_factory.h"
#include "new_command.h"


const ICommand* CommandFactory::getCommand(const ParserParams& params)
{
    if("new" == params[0])
    {
        return new NewCommand(params);
    }
}
