#ifndef SRC_FIND_ALL_COMMAND_H
#define SRC_FIND_ALL_COMMAND_H


#include "analysis_commands.h"


class DNAMetaData;


class FindAllCommand: public AnalysisCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_FIND_ALL_COMMAND_H
