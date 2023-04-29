#include <iostream>
#include <fstream>
#include <sstream>
using  namespace std;
struct  student{
    string imie;
    string nazwisko;
    int l_p;
    int zn=0;
};

void wczytajStudentow(student*&tab, int n){
    tab = new student[n];
}

void zwiekszStudent(student *&tab, int &n)
{
    delete []tab;
    n++;
    tab = new student[n];
}

void usunTabliceStudentow(student *&tab){
    delete []tab;
}

void wyswietlStudentow(student* tab, int n){
    for(int i=0;i<n;i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
    }
}


void sortowanieQuickSort(student* tab, int l, int p, int tryb){
    int srodek =(int)(l+p)/2;
    student piwot = tab[srodek];
    tab[srodek]=tab[p];
    int granica = l;
    int i=l;
    while(i<p){
        bool t=tab[i].l_p<piwot.l_p;
        if(tryb==1){
            t=tab[i].l_p>piwot.l_p;
        }
        if(t){
            student temp = tab[granica];
            tab[granica] = tab[i];
            tab[i] = temp;
            granica++;
        }
        i++;
    }
    tab[p]=tab[granica];
    tab[granica]=piwot;
    if(l<granica-1){
        sortowanieQuickSort(tab,l,granica-1,tryb);
    }
    if(granica+1<p){
        sortowanieQuickSort(tab,granica+1,p,tryb);
    }
}

int wczytywanieDanych(student*& tab){
    string sciezka, linia, pomoc;
    int liczbaStudentow;
    ifstream plik;
    char sredniki;
    sciezka="C:\\Users\\lenovo\\Downloads\\studenci.csv";

    plik.open(sciezka);
    plik >> liczbaStudentow;
    wczytajStudentow(tab,liczbaStudentow);
    for(int i=0;i<2;i++){
        plik>>sredniki;
    }
    for(int i=0; i<liczbaStudentow; i++){
        plik>>linia;
        stringstream ss(linia);
        getline(ss,tab[i].imie,';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].l_p=atoi(pomoc.c_str());
    }
    plik.close();
    cout<<liczbaStudentow<<endl;
    return liczbaStudentow;
}

void line_search(student*& tab, int l_s, int war){
    bool test=true;
    for(int i=0;i<l_s;i++){
        if(tab[i].l_p == war){
            cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].l_p<<endl;
            test=false;
        }
    }
    if(test){
        cout<<"Nie znaleziono"<<endl;
    }
}

void binary_search(student*& tab, int l_s, int war){
int lewy = 0;
bool test=true;
int prawy = l_s-1;
while(lewy<=prawy){
    int srodek = (int)(lewy+prawy)/2;
    if(tab[srodek].l_p==war && tab[srodek].zn==0){
        cout<<tab[srodek].imie<<" "<<tab[srodek].nazwisko<<" "<<tab[srodek].l_p<<endl;
        tab[srodek].zn = 1;
        test = false;
    }else{
        if(war<tab[srodek].l_p){
            prawy=srodek-1;
        }else{
            lewy=srodek+1;
        }
    }
}
if(test){
    cout<<"Nie znaleziono"<<endl;
}
}

void Zapis(student*& tab, int l_s){
    ofstream zapis;
    string sciezkaDoZapisu="wyniki.csv";
    zapis.open(sciezkaDoZapisu);
    for(int i=0,j=0; i<l_s; i++){
        if(tab[i].zn==1) {
            zapis << tab[i].imie << ";" << tab[i].nazwisko << ";" << endl;
        }
    }

    zapis.close();
}

int main() {
    student *tab;
    int l_s=0;
    while(true) {
        cout << "Zadanie 7.1 - 1\nZadanie 7.2 - 2\nZadanie 7.3 - 3\nWyjscie - 0" << endl;
        int a,b;
        cin >> a;
        if (a == 1) {
            l_s = wczytywanieDanych(tab);
            wyswietlStudentow(tab, l_s);
        } else if (a == 2) {
            cout<<"Podaj ilosc pkt"<<endl;
            cin>>b;
            line_search(tab,l_s,b);
        } else if (a == 3) {
            cout<<"Podaj ilosc pkt"<<endl;
            cin>>b;
            sortowanieQuickSort(tab,0,l_s-1,0);
            binary_search(tab,l_s,b);
            Zapis(tab,l_s);
        } else {
            usunTabliceStudentow(tab);
            return 0;
        }
    }
}
