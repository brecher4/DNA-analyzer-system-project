#ifndef SRC_FIND_COMMAND_H
#define SRC_FIND_COMMAND_H


#include "analyzer_commands.h"


class DNAMetaData;


class FindCommand: public AnalyzerCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams();
};


#endif //SRC_FIND_COMMAND_H
