#include "raylib.h"
#include <cmath>
#include "raylib.h"
#include <cmath>
#include <iostream>
#include <fstream>

//function Signitures
void levelDataDraw(Texture2D* textureAtlasLevelPtr, int levelData[40][20]); //function signature
void guiDraw(Texture2D* textureAtlasLevelPtr, int guiScroll,const int scrollSpeed); //function signature
void levelSave(int levelData[40][20]);

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
     Texture2D textureAtlasLevel = LoadTexture("res/gfx/DreamCraftAtlas.png");
     Texture2D* textureAtlasLevelPtr = &textureAtlasLevel;
    //Initalize Sounds
     Sound breakBlock = LoadSound("res/sfx/sounds/random/break.ogg");
    //Initalize Music
    
    int mouseArray[2] = {0,0};
    int guiScroll = 0;
    const int scrollSpeed = 16;
    //Init Player
    //

   
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
        mouseArray[0] = floor((mousePosition.x)/32);
        mouseArray[1] = floor((mousePosition.y-80)/32); //dont remove the -80
        if (IsMouseButtonPressed(0)){
        levelData[mouseArray[0]][mouseArray[1]] = mouseBlock;
        PlaySound(breakBlock);
        }
        }
        if (mousePosition.y < 80)
        {
        if (IsMouseButtonPressed(0)) mouseBlock = ((floor((mousePosition.x+(guiScroll))/52)*2)+(floor(mousePosition.y/40)));
        }
        guiScroll -= (GetMouseWheelMove()*scrollSpeed);
        if (guiScroll < 0)
        {
             guiScroll = 0;
        }
          else if (guiScroll > 8808-1240)
        {
             guiScroll = 8808-1240;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
        
            //draws the level
            levelDataDraw(textureAtlasLevelPtr,levelData);


        
        
          //Draw Gui
          guiDraw(textureAtlasLevelPtr,guiScroll,scrollSpeed);
    

    

    


    EndDrawing();
        //----------------------------------------------------------------------------------
    }
        
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

        //write level data to txt
        levelSave(levelData);
        return 0;
}
void levelDataDraw (Texture2D* textureAtlasLevelPtr, int levelData[40][20])// this function draws the stage
{
               for (int i = 0; i <40; i++)
               {
                    for (int d = 0; d < 20; d++)
                    {
                    switch (levelData[i][d])
                         {
                        case 1 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 2 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 3 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 4 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 5 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 6 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 7 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 8 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 9 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 10 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 11 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 12 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 13 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 14 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 15 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 16 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 17 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 18 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 19 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 20 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 21 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 22 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 23 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 24 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 25 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 26 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 27 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 28 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 29 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 30 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 31 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 32 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,0,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 33 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 34 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 35 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 36 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 37 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 38 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 39 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 40 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 41 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 42 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 43 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 44 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 45 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 46 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 47 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 48 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 49 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 50 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 51 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 52 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 53 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 54 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 55 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 56 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 57 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 58 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 59 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 60 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 61 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 62 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 63 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 64 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,32,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 65 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 66 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 67 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 68 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 69 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 70 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 71 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 72 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 73 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 74 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 75 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 76 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 77 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 78 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 79 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 80 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 81 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 82 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 83 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 84 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 85 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 86 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 87 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 88 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 89 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 90 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 91 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 92 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 93 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 94 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 95 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 96 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,64,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 97 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 98 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 99 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 100 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 101 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 102 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 103 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 104 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 105 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 106 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 107 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 108 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 109 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 110 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 111 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 112 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 113 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 114 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 115 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 116 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 117 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 118 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 119 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 120 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 121 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 122 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 123 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 124 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 125 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 126 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 127 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 128 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,96,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 129 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 130 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 131 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 132 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 133 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 134 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 135 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 136 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 137 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 138 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 139 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 140 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 141 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 142 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 143 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 144 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 145 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 146 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 147 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 148 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 149 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 150 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 151 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 152 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 153 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 154 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 155 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 156 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 157 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 158 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 159 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 160 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,128,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 161 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 162 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 163 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 164 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 165 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 166 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 167 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 168 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 169 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 170 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 171 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 172 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 173 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 174 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 175 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 176 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 177 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 178 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 179 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 180 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 181 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 182 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 183 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 184 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 185 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 186 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 187 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 188 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 189 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 190 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 191 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 192 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,160,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 193 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 194 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 195 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 196 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 197 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 198 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 199 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 200 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 201 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 202 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 203 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 204 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 205 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 206 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 207 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 208 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 209 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 210 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 211 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 212 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 213 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 214 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 215 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 216 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 217 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 218 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 219 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 220 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 221 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 222 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 223 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 224 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,192,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 225 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 226 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 227 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 228 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 229 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 230 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 231 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 232 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 233 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 234 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 235 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 236 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 237 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 238 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 239 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 240 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 241 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 242 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 243 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 244 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 245 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 246 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 247 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 248 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 249 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 250 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 251 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 252 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 253 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 254 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 255 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 256 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,224,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 257 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 258 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 259 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 260 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 261 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 262 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 263 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 264 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 265 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 266 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 267 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 268 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 269 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 270 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 271 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 272 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 273 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 274 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 275 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 276 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 277 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 278 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 279 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 280 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 281 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 282 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 283 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 284 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 285 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 286 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 287 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 288 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,256,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 289 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 290 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 291 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 292 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 293 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 294 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 295 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 296 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 297 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 298 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 299 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 300 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 301 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 302 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 303 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 304 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 305 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 306 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 307 :
                             DrawTextureRec(*textureAtlasLevelPtr,{576,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 308 :
                             DrawTextureRec(*textureAtlasLevelPtr,{608,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 309 :
                             DrawTextureRec(*textureAtlasLevelPtr,{640,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 310 :
                             DrawTextureRec(*textureAtlasLevelPtr,{672,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 311 :
                             DrawTextureRec(*textureAtlasLevelPtr,{704,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 312 :
                             DrawTextureRec(*textureAtlasLevelPtr,{736,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 313 :
                             DrawTextureRec(*textureAtlasLevelPtr,{768,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 314 :
                             DrawTextureRec(*textureAtlasLevelPtr,{800,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 315 :
                             DrawTextureRec(*textureAtlasLevelPtr,{832,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 316 :
                             DrawTextureRec(*textureAtlasLevelPtr,{864,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 317 :
                             DrawTextureRec(*textureAtlasLevelPtr,{896,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 318 :
                             DrawTextureRec(*textureAtlasLevelPtr,{928,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 319 :
                             DrawTextureRec(*textureAtlasLevelPtr,{960,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 320 :
                             DrawTextureRec(*textureAtlasLevelPtr,{992,288,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 321 :
                             DrawTextureRec(*textureAtlasLevelPtr,{0,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 322 :
                             DrawTextureRec(*textureAtlasLevelPtr,{32,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 323 :
                             DrawTextureRec(*textureAtlasLevelPtr,{64,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 324 :
                             DrawTextureRec(*textureAtlasLevelPtr,{96,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 325 :
                             DrawTextureRec(*textureAtlasLevelPtr,{128,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 326 :
                             DrawTextureRec(*textureAtlasLevelPtr,{160,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 327 :
                             DrawTextureRec(*textureAtlasLevelPtr,{192,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 328 :
                             DrawTextureRec(*textureAtlasLevelPtr,{224,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 329 :
                             DrawTextureRec(*textureAtlasLevelPtr,{256,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 330 :
                             DrawTextureRec(*textureAtlasLevelPtr,{288,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 331 :
                             DrawTextureRec(*textureAtlasLevelPtr,{320,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 332 :
                             DrawTextureRec(*textureAtlasLevelPtr,{352,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 333 :
                             DrawTextureRec(*textureAtlasLevelPtr,{384,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 334 :
                             DrawTextureRec(*textureAtlasLevelPtr,{416,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 335 :
                             DrawTextureRec(*textureAtlasLevelPtr,{448,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 336 :
                             DrawTextureRec(*textureAtlasLevelPtr,{480,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 337 :
                             DrawTextureRec(*textureAtlasLevelPtr,{512,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        case 338 :
                             DrawTextureRec(*textureAtlasLevelPtr,{544,320,32,32},{(float)i*32,(float)d*32+80},WHITE); 
                             break;
                        }               
                    }
               }

}
void guiDraw(Texture2D* textureAtlasLevelPtr, int guiScroll,const int scrollSpeed)
{
DrawRectangle(20-guiScroll,5,32,32,GRAY);
DrawTextureRec(*textureAtlasLevelPtr,{0,0,32,32},{(float)20-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,0,32,32},{(float)72-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,0,32,32},{(float)72-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,0,32,32},{(float)124-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,0,32,32},{(float)124-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,0,32,32},{(float)176-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,0,32,32},{(float)176-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,0,32,32},{(float)228-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,0,32,32},{(float)228-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,0,32,32},{(float)280-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,0,32,32},{(float)280-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,0,32,32},{(float)332-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,0,32,32},{(float)332-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,0,32,32},{(float)384-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,0,32,32},{(float)384-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,0,32,32},{(float)436-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,0,32,32},{(float)436-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,0,32,32},{(float)488-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,0,32,32},{(float)488-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,0,32,32},{(float)540-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,0,32,32},{(float)540-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,0,32,32},{(float)592-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,0,32,32},{(float)592-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,0,32,32},{(float)644-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,0,32,32},{(float)644-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,0,32,32},{(float)696-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,0,32,32},{(float)696-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,0,32,32},{(float)748-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,0,32,32},{(float)748-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,0,32,32},{(float)800-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,0,32,32},{(float)800-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,0,32,32},{(float)852-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,32,32,32},{(float)852-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,32,32,32},{(float)904-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,32,32,32},{(float)904-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,32,32,32},{(float)956-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,32,32,32},{(float)956-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,32,32,32},{(float)1008-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,32,32,32},{(float)1008-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,32,32,32},{(float)1060-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,32,32,32},{(float)1060-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,32,32,32},{(float)1112-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,32,32,32},{(float)1112-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,32,32,32},{(float)1164-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,32,32,32},{(float)1164-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,32,32,32},{(float)1216-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,32,32,32},{(float)1216-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,32,32,32},{(float)1268-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,32,32,32},{(float)1268-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,32,32,32},{(float)1320-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,32,32,32},{(float)1320-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,32,32,32},{(float)1372-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,32,32,32},{(float)1372-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,32,32,32},{(float)1424-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,32,32,32},{(float)1424-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,32,32,32},{(float)1476-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,32,32,32},{(float)1476-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,32,32,32},{(float)1528-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,32,32,32},{(float)1528-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,32,32,32},{(float)1580-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,32,32,32},{(float)1580-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,32,32,32},{(float)1632-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,32,32,32},{(float)1632-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,32,32,32},{(float)1684-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,64,32,32},{(float)1684-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,64,32,32},{(float)1736-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,64,32,32},{(float)1736-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,64,32,32},{(float)1788-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,64,32,32},{(float)1788-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,64,32,32},{(float)1840-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,64,32,32},{(float)1840-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,64,32,32},{(float)1892-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,64,32,32},{(float)1892-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,64,32,32},{(float)1944-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,64,32,32},{(float)1944-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,64,32,32},{(float)1996-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,64,32,32},{(float)1996-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,64,32,32},{(float)2048-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,64,32,32},{(float)2048-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,64,32,32},{(float)2100-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,64,32,32},{(float)2100-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,64,32,32},{(float)2152-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,64,32,32},{(float)2152-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,64,32,32},{(float)2204-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,64,32,32},{(float)2204-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,64,32,32},{(float)2256-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,64,32,32},{(float)2256-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,64,32,32},{(float)2308-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,64,32,32},{(float)2308-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,64,32,32},{(float)2360-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,64,32,32},{(float)2360-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,64,32,32},{(float)2412-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,64,32,32},{(float)2412-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,64,32,32},{(float)2464-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,64,32,32},{(float)2464-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,64,32,32},{(float)2516-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,96,32,32},{(float)2516-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,96,32,32},{(float)2568-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,96,32,32},{(float)2568-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,96,32,32},{(float)2620-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,96,32,32},{(float)2620-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,96,32,32},{(float)2672-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,96,32,32},{(float)2672-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,96,32,32},{(float)2724-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,96,32,32},{(float)2724-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,96,32,32},{(float)2776-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,96,32,32},{(float)2776-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,96,32,32},{(float)2828-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,96,32,32},{(float)2828-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,96,32,32},{(float)2880-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,96,32,32},{(float)2880-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,96,32,32},{(float)2932-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,96,32,32},{(float)2932-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,96,32,32},{(float)2984-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,96,32,32},{(float)2984-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,96,32,32},{(float)3036-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,96,32,32},{(float)3036-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,96,32,32},{(float)3088-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,96,32,32},{(float)3088-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,96,32,32},{(float)3140-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,96,32,32},{(float)3140-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,96,32,32},{(float)3192-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,96,32,32},{(float)3192-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,96,32,32},{(float)3244-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,96,32,32},{(float)3244-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,96,32,32},{(float)3296-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,96,32,32},{(float)3296-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,96,32,32},{(float)3348-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,128,32,32},{(float)3348-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,128,32,32},{(float)3400-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,128,32,32},{(float)3400-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,128,32,32},{(float)3452-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,128,32,32},{(float)3452-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,128,32,32},{(float)3504-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,128,32,32},{(float)3504-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,128,32,32},{(float)3556-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,128,32,32},{(float)3556-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,128,32,32},{(float)3608-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,128,32,32},{(float)3608-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,128,32,32},{(float)3660-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,128,32,32},{(float)3660-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,128,32,32},{(float)3712-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,128,32,32},{(float)3712-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,128,32,32},{(float)3764-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,128,32,32},{(float)3764-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,128,32,32},{(float)3816-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,128,32,32},{(float)3816-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,128,32,32},{(float)3868-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,128,32,32},{(float)3868-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,128,32,32},{(float)3920-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,128,32,32},{(float)3920-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,128,32,32},{(float)3972-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,128,32,32},{(float)3972-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,128,32,32},{(float)4024-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,128,32,32},{(float)4024-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,128,32,32},{(float)4076-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,128,32,32},{(float)4076-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,128,32,32},{(float)4128-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,128,32,32},{(float)4128-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,128,32,32},{(float)4180-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,160,32,32},{(float)4180-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,160,32,32},{(float)4232-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,160,32,32},{(float)4232-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,160,32,32},{(float)4284-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,160,32,32},{(float)4284-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,160,32,32},{(float)4336-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,160,32,32},{(float)4336-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,160,32,32},{(float)4388-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,160,32,32},{(float)4388-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,160,32,32},{(float)4440-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,160,32,32},{(float)4440-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,160,32,32},{(float)4492-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,160,32,32},{(float)4492-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,160,32,32},{(float)4544-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,160,32,32},{(float)4544-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,160,32,32},{(float)4596-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,160,32,32},{(float)4596-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,160,32,32},{(float)4648-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,160,32,32},{(float)4648-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,160,32,32},{(float)4700-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,160,32,32},{(float)4700-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,160,32,32},{(float)4752-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,160,32,32},{(float)4752-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,160,32,32},{(float)4804-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,160,32,32},{(float)4804-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,160,32,32},{(float)4856-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,160,32,32},{(float)4856-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,160,32,32},{(float)4908-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,160,32,32},{(float)4908-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,160,32,32},{(float)4960-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,160,32,32},{(float)4960-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,160,32,32},{(float)5012-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,192,32,32},{(float)5012-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,192,32,32},{(float)5064-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,192,32,32},{(float)5064-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,192,32,32},{(float)5116-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,192,32,32},{(float)5116-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,192,32,32},{(float)5168-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,192,32,32},{(float)5168-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,192,32,32},{(float)5220-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,192,32,32},{(float)5220-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,192,32,32},{(float)5272-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,192,32,32},{(float)5272-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,192,32,32},{(float)5324-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,192,32,32},{(float)5324-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,192,32,32},{(float)5376-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,192,32,32},{(float)5376-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,192,32,32},{(float)5428-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,192,32,32},{(float)5428-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,192,32,32},{(float)5480-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,192,32,32},{(float)5480-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,192,32,32},{(float)5532-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,192,32,32},{(float)5532-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,192,32,32},{(float)5584-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,192,32,32},{(float)5584-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,192,32,32},{(float)5636-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,192,32,32},{(float)5636-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,192,32,32},{(float)5688-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,192,32,32},{(float)5688-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,192,32,32},{(float)5740-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,192,32,32},{(float)5740-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,192,32,32},{(float)5792-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,192,32,32},{(float)5792-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,192,32,32},{(float)5844-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,224,32,32},{(float)5844-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,224,32,32},{(float)5896-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,224,32,32},{(float)5896-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,224,32,32},{(float)5948-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,224,32,32},{(float)5948-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,224,32,32},{(float)6000-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,224,32,32},{(float)6000-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,224,32,32},{(float)6052-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,224,32,32},{(float)6052-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,224,32,32},{(float)6104-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,224,32,32},{(float)6104-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,224,32,32},{(float)6156-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,224,32,32},{(float)6156-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,224,32,32},{(float)6208-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,224,32,32},{(float)6208-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,224,32,32},{(float)6260-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,224,32,32},{(float)6260-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,224,32,32},{(float)6312-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,224,32,32},{(float)6312-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,224,32,32},{(float)6364-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,224,32,32},{(float)6364-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,224,32,32},{(float)6416-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,224,32,32},{(float)6416-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,224,32,32},{(float)6468-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,224,32,32},{(float)6468-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,224,32,32},{(float)6520-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,224,32,32},{(float)6520-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,224,32,32},{(float)6572-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,224,32,32},{(float)6572-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,224,32,32},{(float)6624-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,224,32,32},{(float)6624-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,224,32,32},{(float)6676-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,256,32,32},{(float)6676-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,256,32,32},{(float)6728-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,256,32,32},{(float)6728-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,256,32,32},{(float)6780-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,256,32,32},{(float)6780-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,256,32,32},{(float)6832-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,256,32,32},{(float)6832-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,256,32,32},{(float)6884-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,256,32,32},{(float)6884-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,256,32,32},{(float)6936-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,256,32,32},{(float)6936-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,256,32,32},{(float)6988-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,256,32,32},{(float)6988-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,256,32,32},{(float)7040-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,256,32,32},{(float)7040-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,256,32,32},{(float)7092-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,256,32,32},{(float)7092-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,256,32,32},{(float)7144-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,256,32,32},{(float)7144-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,256,32,32},{(float)7196-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,256,32,32},{(float)7196-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,256,32,32},{(float)7248-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,256,32,32},{(float)7248-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,256,32,32},{(float)7300-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,256,32,32},{(float)7300-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,256,32,32},{(float)7352-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,256,32,32},{(float)7352-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,256,32,32},{(float)7404-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,256,32,32},{(float)7404-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,256,32,32},{(float)7456-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,256,32,32},{(float)7456-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,256,32,32},{(float)7508-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,288,32,32},{(float)7508-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,288,32,32},{(float)7560-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,288,32,32},{(float)7560-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,288,32,32},{(float)7612-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,288,32,32},{(float)7612-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,288,32,32},{(float)7664-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,288,32,32},{(float)7664-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,288,32,32},{(float)7716-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,288,32,32},{(float)7716-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,288,32,32},{(float)7768-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,288,32,32},{(float)7768-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,288,32,32},{(float)7820-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,288,32,32},{(float)7820-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,288,32,32},{(float)7872-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,288,32,32},{(float)7872-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,288,32,32},{(float)7924-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,288,32,32},{(float)7924-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,288,32,32},{(float)7976-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{576,288,32,32},{(float)7976-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{608,288,32,32},{(float)8028-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{640,288,32,32},{(float)8028-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{672,288,32,32},{(float)8080-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{704,288,32,32},{(float)8080-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{736,288,32,32},{(float)8132-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{768,288,32,32},{(float)8132-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{800,288,32,32},{(float)8184-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{832,288,32,32},{(float)8184-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{864,288,32,32},{(float)8236-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{896,288,32,32},{(float)8236-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{928,288,32,32},{(float)8288-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{960,288,32,32},{(float)8288-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{992,288,32,32},{(float)8340-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{0,320,32,32},{(float)8340-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{32,320,32,32},{(float)8392-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{64,320,32,32},{(float)8392-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{96,320,32,32},{(float)8444-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{128,320,32,32},{(float)8444-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{160,320,32,32},{(float)8496-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{192,320,32,32},{(float)8496-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{224,320,32,32},{(float)8548-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{256,320,32,32},{(float)8548-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{288,320,32,32},{(float)8600-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{320,320,32,32},{(float)8600-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{352,320,32,32},{(float)8652-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{384,320,32,32},{(float)8652-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{416,320,32,32},{(float)8704-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{448,320,32,32},{(float)8704-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{480,320,32,32},{(float)8756-guiScroll,(float)5},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{512,320,32,32},{(float)8756-guiScroll,(float)45},WHITE); 
DrawTextureRec(*textureAtlasLevelPtr,{544,320,32,32},{(float)8808-guiScroll,(float)5},WHITE);
}
void levelSave(int levelData[40][20])
{
     ofstream myfile ("level.txt");
        if (myfile.is_open())
        {
        myfile << "{";
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
        myfile << "}";
        myfile.close();
        }
        else cout << "Unable to open file";
}
