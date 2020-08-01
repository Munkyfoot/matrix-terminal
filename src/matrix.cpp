#include "matrix.h"
#include <string>
#include <vector>
#include <random>

using std::string;
using std::vector;
using std::rand;

void Matrix::GenerateRow() {
    string row{};
    for (int i = 0; i < this->screen_width_; i++) {
        if(rand() % 10 < 8){
            row += " ";
        }
        else{
        row += (char)(rand() % 127);
        }
    }
    rows_.push_back(row);
    if (rows_.size() > this->screen_height_) {
        rows_.erase(rows_.begin());
    }
}