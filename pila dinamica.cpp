// pila dinamica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>//biblioteca estandar en c++ para entrada y salida de archivos
using namespace std;//permite usar los elemntos del espacio estandar std sin necesidad de escribir std:: ante ellos
struct Nodo {//define una estructura llamada nodo
    int dato;//almacena un valor entero en el nodo
    Nodo* siguiente;//este es un puntero que apunta al siguiente nodo
};
class PilaDinamica {//define una clase llamada PilaDinamica
private:
        Nodo* cima;//apunta el nodo encima de la pila 
public:
    PilaDinamica():cima(nullptr){ }//constructor de la clase que inicializa cima como nullptr mostrando que la pila esta vacia

    ~PilaDinamica() {//destructor de la clase piladinamica
        while (cima != nullptr) {//inicializa un bucle para verificar si la pila tiene elementos 
            pop();//llama el metodo pop para eliminar el metodo cima
        }
    }
    void push(int valor) {//declara un metodo push que agrega unu nuevo elemeto con e valor proporcionado
        Nodo* nuevo = new Nodo;//crea un nuevo nodo en la memoria usada new
        nuevo->dato = valor;//almacena el valor en el campo dato del nuevo nodo
        nuevo->siguiente = cima;//enlaza ek nuevo nodo que esta encima
        cima = nuevo;//actualiza cima 
    }
    int pop() {//metodo para eliminar el elemento en la cima de la pila y devolver su valor
        if (cima == nullptr) {//verifica si la pila esta vacia
            cout << "Pila vacia(underflow)." << endl;//muestra en la consola un mensaje pilavacia
            return -1;//valor de error 
        }
        Nodo* temp = cima;//crea un nodo temporal que apunta al nodo actual
        int valor = temp->dato;//actualiza la cima que apunta al siguiente nodo
            cima = cima->siguiente;//la nueva sima es el siguinete nodo
        delete temp;//elimina la momeria del nodo temporal
        return valor;//devuelve el valor del nodo eliminado
    }
    int peek()const {//metodo para obtener el elemento en la cima de la pila
        if (cima == nullptr) {//verifica si la pila esta vacia
            cout << "Pila vacia:" << endl;//muestra un mensaje pila vacia
            return -1;//devuelve el valor de error 
        }
        return cima->dato;//retorna el valor almacenado en la cima
    }
};
int main()//funcion principal del programa 
{
    PilaDinamica pila;//crea una instancia de la clase pila dinamica
    pila.push(100);//agrega el valor 100 
    pila.push(200);//agrega el valor 200 a la pila
    pila.push(300);//agrega el valor 300 a  la pila
    cout << "Eleneto en la cima: " << pila.peek()<< endl;//deberia mostrar 300
    cout << "Elmento eliminado: " << pila.pop() << endl,//300
        cout << "Elemnto eliminado:" << pila.pop() << endl;//200
    return 0;//finaliza la ejecucon del programa 
}

