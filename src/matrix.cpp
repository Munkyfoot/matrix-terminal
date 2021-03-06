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

    // Initiliazes row strings as unique pointers
    for (int i = 0; i < height; i++) {
        this->rows_.push_back(std::make_unique<string>(""));
    }
    GenerateAllRows();

    // Sets starting points and lengths for vertical character streams
    for (int i = 0; i < width; i++) {
        this->lengths_.push_back(rand() % (height / 3) + height / 3);
        this->starts_.push_back(rand() % height);
    }
}

// Generates content for all rows
void Matrix::GenerateAllRows() {
    for (int i = 0; i < this->rows_.size(); i++) {
        GenerateRow(*this->rows_[i]);
    }
}

// Generates content for specified row
void Matrix::GenerateRow(string &row) {
    row = "";
    for (int i = 0; i < this->screen_width_; i++) {
        switch (this->charset_) {
        case CharSet::ASCII:
            row += (char)(rand() % 76 + 48);
            break;
        case CharSet::Binary:
            row += std::to_string(rand() & 2 / 2);
            break;
        }
    }
}

// Randomly changes characters within all rows
void Matrix::AddNoise(float noise) {
    if (noise < 0) {
        noise = 0;
    } else if (noise > 1) {
        noise = 1;
    }

    std::lock_guard<std::mutex> lck(this->mtx_);
    for (int r = 0; r < this->screen_height_; r++) {
        int changes = rand() % (int)(this->rows_[r]->length() * noise);
        for (int c = 0; c < changes; c++) {
            char replacement{'-'};
            switch (this->charset_) {
            case CharSet::ASCII:
                replacement = (char)(rand() % 76 + 48);
                break;
            case CharSet::Binary:
                replacement = std::to_string(rand() & 2 / 2)[0];
                break;
            }
            this->RowReference(r)[rand() % (int)(this->rows_[r]->length())] =
                replacement;
        }
    }
}

// Simulates vertical characters streams 'falling'
// Randomizes vertical character stream length when appropriate
void Matrix::Tick() {
    for (int i = 0; i < screen_width_; i++) {
        this->starts_[i] = (this->starts_[i] + 1) % screen_height_;
        if (this->starts_[i] + this->lengths_[i] == screen_height_) {
            if (rand() % 3 == 0) {
                if (this->lengths_[i] < (2 * screen_height_) / 3) {
                    this->lengths_[i] += 1;
                }
            } else {
                if (this->lengths_[i] > screen_height_ / 3) {
                    this->lengths_[i] -= 1;
                }
            }
        }
    }
}

// Changes the current character set and regenerates all rows
void Matrix::ChangeCharSet(CharSet set) {
    charset_ = set;
    GenerateAllRows();
}

// Makes it easy to toggle between ASCII and Binary character sets
void Matrix::ToggleCharSet() {
    if (charset_ == CharSet::Binary) {
        ChangeCharSet(CharSet::ASCII);
    } else {
        ChangeCharSet(CharSet::Binary);
    }
}