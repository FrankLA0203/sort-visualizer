#include <iostream>
#include "selectionSort.h"

const int SENTINEL = -1;

int main() {
    int input;

    while (input != SENTINEL) {
        std::cout << "(1) Selection sort" << std::endl;
        std::cout << "(2) Bubble sort" << std::endl;

        std::cout << "Enter a number corresponding to a sort algorithm (-1 to quit): ";
        std::cin >> input;

        switch (input) {
            case -1:
                break;
            case 1:
                selectionSort();
                break;
            default:
                std::cout << "Unknown option." << std::endl;
        }
    }

    return 0;
}
