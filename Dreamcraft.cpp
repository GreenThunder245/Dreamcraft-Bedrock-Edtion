#include "raylib.h"
#include <cmath>
#include "include/player.h"



void levelDataDraw(Texture2D* textureAtlasLevelPtr, int levelData[40][20]); //function signature
bool levelDataCollision(int levelData[40][20],Player player);
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    //SetConfigFlags(FLAG_MSAA_4X_HINT);

    //Initalize Audio Device
    InitAudioDevice();
    //InitPhysics();
    

    
    InitWindow(screenWidth, screenHeight, "Dreamcraft Bedrock Edition");
    


        int levelData[40][20] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,}};
        Vector2 mousePosition;
        int mouseBlock = 0;
        bool collision = false;
    //initalize Textures
        Texture2D playerTexture = LoadTexture("res/gfx/dream.png");
        Texture2D textureAtlasLevel = LoadTexture("res/gfx/DreamCraftAtlas.png");
        Texture2D* textureAtlasLevelPtr = &textureAtlasLevel;

    //Initalize Sounds
        Sound breakBlock = LoadSound("res/sfx/sounds/random/break.ogg");
    //Initalize Music
    //Music dreamcraft;
    
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

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
        
            //draws the level
        levelDataDraw(textureAtlasLevelPtr,levelData);
    
        
    
    //Modify player
         

        dream.speed.y -= 0.25f; //gravity

          //move left and right
        if (IsKeyDown(KEY_RIGHT)) dream.speed.x -= 0.10f; 
        if (IsKeyDown(KEY_LEFT)) dream.speed.x += 0.10f;
          //friction to slow the player down
        dream.speed.x *= 0.975f;
          //
          dream.x = dream.x - dream.speed.x; 
        
        //what to do if dream is grounded
        if (dream.isGroundedf1 == true)
        {
               dream.speed.y = 0;
               dream.y = (int)dream.y + (-(int)dream.y % 32) + 16;
               dream.isGroundedf1 = false;
               dream.isGrounded = true;
        }
        if (dream.isGrounded == true)
        {
             dream.speed.y = 0;
             if (IsKeyDown(KEY_UP)) {
                  dream.speed.y += 10.0f;
                  dream.isGrounded = false;
             }
             
        }
        
        dream.y = dream.y - dream.speed.y;

        collision = levelDataCollision(levelData,dream);
        if (collision == true)
        {
               dream.isGroundedf1 = true;
               DrawText("COLLISION!", GetScreenWidth()/2 - MeasureText("COLLISION!", 20)/2, 720/2 - 10, 20, BLACK);
               dream.speed.x *= -1;
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
void levelDataDraw (Texture2D* textureAtlasLevelPtr, int levelData[40][20])// this function draws the stage
{
    for (int i = 0; i <40; i++)
            {
                for (int d = 0; d < 20; d++)
                {
switch (levelData[i][d]){
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
bool levelDataCollision(int levelData[40][20],Player player)
{
        bool returnCollision = false;
        bool collision = false;
        Rectangle playerHitbox = {player.x,player.y,32,64};
        for (int i = 0; i <40; i++)
                {
                for (int d = 0; d < 20; d++)
                {
                        switch (levelData[i][d]){
                        case 0:
                                break;
                        default:
                                collision = CheckCollisionRecs(playerHitbox,{(float)i*32,(float)d*32+80,32,32});
                                if (collision == true)
                                {
                                        returnCollision = true;
                                }
                                break;
                        }
                }
        }
        return returnCollision;
}
bool deathPlain(Player player)
{
        if (player.y<0)
        {
                return true;
        }
        else if (player.y>720)
        {
                return true;
        }
        else if (player.x>1280)
        {
                return true;
        }
        else if (player.x<0)
        {
                return true;
        }
        else
        {
                return false;
        }
        return false;
}
