#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
 
int findMinDiff(const std::vector<int>& vect){
    int prev;
    int curr;
    int diff;
    int minDiff =  INT_MAX;
 
    for (int i = 0; i < vect.size()-1; ++i) {
        prev = vect[i];
        curr = vect[i+1];
        diff = curr-prev;
        
        if(diff < minDiff){
            minDiff = diff;
        }
        
        if(minDiff == 0){
            return 0;
        }
    }
    
    return minDiff;
}

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    std::vector<int> v;
    for (int i = 0; i < N; ++i) {
        int Pi;
        std::cin >> Pi; std::cin.ignore();
        v.push_back(Pi);      
    }
    std::sort(v.begin(),v.end());

    std::cout << findMinDiff(v) << std::endl;
}
