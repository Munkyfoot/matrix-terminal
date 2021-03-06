#ifndef MATRIX_H
#define MATRIX_H

#include <memory>
#include <mutex>
#include <string>
#include <vector>

using std::string;
using std::vector;

// Used to choose which character set is displayed
enum CharSet { Binary, ASCII };

// Used to store the tip of a vertical character stream
struct Drop {
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
    string RowCopy(int index) const { return *rows_[index]; }
    int Width() const { return screen_width_; }
    int Height() const { return screen_height_; }
    vector<int> Lengths() const { return lengths_; }
    vector<int> Starts() const { return starts_; }
    CharSet CurrentCharSet() const { return charset_; }

    // Methods
    void GenerateAllRows();          // Defined in matrix.cpp
    void GenerateRow(string &row);   // Defined in matrix.cpp
    void AddNoise(float noise);      // Defined in matrix.cpp
    void Tick();                     // Defined in matrix.cpp
    void ChangeCharSet(CharSet set); // Defined in matrix.cpp
    void ToggleCharSet();

  protected:
    string &RowReference(int index) { return *rows_[index]; }

  private:
    vector<std::unique_ptr<string>> rows_{};
    vector<int> lengths_{};
    vector<int> starts_{};
    int screen_width_{};
    int screen_height_{};
    CharSet charset_{CharSet::ASCII};
    std::mutex mtx_;
};

#endif