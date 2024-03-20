// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

//Including needed header files and libraries
#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "colours.h"
#include "map.h"

//Defining needed variables
#define WALL 'W'
#define DOT '.'
#define PACMAN 'P'
#define GHOST 'G'
#define EMPTY_SPACE ' '


extern char *map, *dot_map;
extern int width, height;

int move_actor(int * y, int * x, char direction, int eat_dots) {
    return MOVED_OKAY;
}

int is_wall(int y, int x) {
    return NOT_WALL;
}

char * load_map(char * filename, int *map_height, int *map_width) {
    //opening the map file and reading the map
    FILE* file = fopen(filename, "r");

    //Returning error if NULL
    if (file == NULL) {
        printf("Error opening map file\n", filename);
        fclose(file); //closing and freeing file pointer
        return 0; //end code
    }

    //defining my height and width to work easier with
    height = *map_height;
    width = *map_width;

    //Allocating memory for the map using a char pointer and malloc
    char* map = (char*)malloc(81 * sizeof(char));
    if (map == NULL) {
        printf("Failed to allocate memory of the map\n");
        fclose(file); //closing and freeing file pointer
        return 0; //end code;
    }


    //Reading in the map characters and sticking them into a 1D array (cmon man, why not 2D for our sake?)
    int index = 0; //counter for the map index, set at 0
    char ch; // character placeholder

    while ((ch = fgetc(file)) != EOF) { //looping through until out of bounds, acquiring each character, EOF = -1
        if (ch != '\n' && ch != ' ') {
            map[index++] = ch; //placing all characters that are not new lines into 1D array - WHY 1D!?!?!
        }
    }


    fclose(file); //closing and freeing the file
    return map;
}

//ADDITIONAL FUNCTION

void print_map(char *map, int map_height, int map_width) {
    int x = 0;

    //Printing walls on first row
        printf("W W  W  W  W  W  W  W  W  W  W\n");


    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {

            //Printing left wall
            if (j == 0) {
                printf("W  ");
            }

            printf("%c  ", map[x]);
            x++;

            //Printing right wall
            if (j == (map_width-1)) {
                printf("W  ");
            }
        }
        printf("\n");
    }

    //Printing walls on last row
    printf("W  W  W  W  W  W  W  W  W  W  W\n");
}

