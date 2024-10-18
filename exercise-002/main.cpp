#include <fmt/chrono.h>
#include <fmt/format.h>

/* .bss Segment*/
int foo;
int foo2;

/* .data segment*/
int data = 53;
int data2 = 50;

/* .rodata segment*/
const int rodata = 45; // landen nicht im RAM nur im Flash
const int rodata2 = 46;


void doSomething(int value){
    value = value+1;
    fmt::print("doSomething, value {}!\n", value);
}

void doSomethingPtr(int* ptr){  // Übergabe Adresse
    *ptr = *ptr+1;              // * holt den Wert worauf der Pointer zeigt und speichert den Wert darauf
    fmt::print("doSomethingPtr, value {}!\n", *ptr);
}

int* doReturnAPtr(){
    static int value = 47;
    fmt::print("doSomethingPtr, value {}\n", value);
    return &value; // niemals eine Adresse einer lokalen Var einer Funktion nach außen geben man muss sie statisch machen
}

void doSomethingStatic(){
    static int value = 56; // bleibt nach verlassen der Funktion erhalten
    value = value + 1;
    fmt::print("doSomething, value {}!\n", value);
}

auto main(int argc, char **argv) -> int
{
  
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]); // gibt die erste komplette Zeile des Arrays aus
    fmt::print("Value of foo {} address of foo {}\n", foo, fmt::ptr(&foo)); // Adresse richtig interpretieren und ausgeben


    int bar = 42;
    doSomething(bar); // verarbeitet die 42 aber kann die variable nicht verändern
    fmt::print("The value of bar is: {}\n", bar);

    doSomethingPtr(&bar); // arbeitet mit der Adresse von bar und verändert dadurch den Wert 42
    fmt::print("The value of bar after doSomethingPtr: {}\n", bar);


    int* returnedPtr = doReturnAPtr();
    fmt::print("{}\n", *returnedPtr);
    doSomething(42);
    fmt::print("{}\n", *returnedPtr); // Adresse war nur in doReturnAPtr verfügbar die nächste Funktion schreibt auf diese Adresse

    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();
    doSomethingStatic();

    int var;
    static int var2; // Stack Segment hohe Adressen

    return 0; /* exit gracefully*/
}
