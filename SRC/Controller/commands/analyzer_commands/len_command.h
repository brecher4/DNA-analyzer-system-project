#ifndef SRC_LEN_COMMAND_H
#define SRC_LEN_COMMAND_H


#include "analyzer_commands.h"


class DNAMetaData;


class LenCommand: public AnalyzerCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_LEN_COMMAND_H
