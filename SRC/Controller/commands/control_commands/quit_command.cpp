#include <stdexcept>
#include <sstream>
#include <vector>
#include "quit_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void QuitCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void QuitCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    std::stringstream out;
    size_t numModifiedDNA = database->getNumModifiedDNA();
    size_t numNewDNA = database->getNumNewDNA();
    bool isNeedAnd = false;

    if(numModifiedDNA || numNewDNA)
    {
        out << "There are ";

        if(numModifiedDNA)
        {
            out << numModifiedDNA << " modified ";
            isNeedAnd = true;
        }

        if(numNewDNA)
        {
            if(isNeedAnd)
            {
                out << "and ";
            }

            out << numNewDNA << " new ";
        }

        out << "sequences. Are you sure you want to quit? \nPlease confirm by 'y' or 'Y', or cancel by 'n' or 'N'.\n";
        out << "> confirm >>> ";
        output->write(out.str().c_str());
        out.str("");
        input->initInput();
        std::string in = input->read();

        while(in != "y" && in != "Y" && in != "n" && in != "N")
        {
            out << "You have typed an invalid response. Please either confirm by 'y'/'Y', or cancel by 'n'/'N'.\n";
            out << "> confirm >>> ";
            output->write(out.str().c_str());
            out.str("");
            input->initInput();
            in = input->read();
        }

       if(in == "n" || in == "N")
       {
           out.str("");
           out << "";
           output->write(out.str().c_str());

           return;
       }
    }

    out << "Thank you for using Dnalanyzer. \nGoodbye!\n";
    output->write(out.str().c_str());
    throw std::logic_error("");

}


bool QuitCommand::isValidParams()const
{
    return 1 == (*m_pParams).getSize();
}
