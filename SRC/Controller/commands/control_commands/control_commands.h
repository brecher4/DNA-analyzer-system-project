#ifndef SRC_CONTROL_COMMANDS_H
#define SRC_CONTROL_COMMANDS_H


#include "../i_command.h"


class ControlCommands: public ICommand
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_CONTROL_COMMANDS_H
