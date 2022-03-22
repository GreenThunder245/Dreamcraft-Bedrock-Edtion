#include <switch.h>
#include "raylib.h"
#include "player.h"
#include <cmath>


void levelDataDraw(Texture2D* textureAtlasLevelPtr, int levelData[40][20],int levelLength,int levelHeight); //function signature
void levelDataCollisionSides(bool* array,int levelData[40][20],Player player);
bool deathPlain(Player player);
Player playerMove(int levelData[40][20],Player dream,Sound* jumpSound);
Player blockEdit(Vector2 mousePosition, int mouseArray[2],int levelData[40][20],Player dream,Sound* placeBlockSound,Sound* placeBlock2Sound,Sound* breakBlockSound,Sound* breakBlock2Sound);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    //Initalize Audio Device
    InitAudioDevice();
    

    
    InitWindow(screenWidth, screenHeight, "Dreamcraft Bedrock Edition");
    


        int levelData[40][20] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,3,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,4,4,}};
        Vector2 mousePosition;
        bool collision[4] = {false,false,false,false};
        int levelCount = 1;
        bool isMusicPlayed = false;
    //initalize Textures
        Texture2D playerTexture = LoadTexture("res/gfx/dream.png");
        Texture2D backgroundTexture = LoadTexture("res/gfx/skyfinal.png");
        Texture2D textureAtlasLevel = LoadTexture("res/gfx/DreamCraftAtlas.png");
        Texture2D* textureAtlasLevelPtr = &textureAtlasLevel;

    //Initalize Sounds
        Sound breakBlockSound = LoadSound("res/sfx/axechop.wav");
        Sound breakBlock2Sound = LoadSound("res/sfx/pickaxe.wav");
        Sound placeBlockSound = LoadSound("res/sfx/putitem.wav");
        Sound placeBlock2Sound = LoadSound("res/sfx/place.wav");
        Sound jumpSound = LoadSound("res/sfx/jump.wav");
        Sound* jumpSoundPtr = &jumpSound;
        Sound* breakBlockSoundPtr = &breakBlockSound;
        Sound* breakBlock2SoundPtr = &breakBlock2Sound;
        Sound* placeBlockSoundPtr = &placeBlockSound;
        Sound* placeBlock2SoundPtr = &placeBlock2Sound;
    //Initalize Music
    Music music = LoadMusicStream("res/sfx/DivideByFourAddSeven.mp3");
    
    
     //init level size
     int levelLength = sizeof levelData / sizeof levelData[0];
     int levelHeight = sizeof levelData[0] / sizeof levelData[0][0];
     //mouse mouse position
     int mouseArray[2] = {0,0};
    //Init Player
    Player dream = {100,100};
    

     
   
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
     //PlayMusicStream(music);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        mousePosition = GetMousePosition();
          UpdateMusicStream(music);
          if (isMusicPlayed == false) 
          {
          PlayMusicStream(music); 
          isMusicPlayed = true;
          }
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
          ClearBackground(RAYWHITE);
     
            //draws the level
     DrawTexture(backgroundTexture,0,0,WHITE); 
     levelDataDraw(textureAtlasLevelPtr,levelData,levelLength,levelHeight);       
    dream = playerMove(levelData,dream,jumpSoundPtr);
    //Draw Player
    DrawTexture(playerTexture,dream.x,dream.y,WHITE);
    
    //Break Blocks
     dream = blockEdit(mousePosition,mouseArray,levelData,dream,placeBlockSoundPtr,placeBlock2SoundPtr,breakBlockSoundPtr,breakBlock2SoundPtr);
    EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}
void levelDataDraw (Texture2D* textureAtlasLevelPtr, int levelData[40][20],int levelLength,int levelHeight)// this function draws the stage using the level data int[][] as a parameter
{
     //this nested for loop uses the size of the level to draw each block
     
    for (int x = 0; x < levelLength; x++) 
          {
                for (int y = 0; y < levelHeight; y++)
                {
                    DrawTextureRec(*textureAtlasLevelPtr,{(float)((levelData[x][y]-1) % 32)*32,(float)(levelData[x][y]/32)*32,(float)32*(levelData[x][y] > 0),(float)32*(levelData[x][y] > 0)},{(float)x*32,(float)y*32+80},WHITE); //Branchless Edition
                }
          } 
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
void levelDataCollisionSides(bool* array,int levelData[40][20],Player player)
{
          //create and draw hitboxes
        Rectangle playerHitboxFloor = {player.x+4,player.y+63,24,1-(player.speed.y)};
        Rectangle playerHitboxTopSide = {player.x+4,player.y-1,24,1};
        Rectangle playerHitboxLeftSide = {player.x-(player.speed.x)+1,player.y+2,1+(player.speed.x),60};
        Rectangle playerHitboxRightSide = {player.x+31,player.y+2,1-(player.speed.x),60};
        //set to false as default
        array[0] = false;
        array[1] = false;
        array[2] = false;
        array[3] = false;
        //set to true if collision by checking collision between the hitboxes and every block
        for (int i = 0; i <40; i++)
                {
                for (int d = 0; d < 20; d++)
                {
                        switch (levelData[i][d]){
                        case 0:
                                break;
                        default:
                                if (CheckCollisionRecs(playerHitboxFloor,{(float)i*32,(float)d*32+80,32,32}) == true) array[0] = true;                          
                                if (CheckCollisionRecs(playerHitboxTopSide,{(float)i*32,(float)d*32+80,32,32}) == true) array[1] = true;
                                if (CheckCollisionRecs(playerHitboxLeftSide,{(float)i*32,(float)d*32+80,32,32}) == true) array[2] = true;
                                if (CheckCollisionRecs(playerHitboxRightSide,{(float)i*32,(float)d*32+80,32,32}) == true) array[3] = true;
                                break;
                        }
                }
        }
}
Player playerMove(int levelData[40][20],Player dream,Sound* jumpSound)
{
     //Modify player
         
     bool collision[4];
        dream.speed.y -= dream.gravity; //gravity

          //move left and right
        if (IsKeyDown(KEY_RIGHT)) dream.speed.x -= 0.12f; 
        if (IsKeyDown(KEY_LEFT)) dream.speed.x += 0.12f;
          //friction to slow the player down
        dream.speed.x *= 0.975f;
        /*
        if(dream.speed.x < 0) dream.speed.x += 0.02f;
        if(dream.speed.x > 0) dream.speed.x -= 0.02f;
        */
          //moves the player based on their speed

          
     
     levelDataCollisionSides(collision,levelData,dream);
     if (collision[0] == true)
     {
          if(dream.isGrounded == false) dream.isGroundedf1 = true;
     }
     if (collision[1] == true)
     {
          dream.speed.y *= -1;
     }
     if (collision[2] == true)
     {
          dream.speed.x = 0;
          dream.x = 32*round(dream.x/32);
          //dream.x = dream.x+dream.speed.x;
     }
     if (collision[3] == true)
     {
          dream.speed.x = 0;
          dream.x = 32*round(dream.x/32);
          //dream.x = dream.x-dream.speed.x;
     }
        
     if (dream.isGroundedf1 == true)
     {
               dream.speed.y = 0;
               //dream.y = (32*round(dream.y/32))+16;
               dream.y = dream.y - dream.speed.y;
               dream.isGroundedf1 = false;
               dream.isGrounded = true;
     }
        //keeps the player off the ground
     if (dream.isGrounded == true)
     {
             dream.speed.y = 0;
             dream.isGrounded = collision[0]; //checks if the player is still on the floor
             if (IsKeyDown(KEY_UP)) 
             {
                  dream.speed.y += 5.0f;
                  dream.isGrounded = false;
                  PlaySound(*jumpSound);
             }
     }

     dream.x = dream.x - dream.speed.x;   
     dream.y = dream.y - dream.speed.y;
     
     return dream;
}
Player blockEdit(Vector2 mousePosition, int mouseArray[2],int levelData[40][20],Player dream,Sound* placeBlockSound,Sound* placeBlock2Sound,Sound* breakBlockSound,Sound* breakBlock2Sound)
{
          if (mousePosition.y > 80)
     {
          mouseArray[0] = floor((mousePosition.x)/32);
          mouseArray[1] = floor((mousePosition.y-80)/32); //dont remove the -80
          if (IsMouseButtonPressed(0)){
          switch (levelData[mouseArray[0]][mouseArray[1]])
          {
          case 0:
                    switch (dream.mouseBlock)
                    {
                         case 0:
                              break;         
                         default:
                              if ((CheckCollisionRecs({(float)dream.x,(float)dream.y,32,64},{(float)mouseArray[0]*32,(float)mouseArray[1]*32+80,32,32}) == false)) //Checks if block if being placed on the player
                              {
                                   if(levelData[mouseArray[0]-1][mouseArray[1]] != 0 || levelData[mouseArray[0]+1][mouseArray[1]] != 0 || levelData[mouseArray[0]][mouseArray[1]-1] != 0 || levelData[mouseArray[0]][mouseArray[1]+1] != 0) //Checks if there is an adjcent block to the one being placed
                                   {
                                        dream.inventory[0] = levelData[mouseArray[0]][mouseArray[1]];
                                        levelData[mouseArray[0]][mouseArray[1]] = dream.mouseBlock;
                                        dream.mouseBlock = dream.inventory[0];
                                        if (rand() % 2 == 1)
                                        {
                                             PlaySound(*placeBlockSound);
                                        }
                                        else
                                        {
                                             PlaySound(*placeBlock2Sound);
                                        }                            
                                   }   
                              }
                              break;
                    }
               break;
          case 215:
               break;
          default:
                    switch (dream.mouseBlock)
                    {
                    case 0:
                              
                              dream.inventory[0] = levelData[mouseArray[0]][mouseArray[1]];
                              levelData[mouseArray[0]][mouseArray[1]] = dream.mouseBlock;
                              dream.mouseBlock = dream.inventory[0];
                              if (rand() % 2 == 1)
                              {
                                   PlaySound(*breakBlockSound);
                              }
                              else
                              {
                                   PlaySound(*breakBlock2Sound);
                              } 
                              break;
                    default:
                              break;
                    }       
               }
          }
     }
     return dream;
}
