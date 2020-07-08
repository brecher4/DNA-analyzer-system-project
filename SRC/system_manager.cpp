#include "system_manager.h"
#include "terminal.h"


void SystemManager::start(IReader* input, IWriter* output)
{
    Terminal::start(input, output, &m_dbDNASequence);
}