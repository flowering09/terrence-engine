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
#include "terrencewiianim.h"
#include "cube.h"
#include "cube-anim.h"
#include "flowery_png.h"

int main(int argc, char **argv)
{
    // Initialise the Graphics & Video subsystem
    GRRLIB_Init();
    // Initialise the Wiimotes
    WPAD_Init();

    Thing *root = ThingFactory::create("Thing");
    Thing *root3d = ThingFactory::create("Thing3D");
    Thing *root2d = ThingFactory::create("Thing2D");
    Thing *rootUI = ThingFactory::create("Thing2D");
    Thing *animMesh = ThingFactory::create("AnimatedMesh");
    Thing *animMesh2 = ThingFactory::create("AnimatedMesh");
    Thing *mesh = ThingFactory::create("MeshRenderer");
    Thing *cam = ThingFactory::create("DebugCamera");
    Thing *txt = ThingFactory::create("DebugText");

    root3d->addChild(animMesh);
    Loadable l;
    l.animatedMesh = &terrencewiianim_animation;
    animMesh->load(l);

    root3d->addChild(mesh);
    Loadable l2;
    l2.mesh = &cube_mesh;
    Material mat = Material();
    mat.texture = GRRLIB_LoadTexture(flowery_png);
    mat.textured = true;
    l2.mat = mat;
    mesh->load(l2);

    root3d->addChild(animMesh2);
    Loadable l3;
    l3.mat = mat;
    l3.animatedMesh = &cube_anim_animation;
    animMesh2->load(l3);

    rootUI->addChild(txt);
    Loadable lT;
    lT.text = "TERRENCE ENGINE";
    txt->load(lT);

    root->addChild(root3d);
    root->addChild(root2d);
    root->addChild(rootUI);
    root->addChild(cam);

    engine.Init(dynamic_cast<Thing3D *>(root3d), dynamic_cast<Thing2D *>(root2d), dynamic_cast<Thing2D *>(rootUI));
    root->init();

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

        GRRLIB_Render(); // Render the frame buffer to the TV
    }

    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB

    exit(0); // Use exit() to exit a program, do not use 'return' from main()
}
