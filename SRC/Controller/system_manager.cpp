#include "system_manager.h"
#include "../View/ui/terminal.h"
#include "commands/command_factory.h"
#include "callback.h"


void SystemManager::start(IReader* input, IWriter* output, UI* userInterface)
{
    Callback<SystemManager> callback(this, &SystemManager::executeCommand);
    userInterface->run(input, output, &m_dbDNASequence, callback);
}


void SystemManager::end()
{
    CommandFactory::release();
}


void SystemManager::executeCommand(ParserParams& params, IReader* input, IWriter* output)
{
    params.parseInput(*input);

    const ICommand* pCommand = CommandFactory::getCommand(params);
    pCommand->execute(input, output, &m_dbDNASequence);
}
