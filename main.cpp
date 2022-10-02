#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>

#include "funciones.h"

using namespace std;

int main()
{
    srand(time(NULL));

    string jugadorhistorico;
    int opcion, puntajehistorico;

    opcion = menu_principal(jugadorhistorico, puntajehistorico);

    while (opcion==1)
    {
        string jugador1, jugador2, jugador;
        int cantdadosj1=6, cantdadosj2=6, ronda=1, cantdados, tirada, sumaObjetivo, sumaseleccionada, dadoelegido, dadosSeleccionados, puntajej1=0, puntajej2=0, puntajeronda;
        int dadosStock[12]= {};
        bool banderajugador;
        const int RONDAS=5, PGANADOR=10000;

        cout << "Bienvenido Jugador 1." << endl << "Por favor ingrese su nombre: ";
        cin >> jugador1;
        cout << endl;
        system("cls");
        cout << "Bienvenido Jugador 2." << endl << "Por favor ingrese su nombre: ";
        cin >> jugador2;
        cout << endl << endl;

        system("cls");

        banderajugador = arrancar_partida (jugador1, jugador2);
        cout << endl << endl;

        bandera_jugador (banderajugador, jugador, jugador1, jugador2);

        cout << "Comienza " << jugador << endl << endl;

        system("pause");
        system("cls");

        while (ronda <= RONDAS && puntajeronda<PGANADOR)
        {
            tirada=1;

            cout << "------------------" << endl;
            cout << "    RONDA " << ronda << endl;
            cout << "------------------" << endl << endl;

            cout << "PUNTAJE " << jugador1 << ": " << puntajej1 << endl;
            cout << "CANTIDAD DADOS STOCK: " << cantdadosj1 << endl << endl;

            cout << "PUNTAJE " << jugador2 << ": " << puntajej2 << endl;
            cout << "CANTIDAD DADOS STOCK: " << cantdadosj2 << endl << endl;

            while (tirada <=2 && puntajeronda<PGANADOR)
            {

                int vCaras [12]= {};
                bool validarDados[12]= {};
                dadoelegido=1;
                dadosSeleccionados=0;
                sumaseleccionada=0;

                cout << "***TIRADA " << jugador << "***" << endl << endl;

                sumaObjetivo = lanzar_dados12caras ();

                cout << "Numero objetivo: " << sumaObjetivo << endl << endl;

                cantdados = cant_dados (banderajugador, cantdadosj1,cantdadosj2);

                lanzarDadosStock (dadosStock, cantdados);

                cout << "Dados stock de " << jugador << ": " << endl;

                mostrarDadosStock (dadosStock, cantdados);

                cout << "Seleccione sus dados:" << endl;
                cout<< "La suma de los dados seleccionados debe ser igual al numero de la suma objetivo." << endl;
                cout<< "(Seleccione 0 en caso de querer saltar la ronda)"<< endl << endl;

                for (int i=0; i<12; i++)
                {
                    validarDados [i] = false;
                }

                while (sumaseleccionada!=sumaObjetivo && dadoelegido!=0)
                {
                    cin >> dadoelegido;

                    if(validarDados [dadoelegido-1] == false)
                    {
                        validarDados [dadoelegido-1] = true;
                        sumaseleccionada+=dadosStock[dadoelegido-1];
                        dadosSeleccionados++;

                        for(int i=0; i<dadosSeleccionados; i++)
                        {
                            if(vCaras[i]==0)
                            {
                                vCaras[i] = dadosStock [dadoelegido-1];
                            }
                        }

                    }
                    else
                    {
                        if(dadoelegido!=0){
                        cout << "No se puede seleccionar dos veces el mismo dado, por favor elija otro: " << endl;
                        }
                    }
                }

                if (sumaseleccionada == sumaObjetivo)
                {
                    cout << "*** Tirada exitosa ***" << endl << endl;

                    puntajeronda= sumaseleccionada*dadosSeleccionados;

                    if (jugador==jugador1)
                    {
                        puntajej1+=puntajeronda;
                    }
                    else
                    {
                        puntajej2+=puntajeronda;
                    }

                    tirada_exitosa (banderajugador, dadosSeleccionados, cantdados, cantdadosj1, cantdadosj2, jugador, jugador1, jugador2);

                    if(cantdados!=0)
                    {


                        cout << "Suma seleccionada: " << sumaseleccionada << endl;
                        cout << "Caras seleccionadas: " << endl;
                        mostrarDadosStock (vCaras, dadosSeleccionados);

                        cout << "Puntaje Ronda " << ronda << " de " << jugador << ": " << puntajeronda << endl << endl;
                    }
                    else
                    {

                        cout << "¡¡¡Partida ganada por " << jugador << "!!!" << endl << endl;

                        if(banderajugador)
                        {
                            puntajeronda+=PGANADOR;
                            puntajej2+= PGANADOR;
                        }
                        else
                        {
                            puntajeronda+=PGANADOR;
                            puntajej1+=PGANADOR;
                        }
                    }
                }

                if (dadoelegido==0)
                {

                    cout << "*** Tirada NO exitosa ***" << endl << endl;

                    tirada_noexitosa (banderajugador, cantdados, cantdadosj1, cantdadosj2, jugador1, jugador2);

                }

                cout << "------------------------------------" << endl << endl;

                bandera_jugador (banderajugador, jugador, jugador1, jugador2);
                tirada++;
                system("pause");

            }

            cout << "--------------------" << endl;
            cout << " Resultados RONDA " << ronda << endl;
            cout << "--------------------" << endl << endl;
            cout << "Puntaje acumulado " << jugador1 << ": " << puntajej1 << endl;
            cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;
            cout << "Puntaje acumulado " << jugador2 << ": " << puntajej2 << endl;
            cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;

            system("pause");

            ronda++;
            system("cls");

        }

        cout << "*** PARTIDA FINALIZADA ***" << endl << endl << endl;
        cout << "--------------------" << endl;
        cout << " Resultado FINAL " << endl;
        cout << "--------------------" << endl << endl;
        cout << "Puntaje acumulado " << jugador1 << ": " << puntajej1 << endl;
        cout << "Cantidad de dados stock " << jugador1 << ": " << cantdadosj1 << endl << endl;
        cout << "Puntaje acumulado " << jugador2 << ": " << puntajej2 << endl;
        cout << "Cantidad de dados stock " << jugador2 << ": " << cantdadosj2 << endl << endl;
        cout << "--------------------" << endl << endl;

        if(puntajej1>puntajej2)
        {

            cout << jugador1 << " HA GANADO EL JUEGO" << endl << endl;
            cout << "--------------------" << endl << endl;

            if(puntajej1> puntajehistorico)
            {

                jugadorhistorico=jugador1;
                puntajehistorico=puntajej1;

            }

        }
        else
        {

            if(puntajej2>puntajej1)
            {

                cout << jugador2 << " HA GANADO EL JUEGO" << endl << endl;
                cout << "--------------------" << endl << endl;

                if(puntajej2> puntajehistorico)
                {

                    jugadorhistorico=jugador2;
                    puntajehistorico=puntajej2;

                }
            }
            else
            {
                cout << "-------------------------" << endl << endl;
                cout << "EL PARTIDO QUEDA EMPATADO" << endl << endl;
                cout << "-------------------------" << endl << endl;

                if (jugador==jugador1 && puntajej1>puntajehistorico)
                {

                    jugadorhistorico= jugador2;
                    puntajehistorico= puntajej2;
                }
                else
                {
                    if (jugador==jugador2 && puntajej2>puntajehistorico)
                    {

                        jugadorhistorico=jugador2;
                        puntajehistorico= puntajej2;
                    }

                }
            }

        }

        system("pause");
        system("cls");
        menu_principal(jugadorhistorico, puntajehistorico);
    }
}
