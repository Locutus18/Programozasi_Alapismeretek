# 4. Gyakorlat - Programozási Tételek

A programozási tételek gyakran használt algoritmusokat takarnak. Ezeket az algoritmusokat általában tömbökön hajtjuk végre.

Az itt található feladatok t[] tömbön kerülnek végrehajtásra, a t[] tömbnek pedig n darab eleme van. Ahol több tömbbel dolgozunk ott az első tömb a[], amelynek n eleme van, a második tömb b[], amelynek m elem van. Harmadik tömb neve például c[]. Az a[] tömb ciklus változója szokásosan i, a b[] tömbbé j, a harmadik c[] tömbbé k.

A tömbök indexelését 1-el kezdem. Az értékadást egy kettőspont és egy darab egyenlőségjel (:=) jelenti, az egyenlőség vizsgálatot egy darab egyenlőségjel (=) jelzi, a nem egyenlőt egy kisebb-mint és egy nagyobb-mint jel jelzi (<>).

(A rendezés tételtelek egyelőre a pascal szintaxis szerint vannak leírva).

## Összegzés

```c++
osszeg = 0
ciklus i = 1 .. n
    osszeg = osszeg + t[i]
ciklus vége
ki osszeg
```

## Megszámolás

Adott feltételek alapján a tömb bizonyos elemeit megszámolom.

Pl.: Megszámoljuk mennyi negatív szám van a tömbben

```c++
szamlalo = 0
ciklus i = 1 .. n
    ha t[i] < 0 akkor 
        szamlalo = szamlalo + 1
    ha vége
ciklus vége
ki szamlalo
```

## Eldöntés

Szeretnénk tudni, hogy egy érték megtalálható-e egy tömbben.

```c++
  van = 0
  ciklus i = 1 .. n
    ha tomb[i] = keresett_ertek akkor
        van = 1
    ha vége
  ciklus vége
```

A fenti megoldásnak az a hátránya, ha keresett értéket megtaláltuk, a ciklus akkor is tovább megy. Erre megoldást ad, ha a olyan ciklus állítunk munkába, amelyet akkor szoktunk használni, ha nem tudjuk meddig kell menni. Itt pedig ezzel van, dolgunk. Hogy hol lesz a keresett érték nem tudjuk, de ha meg van, le kell állni. Kell egy feltétel, hogy a ciklus addig menjen amíg nincs meg. Egy másik pedig, miszerint a ciklus addig menjen amíg van adat (nincs vége a tömbnek).A következő algoritmus megvalósítja ezt:

```c++
i = 1
ciklus amíg i<=n és t[i]<> ker
    i=i+1
ciklus vége

Ha i<=n akkor
    ki "Van ilyen" 
különben
    ki "A keresett érték nem található"
ha vége
```

A ker változó tartalmazza a keresett értéket, a tömb 0-tól van indexelve!

## Kiválasztás

Az adott elem a tömb hányadik helyén van

```c++
i = 1
ciklus amíg tomb[i] <> ker
    i = i + 1
ciklus vége
ki i
```

A kiválasztás tételt akkor használjuk, ha tudjuk, hogy a keresett értéket tartalmazza a tömb. Ezért az nem vizsgáljuk, hogy vége van-e a tömbnek. A példában a ker változó tartalmazza a keresett értéket.

## Keresés

Lineáris vagy szekvenciális keresés néven is ismert, mivel végig megyünk a számokon sorba.

Adott elem szerepel-e a tömbben és hányadik helyen.

```c++
ker = 30
i = 1
ciklus amíg i<=n és t[i]<>ker
    i = i + 1
ciklus vége

Ha i<=n akkor
    ki "Van ilyen" 
    ki: "Indexe: ", i
különben
    ki: "A keresett érték nem található"
ha vége
```

Ha nincs ilyen elem, akkor erről értesítjük a felhasználót.

## Kiválogatás

A tömb elemit egy másik tömbbe rakom, feltételhez kötve.

Például: Adott a és b tömb. Az a tömb egész számokat tartalmaz. Az a tömbből az 5-nél kisebb számokat átrakom b tömbbe.

```c++
j = 1
ciklus i = 1 .. n
    ha a[i] < 5 
        b[j] = a[i]
        j = j + 1
    ha vége
ciklus vége
```

## Szétválogatás

Két tömbbe válogatjuk szét egy tömb elemeit

Adott „a” tömb, amely egész számokat tartalmaz. A „b” és „c” tömb pedig üres. Az „a” elemeit „b” tömbbe rakjuk ha kisebbek 5-él, különben c-ben tároljuk.

```c++
j = 1
k = 1
ciklus i = 1 .. n
    ha a[i] < 5 
        b[j] = a[i]
        j = j + 1
    különben
        c[k] = a[i]
        k = k + 1
    ha vége
ciklus vége
```

## Metszet

Két tömb azonos elemeinek kiválogatása egy harmadik tömbbe

Adott például A és B tömb:

A	5, 3, 6, 2, 1
B	6, 2, 7, 8, 9
A közös elemeket szeretnénk C tömbben:

C	6, 2

Algoritmus:

```c++
k = 1
ciklus i = 1 .. n
    j = 1
    ciklus amíg j<=m és b[j]<>a[i]
        j = j + 1
    ciklus vége
    ha j<=m akkor 
        c[k] = a[i]
        k = k + 1
    ha vége
ciklus vége
```

## Unió

A és B tömb minden elemét szeretnénk C tömbbe tenni.

Adott például A és B tömb:

A	5, 3, 6, 2, 1
B	6, 2, 7, 8, 9
Az elemek uniója C tömbben:

C	5, 3, 6, 2, 1, 7, 8, 9
Először C-be tesszük az A összes elemét, majd ami nem szerepel A-ban, azt beletesszük C-be.

```c++
ciklus i = 1 .. n
    c[i] = a[i]
ciklus vége 
k = n
ciklus j = 1 .. m
    i = 1
    ciklus amíg i<=n és b[j]<>a[i]
        i = i + 1
    ciklus vége
    ha i>n akkor
        c[k] = b[j]      
        k = k + 1
    ha vége
ciklus vége
```

## Maximum kiválasztás

Keressük a tömb legnagyobb elemét. A következő megoldás akkor működik, ha nincs negatív vagy nulla érték a tömbben:

```c++
max = 0
ciklus i = 1 .. n
    ha t[i]> max akkor 
        max = t[i]
    ha vége
ciklus vége
```

A másik lehetőség, hogy a max kezdeti értéke rögtön az első elem. Ez a megoldás bármilyen halmazon megállja a helyét:

```c++
max = t[1]
ciklus i = 2 .. n
    ha t[i]> max akkor 
        max = t[i]
    ha vége
ciklus vége
```

Ebben a formában viszont elég ha a második elemtől hasonlítunk össze.

## Minimum kiválasztás

Keressük a legkisebb elemet

```c++
min=t[1]
ciklus i = 1 .. n
    ha t[i] < min 
        min = t[i]
    ha vége
ciklus vége
```

## Rendezések
### Buborékrendezés

A sorozat két utolsó elemét összehasonlítjuk, és ha fordított sorrendben vannak felcseréljük.

```c++
ciklus i := n-1 .. 1
  ciklus j := 1 .. i
    ha t[j] > t[j+1] akkor 
      b := t[j+1]
      t[j+1] := t[j]
      t[j] := b
    ha vége
  ciklus vége
ciklus vége
```

A buborék rendezés megvalósítható lentről felfelé és fentről lefelé is.

### Rendezés cserével

Az aktuális első elemet összehasonlítjuk az után következőkkel, ha a következő kisebb akkor csere. Utána a második, harmadik, stb. elemmel.

```c++
Ciklus i := 1 .. n-1
  Ciklus j := i+1 .. n
    Ha T[i] > T[j] akkor
       Csere(i,j)
    Elágazás vége
  Ciklus vége
Ciklus vége
```

### Rendezés maximum kiválasztással

Kiválasztjuk a legnagyobb elemet és a tömb végére rakjuk.

```c++
ciklus i := n .. 1
  max := i
  ciklus j := 1 .. i
    ha t[j] > t[max] akkor max := j
  ciklus vége
  csere(t[i], t[max])
ciklus vége
```

Például a tömb végétől kezdve feltételezem, hogy a legutolsó a legnagyobb. De nem magát a számot, hanem annak indexét jegyzem fel. Ezek után elölről kezdve átnézem, hogy a feltételezettnél nagyobb-e valamelyik. A végén mindenképpen cserélek.

### Minimum kiválasztásos rendezés

Megkeressük a legkisebbet és a tömb elejére tesszük

```c++
ciklus i := 1 .. n-1
  min := i
  ciklus j := i+1  .. n
    ha T[j] < T[min] akkor 
      min := j 
    Elágazás vége
  ciklus vége
  ha min <> i akkor 
    Csere(i,min) 
  Elágazás vége
ciklus vége
```

### Rendezés beszúrással

Balról veszem a második elemet és haladok jobbra. Ez lesz az aktuális elem. Mindig az aktuális elemtől balra lévő elemhez hasonlítok. Ha a balra lévő nagyobb, cserélek. Ha cseréltem a csere kisebb elemét megint a baloldalihoz hasonlítom. Ha nem cserélek tovább balra haladva, akkor visszamegyek az aktuális elemhez, és ott újra kezdem.

```c++
ciklus i := 2 .. n
  kulcs := t[i]
  j := i-1
  ciklus amíg j>0 és t[j]>kulcs
    t[j+1] := t[j]
    j := j - 1
  ciklus vége
  t[j+1] := kulcs
ciklus vége
```
