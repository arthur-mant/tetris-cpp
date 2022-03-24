#include "defs.h"
#include "game_run.h"

int main() {

    GameRun game_run(true, true, true, 60);

    while(game_run.run_frame());

}
