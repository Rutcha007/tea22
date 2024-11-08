#include <fmt/chrono.h>
#include <fmt/format.h>
#include "triangle.h"
#include "triangle.h"

#define MAX_NAME_LENGTH 25

struct Person {
    unsigned int alter;
    float gewicht;
    char name[MAX_NAME_LENGTH];
};

auto main(int argc, char** argv) -> int
{
    fmt::print("Hello, {}!\n", argv[0]);

    Person paul;
    paul.gewicht = 47.3;
    paul.alter = 14;
    fmt::print("Paul ist {} Jahre alt\n", paul.alter);

    Person* pPers;
    pPers = &paul;
    fmt::print("Paul ist {} Jahre alt\n", pPers -> alter);
    
    Person paula = {18,57.0,"Paula"};
    fmt::print("Paul ist {} Jahre alt\n", paula.alter);

    pPers = &paula;
    fmt::print("Die Person auf die der Zeiger pPers zeigt ist {} Jahre alt\n", pPers -> alter);

    //paul.name = "Paul"; geht nicht
    strncpy(paul.name,"Paul",MAX_NAME_LENGTH);
    fmt::println("Der Name von Paul ist {}\n",paul.name);




    Triangle* trig = newTriangle(); // Rückgabe von new ist vom Typ Triangle die Adresse und wird auf den Pointer von Typ Triangle gespeichert

    fmt::println("Side a of the triangle trig {}\n", trig->side_a); //zuweisen auf die Adresse wo trig draufzeigt
    fmt::println("Side b of the triangle trig {}\n", trig->side_b);
    fmt::println("Side c of the triangle trig {}\n", trig->side_c);

    // Speicherloch
    // trig = newTriangle();

    // Richtig
    freeTriangle(trig);
    trig = newTriangleWithValues(42,34,56);


fmt::println("The perimeter ist: {}", perimeter(trig));

    return 0; /* exit gracefully*/
}
