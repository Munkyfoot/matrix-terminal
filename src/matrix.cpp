#include "matrix.h"
#include <random>
#include <string>
#include <vector>

using std::rand;
using std::string;
using std::vector;

Matrix::Matrix(int width, int height) {
    this->screen_width_ = width;
    this->screen_height_ = height;

    for (int i = 0; i < height; i++) {
        this->rows_.push_back("");
    }
}

string Matrix::GenerateRow() const {
    string row{};
    for (int i = 0; i < this->screen_width_; i++) {
        if (rand() % 10 < 8) {
            row += " ";
        } else {
            row += (char)(rand() % 76 + 48);
        }
    }
    return row;
}

void Matrix::Display(string row) {
    for (int i = this->rows_.size() - 1; i >= 0; i--) {
        if (i == 0) {
            this->rows_[i] = row;
        } else {
            this->rows_[i] = this->rows_[i - 1];
        }
    }
}