#include "ProgramasHeader.h"

int main()
{

    caratula();

    int opcMenu = 0;

    do
    {
        cout << "\n\nOpc 1. Metodos abiertos\n";
        cout << "Opc 2. Eliminacion Gaussiana\n";
        cout << "Opc 0. Salida\n\n";
        cin >> opcMenu;

        switch (opcMenu)
        {
        case 1:
            metodosAbiertos();
            break;

        case 2:
            eliminacionGauss();
            break;

        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
            break;
        }

    } while (opcMenu != 0);

    return 0;
}
