# 5. Gyakorlat - Struktúra

## Struktúra

Ha létre akarunk hozni egy új adattípust, már korábbi tanulmányaink során láthattuk, hogy a
```c++
[Új típus típusa] [Új típus neve];
```
módon tehetjük meg.
Eddig ismertetett típus típusok:
* struct

Amikor egy structot létrehozunk több alaptípust akarunk összefogni egy új típusban. Például ha egy koordinátát megvalósítú struktúrát akarunk létrehozni, akkor a következő módon tehetjük:
```c++
struct Coord{
    int x;
    int y;
};
```
, ahol az ```x``` az egyik tengely, az ```y``` a másik tengely mentén felvett értéket jelöli.
Innentől a két változót egy típusként tudjuk kezelni és ```.``` operátorral tudunk hivatkozni egy-egy részére az adott példánynak.

```c++
Coord a;
a.x = 12;
a.y = 0;
if(a.x > 0){
   ...
}
```

## Tulajdonság számolása egy struktúrának

```c++
#include <iostream>
#include <cmath>

using namespace std;

struct Coord{
    int x;
    int y;
};

float length(const Coord &o){
    return sqrt(pow(o.x,2)+pow(o.y,2));
}

int main(){
    Coord a;
    a.x = 12;
    a.y = 13;
    cout << length() << endl;
    return 0;
}
```

## Függvény bevitele a struktúrába

Ahogy eddig írtunk függvényeket azt szoktuk úgy hívni, hogy globális térbe írjuk a függvényt, mivel csak úgy magába a fájlba írjuk, viszont a függvényeket be tudjuk rakni a struktúrába is, hogy szorosan hozzákapcsolódjon logikailag. Olyan függvényeket tudunk bevinni az struktúrába aminek az első paramétere maga az osztály és akkor
```length(a)``` helyett ```a.length()``` formában fogjuk hívni a függvényt.


```c++
#include <iostream>
#include <cmath>

using namespace std;

struct Coord{
  int x;
  int y;
  
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};

int main(){
  Coord a,b;
  a.x = 12;
  a.y = 13;
  cout << (a).length() << endl;
}
```

## Láthatóság

Az új típus amiről ez a lecke szól az az osztály lesz, amit ```class```-al jelölünk c++-ban. Egy class és struct sok dologban nem különbözik, csak az úgynevezett alapértelmezett láthatóságban.
Két típusú láthatóságot fogunk tárgyalni:
```private``` - titkos, azaz kívülről ezek a függvények és változók nem érhetőek el.
```public``` - mindenki által elérhető és módosítható változók és meghívható függvények.

A következő példán keresztül nézük meg, hogy hogy is működik ez a láthatóság.
```c++
struct Valami{
  int a;
private:
  int b;
  int c;
public: 
  int d;
};

```
Ennek a strutkúrának az ```a``` és ```d``` változóját elérjük, de ```b``` és ```c``` változókat nem, tehát alapvetően egy struktúra publikus, tehát elérhetőek az elemei, de mihelyt egy ```private``` jelzőt rakunk oda a példában látható módon, akkor onnantól privát lesz minden tag, amíg meg nem jelenik egy különböző láthatósági jelző.


## Egy lépés az osztály felé

Az osztály mai fordítóknál lényegében csak egy dologban különbözik, hogy az alapvető láthatóság ```private```, tehát ha a kódunkat így módosítjuk akkor a két kódunk azonos lesz lényegében.
```c++
class Coord{
public:
  int x;
  int y;
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};
```

## Adattagokat konvencionálisan priváttá tesszük

```c++
#include <iostream>
#include <cmath>

using namespace std;

class Coord{
  int x;
  int y;
  
public:
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }
};

int main(){
  Coord a,b;
  a.x = 12;
  a.y = 13;
  
  cout << (a).length() << endl;
}
```

Ebben az esetben viszont egy probléma is fellép a kódunkban.
* A main függvényben értékeket adunk egyenesen a változóknak. Ezt a hibát setter-getter-el fogjuk megoldani.

## Getter-Setter

A getter-setter függvények arra valók, hogy ahelyett, hogy egyenesen hozzáférnénk az osztály egyes tagjaihoz ezt egy függvényen keresztül tehessük meg. Tehát privát minden adattag, viszont a legtöbb adattag módosítható egy-egy setterrel. Setterek konvencionális neve set[Változónév upper camel case-el], azaz ```repaRetekMogyoro``` osztálytváltozó setterének a neve ```setRepaRetekMogyoro```.
Hasonlóan getternél: ```getRepaRetekMogyoro```.

A maint nem tesszük baráttá, mivel ő nem tartozik szorosan az osztályunkhoz. 

## Működő kód

```c++
#include <iostream>
#include <cmath>

using namespace std;

class Coord{
  int x;
  int y;
  
public:
  float length(){
    return sqrt(pow(x,2)+pow(y,2));
  }

  void setX(int x){
    this->x = x;
  }
  void setY(int y){
    this->y = y;
  }
  
  int getX(){
    return x;
  }
  int getY(){
    return y;
  }
};

int main(){
  Coord a,b;
  a.setX(12);
  a.setY(13);
  
  cout << (a).length() << endl;
}
```

## Miért kell a láthatóság?

A láthatóságra azért van szükségünk, hogy az osztályunknak az állapotterét a megfelelő keretek között tartsuk, hogy végig előfeltételnek megfelelő legyen.
Például, ha kell egy pozitív egész számokat tartalmazó osztály, akkor tudunk olyan settert megadni, ami exception dob, hogyha negatív számot adunk át neki, vagy csak egyszerűen nem hagyja, hogy felülírják.