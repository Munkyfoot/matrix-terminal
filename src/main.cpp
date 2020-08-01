#include "matrix.h"
#include <chrono>
#include <cstring>
#include <curses.h>
#include <string>
#include <thread>
#include <vector>

using std::string;

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    use_default_colors();
    start_color();

    Matrix matrix(getmaxx(stdscr) - 1, getmaxy(stdscr) - 1);

    while (1) {
        matrix.AddNoise(0.1);
        init_pair(1, COLOR_GREEN, -1);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < matrix.Rows().size(); y++) {
            string this_row = matrix.Rows()[y];
            mvprintw(y, 0, this_row.c_str());
        }
        attroff(COLOR_PAIR(1));
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(65));
    }
    endwin();

    return 0;
}