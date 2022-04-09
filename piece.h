#include "defs.h"

#ifndef _PIECE
#define _PIECE

class Piece {

    private:
        int x, y, type, rotation;
        int rot_num;
        std::array<std::array<int, 4>, 4> rot_array;

    public:
        Piece();
        Piece(int orig_x, int orig_y);
        std::array<int, 4> image();
        void rotate(int i);
        int move_x(int n);
        int move_down(int n);
        int get_x();
        int get_y();
        int get_rotation();
        std::array<std::array<int, 4>, 4> Piece::get_rot_array();
        int get_type();
        int get_num_rot();
};

#endif
