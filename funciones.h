#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

int menu_principal (string jugadorhistorico, int puntajehistorico);

bool arrancar_partida (string jugador1, string jugador2);

void bandera_jugador (bool &banderajugador, string &jugador, string jugador1, string jugador2);

int cant_dados (bool banderajugador, int &cantdadosj1, int &cantdadosj2);

int lanzar_dados12caras ();

void lanzarDadosStock (int dadosStock[], int cantdados);

void mostrarDadosStock (int dadosStock[], int cantdados);

void tirada_exitosa (bool banderajugador, int dadosSeleccionados, int &cantdados, int &cantdadosj1, int &cantdadosj2, string jugador, string jugador1, string jugador2);

void tirada_noexitosa (bool banderajugador, int cantdados, int &cantdadosj1, int &cantdadosj2, string jugador1, string jugador2);

#endif // FUNCIONES_H_INCLUDED
