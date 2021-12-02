#include "raylib.h"
#include <cmath>
#include "player.h"
#include <iostream>
#include <fstream>



using namespace std;
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //Initalize Audio Device
    InitAudioDevice();
    

    
    InitWindow(screenWidth, screenHeight, "Dreamcraft Bedrock Edition");
    


    int levelData[40][20] = {0};
    Vector2 mousePosition;
    int mouseBlock = 0;
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
    //Initalize Texture Pointers to pass as parameters to the varBlock Function 
    Texture2D* dirtTexturePtr = &dirtTexture;
    Texture2D* grassTexturePtr = &grassTexture; 
    Texture2D* dirtTexturePtr = &oakLogTexture;
    Texture2D* brickTexturePtr = &stoneTexture; 
    Texture2D* dirtTexturePtr = &ironOreTexture;
    Texture2D* brickTexturePtr = &coalOreTexture; 
    Texture2D* dirtTexturePtr = &cobblestoneTexture;
    Texture2D* dirtTexturePtr = &oakPlankTexture;
    Texture2D* grassTexturePtr = &oakLeavesTexture; 
    Texture2D* dirtTexturePtr = &birchWoodTexture;
    Texture2D* brickTexturePtr = &birchLeavesTexture; 
    Texture2D* brickTexturePtr = &brickTexture;
    
        
    //Initalize Sounds
Sound breakBlock = LoadSound("res/sfx/sounds/random/break.ogg");
    //Initalize Music
    
    int mouseArray[2] = {0,0};

    //Init Player
    //Player dream = {100,100,false,false,false,false,0,0,0};

   
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        mousePosition = GetMousePosition();
        if (mousePosition.y > 80)
        {
        mouseArray[0] = floor(mousePosition.x/32);
        mouseArray[1] = floor((mousePosition.y-80)/32);
        if (IsMouseButtonPressed(0)){
        levelData[mouseArray[0]][mouseArray[1]] = mouseBlock;
        PlaySound(breakBlock);
        }
        }
        if (mousePosition.y < 80)
        {
        if (IsMouseButtonPressed(0)) mouseBlock = ((floor(mousePosition.x/52)*2)+(floor(mousePosition.y/40)));
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
        
            //draws the level
            for (int i = 0; i <40; i++)
            {
                for (int d = 0; d < 20; d++)
                {
                        //selects which texture to draw based on the integers stored in the level data
                        switch (levelData[i][d])
                        {
                        case 0:
                                break;
                        case 1:
                                DrawTexture(dirtTexture,i*32,d*32+80,WHITE);
                                break;
                        case 2:
                                DrawTexture(grassTexture,i*32,d*32+80,WHITE);
                                break;
                        case 3:
                                DrawTexture(oakLogTexture,i*32,d*32+80,WHITE);
                                break;
                        case 4:
                                DrawTexture(stoneTexture,i*32,d*32+80,WHITE);
                                break;
                        case 5:
                                DrawTexture(ironOreTexture,i*32,d*32+80,WHITE);
                                break;
                        case 6:
                                DrawTexture(coalOreTexture,i*32,d*32+80,WHITE);
                                break;
                        case 7:
                                DrawTexture(cobblestoneTexture,i*32,d*32+80,WHITE);
                                break;
                        case 8:
                                DrawTexture(oakPlankTexture,i*32,d*32+80,WHITE);
                                break;
                        case 9:
                                DrawTexture(oakLeavesTexture,i*32,d*32+80,DARKGREEN);
                                break;
                        case 10:
                                DrawTexture(birchLeavesTexture,i*32,d*32+80,DARKGREEN);
                                break;
                        case 11:
                                DrawTexture(birchWoodTexture,i*32,d*32+80,WHITE);
                                break;
                        case 12:
                                DrawTexture(brickTexture,i*32,d*32+80,WHITE);
                                break;
                        case 13:

                                break;
                        default:
                                break;
                        }
                    }
                }

        
        DrawRectangle(20,5,32,32,GRAY);
        DrawTexture(dirtTexture,20,45,WHITE);
        DrawTexture(grassTexture,72,5,WHITE);
        DrawTexture(oakLogTexture,72,45,WHITE);
        DrawTexture(stoneTexture,124,5,WHITE);
        DrawTexture(ironOreTexture,124,45,WHITE);
        DrawTexture(coalOreTexture,176,5,WHITE);
        DrawTexture(cobblestoneTexture,176,45,WHITE);
        DrawTexture(oakPlankTexture,228,5,WHITE);
        DrawTexture(oakLeavesTexture,228,45,DARKGREEN);
        DrawTexture(birchLeavesTexture,280,5,DARKGREEN);
        DrawTexture(birchWoodTexture,280,45,WHITE);
        DrawTexture(brickTexture,332,5,WHITE);
        DrawRectangle(332,45,32,32,BLUE);
        DrawRectangle(384,5,32,32,BLUE);
        DrawRectangle(384,45,32,32,BLUE);
        DrawRectangle(436,5,32,32,BLUE);
        DrawRectangle(436,45,32,32,BLUE);
        DrawRectangle(488,5,32,32,BLUE);
        DrawRectangle(488,45,32,32,BLUE);
        DrawRectangle(540,5,32,32,BLUE);
        DrawRectangle(540,45,32,32,BLUE);
        DrawRectangle(592,5,32,32,BLUE);
        DrawRectangle(592,45,32,32,BLUE);
        DrawRectangle(644,5,32,32,BLUE);
        DrawRectangle(644,45,32,32,BLUE);
        DrawRectangle(696,5,32,32,BLUE);
        DrawRectangle(696,45,32,32,BLUE);
        DrawRectangle(748,5,32,32,BLUE);
        DrawRectangle(748,45,32,32,BLUE);
        DrawRectangle(800,5,32,32,BLUE);
        DrawRectangle(800,45,32,32,BLUE);
        DrawRectangle(852,5,32,32,BLUE);
        DrawRectangle(852,45,32,32,BLUE);
        DrawRectangle(904,5,32,32,BLUE);
        DrawRectangle(904,45,32,32,BLUE);
        DrawRectangle(956,5,32,32,BLUE);
        DrawRectangle(956,45,32,32,BLUE);
        DrawRectangle(1008,5,32,32,BLUE);
        DrawRectangle(1008,45,32,32,BLUE);
        DrawRectangle(1060,5,32,32,BLUE);
        DrawRectangle(1060,45,32,32,BLUE);
        DrawRectangle(1112,5,32,32,BLUE);
        DrawRectangle(1112,45,32,32,BLUE);
        DrawRectangle(1164,5,32,32,BLUE);
        DrawRectangle(1164,45,32,32,BLUE);
        DrawRectangle(1216,5,32,32,BLUE);
        DrawRectangle(1216,45,32,32,BLUE);
        
        
    
    

    

    

    //Draw Player
    //DrawTexture(playerTexture,dream.x,dream.y,WHITE);

    EndDrawing();
        //----------------------------------------------------------------------------------
    }
        
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

        //write level data to txt
        ofstream myfile ("level.txt");
        if (myfile.is_open())
        {
        for (int i = 0; i <40; i++)
                {
                        myfile << "{" ;
                        for (int d = 0; d < 20; d++)
                        {
                                if (d < 20)
                                myfile << levelData[i][d] << ",";
                                else
                                myfile << levelData[i][d];
                        }
                        if (i < 39)
                        {
                                myfile << "},";
                        }
                        else
                        {
                                myfile << "}";
                        }
                }
        myfile.close();
        }
        else cout << "Unable to open file";
        return 0;
}
