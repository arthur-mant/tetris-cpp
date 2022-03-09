#include "piece.h"


int ***pieces_def = {
   {{8, 9, 10, 11}, {2, 6, 10,14}},    //I
   {{8, 9, 10, 14}, {5, 9, 12, 13}, {4, 8, 9, 10}, {5, 6, 9, 13}},      //J
   {{8, 9, 10, 12}, {4, 5, 9, 13}, {6, 8, 9, 10}, {5, 9, 13, 14}},      //L
   {{8, 9, 10, 13}, {5, 8, 9, 13}, {5, 8, 9, 10}, {5, 9, 10, 13}},      //T
   {{9, 10, 13, 14}},                    //O
   {{8, 9, 13, 14}, {6, 9, 10, 13}},     //Z
   {{9, 10, 12, 13}, {5, 9, 10, 14}}     //S
}


Piece(int orig_x, int orig_y) {
    x = orig_x;
    y = orig_y;
    type = rand() % 7;
    rotation = 0;
    rot_array = pieces_def[type];
}
int *image() {
    return rot_array[rotation];
}
void rotate(direction) {
    rotation = (rotation+direction) % (sizeof(rot_array)/sizeof(rot_array[0]));
}
int move_x(int n) {
    if ((n != 1) && (n != -1))
        printf("ERROR: ILLEGAL X AXIS PIECE MOVE\n");
        return NULL;
    x += n;
    return x;
}
int move_down(int n) {
    y += n;
    return y;
}

std::tuple<int, int, int> get_coordinates() {
    return std::make_tuple(x, y, rotation);
}

int get_x() {
    return x;
}
int get_y() {
