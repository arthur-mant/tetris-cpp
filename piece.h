#ifndef _PIECE
#define _PIECE

class Piece {

    private:
        int x, y, type, rotation;
        int **rot_array;

    public:
        Piece(int orig_x, int orig_y);
        int *image();
        void rotate(direction);
        int move_x(int n);
        int move_down(int n);
        int get_x();
        int get_y();
        int get_rotation();
};

#endif
