/*
Mi is az az #include? A #-el kezd�d� r�szeket a programban direkt�v�nak h�vjuk.
Els� direkt�va amir�l besz�l�nk a legalapvet�bb #include, ami annyit tesz, hogy m�sol�s beilleszt�s,
ekkor az �gynevezett fejl�cf�jlt m�sol be a mi k�dunkba, hogy a ford�t� tudja, hogy miket haszn�lhatunk a programban.
De err�l k�s�bb r�szletesebben besz�lget�nk majd.
A t�rgyon bel�l az �gynevezett STL-t (standard template library) fogjuk haszn�lni. P�ld�ul ilyen az iostream.

Pr�b�ld ki: jobb klikk az iostream-re �s <Open #include file: 'iostream'>

*/
#include <iostream>

/*
Ez egy egyszer� r�vid�t�s, mivel ha ez nincs ki�rva, akkor minden cout el� oda kell �rni, hogy
std::cout (k�s�bb lesz sz� r�szletesebben a :: oper�torr�l). De mire is j�? Egy k�nnyen �rthet�
magyar�zat, hogy programoz�sban minden feladat megval�s�t�s�ra nagyon sok verzi� k�sz�l k�l�nb�z�
programoz�kt�l, �gy viszont elker�lhetetlen, hogy egy nagy projekt eset�ben ne nevezzenek el a
fejleszt�k k�t k�l�nb�z� f�ggv�nyt azonos n�vvel, de ha mindkett�t szeretn�nk haszn�lni akkor mit tudunk tenni?
Erre val�k a n�vterek, hogy valamilyen megbesz�lt feloszt�s szerint a f�ggv�nyeket n�vcsoportokba soroljuk.
*/
using namespace std;

/*
Egy programk�d futtat�s n�lk�li elemz�s�hez az els� dolog amit szem el�tt kell tartani, hogy a programunk
mindig sorr�l sorra fut, ergo a g�p nem fogja m�gikus m�don kital�lni, hogy mit akarunk, hanem sorr�l sorra
fogja azokat v�grehajtani, mint egy g�p:). El�sz�r figyelj�k meg azt, hogy hol jelenik meg a programunkban az
int main() nev� f�ggv�ny, mivel innen fog indulni a fut�sunk. Ami a main ut�n van a { �s } k�z�tt, az a r�sz lesz a f�programunk.
*/
int main()
{
    /*
    Ki�rjuk a "Hello World"-t, ergo a k�perny�re kiker�l, hogy "Hello World" majd ut�na egy sort�r�s
    (sort�r�st jel�l�se: endl). Minden main v�g�n k�telez�, ezzel jelezz�k a programot ind�t�nak, hogy a
    program lefut�sa sikeres volt (ha nem 0-t �runk a return ut�n, akkor azzal hib�t jelz�nk a programunkat futtat� fel�).
    */
    cout << "Hello world!" << endl;
    return 0;
}
