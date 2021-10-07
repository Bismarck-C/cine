#pragma once
#include <iostream>
#include <sstream>
using namespace std;

// creacion de clase para crear objetos de tipo pelicula
class Pelicula { 
	
public:
	string nombre;
	string genero;
	string tipo;
	string dimension;
	short tipoPublico;
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
		tipo = pClasi;

	}
	void setDimension(string pDimen) {
		dimension = pDimen;

	}
	void setTipoPublico(short pTipoP) {
		tipoPublico = pTipoP;
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
	string getDimension() {
		return dimension;
	}
	short getTipoPublico() {
		return tipoPublico;
	}
	void insertar() {
		string nom, gene, tipo, dimen;
		short tipoPublico;

		
		cout << "Digite el nombre de la Pelicula: "; cin >> (nom);
		cout << "Digite el genero de la pelicula: "; cin >> gene;
		cout << "Digite el Tipo : "; cin >> tipo;
		cout << "Digite el la dimendion de la pelicula: "; cin >> dimen;
		cout << "Digite el nuemero de tipo de publico 1 =*adulto* o 2 = *ninos*: "; cin >> tipoPublico;

		setNombre(nom);
		setGenero(gene);
		setTipo(tipo);
		setDimension(dimen);
		setTipoPublico(tipoPublico);

	
	
	}






	string toString() {
		stringstream s;
		s << "********************************************" << endl;
		s << "Nombre: " << this->nombre << endl;
		s << "\n Genero: " << this->genero;
		s << "\n Tipo: " << this->tipo;
		s << "\n Dimension: " << this->dimension;
		s << "\n Publico: " << this->tipoPublico<<endl;
		s << "*********************************************" << endl;

		return s.str();
	}



};
class Funcion {
public:
	Pelicula* objetoP;
	string hora;
	string tanda;

	Funcion(Pelicula *ptrObj, string pHora, string pTanda) {
		objetoP = ptrObj;
		hora = pHora;
		tanda = pTanda;
	
	}



};

class Sala {
public:
	Funcion *ptrFun;
	//Contenedor* ptrSala[];

	Sala(Funcion* objFun) {
		ptrFun = objFun;
	
	}
	string toString() {
		stringstream t;
		t << "Tanda: " << ptrFun->tanda << endl;
		t << "Hora de Funcion: " << ptrFun->hora << endl;
		t << "Pelicula: " << endl;
		t << ptrFun->objetoP->toString() << endl;
		return t.str();
	}
};
