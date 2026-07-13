#include "engine.h"
#include <grrlib.h>
#include <ogc/gx.h>
#include "font_png.h"
#include "meshanimation.h"
#include <string>

void Engine::Init(Thing3D *root3, Thing2D *root2, Thing2D *rootui)
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

    root3d = root3;
    root2d = root2;
    rootUI = rootui;
}

void Engine::print(const char *text)
{
    GRRLIB_Printf(20, 20, tex_font, 0xFFFFFFFF, 1, text);
}

void Engine::DrawMesh(
    Mesh &mesh,
    Transform transform,
    Material material)
{
    GX_ClearVtxDesc();

    GX_SetVtxDesc(
        GX_VA_POS,
        GX_DIRECT);

    GX_SetVtxDesc(
        GX_VA_CLR0,
        GX_DIRECT);

    if (material.textured)
        GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

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

    if (material.textured)
    {
        GX_SetVtxAttrFmt(
            GX_VTXFMT0,
            GX_VA_TEX0,
            GX_TEX_ST,
            GX_F32,
            0);
    }

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

    if (material.textured && material.texture)
    {
        if (!material.texObjInitialized)
        {
            GX_InitTexObj(
                &material.texObj,
                material.texture->data,
                material.texture->w,
                material.texture->h,
                material.texture->format,
                GX_CLAMP,
                GX_CLAMP,
                GX_FALSE);

            material.texObjInitialized = true;
        }

        GX_LoadTexObj(&material.texObj, GX_TEXMAP0);

        GX_SetNumTexGens(1);

        GX_SetTexCoordGen(
            GX_TEXCOORD0,
            GX_TG_MTX2x4,
            GX_TG_TEX0,
            GX_IDENTITY);

        GX_SetTevOrder(
            GX_TEVSTAGE0,
            GX_TEXCOORD0,
            GX_TEXMAP0,
            GX_COLOR0A0);

        GX_SetTevOp(
            GX_TEVSTAGE0,
            GX_MODULATE);
    }
    else
    {
        GX_SetNumTexGens(0);

        GX_SetTevOrder(
            GX_TEVSTAGE0,
            GX_TEXCOORDNULL,
            GX_TEXMAP_NULL,
            GX_COLOR0A0);

        GX_SetTevOp(
            GX_TEVSTAGE0,
            GX_PASSCLR);
    }

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

        if (material.textured)
        {
            GX_TexCoord2f32(v.u, v.v);
        }
    }

    GX_End();
}

void Engine::DrawAnimFrame(MeshAnimation &mesh, Transform transform, int frame, Material material)
{
    GX_ClearVtxDesc();

    GX_SetVtxDesc(
        GX_VA_POS,
        GX_DIRECT);

    GX_SetVtxDesc(
        GX_VA_CLR0,
        GX_DIRECT);

    if (material.textured)
        GX_SetVtxDesc(GX_VA_TEX0, GX_DIRECT);

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

    if (material.textured)
    {
        GX_SetVtxAttrFmt(
            GX_VTXFMT0,
            GX_VA_TEX0,
            GX_TEX_ST,
            GX_F32,
            0);
    }

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

    if (material.textured && material.texture)
    {
        if (!material.texObjInitialized)
        {
            GX_InitTexObj(
                &material.texObj,
                material.texture->data,
                material.texture->w,
                material.texture->h,
                material.texture->format,
                GX_CLAMP,
                GX_CLAMP,
                GX_FALSE);

            material.texObjInitialized = true;
        }

        GX_LoadTexObj(&material.texObj, GX_TEXMAP0);

        GX_SetNumTexGens(1);

        GX_SetTexCoordGen(
            GX_TEXCOORD0,
            GX_TG_MTX2x4,
            GX_TG_TEX0,
            GX_IDENTITY);

        GX_SetTevOrder(
            GX_TEVSTAGE0,
            GX_TEXCOORD0,
            GX_TEXMAP0,
            GX_COLOR0A0);

        GX_SetTevOp(
            GX_TEVSTAGE0,
            GX_MODULATE);
    }
    else
    {
        GX_SetNumTexGens(0);

        GX_SetTevOrder(
            GX_TEVSTAGE0,
            GX_TEXCOORDNULL,
            GX_TEXMAP_NULL,
            GX_COLOR0A0);

        GX_SetTevOp(
            GX_TEVSTAGE0,
            GX_PASSCLR);
    }
    GX_Begin(
        GX_TRIANGLES,
        GX_VTXFMT0,
        mesh.index_count);

    for (unsigned int i = 0; i < mesh.index_count; i++)
    {
        Vertex &v = mesh.frames[frame][mesh.indices[i]];
        ;

        GX_Position3f32(
            v.x + transform.position.x,
            v.y + transform.position.y,
            v.z + transform.position.z);

        GX_Color4u8(
            v.r,
            v.g,
            v.b,
            v.a);

        if (material.textured)
        {
            GX_TexCoord2f32(v.u, v.v);
        }
    }

    GX_End();
}

void Engine::DrawMesh(
    Mesh &mesh,
    float x,
    float y,
    float z,
    Material material)
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

    DrawMesh(mesh, t, material);
}

void Engine::DrawAnimFrame(
    MeshAnimation &mesh,
    int frame,
    float x,
    float y,
    float z,
    Material material)
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

    DrawAnimFrame(mesh, t, frame, material);
}

void Engine::Begin3D()
{
    if (!in3D)
    {
        GRRLIB_3dMode(
            45.0f,
            50000.0f,
            0.1f,
            true,
            true);
        in3D = true;
    }
}

void Engine::End3D()
{
    if (in3D)
    {
        GRRLIB_2dMode();
        in3D = false;
    }
}

Engine engine;