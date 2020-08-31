#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Drop{
    public:
        int x{};
        int y{};
        char c{};

        Drop(int _x, int _y, int _c) : x(_x), y(_y), c(_c) {} 
};

class Matrix {
  public:
    Matrix(int width, int height); // Defined in matrix.cpp

    // Accessors
    vector<string> Rows() const { return rows_; }
    int Width() const { return screen_width_; }
    int Height() const { return screen_height_; }
    vector<int> Lengths() const { return lengths_; }
    vector<int> Starts() const { return starts_; }

    // Methods
    string GenerateRow() const; // Defined in matrix.cpp
    void AddNoise(float noise); // Defined in matrix.cpp
    void Tick();                // Defined in matrix.cpp

  private:
    vector<string> rows_{};
    vector<int> lengths_{};
    vector<int> starts_{};
    int current_row_id_{0};
    int screen_width_{};
    int screen_height_{};
};

#endif