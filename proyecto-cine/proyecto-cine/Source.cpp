#include "cine.h"
#include <sstream>

int main() {
	Pelicula* objPeli = NULL;
	Funcion* ptrFuncion = NULL;
	Sala* ptrSala1 = NULL;
	Sala* ptrSala2 = NULL;
	Coleccion* ptrCole = NULL;
	Asiento ptrAsiento;
	Cinema* ptrCinema = NULL;

	Sala* auxSala = NULL;
	Pelicula* auxPeli = NULL;

	ptrCinema = new Cinema;

	short cont = 0, cont2 = 0, cont3 = 0, opc, tan, numSa, sala, insertar;
	short contador = 0;
	string auxTanda, auxHora, auxDia;
	string nom, gene, tipo, dimen, sinopsis, pais;
	short tipoPublico, annio, tipSa;
	char letra;
	short fila = 0, colum;
	
	do {
		system("cls");
		cout << "\t******************************************************" << endl;
		cout << "\t*                     ++Menu++                       *" << endl;
		cout << "\t******************************************************" << endl;
		cout << endl;
		cout << "[1]................................. Insertar Sala." << endl;
		cout << "[2]................................. Insertar Funcion." << endl;
		cout << "[3]................................. Mostrar Funciones" << endl;
		cout << "[4]................................. Generar Tiquete" << endl;
		cout << "[5]................................. Buscar Pelicula" << endl;
		cout << "[6]................................. salir" << endl;
		cout << "Elija una de las opciones: ";
		cin >> opc;
		system("cls");

		switch (opc)
		{

		case 1:

			do{
				system("cls");
				cout << "Digite el numero de sala a crear: "; cin >> sala;
				cout << "Digite el tipo de sala: " << endl;
				cout << "[1]............VIP" << endl;
				cout << "[2]............Normal" << endl;
				cout << "Opcion: ";  cin >> tipSa;
				if (sala == 1) {
					ptrCole = new Coleccion;
					ptrCole->insertarAsientos(ptrAsiento);
					ptrSala1 = new Sala(sala, tipSa);
					ptrSala1->insertarCole(ptrCole);
					cout << "Se creo con exito la sala!" << endl;


				}
				else if (sala == 2) {
					ptrCole = new Coleccion;
					ptrCole->insertarAsientos(ptrAsiento);
					ptrSala2 = new Sala(sala, tipSa);
					ptrSala2->insertarCole(ptrCole);
					cout << "Se creo con exito la sala!" << endl;



				}
				else {
					cout << "Error! numero de sala incorrecto, digite un valor valido!" << endl;

				}
				
				system("pause");

			} while (sala >= 3);
			
			
		


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
			}
			cout << endl;

			cout << "Digite la hora de la Funcion: "; cin >> auxHora;
			cout << "Digite el dia de la funcion: "; cin >> auxDia;

			objPeli = new Pelicula;
			ptrFuncion = new Funcion;
			cout << "\nDigite el nombre de la Pelicula: "; cin >> nom;
			cout << "Digite el genero de la pelicula: "; cin >> gene;
			cout << "Digite el Tipo: "; cin >> tipo;
			cout << "Digite el la dimension de la pelicula: "; cin >> dimen;
			cout << "Digite la sinopsis de la pelicula: "; cin >> sinopsis;
			cout << "Digite el pais de la pelicula: "; cin >> pais;
			cout << "Digite el anio de la pelicula: "; cin >> annio;
			cout << "Digite el nuemero de tipo de publico 1 =*adulto* o 2 = *ninos*: "; cin >> tipoPublico;
			objPeli->insertarPelicula(nom, gene, tipo, dimen, sinopsis, pais, annio, tipoPublico);
			ptrFuncion->insertarFuncion(auxHora, auxTanda, auxDia);
			ptrFuncion->insertarPelicula(objPeli);
			if (insertar == 1) {
				ptrSala1->insertarFuncion(ptrFuncion);
				ptrCinema->insertar(ptrSala1, insertar);
			}
			else {
				ptrSala2->insertarFuncion(ptrFuncion);
				ptrCinema->insertar(ptrSala2, insertar);

			}

			break;
		case 3:
			cout << ptrCinema->toString();
			system("pause");

			break;
		case 4:
			cout << "Digite el Numero de sala: "; cin >> sala;
			cout<< ptrCinema->obtnerElemento(sala)->toString();
			
			


			cout << "Digite letra de la Fila: "; cin >> letra;
			switch (letra){
			case 'A': case 'a':
				fila = 0;
				break;
			case 'B': case 'b':
				fila = 1;
				break;
			case 'C':case 'c':
				fila = 2;
				break;
			case 'D': case 'd':
				fila = 3;
				break;
			case 'E':case 'e':
				fila = 4;
				break;
			case 'F': case 'f':
				fila = 5;
				break;
				
			default:
				break;
			}
			cout << "Digite la columna: "; cin >> colum;
			ptrCinema->obtnerElemento(sala)->obtenerCole()->reservar(fila, colum);
			

			break;
		case 5:
			break;
		}


		
		

	} while (opc < 6);

	return 0;
}













