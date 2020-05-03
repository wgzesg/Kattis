#include <iostream>
#include <vector>
using namespace std;

int findRank(int p, int q);

int main(void){
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i ++){
        int currentCase, p, q;
        cin >> currentCase >> p;
        cin.get();
        cin >> q;
        int rank = findRank(p,q);
        cout << currentCase << " " << rank << endl;
    }
}

int findRank(int p, int q){
    if(p == 1 && q == 1){
        return 1;
    }
    else if(p > q){
        return 2 * findRank(p -q, q) + 1;
    }
    else{
        return 2 * findRank(p, q - p);
    }
}