#include "MyClass.h"

int main() {
    // Tworzenie obiektu z wywo³aniem konstruktora
    MyClass obj1;

    // Tworzenie obiektu poprzez kopiowanie
    MyClass obj2 = obj1;

    // Tworzenie obiektu za pomoc¹ operatora przypisania
    MyClass obj3;
    obj3 = obj1;

    // Tworzenie obiektu za pomoc¹ operatora new
    MyClass* obj4 = new MyClass;

    // Wywo³anie zaprzyjaŸnionej funkcji
    friendFunction(obj1);

    // Usuniêcie obiektu stworzonego przez operator new
    delete obj4;

    return 0;
}

//Odpowiedzi na pytania :
//
//Nie, funkcja zaprzyjaŸniona nie jest kopiowana wraz z kopi¹ obiektu.Funkcja zaprzyjaŸniona jest jedynie zaprzyjaŸniona z klas¹ i ma dostêp do jej prywatnych sk³adowych, ale nie jest jej czêœci¹.
//Nie, !(kopiowanie obiektu wymaga utworzenia w klasie konstruktora kopiuj¹cego.W przeciwnym wypadku), jeœli konstruktor kopiuj¹cy nie zostanie zdefiniowany, kompilator utworzy dla nas domyœlny konstruktor kopiuj¹cy, który skopiuje wszystkie sk³adowe obiektu.
//Nie, !(dla tworzonego obiektu, bêd¹cego kopi¹ innego obiektu, uruchamiany jest konstruktor kopiuj¹cy) chyba ¿e jest kopiuj¹cy.