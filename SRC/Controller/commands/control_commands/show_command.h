#ifndef SRC_SHOW_COMMAND_H
#define SRC_SHOW_COMMAND_H


#include "control_commands.h"


class DNAMetaData;


class ShowCommand: public ControlCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
    std::string getDNADataFormat(const DNAMetaData& pDNA, size_t numChars = 99)const;
};


#endif //SRC_SHOW_COMMAND_H
