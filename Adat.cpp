#include "Adat.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include  <time.h>
using namespace std;


Adat::Adat() {}

Adat::~Adat() {}

void Adat:: read() {
    string help = "";
    ifstream f("alap.txt");
    while(f.good()) {
        getline(f,help);
        vector<string>line;
        for(unsigned int i=0; i<help.length(); i++) {
            string s="";
            s += help[i];
            line.push_back(s);
        }
        n.push_back(line);
        line.clear();
    }
}

void Adat::mix() {
    srand(time(0));
    std::string s1;
    int line1 = rand()%2;
    int line2 = rand()%2+3;
    int line3 = rand()%2+6;
    int oszlop1 = rand()%2;
    int oszlop2 = rand()%2+3;
    int oszlop3 = rand()%2+6;

    switch(line1) {
    case 0:
        for(int i=0; i<9; i++) {
            s1=n[1][i];
            n[1][i]=n[2][i];
            n[2][i]=s1;
        }
        break;
    case 1:
        for(int i=0; i<9; i++) {
            s1=n[0][i];
            n[0][i]=n[2][i];
            n[2][i]=s1;
        }
        break;
    case 2:
        for(int i=0; i<9; i++) {
            s1=n[0][i];
            n[0][i]=n[1][i];
            n[1][i]=s1;
        }
        break;
    }
    switch(line2) {
    case 3:
        for(int i=0; i<9; i++) {
            s1=n[4][i];
            n[4][i]=n[5][i];
            n[5][i]=s1;
        }
        break;
    case 4:
        for(int i=0; i<9; i++) {
            s1=n[3][i];
            n[3][i]=n[5][i];
            n[5][i]=s1;
        }
        break;
    case 5:
        for(int i=0; i<9; i++) {
            s1=n[3][i];
            n[3][i]=n[4][i];
            n[4][i]=s1;
        }
        break;
    }
    switch(line3) {
    case 6:
        for(int i=0; i<9; i++) {
            s1=n[7][i];
            n[7][i]=n[8][i];
            n[8][i]=s1;
        }
        break;
    case 7:
        for(int i=0; i<9; i++) {
            s1=n[6][i];
            n[6][i]=n[8][i];
            n[8][i]=s1;
        }
        break;
    case 8:
        for(int i=0; i<9; i++) {
            s1=n[6][i];
            n[6][i]=n[7][i];
            n[7][i]=s1;
        }
        break;
    }
    switch(oszlop1) {
    case 0:
        for(int i=0; i<9; i++) {
            s1=n[i][1];
            n[i][1]=n[i][2];
            n[i][2]=s1;
        }
        break;
    case 1:
        for(int i=0; i<9; i++) {
            s1=n[i][0];
            n[i][0]=n[i][2];
            n[i][2]=s1;
        }
    case 2:
        for(int i=0; i<9; i++) {
            s1=n[i][0];
            n[i][0]=n[i][1];
            n[i][1]=s1;
        }
        break;
    }
    switch(oszlop2) {
    case 3:
        for(int i=0; i<9; i++) {
            s1=n[i][4];
            n[i][4]=n[i][5];
            n[i][5]=s1;
        }
        break;
    case 4:
        for(int i=0; i<9; i++) {
            s1=n[i][3];
            n[i][3]=n[i][5];
            n[i][5]=s1;
        }
        break;
    case 5:
        for(int i=0; i<9; i++) {
            s1=n[i][3];
            n[i][3]=n[i][4];
            n[i][4]=s1;
        }
        break;
    }
    switch(oszlop3) {
    case 6:
        for(int i=0; i<9; i++) {
            s1=n[i][7];
            n[i][7]=n[i][8];
            n[i][8]=s1;
        }
        break;
    case 7:
        for(int i=0; i<9; i++) {
            s1=n[i][6];
            n[i][6]=n[i][8];
            n[i][8]=s1;
        }
        break;
    case 8:
        for(int i=0; i<9; i++) {
            s1=n[i][6];
            n[i][6]=n[i][8];
            n[i][8]=s1;
        }
        break;
    }

vector<vector<string> >help_matrix= n;
    for(unsigned int i = 0; i < n.size(); i++){
        for(unsigned int j = 0; j < n.size(); j++){
            n[i][j] = help_matrix[j][i];
        }
    }
}

vector<vector<string>> Adat:: make(){
read();
srand(time(0));
int numb=rand()%7;
for(int i=0;i<numb;i++){
    mix();
}
return n;
}
