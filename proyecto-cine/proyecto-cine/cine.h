
#include <iostream>
#include <sstream>
using namespace std;

class Cinema {
private:
	Funciones objFunciones;
	Sala objSala;
public:
	void
	





};




class Funciones {
private:
	Pelicula obj;
	string dia;
	string hora;
	string funcion;
public:

	Funciones() {
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
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
string Funciones::toString() {
	stringstream m;


}

// se recibe una opcion desde el main para saber porque filtro quiere buscar la pelicula;
void Funciones::buscar(short pbusqueda) {
	string busqueda = "";
	string bandera = "f";
	

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
	Pelicula(string pNom, string pGenero, string pClasi, string pDimen, short pTipo) {
		nombre = pNom;
		genero = pGenero;
		tipo = pClasi;
		dimension = pDimen;
		tipoPublico = pTipo;
	
	} // constructor con parametros
		
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
