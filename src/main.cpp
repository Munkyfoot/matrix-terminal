#include "matrix.h"
#include <chrono>
#include <cstring>
#include <curses.h>
#include <future>
#include <memory>
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

    std::unique_ptr<Matrix> matrix =
        std::make_unique<Matrix>(getmaxx(stdscr) - 1, getmaxy(stdscr));

    while (1) {
        auto noise_ftr = std::async([&matrix]{ matrix->AddNoise(0.1); });
        matrix->Tick();
        init_pair(1, COLOR_GREEN, -1);
        attron(COLOR_PAIR(1));
        vector<Drop> drops{};
        for (int y = 0; y < matrix->Height(); y++) {
            string this_row = matrix->RowCopy(y);
            for (int x = 0; x < this_row.length(); x++) {
                if (y < matrix->Starts()[x] ||
                    y > matrix->Starts()[x] + matrix->Lengths()[x]) {
                    if (y > matrix->Starts()[x] + matrix->Lengths()[x] -
                                matrix->Height()) {
                        this_row[x] = ' ';
                    }
                }
                if (y == (matrix->Starts()[x] + matrix->Lengths()[x]) %
                             matrix->Height()) {
                    Drop drop{x, y, this_row[x]};
                    drops.push_back(drop);
                }
            }
            mvprintw(y, 0, this_row.c_str());
        }
        attroff(COLOR_PAIR(1));
        for (int d = 0; d < drops.size(); d++) {
            char c[]{drops[d].c};
            mvprintw(drops[d].y, drops[d].x, c);
        }
        noise_ftr.wait();
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(84));
    }
    endwin();

    return 0;
}