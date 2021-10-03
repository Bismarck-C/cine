
#include <iostream>
#include <sstream>
using namespace std;




// CREACION DE LA CLASE CARTELERA PARA PODER MOSTRAR LAS PELICULAS
class Funciones {
private:
	Pelicula *objPeli;
	string dia;
	string hora;
	string funcion;
public:

	Funciones() {
		objPeli = NULL;
		dia = "";
		hora = "DD/MM/AA";
		funcion = "manana";
	}
	~Funciones() {
		
	}
	string toString(); //mostramos los objetos mediante el toString
	void comprar();
	void buscar(short); // funcin para buscar

};

}
string Funciones::toString() {
	stringstream m;
	

}

// se recibe una opcion desde el main para saber porque filtro quiere buscar la pelicula;
void Funciones::buscar(short pbusqueda) {
	string busqueda = "";
	string bandera = "f";
	switch (pbusqueda){
	case 1: // busqueda por nombre
		cout << "Digite el nombre de la pelicula: "; cin >> busqueda;
		for (short i = 0; i < cantidad; i++) {
			if (vector[i].getNombre() == busqueda)
				cout << vector[i].toString();
				bandera = "t";
		}

		if (bandera == "f") {
			cout << "/n No se encontraron resultados";
		}
		break;
	case 2: //busqueda por genero


		break;
	case 3: // busqueda por clasificacion

		break;
	case 4: // busqueda por dia

		break;



	default:

		cout << "Opcion digita errornea, por favor digite una opcion valida "<< endl;

		break;
	}


}


class Pelicula { // creacion de clase para crear objetos de tipo pelicula
private:
	// atributos
	string nombre;
	string genero;
	string tipo;
	string dimension;
	short tipoPublico;

public:
	//constructor por defecto
	Pelicula() {
		nombre = " ";
		genero = " ";
		tipo = " ";
		dimension = " ";
		tipoPublico = 0;

	}
	Pelicula(string pNom, string pGenero, string pClasi, string pDimen, short pTipo) { // constructor con parametros
		nombre = pNom;
		genero = pGenero;
		tipo = pClasi;
		dimension = pDimen;
		tipoPublico = pTipo;
	}
	~Pelicula() {

	}
	//metodos set
	void setNombre(string pNom) {
		nombre = pNom;
	}
	void setGenero(string pGenero) {
		genero = pGenero;
	}
	void setTipo(string pClasi) {
		clasificacion = pClasi;

	}
	void setDimension(string pDimen) {
		dimension = pDimen;

	}
	void setTipoPublico(short pTipoP) {
		tipoPublico = pTipoP
	}
	//metodos get
	string getNombre() {
		return nombre;
	}
	string getGenero() {
		return genero;
	}
	string getTipo() {
		return tipo;
	}
	strign getDimension() {
		return dimension;
	}
	short setTipoPublico() {
		return tipoPublico
	}

	string toString() {
		stringstream s;
		s << "********************************************" << endl;
		s << "\n Nombre: " << this->nombre;
		s << "\n Genero: " << this->genero;
		s << "\n clasificacion" << this->clasificacion;
		s << "\n Dimension: " << this->dimension;
		s << "\n Publico: " << this->tipoPublico;
		s << "*********************************************" << endl;

		return s.str();
	}



};

class Sala {
private:
	string sala1[][];
	string sala2[][];
	short filas;
	short columnas;

public:
	Sala() {
		filas = 6;
		columnas = 10;
		
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; i++) {
				sala1[filas][columnas] = "V";
			}
		}
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; j++) {
				sala2[filas][columnas] = "V";
			}
		}
	}
	~Sala() {
	
	}
	void mostarSala1();
	void mostarSla2()
	void selecionarAsietos1();
	void selecionarAsietos2();
	

};
