#include <gb/gb.h>
#include <stdio.h>
#include "Hero1.h"

void main() {
    set_sprite_data(0, 2, Hero1Left);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);
    SHOW_SPRITES;
}