#include "system_manager.h"
#include "../View/terminal.h"
#include "commands/command_factory.h"


void SystemManager::start(IReader* input, IWriter* output, UI* userInterface)
{
    CommandFactory::init();
    userInterface->run(input, output, &m_dbDNASequence);
    CommandFactory::release();
}