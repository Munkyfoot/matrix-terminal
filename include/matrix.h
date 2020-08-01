#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Matrix {
  public:
    Matrix(int width, int height); // Defined in matrix.cpp

    // Accessors
    vector<string> Rows() const { return rows_; }
    int Width() const { return screen_width_; }
    int Height() const { return screen_height_; }

    // Methods
    string GenerateRow() const; // Defined in matrix.cpp
    void AddNoise(float noise); // Defined in matrix.cpp

  private:
    vector<string> rows_{};
    int current_row_id_{0};
    int screen_width_{};
    int screen_height_{};
};

#endif