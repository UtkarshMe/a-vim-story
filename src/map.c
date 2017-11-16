#include <unistd.h>             /* for NULL */
#include <stdlib.h>             /* for malloc() */
#include <assert.h>             /* for assert() */

#include "datatypes.h"
#include "map.h"


int convert_point_to_linear(map_t *, point_t);


boolean map_init()
{
    return B_TRUE;
}

map_t * map_load()
{
    /* TODO: remove the hardcoded map */

    map_t *map = NULL;
    char buffer[18][63] = {
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++",
        "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
        "+~~~~~~~~~~~~~~~#############################################~+",
        "+~~~~~~~~~~~~~~~#              #   #            #           #~+",
        "+~~~~~~~~~~~~~~~# ############ # # # ######## # # ######### #~+",
        "+~~~~~~~~~~~~~~~# #@           #@# # #   # @# # #   #@# #   #~+",
        "+~~~~~~~~~~~~~~~# ################ # # #   ## # # # #   # # #~+",
        "+~ k    #   #                      # # ###### # # # ## ## # #~+",
        "+~h l   # # # ~~##################   #        # # #       # #~+",
        "+~ j      #   ~~#                  ############ # ######### #~+",
        "+~~~~~~~~~~~~~~~# ############# ###   #   #     #           #~+",
        "+~~~~~~~~~~~~~~~# #           #   #@# # #   ########## ######~+",
        "+~~~~~~~~~~~~~~~# #@######### ### ### #  # #       #         ~+",
        "+~~~~~~~~~~~~~~~# ########### #   #    # # ##### # # ########~+",
        "+~~~~~~~~~~~~~~~#             # ### ## # # #   # # #    #   #~+",
        "+~~~~~~~~~~~~~~~###############      #   #   #   #   ##   # %~+",
        "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+",
        "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
    };

    map = (map_t *) malloc(sizeof(map_t));

    map -> size.x = 63;
    map -> size.y = 18;

    map -> data = (map_tile_t *) malloc(sizeof(map_tile_t) 
            * map -> size.x
            * map -> size.y);

    int count = 0;
    for (int i = 0; i < map -> size.y; ++i) {
        for (int j = 0; j < map -> size.x; ++j) {
            map -> data[count].value = ' ';
            switch (buffer[i][j]) {
                case '~':
                    map -> data[count].type = TILE_WATER;
                    break;
                case '+':
                    map -> data[count].type = TILE_BORDER;
                    break;
                case ' ':
                    map -> data[count].type = TILE_GRASS;
                    break;
                case '#':
                    map -> data[count].type = TILE_BRICK;
                    break;
                case '%':
                    map -> data[count].type = TILE_DOOR;
                    break;
                case '@':
                    map -> data[count].type = TILE_GEM;
                    break;
                default:
                    map -> data[count].type = TILE_LETTER;
                    map -> data[count].value = buffer[i][j];
            }
            count++;
        }
    }

    map -> cursor.y = 8;
    map -> cursor.x = 3;

    return map;
}

boolean map_is_free(map_t *map, point_t point)
{
    int pos = convert_point_to_linear(map, point);

    if (map -> data[pos].type == TILE_GRASS
            || map -> data[pos].type == TILE_DOOR
            || map -> data[pos].type == TILE_GEM
            || map -> data[pos].type == TILE_LETTER) {
        return B_TRUE;
    }
    return B_FALSE;
}

map_tile_t map_get_tile(map_t *map, point_t point)
{
    return map -> data[convert_point_to_linear(map, point)];
}

void map_set_tile(map_t *map, point_t point, map_tile_t tile)
{
    map -> data[convert_point_to_linear(map, point)] = tile;
}

int convert_point_to_linear(map_t *map, point_t point)
{
    return map -> size.x * point.y + point.x;
}
