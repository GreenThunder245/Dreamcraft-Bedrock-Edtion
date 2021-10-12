/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>
#include <cmath>
Vector2 mousePosition;
//Function Signatures

void varBlock(int xPos, int yPos,int blockType);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //int levelDat[20][10];
    int levelData[30][20] = { 
    {1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10}
    };

    //initalize Textures
    Texture2D playerTexture = LoadTexture("res/gfx/dream.png");
    Texture2D dirtTexture = LoadTexture("res/gfx/block/dirt.png");
    Texture2D grassTexture = LoadTexture("res/gfx/block/grass_block_side.png");
    Texture2D oakLogTexture = LoadTexture("res/gfx/block/oak_log.png");
    Texture2D stoneTexture = LoadTexture("res/gfx/block/stone.png");
    Texture2D ironOreTexture = LoadTexture("res/gfx/block/iron_ore.png"); 
    Texture2D coalOreTexture = LoadTexture("res/gfx/block/coal_ore.png");
    Texture2D cobblestoneTexture = LoadTexture("res/gfx/block/cobblestone.png"); 
    Texture2D oakPlankTexture = LoadTexture("res/gfx/block/oak_planks.png"); 
    Texture2D oakLeaveTexture = LoadTexture("res/gfx/block/oak_leaves.png"); 
    Texture2D birchWoodTexture = LoadTexture("res/gfx/block/birch_log.png"); 
    //Texture2D birchLeaveTexture = LoadTexture("res/gfx/block/birch_leaves.png");
    //Texture2D savannaWoodTexture = LoadTexture("res/gfx/block/birch_log.png");
    //Texture2D savannaLeaves = LoadTexture("res/gfx/block/birch_log.png");
    //Texture2D spruceWoodTexture = LoadTexture("res/gfx/block/birch_log.png");
    //Texture2D spruceLeaveTexture = LoadTexture("res/gfx/block/birch_log.png");
    //Texture2D andesiteTexture = LoadTexture("res/gfx/block/birch_log.png");
    //Texture2D mossyCobblestoneTexture = LoadTexture("res/gfx/block/birch_log.png");

    //

    //
    int mouseArray[2] = {0,0};

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        mousePosition = GetMousePosition();

        mouseArray[0] = round(mousePosition.x/32);
        mouseArray[1] = round(mousePosition.y/32);
        if (IsMouseButtonPressed(0)) levelData[mouseArray[0]][mouseArray[1]] = 1; 
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            for (int i = 0; i <30; i++)
            {
                for (int d = 0; d < 20; d++)
                {
                        switch (levelData[i][d])
    {
        case 0:
        DrawTexture(playerTexture,i*32,d*32,WHITE);
        break;
    case 1:
        DrawTexture(dirtTexture,i*32,d*32,WHITE);
        break;
    case 2:
        DrawTexture(grassTexture,i*32,d*32,WHITE);
        break;
    case 3:
        DrawTexture(oakLogTexture,i*32,d*32,WHITE);
        break;
    case 4:
        DrawTexture(stoneTexture,i*32,d*32,WHITE);
        break;
    case 5:
        DrawTexture(ironOreTexture,i*32,d*32,WHITE);
        break;
    case 6:
        DrawTexture(coalOreTexture,i*32,d*32,WHITE);
        break;
    case 7:
        DrawTexture(cobblestoneTexture,i*32,d*32,WHITE);
        break;
    case 8:
        DrawTexture(oakPlankTexture,i*32,d*32,WHITE);
        break;
    case 9:
        DrawTexture(oakLeaveTexture,i*32,d*32,DARKGREEN);
        break;
    case 10:
        DrawTexture(birchWoodTexture,i*32,d*32,WHITE);
        break;
    default:
        break;
    }
                }
            }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}