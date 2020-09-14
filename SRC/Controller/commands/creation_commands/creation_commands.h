#ifndef SRC_CREATION_COMMANDS_H
#define SRC_CREATION_COMMANDS_H


#include "../i_command.h"


class CreationCommands: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CREATION_COMMANDS_H
