/*

This code is for a ROM which demonstrates sprite collision and background collision.
It also functions as a basic game, where the player navigates a maze to try and collect
3 stars. You win when you collect all 3.

*/

#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "Maze.c"
#include "PlayerCharacter.c"
#include "MazeTiles.c"
#include "windowmap.c"

UINT8 playerlocation[2];
UINT8 score = 0;

void _delay(UINT8 numloops) {
    UINT8 i;
    for(i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}

UBYTE checkcollision(UINT8 newX, UINT8 newY) {
    UINT16 indexTopLeftX, indexTopLeftY, tileindexTopLeft;
    UBYTE Result;

    indexTopLeftX = (newX - 8) / 8;
    indexTopLeftY = (newY - 16) / 8;
    tileindexTopLeft = 20 * indexTopLeftY + indexTopLeftX;

    Result = Maze[tileindexTopLeft];
    
    if (Result == 0x02) {
        Maze[tileindexTopLeft] = 0x00;
        set_bkg_tiles(0, 0, 20, 18, Maze);
        score += 1;
    }

    return Result;
}

void main() {

    DISPLAY_ON;

    while(1) {
        score = 0;

        set_bkg_data(0, 3, MazeTiles);
        set_bkg_tiles(0, 0, 20, 18, Maze);

        set_sprite_data(0, 3, PlayerCharacter);
        set_sprite_tile(0, 2);

        playerlocation[0] = 152;
        playerlocation[1] = 144;

        move_sprite(0, playerlocation[0], playerlocation[1]);

        SHOW_SPRITES;
        SHOW_BKG;
    
        while(score < 3) {
            if(joypad() & J_LEFT) {
                set_sprite_tile(0, 2);
                if(checkcollision(playerlocation[0] - 8, playerlocation[1]) == 0x00) {
                    playerlocation[0] -= 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else if (checkcollision(playerlocation[0] - 8, playerlocation[1]) == 0x01) {
                    // can't move
                } 
                
                else if (checkcollision(playerlocation[0] - 8, playerlocation[1]) == 0x02) {
                    playerlocation[0] -= 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else {}
            } 
            
            else if(joypad() & J_RIGHT) {
                set_sprite_tile(0, 1);
                if(checkcollision(playerlocation[0] + 8, playerlocation[1]) == 0x00) {
                    playerlocation[0] += 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else if (checkcollision(playerlocation[0] + 8, playerlocation[1]) == 0x01) {
                    // can't move
                } 
                
                else if (checkcollision(playerlocation[0] + 8, playerlocation[1]) == 0x02) {
                    playerlocation[0] += 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else {}
            } 
            
            else if(joypad() & J_UP) {
                if(checkcollision(playerlocation[0], playerlocation[1] - 8) == 0x00) {
                    playerlocation[1] -= 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else if (checkcollision(playerlocation[0], playerlocation[1] - 8) == 0x01) {
                    // can't move
                } 
                
                else if (checkcollision(playerlocation[0], playerlocation[1] - 8) == 0x02) {
                    playerlocation[1] -= 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else {}
            } 
            
            else if(joypad() & J_DOWN) {
                if(checkcollision(playerlocation[0], playerlocation[1] + 8) == 0x00) {
                    playerlocation[1] += 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else if (checkcollision(playerlocation[0], playerlocation[1] + 8) == 0x01) {
                    // can't move
                } 
                
                else if (checkcollision(playerlocation[0], playerlocation[1] + 8) == 0x02) {
                    playerlocation[1] += 8;
                    move_sprite(0, playerlocation[0], playerlocation[1]);
                } 
                
                else {}
            }
            _delay(6);
        }

        printf(" You Win! Press A to restart");

        while (!(joypad() & J_A)) {}

        Maze[63] = 0x02;
        Maze[183] = 0x02;
        Maze[216] = 0x02;

    }
}