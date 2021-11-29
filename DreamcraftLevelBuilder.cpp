#include "raylib.h"
#include <cmath>
#include "player.h"





int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 800;

    //Initalize Audio Device
    InitAudioDevice();
    

    
    InitWindow(screenWidth, screenHeight, "Dreamcraft Bedrock Edition");
    


    //int levelDat[20][10];
    int levelData[40][22] = {0
    };
    Vector2 mousePosition;
    int mouseBlock = 0;
    bool guiDrawn = false;
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
    Texture2D oakLeavesTexture = LoadTexture("res/gfx/block/oak_leaves.png"); 
    Texture2D birchWoodTexture = LoadTexture("res/gfx/block/birch_log.png"); 
    Texture2D birchLeavesTexture = LoadTexture("res/gfx/block/birch_leaves.png");
    Texture2D brickTexture = LoadTexture("res/gfx/block/bricks.png");

    //Initalize Sounds
Sound breakBlock = LoadSound("res/sfx/sounds/random/break.ogg");
    //Initalize Music
    
    int mouseArray[2] = {0,0};

    //Init Player
    Player dream = {100,100,false,false,false,false,0,0,0};

   
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        mousePosition = GetMousePosition();
        if (mousePosition.y > 96)
        {
        mouseArray[0] = floor(mousePosition.x/32);
        mouseArray[1] = floor((mousePosition.y-96)/32);
        if (IsMouseButtonPressed(0)){
        levelData[mouseArray[0]][mouseArray[1]] = mouseBlock;
        PlaySound(breakBlock);
        switch (mouseBlock)
        {
        case 0:
                
                break;
        
        default:
                break;
        }
        }
        }
        if (mousePosition.y < 96)
        {
        if (IsMouseButtonPressed(0)) mouseBlock = (round(mousePosition.x/52)*2+floor(mousePosition.y/48)-2);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
        
            //draws the level
            for (int i = 0; i <40; i++)
            {
                for (int d = 0; d < 22; d++)
                {
                        //selects which texture to draw based on the integer
                        switch (levelData[i][d])
                        {
                            case 0:
                                break;
                            case 1:
                                DrawTexture(playerTexture,i*32,d*32+96,RAYWHITE);
                                break;
                        case 2:
                                DrawTexture(dirtTexture,i*32,d*32+96,WHITE);
                                break;
                        case 3:
                                DrawTexture(grassTexture,i*32,d*32+96,WHITE);
                                break;
                        case 4:
                                DrawTexture(oakLogTexture,i*32,d*32+96,WHITE);
                                break;
                        case 5:
                                DrawTexture(stoneTexture,i*32,d*32+96,WHITE);
                                break;
                        case 6:
                                DrawTexture(ironOreTexture,i*32,d*32+96,WHITE);
                                break;
                        case 7:
                                DrawTexture(coalOreTexture,i*32,d*32+96,WHITE);
                                break;
                        case 8:
                                DrawTexture(cobblestoneTexture,i*32,d*32+96,WHITE);
                                break;
                        case 9:
                                DrawTexture(oakPlankTexture,i*32,d*32+96,WHITE);
                                break;
                        case 10:
                                DrawTexture(oakLeavesTexture,i*32,d*32+96,DARKGREEN);
                                break;
                        case 11:
                                DrawTexture(birchWoodTexture,i*32,d*32+96,WHITE);
                                break;
                        case 12:
                            DrawTexture(birchLeavesTexture,i*32,d*32+96,WHITE);
                                break;
                        case 13:
                            DrawTexture(brickTexture,i*32,d*32+96,WHITE);
                        case 14:
                            break;
                        default:
                            break;
                        }
                    }
                }

    //Block Selection GUI
    while ((guiDrawn = false))
    {
        DrawRectangle(20,10,32,32,GRAY);
        DrawRectangle(20,52,32,32,GREEN);
        DrawTexture(dirtTexture,72,10,WHITE);
        DrawTexture(grassTexture,72,52,WHITE);
        DrawTexture(oakLogTexture,124,10,WHITE);
        DrawTexture(stoneTexture,124,52,WHITE);
        DrawTexture(ironOreTexture,176,10,WHITE);
        DrawTexture(coalOreTexture,176,52,WHITE);
        DrawTexture(cobblestoneTexture,228,10,WHITE);
        DrawTexture(oakPlankTexture,228,52,WHITE);
        DrawTexture(oakLeavesTexture,280,10,WHITE);
        DrawTexture(birchLeavesTexture,280,52,DARKGREEN);
        DrawTexture(birchWoodTexture,332,10,WHITE);
        DrawTexture(brickTexture,332,52,WHITE);
        DrawRectangle(384,10,32,32,BLUE);
        DrawRectangle(384,52,32,32,BLUE);
        DrawRectangle(436,10,32,32,BLUE);
        DrawRectangle(436,52,32,32,BLUE);
        DrawRectangle(488,10,32,32,BLUE);
        DrawRectangle(488,52,32,32,BLUE);
        DrawRectangle(540,10,32,32,BLUE);
        DrawRectangle(540,52,32,32,BLUE);
        DrawRectangle(592,10,32,32,BLUE);
        DrawRectangle(592,52,32,32,BLUE);
        DrawRectangle(644,10,32,32,BLUE);
        DrawRectangle(644,52,32,32,BLUE);
        DrawRectangle(696,10,32,32,BLUE);
        DrawRectangle(696,52,32,32,BLUE);
        DrawRectangle(748,10,32,32,BLUE);
        DrawRectangle(748,52,32,32,BLUE);
        DrawRectangle(800,10,32,32,BLUE);
        DrawRectangle(800,52,32,32,BLUE);
        DrawRectangle(852,10,32,32,BLUE);
        DrawRectangle(852,52,32,32,BLUE);
        DrawRectangle(904,10,32,32,BLUE);
        DrawRectangle(904,52,32,32,BLUE);
        DrawRectangle(956,10,32,32,BLUE);
        DrawRectangle(956,52,32,32,BLUE);
        DrawRectangle(1008,10,32,32,BLUE);
        DrawRectangle(1008,52,32,32,BLUE);
        DrawRectangle(1060,10,32,32,BLUE);
        DrawRectangle(1060,52,32,32,BLUE);
        DrawRectangle(1112,10,32,32,BLUE);
        DrawRectangle(1112,52,32,32,BLUE);
        DrawRectangle(1164,10,32,32,BLUE);
        DrawRectangle(1164,52,32,32,BLUE);
        DrawRectangle(1216,10,32,32,BLUE);
        DrawRectangle(1216,52,32,32,BLUE);//Block Selection GUI Drawing
        DrawRectangle(20,10,32,32,GRAY);
        DrawRectangle(20,52,32,32,GREEN);
        DrawTexture(dirtTexture,72,10,WHITE);
        DrawTexture(grassTexture,72,52,WHITE);
        DrawTexture(oakLogTexture,124,10,WHITE);
        DrawTexture(stoneTexture,124,52,WHITE);
        DrawTexture(ironOreTexture,176,10,WHITE);
        DrawTexture(coalOreTexture,176,52,WHITE);
        DrawTexture(cobblestoneTexture,228,10,WHITE);
        DrawTexture(oakPlankTexture,228,52,WHITE);
        DrawTexture(oakLeavesTexture,280,10,WHITE);
        DrawTexture(birchLeavesTexture,280,52,DARKGREEN);
        DrawTexture(birchWoodTexture,332,10,WHITE);
        DrawTexture(brickTexture,332,52,WHITE);
        DrawRectangle(384,10,32,32,BLUE);
        DrawRectangle(384,52,32,32,BLUE);
        DrawRectangle(436,10,32,32,BLUE);
        DrawRectangle(436,52,32,32,BLUE);
        DrawRectangle(488,10,32,32,BLUE);
        DrawRectangle(488,52,32,32,BLUE);
        DrawRectangle(540,10,32,32,BLUE);
        DrawRectangle(540,52,32,32,BLUE);
        DrawRectangle(592,10,32,32,BLUE);
        DrawRectangle(592,52,32,32,BLUE);
        DrawRectangle(644,10,32,32,BLUE);
        DrawRectangle(644,52,32,32,BLUE);
        DrawRectangle(696,10,32,32,BLUE);
        DrawRectangle(696,52,32,32,BLUE);
        DrawRectangle(748,10,32,32,BLUE);
        DrawRectangle(748,52,32,32,BLUE);
        DrawRectangle(800,10,32,32,BLUE);
        DrawRectangle(800,52,32,32,BLUE);
        DrawRectangle(852,10,32,32,BLUE);
        DrawRectangle(852,52,32,32,BLUE);
        DrawRectangle(904,10,32,32,BLUE);
        DrawRectangle(904,52,32,32,BLUE);
        DrawRectangle(956,10,32,32,BLUE);
        DrawRectangle(956,52,32,32,BLUE);
        DrawRectangle(1008,10,32,32,BLUE);
        DrawRectangle(1008,52,32,32,BLUE);
        DrawRectangle(1060,10,32,32,BLUE);
        DrawRectangle(1060,52,32,32,BLUE);
        DrawRectangle(1112,10,32,32,BLUE);
        DrawRectangle(1112,52,32,32,BLUE);
        DrawRectangle(1164,10,32,32,BLUE);
        DrawRectangle(1164,52,32,32,BLUE);
        DrawRectangle(1216,10,32,32,BLUE);
        DrawRectangle(1216,52,32,32,BLUE);
        guiDrawn = true;
    }
    
    

    

    

    //Draw Player
    DrawTexture(playerTexture,dream.x,dream.y,WHITE);

    EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
