#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_net.h>
#include <SDL2/SDL_ttf.h>

const int GAME_WIDTH = 800, GAME_HEIGHT = 600;
const float G = 0.3;
const int LEFT_MOVE = -4, RIGHT_MOVE = 4;
int player1_jump_V = -12, player2_jump_V = -12;
int player1_pos_X = 200, player1_pos_Y = 600, player2_pos_X = 600, player2_pos_Y = 600;
bool player1_isJumping = false, player2_isJumping = false;
int player1_jumptime = 0, player2_jumptime;

void player1_position()
{
    if(keystate[SDL_SCANCODE_UP] && player1_pos_Y == 600)
    {
        player1_isJumping = true;
    }
    if(keystate[SDL_SCANCODE_RIGHT] && player1_pos_x < 400)
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
        player1_jump_V -= G * player1_jumptime;
        player1_jumptime += 1;
        
        if(jumptime == 80)
        {
            player1_pos_Y = 600;
            player1_jump_V = -12;
            player1_jumptime = 0;
        }
    }
}

void player2_position()
{
    if(keystate[SDL_SCANCODE_UP] && player2_pos_Y == 600)
    {
        player2_isJumping = true;
    }
    if(keystate[SDL_SCANCODE_RIGHT])
    {
        player2_pos_X += RIGHT_MOVE;
    }
    if(keystate[SDL_SCANCODE_LEFT] && player2_pos_x > 400)
    {
        player2_pos_X += LEFT_MOVE;
    }
    
    if(player2_isJumping)
    {
        player2_pos_Y += player2_jump_V;
        player2_jump_V -= G * player2_jumptime;
        player2_jumptime += 1;
        
        if(jumptime == 80)
        {
            player2_pos_Y = 600;
            player2_jump_V = -12;
            player2_jumptime = 0;
        }
    }
}

int main()
{
	while(true)
	{
		player1_position();
		player2_position();
		
		cout << "(" << player1_pos_X << "," << player1_pos_Y << ")" << "\n";
		cout << "(" << player2_pos_X << "," << player2_pos_Y << ")" << "\n";
		
		
		if(keystate[SDL_SCANCODE_BACKSPACE])
			break;
	}
	
	cout << "END";
	
	return 0;
}
