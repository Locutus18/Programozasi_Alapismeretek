/*
Mi is az az #include? A #-el kezdõdõ részeket a programban direktívának hívjuk.
Elsõ direktíva amirõl beszélünk a legalapvetõbb #include, ami annyit tesz, hogy másolás beillesztés,
ekkor az úgynevezett fejlécfájlt másol be a mi kódunkba, hogy a fordító tudja, hogy miket használhatunk a programban.
De errõl késõbb részletesebben beszélgetünk majd.
A tárgyon belül az úgynevezett STL-t (standard template library) fogjuk használni. Például ilyen az iostream.

Próbáld ki: jobb klikk az iostream-re és <Open #include file: 'iostream'>

*/
#include <iostream>

/*
Ez egy egyszerû rövidítés, mivel ha ez nincs kiírva, akkor minden cout elé oda kell írni, hogy
std::cout (késõbb lesz szó részletesebben a :: operátorról). De mire is jó? Egy könnyen érthetõ
magyarázat, hogy programozásban minden feladat megvalósítására nagyon sok verzió készül különbözõ
programozóktól, így viszont elkerülhetetlen, hogy egy nagy projekt esetében ne nevezzenek el a
fejlesztõk két különbözõ függvényt azonos névvel, de ha mindkettõt szeretnénk használni akkor mit tudunk tenni?
Erre valók a névterek, hogy valamilyen megbeszélt felosztás szerint a függvényeket névcsoportokba soroljuk.
*/
using namespace std;

/*
Egy programkód futtatás nélküli elemzéséhez az elsõ dolog amit szem elõtt kell tartani, hogy a programunk
mindig sorról sorra fut, ergo a gép nem fogja mágikus módon kitalálni, hogy mit akarunk, hanem sorról sorra
fogja azokat végrehajtani, mint egy gép:). Elõször figyeljük meg azt, hogy hol jelenik meg a programunkban az
int main() nevû függvény, mivel innen fog indulni a futásunk. Ami a main után van a { és } között, az a rész lesz a fõprogramunk.
*/
int main()
{
    /*
    Kiírjuk a "Hello World"-t, ergo a képernyõre kikerül, hogy "Hello World" majd utána egy sortörés
    (sortörést jelölése: endl). Minden main végén kötelezõ, ezzel jelezzük a programot indítónak, hogy a
    program lefutása sikeres volt (ha nem 0-t írunk a return után, akkor azzal hibát jelzünk a programunkat futtató felé).
    */
    cout << "Hello world!" << endl;
    return 0;
}
