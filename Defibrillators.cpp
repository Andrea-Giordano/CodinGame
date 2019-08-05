#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include <cstring>
#include <sstream>

using namespace std;


double calculateDistance(double lat1, double lat2, double long1, double long2){
    double x = (long2-long1)*cos((lat1+lat2)/2);
    double y = lat2-lat1;
    
    return (sqrt(pow(x,2)+pow(y,2)))*6371;    
}

const int NAME_INDEX = 1;
const int LONGITUDE_INDEX = 4;
const int LATITUDE_INDEX = 5;

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();
        
    int comma = LON.find(",");
    LON[comma] = '.';
    comma = LAT.find(",");
    LAT[comma] = '.';
    
    double dLON = stod(LON);
    double dLAT = stod(LAT);
    
    vector<string> parts;
    string match;
    double minDist=INT_MAX;

    for (int i = 0; i < N; ++i) {
        string DEFIB;
        getline(cin, DEFIB);
        
        stringstream stream(DEFIB);
        string tmp;
        while(getline(stream,tmp,';')){
            parts.push_back(tmp);
        }   
        
        string name = parts[NAME_INDEX];
        string longitude = parts[LONGITUDE_INDEX];
        string latitude = parts[LATITUDE_INDEX];
        
        comma = longitude.find(",");
        longitude[comma] = '.';
        comma = latitude.find(",");
        latitude[comma] = '.';
        
        double lineLON = stod(longitude);
        double lineLAT = stod(latitude);
        
        double dist = calculateDistance(dLAT, lineLAT, dLON, lineLON);

        if(dist < minDist){
            minDist = dist;
            match = name;           
        }  
        parts.clear();
    }

    cout << match << endl;
}
