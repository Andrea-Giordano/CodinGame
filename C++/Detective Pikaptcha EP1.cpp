//https://www.codingame.com/ide/puzzle/detective-pikaptcha-ep1
#include <iostream>
#include <string>

int main(){
    
    int width;
    int height;
    std::cin >> width >> height; std::cin.ignore();
    
    char resGrid[height][width];
    
    //Matrix initialization to '0'
    for(int i=0; i<height; ++i){                       
            for(int j=0; j<width; ++j){
                resGrid[i][j] = '0';
            }            
    }
    
    
    // Count passages
    for (int i=0; i<height; ++i) {
        std::string line;       
        std::cin >> line; std::cin.ignore();       
        
        for(int j=0; j<width; ++j){

            if(line[j]=='0'){
               
               if(j-1 >= 0 && line[j-1]=='0'){
                  resGrid[i][j-1] = resGrid[i][j-1]-'0' +'1';
                  resGrid[i][j] = resGrid[i][j]-'0' +'1';
                  
               }
               if(i-1 >= 0 && resGrid[i-1][j]!='#'){
                  resGrid[i-1][j] = resGrid[i-1][j]-'0' +'1';  
                  resGrid[i][j] = resGrid[i][j]-'0' +'1';
               } 
            
            }else{
               resGrid[i][j] = '#';
            }        
        }
        
    }
    

   // Print result
   for(int i=0; i<height; ++i){                       
            for(int j=0; j<width; ++j){
                std::cout << resGrid[i][j];
            }            
            std::cout << std::endl;
    }
    
    
}
