#include "system_manager.h"
#include "../View/ui/terminal.h"
#include "commands/command_factory.h"


void SystemManager::start(IReader* input, IWriter* output, UI* userInterface)
{
    userInterface->run(input, output, &m_dbDNASequence);
}


void SystemManager::end()
{
    CommandFactory::release();
}