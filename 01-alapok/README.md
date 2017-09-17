# 1. Gyakorlat - Alapok

## A programkód 

Ugorjunk rögtön egy mintakód közepébe és próbáljuk meg annak értelmezése mentén elkezdeni az egészet.

```c++
#include <iostream>

using namespace std;

int main(){
  int b=2;
  b++;
  cout << b << endl;
  cin >> b;
  return 0;
}
```
Egy programkód futtatás nélküli elemzéséhez az első dolog amit szem előtt kell tartani, hogy a programunk mindig **sorról sorra fut**, ergo a gép nem fogja mágikus módon kitalálni, hogy mit akarunk, hanem sorról sorra fogja azokat végrehajtani, mint egy gép:). 
Először figyeljük meg azt, hogy hol jelenik meg a programunkban az **int main()** nevű függvény, mivel innen fog indulni a futásunk. Ami a ```main``` után van a **{ és }** között, az a rész lesz a főprogramunk. 
Szóval ez a programkód pl. annyit csinál, hogy létrehoz egy egészeket tároló változót b névvel, majd annak értékéül adja, hogy kettő.
```int b=2;```. következő sorban a b változót növeljük egyel ```b++;```.  Ekkor a b-nk 3 lesz, mivel eddig 2 volt. A << ("tedd bele") műveleti jelet kimeneti operátorként használtuk; a cout a szabványos kimeneti adatfolyam. A >> ("olvasd be") a bemeneti műveleti jele, a cin a szabványos bemenő adatfolyam. Kiírjuk a b-t, ergo a képernyőre kikerül, hogy 3 majd utána egy sortörés (sortörést jelölése: endl). Utána beolvasunk egy értéket a b-be.
```return 0;``` minden main végén kötelező, ezzel jelezzük a programot indítónak, hogy a program lefutása sikeres volt (ha nem 0-t írunk a return után, akkor azzal hibát jelzünk a programunkat futtató felé). 

### De miért kell mindenhova ";"?
A c++ nem foglalkozik a sortörésekkel, szóközökkel, tabulátorokkal (whitespace karakterekkel, szemben a whitespace nevű nyelvvel: http://hu.wikipedia.org/wiki/Whitespace_%28programoz%C3%A1si_nyelv%29), így valahogy el kell választanunk a parancsokat, ebből adódóan az előző programkódot a következő módon is írhattuk volna.

```c++
#include <iostream> 
using namespace std;int main(){int b=2;b++;cout << b;return 0;}
```
A **#include** -os rész sajnos teljesen más világ, így ott az egy sorba behúzást nem tehetjük meg, mivel ezek úgynevezett direktívák.

### Változók és Aritmerika
Minden névnek és kifejezésnek típusa van, amely meghatározza a végrehajtható műveleteket:
```c++
int inch;
```
A fenti deklaráció például azt adja meg, hogy inch típusa int (vagyis inch egy egész típusú változó). 

A deklaráció olyan utasítás, mely a programba egy nevet vezet be. Ehhez a névhez egy típust rendel. A típus egy név vagy kifejezés megfelelő használatát határozza meg. 

A c++ több alaptípussal rendelkezik. Például:
```c++
bool	//logikai típus, lehetséges értékei: true(igaz) vagy false(hamis)
char	//karakter, például: 'a', 'z' vagy '9'
int   //egész érték, például: 1, 42, vagy 1216
float //lebegőpontos szám
double//kétszeres pontosságú lebegőpontos szám
string //karakterlánc literál azaz szöveg :D 
```

Az aritmetikai műveletek e típusok bármilyen párosítására használhatók:
```c++
+	//összeadás vagy előjel, egy- és kétoperandusú is lehet
-	//kivonás vagy előjel, egy- és kétoperandusú is lehet
*	//szorzás
/	//osztás
%	//maradékképzés
```

Ugyanígy az összehasonlító műveletek is:
```c++
==	//egyenlő
!=	//nem egyenlő
<	//kisebb
>	//nagyobb
<=	//kisebb vagy egyenlő
>=	//nagyobb vagy egyenlő
```

### Direktíva

 #-el kezdődő részeket a programban direktívának hívjuk, ami nem konkrét programkód, hanem csak egy előfeldolgozó folyamat.
Első direktíva amiről beszélünk a legalapvetőbb #include, ami annyit tesz, hogy másolás beillesztés, ekkor egy úgynevezett fejlécfájlt másol be a mi kódunkba, hogy a fordító tudja, hogy miket használhatunk a programunkban. De erről részletesebben későbbi fejezetekben lesz, egyelőre maradjunk annyiban, hogy ha valamilyen funkcióra szükségünk van, akkor ilyen #include sorokat kell majd hozzáadnunk és akkor azokat is megtudjuk majd hívni.

A tárgyon belül az úgynevezett STL-t (Standard Template Library) fogjuk használni csak, ennek része az iostream is, de ha pl. matematikai függvényeket akarunk használni, akkor
```c++
#include <cmath> 
```
sor hozzáadásával elérhetővé tesszük a abs() függvényt is ami a paraméterül adott szám abszolútértékét adja vissza. 
Részletesen: http://www.cplusplus.com/reference/ (ezekből csak párat fogunk érinteni a tárgy alatt.

### És mit jelent az az utolsó még nem magyarázott sor?
```c++
using namespace std;
```

Ez egy egyszerű rövidítés, mivel ha ez nincs kiírva, akkor minden cout elé oda kell írni, hogy std::cout (később lesz szó részletesebben a :: operátorról). De mire is jó?
Egy könnyen érthető magyarázat, hogy programozásban minden feladat megvalósítására nagyon sok verzió készül különböző programozóktól, így viszont elkerülhetetlen, hogy egy nagy projekt esetében ne nevezzenek el a fejlesztők két különböző függvényt azonos névvel, de ha mindkettőt szeretnénk használni akkor mit tudunk tenni? Erre valók a névterek, hogy valamilyen megbeszélt felosztás szerint a függvényeket névcsoportokba soroljuk. Legyen A és B névtér (később erről is részletesebben) mindkettőben létezik a hello függvény, ekkor ```A::hello()``` -val hívhatjuk meg az A verziót ```B::hello()```-val meg a B-set. Ha viszont tudjuk, hogy főként az A függvényeit fogjuk használni, akkor kiírjuk a usingos részt és onnantól ha ```hello()```-t írunk automatikusan az A verziót veszi, de továbbra is elérhető a B verziója ```B::hello()```-t használva. A ```::``` operátor más esetekben is használatos lesz majd még. Amit általánosan tudni kell róla az az, hogy ez egy olyan operátor ami egy fogalmi szinten létező dolgon belüli valamit választ ki. A mostani példánkban egy a fogalomban (névtér) lévő másik fogalmat (függvény) érünk elezzel az operátorral (később lesz másra is példa).

Tehát ha eltávolítjuk a usingos rézt, akkor az iostream-ből ismert dolgok elé kikell rakni az ```std::```-t
```c++
#include <iostream>

int main(){
  int b=2;
  b++;
  std::cout << b;
  return 0;
}
```

## Elgázasáok és Ciklusok

### Elágazás (if)
```c++
#include <iostream>

int main() {
  int a;
  cin >> a;
  if(a%2==0) {
    std::cout << "A beolvasott szám páros!" << std::endl;
  } else {
    std::cout << "A beolvasott szám páratlan!" << std::endl;
  }
  return 0;
}
```
Mi is történik a program életében? Létrehozunk egy a nevű változót amibe utána azonnal be is olvasunk egy értéket. (Például a=5;) Utána jön az if szerkezet aminek ha a feltétele igaz kiértékelése mellett lefut a ```std::cout << "A beolvasott szám páros!" << std::endl;˙``` különben pedig ```std::cout << "A beolvasott szám páratlan!" << std::endl;```. Mivel most az 5 nem osztható kettővel maradék nélkül így az ```else``` ág fog lefutni aminek hatására a képernyőre az fog kiíródni, hogy A beolvasott szám páratlan! .

#### else if 
```c++
#include <iostream>

int main() {
  int a;
  cin >> a;
  if(a%3==0) {
    std::cout << "A beolvasott szám 3-mal osztható!" << std::endl;
  } else if(a%3==1) {
    std::cout << "A beolvasott szám 3-mal osztva 1 maradékot add!" << std::endl;
  } else {
    std::cout << "A beolvasott szám 3-mal osztva 2 maradékot add!" << std::endl;
  }
  return 0;
}
```

#### Absztrakt
```
if (feltétel) {
	utasítások_1
} else if(feltétel) {
	utasítások_2
}
...
} else if(feltétel) {
	utasítások_n-1
} else {
	utasítások_n
}
```
Természetesen ha nem akarunk else ágat írni akkor nyugodtan írhatjuk az alábbi kódrészletet is:
```c++
#include <iostream>

int main() {
  int a;
  cin >> a;
  if(a%3==0) std::cout << "A beolvasott szám 3-mal osztható!" << std::endl;
  return 0;
}
```

### for
```c++
#include <iostream>

int main() {
  for(int i = 0; i < 10; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
```
A for szintakszisa az alábbiképpen néz ki: 
```
for([init_rész];[kifejezés];[léptetés]) { utasítás blokk }
```
A for utasítással lehet a ciklust megvalósítani. Az inicializációs részben kell a változó(ka)t (vesszővel elválasztva, ha több van) kezdeti értékre állítani, a léptetés részben kell változtatni az értéküket. A ciklus addig tart, amíg a kifejezés értéke hamis nem lesz. Futtatási sorrendt: init_rész, kifejezés kiértékelés, ha igaz utasítás/blokk, majd léptetés és ismétlés a kifejezés kiértékeléstől.

### while
```c++
#include <iostream>

int main() {
  int a;
  cin >> a;
  while(a < 10) {
    std::cout << a << " ";
	a++;
  }
  std::cout << std::endl;
  return 0;
}
```

### do while
```c++
#include <iostream>

int main() {
  int a;
  cin >> a;
  do {
    std::cout << a << " ";
	a++;
  } while(a < 10);
  std::cout << std::endl;
  return 0;
}
```


### De hol is van ez a programkód?

Egyszerű szöveges fájlt hozunk létre és abban mint szöveg, szerkesztéséhez nem szükséges semmi extra eszköz, egy egyszerű notepad-től, komolyabb fejlesztőkörnyezetig mindennel szerkeszthetjük. Problémák a karakterkódolásoknál jelenhetnek meg, de a tárgy folyamán nem használunk speciális karaktereket, így ezzel nem foglalkozunk.
Általában a kiterjesztése a c/c++ programkód fájloknak **cpp**, **cc** vagy simán **c**, mi és a CodeBlocks is a **cpp**-t fogjuk használni.

## Fordítás

Fordításra nagyon sok mód létezik, viszont a tárgy folyamán legfőképp CodeBlocks-ot fogjuk használni.

### Code Blocks
**Code Blocks** is használható a tárgy alatt, új projekt létrehozása illetve fordítása sokkal egyszerűbb: https://www.youtube.com/watch?v=kYA8rK2fy2U

## Kommentelés

A kódban megjelenhetnek olyan információk is amik nem feltétlenül tartoznak a kódhoz hanem csak a kód megértését könnyítik, TODO (olyan amit még meg kell csinálni), dokumentáció, vagy bármi egyéb megjegyzés.
C++-ban két alapvető lehetésünk van kommentelésre: 
* // jelek után írt szövegrészeket a program figyelmen kívül hagyja (egy soros megjegyzés)
* /* és */ közé írt szöveget szintén (több soros megjegyzés)

```c++
#include <iostream>

using namespace std;

int main(){
  int b=2; //Szeretem a mákosgubát
  b++;
  cout << b;
  /*
  Egyszer volt hol nem volt volt egyszer egy... róka... vége.
  */
  
  return 0;
}
```
A programozási világban a több soros megjegyzés használata esetén óvatosságra intenek, mert ha pl. van egy 1000 soros kódod és kiakarsz kommentelni 200 sort belőle, de valahol van benne egy 10 soros rész aminél már használtad a több soros megjegyzés, akkor a több soros megjegyzés az 200 soros komment nyitójától fog tartani a 10 soros zárójáig, tehát a 10 soros */-jétől nem lesz kikommentelve a kód. Ahhoz, hogy egy soros kommentelést alkalmazzunk több soron, a legtöbb fejlesztő környezet kínál egy billentyűkombinációt, aminek a segítségével a kijelölt sorok mindegyikét egysoros kommentbe teszi. (Ideiglenes kód eltávolítás miatt pl.)

#  Változók
Nemes egyszerűséggel egy változó az ami valamilyen nemű információt tárol. A változót úgy képzelhetjük el, hogy ha azonosulunk a programmal, hogy mi vagyunk a buta program aki nem tud olyan komplexen gondolkozni, hanem egyszerre csak egy dologra tud koncentrálni. Ha megkérdezed a felhasználót, hogy mondjon egy számot, akkor azt a számot le kell írnod egy lapra és ott hagynod az asztalodon (ami a valóságban a memóriát szimbolizálja), mivel ha nemírod fel elfelejted. 

## Hogy hozzuk létre?

A példánkból már látható vagy sejthető, hogy 
```[Változó típus] [Változó név]```
stílusban hozunk létre változót. A példánkban az int típust használjuk ami az egyszerű egész szám, viszont vigyázzunk vele, mert ezek nem minden egész számot képesek eltárolni, csak adott nagyságút, attól függően hány bit-ről van szó. Ha pl. 32. bites az int (általában ez igaz) akkor 2^32 számot képes kifejezni. (Részletesebben: Numerikus módszerek 1. http://numanal.inf.elte.hu/~hegedus/okt.html)

### Konzolból fordítás (Linux)

```bash
g++ main.cpp
```
A programkódunk egyszerűen fordítható a fájl megadásával a g++ parancs után és a.out néven fogja elkészíteni a futtatható állományt (ezt az állományt linux alatt ./a.out parancsal tudjuk futtatni). 
-o kapcsolóval megadhatjuk a kimeneti fájl nevét is, hogy ne a.out néven mentse el.
```bash
g++ main.cpp -o kicsiprogram
```
Ebben az eseteben ./kicsiprogram fogja logikusan elindítani a programunkat (Nem kell kiterjesztés, nem is szokás).

Később több fájlt fordítása esetén alkalmazhatjuk a 
```bash
g++ main.cpp masik.cpp harmadik.cpp -o kicsiprogram
```
vagy 
```bash
g++ *.cpp -o kicsiprogram
```
parancsot.

Részletesen: http://linux.die.net/man/1/g++

# Feladatok:

1. Gondoljon egy pozitív egész számra és olvassa be! Nem pozitív egész esetén jelezze a hibát és lépjen ki a programból. Helyes szám beolvasása után írja ki a beolvasott számot a képernyőre! 
2. Számítsa ki a kreditátlagot! (Az átlag kiszámítása (összegezzük az összes tárgy jegy*kreditét)/30 – csak az elégtelennél jobb jegyek számítanak! ) Olvassa be a jegyek és kreditek szorzatá-nak összegét! Ez az érték csak pozitív lehet, rossz érték esetén jelezze a hibát és lépjen ki a programból. Helyes érték beolvasása után számolja ki a kreditátlagot és írja ki a képernyıre!
3. Licitálás drágakıre. A programban adott a licit alsó értéke, ennél kevesebbet nem lehet ajánlani. Olvassa be a licitet. Amennyiben a licit alsó értékénél kisebbet adott meg, akkor jelezze a hibát és lépjen ki, különben írja ki a beolvasott licit értéket! 
4. Munkavállalás. Olvassa be annak az árintervallumnak az alsó és felsı értékét, amelyben elvállal egy munkát. Jelezze, ha a felsıérték kisebb az alsónál és lépjen ki a programból, különben írja ki a képernyıre az árintervallumot! 
5. Egy testépítı versenyen a 30 versenyzı között, két jó barát is indul (két egész cseréje). A versenyzıket a pontozáshoz sorszámokkal azonosítják (1-30). Egyikük „szerencseszáma” éppen a másik indulási sorszáma – megegyeznek és cserélnek. Olvassuk be a két számot a billentyőzetrıl (ellenırizzük), végezzük el a cserét, majd az eredményt írjuk ki a konzolablakba! 
6. Mennyi pénzt költhet el szórakozásra? Elhatározza, hogy ha 5000 Ft-nál kevesebbet keres (készpénzt kap), akkor azt azonnal elkölti – ennél nagyobb összeg esetében azonban 5000Ft egész számú többszörösét a számlájára utalja és csak a maradékot költi el (maradékosztály).
7. Felvételi pontszámok kiszámítása. (A pontszámítás jelen esetben két középszintő érettségi százalékos eredményébıl, pontduplázásból áll – nyelvvizsga nélkül.) Olvassa be a két tárgy százalékos eredményét. Azonnal jelezze, ha a beolvasott érték nem lehet vizsgaeredmény és lépjen ki a progtam. Jó értékek esetén számítsa ki a duplázott pontot és írja ki az eredményt! (OsszesPont=(Pont1+Pont2)*2) http://192.188.245.220/felveteli/pontszamitas2008.html
8. Hány éves lesz 2050-ben? Olvassa be az illetı nevét és életkorát, az aktuális dátum ismert a programban ( konstansként). Azonnal jelezze a hibát, ha az életkor nem reális és lépjen ki a programból. Helyes adatok esetén számítsa ki a 2050-ben várható életkort és írja ki a képernyıre!
9. Miquel, a perui diák bukása. Peruban 1-tıl 2o-ig osztályoznak, de 1-tıl 1o-ig sajnos bukásnak számít az elért eredmény. Olvassuk be az osztályzatot és azonnal jelezzük, ha az nem felel meg osztályzatnak, ekkor lépjünk is ki a programból. Helyes osztályzat beolvasása után írjuk ki azt és a bukás tényét, ha az elért osztályzat nem megfelelı! 
10. Reggeli hımérséklet értékelése, átszámítása Fahrenheit-re. [°F] = [°C] · 9/5 + 32 Olvassuk be a hımérsékletet - a Földön eddig elıfordult leghidegebb és legmelegebb hımérsékletek a kódban adottak (-89° C, 58° C). Hibás beolvasás esetén jelezzük a hibát és lépjünk ki a programból. Helyes érték esetén adjuk meg és írjuk is ki, hogy fagypont alatti vagy feletti-e a hımérséklet és számoljuk azt át Fahrenheitre!
11. Huszonegyezés. A játékot többen játszhatják, a cél az, hogy minél jobban meg–kö–zelítse alulról a 21-et (ha 21-nél több, akkor nem nyerhet, befuccsolt) – a lapok értékei a rajta levı számok (7-1o), az alsóé: 2, a felsı: 3, a király: 4 és az ász: 11. Kezdetben a játékosok 2 lapot kapnak, amihez kérhetnek még. A kódban adott, hogy mennyi a kézben tartott 2 lap értéke. Olvassa be a kért lap értékét, ha nem létezik ilyen értékő lap, akkor jelezze a hibát és lépjen ki a programból! Helyes adat esetén írja ki az eredményt és azt is, ha befuccsolt! 


