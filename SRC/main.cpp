#include "Controller/system_manager.h"
#include "View/reader/keyboard_reader.h"
#include "View/writer/screen_writer.h"
#include "View/ui/terminal.h"


int main()
{
    KeyboardReader input;
    ScreenWriter output;
    Terminal terminal;
    SystemManager system;
    system.start(&input, &output, &terminal);
    system.end();

    return 0;
}