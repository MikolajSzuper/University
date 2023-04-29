#include <iostream>

using namespace std;
void naiwny(string txt,string wz){
    int dlt = txt.length();
    int dlw = wz.length();
for(int i=0;i<=dlt-dlw;i++){
    int j;
    for(j=0;j<dlw && wz[j]==txt[i+j];j++);
    if(j==dlw){
        cout<<"Ciag znakow zaczyna sie na pozycji: "<<i<<endl;
    }
}
}

void zbudujTabliceDopasowan(string wz,int dlw,int *p){
    p[0]=0;
    p[1]=0;
    int t=0;
    int i=1;
    while(i<dlw){
        while (t>0 && wz[t]!=wz[i]){
            t=p[t];
        }
        if(wz[t]==wz[i]){
            t++;
        }
        p[i+1]=t;
        i++;
    }
}
void kmp(string txt, string wz){
    int dlw = wz.length();
    int dlt = txt.length();
    int *p;
    p=new int[wz.length()];
    zbudujTabliceDopasowan(wz,dlw,p);
    int i=0;
    int j=0;
    while(i<dlt-dlw+1){
        while (wz[j]==txt[i+j] && j<dlw){
            j++;
        }
        if(j==dlw){
            cout<<"Ciag znakow zaczyna sie na pozycji: "<<i<<endl;
        }
        i=i+ max(1,j-p[j]);
        j=p[j];
    }
    delete []p;
}

void bm(string txt, string wz) {
    int n = txt.length();
    int m = wz.length();

    // tablica przesunięć
    int tab_prze[256];
    for(int i = 0; i < 256; i++) {
        tab_prze[i] = m;
    }
    for(int i = 0; i < m - 1; i++) {
        tab_prze[(int) wz[i]] = m - i - 1;
    }

    int s = 0;
    while(s <= (n - m)) {
        int j = m - 1;

        while(j >= 0 && wz[j] == txt[s+j]) {
            j--;
        }

        if(j < 0) {
            cout << "Ciag znakow zaczyna sie na pozycji: " << s << endl;
            s++;
        } else {
            s += max(1, tab_prze[(int) txt[s+j]] - (m - j - 1));
        }
    }
}


int main() {
    string tekst;
    string wz;
    while(true) {
        cout << "Zadanie 5.1 - 1\nZadanie 5.2 - 2\nZadanie 5.3 - 3\nZadanie 5.4 - 4\n0 - wyjscie" << endl;
        int a;
        cin >> a;
        if (a == 1) {
            cout<<"Podaj tekst i wzorzec"<<endl;
            cin>>tekst>>wz;
        } else if (a == 2) {
            naiwny(tekst,wz);
        } else if (a == 3) {
            kmp(tekst,wz);
        } else if (a == 4) {
            bm(tekst,wz);
        } else {
            return 0;
        }
    }
}
