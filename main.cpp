#include <iostream>
#include "Image.hpp"
#include "MultipleImagePrinter.hpp"
#include "Dragon.hpp"
#include "Maze.hpp"

int main()
{
    // Image logo("assets\\logo.dnd");
    // Printer out;
    //  out(logo);
    // Dragon lamb;
    //  fix lamb.print(mOut);
    // std::cin.get();
    Maze m;
     m.print();
    // std::cin.get();
    std::cout << m.isReachable(9, 9);
    std::cin.get();
    return 0;
}