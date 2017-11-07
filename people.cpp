#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

const int MAXN = 1000;

struct Person {
    string name;
    string neptun_kod;
    int old;
    bool monkey;
};

void beolvas_Console(int &N, Person people[MAXN]) {
    bool hiba = false;
    do {
        cout << "Kerem a tomb meretet: ";
        cin >> N;
        hiba = N < 0 || cin.fail();
        if(hiba) {
            cout << "Hiba" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while(hiba);
    for(int i = 0; i < N; ++i) {
        Person person;
        // Nev beolvasasa
        cout << "Kerem az " << i << ".edik nevet: ";
        cin >> person.name;
        // Netun kod beolvasasa
        do {
            cout << "Kerem az " << i << ".edik neptun kodot: ";
            cin >> person.neptun_kod;
            hiba = (person.neptun_kod.size() != 6);
            if(hiba) {
                cout << "Kerem adjon meg helyes neptun kodot.";
            }
        } while(hiba);
        do {
            cout << "Kerem az " << i << ".edik kort: ";
            cin >> person.old;
            hiba = person.old < 16 || cin.fail();
            if(hiba) {
                cout << "Hiba" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while(hiba);
        char temp;
        do {
            cout << "Kerem az " << i << ".edik embernek van-e majma: ";
            cin >> temp;
            hiba = !(toupper(temp) == 'I' || toupper(temp) == 'Y' || toupper(temp) == 'N') || cin.fail();
            if(hiba) {
                cout << "Hiba" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        } while(hiba);
        if(toupper(temp) == 'I' || toupper(temp) == 'Y') {
            person.monkey = true;
        } else {
            person.monkey = false;
        }
        people[i] = person;
    }
}

void beolvas_File(int &N, Person people[MAXN]) {
    fstream fin;
    bool hiba;
    string filename;
    do {
        cout << "Kerem a file nevet: ";
        cin >> filename;
        fin.open(filename.c_str());
        hiba = !fin.is_open();
        if(hiba) {
            cout << "Hiba a file megnyitasakor" << endl;
        }
    } while(hiba);
    fin >> N;
    for(int i = 0; i < N; ++i){
        Person person;
        string firstname;
        getline(fin, firstname, ' ');
        firstname = firstname.substr(1, firstname.size());
        fin >> person.name >> person.neptun_kod >> person.old >> person.monkey;
        person.name = firstname + " " + person.name;
        people[i] = person;
    }
}

void debug(const int &N, const Person people[MAXN] ) {
    cout << "Debug" << endl;
    for(int i = 0; i < N; ++i) {
        cout << people[i].name << " " << people[i].neptun_kod << " " << people[i].old;
        cout << " " << people[i].monkey << endl;
    }
    cout << endl;
}

double atlagKor(const int &N, const Person people[MAXN]) {
    double s = 0;
    for(int i = 0; i < N; ++i) {
        s += people[i].old;
    }
    double atlag = s / N;
    return atlag;
}

Person kivalasztas(const int &N, const Person people[MAXN]) {
    Person temp;
    for(int i = 0; i < N; ++i) {
        if(people[i].old > 20 && people[i].monkey) {
            temp = people[i];
        }
    }
    return temp;
}

int main()
{
    int N;
    Person people[MAXN];
    beolvas_File(N, people);
    debug(N, people);
    cout << "Atlagkor : " << atlagKor(N, people) << endl;
    cout << "Ember neve: " << kivalasztas(N, people).name << endl;
    return 0;
}
