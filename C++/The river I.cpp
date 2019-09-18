// https://www.codingame.com/ide/puzzle/the-river-i-

#include <iostream>
#include <string>

long long sumDigits(int n){
    
    int sum = 0;     
    while (n != 0) {
        sum += n%10;
        n /= 10;
    }
    
    return sum;
}


int main()
{
    long long r1;
    std::cin >> r1; std::cin.ignore();
    long long r2;
    std::cin >> r2; std::cin.ignore();
    
    while(r1 != r2){
        
        if(r1 < r2)                
            r1 += sumDigits(r1);
        else
            r2 += sumDigits(r2);
    }

    std::cout << r1;
}
