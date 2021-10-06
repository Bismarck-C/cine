#include "cine.h"

int main() {
	Sala objSala;
	short opc;

	do
	{
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
		switch (opc)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}

		system("pause");
	} while (opc != 6);

	return 0;
}