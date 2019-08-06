#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    std::cin >> W >> H; std::cin.ignore();
    int N; // maximum number of turns before game over.
    std::cin >> N; std::cin.ignore();
    int X0;
    int Y0;
    std::cin >> X0 >> Y0; std::cin.ignore();
    
    int x1 = 0;
    int x2 = W-1;
    int y1 = 0;
    int y2 = H-1;

    // game loop
    while (1) {
        std::string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        std::cin >> bombDir; std::cin.ignore();

        if(bombDir.find("D") != string::npos){
            y1 = Y0+1;
        }
        else if(bombDir.find("U") != string::npos){
            y2 = Y0-1;
        }
        if(bombDir.find("R") != string::npos){
            x1 = X0 +1;    
        }
        else if(bombDir.find("L") != string::npos){
            x2 = X0 -1;
        }    
    
        X0 = x1 + (x2 - x1)/2;
        Y0 = y1 + (y2 - y1)/2;

        // the location of the next window Batman should jump to.
        std::cout << X0 <<" "<< Y0 << std::endl;
    }
}
