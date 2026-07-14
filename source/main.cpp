#include <grrlib.h>
#include <stdlib.h>
#include <wiiuse/wpad.h>

#include "vertex.h"
#include "meshanimation.h"

#include "engine.h"
#include "controls.h"
#include "thing.h"
#include "thing_factory.h"

#include "game/terrence.h"


int main(int argc, char **argv)
{
    GRRLIB_Init();
    WPAD_Init();

    Thing *root = ThingFactory::create("Thing");

    // Load your exported scene
    scenes["Scene"].build(root);

    Thing3D *root3d = nullptr;
    Thing2D *root2d = nullptr;
    Thing2D *rootUI = nullptr;

    for (Thing *child : root->children)
    {
        if (child->name == "Root3D")
            root3d = dynamic_cast<Thing3D *>(child);

        if (child->name == "Root2D")
            root2d = dynamic_cast<Thing2D *>(child);

        if (child->name == "RootUI")
            rootUI = dynamic_cast<Thing2D *>(child);
    }

    engine.Init(root3d, root2d, rootUI);

    root->init();

    while (true)
    {
        WPAD_ScanPads();

        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
            break;

        controls.a = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_A);
        controls.b = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_B);

        controls.up = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_UP);
        controls.down = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN);
        controls.left = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_LEFT);
        controls.right = (WPAD_ButtonsHeld(0) & WPAD_BUTTON_RIGHT);

        root->update(0);
        root->draw();

        GRRLIB_Render();
    }

    GRRLIB_Exit();

    return 0;
}