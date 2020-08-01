#include "matrix.h"
#include <chrono>
#include <curses.h>
#include <string>
#include <thread>
#include <time.h>

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    use_default_colors();
    start_color();

    Matrix matrix(getmaxx(stdscr) - 1, getmaxy(stdscr) - 1);

    while (1) {
        matrix.Display(matrix.GenerateRow());

        init_pair(1, COLOR_GREEN, -1);
        attron(COLOR_PAIR(1));
        for (int i = 0; i < matrix.Rows().size(); i++) {
            if (i == matrix.Rows().size() - 1) {
                attroff(COLOR_PAIR(1));
            }
            mvprintw(i, 0, matrix.Rows()[i].c_str());
        }
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
    endwin();

    return 0;
}