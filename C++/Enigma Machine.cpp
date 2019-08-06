#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>


int main()
{
    
    std::array<char, 26> alphabet = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

    std::string operation;
    getline(std::cin, operation);
    
    int pseudoRandomNumber;
    std::cin >> pseudoRandomNumber; std::cin.ignore();
    std::vector<std::vector<char> > rotors(26);

    for (int i = 0; i < 3; i++) {
        std::string rotorString;
        getline(std::cin, rotorString);
        
        for(int j=0;j<rotorString.length();++j){
            rotors[i].push_back(rotorString[j]);
        }
    }
    
    std::string message;
    getline(std::cin, message);
    
    //Encoding
    if(operation[0]=='E'){
        
        for(int i=0;i<message.length();++i){
          int index = std::find(alphabet.begin(),alphabet.end(),message[i]) - alphabet.begin();
          int letterIndex = (index+pseudoRandomNumber+i)%26;
          message[i] = alphabet[letterIndex];
        }
        
        for(int j=0;j<3;++j){
             for(int i=0;i<message.length();++i){
                 int index = std::find(alphabet.begin(),alphabet.end(),message[i]) - alphabet.begin();   
                 message[i] = rotors[j][index];
             }
        }
        
    // Decoding
    }else{
        for(int j=2;j>=0;--j){
             for(int i=0;i<message.length();++i){
                 int index = std::find(rotors[j].begin(),rotors[j].end(),message[i]) - rotors[j].begin();   
                 message[i] = alphabet[index];
             }
        }
        
        for(int i=0;i<message.length();++i){
          int index = std::find(alphabet.begin(),alphabet.end(),message[i]) - alphabet.begin();
          int letterIndex = (index-pseudoRandomNumber-i);
          if(letterIndex%26==0)
            letterIndex=0;
          else if(letterIndex<0){
            int cycle = -letterIndex/26+1;
            letterIndex = (26*cycle)+letterIndex; 
          } 
          message[i] = alphabet[letterIndex];
        }

 
    }

     std::cout << message << std::endl;
}
