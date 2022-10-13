#include <iostream>
#include "vector"

using namespace std;

// by @YoussefMoataz
struct dominoT {
    int leftDots;
    int rightDots;

    dominoT(int ld, int rd) {
        leftDots = ld;
        rightDots = rd;
    }
};

// by @YoussefMoataz
vector<dominoT> dominoPieces;
vector<dominoT> temp;
int mainSize;

// by @Seif-Ibrahim1
bool solve(vector<dominoT> &dominos) {
    
    for(int i = 0; i < mainSize; i++) {
        if(dominos.size() == 0) {
                return true;
        } else {
            if(temp.front().leftDots == dominos[i].rightDots) {
                temp.insert(temp.begin(), dominos[i]);
                dominos.erase(dominos.begin() + i);
                i--;
                solve(dominos);
            }
            if(temp.back().rightDots == dominos[i].leftDots) {
                temp.insert(temp.end(), dominos[i]);
                dominos.erase(dominos.begin() + i);
                i--;
                solve(dominos);
            }
        }
    }
    
    return false;
}

int main() {

    // by @YoussefMoataz
    dominoPieces.push_back(dominoT(1, 4));
    dominoPieces.push_back(dominoT(2, 6));
    dominoPieces.push_back(dominoT(4, 4));
    dominoPieces.push_back(dominoT(6, 1));
    dominoPieces.push_back(dominoT(4, 3));

    mainSize = dominoPieces.size();
    temp.push_back(dominoPieces[0]);
    dominoPieces.erase(dominoPieces.begin());


    if (solve(dominoPieces)) {
        cout << "Done" << endl;

        for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i].leftDots << "|" << temp[i].rightDots;
        if(i != temp.size() - 1) {
            cout << " - ";
        }
    }
    cout << endl;

    } else {
        cout << "Failed" << endl;
    }

 
    return 0;
}