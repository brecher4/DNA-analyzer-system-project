#ifndef SRC_CONTROL_COMMANDS_H
#define SRC_CONTROL_COMMANDS_H


#include "../command.h"


class ControlCommands: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CONTROL_COMMANDS_H
