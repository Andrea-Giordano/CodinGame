#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Point{
       
    public:
        Point(){}
        Point(int x,int y){
          this->x = x;
          this->y = y;
        }
        
    int getX(){
        return x;
    }
    
    int getY(){
        return y;
    }
    
    void setX(int val){
        x=val;
    }
    
    void setY(int val){
         y=val;
    }

    private:
        int x;
        int y;
     
};

class Node{
    
    public:
        Node(Point n, Point r, Point b){
            node = n;
            neighborR = r;
            neighborB = b;
        }
        
        Point getNode(){
            return node;
        }
        
        Point getNeighborR(){
            return neighborR;
        }

        Point getNeighborB(){
            return neighborB;
        }

    private:
        Point node;
        Point neighborR;
        Point neighborB;

};

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    
    char mat[width][height];
    
    vector<Node> nodeList;
    
    for (int i = 0; i < height; ++i) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
                
        //create the table
        for(int j=0;j<width;++j){
            mat[j][i] = line[j];
        }
    }

     for(int i=0;i<height;++i){
        for(int j=0;j<width;++j){
            if(mat[j][i]=='0'){
                Point curr_node = Point(j,i);
                Point rnode = Point();
                Point bnode = Point();
                
                int x = j;
                while((++x) < width && mat[x][i]=='.');
                if( x < width){
                    rnode.setX(x);
                    rnode.setY(i);
                }else{
                    rnode.setX(-1);
                    rnode.setY(-1);
                }
                
                int y = i;
                while((++y) < height && mat[j][y]=='.');
                if(y < height){
                   bnode.setX(j);
                   bnode.setY(y);
                }else{
                    bnode.setX(-1);
                    bnode.setY(-1); 
                }
                
                cout << curr_node.getX() << " " << curr_node.getY() << " " << rnode.getX() << " " << rnode.getY() << " " << bnode.getX() << " " << bnode.getY() << endl;

            }   
        }
    }
 }
