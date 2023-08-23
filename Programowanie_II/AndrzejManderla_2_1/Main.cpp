#include "MyClass.h"

int main() {
    // Tworzenie obiektu z wywo�aniem konstruktora
    MyClass obj1;

    // Tworzenie obiektu poprzez kopiowanie
    // skipcq: CXX-P2005
    MyClass obj2 = obj1;

    // Tworzenie obiektu za pomoc� operatora przypisania
    MyClass obj3;
    obj3 = obj1;

    // Tworzenie obiektu za pomoc� operatora new
    MyClass* obj4 = new MyClass;

    // Wywo�anie zaprzyja�nionej funkcji
    friendFunction(obj1);

    // Usuni�cie obiektu stworzonego przez operator new
    delete obj4;

    return 0;
}

//Odpowiedzi na pytania :
//
//Nie, funkcja zaprzyja�niona nie jest kopiowana wraz z kopi� obiektu.Funkcja zaprzyja�niona jest jedynie zaprzyja�niona z klas� i ma dost�p do jej prywatnych sk�adowych, ale nie jest jej cz�ci�.
//Nie, !(kopiowanie obiektu wymaga utworzenia w klasie konstruktora kopiuj�cego.W przeciwnym wypadku), je�li konstruktor kopiuj�cy nie zostanie zdefiniowany, kompilator utworzy dla nas domy�lny konstruktor kopiuj�cy, kt�ry skopiuje wszystkie sk�adowe obiektu.
//Nie, !(dla tworzonego obiektu, b�d�cego kopi� innego obiektu, uruchamiany jest konstruktor kopiuj�cy) chyba �e jest kopiuj�cy.