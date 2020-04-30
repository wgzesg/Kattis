#include <iostream>
#include <vector>
using namespace std;


int findParent(int source, vector<int> map);

int main(void){
    int cities, endpoints, roads;

    cin >> cities;

    for(int i = 0; i < cities; i++){
        cin >> endpoints >> roads;
        vector<int> map(endpoints, -1);

        int source, dest;
        int totalSubsets = endpoints;
        for(int j = 0; j < roads; j++){
            cin >> source >> dest;
            map[source] = findParent(source, map);
            map[dest] = findParent (dest, map);

            totalSubsets --;
            if (map[source] == map[dest]){
                totalSubsets ++;
            }
            else if(map[dest] != map[source]){
                map[map[dest]] = map[source];
            }
        }
        cout << totalSubsets - 1 << endl;
    }
}


int findParent(int source, vector<int> map){
    if(map[source] == -1 || map[source] == source){
        return source;
    }
    else
    {
        map[source] = findParent(map[source], map);
        return map[source];
    }
    
}
