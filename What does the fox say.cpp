#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <sstream>
using namespace std;

int main(void){
    int testCases;
    string temp;
    string intermediate; 

    cin >> testCases;
    getline(cin, temp);
    for (int i = 0; i < testCases; i++){
        int j = 0;
        vector<string> detectedSounds;
        set<string> knownVoices;
        getline(cin, temp);
        stringstream check1(temp); 
        while(getline(check1, intermediate, ' ')) 
        { 
            detectedSounds.push_back(intermediate); 
        }
        while(cin >> temp){
            j++;
            if(temp == "what")
                break;
            if(j%3 == 0){
                knownVoices.insert(temp);
            }
        }

        for(vector<string>::iterator it = detectedSounds.begin(); it != detectedSounds.end(); ++it){
            //cout << *it << " ";
            set<string>::iterator ptr = knownVoices.find(*it);
            if(ptr == knownVoices.end()){
                cout << *it << " ";
            }
        }
        cout << endl;
        getline(cin, temp);
    }

}