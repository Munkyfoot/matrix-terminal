#include "matrix.h"
#include <chrono>
#include <cstring>
#include <curses.h>
#include <string>
#include <thread>
#include <time.h>
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
        matrix.Display(matrix.GenerateRow());

        init_pair(1, COLOR_GREEN, -1);
        attron(COLOR_PAIR(1));
        for (int y = 0; y < matrix.Rows().size(); y++) {
            string this_row = matrix.Rows()[y];
            for (int x = 0; x < this_row.size(); x++) {
                bool end = y == matrix.Rows().size() - 1;
                if (!end) {
                    end = matrix.Rows()[y + 1][x] == ' ';
                }

                if (end) {
                    attroff(COLOR_PAIR(1));
                }
                char c[]{matrix.Rows()[y][x]};
                mvprintw(y, x, c);
                if (end) {
                    attron(COLOR_PAIR(1));
                }
            }
        }
        attroff(COLOR_PAIR(1));
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    endwin();

    return 0;
}