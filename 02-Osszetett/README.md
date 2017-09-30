# 2. Gyakorlat - ÖSszetett szerkezetű típusok

A típusszerkezetekkel egyszerűbb típusokból építhetünk fel összetett szerkezetű típusokat.

## Tömb

A tömb, mint adattípus az összetett adattípusok közé tartozik. A tömb valójában egy sorszámozott egyforma típusú elemeket tartalmazó halmaz. Halmaz alatt csak annyit értek, hogy több elemet tartalmaz, nem matematikai értelemben használjuk, itt ugyanis egy érték többször is előfordulhat a tömbben. A tömbök mérete (hogy hány elemet tartalmaz) középiskolai szinten lényegtelen, akkora tömbökkel nem dolgozunk, ami a túl nagy méret miatt problémát okozna. Ami viszont fontos: a tömb mérete csak egyszer adható meg, amikor deklaráljuk a tömböt. Vagyis ha megadtam, hogy ez egy 10 elemet tartalmazó tömb, akkor ezen később nem változtathatok. Különösen figyelni kell erre akkor, amikor nem tudod, hogy hány lemet szeretnél tárolni, akkor kénytelen vagy az elméleti maximális méretet beállítani, amit a feladat ad meg.

## Tömb elemei

Egy tömb, mint már említettem egy sorszámozott egyforma típusú elemeket tartalmazó halmaz. A sorszámozásnak fontos szerepe van, mert az elemek sorrendje - amíg meg nem változtatjuk - között. Mindenkinek megvan a saját azonosítója, amivel a tömbben elfoglalt pontos helyére hivatkozunk. Ezt nevezzük indexnek. A sorszám annyiban nem a legpontosabb elnevezés, hogy itt a sorszámozás - amit innentől nevezzünk indexelésnek - 0-val kezdődik.

Mivel minden tömbelem helye fix és a helyét az elem indexe adja meg, ezért lehet egy tetszőleges elemre hivatkozni a következő módon:

```c++
tomb[index]
```

Ez egy adott indexű helyen tárolt elem konkrét értékét adja vissza, és amíg direkt nem cserélgetjük össze az elemeket, vagy nem változtatjuk meg az értéküket, mindig ugyanazt az értéket adja. Így lehet például a tömb feltöltése közben az adott helyen lévő "tárolóban" értéket elhelyezni. Értelemszerűen az index legkisebb értéke 0 lehet (ez az első elem), a legnagyobb pedig a tömbméret-1 (ez az utolsó.)

Az indexnek minden esetben egy nem negatív egész számot kell megadni, de akkor honnan tudjuk, hogy melyik valóban az utolsó elem? Hogyan tudjuk a tömbméretét megkapni? Univerzállis megoldás az alap c++ tömbök méretének meghatározására nincs. A tömb méretét neked külön kell tárolnod, és használni, amikor arra szükség van. A későbbi példákból egyértelmű lesz, hogy hogyan. A tömb elemei közül vannak olyanok, melyeket jó, ha általános formában ismersz.

```c++
tomb[0] //mindig ez az első elem
tomb[meret-1] //mindig ez az utolsó
```

Fontos, hogy a tömbméret nem a tömbben általunk eltárolt elemek számát adja meg, mert az lehet kevesebb is, mint a tömb mérete. Például tudom, hogy legfeljebb 20 értéket akarok tárolni, akkor egy 20 elemű tömbre van szükségem. És ha csak 15-öt tároltam el? Akko az utolsó 5 üres lesz. Van ilyen. Illetve lesz benne valami, de hogy mi az tőlem független. A tömbméret tehát azt a darabszámot adja meg, amennyi elem maximálisan elfér a tömbben és nem a már eltárolt elemek számát. Ha nem használtuk ki a tömb teljes méretét, akkor nekünk kell külön nyilvántartani, hogy melyik az utolsó elem, amit mi helyeztünk el a tömbben. Hiszen utána is vannak elemek a tömbben, melyeknek még egyszer hangsúlyozom, nem tudjuk, mik az értékei.

Az alábbi példában egy 10 elemű tömböt hoztam létre, de nem töltöttem fel teljesen. A tömb mérete egyértelműen 10, de nekem nyilván kell tartanom az 5-ös értéket is, mert 5 elem van benne. Ezek közül a tomb[4] az utolsó, hiszen az indexelés 0-tól kezdődik. Így a tárolt 5-ös értékkel a tömb összes feltöltött eleme elérhető, így nem fogok továbbszaladni a kérdőjellel jelölt elemekre, melyek értéke ismeretlen, és nem is egyformák.

# TODO: példa

A lényeg: saját változóban tárold azt hogy hány elemet helyeztél el a tömbben. Legyen ez a változó mondjuk db nevű változó.

```c++
tomb[db-1] // ez az utolsó általam elheyezett elem
tomb[meret-1] // ez pedi a tömb utolsó eleme, ami ismeretlen kezdőérték
```

## Tömbök deklarálása

Előfordulhat, hogy a tömbnek már előre tudjuk a fix értékeit, és ezeket rögtön oda is adjuk neki kezdőértékként. Lássuk ezt hogyan lehet megtenni:

```c++
int tomb[5] = {1,2,3,4,5};
```

A fent megadott tömbnek megadtuk – kötelező jelleggel – hogy 5 eleme lesz, majd ezeket kezdőértékként a kötött formában felsoroljuk. Fontos, hogy több elemet nem adhatunk meg kezdőértékként, mint amekkora a tömb mérete. Ezt még a c++ is hibának veszi, pedig sok hibát lenyel. Kevesebbet viszont adhatunk! Lássuk:

```c++
int tomb[5] = {1,2};
```

Itt az 5 elemű tömbnek csak két értéket adtunk oda kezdőértékként. Ilyenkor az első két elem értéke a felsorolásnak megfelelő lesz, vagyis 1 és 2, a többi elem értéke pedig 0 lesz.

Alaphelyzetben, ha a tömbnek nem adunk kezdőértékeket, a c++ akkor is kiír valami értéket tömbelemként, amikor semmit nem adtunk meg neki. Nézzük az alábbi példát:

```c++
int tomb[3];

cout << tomb[0] << endl;
cout << tomb[1] << endl;
cout << tomb[2] << endl;
```

Ez a következő kimenetet adta:

4309664
2686868
4309758

A tömb még nem kapott kezdőértékeket, de valamit mutat, amelyek természetesen nem valós értékek, de hibát sem produkálnak! Hogyan lehetne akkor megadni, hogy a tömb legyen “üres”, vagyis ne az előzőekhez hasonló ismeretlen értékek legyenek benne, hanem mondjuk mindegyik 0 legyen. Gyakorlatilag ugyanúgy, mint amikor nem adjuk meg a méretének megfelelő összes kezdőértéket. Itt csak az elsőt adjuk meg, és az is 0 legyen:

```c++
int tomb[5] = {0};
```

Ebben a tömbben minden tömbelem 0 lesz, így talán átláthatóbb lesz, hogy melyik elemhez rendeltünk már hozzá értéket, és melyikhez nem. Természetesen itt ügyelni kell arra, hogy ha nem töltjük fel teljesen a tömböt, akkor nyilván kell tartani, hogy éppen hány elem van benne. Vegyük a következő példát:

```c++
int tomb[5] = {0}; // minden elem 0 kezdőértékkel rendelkezik

tomb[0] = 3;
tomb[1] = -5;
tomb[2] = 0;

cout << tomb[0] << " ";
cout << tomb[1] << " ";
cout << tomb[2] << " ";
cout << tomb[3] << " ";
cout << tomb[4] << " ";
```

Kimenetként a következőt láthatjuk:
3 -5 0 0 0

A gond az, hogy az alap 0 értékek és az általunk beállított 0 érték gyakorlatilag megkülönböztethetetlen. Akkor kezelhetjük ezt a problémát, ha tudjuk, hogy az 5 elemű tömbbe elhelyeztünk 3 elemet, mondjuk 3, -5, 0-át, és megjegyeztük, hogy jelenleg 3 elem van a tömbben. Így a 0-ák közül tudjuk, hogy az első általunk feltöltött elem, a többi pedig a tömb alapértékei.

Fordítási időben rögzített méretű, automatikus helyfoglalású egydimenziós tömb
```c++
int t[100]; // 100 elemű tömb
int n;      // tényleges méret: n<=100
cin >> n;
for(int i = 0; i < n; ++i) { // tömb feltöltése
    cin >> t[i];
}
```
Futási időben rögzített méretű, automatikus helyfoglalású egydimenziós tömb

```c++
int n;
cin >> n;
int t[n];  // n elemű tömb
for(int i = 0; i < n; ++i) { // tömb feltöltése
    cin >> t[i];
}
```

Feladatok:

# TODO : Feladatok
