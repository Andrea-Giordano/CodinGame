#include <iostream>

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();

    std::string x;
    std::string y;
    
    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        std::cin >> remainingTurns; std::cin.ignore();
             
        x="";
        y="";
        
        if(initialTX > lightX){
            x = "W";
            initialTX--;
        }else if(initialTX < lightX){
            x = "E";
            initialTX++;
        }
        
        if(initialTY > lightY){
            y = "N";
            initialTY--;
        }else if(initialTY < lightY){
            y = "S";
            initialTY++;
        }
        
        // A single line providing the move to be made: N NE E SE S SW W or NW
        std::cout << y << x << std::endl;
    }
}
