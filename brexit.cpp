#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int c, p, x, l;
    cin >> c >> p >> x >> l;
    int partner1, partner2;
    vector<bool> isOut(c+1, 0);
    vector<int> countries[c + 1];
    vector<int> partnersLeaving(c + 1, 0);
    queue<int> countriesOut;
    

    for(int i = 0; i < p; i++){
        cin >> partner1 >> partner2;
        countries[partner1].push_back(partner2);
        countries[partner2].push_back(partner1);
    }
    isOut[l] = 1;
    if(x == l)
        isOut[x] = 1;
    else
        countriesOut.push(l);
    while(!countriesOut.empty() && isOut[x] == 0){
        int currentOut = countriesOut.front();
        countriesOut.pop();
        int count = countries[currentOut].size();
        for(int i = 0; i < count; i++){
            int partner = countries[currentOut][i];
            if(isOut[partner] == 1){
                continue;
            }
            partnersLeaving[partner] ++;
            if(partnersLeaving[partner] >= countries[partner].size() / 2.0){
                if(partner == x){
                    isOut[x] = 1;
                    break;
                }
                else{
                    countriesOut.push(partner);
                    isOut[partner] = 1;
                }
            }
        }
    }

    if(isOut[x] == 1)
        cout << "leave" << endl;
    else
        cout << "stay" << endl;
}