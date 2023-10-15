#include "raylib.h"
int main(){
    // float root_beer = 1.99;
    // double cheese_burger{5.99};
    // bool shouldHaveLunch = true;

    // bool equal{ 4 == 9}; //false
    // bool notEqual{ 4 != 9}; //true
    // bool less{ 4 < 9}; //true
    // bool greater{ 4 > 9}; //false
    // bool lessEqual{ 4 <= 9}; //true
    // bool greaterEqual{ 4 >= 9}; //false
    //DrawCircle(centerX, centerY, radius, color);
    //DrawRectangle(posX, posY, width, height, color)
    //DrawText(text, posX, posY, fontSize, color);
    // window dimensions
    int width = 800;
    int height{450};
    InitWindow(width, height, "Axe Game");

    //circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_r{25};
    // circle edges
    int l_circle_x{circle_x - circle_r};
    int r_circle_x{circle_x + circle_r};
    int u_circle_y{circle_y - circle_r};//upper
    int b_circle_y{circle_y + circle_r};//bottom

    //axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    //axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y}; //upper
    int b_axe_y{axe_y + axe_length};//bottom

    int direction{10};
    
    bool collision_with_axe = (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (l_axe_x <= r_circle_x) && 
                            (r_axe_x >= l_circle_x);

    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(WHITE);
        if(collision_with_axe == true){
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else{
            //Update the edges
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y + circle_r;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            //update collision_with_axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

            axe_y += direction;

            if(axe_y + axe_length > height || axe_y < 0){
                direction = -direction;
            }

            if(IsKeyDown(KEY_A) && l_circle_x > 0){
                circle_x -= 10;
            }
            if(IsKeyDown(KEY_D) && r_circle_x < width){
                circle_x += 10;
            }
            if(IsKeyDown(KEY_W) && u_circle_y > 0){
                circle_y -= 10;
            }
            if(IsKeyDown(KEY_S) && b_circle_y < height){
                circle_y += 10;
            }
        }
        
        EndDrawing();
    }
    
}