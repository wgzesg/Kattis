#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node{
    public:
        int distance;
        int index;
        node(){
            distance = -1;  // -1 -> untouched; -2 -> boundary / unaccessible
        }
        bool operator<(node B){
            if(distance == B.distance)
                return index > B.index;
            else
                return distance > B.distance;
        }
};

bool findPath(priority_queue<node *> & processing_pq, node* current, vector< vector<node> >& map);

int main(void){
    priority_queue<node* > processing_pq;
    node* source;
    int size;
    bool existPath = 0;
    char input;
    cin >> size;
    vector< vector<node> > map(size + 4, vector<node>(size + 4));
    for (int i = 0; i < size + 4; i ++){
        for(int j = 0; j < size + 4; j ++){
            if(i == 0 || j == 0 || i == 1 || j == 1 ||
               i == size + 2 || j == size + 2 || i == size + 3 || j == size + 3){
                map[i][j].distance = -2;
                map[i][j].index = -1;
            } // set boundary
            else{
                cin >> input;
                if(input == '#')
                    map[i][j].distance = -2;
                else if(input == 'K'){
                    map[i][j].distance = 0;
                    source = &map[i][j];
                }
                map[i][j].index = size * (i - 2) + (j - 2);
            }
        }
    }
    processing_pq.push(source);
    node* current = source;
    while(!processing_pq.empty() && !existPath){
        current = processing_pq.top();
        processing_pq.pop();
        existPath = findPath(processing_pq, current, map);
    }
    
    cout << map[2][2].distance << endl;
}

bool findPath(priority_queue<node *> & processing_pq, node* current, vector< vector<node> >& map){
    int i = current->index / (map.size() - 4);
    int j = current->index % (map.size() - 4);
    for(int x = -2; x< 3; x ++){
        for(int y = -2; y < 3; y++){
            if(x * y == 2 || x * y == -2){
                node* nextDest = &map[i + x + 2][j + y + 2];
                if(nextDest->distance == -2)
                    continue;
                if(nextDest->distance == -1 || nextDest->distance > current->distance + 1){
                    nextDest->distance = current->distance + 1;
                    if(nextDest->index == 0){
                        return true;
                    }
                    processing_pq.push(nextDest);
                }
            }

        }
    }
    return false;
}