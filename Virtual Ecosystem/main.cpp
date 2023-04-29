#include <iostream>
#include "organizm.h"

#include "ustawienia.h"
#include "generatorlosowy.h"
#include "sasiedztwo.h"
#include "nisza.h"
#include "osobniki.h"
#include "zlab09.h"

static Nisza n1,n2,n3;

using namespace std;

//void drukujOrganizm(const Organizm & o){
//    cout << "licznikzycia: "
//    << o.stanLicznikazycia()
//    << " licznikPosilkow: "
//    << o. stanLicznikaPosilkow() << endl
//    << "limitPosilkow: "
//    << o.limitPosilkow
//    << " kosztPotomka: "
//    << o.kosztPotomka << endl
//    << "głodny: " << o.glodny()
//    << " pączkujacy: "
//    << o.paczkujacy() << endl << endl;
//}

//int main()
//{
//    //1. Test kreacji obiektów
//    Organizm organizm1(8, 3, 2);
//    Organizm organizm2 = organizm1;
//    Organizm organizm3(organizm1);
//    cout << "wynik testu kreacji obiektów:"
//    <<endl << endl;
//    cout << "Organizm1: " << endl;
//    drukujOrganizm(organizm1);
//    cout << "Organizm2" << endl;
//    drukujOrganizm(organizm1);
//    cout << "Organizm3" << endl;
//    drukujOrganizm(organizm2);
//    //2. Test niezależności obiektów
//    organizm1.posilek();
//    organizm1.posilek();
//    organizm2.posilek();
//    organizm3.krokSymulacji();
//    cout << "Wynik testu niezależności obiektów:"
//    <<endl << endl;
//    cout << "Organizm1:" << endl;
//    drukujOrganizm (organizm1);
//    return 0;
//}
//void wyswietl(UstawieniaSymulacji & UST){
//    cout << "Znak glon:" << UST.znakGlon
//    << " zycieMin=" << UST.glonZycieMin
//    << " zycieMax=" << UST.glonZycieMax << endl;
//}
//int main(){
//    //1. Dostęp do obiektu klasy UstawienaSymulacji
//    UstawieniaSymulacji & UST1
//    = UstawieniaSymulacji::pobierzUstawienia();
//    UstawieniaSymulacji & UST2
//    = UstawieniaSymulacji::pobierzUstawienia();
//    UstawieniaSymulacji & UST3
//    = UstawieniaSymulacji::pobierzUstawienia();
//    cout << "Pobranie ustawien 3x" << endl;
//    cout << "UST1:"; wyswietl(UST1);
//    cout << "UST2: "; wyswietl (UST2) ;
//    cout << "UST3: "; wyswietl (UST3);
//    cout << endl << "Zmiana wartości tylko 1x" << endl;
//    UST2.glonZycieMax = 100;
//    cout << "UST1: "; wyswietl(UST1);
//    cout << "UST2: "; wyswietl (UST2);
//    cout << "UST3: "; wyswietl(UST3);
//    return 0;
//}

//int main()
//{
//    cout << "Liczby losowe typu int:" << endl;
//    cout <<" od 0 do 5: ";
//    for (int i=0; i<10; i++)
//        cout << GEN::losujOdZeraDo (5) << " ";
//    cout << endl << " od 0 do 3:";
//    for (int i=0; i<10; i++)
//        cout << GEN::losujOdZeraDo(3) << " ";
//    cout << endl << " od 0 do 20: ";
//    for(int i=0; i<10; i++)
//        cout << GEN::losujOdZeraDo(20) << " ";

//    cout << endl << endl;
//    cout << "Liczby losowe typu long: " << endl;
//    cout <<" od -2 do 2:";
//    for (int i=0; i<10; i++)
//        cout << GEN::losujPomiedzy(-2L, 2L) <<" ";
//    cout << endl << endl
//        << "Liczby losowe typu unsigned short: " << endl;
//    cout << " od 2 do 6: ";
//    unsigned short min=2, max=6;
//    for (int i=0; i<10; i++)
//    cout << GEN::losujPomiedzy(max, min) <<" ";
//    cout << endl << endl;
//    return 0;
//}
//int main(){
//Sasiedztwo sasiedztwo;
//sasiedztwo.okreslSasiada(P, GLON);
//sasiedztwo.okreslSasiada(PG, GRZYB);
//sasiedztwo.okres1Sasiada(G, GRZYB);
//sasiedztwo.okres1Sasiada(LG, GLON);
//sasiedztwo.okreslSasiada(L, BAKTERIA);
//sasiedztwo.okreslSasiada(LD, BAKTERIA);
//sasiedztwo.okres1Sasiada(D, GLON);
//sasiedztwo.okres1Sasiada(PD, PUSTKA);
//cout << "Przegląd sasiedztwa:" << endl;
//for(int i=0; i<8; i++){
//Polozenie p = static_cast<Polozenie>(i);
//RodzajMieszkanca
//r = sasiedztwo.ktoJestSasiadem(p);
//cout << "polozenie=" << p << " rodzaj="
//<< nazwaRodzaju(r) << endl;
//}
//cout << endl << "Policzenie sasiadów"
//<<"określonego rodzaju:" << endl
//<<" glony=" << sasiedztwo. ile ( GLON) << endl
//<<"grzyby=" << sasiedztwo. ile( GRZYB) << endl
//<<" trupy=" << sasiedztwo.ile( TRUP) << endl;
//cout << endl << "Wylosowanie sasiada:" << endl
//<< "glon -> "
//<<sasiedztwo.losujSasiada ( GLON) << endl
//<<"pustka -> "
//<<sasiedztwo. losujsasiada (PUSTKA) << endl
//<< " trup -> "
//<<sasiedztwo.losujSasiada ( TRUP) << endl1;
//long wiersz, kolumna;
//cout << endl
//<< "Zmiana indeksów [5][7]"
//<< "wg polozenia:" << endl;
//for (int i=0; i<8; i++) {
//Polozenie p = static_cast<Polozenie>(i);
//wiersz = 5; kolumna = 7;
//Sasiedztwo::zmienIdeksywgPolozenia (p, wiersz, kolumna);
//cout <" polozenie: " << p << " ->[" << wiersz
//<< "][" << kolumna << "]" << endl;
//}
//cout<<endl;
//return 0;
//}

//string nazwaRodzaju(RodzajMieszkanca rodzaj){
//    switch (rodzaj) {
//        case GLON: return "GLON";
//        case GRZYB: return "GRZYB";
//        case BAKTERIA: return "BAKTERIA";
//        case PUSTKA: return "PUSTKA";
//        case SCIANA: return "SCIANA";
//        case TRUP: return "TRUP";
//        case NIEZNANE: return "NIEZNANE";
//    }
//}

//int main(){
//Sasiedztwo sasiedztwo;
//sasiedztwo.okreslSasiada(P,GLON);
//sasiedztwo.okreslSasiada (PG, GRZYB);
//sasiedztwo.okreslSasiada(G,GRZYB);
//sasiedztwo.okreslSasiada(LG,GLON);
//sasiedztwo.okreslSasiada(L, BAKTERIA);
//sasiedztwo.okreslSasiada(LD, BAKTERIA);
//sasiedztwo.okreslSasiada(D,GLON);
//sasiedztwo.okreslSasiada(PD,PUSTKA);
//cout << "Przeglad sasiedztwa:" << endl;
//for(int i=0; i<8; i++){
//Polozenie p = static_cast<Polozenie>(i);
//RodzajMieszkanca r = sasiedztwo.ktoJestSasiadem(p);
//cout << "polozenie=" << p << " rodzaj="<< nazwaRodzaju(r) << endl;
//}
//cout << endl << "Policzenie sasiadéw"
//<< "okreslonego rodzaju:" << endl
//<< " glony=" << sasiedztwo.ile(GLON) << endl
//<< " grzyby=" << sasiedztwo.ile(GRZYB) << endl
//<< " trupy=" << sasiedztwo.ile(TRUP) << endl;
//cout << endl << "Wylosowanie sasiada:" << endl
//<< " glon -> "
//<< sasiedztwo.losujSasiada(GLON) << endl
//<< " pustka -> "
//<< sasiedztwo.losujSasiada(PUSTKA) << endl
//<< " trup -> "
//<< sasiedztwo.losujSasiada(TRUP) << endl;
//long wiersz, kolumna;
//cout << endl
//<< "Zmiana indekséw [5][7]"
//<< "wg polozenia:" << endl;
//for(int i=0; i<8; i++){
//Polozenie p = static_cast<Polozenie>(i);
//wiersz = 5; kolumna = 7;
//Sasiedztwo::zmienIndeksyWgPolozenia(p,wiersz,kolumna);
//cout << " polozenie: " << p << " ->[" << wiersz
//<< "][" << kolumna << "]" << endl;
//}
//cout << endl;
//return 0;
//}


//static char sep = UstawieniaSymulacji::
//pobierzUstawienia().znakSeparator;
//void wyswietlNisze()
//{
//cout << n1.jakiSymbol() << sep
//<< n2.jakiSymbol() << sep
//<< n3.jakiSymbol() << endl;
//}
//int main()
//{
//cout << "Puste nisze: ";
//wyswietlNisze();
//cout << "Lokowanie mieszkarncow: ";
//n1.przyjmijLokatora(new Glon());
//n3.przyjmijLokatora(new Grzyb());
//wyswietlNisze();
//cout << "Przesuwanie lokatordw: ";
//n2 = n1;
//wyswietlNisze();
//cout << "Przesuwanie lokatoroéw:";
//n3 = n2;
//wyswietlNisze();
//cout << endl;
//return 0;
//}

int main(){
    ZLab09 z;
    z.rozmiary();
    z.skalar();
    z.tablica1D();
    z.tablica2D(2,5);
    z.referencja();
    return 0;
}
