#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include <complex>
#include <math.h>
#include <limits>


using namespace std;

//[Se define la macro como el valor donde se paran las iteraciones]
#define ERROR_TOLE 0.00005

//[FUNCION PARA LA IMPRESION DE UNA CARATULA]
void caratula()
{
    cout << "\t\tPrograma 3.\n\n";
    cout << "Equipo 1. \n\nIntegrantes: \n";
    cout << "Beltrán Isidro Carlos Fabián\n";
    cout << "Díaz Valdez Fidel\n";
    cout << "Chaparro Blas Adrian Alexis\n";
    cout << "Goméz Herrera Cristian Yair\n";
    cout << "Propósito: Resolver un sistema de ecuaciones ingresado en su forma matricial por el método de Jacobi \n\n";
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

void raizNewton(float valX, int opc){
    float x_0 = valX, x_1 = 0, f_0 = 0, f_1 = 0, errorA = 0, errorR = 0;
    bool flagExit = false;
    int cantidad_derivadas = 0;

    if (opc < 1 || opc > 4)
        flagExit = true;
    else
    {
        do{
            if (opc == 1){
                cout << "\t\n[PRIMERA FUNCION POR NEWTON: x^2 cos(x) - 2x]\n";
                f_0 = primeraFunc(x_0);
                f_1 = primeraDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 2){

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
                else if (x_0 <= -1){
                    cout << "\t\n La derivida del punto dado tiende a cero.!!\n Hay una asintota en y = 1\n";
                    cout << "\t\n Se modificara el valor de x_0 por -0.75\n";

                    x_0 = -0.75;
                    f_1 = segundoDer(x_0);
                    printf("\t[     x_0    ] [     f_x    ]\n");
                    printf("\t[%12.6f] [%12.6f] \n", x_0, f_1);
                }
                else{
                    f_1 = segundoDer(x_0);
                    printf("\t[%12.6f] [%12.6f] \n", x_0, f_1);
                }

                //                cout << f_1;

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 3){
                cout << "\t\n[TERCERA FUNCION POR NEWTON: x^3 - 3sen(x^2) + 1]\n";
                f_0 = tercerFunc(x_0);
                f_1 = tercerDer(x_0);

                x_1 = x_0 - (f_0 / f_1);
            }

            if (opc == 4){
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
            printf("\tLA FUNCIÃ¯Â¿Â½N NO ES VIABLE POR EL MÃ¯Â¿Â½TODO DE NEWTON");
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

        if (opc == 1){
            f_0 = primeraFunc(x_0);
            f_1 = primeraDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 2){
            f_0 = segundoFunc(x_0);
            f_1 = segundoDer(x_0);

            x_1 = x_0 - f_0 / f_1;
        }

        if (opc == 3){
            f_0 = tercerFunc(x_0);
            f_1 = tercerDer(x_0);

            x_1 = x_0 - (f_0 / f_1);
        }

        if (opc == 4){
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

    do{
        cout << "\n\nElección de Método: \n\n";
        cout << "1. Secante\n";
        cout << "2. Newton-Raphson\n\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 2){
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
        }

    } while (opcion < 1 || opcion > 2);

    if (opcion == 1)
    {
        cout << "\n\nSe eligió el método de la Secante.\n\n";
        cout << "Da el valor del x_ 0: ";
        cin >> x0;
        cout << "Da el valor del x_1: ";
        cin >> x1;
        raizSecante(x0, x1, funcion);
    }
    else
    {
        cout << "\n\nSe eligió Newton.\n\n";
        cout << "Da el valor de x: ";
        cin >> x;
        raizNewton(x, funcion);
    }
}

int menuDos(){
    int opcion;

    cout << "\n\nOpc 1. Funcion 1: x^2 cos(x) - 2x\n";
    cout << "Opc 2. Funcion 2: (6 - 2/x^2) (e^2+x /4) + 1\n";
    cout << "Opc 3. Funcion 3: x^3 - 3sen(x^2) + 1\n";
    cout << "Opc 4. Funcion 4: x^3 + 6x^2 + 9.4x\n";
    cout << "Opc 0. Salida\n\n";

    // Pedir al usuario que elija una opción
    cout << "Seleccione una opción: ";
    cin >> opcion;

    return opcion;
}

void metodosAbiertos(){
    int respuesta = 0, opcDos = 0;

    do{
        respuesta = menuDos();

        switch (respuesta){
        case 1:
            metodo(respuesta);
            break;
        case 2:
            cout << "\n\nTener en cuenta que la función no es continua, por ende es complicado encontrar la raiz por medio de Newton\n\n";
            metodo(respuesta);
            break;
        case 3:
            metodo(respuesta);
            break;
        case 4:
            metodo(respuesta);
            break;
        case 0:
            cout << "\nSaliendo del programa." << endl;
            break;
        default:
            cout << "Opción no válida. Por favor, elija una opción válida." << endl;
            break;
        }

    } while (opcDos != 0);
}

// Función para obtener el determinante de una matriz
double determinante(vector<vector<double> > matriz, int n)
{
    double det = 1.0;

    for (int i = 0; i < n; i++){
        int maxRow = i;
        for (int j = i + 1; j < n; j++){
            if (abs(matriz[j][i]) > abs(matriz[maxRow][i])){
                maxRow = j;
            }
        }

        if (maxRow != i){
            swap(matriz[i], matriz[maxRow]);
            det *= -1.0;
        }

        det *= matriz[i][i];

        if (abs(det) < 1e-9){
            return 0.0; // La matriz es singular
        }

        for (int j = i + 1; j < n; j++){
            for (int k = n - 1; k >= i; k--){
                matriz[j][k] -= matriz[i][k] * (matriz[j][i] / matriz[i][i]);
            }
        }
    }

    return det;
}

void printMatriz(vector<vector<double> > &mat, vector<double> &vec, int n){
    cout << "Matriz proporcionada. \n\n";

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%7.2f ", mat[i][j]);
        }
        printf(" | %7.2f\n", vec[i]);
    }
    cout << "\n\n";
}


void dominanteDiagonalmente(const vector<vector<double> > & matrizA){
    int numMaxDiagonal = 0, j, i , n = matrizA.size();
    double diagonal, sums = 0;
    vector<double> diagonalesIntercambio(n, 0.0);

    for ( i = 0; i < n; i++){
            // diagonalValor=matrizA[i][i];
        for (j = 0; j < n; j++){
            if (i != j){
                sums += abs(matrizA[i][j]);
            }
        }
        if (matrizA[i][i] > sums || matrizA[i][i] == sums){
            numMaxDiagonal ++;
        }else{
            diagonalesIntercambio[i] = i;
        }
        sums = 0;
    }

    if (numMaxDiagonal == n){
        std::cout << "\n\n\t--------------La matriz es EDD--------------\n\n";
    }
    else{
        std::cout << "\n\n\t--------------La convergencia no se garantiza por no tratarse de un sistema EDD --------------\n\n";
    }
}

double normaEspectral(const vector<double> & vector1, const vector<double> & vector2) {
    double maxDiferencia = 0.0;
    int i;
    for (i = 0; i < vector1.size(); ++i) {
        double diferencia = abs(vector2[i] - vector1[i]);
        maxDiferencia = max(maxDiferencia, diferencia);
    }

    return maxDiferencia;
}

void metodoJacobi(vector<vector<double> > matrizA, vector<double> vectorB, vector<double>& vectorInicial, int maxIteraciones, double tolerancia) {
    int i, j, k, n = matrizA.size();
    vector<double> x = vectorInicial;
    double error= 0;
    dominanteDiagonalmente(matrizA);
    int a; 


// -------  "Depeje"
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            if (i != j && matrizA[i][i] != 0){
                matrizA[i][j] =  -1 * (matrizA[i][j] / matrizA[i][i]);
            }
        }
        vectorB[i] = vectorB[i] / matrizA[i][i]; 
                
    }
    

// ------- ITERCACIONES
    // vector<double> x(n, 1);
    vector<double> xSiguiente(n, 0.0);

    for ( k = 0; k < maxIteraciones; ++k) {
        a = 1;

        for ( i = 0; i < n; ++i) {
            double suma = 0.0;
            for ( j = 0; j < n; ++j) {
                if (i != j) {
                    suma += matrizA[i][j] * x[j];
                }
            }
            xSiguiente[i] = suma + vectorB[i];
        }

            error = normaEspectral(x, xSiguiente);
        // Calcular el error por norma espectral
        // double error = normaVector(productoMatrizVector(matrizA, xSiguiente)normaVector) - vectorB;

        // Mostrar la sucesión de vectores y el error
        std::cout << "Iteración " << k + 1 << ": ";
        
		for(i = 0; i<xSiguiente.size(); i++){
			printf("x_%d: %9.6f    ", i+1, xSiguiente[i]);
            
		}
        std::cout << "Error: " << error << endl;

        // Verificar si se ha alcanzado la tolerancia
        if (error < tolerancia) {
            std::cout << "\nConvergencia alcanzada. Solución obtenida:\n";
           
            for(i = 0; i<xSiguiente.size(); i++){
				printf("x_%d: %9.6f    ", i+1, round(xSiguiente[i]));
			}
    
            std::cout << endl;
            return;
        }

        x = xSiguiente;
    }

    std::cout << "\nSe alcanzó el número máximo de iteraciones sin convergencia.\n";
            for(i = 0; i<xSiguiente.size(); i++){
				printf("x_%d: %9.6f    ", i+1, round(xSiguiente[i]));
			}
            std::cout << endl;
            return;
}

int simetrica(std::vector<std::vector<double> >& matriz, int n){
    int control = 0;

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(matriz[i][j] != matriz[j][i]){
                control = 1;
               printf("\n\n La matriz no es simetrica\n\n");
                return 1;
            }
        }
    }
    // if( control == 1){
        // return 1; 
    // }else{
        printf("\n\n La matriz es simetrica\n\n");
        return 0; 
    // }
}

/*
bool esSimetrica(const std::vector<std::vector<double>>& matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }
    return true;
}
*/

std::vector <double> sustitucionHaciaDelante(std::vector<std::vector<double> >& matriz, const std::vector<double>b) {
    int n = matriz.size();
    std::vector<double> resultado(n, 0.0);

    for (int i = 0; i < n; ++i) {
        resultado[i] = b[i];

        for (int j = 0; j < i; ++j) {
            resultado[i] -= matriz[i][j] * resultado[j];
        }

        resultado[i] /= matriz[i][i];
    }

    return resultado;
}

std::vector <double> sustitucionHaciaAtras(std::vector<std::vector<double> >& matriz, const std::vector<double> &b) {
    int n = matriz.size();
    std::vector<double> resultado(n, 0.0);

    for (int i = n - 1; i >= 0; --i) {
        resultado[i] = b[i];

        for (int j = i + 1; j < n; ++j) {
            resultado[i] -= matriz[i][j] * resultado[j];
        }

        resultado[i] /= matriz[i][i];
    }

    return resultado;
}

int defPostiva(vector<vector<double> > matriz, int n){
    int i;
    double det;

    for ( i = 1; i < n; i++){
        det = determinante(matriz, i+1);
        if (det <= 0) {
            return 0;
        }
        
    }
    return 1;
}

void CholeskyAlgorithm(std::vector<std::vector<double> >& matriz) {
    int i,j,n = matriz.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; ++k){
                    sum += pow(matriz[j][k], 2);
                }
                matriz[j][j] = sqrt(matriz[j][j] - sum);
            } else {
                for (int k = 0; k < j; ++k){
                    sum += (matriz[i][k] * matriz[j][k]);
                }
                if (matriz[j][j] > 0){
                    matriz[i][j] = (matriz[i][j] - sum) / matriz[j][j];
                }
                else {
                    std::cout << "La matriz no es definida positiva" << std::endl;
                    return;
                }
            }
        }
    }

    for ( i = 0; i < n; ++i) {
        for ( j = i + 1; j < n; ++j) {
            matriz[i][j] = 0.0;
        }
    }
}

void LowUpeer(std::vector<std::vector<double> >& matriz, std::vector<std::vector<double> >& L, std::vector<std::vector<double> >& U){
    int i,j,n=matriz.size();
    for (i = 0; i < n; i++){
        L[i][i] = matriz[i][i];
        U[i][i] = matriz[i][i];
        
        for ( j = 0; j < n; j++){
            if (i != j){
                L[i][j] = matriz[i][j]; 
                U[j][i] = matriz[i][j];
            }
        }
    }
    
}

void printSolucion(const std::vector<double>&res, int n){
    int i;
    printf( "\n\n");
    for ( i = 0; i < n; i++){
        printf("| \t %7.2f \t | \n", res[i]);
    }
    printf( "\n\n");
    

}


void opcionSitemaEcuaciones(){
    int control;
    int eleccion = 10;
    // Lectura de la matriz y cálculo del determinante
    int n;
    char txtContinuar;
    std::cout << "Ingrese el tamaño de la matriz cuadrada: ";
    std::cin >> n;

    vector<vector<double> > matriz(n, vector<double>(n));
    //Matriz para choelsky
    vector<vector<double> > matrizB(n, vector<double>(n));
    vector<double> vectorIndependiente(n);   
    
    std::cout << "\n\t2.1 Lectura de la matriz\n\n";
    std::cout << "\n Ingrese los elementos de la matriz por filas:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "Elemento en la posición [" << i+1 << "][" << j+1 << "]: ";
            std::cin >> matriz[i][j];
        }
        std::cout << "\n";
    }

    // Comprobar si la matriz es cuadrada
    if (n != matriz[0].size()) {
        std::cout << "La matriz no es cuadrada. Vuelva a ingresar una matriz cuadrada.\n";
        return;
    }

    std::cout << "Ingrese los elementos del vector independiente de términos constantes:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Elemento x_" << i+1 <<": ";
        std::cin >> vectorIndependiente[i];
    }

    // Verificar y corregir la matriz si es necesario
    char correccion, otroVector;

    printMatriz(matriz, vectorIndependiente, n);
    cout << "¿Los datos son correctos? (S/N): ";
    fflush(stdin);
    cin >> correccion;

    while (correccion == 'N' || correccion == 'n'){
        int fila, columna;
        double nuevoValor;

        cout << "Ingrese la fila del elemento a modificar: ";
        cin >> fila;
        cout << "\nIngrese la columna del elemento a modificar: ";
        cin >> columna;

        if (fila >= 1 && fila <= n && columna >= 1 && columna <= n){
            cout << "Ingrese el nuevo valor: ";
            cin >> nuevoValor;
            matriz[fila - 1][columna - 1] = nuevoValor;
        }
        else if (fila>n || columna >n){
            cout << "Ingrese el nuevo valor en el Vector Independiente: ";
            cin >> nuevoValor;
            vectorIndependiente[fila-1] = nuevoValor;
        }

        printMatriz(matriz, vectorIndependiente, n);
        cout << "¿Los datos son correctos? (S/N): ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> correccion;
    }

    // Calcular el determinante
    double det = determinante(matriz, n);
    vector<double> vectorInicial(n);
    int simetria, definidaPostiva; 

    if (det != 0){
        cout << "\nEl determinante de la matriz es: " << det << endl;
        control = 10;
        while(control != 0){
            cout << "\n\n\tOpc 2.2 Solución del sistema por Jacobi (2)\n";
            cout << "\n\n\tOpc 2.3 Solución del sistema por Cholesky (3)\n";
            cout << "\n\tOpc 0 Salida (0)\n";
            cout << "\n\n Dame la opcion que quieres usar según su numero\n";
            std::cout << "Ingrese el número aquí: ";
            std::cin >> control;

            switch (control){
            case 2:
                std::cout << "Ingrese el vector inicial:\n";
                for (int i = 0; i < n; ++i) {
                    std::cout << "Elemento x_" << i+1 <<": ";
                    std::cin >> vectorInicial[i];
                }
                int maxIteraciones;
                double tolerancia;
                std::cout << "Ingrese el número máximo de iteraciones: ";
                std::cin >> maxIteraciones;
                std::cout << "Ingrese la tolerancia: ";
                std::cin >> tolerancia;


                metodoJacobi(matriz, vectorIndependiente, vectorInicial, maxIteraciones, tolerancia);
                break;
            
            case 3:
                simetria = simetrica(matriz, n);
                definidaPostiva = defPostiva(matriz, n);
                if(simetria != 1 && definidaPostiva == 1 ){
                    std::vector<std::vector<double> > L(n, std::vector<double>(n, 0.0));
                    std::vector<std::vector<double> > U(n, std::vector<double>(n, 0.0));
                    std::vector<double> resultado(n, 0.0);

                    CholeskyAlgorithm(matriz);
                    LowUpeer(matriz, L,U);
                    printf("\nMatriz factorizada\n");
                    printMatriz(L, vectorIndependiente, n);
                    printf("\n--Sustitución hacia adelante--\n");
                    resultado = sustitucionHaciaDelante(L, vectorIndependiente);
                    printSolucion(resultado, n);
    
                    printf("\n--Vector solución--\n");
                    resultado = sustitucionHaciaAtras(U, resultado);
                    printSolucion(resultado, n);
                        printf("\n¿Deseas ingresar otro vector independiente?[S/N]\n\n");
                        fflush(stdin);
    					std::cin >> otroVector;
//                    while(eleccion != 0){
                    while(otroVector == 's' || otroVector == 'S'){
                                std::cout << "Ingrese los elementos del vector independiente de términos constantes:\n";
                                    for (int i = 0; i < n; ++i) {
                                        std::cout << "Elemento x_" << i+1 <<": ";
                                        std::cin >> vectorIndependiente[i];
                                    }
                                printf("\n--Sustitución hacia adelante--\n");
                            resultado = sustitucionHaciaDelante(L, vectorIndependiente);
                            printSolucion(resultado, n);
            
                            printf("\n--Vector solución--\n");
                            resultado = sustitucionHaciaAtras(U, resultado);
                            printSolucion(resultado, n);


                        printf("\n¿Deseas ingresar otro vector independiente?[S/N]\n\n");
                        fflush(stdin);
    					std::cin >> otroVector;
//                        std::cin >> eleccion;
                    }
                    

                }else{
                    cout << "\n\n Sistema no apropiado para Cholesky\n"; 
                }


                break;
            
            default:
                cout << "\n\n Saliendo menú principal : )";
                break;
            }

        }

    }else{
        cout << "El determinante es igual a cero. El sistema asociado no tiene solución o tiene una infinidad de soluciones." << endl;
        return;
    }
}
