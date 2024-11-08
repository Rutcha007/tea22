#include "triangle.h"
#include "stdlib.h"

unsigned int perimeter(Triangle* self) {
    return self->side_a + self->side_b + self->side_c;
}

// Triangle temp; Nur ein Dreieck kann erzeugt werden

Triangle* newTriangle() { //Rückgabe ist Adresse des Pointers

    //Triangle temp; -> Problem Verweis auf Stacklokale Variable
    Triangle* temp = (Triangle*) malloc(sizeof(Triangle)); //dynamischer Speicher
    /*
    temp ->side_a = 0;
    temp ->side_b = 0;
    temp ->side_c = 0;
    */
    return temp;
}

void freeTriangle(Triangle* ptr) {
    free(ptr);
}

Triangle* newTriangleWithValues(unsigned int a, unsigned int b, unsigned int c) {
    Triangle* temp = newTriangle();
    temp->side_a = a;
    temp->side_b = b;
    temp->side_c = c;
    return temp;
}