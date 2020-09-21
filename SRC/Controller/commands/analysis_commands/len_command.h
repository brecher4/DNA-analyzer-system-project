#ifndef SRC_LEN_COMMAND_H
#define SRC_LEN_COMMAND_H


#include "analysis_commands.h"


class DNAMetaData;


class LenCommand: public AnalysisCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_LEN_COMMAND_H
