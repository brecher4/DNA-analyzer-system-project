#ifndef SRC_CREATION_COMMANDS_H
#define SRC_CREATION_COMMANDS_H


#include "../i_command.h"


class CreationCommands: public ICommand
{
public:
    CreationCommands(const ParserParams& params): ICommand(params){}
};


#endif //SRC_CREATION_COMMANDS_H
