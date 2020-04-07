#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <queue>
using namespace std;

class Edge{
public:
    int destination;
    int weight;
    Edge(int A, int B){
        destination = A;
        weight = B;
    }
};

class Node
{
public:
    int nodeIndex;
    int precessor;
    int distance;
    int isComplete;
    Node(){
        distance = -1;
        isComplete = 0;
    }
    bool operator<( Node const &B) const{
        return distance > B.distance;
    }
    bool operator==(Node const &B) const{
        return nodeIndex == B.nodeIndex;
    }
};

int main(void){
    int nodes, edges, destinations, source, terminal;

    cin >> nodes >> edges >> destinations >> source;
    while(nodes != 0 || edges != 0 || destinations != 0|| source != 0){
        vector < vector<Edge> > graph(nodes);
        for(int i = 0; i < edges; i++){
            int A, B, weight;
            cin >> A >> B >> weight;
            graph[A].push_back(Edge(B, weight));
        }
        
        priority_queue<Node> minDistTree;
        vector<Node> completedNodes(nodes);
        int startingPoint = source;
        completedNodes[startingPoint].distance = 0;
        completedNodes[startingPoint].precessor = startingPoint;
        completedNodes[startingPoint].isComplete = 1;


        for(int i = 0; i < destinations; i ++){
            cin >> terminal;
            while(completedNodes[terminal].isComplete == 0){
                vector<Edge>::iterator it;
                int currentDist = completedNodes[startingPoint].distance;
                for(it= graph[startingPoint].begin(); it != graph[startingPoint].end(); it++){
                    int destPoint = it->destination;
                    if(completedNodes[destPoint].distance == -1 || completedNodes[destPoint].distance > currentDist + it->weight){
                        completedNodes[destPoint].distance = currentDist + it->weight;
                        completedNodes[destPoint].precessor = startingPoint;
                        completedNodes[destPoint].nodeIndex = destPoint;
                        minDistTree.push(completedNodes[destPoint]);
                    }
                }
                if(minDistTree.empty()){
                    break;
                }
                startingPoint = minDistTree.top().nodeIndex;
                completedNodes[startingPoint].isComplete = 1;
                minDistTree.pop();
            }
            if(completedNodes[terminal].isComplete == 1)
                cout << completedNodes[terminal].distance << endl;
            else
                cout << "Impossible" << endl;
        }
        cin >> nodes >> edges >> destinations >> source;
        if(nodes != 0 || edges != 0 || destinations != 0|| source != 0)
            cout << endl;
    }

}
