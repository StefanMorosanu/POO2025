#include <iostream>
#include "Canvas.h"
#include "canvas.cpp"

int main() {
    Canvas c(50, 20);

    c.DrawRect(2, 2, 20, 8, '#');
    c.FillRect(3, 3, 19, 7, '.');

    c.DrawCircle(35, 6, 5, 'o');
    c.FillCircle(35, 6, 3, '+');

    c.DrawLine(0, 0, 49, 19, '*');

    c.SetPoint(25, 10, '@');

    c.Print();

    std::cout << "\nClearing canvas...\n\n";
    c.Clear();
    c.Print();

    return 0;
}
