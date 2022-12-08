#include <iostream>
#include <cstdlib>

const int GAME_WIDTH = 800, GAME_HEIGHT = 600;
const float G = 0.3;
const int LEFT_MOVE = -4, RIGHT_MOVE = 4;
int player1_jump_V = -12;
int player1_pos_X = 200, player1_pos_Y = 600;
bool player1_isJumping = false;
int jumptime = 0;

int main()
{
    if(keystate[SDL_SCANCODE_UP])
    {
        player1_isJumping = true;
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
        player1_pos_X += RIGHT_MOVE;
    }
    if(keystate[SDL_SCANCODE_LEFT])
    {
        player1_pos_X += LEFT_MOVE;
    }
    
    if(player1_isJumping)
    {
        player1_pos_Y += player1_jump_V;
        player1_jump_V -= G * jumptime;
        jumptime += 1;
        
        if(jumptime == 80)
        {
            player1_pos_Y = 600;
            player1_jump_V = -12;
            jumptime = 0;
        }
    }
    
    return 0;
}
