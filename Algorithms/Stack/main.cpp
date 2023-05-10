#include <iostream>
#include <fstream>

using namespace std;

struct element{
    int number;
    element* next;
};

void push(element*& stack, int value){
    element* el = new element;
    el->number=value;
    el->next=stack;
    stack=el;
}

void pop(element*& stack){
    element* temp = stack;
    stack = stack->next;
    delete temp;
}

bool isEmpty(element* stack){
    if(stack == nullptr){
        return true;
    }else{
        return false;
    }
}

int top(element* stack){
    return stack->number;
}

struct element2{
    char ele;
    element2* next;
};

void push2(element2*& stack, char value){
    element2* el = new element2;
    el->ele=value;
    el->next=stack;
    stack=el;
}

void pop2(element2*& stack){
    element2* temp = stack;
    stack = stack->next;
    delete temp;
}

bool isEmpty2(element2* stack){
    if(stack == nullptr){
        return true;
    }else{
        return false;
    }
}

char top2(element2* stack){
    return stack->ele;
}

int main() {
    while (true) {
        int a,c,dls;
        fstream plik;
        ofstream zapis;
        char linia;
        srand(NULL);
        element* stack = nullptr;
        element2* stack2 = nullptr;
        cout << "Ktore zadanie? 9.1 - 1, 9.2-2, wyjscie-3" << endl;
        cin >> a;
        switch (a) {
            case 1:
                while(true) {
                    int b;
                    cout << "Co zrobic ze stosem?" << endl;
                    cout << "Czy stos jest pusty? - 1" << endl;
                    cout << "Dodaj wartosc z przedzialu 1-10 - 2" << endl;
                    cout << "Usun element ze stosu - 3" << endl;
                    cout << "Pobierz ostatni element - 4" << endl;
                    cout << "Usun wszystskie elementy - 5" << endl;
                    cout << "Wyjscie - 6" << endl;
                    cin >> b;
                    switch (b) {
                        case 1:
                            if (isEmpty(stack)) {
                                cout << "Stos jest pusty" << endl;
                            }
                            break;
                        case 2:
                            c = rand() % 10 + 1;
                            push(stack, c);
                            break;
                        case 3:
                            if (!isEmpty(stack)) {
                                pop(stack);
                            } else {
                                cout << "Stos jest pusty" << endl;
                            }
                            break;
                        case 4:
                            cout << top(stack) << endl;
                            break;
                        case 5:
                            while (!isEmpty(stack)) {
                                pop(stack);
                            }
                            break;
                        case 6:
                            return 0;
                    }
                }
            case 2:
                plik.open("C:\\Users\\lenovo\\Downloads\\znaki1.txt");
                while (!plik.eof()) {
                    //getline(plik, linia);
                    linia = plik.get();
                    push2(stack2, linia);
                }
                plik.close();

                zapis.open("wyniki.txt");
                while(!isEmpty2(stack2)){
                    zapis << top2(stack2);
                    pop2(stack2);
                }
                zapis.close();
                break;
            case 3:
                return 0;
        }
    }
}
