#ifndef MY_FANCY_TRIANGLE_H //include guard
#define MY_FANCY_TRIANGLE_H

struct Triangle {
    unsigned int side_a;
    unsigned int side_b;
    unsigned int side_c;
};

//Vorwärtsdeklaration
Triangle* newTriangle();
Triangle* newTriangleWithValues(unsigned int a, unsigned int b, unsigned int c);

void freeTriangle(Triangle* ptr);

unsigned int perimeter(Triangle* self);

#endif