#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    int L;
    std::cin >> L; std::cin.ignore();
    std::vector<std::vector<std::string>> mat(N);
    
    // Input collection
    int M=0;
    for (int i = 0; i < N; i++) {
        std::string LINE;
        getline(std::cin, LINE);

        mat[i].resize(LINE.length());
        for(int j =0;j<LINE.length();j=j+2){
            mat[i][j/2] = LINE[j];
            M++;
        }
    }
    M = M/N;


    int res[N][M];
    
    // Initialize a result matrix containing references to the enlighted and dark spots
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            res[i][j]=0;
        }
    }
    
    int lightPoints = 0;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){

            if(mat[i][j]=="C"){                
                res[i][j]=1;
                
                for(int x=i-L+1;x<i+L;++x){
                    if(x<0 || x>=N)
                        continue;
                        
                    for(int y=j-L+1;y<j+L;++y){
                        if(y<0 || y>=M || res[x][y]==1)
                            continue;
                        res[x][y]=1;
                    }
                }                  
            }
        }
    }
    
    int darkPoints = 0;
    
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            if(res[i][j]==0)
                darkPoints++;           
        }
    }
    
    std::cout << darkPoints << std::endl;
}
