#include "system_manager.h"
#include "../View/keyboard_reader.h"
#include "../View/screen_writer.h"
#include "../View/terminal.h"


int main()
{
    KeyboardReader input;
    ScreenWriter output;
    Terminal terminal;
    SystemManager system;
    system.start(&input, &output, &terminal);

    return 0;
}