// https://www.codingame.com/ide/puzzle/the-river-i-

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


long long sumDigits(int n){
    
    int sum = 0;     
    while (n != 0) {
        sum += n%10;
        n = n/10;
    }
    
    return sum;
}


int main()
{
    long long r1;
    cin >> r1; cin.ignore();
    long long r2;
    cin >> r2; cin.ignore();
    
    long long r = r1;    
    vector<long long> vals;    

    while(r1 != r2){
        
        vals.push_back(max(r1,r2));
         
        if(find(vals.begin(), vals.end(), min(r1,r2)) != vals.end()){
            r = min(r1,r2);
            break;
        }
                    
        r1 += sumDigits(r1);
        r2 += sumDigits(r2);
        r = r1;        
    }

    cout << r << endl;
}
