#include "piece.h"

std::array<std::array<std::array<int, 4>, 4>, 7> pieces_def = {{
   {{{8, 9, 10, 11}, {2, 6, 10,14}}},    //I
   {{{8, 9, 10, 14}, {5, 9, 12, 13}, {4, 8, 9, 10}, {5, 6, 9, 13}}},      //J
   {{{8, 9, 10, 12}, {4, 5, 9, 13}, {6, 8, 9, 10}, {5, 9, 13, 14}}},      //L
   {{{8, 9, 10, 13}, {5, 8, 9, 13}, {5, 8, 9, 10}, {5, 9, 10, 13}}},      //T
   {{{9, 10, 13, 14}}},                    //O
   {{{8, 9, 13, 14}, {6, 9, 10, 13}}},     //Z
   {{{9, 10, 12, 13}, {5, 9, 10, 14}}}     //S
}};
const int num_rot[7] = {2, 4, 4, 4, 1, 2, 2};


Piece::Piece(int orig_x, int orig_y) {
    x = orig_x;
    y = orig_y;
    type = rand() % 7;
    rotation = 0;
    rot_array = pieces_def[type];
    rot_num = num_rot[type];
}
std::array<int, 4> Piece::image() {
    return rot_array[rotation];
}
void Piece::rotate(int i) {
    rotation = (rotation+i) % (rot_num);
}
int Piece::move_x(int n) {
    if ((n != 1) && (n != -1))
        printf("ERROR: ILLEGAL X AXIS PIECE MOVE\n");
        return -1;
    x += n;
    return x;
}
int Piece::move_down(int n) {
    y += n;
    return y;
}

int Piece::get_x() {
    return x;
}

int Piece::get_y() {
    return y;
}
int Piece::get_rotation() {
    return rotation;
}
int Piece::get_type() {
    return type;
}
