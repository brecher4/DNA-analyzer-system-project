#include "system_manager.h"
#include "../View/keyboard_reader.h"
#include "../View/screen_writer.h"


int main()
{
    KeyboardReader input;
    ScreenWriter output;
    SystemManager system;
    system.start(&input, &output);

    return 0;
}