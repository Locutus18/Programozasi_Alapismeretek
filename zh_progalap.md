# Algoritmus Zárthelyi Dolgozat Programozási Alapismeretek 

Az alábbi három feladatot kell megoldani papíron. Feladatonként 15 pont jár. Így összesen 45 pontot lehet szerezni.
Ponthatárok:
* 0-11 : 1
* 12-16 : 2
* 17-21 : 3
* 22-26 : 4
* 27-45 : 5

## 1. Feladat

Keressük meg az első 20 és 80 között az első Catalan-számot. 
Használható függvény:
* Catalane(n)
  * Amely egy paraméterben kapott számról eldönti,hogy Catalan-szám.

Pontozás:
* Specifikáció : 5 pont
* Algoritmus : 10 pont

## 2. Feladat

Határozza meg 1-től 10000-ig a tökéletes számok összegét! Egy szám tökéletesnek számít akkor ha az önmagánál kisebb osztóinak összege egyenlő a számmal. 
Például : 6 tökéletes szám azért mert 1+2+3 = 6.

Pontozás:
* Specifikáció : 5 pont
* Algoritmus : 7 pont

Az alábbi függvényeket használva az alábbi pontok járnak:

* Tokeletese(n) -> 1 pont
  * A paraméterben megadott számról eldönti, hogy tökéletes-e.
* SzamToTomb(n) -> 2 pont
  * A paraméterben megadott szám osztóival tér vissza tömbben. (Ezeket kell összegezni és eldönteni, hogy tökéletes-e.) 
* Magadnak definiálod a tökéletes számot és határozod meg -> 3 pont
  * Itt nyugodtan használhatod osztás megállapítására az (i|N), azaz i osztója az N-nek.

## 3. Feladat

Adjuk meg a legnagyobb olyan számot 1 és 100 között amelynek a legtöbb osztója van. 

Pontozás:
* Specifikáció : 5 pont
* Algoritmus : 7 pont

Az alábbi függvényeket használva az alábbi pontok járnak:

* OsztokSzama(n) -> 1 pont
  * A paraméterben megadott szám osztóinak számával tér vissza.
* Osztok(n) -> 2 pont
  * A paraméterben megadott szám osztóival tér vissza tömbben.
* Magadnak definiálod a az osztók számát. -> 3 pont
  * Itt nyuigodtan használhatod az osztás megállapítására az (i|N), azaz i osztója N-nek.

