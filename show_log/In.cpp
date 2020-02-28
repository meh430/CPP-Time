#include "Show.h"
#include "In.h"
#include <iostream>

void In::onStart() {
    std::cout<<"1) Create new repo\n";
    std::cout << "2) Access existing repo\n";
    int choice = 0;
    std::cin >> choice;
    switch (choice) {
    case 1:
        break;
    default:
        break;
    }
}

int main() {
    In start;
    start.onStart();
    return 0;
}