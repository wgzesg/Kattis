#include <iostream>
#include <queue>
using namespace std;

struct knig{
    int year;
    int strength;
};

struct yearComparison{
    bool operator()( const knig& a, const knig& b ) {
        return a.year > b.year;
    }
};

struct strengthComparison{
    bool operator()( const knig& a, const knig& b ) {
        return a.strength < b.strength;
    }
};

int main(void){
    int size, years;
    cin >> size >> years;
    knig KA;
    cin >> KA.year >> KA.strength;
    priority_queue<knig, vector<knig>, yearComparison> incomingPool;
    priority_queue<knig, vector<knig>, strengthComparison> contestantPool;
    if(KA.year == 2011)
        contestantPool.push(KA);
    else
        incomingPool.push(KA);
    for(int i = 0; i < size + years - 2; i ++){
        knig newcoming;
        cin >> newcoming.year >> newcoming.strength;
        if(newcoming.year == 2011)
            contestantPool.push(newcoming);
        else
            incomingPool.push(newcoming);
    }

    int currentYear = 2011;
    bool isKing = false;
    for(int i = 0; i < years; i ++){
        knig newking = contestantPool.top();
        if(newking.strength == KA.strength){
            isKing = true;
            break;
        }
        contestantPool.pop();

        currentYear ++;
        knig newcomer = incomingPool.top();
        contestantPool.push(newcomer);
        incomingPool.pop();
    }

    if(isKing)
        cout << currentYear << endl;
    else
        cout << "unknown" << endl;
}
