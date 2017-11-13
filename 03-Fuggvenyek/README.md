# 03 Gyakorlat - Függvények

A programozási nyelvek első egyik legfontosabb eleme a függvények, amik segítségével struktúráltabbá tudjuk tenni a programunkat. A függvényt úgy lehet elképzelni, mint egy doboz amiben ül egy manó te odaadod neki a paramétereket ő meg folyamatosan ugyanazt a feladatot hajtja végre és ha a függvény olyan, hogy visszaad valami választ akkor addig mi ott állunk és tartjuk a kezünket, ha nem akkor is megvárjuk míg végez (kivéve párhuzamos programozás, ami arról szól, hogy nem feltétlenül várjuk meg a függvényt míg végez). Ilyenkor a sorról sorra futásból hirtelen átugrik arra a kódrészletre ami meg lett hívva. A hívást egyszerűen úgy írjuk, hogy megadjuk a függvénynevét és utána zárójelben a paramétereket.
Egy függvény két részből áll: van deklaráció és definíció része.

## Deklaráció

A deklaráció arra szolgál, hogy jelezzük a fordító számára (ami sorról sorra értelmezi a kódot, hasonlóan ahogyan futtatja is), hogy lesz egy ilyen nevű és szignatúrájú függvény (Szignatúra később részletesebben). A deklaráció szerkezete a következő:
```
[Visszatérési érték] [Függvény név]([Paraméterek]);
[Paraméterek] ::= [1. Paraméter típus] [1. Paraméter név], [2. Paraméter típus] [2. Paraméter név] ...
```
Például:
```c++
int max(int a, int b);
```
A kódban ezalatt a deklaráció alatt már akárhol hívhatjuk a ```max``` függvényt függetlenül attól, hogy definiálva lett-e, hogy mit is csinál ez a függvény.

```c++
cout << max(2,3); 
```
Ez természetesen kifogja írni, hogy 3 ha megfelelően definiáljuk később a függvényt. A deklaráció elhagyható és csak a definíció is elég, de később látni fogjuk a hasznát. Ha mégis megakarjuk spórolni a deklaráció leírását, akkor figyeljünk arra, hogy az adott függvény csak onnantól hívható meg a programkódban ha volt deklarálva vagy definiálva.

## Definíció

A függvény definíciója nem sokban különbözik a deklarációtól, annyi különbséggel, hogy a végén nem ;-el zárjuk le hanem { és } között megírunk egy alprogramot ami végre fog hajtódni a hívás esetén.

```c++
int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```

## Összegezve
```c++
#include <iostream>
using namespace std;


int max(int a, int b)

int main(){
  cout << max(2,3);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```
Helyes.

```c++
#include <iostream>
using namespace std;

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

int main(){
  cout << max(2,3);
  return 0;
}

```
Helyes.
```c++
#include <iostream>
using namespace std;

int main(){
  cout << max(2,3);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}

```
Nem helyes, mivel az első hívásnál még a fordító nem tud a max függvényről.
```c++
#include <iostream>
using namespace std;


int max(int a, int b)

int main(){
  cout << max(2,3);
  return 0;
}
```
Nem helyes, mert az értelmezés során a max függvény nem lesz ismertlen számára, de a végén amikor össze akarja rakni a végleges programot a fordító panaszkodni fog, hogy azt állítottad a program elején, hogy lesz max függvény, de végül nem definiáltad, így nem tudja összerakni a programot.

## Szignatúra és overload

Egy függvényt nem csak a neve azonosít hanem az úgynevezett szignatúrája is, ami esetünkben a paraméterek típusa lesz. Az előző példánkban a függvény neve ```max``` volt, a szignatúrája pedig ```int,int```, mivel két paramétert vár és mindkettő int. Ez azért fontos, mert ha ```max(2); ``` parancsot adjuk ki a kódunkban, akkor a fordító panaszkodni fog, hogy nem ismeri a függvényt.

Viszont pont ezt kihasználva, hogy a szignatúra is beleszámít egy függvény azonosításába nem csak a név, tudunk úgymond overloadolni, ami annyit tesz, hogy egy névhez több funkciót is megadunk. 

Például:
```c++
int max(int a, int b, int c){
  return max(max(a,b),c);
}
```
Ezzel a kóddal elérjük azt, hogy ha három paraméterrel hívják meg a max függvényünket akkor már az is fog működni. Ez a függvény teljesen egyszerűen, ha nézzük a definíciót meghívja a két paraméteres maxot. 
*Note: Egyelőre nem törekedünk optimális kód írására, a fő szempontunk, hogy gyorsabban és szebb kódot írjunk.*


##Név változtatás
Az, hogy a hívó függvényben hogy nevezzük el a változókat az teljesen független attól, hogy egy függvényen belül hogy hívjuk.
```c++
#include <iostream>
using namespace std;

int max(int a, int b)

int main(){
  int bela=2;
  int feri=3;
  cout << max(bela,feri);
  return 0;
}

int max(int a, int b){
  if(a > b){
    return a;
  }else{
    return b;
  }
}
```
Helyes. A ```max``` függvényen belül az átadott értékek nevei ```a``` és ```b``` lesz a többitől függetlenül.