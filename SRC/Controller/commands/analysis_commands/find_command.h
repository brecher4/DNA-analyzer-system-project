#ifndef SRC_FIND_COMMAND_H
#define SRC_FIND_COMMAND_H


#include "analysis_commands.h"


class DNAMetaData;


class FindCommand: public AnalysisCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_FIND_COMMAND_H
