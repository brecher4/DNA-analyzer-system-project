#ifndef SRC_HELP_COMMAND_H
#define SRC_HELP_COMMAND_H


#include "control_commands.h"


class DNAMetaData;


class HelpCommand: public ControlCommands
{
public:
    /* virtual */ void initParams(const ParserParams& params);
    /* virtual */ void execute(IReader* input, IWriter* output, DBDNASequence* database)const;

private:
    bool isValidParams()const;
    std::string getAvailableCommands()const;
    std::string getInfoCommand(const std::string& str)const;
};


#endif //SRC_HELP_COMMAND_H
