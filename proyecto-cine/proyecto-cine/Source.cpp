#include "cine.h"

Pelicula* objPeli = NULL;
Funcion* ptrFuncion = NULL;
Sala *ptrSala = NULL;
Asiento* ptrAsiento = NULL;

int main() {
	short opc, tan, numSa;
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
			cout << "Digite el Numero de sala: "; cin >> numSa;
			cout << "Digite el tipo de la sala: "; cin >> tipSa;
			ptrAsiento = new Asiento;
			ptrAsiento->insertar();
			ptrSala = new Sala;
			ptrSala->insertarSala(ptrAsiento, numSa, tipSa);
			
			
			
			
			
			break;
		case 2:
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
			ptrSala->insertarFuncion(ptrFuncion);

			
			
			break;
		case 3:
			cout << ptrSala->toString();
			

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


	


	







