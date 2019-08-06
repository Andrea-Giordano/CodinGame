#include <iostream>

int main()
{

    // game loop
    while (1) {
        std::string enemy1; // name of enemy 1
        std::cin >> enemy1; std::cin.ignore();
        int dist1; // distance to enemy 1
        std::cin >> dist1; std::cin.ignore();
        std::string enemy2; // name of enemy 2
        std::cin >> enemy2; std::cin.ignore();
        int dist2; // distance to enemy 2
        std::cin >> dist2;std:: cin.ignore();

        if (dist1 < dist2) {
            std::cout << enemy1 <<std::endl;
        }  else {
            std::cout << enemy2 << std::endl;
        }
    }
}
