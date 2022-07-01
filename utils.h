#include <string>
#include <iostream>

using namespace std;

string divr = " ----------------------------------- ";

//? MENU Generator
int MenuGenerator(string title, string subtitle, string param[10], int cant, bool back)
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

//? Clear
void clear()
{ //* system("@cls||clear")
    system("@cls||clear");
    cout << divr << endl;
}

//? Continue
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