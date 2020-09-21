#ifndef SRC_ANALYSIS_COMMANDS_H
#define SRC_ANALYSIS_COMMANDS_H


#include "../command.h"


class AnalysisCommands: public Command
{
public:
    /* virtual */ void initParams(const ParserParams& params) = 0;
};


#endif //SRC_ANALYSIS_COMMANDS_H
