#include <iostream>
#include <set>
#include <string>

using namespace std;
typedef struct{
    string instruction;
    int energy;
    int gold;
    int ID;
}command;

typedef struct{
     bool operator() (command A, command B)const{
        if(A.energy < B.energy)
            return true;
        else if(A.energy == B.energy && B.instruction == "query")
            return true;
        else if(A.energy == B.energy && A.instruction == "query")
            return false;
        else if (A.energy == B.energy && A.gold < B.gold)
            return true;
        else if(A.ID < B.ID)
            return true;
        else
            return false; 
    }
}cmp;

long doAll(set<command, cmp>* commandSet, int en);

int main(void){
    int noOfCommands;
    set<command, cmp>* commands = new set<command, cmp>;
    command current;
    long gold;
    cin >> noOfCommands;
    for(int i = 0; i < noOfCommands; i++){
        cin >> current.instruction;
        cin >> current.energy;
        if(current.instruction == "query"){
            gold = doAll(commands, current.energy);     
            cout << gold << endl;
        }
        else if(current.instruction == "add"){
            cin >> current.gold;
            current.ID = i;
            commands->insert(current);
        }
    }
}

long doAll(set<command, cmp>* commandSet, int en){
    long gold = 0;
    command temp = {"query", en, 0, -1};
    set<command, cmp>::iterator it = commandSet->upper_bound(temp);
    int smallest = commandSet->begin()->energy;

    while(true){
        if(smallest == 0 || temp.energy < smallest){
            break;
        }
        it --;
        temp.energy -= it->energy;
        gold += it->gold;
        commandSet->erase(it);
        it = commandSet->upper_bound(temp);
        smallest = commandSet->begin()->energy;
    }
    return gold;
}
