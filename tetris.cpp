#include <stdlib.h>

int ***pieces_def = {
        {{8, 9, 10, 11}, {2, 6, 10,14}},    //I
        {{8, 9, 10, 14}, {5, 9, 12, 13}, {4, 8, 9, 10}, {5, 6, 9, 13}},      //J
        {{8, 9, 10, 12}, {4, 5, 9, 13}, {6, 8, 9, 10}, {5, 9, 13, 14}},      //L
        {{8, 9, 10, 13}, {5, 8, 9, 13}, {5, 8, 9, 10}, {5, 9, 10, 13}},      //T
        {{9, 10, 13, 14}},                    //O
        {{8, 9, 13, 14}, {6, 9, 10, 13}},     //Z
        {{9, 10, 12, 13}, {5, 9, 10, 14}}     //S
}

class Piece {

    private:
        int x, y, type, rotation;
        int **rot_array;

    public:
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
        void rotate() {
            rotation = (rotation+1) % (sizeof(rot_array)/sizeof(rot_array[0]));
        }
        void move_x(int n) {
            if ((n != 1) && (n != -1))
                printf("ERROR: ILLEGAL X AXIS PIECE MOVE\n");
            else
                x += n;
        }
        void move_y(int n) {
            if ((n != 1) && (n != -1))
                printf("ERROR: ILLEGAL Y AXIS PIECE MOVE\n");
            else
                y += n;
        }
}
