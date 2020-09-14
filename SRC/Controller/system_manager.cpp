#include "system_manager.h"
#include "../View/terminal.h"


void SystemManager::start(IReader* input, IWriter* output, UI* userInterface)
{
    userInterface->run(input, output, &m_dbDNASequence);
}