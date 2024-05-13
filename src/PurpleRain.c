#include <stdio.h>
#include "raylib.h"

#define noDrops 500
#define rainWidth 4 
#define rainHeight 10

const int screenWidth = 800;
const int screenHeight = 450;

const float zFar = 10;

struct Rain
{
    Vector3 pos;
    float speed;
    int width;
    int height;
};

void getRandomVec(struct Vector3* pos)
{
    pos->x = GetRandomValue(0,screenWidth);
    pos->y = GetRandomValue(0,100);
    pos->z = GetRandomValue(1,zFar);
}

int main(void)
{

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               
    
    struct Rain drops[noDrops]; 
    
    for(int i = 0 ; i < noDrops ; i++)
    {
        getRandomVec(&drops[i].pos);
        drops[i].speed = GetRandomValue(1,10);
        drops[i].width = rainWidth;
        drops[i].height = rainHeight;
    }


    while (!WindowShouldClose())    
    {
        for(int i = 0 ; i < noDrops ; i++)
        {
            drops[i].pos.y += drops[i].speed; 
            drops[i].speed += 0.1;

            if(drops[i].pos.y >= screenHeight)
            {
                getRandomVec(&drops[i].pos);
                drops[i].speed = GetRandomValue(1,10);
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        for(int i = 0 ; i < noDrops ; i++)
        {
            float x = drops[i].pos.x ;
            float y = drops[i].pos.y ;

            DrawRectangle(x,y,drops[i].width,drops[i].height,PURPLE);
        }


        EndDrawing();

    }

    CloseWindow();        


    return 0;
}

