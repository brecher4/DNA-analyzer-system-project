#ifndef SRC_DUPCOMMAND_H
#define SRC_DUPCOMMAND_H


#include "creation_commands.h"


class DNAMetaData;


class DupCommand: public CreationCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
};


#endif //SRC_DUPCOMMAND_H
