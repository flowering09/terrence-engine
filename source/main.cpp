/*===========================================
        GRRLIB (GX Version)
        - Template Code -

        Minimum Code To Use GRRLIB
============================================*/
#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>
#include "thing.h"
#include "engine.h"
#include "controls.h"
#include "thing_factory.h"

int main(int argc, char **argv)
{
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();
    // Initialise the Wiimotes
    WPAD_Init();
    engine.Init();
    Thing *root = ThingFactory::create("Thing");
    Thing *obj = ThingFactory::create("Test");
    root->addChild(obj);
    // Loop forever
    while (1)
    {

        WPAD_ScanPads(); // Scan the Wiimotes

        // If [HOME] was pressed on the first Wiimote, break out of the loop
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
            break;

        controls.a = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_A);
        controls.b = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_B);

        controls.up = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP);
        controls.down = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN);
        controls.left = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT);
        controls.right = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT);

        // ---------------------------------------------------------------------
        // Place your drawing code here
        root->update(0);
        root->draw();
        // ---------------------------------------------------------------------

        GRRLIB_Render(); // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0); // Use exit() to exit a program, do not use 'return' from main()
}
