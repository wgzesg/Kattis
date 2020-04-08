#include<iostream>
#include <string>
using namespace std;

int main(void){
    string directions;
    int levels;
    int number = 1;
    cin >> levels >> directions;
    for(char c : directions){
        number = number * 2 + (c == 'R');
    }
    cout << (1<<(levels+1)) - number << endl;
}