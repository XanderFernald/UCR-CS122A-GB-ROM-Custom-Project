/*

This code is for a ROM which demonstrates simple background usage.
It has a set of tiles and a put together background, which it will scroll through.

*/

#include <gb/gb.h>
#include <gb/font.h>
#include <stdio.h>
#include "Background1.c"
#include "BackgroundTiles.c"
#include "windowmap.c"

void main() {
    font_t min_font;

    font_init();
    min_font = font_load(font_min); // 36 tiles
    font_set(min_font);

    set_bkg_data(37, 6, BackgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, Background1);

    set_win_tiles(0, 0, 11, 1, windowmap);
    move_win(7, 130);

    SHOW_BKG;
    SHOW_WIN;
    DISPLAY_ON;

    while(1) {
        scroll_bkg(1, 0);
        delay(100);
    }
}