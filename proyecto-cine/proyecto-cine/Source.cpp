#include "cine.h"

int main() {
	Pelicula* objPeli = NULL;
	Funcion* ptrFuncion = NULL;
	Sala* ptrSala = NULL;
	Coleccion* ptrCole;
	Asiento* ptrAsiento = NULL;
	Cinema* ptrCinema = NULL;

	Sala* auxSala = NULL;

	
	short opc, tan, numSa, sala, insertar;
	short contador = 0;
	string auxTanda, auxHora, tipSa;

	do{
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
			
			cout << "Digite el numero de sala a crear: "; cin >> sala;
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

			
			
			
			
			
			
			
			
			break;
		case 2:
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

			default:
				break;
			}
			cout << endl;
			cout << "Digite la hora de la Funcion: "; cin >> auxHora;
			objPeli = new Pelicula;
			objPeli->insertar();
			ptrFuncion = new Funcion(objPeli, auxHora, auxTanda);
			ptrCinema->insertarFuncion(ptrFuncion, insertar);

			


			
			



			




			
			

			
			
			break;
		case 3:
			cout << "Digite la Sala a mostrar"; cin >> sala;
			cout << ptrCinema->toString(sala);
			

			break;
		case 4:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");

	} while (opc != 5);

	return 0;
}


	


	







