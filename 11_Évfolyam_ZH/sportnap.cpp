#include <iostream>

using namespace std;

const int MAXN = 500;
const int MAXS = 40;

struct Sportolo {
    string nev;
    int nevSzam;
};

void beolvas(int &S, int &N, Sportolo sportnap[MAXN]) {
    cin >> S >> N;
    for(int i = 0; i < N; ++i) {
        cin >> sportnap[i].nev >> sportnap[i].nevSzam;
    }
}

string A_feladat(const int &N, Sportolo sportnap[MAXN]) {
    int i = 0;
    int j = 0;
    while(i < N) {
        j = 0;
        while(j < N && (sportnap[i].nev != sportnap[j].nev || i == j)) {
	    j++;
        }
        if(j == N) return sportnap[i].nev;
        i++;
    }
    return "";
}

int seged_B(const int &N, Sportolo sportnap[MAXN], const string &nev) {
    int s = 0;
    for(int j = 0; j < N; ++j) {
        if(nev == sportnap[j].nev) s++;
    }
    return s;
}

string B_feladat(const int &N, Sportolo sportnap[MAXN]) {
    string kiv[N];
    int ind = 0;
    int maxInd = 0;
    int kivDB = 0;
    int j = 0;   
    for(int i = 0; i < N; ++i) {
        j = 0;
        while(j < kivDB && kiv[j] != sportnap[i].nev) {
            j++;
        }
        if(j == kivDB) {
            kiv[kivDB] = sportnap[i].nev;
            if(seged_B(N, sportnap, kiv[maxInd]) < seged_B(N, sportnap, kiv[kivDB])) {
                maxInd = kivDB;
                
            }
            kivDB++;
        }
    }
    return kiv[maxInd];
}

void C_feladat(const int &S, const int &N, Sportolo sportnap[MAXN]) {
    int res[S];
    for(int i = 0; i < S; ++i) res[i] = 0;
    for(int i = 0; i < N; ++i) {
        res[sportnap[i].nevSzam-1]++;
    }
    for(int i = 0; i < S; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void D_feladat(const int &S, const int &N, Sportolo sportnap[MAXN]) {
    for(int i = 1; i <= S; ++i) {
        for(int j = i + 1; j <= S; ++j) {
            string kiv1[N];
            int kivDB1 = 0;
            for(int z = 0; z < N; ++z) {
                if(sportnap[z].nevSzam == i) {
                    kiv1[kivDB1] = sportnap[z].nev;
                    kivDB1++;
                }
            }
            string kiv2[N];
            int kivDB2 = 0;
            for(int z = 0; z < N; ++z) {
                if(sportnap[z].nevSzam == j) {
                    kiv2[kivDB2] = sportnap[z].nev;
                    kivDB2++;
                }
            }
            bool l = false;
            int z = 0;
            int z1 = 0;
            while(z < kivDB1 && !l) {
                z1 = 0;
                while(z1 < kivDB2 && !l) {
                    if(kiv1[z] == kiv2[z1]) l = true;
                    z1++;
                }
                z++;
            }
            if(!l) cout << i << " " << j << endl;
        }
    }
}

int seged_E(const int &S, const int &N, Sportolo sportnap[MAXN], const string &nev) {
    int kiv[N];
    int kivDB = 0;
    for(int i = 0; i < N; ++i) {
        if(sportnap[i].nev == nev) {
            kiv[kivDB] = sportnap[i].nevSzam;
            kivDB++;
        }
    }
    int s = 0;
    int j = 0;
    int z = 0;
    string kiv2[N];
    int kivDB2 = 0;
    for(int i = 0; i < N; ++i) {
        j = 0;
        z = 0;
        if(nev == sportnap[i].nev) continue;
        while(z < kivDB2 && kiv2[z] != sportnap[i].nev) z++;
        if(z != kivDB2) continue;
        while(j < kivDB && kiv[j] != sportnap[i].nevSzam) j++;
        if(j < kivDB) {
            kiv2[kivDB2] = sportnap[i].nev;
            kivDB2++;
            s++;
        }
    }
    return s;
}

void E_feladat(const int &S, const int &N, Sportolo sportnap[MAXN]) {
    string kiv[N];
    int kivDB = 0;
    int j = 0;
    for(int i = 0; i < N; ++i) {
        j = 0;
        while(j < kivDB && sportnap[i].nev != kiv[j]) j++;
        if(j == kivDB) {
            kiv[kivDB] = sportnap[i].nev;
            cout << kiv[kivDB] << " " << seged_E(S,N,sportnap,kiv[kivDB]) << endl;
            kivDB++;
        }
    }
}

int main()
{
    int S,N;
    Sportolo sportnap[MAXN];
    beolvas(S,N,sportnap); 
    cout << "#" << endl;
    cout << A_feladat(N, sportnap) << endl;
    cout << "#" << endl;
    cout << B_feladat(N, sportnap) << endl;
    cout << "#" << endl;
    C_feladat(S,N,sportnap);
    cout << "#" << endl;
    D_feladat(S,N,sportnap);
    cout << "#" << endl;
    E_feladat(S,N,sportnap);
}
