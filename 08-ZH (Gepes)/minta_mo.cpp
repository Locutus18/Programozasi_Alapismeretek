#include <iostream>

using namespace std;

const int MAXN = 100;

struct Nap {
    int N;
    int vetel[MAXN];
};

void beolvas_console(int &N, Nap napok[MAXN]) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> napok[i].N;
        for(int j = 0; j < napok[i].N; ++j) {
            cin >> napok[i].vetel[j];
        }
    }
}

void debug(int &N, Nap napok[MAXN]) {
    cout << N << endl;
    for(int i = 0; i < N; ++i) {
        cout << napok[i].N << " ";
        for(int j = 0; j < napok[i].N; ++j) {
            cout << napok[i].vetel[j] << " ";
        }
        cout << endl;
    }
}

float A_feladat(Nap napok[MAXN], int k) {
    float res = 0;
    for(int i = 0; i < napok[k-1].N; ++i) {
        res += napok[k-1].vetel[i];
    }
    return (res / napok[k-1].N);
}

bool B_feladat(Nap napok[MAXN], int k) {
    //Egyszerű megoldás:
    return napok[k].N >= 3;
}

int C_feladat(Nap napok[MAXN], int N) {
    int maxR = -1;
    bool l = false;
    for(int i = 0; i < N; ++i) {
        if(!l && B_feladat(napok,i)) {
            maxR = i;
            l = true;
        } else if(l && B_feladat(napok,i)) {
            if(A_feladat(napok,maxR+1) < A_feladat(napok,i+1)) {
                maxR = i;
            }
        }
    }
    return maxR+1;
}

int main()
{
    int N;
    Nap napok[MAXN];
    beolvas_console(N, napok);
    //debug(N, napok);
    cout << A_feladat(napok,3) << endl;
    cout << B_feladat(napok,4) << endl;
    cout << C_feladat(napok,N) << endl;
    return 0;
}
