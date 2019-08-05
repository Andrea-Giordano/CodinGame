#include <iostream>

#define NUM_LINES 8 
int main()
{

    // game loop
    while (1) {
        int max = -1;
        int highest = 0;
        for (int i = 0; i < NUM_LINES; ++i) {
            int mountainH; // represents the height of one mountain.
            std::cin >> mountainH; std::cin.ignore();
            
            if(mountainH > max){
                max = mountainH;
                highest = i;
            }
            
        }
        
        std::cout << highest << std::endl; // The index of the mountain to fire on.
    }
}
