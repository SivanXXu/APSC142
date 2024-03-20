// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

// don't forget to update your project configuration to select "Emulate terminal in the output console"

// Make sure to include all relevant libraries
#include <stdio.h>
#include <stdlib.h>

// colours.h contains functions to change text colour and read single characters without requiring an enter
#include "colours.h"
// defines.h contains useful definitions to keep your code readable
#include "defines.h"
// map.h, game.h, and ghost.h contain prototypes of functions you must implement
#include "map.h"
#include "game.h"
#include "ghost.h"

// These global variables must be used to store map information.
// Almost every function needs these variables, so keeping them as globals helps keep things organized.
// map is a pointer to a dynamically allocated map for displaying to the user
// dot_map is a pointer to a dynamically allocated map for keeping track of what dots are left
char *map = NULL, *dot_map = NULL;
// width and height store the width and height of map, NOT counting outer walls
int width = 9, height = 9;




/**
 * Main entry point into your program.
 * Make sure that main returns appropriate status codes depending on what
 * happens.  The codes you must use are:
 *   NO_ERROR when no error occurs
 *   ERR_NO_MAP when no map file is found
 *   ERR_NO_PACMAN when no pacman is found on the map
 *   ERR_NO_GHOSTS when fewer than 2 ghosts are found on the map
 *
 * Make sure that any allocated memory is freed before returning.
 * @return a status code
 */
int main(void) {
    setbuf(stdout, NULL);

    //Defining pointers for height and width
    int *map_height = (int*)malloc(sizeof(int));
    int *map_width = (int*)malloc(sizeof(int));
    if (map_height == NULL || map_width == NULL) {
        printf("Memory allocation failed\n");
        return 0;
    }
    //Hardcoding width and height to be 9
    *map_height = 9;
    *map_width = 9;

    //loading *map
    map = load_map("map.txt", map_height, map_width);




    //Calling print map function
    print_map(map, *map_height, *map_width);

    // Don't forget to free the allocated memory when done using the map
    free(map);



    return NO_ERROR;
}
