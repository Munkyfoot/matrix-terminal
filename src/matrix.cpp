#include "matrix.h"
#include <ctime>
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
        this->rows_.push_back(this->GenerateRow());
    }

    for (int i = 0; i < width; i++) {
        this->lengths_.push_back(rand() % (height / 4) + height / 4);
        this->starts_.push_back(rand() % height);
    }
}

string Matrix::GenerateRow() const {
    string row{};
    for (int i = 0; i < this->screen_width_; i++) {
        row += (char)(rand() % 76 + 48);
    }
    return row;
}

void Matrix::AddNoise(float noise) {
    if (noise < 0) {
        noise = 0;
    } else if (noise > 1) {
        noise = 1;
    }

    for (int r = 0; r < this->rows_.size(); r++) {
        int changes = rand() % (int)(this->rows_[r].length() * noise);
        for (int c = 0; c < changes; c++) {
            this->rows_[r][rand() % (int)(this->rows_[r].length())] =
                (char)(rand() % 76 + 48);
        }
    }
}

void Matrix::Tick() {
    for (int i = 0; i < screen_width_; i++) {
        this->starts_[i] = (this->starts_[i] + 1) % screen_height_;
    }
}