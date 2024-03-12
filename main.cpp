#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setMark(vector<vector<int>> ttt), printT(vector<vector<int>> &ttt);

int main(){
    vector<vector<int>> ttt(3, vector<int> (3));

    for (int i = 0; i < ttt.size(); i++)
    {
        for(int j = 0; j < ttt[i].size(); j++){
            ttt[i][j] = 0;
        }
        for(int j = 0; j < ttt[i].size(); j++){
            cout << ttt[i][j] << " ";
        }
        
        cout << endl;
    }

    setMark(ttt);
    
    return 0;
}

void printT(vector<vector<int>> &ttt){
    system("cls");
    for(int i=0; i < ttt.size(); i++){
        for(int j = 0; j < ttt[i].size(); j++){
            cout << ttt[i][j] << " ";
        }
        cout << endl;
    }
}

void setMark(vector<vector<int>> ttt){
    int whereMarkX;
    int whereMarkY;
    cin >> whereMarkX >> whereMarkY;
    whereMarkX--;
    whereMarkY--;
    ttt[whereMarkX][whereMarkY] = 1;
    printT(ttt);
}