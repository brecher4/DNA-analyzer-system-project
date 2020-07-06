#include <stdexcept>
#include "new_command.h"


NewCommand::NewCommand(const ParserParams& params):CreationCommand(params)
{
    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void NewCommand::execute()const
{

}


bool NewCommand::isValidParams()
{
    return true;
}
