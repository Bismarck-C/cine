#include "cine.h"

Pelicula* objPeli = NULL;
Funcion* ptrFuncion = NULL;
Sala* ptrSala = NULL;
Asiento* ptrAsiento = NULL;
Coleccion* ptrColeccion = NULL;

int main() {
	short opc, tan;
	string auxTanda, auxHora;

	do{
		system("cls");
		cout << "_____Menu de opciones:_____" << endl;
		cout << "1. Insertar Sala." << endl;
		cout << "2. Insertar Funcion-Pelicula" << endl;
		cout << "3. Mostrar" << endl;
		cout << "4. Generar Tiquete" << endl;
		cout << "5. Buscar Pelicula" << endl;
		cout << "6. salir" << endl;
		cout << "___Elija una de las opciones___" << endl;
		cin >> opc;
		system("cls");
		
		switch (opc)
		{
		case 1:
			
			ptrAsiento = new Asiento;
			ptrAsiento->insertar();
			ptrColeccion = new Coleccion(ptrAsiento);
			ptrSala = new Sala(ptrColeccion);
			
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
			ptrSala = new Sala(ptrFuncion);
			
			break;
		case 3:

			cout << ptrSala->toString();

			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");

	} while (opc != 6);

	return 0;
}


	


	







