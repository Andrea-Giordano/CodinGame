// https://www.codingame.com/ide/puzzle/the-river-ii-

#include <iostream>
#include <string>
#include <unordered_set>

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
    std::unordered_set<int> seen;
    
    for(int i=r-1; i>0 && r1 != r; --i){
        r1 = i;
        
        while(r1<r && seen.find(r1) == seen.end()){ //When a non meeting river is met, just skip.
            seen.insert(r1);
            r1 += sumDigits(r1);
        }
    }
    
    std::string res = (r1 == r) ? "YES" : "NO"; 
    std::cout << res << std::endl;        
}
