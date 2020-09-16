#include <stdexcept>
#include <sstream>
#include <vector>
#include "list_command.h"
#include "../../parser_params.h"
#include "../../../Model/db_dna_sequences.h"
#include "../../../Model/dna_meta_data.h"
#include "../../utils.h"


void ListCommand::initParams(const ParserParams& params)
{
    m_pParams = &params;

    if(!isValidParams())
    {
        throw std::invalid_argument("INVALID PARAMETERS");
    }
}


void ListCommand::execute(IReader* input, IWriter* output, DBDNASequence* database)const
{
    const std::vector<size_t> vecIds = database->getIdsByOrder();
    std::vector<size_t>::const_iterator iter;
    std::stringstream out;
    Status status;
    DNAMetaData* pDNA;

    for(iter = vecIds.begin(); iter != vecIds.end(); ++iter)
    {
        pDNA = database->findDNAById(*iter);

        switch(pDNA->getStatus())
        {
            case UP_TO_DATA:
                out << "- ";
                break;

            case MODIFIED:
                out << "* ";
                break;

            case NEW:
                out << "o ";
                break;
        }

        out << Utils::getShortDNADataFormat(pDNA);
    }

    output->write(out.str().c_str());
}


bool ListCommand::isValidParams()const
{
    return 1 == (*m_pParams).getSize();
}
