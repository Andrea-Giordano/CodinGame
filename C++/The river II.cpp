// https://www.codingame.com/ide/puzzle/the-river-ii-

#include <iostream>
#include <string>
#include <unordered_map>

int sumDigits(int n){
    
    int sum = 0;     
    while (n != 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
    
    
int main()
{
    int r, r1 = 1;
    std::cin >> r; std::cin.ignore();
    std::unordered_map<int, bool> seen;
    
    for(int i=1; i<r && r1 != r; ++i){
        r1 = i;
        
        while(r1<r && seen.find(r1) == seen.end()){ //When a non meeting river is met, just skip.
            seen[r1] = true;
            r1 += sumDigits(r1);
        }
    }
    
    std::string res = (r1 == r) ? "YES" : "NO"; 
    std::cout << res << std::endl;        
}
