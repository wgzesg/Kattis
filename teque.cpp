#include <iostream>
#include <map>
#include <string>

int main(void){
    int commands;
    int nextNumber;
    float max, min, mid;
    max = min = 0;
    mid = 10;
    std::map<float, int> teque;
    std::string nextCommand;
    std::cin >> commands;
    for(int i = 0; i < commands; i++){
        std::cin >> nextCommand >> nextNumber;
        if(nextCommand == "push_back"){
            max += 10;
            std::cout << "max" << max << nextNumber << std::endl;
            teque.insert(std::pair<float, int>(max, nextNumber));
            std:: cout << teque.find(10)->second << std::endl;
        }
        else if(nextCommand == "push_front"){
            min -= 10;
            std::cout << "min" << min << nextNumber << std::endl;
            teque.insert(std::pair<float, int>(min, nextNumber));
        }
        else if(nextCommand == "push_middle"){
            std::map<float, int>::iterator it = teque.find(mid);
            if(teque.size() % 2 == 0){
                std::cout << "fine1" << std::endl;
                mid = (it->first + (it--)->first) / 2;
            }
            else
            {
                if(it != teque.begin()){
                    std::cout << "fine2" << std::endl;
                    mid = (it->first + (it++)->first) / 2;
                }
                else
                {
                    std::cout << "fine3" << std::endl;
                    mid = it->first / 2;
                }
            }
            
            std::cout << "mid" << mid << nextNumber << std::endl;
            teque.insert(std::pair<float, int>(mid, nextNumber));
        }
        else if(nextCommand == "get"){
            std::cout << teque[nextNumber] << std::endl;
        }
    }
}