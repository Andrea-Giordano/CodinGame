#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int n; // the number of temperatures to analyse
    int closest=5527;
    std::cin >> n; std::cin.ignore();
    
    if(n==0){
        std::cout <<  0 << std::endl;
        exit(0);
    }else{
        for (int i = 0; i < n; ++i) {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            std::cin >> t; std::cin.ignore();
        
            if(t==0){
                std::cout << t << std::endl;
                exit(0);
            }
        
            if(abs(t) == abs(closest)){
                closest = t > closest? t:closest;
            }else if(abs(t) < abs(closest)){
                closest = t;
            }
        }
    }
        
    std::cout << closest << std::endl;
}
