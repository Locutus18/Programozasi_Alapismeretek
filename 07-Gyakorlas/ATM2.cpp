#include <iostream>
#include <fstream>

using namespace std;

struct Person
{
    int id;
    string nev;
    int befizNum;
    int befiz[100];

    int getMoney() const {
        int s = 0;
        for(int j = 0; j < befizNum; ++j) {
            s += befiz[j];
        }
        return s;
    }

};

struct ATM
{
    Person data[100];
};

//Deklaráció
void beolvas_file(int& N, ATM& atm);
void kiir(const int& N,const ATM& atm);
int A_feladat(const int& N, const ATM& atm);
int B_feladat(const int& N, const ATM& atm);
bool C_feladat(const int& N,const ATM& atm);
int D_feladat(const int& N, const ATM& atm);
void E_feladat(const int& N, const ATM& atm);
Person F_feladat(const int& N, const ATM& atm);

int main()
{
    ATM atm1;
    int N;
    beolvas_file(N, atm1);
    kiir(N, atm1);
    cout << endl;
    cout << "Jelenlegi keszpenz: " << A_feladat(N, atm1) << endl;
    cout << "10.000 forint feletti penzek szama: " << B_feladat(N, atm1) << endl;
    cout << "Van-e Bela nevű ember?: " << C_feladat(N, atm1) << endl;
    cout << "Valasszuk ki Mark-ot: " << atm1.data[D_feladat(N, atm1)].id << endl;
    E_feladat(N, atm1);
    cout << "Adjuk meg a legtobb penz birtokosat : " << F_feladat(N, atm1).nev << endl;
    return 0;
}

//Definíció
void kiir(const int& N, const ATM& atm)
{
    for(int i = 0; i < N; ++i)
    {
        cout << atm.data[i].id << " ";
        cout << atm.data[i].nev << " ";
        for(int j = 0; j < atm.data[i].befizNum; ++j) {
            cout << atm.data[i].befiz[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void beolvas_file(int& N, ATM& atm)
{
    string filename;
    fstream fin;
    bool hiba;
    do
    {
        cout << "Kerem a file nevet: ";
        cin >> filename;
        fin.open(filename.c_str());
        hiba = !fin.is_open();
        if(hiba)
        {
            cout << "Hiba a file megnyitasakor" << endl;
        }
    }
    while(hiba);
    fin >> N;
    for(int i = 0; i < N; ++i)
    {
        fin >> atm.data[i].id >> atm.data[i].nev;
        fin >> atm.data[i].befizNum;
        for(int j = 0; j < atm.data[i].befizNum; ++j) {
            fin >> atm.data[i].befiz[j];
        }
    }
}

int A_feladat(const int& N, const ATM& atm)
{
    int s = 0;
    for(int i = 0; i < N; ++i)
    {
        s += atm.data[i].getMoney();
    }
    return s;
}

int B_feladat(const int& N, const ATM& atm)
{
    int c = 0;
    for(int i = 0; i < N; ++i)
    {
        if(atm.data[i].getMoney() >= 10000)
        {
            c++;
        }
    }
    return c;
}

bool C_feladat(const int& N,const ATM& atm)
{
    int i = 0;
    while( i < N && atm.data[i].nev != "Bela")
    {
        i++;
    }
    if(i < N) return true;
    else return false;
}

int D_feladat(const int& N, const ATM& atm)
{
    int i = 0;
    while( i < N && atm.data[i].nev != "Mark")
    {
        i++;
    }
    return i;
}

void E_feladat(const int& N, const ATM& atm)
{
    int i = 0;
    while( i < N && atm.data[i].nev != "Bela")
    {
        i++;
    }
    if(i < N)
    {
        cout << "Keresett ertek " << atm.data[i].id << endl;
    }
    else
    {
        cout << "Keresett ertek nem talalhato!" << endl;
    }
}

Person F_feladat(const int& N, const ATM& atm) {
    Person maxP = atm.data[0];
    for(int i = 0; i < N; ++i) {
        if(maxP.getMoney() < atm.data[i].getMoney()) {
            maxP = atm.data[i];
        }
    }
    return maxP;
}
