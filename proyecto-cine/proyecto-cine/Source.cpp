#include "cine.h"

int main() {
	Pelicula* objPeli = NULL;
	Funcion* ptrFuncion = NULL;
	Sala* ptrSala = NULL;
	Coleccion* ptrCole;
	Asiento* ptrAsiento = NULL;
	Cinema* ptrCinema = NULL;

	Sala* auxSala = NULL;


	short cont = 0, cont2 = 0, cont3 = 0, opc, tan, numSa, sala, insertar;
	short contador = 0;
	string auxTanda, auxHora, auxDia, tipSa;

	do {
		system("cls");
		cout << "_____Menu de opciones:_____" << endl;
		cout << "1. Insertar Sala." << endl;
		cout << "2. Insertar Funcion." << endl;
		cout << "3. Mostrar" << endl;
		cout << "4. Generar Tiquete" << endl;
		cout << "5. Buscar Pelicula" << endl;
		cout << "6. salir" << endl;
		cout << "Elija una de las opciones: " << endl;
		cin >> opc;
		system("cls");

		switch (opc)
		{

		case 1:
			if (cont2 < 2) {

				cout << "Digite el numero de sala a crear: "; cin >> sala;
				if (cont2 < 1) {
					cont++;
					cont2++;
					//cout << "Digite el numero de sala a crear: "; cin >> sala;
					ptrAsiento = new Asiento;
					ptrCole = new Coleccion(ptrAsiento);
					ptrSala = new Sala;
					ptrSala->insertarSala(ptrCole, sala);
					ptrCinema = new Cinema;
					if (ptrCinema->insertar(ptrSala, sala)) {
						cout << "Se creo la Sala con exito" << endl;
					}
					else {
						cout << "Error! No se permiten crear mas Salas" << endl;
					}
				}
				else if (ptrCinema->ValidarSala(sala) == true) {

					cout << "La sala ya fue creada." << endl;

				}
				else {
					cont++;
					cont2++;
					//cout << "Digite el numero de sala a crear: "; cin >> sala;
					ptrAsiento = new Asiento;
					ptrCole = new Coleccion(ptrAsiento);
					ptrSala = new Sala;
					ptrSala->insertarSala(ptrCole, sala);
					ptrCinema = new Cinema;
					if (ptrCinema->insertar(ptrSala, sala)) {
						cout << "Se creo la Sala con exito" << endl;
					}
					else {
						cout << "Error! No se permiten crear mas Salas" << endl;
					}
				}
			}
			else {
				cout << "Ya se crearon todas las salas" << endl;
			}






			break;
		case 2:
			if (cont >= 1) {
				cont3++;
				cout << "Digite el numero de sala a ingresar la funcion: "; cin >> insertar;
				do {
					cout << "Digite la tanda: " << endl;
					cout << "1. manana " << endl;
					cout << "2. tarde " << endl;
					cout << "3. noche " << endl;
					cout << "Opcion: "; cin >> tan;
				} while (tan > 3);
				cout << endl;

				switch (tan)
				{
				case 1:
					auxTanda = "manana";
					break;
				case 2:
					auxTanda = "tarde";
					break;
				case 3:
					auxTanda = "Noche";
					break;
				}
				cout << endl;

				cout << "Digite la hora de la Funcion: "; cin >> auxHora;
				cout << "Digite el dia de la funcion: "; cin >> auxDia;
				objPeli = new Pelicula;
				objPeli->insertar();
				ptrFuncion = new Funcion(objPeli, auxHora, auxTanda, auxDia);
				ptrCinema->insertarFuncion(ptrFuncion, insertar);
			}
			else {
				cout << "No hay salas ingresadas" << endl;
			}



















			break;
		case 3:
			if (cont3 >= 1) {
				cout << "Digite la Sala a mostrar: "; cin >> sala;
				cout << ptrCinema->toString(sala);
			}
			else {
				cout << "No hay funciones ingresadas." << endl;
			}

			break;
		case 4:
			short fill, columm;

			cout << "Digite la fila: "; cin >> fill;
			cout << "Digite la columna: "; cin >> columm;
			ptrCole->reservar(fill, columm);

			break;
		case 5:
			break;
		}

		system("pause");
		system("cls");

	} while (opc < 6);

	return 0;
}













