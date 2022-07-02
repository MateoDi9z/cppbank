#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <windows.h>

using namespace std;

const string divr = " ----------------------------------- ";

/* 
*   Generador de Menu
*   @param title Titulo del menu
*   @param subtitle Subtitulo del menu
*   @param param Array de strings con opciones a mostrar en el Menu
*   @param cant Cantidad de opciones a mostrar en el Menu
*   @param back Si es true muestra opcion adicional para volver al menu anterior
*   @return Opcion - Indice de opcion en array de opciones
*   @since v1.0
*/
int MenuGenerator(string title, string subtitle, string param[], int cant, bool back)
{
    cout << " " << title << endl;
    cout << divr << endl;
    cout << " " << subtitle << endl;

    int i;
    for (i = 0; i < 9; i++) {
        if (i < cant)
            cout << " " << i + 1 << " | " << param[i] << endl;
        else break;
    }

    if (back)
        cout << " " << i + 1 << " | " << "<- BACK" << endl;
    else
        cout << "> ";

    int temp;
    cin >> temp;
    return temp;
}

/* 
*   Limpia la consola
*   @return void
*   @since v1.0
*/
void clear()
{
    system("@cls||clear");
    cout << divr << endl;
}

/* 
*   Pregunta y cierra el programa si es deseado
*   @return void
*   @since v1.0
*/
void askToCLose()
{
    string res;
    cout << " Deseas continuar? si/no - ";
    cin >> res;
    
    if (res != "si" && res != "Si" && res != "SI" && res != "1") {
        exit(0);
        system("exit");
    }
    return;
}

/* 
*   Pregunta si desea confirmar
*   @return Confirmar 
*   1 = SI,
*   0 = NO
*   @since v1.0
*/
int confirm()
{
    string confirm;
    cout << " Confirmar? si/no - ";
    cin >> confirm;

    if (confirm != "si" && confirm != "1")
    {
        printf("Operación cancelada! \n");
        return 0;
    }
    printf("Success! \n");
    return 1;
}

/*
*   Esperar
*   @param ms Tiempo a esperar (Milisegundos)
*   @return void
*/
void delay(int ms) {
    Sleep(ms);
}

/*
*   Print - para debug :)
*   @param x Mensaje
*/
void print(auto x) {
    cout << x << endl;
}