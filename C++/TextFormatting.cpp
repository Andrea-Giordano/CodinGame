#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

std::array<char,12> punctuation={'.',',',':',';','\'','!','?','-','_','(',')'};

/* @brief: Check if a character is a punctuation mark
*  @Params: A character to be checked
*  @Returns: True if the char is a puntuation mark, False otherwise 
*/
bool isAPunctuationMark(char c){
    
    for(int i=0;i<punctuation.size();++i){
        if(c == punctuation[i]){
            return true;
        }
    }
    return false;
}

/* @brief: Check if a character is a whitespace
*  @Params: A character to be checked
*  @Returns: True if the char is a whitespace, False otherwise 
*/
bool isAWhiteSpace(char c){
    int space = ' ';
    int asciiC = c;
    
    return asciiC == space;
}

/* @brief: Check if a character is a upper case formatted
*  @Params: A character to be checked
*  @Returns: True if the char is a upper case formatted, False otherwise 
*/
bool isUpperCase(char c){
    int A = 'A';
    int Z = 'Z';
    int asciiC = c;
    
    return asciiC >= A || asciiC <= Z;    
}

int main()
{
        
    std::string intext;
    getline(std::cin, intext);
    

    // lower case the whole text
    for(int j=0;j<intext.length();j++){
        if(isUpperCase(intext[j])){
            intext[j] = std::tolower(intext[j]);
        }
    }
    


    //Remove space before punctuation
    for(int j=1;j<intext.length();j++){
        if(isAWhiteSpace(intext[j-1]) && isAPunctuationMark(intext[j])){
            intext.erase(j-1,1);
            j=0; 
        }
    }


    //Remove double punctuation
    for(int j=0;j<intext.length()-1;j++){
        if(isAPunctuationMark(intext[j]) && isAPunctuationMark(intext[j+1])){
            intext.erase(j+1,1);
            j--; 
        }
    }

    // erase multiple spaces
    for(int j=0;j<intext.length()-1;j++){
        if(isAWhiteSpace(intext[j]) && isAWhiteSpace(intext[j+1])){
            intext.erase(j+1,1);
            j--;
        }
    }


    //insert space after punctuation
    for(int j=0;j<intext.length()-1;j++){
        if(isAPunctuationMark(intext[j]) && !isAWhiteSpace(intext[j+1])){
            intext.insert(j+1," ");           
        }
    }

    //Capitalize all characters after dot
    intext[0] = toupper(intext[0]); 
    for(int j=1;j<intext.length();j++){
        if(intext[j]=='.' && (j+2)<intext.length()){
            intext[j+2] = toupper(intext[j+2]);
        }
    }
    

    std::cout << intext << std::endl;
}
