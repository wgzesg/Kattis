#include <iostream>

using namespace std;
void mergeSort(string name[], int start, int end, int mid);
void merge(string name[], int start, int end, int mid);
void printList(string name[], int no_of_names);


int main(void){
    int no_of_names = 0;
    cin >> no_of_names;
    while(no_of_names != 0){
        string name[no_of_names];
        for(int i = 0; i < no_of_names; i++){
            cin >> name[i];
        }
        mergeSort(name, 0, no_of_names, no_of_names / 2);
        printList(name, no_of_names);
        cin >> no_of_names;
    }
}

void mergeSort(string name[], int start, int end, int mid){
    if(end - start <= 1){
        return;
    }
    else{
        mergeSort(name, start, mid, (start + mid) / 2);
        mergeSort(name, mid, end, (end + mid) / 2);
        merge(name, start, end, mid);
    }
}

void merge(string name[], int start, int end, int mid){
    int left = start;
    int right = mid;
    string temp[end - start];
    int tempidx = 0;
    while(left < mid && right < end){
        if(name[left][0] < name[right][0]){
            temp[tempidx++] = name[left++];
        }
        else if(name[left][0] > name[right][0]){
            temp[tempidx++] = name[right++];
        }
        else{
            if(name[left][1] <= name[right][1]){
                temp[tempidx++] = name[left++];
            }
            else if(name[left][1] > name[right][1]){
                temp[tempidx++] = name[right++];
            }
        }
    }
    while(left < mid)
        temp[tempidx++] = name[left++];
    while(right < end)
        temp[tempidx++] = name[right++];
    for (int k = start; k < end; k++)
        name[k] = temp[k - start];
}

void printList(string name[], int no_of_names){
    for(int i = 0; i < no_of_names; i ++){
        cout << name[i] << endl;
    }
}
