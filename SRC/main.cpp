#include "system_manager.h"
#include "keyboard_reader.h"
#include "screen_writer.h"


int main()
{
    KeyboardReader input;
    ScreenWriter output;
    SystemManager system;
    system.start(&input, &output);

    return 0;
}