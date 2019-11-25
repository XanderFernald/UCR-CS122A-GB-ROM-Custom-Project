/*

This code is for a sprite and input testing ROM. 
There are 2 sprites, both contained within Face.c and Face.h.
The switch statement provides cases for D pad and A button inputs.

*/

#include <gb/gb.h>
#include <stdio.h>
#include "Face.c"

void main() {
    UINT8 tile = 0;
    set_sprite_data(0, 2, Face);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;

    while(1) {
        switch(joypad()) {
            case J_LEFT:
                scroll_sprite(0, -10, 0);
            break;
            case J_RIGHT:
                scroll_sprite(0, 10, 0);
            break;
            case J_UP:
                scroll_sprite(0, 0, -10);
            break;
            case J_DOWN:
                scroll_sprite(0, 0, 10);
            break;
            case J_A:
            if (tile == 0) {
                tile = 1;
                set_sprite_tile(0, tile);
            } else if (tile == 1) {
                tile = 0;
                set_sprite_tile(0, tile);
            }
            break;
        }
        delay(100);
    }
}