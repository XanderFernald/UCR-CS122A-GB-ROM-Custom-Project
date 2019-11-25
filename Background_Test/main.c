/*

This code is for a ROM which demonstrates simple background usage.
It has a set of tiles and a put together background, which it will scroll through.

*/

#include <gb/gb.h>
#include <stdio.h>
#include "BackgroundTiles.c"
#include "Background1.c"

void main() {
    set_bkg_data(0, 6, BackgroundTiles);
    set_bkg_tiles(0, 0, 40, 18, Background1);

    SHOW_BKG;
    DISPLAY_ON;

    while(1) {
        scroll_bkg(1, 0);
        delay(100);
    }
}