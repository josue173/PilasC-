#include <iostream>
using namespace std;

struct Pila {
    int dato;
    struct Pila* sig;
};

struct Pila* cab = NULL;
struct Pila* tope = NULL;

struct Pila* crearNodoPila() {
    struct Pila* p;
    p = new Pila;
    if (p != NULL) {
        cout << "Ingrese dato: ";
        cin >> p->dato;
        p->sig = NULL;
    }
    return p;
}

void Insertar() {
    if (tope == NULL) {
        cab = crearNodoPila();
        tope = cab;
    } else {
        struct Pila* temp = tope;
        struct Pila* ant = NULL;
        while (temp != NULL) {
            ant = temp;
            temp = temp->sig;
        }
        ant->sig = crearNodoPila();
        tope = ant->sig;
    }
}

int main(int argc, char** argv) {
    char resp = 's';
    while (resp == 's') {
        Insertar();
        cout << "Quiere agregar mas? (s/n): ";
        cin >> resp;
    }

    struct Pila* p = cab;
    while (p != NULL) {
        cout << p->dato << " ";
        p = p->sig;
    }
    
    return 0;
}
