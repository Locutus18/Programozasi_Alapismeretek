# Minta Zárthelyi

## ZH Minta 1
Egy pizzéria felkért minket, hogy segítsünk kitalálni nekik, hogy melyik napon lenne érdemes fejleszteni (tovább nyitvatartani vagy több felszolgálót behívni). Ennek a eldöntéséhez feljegyezték, hogy mennyi bevételük volt az elmúlt napok folyamán. Úgy gondolják, hogy ha az alábbi kérdésekre válaszolunk akkor az nekik most megfelelő lesz:
* Számoljuk meg az 1 napra eső átlagos forgalmat.
* Döntsük el, hogy egy nap volt-e legalább 3 vétel.
* Határozzuk meg a legnagyobb átlagos forgalmat, ahol volt legalább 3 vétel.

#### Segítség:
Használjunk egy struct-ot, aminek két eleme van, az egyik egy int N, a másik pedig egy tömb ami maximum 1000 elemet tartalmazhat. Ez ugyebár a egy napot fog definiálni. A main()-ben pedig definiáljunk egy tömböt ami napot tartalmaz azok lesznek a napok és annak ismételten a maximum értéke 1000 lehet.

### Bemenet

Bemenő adatként a pizzéria egy nagy fájlt fog nekünk adni, az elmúlt x nap bevételeiből, úgy hogy az első rekord hétfői (majd kedd, szerda és vasárnap utána ismét hétfő).
A fájl a feljegyzett napok számával kezdődik majd sorban 1-1 nap bevételeinek a felsorolása, úgy hogy elősször megadjuk hogy az adott napon mennyiszer volt bevétel, majd a bevételek értékeit sorban.
```
10
3 500 1000 2000
2 1000 1200
3 1200 1000 500
1 500
1 200
0
3 5000 5000 10000
1 200
2 500 1000 
1 500
```
### Output Feladatonként:

* Az első feladatban kell definiálni egy függvényt, aminek paraméterei között szerepel egy szám, amely segítségével megadhatjuk, hogy hanyadik nap átlagos forgalmát akarjuk meghatározni. Például:
```
//output: 900 //(1200+1000+500) / 3
std::cout << A_feladat(napok,3) << std::endl;
```

* A második feladatban is hasonlóan járjunk el mint az első feladatban. Legyen egy szám amely, segítségével megadjuk, hogy hanyadik napról akarjuk eldönteni, hogy volt-e legalább 3 vétel. Például:
```
//output: 0
std::cout << B_feladat(napok, 4) << std::endl;
```

* A harmadik feladatnak már nincs plusz bemenő paramétere. A harmadik feladat egy index értékkel fog visszatérni amire igaz.
A fenti példa megoldása:
```
7
```

### Tudnivalók

https://github.com/Hudi89/prog/blob/master/06-zh/main.md
