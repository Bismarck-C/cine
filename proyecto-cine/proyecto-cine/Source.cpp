#include "Cine.h"
/*Universidad de Nacional Costa Rica
proyecto #2 progracion 1
integrantes:
	Bismarck Victor Cuendis
	Keylor Ruiz Rodriguez

	Se realiza un sistema de apartadado de asientos y la creacion de funciones para una sala.
*/
int main() {
	//objetos de las clases
	Cinema* ptrCinema = new Cinema;
	Pelicula* ptrPeli = NULL;
	Funcion* ptrFun = NULL;


	short opc, sala;
	//variables contadoras

	short contador = 0, activador = 0, conta = 0, contadorTanda = 0;

	// variables para pelicula
	string nom, gene, tipo, dimen, pais;
	short tipoPublico, annio;

	//variables tiqueteria
	short totalBoletos, bole1 = 0, bole2 = 0, fila, colum, numFun, busq = 0;
	char letra;
	float total, boletoAdulto, boletosNi;

	short pSala;
	cout << "\t******************************************************" << endl;
	cout << "\t*                     ++Inicio++                     *" << endl;
	cout << "\t******************************************************" << endl;
	cout << endl;
	cout << "Solo se podran comprar asientos de la tanda seleccionada!" << endl;
	cout << "Digite la tanda para activar ventas " << endl;
	cout << "[1]................................. manana" << endl;
	cout << "[2]................................. tarde" << endl;
	cout << "[3]................................. noche" << endl;
	cout << "Opcion: "; cin >> activador;
	
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
				cout << "[1]................................. insertar sala" << endl;
				cout << "[2]................................. Insertar Funcion" << endl;
				cout << "[3]................................. Activar nueva tanda "<< endl;
				cout << "[4]................................. Salir a menu principal" << endl;
				cout << "Opcion-> "; cin >> opc;

				switch (opc) {
				case 0:
					
					break;
				case 1:
					cout << "Digite el numero de sala a crear: "; cin >> pSala;
					if (ptrCinema->getSalas(pSala)->insertarSala(pSala)) {
						cout << "Se inserto correctamente la Sala!" << endl;
					}
					else {
						cout << "Error! no hay espacio para mas salas!" << endl;
					}


					break;

				case 2:
					cout << "Digite el numero de sala a insertar la Funcion: "; cin >> sala;
					ptrFun = new Funcion;
					ptrFun->insertarFuncion();
					cout << "\nDigite el nombre de la Pelicula: "; cin >> nom;
					cout << "Digite el genero de la pelicula: "; cin >> gene;
					cout << "Digite el Tipo: "; cin >> tipo;
					cout << "Digite el la dimension de la pelicula: "; cin >> dimen;
					cout << "Digite el pais de la pelicula: "; cin >> pais;
					cout << "Digite el anio de la pelicula: "; cin >> annio;
					cout << "Digite el nuemero de tipo de publico 1 =*adulto* o 2 = *ninos*: "; cin >> tipoPublico;
					ptrPeli = new Pelicula;
					ptrPeli->insertarPelicula(nom, gene, tipo, dimen, pais, annio, tipoPublico);
					ptrFun->insertarPeli(ptrPeli);
					do
					{
						if (sala == 1 && sala < 3) {
							ptrCinema->getSala1()->insertarFuncion(ptrFun);
							cout << "Se inserto correctamente la funcion!" << endl;

						}
						else
							if (sala == 2 && sala < 3) {
								ptrCinema->getSala2()->insertarFuncion(ptrFun);
								cout << "Se inserto correctamente la funcion!" << endl;
							}

					} while (sala >= 3);





					break;
				case 3:
					cout << "Digite la tanda para activar ventas " << endl;
					cout << "Solo se venderan entradas de tanda seleccionada" << endl;
					cout << "[1]................................. manana" << endl;
					cout << "[2]................................. tarde" << endl;
					cout << "[3]................................. noche" << endl;
					cout << "Opcion: "; cin >> activador;
					ptrCinema->getSala1()->getCole()->reiniciarMatriz();
					ptrCinema->getSala2()->getCole()->reiniciarMatriz();
					break;

				case 4:
					cout << "Volviendo al menu principal..." << endl;
					break;
				default:
					cout << "Opcion invalida! " << endl;
					break;
				}
				system("pause");
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
			cout << "\t******************************************************" << endl;
			cout << "\t*                     Tiqueteria                     *" << endl;
			cout << "\t******************************************************" << endl;
			cout << endl;
			cout << "Digite el Numero de sala de la pelicula: "; cin >> sala;
			system("cls");
			if (sala == 1) {
				if (ptrCinema->getSala1()->getFuncion(activador - 1) != NULL && activador == 1) {
					if (ptrCinema->getSala1()->getFuncion(activador - 1)->getTanda() == "manana") {
						ptrCinema->getSala1()->mostrarFuncion(activador - 1);
						contadorTanda = 1;
					}

					cout << endl;
				}
				else
					if (ptrCinema->getSala1()->getFuncion(activador - 1) != NULL && activador == 2) {

						if (ptrCinema->getSala1()->getFuncion(activador - 1)->getTanda() == "tarde") {
							ptrCinema->getSala1()->mostrarFuncion(activador - 1);
							contadorTanda = 1;

						}
						cout << endl;

					}
					else
						if (ptrCinema->getSala1()->getFuncion(activador - 1) != NULL && activador == 3) {
							if (ptrCinema->getSala1()->getFuncion(activador - 1)->getTanda() == "noche") {
								ptrCinema->getSala1()->mostrarFuncion(activador - 1);
								contadorTanda = 1;
							}
						}
						else {
							cout << "No hay Funciones!" << endl;
						}
				
			}
			else{
				if (sala == 2 && ptrCinema->getSala2()->getFuncion(activador - 1) != NULL && activador == 1) {
					if (ptrCinema->getSala2()->getFuncion(activador - 1)->getTanda() == "manana") {
						ptrCinema->getSala2()->mostrarFuncion(activador - 1);
						contadorTanda = 1;
					}

				}
				else
					if (sala == 2 && ptrCinema->getSala2()->getFuncion(activador - 1) != NULL && activador == 2) {
						if (ptrCinema->getSala2()->getFuncion(activador - 1)->getTanda() == "tarde") {
							ptrCinema->getSala2()->mostrarFuncion(activador - 1);
							contadorTanda = 1;
						}
						cout << endl;


					}
					else
						if (sala == 2 && ptrCinema->getSala2()->getFuncion(activador - 1) != NULL && activador == 3) {
							if (ptrCinema->getSala2()->getFuncion(activador - 1)->getTanda() == "noche") {
								ptrCinema->getSala2()->mostrarFuncion(activador - 1);
								contadorTanda = 1;
							}
							cout << endl;

						}
						else {
							cout << "No hay funiones!" << endl;
						}

			}
			
			if (contadorTanda == 1) {
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
				system("cls");
				cout << "Esta pelicula es para: " << ptrCinema->getSalas(sala)->getFuncion(numFun - 1)->getPelicula()->getTipoPublico() << endl;
				ptrCinema->getSalas(sala)->mostrarFuncion(numFun - 1);
				if (ptrCinema->getSalas(sala)->getTipoSala() == "normal" && ptrCinema->getSalas(sala)->getFuncion(numFun - 1)->getPelicula()->getTipoPublico() == "ninos") {
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
					if (ptrCinema->getSalas(sala)->getTipoSala() == "VIP" && ptrCinema->getSalas(sala)->getFuncion(numFun - 1)->getPelicula()->getTipoPublico() == "ninos") {
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
						if (ptrCinema->getSalas(sala)->getTipoSala() == "normal" && ptrCinema->getSalas(sala)->getFuncion(numFun - 1)->getPelicula()->getTipoPublico() == "adultos") {
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
				ptrCinema->getSalas(sala)->getCole()->toString();

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
					if (ptrCinema->getSalas(sala)->getCole()->reservar(fila, colum)) {
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
				cout << ptrCinema->getSalas(sala)->getCole()->toString();
				cout << endl;
				cout << endl;
				cout << ptrCinema->getSalas(sala)->getFuncion(numFun - 1)->getPelicula()->toString() << endl;
				cout << "Asientos para adultos: ........................." << bole2 << endl;
				cout << "Asientos para ninos:   ........................." << bole1 << endl;
				cout << "Total a pagar:         ........................." << total << endl;
				bole1 = 0;
				bole2 = 0;
				system("pause");
			}
			else {
				cout << "No se pueden vender boletos para esta tanda!" << endl;
			}
			contadorTanda = 0;

			

			break;
		case 4:
			cout << "\t******************************************************" << endl;
			cout << "\t*               Busqueda de Pelicula                *" << endl;
			cout << "\t******************************************************" << endl;
			cout << endl;
			cout << "Digite el genero de la pelicula a buscar: "; cin >> gene;
			for (short i = 0; i < 3; i++){
				if (ptrCinema->getSala1()->getFuncion(i) != NULL && ptrCinema->getSala1()->getFuncion(i)->getPelicula()->getGenero() == gene) {
					cout << ptrCinema->getSala1()->getFuncion(i)->getPelicula()->toString();
					conta++;
				}
	
			}
			for (short i = 0; i < 3; i++) {
				if (ptrCinema->getSala2()->getFuncion(i) != NULL && ptrCinema->getSala2()->getFuncion(i)->getPelicula()->getGenero() == gene) {
					cout << ptrCinema->getSala2()->getFuncion(i)->getPelicula()->toString();
					conta++;
				}

			}
			if (conta == 0) {
				cout << "No se encotraron resultados!" << endl;
			
			}

			

			



			system("pause");

			break;
		}





	} while (opc != 5);



	return 0;
}












