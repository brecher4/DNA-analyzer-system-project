#ifndef SRC_ANALYZER_COMMANDS_H
#define SRC_ANALYZER_COMMANDS_H


#include "../command.h"


class AnalyzerCommands: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_ANALYZER_COMMANDS_H
