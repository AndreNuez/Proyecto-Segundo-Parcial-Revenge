#include <iostream>
#include <cstdlib>
#include <stdio.h>

#include "funciones.h"

using namespace std;

int menu_principal (string jugadorhistorico, int puntajehistorico)
{
    int opcion, a;

    system("color 57");

    cout << "     REVENGE " << endl << endl;
    cout << " ------------------ " << endl << endl;

    cout << " 1 - JUGAR " << endl;
    cout << " 2 - ESTADISTICAS " << endl;
    cout << " 3 - CREDITOS " << endl << endl;

    cout << " ------------------ " << endl << endl;
    cout << " 0 - SALIR " << endl << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;

    while(opcion!=0)
    {

        switch(opcion)
        {

        case 1:

            system("cls");

            return 1;

            break;

        case 2:

            system("cls");


            cout << "Mejor puntaje hasta el momento: " << puntajehistorico << endl;
            cout << "Jugador: " << jugadorhistorico << endl << endl;

            system("pause");
            system("cls");

            break;

        case 3:

            system("cls");
            cout << "      GRUPO 20 " << endl << endl;
            cout << " ---------------------- " << endl << endl;
            cout << " Tamara Mendoza --- Legajo 25543 " << endl << endl;
            cout << " Mauricio Ribeiro ---- 25588 " << endl << endl;
            cout << " Andrea Nunez --- Legajo 25558 " << endl << endl;

            system("pause");
            system("cls");

            break;

        default:

            system("cls");

            break;

        }

        cout << "    REVENGE" << endl << endl;
        cout << "------------------" << endl << endl;

        cout << " 1 - JUGAR " << endl;
        cout << " 2 - ESTADISTICAS " << endl;
        cout << " 3 - CREDITOS " << endl << endl;

        cout << "------------------" << endl << endl;
        cout << " 0 - SALIR " << endl << endl;

        cout << "Ingrese una opcion: ";
        cin >> opcion;

    }

    if(opcion==0)
    {

        system("cls");

        cout << "¿Seguro que desea salir?" << endl << endl;
        cout << " 1 - SI " << endl;
        cout << " 2 - NO " << endl;
        cin >> a;

        if (a==1)
        {

            system("cls");
            exit (0);
        }

        else
        {

            system("cls");
            menu_principal (jugadorhistorico, puntajehistorico);
        }

    }
}

bool arrancar_partida (string jugador1, string jugador2)
{

    int dado1, dado2;

    cout << "------------------" << endl;
    cout << "  RONDA INCICIAL" << endl;
    cout << "------------------" << endl << endl;


    do
    {
        dado1 = 1 + rand() % 6;
        dado2 = 1 + rand() % 6;
        cout << "Dado " << jugador1 << ":  | " << dado1 << " |" << endl;
        cout << "Dado " << jugador2 << ":  | " << dado2 << " |" << endl;
    }

    while (dado1==dado2);

    if(dado1>dado2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bandera_jugador (bool &banderajugador, string &jugador, string jugador1, string jugador2)
{
    if(banderajugador)
    {
        jugador= jugador1;
        banderajugador=false;

    }
    else
    {
        jugador=jugador2;
        banderajugador=true;

    }
}

int lanzar_dados12caras ()
{

    int dadogrande1, dadogrande2, sumaObjetivo;

    dadogrande1 = 1 + rand() % 12;
    dadogrande2 = 1 + rand() % 12;
    cout << "Dados de 12 caras: " << "\nDado 1:  | " << dadogrande1 << " |  " << "\nDado 2:  | " << dadogrande2 << " |" << endl;

    sumaObjetivo= dadogrande1 + dadogrande2;

    cout << endl;

    return sumaObjetivo;
}

void lanzarDadosStock (int dadosStock[], int cantdados)
{
    for(int i=0; i<cantdados; i++)
    {
        dadosStock[i] = 1 + rand () % 6;
    }
}

void mostrarDadosStock (int dadosStock[], int cantdados)
{

    for(int i=0; i<cantdados; i++)
    {
        cout << "Dado " << i+1 << ":  | " << dadosStock[i] << " |" << endl;
    }
    cout << endl << endl;

}

int cant_dados (bool banderajugador, int &cantdadosj1, int &cantdadosj2)
{
    int cantdados;

    if(banderajugador)
    {
        cantdados= cantdadosj2;
    }

    else
    {
        cantdados= cantdadosj1;
    }

    return cantdados;
}

void tirada_exitosa (bool banderajugador, int dadosSeleccionados, int &cantdados, int &cantdadosj1, int &cantdadosj2, string jugador, string jugador1, string jugador2)
{

    if(banderajugador)
    {
        cantdadosj2-=dadosSeleccionados;
        cantdadosj1+=dadosSeleccionados;

        cout << "Se envian al contrincante " << dadosSeleccionados << " dados" << endl;
        cout << jugador2 << " tiene " << cantdadosj2 << " dados." << endl;
        cout << jugador1 << " tiene " << cantdadosj1 << " dados." << endl << endl;

        cantdados=cantdadosj2;

    }
    else
    {
        cantdadosj1-=dadosSeleccionados;
        cantdadosj2+=dadosSeleccionados;

        cout << "Se envian al contrincante " << dadosSeleccionados << " dados" << endl;
        cout << jugador1 << " tiene " << cantdadosj1 << " dados." << endl;
        cout << jugador2 << " tiene " << cantdadosj2 << " dados." << endl << endl;

        cantdados=cantdadosj1;
    }

}

void tirada_noexitosa (bool banderajugador, int cantdados, int &cantdadosj1, int &cantdadosj2, string jugador1, string jugador2)
{

    if (cantdadosj1>1 && cantdadosj2>1)
    {
        if(banderajugador)
        {

            cout << jugador2 << " recibe 1 dado como penalidad." << endl;
            cantdadosj2++;
            cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;
            cout << jugador1 << " descuenta 1 dado." << endl;
            cantdadosj1--;
            cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;
        }
        else
        {
            cout << jugador1 << " recibe 1 dado como penalidad." << endl;
            cantdadosj1++;
            cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;
            cout << jugador2 << " descuenta 1 dado." << endl;
            cantdadosj2--;
            cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;
        }

    }
    else
    {
        if (cantdados==cantdadosj1)
        {
            if(cantdadosj2>1)
            {
                cout << jugador1 << " recibe 1 dado como penalidad." << endl;
                cantdadosj1++;
                cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;
                cout << jugador2 << " descuenta 1 dado." << endl;
                cantdadosj2--;
                cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;

            }
            else
            {
                cout << "No hay penalidad por falta de dados. " << endl << endl;
            }
        }
        else{

            if (cantdados==cantdadosj2)
        {

            if(cantdadosj1>1)
            {
                cout << jugador2 << " recibe 1 dado como penalidad." << endl;
                cantdadosj2++;
                cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;
                cout << jugador1 << " descuenta 1 dado." << endl;
                cantdadosj1--;
                cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;

            }
            else
            {
                cout << "No hay penalidad por falta de dados. " << endl << endl;
            }

        }
    }

}
}
