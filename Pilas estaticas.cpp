
#include <iostream>//libreria estandar en c++ para entrada y salida de archivos

using namespace std;// Permite usar elementos del espacio de nombres estándar (std) sin prefijo, como cout y endl.

class PilaEstatica {
private://seccion de atributos privados
    static const int MAX = 10;//Tamaño fijo de la pila 
    int arr[MAX];//es el arreglo de la pila definido como constante
    int top;//indice del ultimo elementos insertado

public://seccion publica donde podran ser accesibles desde fuera de la clase
    PilaEstatica() : top(-1) { }//inicializador de la clase que inicia en top -1 indicando que la pila esta vacia
    bool push(int valor) {//declara un metodo push que permite insetar un nuevo valor en la pila y recibe un entero, nos devuelve
        if (top >= MAX - 1) {//verifica si el indice top llega al maximo permitido a max-1
            cout << "Pilas esta llena (overflow)." << endl;//si la condicion anterior es correcta nos muestra un mensaje en la consola 
            return false;//devuelve el valor falso si la condicion no se cumple y temina la ejecusion
        }
        arr[++top] = valor;//incrementa top e inserta el valor
        return true;//retorna true para indicar que la operacioin fue exitosa
    }

    int pop() {//define la funcion que elimina y devuelve el ultimo elemento agregado en la pila
        if (top < 0) {//verifica si el indice top llega al minimo de 0
            cout << "la pila esta vacia (underflow)." << endl;//muestra un mensaje advirtiendo que la pila esta vacia
            return -1;//valor de error 
        }
        return arr[top--];//devuelve el elemento y decrementa top

    }
    int peek()const {//define un metodo llamado peek que no modifica que nos permite verificar el siguiente objetivo
        if (top < 0) {//verifica si el indice top llega el minimo 0
            cout << "Pila vacia." << endl;//nos muestra un mensaje pila vacia
            return -1;//retorna a -1 para indicar que la operacion no fue valida
        }
        return arr[top];//devuelve el elemento que esta en la posicion top del arreglo
    }
};
int main(){//funcion principal del programa 
    PilaEstatica pila;//crea una instancia de la pila estatica que representa la pila
    pila.push(10);//añade el valor 10 a la pila
    pila.push(20);//añade el valor 20 a la pila 
    pila.push(30),//añade el valor 30 a la pila 
    cout << "Elemento en la cima: " << pila.peek() << endl;//llama al elemeto peek para consultar el eleento encima de lapila
    cout << "Elemento eliminado:" << pila.pop() << endl;//llama al elemento pop para eliminar el elemento en la cima de la pila
    cout << "Elemento eliminado:" << pila.pop() << endl;//llama al elemento pop para eleiminar otro elemento encima 
    return 0;//finaliza la ejecion del programa 
}
