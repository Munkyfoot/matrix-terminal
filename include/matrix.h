#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Matrix {
  public:
    Matrix(int width, int height)
        : screen_width_(width), screen_height_(height) {}

    // Accessors
    vector<string> Rows() const { return rows_; }
    int Width() const { return screen_width_; }
    int Height() const { return screen_height_; }

    // Methods
    void GenerateRow(); //Defined in matrix.cpp

  private:
    vector<string> rows_{};
    int screen_width_{};
    int screen_height_{};
};

#endif