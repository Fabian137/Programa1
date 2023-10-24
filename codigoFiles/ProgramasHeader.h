#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <complex>
#include <math.h>

using namespace std;

//[Se define la macro como el valor donde se paran las iteraciones]
#define ERROR_TOLE 0.00005

//[FUNCION PARA LA IMPRESION DE UNA CARATULA]
void caratula()
{
    cout << "\t\tPrograma 1.\n\n";
    cout << "Equipo 1. \n\nIntegrantes: \n\n";
    cout << "Beltran Isidro Carlos\n\n";
    cout << "Diaz Valdez Fidel\n\n";
    cout << "Chaparro Blas Adrian Alexis\n\n";
    cout << "Gomez Herrera Cristian Yair\n\n";
    cout << "Proposito: Dadas 4 funciones encontrar sus raices correspondientes mediante los mÃ©todos, ya sean de Secante o de Newton. Permitir que el usuario ingrese el intervalo o valor inicial. \n\n";
    cout << "\t\tComienzo de Programa: \n\n";
}

//[FUNCIONES DE LAS ECUACIONES]
float primeraFunc(float valInput)
{
    return (pow(valInput, 2) * cos(valInput)) - (2 * valInput);
}

float segundoFunc(float valInput)
{
    return ((6 - (2 / pow(valInput, 2))) * ((exp(2 + valInput)) / 4)) + 1;
}

float tercerFunc(float valInput)
{
    return (pow(valInput, 3)) - (3 * sin(pow(valInput, 2))) + 1;
}

float cuartaFunc(float valInput)
{
    return (pow(valInput, 3)) + (6 * pow(valInput, 2)) + (9.4 * valInput) + 2.5;
}

//[FUNCIONES PARA LAS DERIVADAS]
float primeraDer(float valInput)
{
    return (-pow(valInput, 2) * sin(valInput)) + ((2 * valInput) * (cos(valInput))) - 2;
}
/*

float segundoDer(float valInput){
    return ((1 / 4) * exp(2 + valInput)) * ((6 - (2 / pow(valInput, 2))) + (4 / pow(valInput, 3)));
}
Se hacia cero porque c++ toma 1/4 como entero y pues es cero. Btw habï¿½a que cambiar un poco la derivada.
Tuve el mismo error con 1/2
*/

float segundoDer(float valInput)
{
    return (0.5) * (((2 * exp(valInput + 2)) - (valInput * exp(valInput + 2)) + (3 * pow(valInput, 3)) * (exp(valInput + 2))) / pow(valInput, 3));
}

float tercerDer(float valInput)
{
    return (3 * pow(valInput, 2)) - (6 * valInput * cos(pow(valInput, 2)));
}

float cuartaDer(float valInput)
{
    return (3 * pow(valInput, 2)) + (12 * valInput) + 9.4;
}

/*[FUNCION PARA EL METODO DE LA SECANTE]
cotaI es el valor del intervalo por el lado izquierdo
cotaD es el valor del intervalo por el lado derecho
opc determina a que funcion se le buscara raices*/

void raizSecante(float cotaI, float cotaD, int opc)
{
    float x_0 = cotaI, x_1 = cotaD, x_2 = 0, f_0 = 0, f_1 = 0, f_2 = 0, errorA = 0, errorR = 0;
    bool flagExit = false;

    if (opc == 1)
    {
        cout << "\t\n[PRIMERA FUNCION POR SECANTE: x^2 cos(x) - 2x]\n";
        f_0 = primeraFunc(x_0);
        f_1 = primeraFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = primeraFunc(x_2);
    }

    if (opc == 2)
    {

        cout << "\t\n[SEGUNDA FUNCION POR SECANTE: (6 - 2/x^2) (e^2+x /4) + 1]\n";

        while (x_1 == 0 || x_0 == 0)
        {
            cout << "\n\t[EL VALOR NO ESTA DEFINIDO EN LA FUNCION, INTRODUCE UNO NUEVO]\n";
            if (x_1 == 0)
                cin >> x_1;
            if (x_0 == 0)
                cin >> x_0;
        }

        f_0 = segundoFunc(x_0);
        f_1 = segundoFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = segundoFunc(x_2);
    }

    if (opc == 3)
    {
        cout << "\t\n[TERCERA FUNCION POR SECANTE: x^3 - 3sen(x^2) + 1]\n";
        f_0 = tercerFunc(x_0);
        f_1 = tercerFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = tercerFunc(x_2);
    }

    if (opc == 4)
    {
        cout << "\t\n[CUARTA FUNCION POR SECANTE: x^3 + 6x^2 + 9.4x]\n";
        f_0 = cuartaFunc(x_0);
        f_1 = cuartaFunc(x_1);

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));
        f_2 = cuartaFunc(x_2);
    }

    if (opc < 1 || opc > 4)
        flagExit = true;
    else
        printf("\n\t[     x_0    ] [     x_1    ] [     f_0    ] [     f_1    ] [     x_2    ] [     f_2    ] [     Ea     ] [     Er     ]\n");

    do
    {
        if (flagExit == false)
            printf("\t[%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f]\n", x_0, x_1, f_0, f_1, x_2, f_2, errorA, errorR);

        x_0 = x_1;
        f_0 = f_1;

        x_1 = x_2;
        f_1 = f_2;

        x_2 = x_1 - ((f_1) * ((x_1 - x_0) / (f_1 - f_0)));

        if (opc == 1)
            f_2 = primeraFunc(x_2);

        if (opc == 2)
            f_2 = segundoFunc(x_2);

        if (opc == 3)
            f_2 = tercerFunc(x_2);

        if (opc == 4)
            f_2 = cuartaFunc(x_2);

        errorA = fabs(x_2 - x_1);
        errorR = fabs(errorA / x_2);

    } while (errorA > ERROR_TOLE && flagExit != true);

    if (flagExit == true)
        cout << endl
             << "\t[Opcion no valida]" << endl;
    else
    {
        printf("\t[%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f]\n", x_0, x_1, f_0, f_1, x_2, f_2, errorA, errorR);
        printf("\t[LA RAIZ ES: %12.6f]\n\n", x_1);
    }
}

void raizNewton(float valX, int opc)
{
    float x_0 = valX, x_1 = 0, f_0 = 0, f_1 = 0, errorA = 0, errorR = 0;
    bool flagExit = false;
    int cantidad_derivadas = 0;

    if (opc < 1 || opc > 4)
        flagExit = true;
    else
    {
        do
        {
            if (opc == 1)
            {
                cout << "\t\n[PRIMERA FUNCION POR NEWTON: x^2 cos(x) - 2x]\n";
                f_0 = primeraFunc(x_0);
                f_1 = primeraDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 2)
            {

                cout << "\t\n[SEGUNDA FUNCION POR NEWTON: (6 - 2/x^2) (e^2+x /4) + 1]\n";
                f_0 = segundoFunc(x_0);
                f_1 = segundoDer(x_0);

                if (x_0 >= 0)
                {

                    if (x_0 == 0)
                    {
                        printf("\tf'(%12.6f) = %12.6f\n", x_0, f_1);
                        printf("\t NO SE PUEDE EVALUAR\n");
                        return;
                    }
                    else if (x_0 > 15)
                    {
                        printf("\tLa funcion tiende a infinito y NO es tan recomendable por Newton: valor de f'(%12.6f) = %12.6f\n", x_0, f_1);
                        return;
                    }
                }
                else if (x_0 < -1)
                {
                    cout << "\t\n La derivida del punto dado tiende a cero.!!\n Hay una asintota en y = 1\n";
                    cout << "\t\n Se modificara el valor de x_0 por -0.75\n";

                    x_0 = -0.75;
                    f_1 = segundoDer(x_0);
                    printf("\t[     x_0    ] [     f_x    ]\n");
                    printf("\t[%12.6f] [%12.6f] \n", x_0, f_1);
                }
                else
                {
                    f_1 = segundoDer(x_0);
                    printf("\t[%12.6f] [%12.6f] \n", x_0, f_1);
                }

                //                cout << f_1;

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 3)
            {
                cout << "\t\n[TERCERA FUNCION POR NEWTON: x^3 - 3sen(x^2) + 1]\n";
                f_0 = tercerFunc(x_0);
                f_1 = tercerDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 4)
            {
                cout << "\t\n[CUARTA FUNCION POR NEWTON: x^3 + 6x^2 + 9.4x]\n";
                f_0 = cuartaFunc(x_0);
                f_1 = cuartaDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (f_1 == 0)
            {
                printf("\t[LA DERIVADA EVALUADA EN EL PUNTO %12.2f ES IGUAL A %12.2f, INTENTAR OTRO INTERVALOR]\n", x_0, f_1);
                cin >> x_0;
                cantidad_derivadas++;
            }

        } while (f_1 == 0 && cantidad_derivadas <= 3);
        if (cantidad_derivadas > 2)
        {
            printf("\tLA FUNCIï¿½N NO ES VIABLE POR EL Mï¿½TODO DE NEWTON");
            return;
        }
    }

    if (0 < opc && opc < 5)
        printf("\n\t[     x_0    ] [     f_x    ] [    f'_x    ] [     x_1    ] [     Ea     ] [     Er     ]\n");

    do
    {
        if (flagExit == false)
            printf("\t[%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f]\n", x_0, f_0, f_1, x_1, errorA, errorR);

        x_0 = x_1;

        if (opc == 1)
        {
            f_0 = primeraFunc(x_0);
            f_1 = primeraDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 2)
        {
            f_0 = segundoFunc(x_0);
            f_1 = segundoDer(x_0);

            x_1 = x_0 - f_0 / f_1;
        }

        if (opc == 3)
        {
            f_0 = tercerFunc(x_0);
            f_1 = tercerDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 4)
        {
            f_0 = cuartaFunc(x_0);
            f_1 = cuartaDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        errorA = fabs(x_1 - x_0);
        errorR = fabs(errorA / x_1);

    } while (errorA > ERROR_TOLE && flagExit != true);

    if (flagExit == true)
        cout << endl
             << "\t[Opcion no valida]" << endl;
    else
    {
        printf("\t[%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f] [%12.6f]\n", x_0, f_0, f_1, x_1, errorA, errorR);
        printf("\t[LA RAIZ ES: %12.6f]\n\n", x_1);
    }
}

void metodo(int funcion)
{
    int opcion;
    float x0, x1, x;

    do
    {
        cout << "\n\nElecciÃ³n de MÃ©todo: \n\n";
        cout << "1. Secante\n";
        cout << "2. Newton-Raphson\n\n";
        cout << "Seleccione una opciÃ³n: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 2)
        {
            cout << "OpciÃ³n no vÃ¡lida. Por favor, elija una opciÃ³n vÃ¡lida." << endl;
        }

    } while (opcion < 1 || opcion > 2);

    if (opcion == 1)
    {
        cout << "\n\nSe eligiÃ³ el mÃ©todo de la Secante.\n\n";
        cout << "Da el valor del x_ 0: ";
        cin >> x0;
        cout << "Da el valor del x_1: ";
        cin >> x1;
        raizSecante(x0, x1, funcion);
    }
    else
    {
        cout << "\n\nSe eligiÃ³ Newton.\n\n";
        cout << "Da el valor de x: ";
        cin >> x;
        raizNewton(x, funcion);
    }
}

int menuDos()
{
    int opcion;

    cout << "\n\nOpc 1. Funcion 1: x^2 cos(x) - 2x\n";
    cout << "Opc 2. Funcion 2: (6 - 2/x^2) (e^2+x /4) + 1\n";
    cout << "Opc 3. Funcion 3: x^3 - 3sen(x^2) + 1\n";
    cout << "Opc 4. Funcion 4: x^3 + 6x^2 + 9.4x\n";
    cout << "Opc 0. Salida\n\n";

    // Pedir al usuario que elija una opciÃ³n
    cout << "Seleccione una opciÃ³n: ";
    cin >> opcion;

    return opcion;
}

void metodosAbiertos()
{
    int respuesta = 0, opcDos = 0;

    do
    {
        respuesta = menuDos();

        switch (respuesta)
        {
        case 1:
            metodo(respuesta);
            break;
        case 2:
            cout << "\n\nTener en cuenta que la funciÃ³n no es continua, por ende es complicado encontrar la raiz por medio de Newton\n\n";
            metodo(respuesta);
            break;
        case 3:
            metodo(respuesta);
            break;
        case 4:
            metodo(respuesta);
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "OpciÃ³n no vÃ¡lida. Por favor, elija una opciÃ³n vÃ¡lida." << endl;
            break;
        }

    } while (opcDos != 0);
}

// FunciÃ³n para obtener el determinante de una matriz
double determinante(vector<vector<double>> &matriz, int n)
{
    double det = 1.0;

    for (int i = 0; i < n; i++)
    {
        int maxRow = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(matriz[j][i]) > abs(matriz[maxRow][i]))
            {
                maxRow = j;
            }
        }

        if (maxRow != i)
        {
            swap(matriz[i], matriz[maxRow]);
            det *= -1.0;
        }

        det *= matriz[i][i];

        if (abs(det) < 1e-9)
        {
            return 0.0; // La matriz es singular
        }

        for (int j = i + 1; j < n; j++)
        {
            for (int k = n - 1; k >= i; k--)
            {
                matriz[j][k] -= matriz[i][k] * (matriz[j][i] / matriz[i][i]);
            }
        }
    }

    return det;
}

void printMatriz(vector<vector<double>> &mat, vector<double> &vec, int n)
{
    cout << "Matriz proporcionada. \n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%7.2f ", mat[i][j]);
        }

        printf(" | %7.2f\n", vec[i]);
    }
}

void eliminacionGauss()
{
    int n;

    cout << "1. Ingrese la dimensiÃ³n n de la matriz: ";
    cin >> n;

    vector<vector<double>> matriz(n, vector<double>(n));
    vector<double> vectorIndependiente(n);

    // Lectura de la matriz y el vector independiente
    cout << "2. Ingrese los coeficientes de la matriz por renglÃ³n:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "RenglÃ³n " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            cin >> matriz[i][j];
        }
        cout << "Valor en el vector independiente: ";
        cin >> vectorIndependiente[i];
    }

    // Verificar y corregir la matriz si es necesario
    char correccion;

    printMatriz(matriz, vectorIndependiente, n);
    cout << "3. Â¿Los datos son correctos? (S/N): ";
    fflush(stdin);
    cin >> correccion;

    while (correccion == 'N' || correccion == 'n')
    {
        int fila, columna;
        double nuevoValor;

        cout << "Ingrese la fila y columna del coeficiente a corregir: ";
        cin >> fila >> columna;

        if (fila >= 1 && fila <= n && columna >= 1 && columna <= n)
        {
            cout << "Ingrese el nuevo valor: ";
            cin >> nuevoValor;
            matriz[fila - 1][columna - 1] = nuevoValor;
        }

        printMatriz(matriz, vectorIndependiente, n);
        cout << "3. Â¿Los datos son correctos? (S/N): ";
        fflush(stdin);
        cin >> correccion;
    }

    // Calcular el determinante
    double det = determinante(matriz, n);

    if (det != 0)
    {
        cout << "4. El determinante de la matriz es: " << det << endl;

        // Verificar si la matriz es dominante diagonalmente
        bool esDominante = true;

        for (int i = 0; i < n; i++)
        {
            double suma = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    suma += abs(matriz[i][j]);
                }
            }

            if (abs(matriz[i][i]) <= suma)
            {
                esDominante = false;
                break;
            }
        }

        if (esDominante)
        {
            cout << "5. La matriz es dominante diagonalmente." << endl;
            // Implementar el resto de las opciones
        }
        else
        {
            cout << "5. La matriz no es dominante diagonalmente." << endl;
            // Obtener el determinante por triangulaciÃ³n y continuar con las opciones
        }

        // Implementar el resto de las opciones
    }
    else
    {
        cout << "4. El determinante es igual a cero, el sistema asociado no tiene soluciÃ³n." << endl;
    }
}