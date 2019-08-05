#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    unordered_map<string,string> map;
    vector<string> answers;
    
    //map population
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT;  // MIME type.
        cin >> EXT >> MT; cin.ignore();
        transform(EXT.begin(),EXT.end(),EXT.begin(),::toupper);

        map[EXT]=MT;
    }
    
    // parse filename in order to find dot index
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        int index = FNAME.find_last_of(".");
        
        if(index == string::npos){
            answers.push_back("UNKNOWN");
        }else{      
            string sub = FNAME.substr(index+1);
            transform(sub.begin(),sub.end(),sub.begin(),::toupper);

            if(map.find(sub) != map.end()){
                answers.push_back(map[sub]);
             }else{
                answers.push_back("UNKNOWN");
             }
        }
    }

    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    for(auto answer:answers)
        cout << answer << endl;
}
