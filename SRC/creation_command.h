#ifndef SRC_CREATION_COMMAND_H
#define SRC_CREATION_COMMAND_H


#include "i_command.h"


class CreationCommand: public ICommand
{
public:
    CreationCommand(const ParserParams& params):ICommand(params){}
};


#endif //SRC_CREATION_COMMAND_H
