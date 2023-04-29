#include <iostream>
#include <random>

using namespace  std;
void przydzielPamiec1D(int *&tab, int n){
    tab = new int[n];
}
void przydzielPamiec2D(int **&tab, int w, int k){
    tab=new int*[w];
    for(int i=0; i<w;i++){
        tab[i]=new int[k];
    }
}
// przydzielanie pamieci -> listing 1.9
void wypelnijTablice1D(int *tab, int n, int a, int b){
    srand(time(NULL));
    for(int i=0; i<n; i++){
        tab[i]=rand()%(b-a+1)+a;
    }
}
void wypelnijTablice2D(int **tab, int w, int k, int a, int b){
    srand(time(NULL));
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            tab[i][j]=rand()%(b-a+1)+a;
        }
    }
}
// generowanie liczb pseudolosowych -> listing 1.11
void usunTablice1D(int *&tab){
    delete []tab;
}
void usunTablice2D(int **&tab, int w){
    for(int i=0; i<w; i++){
        delete []tab[i];
    }
    delete []tab;
}
// zwalnianie pamieci -> listing 1.9
void wyswietl1D(int* tab, int n){
    for(int i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
void wyswietl2D(int** tab, int w, int k){
    for(int i=0; i<w; i++){
        for(int j=0; j<k; j++){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sortowanieBabelkowe(int* tab, int n, int tryb){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (tryb == 0)
                {
                if (tab[j] > tab[j + 1]) {
                    int temp;
                    temp = tab[j];
                    tab[j] = tab[j + 1];
                    tab[j + 1] = temp;
                }
                }else{if (tab[j] < tab[j + 1]) {
                        int temp;
                        temp = tab[j];
                        tab[j] = tab[j + 1];
                        tab[j + 1] = temp;
                    }
                }
            }
        }
}
void sortowaniePrzezWybor(int* tab, int n, int tryb){
    for(int i=0;i<n;i++){
        int ind=i;
        for(int j=i;j<n;j++){
            if(tryb ==0) {
                if (tab[j] < tab[ind]) {
                    ind = j;
                }
            }else{
                if (tab[j] > tab[ind]) {
                    ind = j;
                }
            }
        }
        int temp = tab[i];
        tab[i] = tab[ind];
        tab[ind] = temp;
    }
}
void sortowaniePrzezWstawianie(int* tab, int n, int tryb){
    int i = n-2;
    while(i>=0){
        int j=i;
        int temp = tab[j];
        if(tryb ==0) {
            while (temp > tab[j + 1] && j < n - 1) {
                tab[j] = tab[j + 1];
                j = j + 1;
            }
        }else{
            while (temp < tab[j + 1] && j < n - 1) {
                tab[j] = tab[j + 1];
                j = j + 1;
            }
        }
        tab[j]=temp;
        i--;
    }
}
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol){

}

void Zad2(){
    cout<<"Rozmiar tablicy?"<<endl;
    int n;
    cin>>n;
    cout<<"Podaj a i b"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"Tryb sortowania 0 1"<<endl;
    int tryb;
    cin>>tryb;
    int* tab1 = nullptr;
    przydzielPamiec1D(tab1,n);
    wypelnijTablice1D(tab1,n,a,b);
    wyswietl1D(tab1,n);
    sortowanieBabelkowe(tab1,n,tryb);
    wyswietl1D(tab1,n);
    usunTablice1D(tab1);
}
void Zad3(){
    cout<<"Rozmiar tablicy?"<<endl;
    int n;
    cin>>n;
    cout<<"Podaj a i b"<<endl;
    int a,b;
    cin>>a>>b;
    cout<<"Tryb sortowania 0 1"<<endl;
    int tryb;
    cin>>tryb;
    int* tab1 = nullptr;
    przydzielPamiec1D(tab1,n);
    wypelnijTablice1D(tab1,n,a,b);
    wyswietl1D(tab1,n);
    sortowaniePrzezWstawianie(tab1,n,tryb);
    wyswietl1D(tab1,n);
    usunTablice1D(tab1);
}

int main(){

    int tab[5]={5,3,2,7,9};
    sortowaniePrzezWstawianie(tab,5,0);
    wyswietl1D(tab,5);

    int tryb;
    cout << "Ktory program?"<<endl;
    cin>>tryb;
    switch (tryb) {
        case 1:
            Zad2();
            break;
        case 2:
            Zad3();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            return 0;
            break;
    }

    return 0;
}