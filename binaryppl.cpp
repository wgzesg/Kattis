#include <iostream> //include all library
using namespace std; //cpp special
#define MAX 1000

void readmap(char map[][MAX], int &row, int &col);
int findpath(char map[][MAX], int region[][MAX], int y1, int x1, int y2, int x2);
void convertmap(char map[][MAX], int region[][MAX], int r, int c);
void printMap(int map[][MAX], int r, int c);
int color(char map[][MAX], int region[][MAX], int i, int j, int label, int r, int c);

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int r,c;
    char map[MAX][MAX];
    int region[MAX][MAX] = {0};
    readmap(map, r, c);
    convertmap(map, region, r, c);

    int rounds; cin >> rounds;
    for(int i = 0; i < rounds; i ++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int path = findpath(map, region, y1, x1, y2, x2);
        switch (path)
        {
        case 1:
            cout << "decimal" << "\n";
            break;
        case 0:
            cout << "binary" << "\n";
            break;
        
        default:
            cout << "neither" << "\n";
            break;
        }
    }
}

void readmap(char map[][MAX], int &row, int &col){
    cin >> row >> col;
    char waste;
    for(int i = 0; i < row; i ++){
        cin >> map[i];
        if(map[i][col] == '\n'){
            map[i][col] = '\0';
        }
    }
}

void convertmap(char map[][MAX], int region[][MAX], int r, int c){
    int label = 0;
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j ++){
            if (region[i][j] == 0){
                label ++;
                region[i][j] = label;
                color(map, region, i+1, j, label, r, c);
                color(map, region, i, j+1, label, r, c);
            }
        }
    }
}

int color(char map[][MAX], int region[][MAX], int i, int j, int label, int r, int c){
    if (i < 0 || j < 0 || i >= r || j >= c){
        return 0;
    }
    if(region[i][j] != 0){
        return 0;
    }
    if(map[i][j] == map[i - 1][j] && region[i - 1][j] != 0 && (i - 1) >= 0){
        region[i][j] = region[i - 1][j];
    }
    else if(map[i][j] == map[i][j - 1] && region[i][j - 1] != 0 && (j - 1) >= 0){
        region[i][j] = region[i][j - 1];
    }
    else if(map[i][j] == map[i][j + 1] && region[i][j + 1] != 0 && (j + 1) < c){
        region[i][j] = region[i][j + 1];
    }
    else if(map[i][j] == map[i + 1][j] && region[i + 1][j] != 0 && (i + 1) < r){
        region[i][j] = region[i + 1][j];
    }
    else{ 
        return 0;
    }
    color(map, region, i + 1, j, label, r, c);
    color(map, region, i, j + 1, label, r, c);
    color(map, region, i - 1, j, label, r, c);
    color(map, region, i, j - 1, label, r, c);
    return 0;
}

void printMap(int map[][MAX], int r, int c){
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j ++){
            cout << map[i][j] << "  ";
        }
        cout << "\n";
    }
}

int findpath(char map[][MAX], int region[][MAX], int y1, int x1, int y2, int x2){
    if(region[y1 - 1][x1 - 1] == region[y2 - 1][x2 - 1]){
        if(map[y1 - 1][x1 - 1] == '1')
            return 1;
        else 
            return 0;
    }
    else{
        return -1;
    }
}