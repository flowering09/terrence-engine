#include "engine.h"
#include <grrlib.h>
#include <ogc/gx.h>
#include "font_png.h"
#include <string>

void Engine::Init()
{
    tex_font = GRRLIB_LoadTexture(font_png);
    GRRLIB_InitTileSet(tex_font, 16, 16, 32);

    GX_ClearVtxDesc();

    GX_SetVtxDesc(
        GX_VA_POS,
        GX_DIRECT);

    GX_SetVtxAttrFmt(
        GX_VTXFMT0,
        GX_VA_POS,
        GX_POS_XYZ,
        GX_F32,
        0);

    GX_SetNumTexGens(0);
    GX_SetNumTevStages(1);
    GX_SetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
}

void Engine::print(const char *text)
{
    GRRLIB_Printf(20, 20, tex_font, 0xFFFFFFFF, 1, text);
}

void Engine::DrawMesh(Mesh &mesh, Transform transform)
{
    GX_ClearVtxDesc();

    GX_SetVtxDesc(
        GX_VA_POS,
        GX_DIRECT);

    GX_SetVtxDesc(
        GX_VA_CLR0,
        GX_DIRECT);

    GX_SetVtxAttrFmt(
        GX_VTXFMT0,
        GX_VA_POS,
        GX_POS_XYZ,
        GX_F32,
        0);

    GX_SetVtxAttrFmt(
        GX_VTXFMT0,
        GX_VA_CLR0,
        GX_CLR_RGBA,
        GX_RGBA8,
        0);

    GX_SetCullMode(GX_CULL_BACK);

    GX_SetNumTevStages(1);
    GX_SetTevOp(
        GX_TEVSTAGE0,
        GX_PASSCLR);

    GX_SetNumChans(1);

    GX_SetChanCtrl(
        GX_COLOR0A0,
        GX_DISABLE,
        GX_SRC_VTX,
        GX_SRC_VTX,
        0,
        GX_DF_NONE,
        GX_AF_NONE);

    GX_SetNumTevStages(1);

    GX_SetTevOrder(
        GX_TEVSTAGE0,
        GX_TEXCOORDNULL,
        GX_TEXMAP_NULL,
        GX_COLOR0A0);

    GX_SetTevOp(
        GX_TEVSTAGE0,
        GX_PASSCLR);

    GX_Begin(
        GX_TRIANGLES,
        GX_VTXFMT0,
        mesh.index_count);

    for (unsigned int i = 0; i < mesh.index_count; i++)
    {
        Vertex &v = mesh.vertices[mesh.indices[i]];

        GX_Position3f32(
            v.x + transform.position.x,
            v.y + transform.position.y,
            v.z + transform.position.z);

        GX_Color4u8(
            v.r,
            v.g,
            v.b,
            v.a);
    }

    GX_End();
}

void Engine::DrawMesh(
    Mesh &mesh,
    float x,
    float y,
    float z)
{
    Transform t;

    t.position.x = x;
    t.position.y = y;
    t.position.z = z;

    t.rotation.x = 0;
    t.rotation.y = 0;
    t.rotation.z = 0;

    t.scale.x = 1;
    t.scale.y = 1;
    t.scale.z = 1;

    DrawMesh(mesh, t);
}

void Engine::Begin3D()
{
    GRRLIB_3dMode(
        45.0f,
        50000.0f,
        0.1f,
        true,
        true);
}

void Engine::End3D()
{
    GRRLIB_2dMode();
}

Engine engine;