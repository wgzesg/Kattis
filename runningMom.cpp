#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <string>
//using namespace std;

class City{
public:
    int outFlightCount;
    int isSafe; // -1 unknown; 0 unsafe; 1 safe
    std::vector<std::string> destinations;
    City(){
        isSafe = -1;
        outFlightCount = 0;
    }
};

int main(void){
    int flights;
    std::string city1Name, city2Name;
    std::cin >> flights;
    std::unordered_map<std::string, City*> cities;
    for(int i = 0; i <  flights; i ++){
        std::cin >> city1Name >> city2Name;
        std::pair<std::unordered_map<std::string, City*>::iterator,bool> ret;
        ret = cities.insert( std::pair<std::string, City*>(city1Name, new City()));
        cities.insert( std::pair<std::string, City*>(city2Name, new City()));
        ret.first->second->outFlightCount ++;
        ret.first->second->destinations.push_back(city2Name);
    }
    int noOfCities = cities.size();
    for(int i = 0; i < noOfCities; i++){
        for(std::unordered_map<std::string, City*>::iterator it = cities.begin(); it != cities.end(); ++it){
            if(it->second->isSafe == 0)
                continue;
            if(it->second->outFlightCount == 0){
                it->second->isSafe = 0;
                continue;
            }
            int isUnknown = 0;
            for(std::vector<std::string>::iterator strIt = it->second->destinations.begin(); strIt != it->second->destinations.end(); strIt++){
                std::unordered_map<std::string, City*>::iterator destCity = cities.find(*strIt);
                if(destCity->second->isSafe != 0){
                    isUnknown = 1;
                    break;
                }
            }
            if(isUnknown == 0){
                it->second->isSafe = 0;
            }
            
        }
    }
    for(std::unordered_map<std::string, City*>::iterator it = cities.begin(); it != cities.end(); ++it){
        if(it->second->isSafe == -1)
            it->second->isSafe = 1;
    }

    while(std::cin >> city1Name){
        if(std::cin.eof())
            break;
        std::unordered_map<std::string, City*>::iterator testingCity = cities.find(city1Name);
        if(testingCity->second->isSafe == 1)
            std::cout << city1Name << " safe" << std::endl;
        else
            std::cout << city1Name << " trapped" << std::endl;
    }
}