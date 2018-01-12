#include <iostream>

using namespace std;

const int MAXN = 1000;

struct Auto {
    string nev;
    int start;
    int vege;
};

void beolvas(int &N, Auto autokolcsonzes[MAXN]) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> autokolcsonzes[i].nev >> autokolcsonzes[i].start >> autokolcsonzes[i].vege;
    }
}

int A_feladat(const int &N, Auto autokolcsonzes[MAXN]) {
    int s = 0;
    for(int i = 0; i < N; ++i) {
        s += autokolcsonzes[i].vege - autokolcsonzes[i].start + 1;
    }
    return s;
}

string B_feladat(const int &N, Auto autokolcsonzes[MAXN]) {
    int maxInd = 0;
    int maxErt = 0;
    string seged[MAXN];
    int segedDB = 0;
    int j = 0;
    for(int i = 0; i < N; ++i) {
        j = 0;
        while(j < segedDB && seged[j] != autokolcsonzes[i].nev) j++;
        if(j == segedDB) {
            seged[segedDB] = autokolcsonzes[i].nev;
            segedDB++;
            int s = 0;
            for(int z = 0; z < N; ++z) {
                if(autokolcsonzes[i].nev == autokolcsonzes[z].nev) s += autokolcsonzes[z].vege - autokolcsonzes[z].start + 1;
            }
            if(maxErt < s) {
                maxInd = j;
                maxErt = s;
            }
        }
    }
    return seged[maxInd];
}

int C_feladat(const int &N, Auto autokolcsonzes[MAXN]) {
    int maxInd = 0;
    int maxErt = 0;
    int s = 0;
    for(int i = 0; i < 30; ++i) {
        s = 0;
        for(int j = 0; j < N; ++j) {
            if(autokolcsonzes[j].start <= i + 1  && i + 1 <= autokolcsonzes[j].vege) s++;
        }
        if(maxErt < s) {
            maxErt = s;
            maxInd = i + 1;
        }
    }
    return maxInd;
}

void D_feladat(const int &N, Auto autokolcsonzes[MAXN]) {
    int maxErt = 0;
    int s = 0;
    for(int i = 0; i < N; ++i) {
        if(autokolcsonzes[i].start <= 1 && 1 <= autokolcsonzes[i].vege) maxErt++;
    }
    for(int i = 1; i < 30; ++i) {
        s = 0;
        for(int j = 0; j < N; ++j) {
            if(autokolcsonzes[j].start <= i + 1 && i + 1 <= autokolcsonzes[j].vege) s++;
        }
        if(maxErt < s) {
            maxErt = s;
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

void E_feladat(const int &N, Auto autokolcsonzes[MAXN]) {
    int maxInd = 0;
    int maxErt = 0;
    string seged[MAXN];
    int segedDB = 0;
    int j = 0;
    for(int i = 0; i < N; ++i) {
        j = 0;
        while(j < segedDB && seged[j] != autokolcsonzes[i].nev) j++;
        if(j == segedDB) {
            seged[segedDB] = autokolcsonzes[i].nev;
            segedDB++;
            int s = 0;
            int k = 0;
            for(int z = 0; z < N; ++z) {
                if(autokolcsonzes[i].nev == autokolcsonzes[z].nev) {
                    s += autokolcsonzes[z].vege - autokolcsonzes[z].start + 1;
                    k++;
                }
            }
	    cout << autokolcsonzes[i].nev << " " << k << " " << s << endl;
        }
    }
}

int main() {
    int N;
    Auto autokolcsonzes[MAXN];
    beolvas(N, autokolcsonzes);
    cout << "#" << endl;
    cout << A_feladat(N, autokolcsonzes) << endl;
    cout << "#" << endl;
    cout << B_feladat(N, autokolcsonzes) << endl;
    cout << "#" << endl;
    cout << C_feladat(N, autokolcsonzes) << endl;
    cout << "#" << endl;
    D_feladat(N, autokolcsonzes);
    cout << "#" << endl;
    E_feladat(N, autokolcsonzes);
}
