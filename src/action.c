#include <assert.h>

#include "datatypes.h"
#include "action.h"
#include "map.h"
#include "input.h"
#include "key.h"

int action_make_move(map_t *map)
{
    point_t point;
    int loop = 1;
    int multiplier = 0;
    input_key_t key;

    /* calculate the update */
    point.x = map -> cursor.x;
    point.y = map -> cursor.y;

    /* get key and check if it's unlocked */
    key = input_get_key();

    while (loop) {

        if (!key_unlocked(key)) {
            key = input_get_key();
            continue;
        } else {
            loop--;
        }

        switch (key) {
            case 'j':
                point.y += 1;
                break;
            case 'k':
                point.y -= 1;
                break;
            case 'l':
                point.x += 1;
                break;
            case 'h':
                point.x -= 1;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                multiplier = (multiplier) * 10 + key - '0';

                /* loop it multiplier number of times */
                loop = multiplier;
                key = input_get_key();
                break;
            case 'q':
                return 0;
        }

        if (!map_is_free(map, point)) {
            break;
        } else {
            map -> cursor.x = point.x;
            map -> cursor.y = point.y;
        }
    }

    return 1;
}