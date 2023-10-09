#include "ProgramaUnoHeader.h"

int menu();
int metodo(int funcion);
void caratula();

int main() {
    int respuesta, eleccion; 
    float x0, x1, x;
    caratula();
    
    do {
        respuesta = menu();

        switch (respuesta) {
            case 1:                
                eleccion = metodo(respuesta);
                break;
            case 2:
                cout << "\n\nTener en cuenta que la función no es continua, por ende es complicado encontrar la raiz por medio de Newton\n\n"; 
                eleccion = metodo(respuesta);
                break;
            case 3:
                eleccion = metodo(respuesta);
                break;
            case 4:
                eleccion = metodo(respuesta);
                break;
            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, elija una opción válida." << endl;
                break;
        }

    } while (respuesta != 0);

    return 0;
}

int menu() {
    int opcion;
    
    cout << "\n\nFuncion 1: x^2 cos(x) - 2x\n";
    cout << "Funcion 2: (6 - 2/x^2) (e^2+x /4) + 1\n";
    cout << "Funcion 3: x^3 - 3sen(x^2) + 1\n";
    cout << "Funcion 4: x^3 + 6x^2 + 9.4x\n";
    cout << "0. Salida\n\n";

    // Pedir al usuario que elija una opción
    cout << "Seleccione una opción: ";
    cin >> opcion;
    
    return opcion;
}

int metodo(int funcion) {
    int opcion;
    float x0, x1, x;
    
    do {
        cout << "\n\nElección de Método: \n\n";
        cout << "1. Secante\n";
        cout << "2. Newton-Raphson\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion < 1 || opcion > 2) {
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }

    } while (opcion < 1 || opcion > 2);

    if(opcion == 1){
        cout << "\n\nSe eligió el método de la Secante.\n\n";
        cout << "Dame el valor del x_ 0: ";
        cin >> x0; 
        cout << "Dame el valor del x_1: ";
        cin >> x1;
        raizSecante(x0, x1, funcion);
    }else{
        cout << "\n\nSe eligió Newton.\n\n";
        cout << "Dame el valor de x: ";
        cin >> x;
        raizNewton(x, funcion);
    }

    return opcion;
}

void caratula(){
    cout << "\t\tPrograma 1.\n\n";
    cout << "Equipo 1. \n\nIntegrantes: \n\n"; 
    cout << "Beltran Isidro Carlos\n\n";
    cout << "Diaz Valdez Fidel\n\n";
    cout << "Chaparro Blas Adrian Alexis\n\n";
    cout << "Gomez Herrera Cristian Yair\n\n";
    cout << "Proposito: Dadas 4 funciones encontrar sus raices correspondientes mediante los métodos, ya sean de Secante o de Newton. Permitir que el usuario ingrese el intervalo o valor inicial. \n\n";
    cout << "\t\tComienzo de Programa: \n\n";

}