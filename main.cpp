#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setMarkPlayerOne(vector<vector<int>> &ttt), printT(vector<vector<int>> &ttt), setMarkPlayerTwo(vector<vector<int>> &ttt);
bool isPlayerOneWinner(vector<vector<int>> &ttt), isPlayerTwoWinner(vector<vector<int>> &ttt);

int main(){
    vector<vector<int>> ttt(3, vector<int> (3));

    for (int i = 0; i < ttt.size(); i++)
    {
        for(int j = 0; j < ttt[i].size(); j++){
            ttt[i][j] = 0;
        }        
        cout << endl;
    }

    printT(ttt);

    while(true){
        
        setMarkPlayerOne(ttt);
        if(isPlayerOneWinner(ttt) || isPlayerTwoWinner(ttt)){
            break;
        }

        setMarkPlayerTwo(ttt);
        if(isPlayerOneWinner(ttt) || isPlayerTwoWinner(ttt)){
            break;
        }
    }

    if(isPlayerOneWinner(ttt)){
        cout << "Spieler 2 ist ein Loser\n";
    }else{
        cout << "Spieler 1 ist ein Loser\n";
    }
    
    return 0;
}

void printT(vector<vector<int>> &ttt){
    system("cls");
    cout << "      Spalte" << endl;
    for(int i=0; i < ttt.size(); i++){
        cout << "Reihe ";
        for(int j = 0; j < ttt[i].size(); j++){
            cout << ttt[i][j] << " ";
        }
        cout << endl << endl;
    }
}

bool isPlayerOneWinner(vector<vector<int>> &ttt){
    bool isLineEqual = false; 
    for(int i = 0; i < ttt.size(); i++){
        for(int j = 0; j < ttt[i].size(); j++){
            if(ttt[i][j] == 1){
                isLineEqual = true;
            }else{
                isLineEqual = false;
                break;
            }
        }
        if(isLineEqual == true){
            return true;
        }
    }

    for(int i = 0; i < ttt.size(); i++){
        for(int j = 0; j < ttt[i].size(); j++){
            if(ttt[j][i] == 1){
                isLineEqual = true;
            }else{
                isLineEqual = false;
                break;
            }
        }
        if(isLineEqual == true){
            return true;
        }
    }

    for(int i = 0; i < ttt.size(); i++){
        if(ttt[i][i] == 1){
            isLineEqual = true;
        }else{
            isLineEqual = false;
            break;
        }
    }
    if(isLineEqual == true){
        return true;
    }

    for(int i = ttt.size() - 1; i >= 0; i--){
        if(ttt[ttt.size() - i - 1][i] == 1){ 
            isLineEqual = true;
        }else{
            isLineEqual = false;
            break;
        }
    }
    if(isLineEqual == true){
        return true;
    }

    return false;
}

bool isPlayerTwoWinner(vector<vector<int>> &ttt){
    bool isLineEqual = false; 
    for(int i = 0; i < ttt.size(); i++){
        for(int j = 0; j < ttt[i].size(); j++){
            if(ttt[i][j] == 2){
                isLineEqual = true;
            }else{
                isLineEqual = false;
                break;
            }
        }
        if(isLineEqual == true){
            return true;
        }
    }

    for(int i = 0; i < ttt.size(); i++){
        for(int j = 0; j < ttt[i].size(); j++){
            if(ttt[j][i] == 2){
                isLineEqual = true;
            }else{
                isLineEqual = false;
                break;
            }
        }
        if(isLineEqual == true){
            return true;
        }
    }

    for(int i = 0; i < ttt.size(); i++){
        if(ttt[i][i] == 2){
            isLineEqual = true;
        }else{
            isLineEqual = false;
            break;
        }
    }
    if(isLineEqual == true){
        return true;
    }

    for(int i = ttt.size() - 1; i >= 0; i--){
        if(ttt[ttt.size() - i - 1][i] == 2){ 
            isLineEqual = true;
        }else{
            isLineEqual = false;
            break;
        }
    }
    if(isLineEqual == true){
        return true;
    }

    return false;
}

void setMarkPlayerOne(vector<vector<int>> &ttt){
    int whereMarkX;
    int whereMarkY;
    do{
        printT(ttt);
        cout << "Spieler 1 - Gib die Reihe ein: (1; 2; 3)" << endl;
        cin >> whereMarkX;
        cout << "Spieler 1 - Gib die Spalte ein: (1; 2; 3)" << endl;
        cin >> whereMarkY;
        whereMarkX--;
        whereMarkY--;
    }while(ttt[whereMarkX][whereMarkY] != 0);
    
    ttt[whereMarkX][whereMarkY] = 1;
    printT(ttt);
}

void setMarkPlayerTwo(vector<vector<int>> &ttt){
    int whereMarkX;
    int whereMarkY;
    do{
        printT(ttt);
        cout << "Spieler 2 - Gib die Reihe ein: (1; 2; 3)" << endl;
        cin >> whereMarkX;
        cout << "Spieler 2 - Gib die Spalte ein: (1; 2; 3)" << endl;
        cin >> whereMarkY;
        whereMarkX--;
        whereMarkY--;
    }while(ttt[whereMarkX][whereMarkY] != 0);
    ttt[whereMarkX][whereMarkY] = 2;
    printT(ttt);
}