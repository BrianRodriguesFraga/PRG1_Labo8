#ifndef types_hpp
#define types_hpp

struct position_t {
    int x;
    int y;

    position_t() { x = 0; y = 0; }
    position_t(int x, int y) : x(x), y(y) { }
};

struct dim_t {
    int width;
    int height;

    dim_t() { width = 0; height = 0; }
    dim_t(int w, int h) : width(w), height(h) { }
};

enum class MoveType { Left, Right, Up, Down };

#endif