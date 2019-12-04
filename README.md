# UCR-CS122A-GB-ROM-Custom-Project
My first attempts at Gameboy ROM(s) for my Intermediate Embedded Systems class at UCR.

Each folder is a VS Code workspace for a ROM which tests some aspect(s) of GameBoy programming. The files with the .gb extensions are the compiled ROMs.

This project uses the GBDK (GameBoy Developer Kit) to write these ROMs, as well as the BGB emulator to test them. Gameboy Tiler Designer is used to create sprites and tiles. The Gameboy map Builder is used to make backgrounds and maps for ROMs. The map builder takes tiles exported from the tile designer to build maps. Both export their data as C code which is included and referenced in main.

GBDK Link: https://sourceforge.net/projects/gbdk/

BGB Emulator Link: http://bgb.bircd.org/

Gameboy Tile Designer Link: http://www.devrs.com/gb/hmgd/gbtd.html

Gameboy Map Builder Link: http://www.devrs.com/gb/hmgd/gbmb.html
