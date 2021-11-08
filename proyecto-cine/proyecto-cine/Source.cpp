#include "Cine.h"
#include <sstream>
/*Universidad de Nacional Costa Rica
proyecto #1 progracion 1
integrantes:
	Bismarck Victor Cuendis
	Keylor Ruiz Rodriguez

	Se realiza un sistema de apartadado de asientos y la creacion de funciones para una sala.
*/

// objetos punteros
Pelicula* objPeli = NULL;
Funcion* ptrFuncion = NULL;
Sala* ptrSala1 = NULL;
Sala* ptrSala2 = NULL;
Coleccion* ptrCole = NULL;
Asiento ptrAsiento;
Cinema* ptrCinema = NULL;

//
void eliminar();

int main() {
	ptrCinema = new Cinema;// se inicializa el puntero de cinema

	//variables para atributos de sala
	short  opc, tan, numSa, sala, insertar, annio, tipSa;
	//variables contadoras
	short contador = 0, activador = 0, conta = 0;
	// variables para atributos de funcion
	string auxTanda, auxHora, auxDia; 
	// variables de pelicula
	string nom, gene, tipo, dimen, pais; 
	short tipoPublico;
	//varaibles para tiqueteria
	short totalBoletos, bole1 = 0, bole2 = 0, fila, colum, numFun, busq = 0;
	char letra;
	float total, boletoAdulto, boletosNi;
	

	
	do {
		system("cls");
		cout << "\t******************************************************" << endl;
		cout << "\t*                     ++Menu++                       *" << endl;
		cout << "\t******************************************************" << endl;
		cout << endl;
		cout << "[1]................................. Administracion" << endl;
		cout << "[2]................................. Mostrar Funciones" << endl;
		cout << "[3]................................. Generar Tiquete" << endl;
		cout << "[4]................................. Buscar Pelicula" << endl;
		cout << "[5]................................. salir" << endl;
		cout << "Elija una de las opciones: ";
		cin >> opc;
		system("cls");

		switch (opc) {

		case 1:
			do {

				cout << "\t**********************************ADIMINISTRACION********************************************" << endl;
				cout << "[0]................................. Activar tanda(Inicio)" << endl;
				cout << "[1]................................. insertar sala" << endl;
				cout << "[2]................................. Insertar Funcion" << endl;
				cout << "[3]................................. Activar nueva tanda (solo usar si ya hay tandas activas)" << endl;
				cout << "[4]................................. Salir a menu principal" << endl;
				cout << "Opcion-> "; cin >> opc;

				switch (opc) {
				case 0:
					cout << "Digite la tanda para activar ventas " << endl;
					cout << "[1]................................. manana" << endl;
					cout << "[2]................................. tarde" << endl;
					cout << "[3]................................. noche" << endl;
					cout << "Opcion: "; cin >> activador;
					break;
				case 1:

					do {
						conta++;
						system("cls");
						cout << "Digite el numero de sala a crear: "; cin >> sala;
						cout << "Digite el tipo de sala: " << endl;
						cout << "[1]............VIP" << endl;
						cout << "[2]............Normal" << endl;
						cout << "Opcion: ";  cin >> tipSa; // se guarda el tipo de sala
						if (sala == 1 && conta <= 2) {// si es 1 se crea la sala 1

							ptrCole = new Coleccion; // se crea la matriz con asientos
							ptrCole->insertarAsientos(ptrAsiento);
							ptrSala1 = new Sala(sala, tipSa); // se manda por argumento el tipo de sala y el numero
							ptrSala1->insertarCole(ptrCole); // se inserta a la sala la matriz
							cout << "Se creo con exito la sala!" << endl;


						}
						else if (sala == 2 && conta <= 2) {
							ptrCole = new Coleccion;
							ptrCole->insertarAsientos(ptrAsiento);
							ptrSala2 = new Sala(sala, tipSa);
							ptrSala2->insertarCole(ptrCole);
							cout << "Se creo con exito la sala!" << endl;



						}
						else {
							cout << "Error! salas llena!" << endl;


						}

						system("pause");

					} while (sala >= 3);
					break;

				case 2:
					//se crean la funcion para la sala
					cout << "Digite el numero de sala a ingresar la funcion: "; cin >> insertar;
					do {

						cout << "Digite la tanda: " << endl;
						cout << "1. manana " << endl;
						cout << "2. tarde " << endl;
						cout << "3. noche " << endl;
						cout << "Opcion: "; cin >> tan;
					} while (tan > 3); 

					switch (tan)
					{
					case 1:
						auxTanda = "manana";
						break;
					case 2:
						auxTanda = "tarde";
						break;
					case 3:
						auxTanda = "noche";
						break;
					}
					cout << endl;

					cout << "Digite la hora de la Funcion: "; cin >> auxHora;
					cout << "Digite el dia de la funcion: "; cin >> auxDia;

					objPeli = new Pelicula; //se inicia la pelicula
					ptrFuncion = new Funcion; // se incia la funcion
					cout << "\nDigite el nombre de la Pelicula: "; cin >> nom;
					cout << "Digite el genero de la pelicula: "; cin >> gene;
					cout << "Digite el Tipo: "; cin >> tipo;
					cout << "Digite el la dimension de la pelicula: "; cin >> dimen;
					cout << "Digite el pais de la pelicula: "; cin >> pais;
					cout << "Digite el anio de la pelicula: "; cin >> annio;
					cout << "Digite el nuemero de tipo de publico 1 =*adulto* o 2 = *ninos*: "; cin >> tipoPublico;
					objPeli->insertarPelicula(nom, gene, tipo, dimen, pais, annio, tipoPublico); //se insertan los atributos a la pelicula
					ptrFuncion->insertarFuncion(auxHora, auxTanda, auxDia);
					ptrFuncion->insertarPelicula(objPeli); //se inserta la pelicula ya creada a la funcion
					if (insertar == 1) {
						if (ptrSala1->insertarFuncion(ptrFuncion)) {
							if (ptrCinema->insertar(ptrSala1, insertar)) {
								cout << "Se inserto correctamente la sala!" << endl;
							}
							else {
								cout << "Error! no se pueden insertar mas salas o dato ingresado erroneo!" << endl;
							}
						
						}
						else {
							cout << "No se pueden insertar mas funciones a la sala!" << endl;
						} // se inserta la funcion a la sala
						
					}
					else {
						if (ptrSala2->insertarFuncion(ptrFuncion)) {
							if (ptrCinema->insertar(ptrSala2, insertar)) {
								cout << "Se inserto correctamente la sala!" << endl;
							}
							else {
								cout << "Error! no se pueden insertar mas salas o dato ingresado erroneo!" << endl;
							}

						
						}
						else {
							cout << "No se pueden insertar mas funciones a la sala!" << endl;
						
						}
	


					}
					break;
				case 3:
					activador = 0;
					conta = 0;
					eliminar();

					break;
				default:
					cout << "Opcion invalida! " << endl;
					break;
				}
				system("cls");

			} while (opc != 4);



			break;
		case 2:
			cout << "\t******************************************************" << endl;
			cout << "\t*                    Cartelera                       *" << endl;
			cout << "\t******************************************************" << endl;
			cout << endl;
			cout << ptrCinema->toString();
			system("pause");

			break;
		case 3:
			/*if (activador == 1) {
			
			}
			else 
				if (activador == 2){
				
				
				}
				else {
				
				}*/
			cout << "\t******************************************************" << endl;
			cout << "\t*                     Tiqueteria                     *" << endl;
			cout << "\t******************************************************" << endl;
			cout << endl;
			//cout << ptrCinema->toString() << endl;

			cout << "Digite el Numero de sala de la pelicula: "; cin >> sala;
			system("cls");
			if (ptrCinema->obtenerElemento(sala) != NULL) {
				if (activador == 1) {
					for (short i = 0; i < 3; i++){
						if (ptrCinema->buscarSala1()->obtenerFuncion(i)->getTanda() == "manana") {
							cout << ptrCinema->buscarSala1()->obtenerFuncion(i)->toString();
						}
					}
						
				}
				else if (activador == 2) {
					for (short i = 0; i < 3; i++) {
						if (ptrCinema->obtenerElemento(sala)->obtenerFuncion(i)->getTanda() == "tarde") {
							cout << ptrCinema->obtenerElemento(sala)->obtenerFuncion(i)->toString();
						}
					}
				
				}
				else if (activador == 3) {
					for (short i = 0; i < 3; i++) {
						if (ptrCinema->obtenerElemento(sala)->obtenerFuncion(i)->getTanda() == "noche") {
							cout << ptrCinema->obtenerElemento(sala)->obtenerFuncion(i)->toString();
						}
					}
				}
				
				cout << "\t******************************************************" << endl;
				cout << "\t*                     Tiqueteria                     *" << endl;
				cout << "\t******************************************************" << endl;
				cout << endl;
				cout << "DISPOBIBLES = O" << endl;
				cout << "OCUPADOS = X" << endl;
				cout << endl;
				cout << endl;
				cout << "Digite el numero de funcion a alegir: "; cin >> numFun;
				/*El precio del tiquete depende del tipo de público, y de la sala; si el tipo es niños(as) y la sala regular, el
			precio del tiquete es ₵3000, si el tipo es niños(as) y la sala VIP, el precio del tiquete es ₵4500. Si el tipo es
			adultos y la sala regular, el precio del tiquete es ₵5000, si el tipo es adultos y la sala VIP, el precio del tiquete
			es ₵6500*/
				cout << "Esta pelicula es para: " << ptrCinema->obtenerElemento(sala)->obtenerFuncion(numFun-1)->ObtenerPelicula()->getTipoPublico() << endl;
				if (ptrCinema->obtenerElemento(sala)->getTipoSala() == "normal" && ptrCinema->obtenerElemento(sala)->obtenerFuncion(numFun-1)->ObtenerPelicula()->getTipoPublico() == "ninos") {
					boletosNi = 3000;
					boletoAdulto = 3500; //se crearon nuevos precios
					cout << "\t******************************************************" << endl;
					cout << "\t*                Apta para todo publico              *" << endl;
					cout << "\t******************************************************" << endl;
					cout << endl;
					cout << "Valor de la entrada adulto: " << boletoAdulto << endl;
					cout << "Valor de la entrada ninos: " << boletosNi << endl;
					cout << "Digite cuantos boletos para ninos: "; cin >> bole1;
					cout << "Digite cuantos boletos adulto: "; cin >> bole2;
					totalBoletos = bole1 + bole2;
					total = (boletosNi * bole1) + (bole2 * boletoAdulto);//se calculan el total a pagar



				}
				else
					if (ptrCinema->obtenerElemento(sala)->getTipoSala() == "VIP" && ptrCinema->obtenerElemento(sala)->obtenerFuncion(numFun-1)->ObtenerPelicula()->getTipoPublico() == "ninos") {
						boletosNi = 4500;
						boletoAdulto = 4800;
						cout << "\t******************************************************" << endl;
						cout << "\t*                Apta para todo publico              *" << endl;
						cout << "\t******************************************************" << endl;
						cout << endl;
						cout << "Valor de la entrada adulto: " << boletoAdulto << endl;
						cout << "Valor de la entrada ninos: " << boletosNi << endl;
						cout << "Digite cuantos boletos para ninos: "; cin >> bole1;
						cout << "Digite cuantos boletos adulto: "; cin >> bole2;
						totalBoletos = bole1 + bole2;
						total = (boletosNi * bole1) + (bole2 * boletoAdulto);



					}
					else
						if (ptrCinema->obtenerElemento(sala)->getTipoSala() == "normal" && ptrCinema->obtenerElemento(sala)->obtenerFuncion(numFun-1)->ObtenerPelicula()->getTipoPublico() == "adultos") {
							boletoAdulto = 5000;
							cout << "\t******************************************************" << endl;
							cout << "\t*                Apta solo para aultos               *" << endl;
							cout << "\t******************************************************" << endl;
							cout << endl;
							cout << "Valor de la entrada: " << boletoAdulto << endl;
							cout << "Digite cuantos boletos para adulto: "; cin >> bole2;
							totalBoletos = bole2;
							total = totalBoletos * boletoAdulto;
						}
						else {
							boletoAdulto = 6500;
							cout << "\t******************************************************" << endl;
							cout << "\t*                Apta solo para aultos               *" << endl;
							cout << "\t******************************************************" << endl;
							cout << endl;
							cout << "Valor de la entrada: " << boletoAdulto << endl;
							cout << "Digite cuantos boletos para adulto: "; cin >> bole2;
							totalBoletos = bole2;
							total = totalBoletos * boletoAdulto;
						}

				do {
					cout << "Digite letra de la Fila: "; cin >> letra;// se verifica la letra para mandar un numero de fila segun cada letra
					switch (letra) {
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
					if (ptrCinema->obtenerElemento(sala)->obtenerCole()->reservar(fila, colum)) {
						cout << "Reserva exitosa" << endl;
						contador++; //cuenta el numero de veces que se a reservado
					}
					else {
						cout << "El asiento ya esta reservado, digite otro!" << endl;

					}
				} while (contador != totalBoletos);// se verifica que el numero de veces concuerde con los boletos
				contador = 0;
				system("cls");
				cout << "\t******************************************************" << endl;
				cout << "\t*                     Tiqueteria                     *" << endl;
				cout << "\t******************************************************" << endl;

				cout << endl;
				cout << endl;
				cout << "\t******************************************************" << endl;
				cout << "\t*                     Factura                        *" << endl;
				cout << "\t******************************************************" << endl;
				cout << endl;
				cout << "ASIENTO SELECIONADOS: " << endl;
				cout << ptrCinema->obtenerElemento(sala)->obtenerCole()->toString();
				cout << endl;
				cout << endl;
				cout << ptrCinema->obtenerElemento(sala)->obtenerFuncion(numFun-1)->ObtenerPelicula()->toString() << endl;
				cout << "Asientos para adultos: ........................." << bole2 << endl;
				cout << "Asientos para ninos:   ........................." << bole1 << endl;
				cout << "Total a pagar:         ........................." << total << endl;
				bole1 = 0;
				bole2 = 0;
				system("pause");
			}
			else {
				cout << "No hay funcion para sala selccionada!" << endl;
			}
			system("pause");
			

			
			

			
			

			

			break;
		case 4:
			cout << "\t******************************************************" << endl;
			cout << "\t*               Busqueda de Pelicula                *" << endl;
			cout << "\t******************************************************" << endl;
			cout << endl;
			cout << "Digite el genero de la pelicula a buscar: "; cin >> gene;

			do{
				
				if (ptrCinema->buscarSala1()->obtenerFuncion(busq)->ObtenerPelicula()->getGenero() == gene) { //se ingresa atravez de las clases haste llegar a la de pelicula
					cout << "Resultados: " << endl;
					cout << ptrCinema->obtenerElemento(1)->obtenerFuncion(busq)->ObtenerPelicula()->toString(); // se imprime
				}
				else
					if (ptrCinema->buscarSala2()->obtenerFuncion(busq)->ObtenerPelicula()->getGenero() == gene) {
						cout << "Resultados: " << endl;
						cout << ptrCinema->obtenerElemento(2)->obtenerFuncion(busq)->ObtenerPelicula()->toString();
					}
					else {
						cout << "No se encontraron Resultados!" << endl;
					}
				busq++;

			} while (busq < 4);
				


				system("pause");

			break;
		}


		
		

	} while (opc != 5);
	// se borran los objetos dinamicos
	/*delete objPeli;
	delete ptrFuncion;
	delete ptrCole;
	delete ptrSala1;
	delete ptrSala2;
	delete ptrCinema;*/

	return 0;
}
void eliminar() {

	ptrCinema->~Cinema(); // se borran los objetos a travez de los destructores
	cout << "Se reinicio el Sistema!" << endl;
	system("pause");
	
	

}












