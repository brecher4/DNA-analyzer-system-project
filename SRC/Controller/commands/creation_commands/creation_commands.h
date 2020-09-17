#ifndef SRC_CREATION_COMMANDS_H
#define SRC_CREATION_COMMANDS_H


#include "../command.h"


class CreationCommands: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CREATION_COMMANDS_H
