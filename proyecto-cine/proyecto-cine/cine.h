#pragma once
#include <iostream>
#include <sstream>
using namespace std;

// creacion de clase para crear objetos de tipo pelicula
class Pelicula {

private:
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
		s << "\n Publico: " << this->tipoPublico << endl;
		s << "*********************************************" << endl;

		return s.str();
	}



};

class Funcion {
public:
	Pelicula* objetoP;
	string hora;
	string tanda;

	Funcion(Pelicula* ptrObj, string pHora, string pTanda) {
		objetoP = ptrObj;
		hora = pHora;
		tanda = pTanda;

	}

	



};
class Asiento {
public:
	string estado;


	Asiento() {
		estado = "O";
	}



	string toString() {
		stringstream a;
		a << this ->estado  << endl;
		return a.str();
	}


	~Asiento() {

	};
	void setEstado(string pEstado) {
		estado = pEstado;
	}

	string getEstado() {
		return estado;
	}

	void insertar() {
		setEstado("O");
	}

};
class Coleccion {
private:
	Asiento* ptr;
	Asiento*** matriz;
	short filas;
	short columnas;
public:
	Coleccion(Asiento* pAsiento) {
		ptr = NULL;
		filas = 6;
		columnas = 10;
		matriz = new Asiento * *[filas];
		for (short i = 0; i < filas; i++)
			matriz[i] = new Asiento * [columnas];
		for (short f = 0; f< filas; f++) {
			for (short c = 0; c < columnas; c++) {
				matriz[f][c] = NULL;
			}
		}
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; j++) {
				matriz[i][j] = pAsiento;;
			}
		}
	}
	string toString() {
		stringstream m;
		m << "---------------------Pantalla--------------------" << endl;
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; j++) {
				if (matriz[i][j] != NULL)
					
					m << "[" << matriz[i][j]->getEstado() << "]"<<"  ";
			}
			m << endl;
		}
		return m.str();
	}
	
};

class Sala {

private:
	short numeroSala;
	string tipoSala;
	Funcion* ptrFun;
	Coleccion* ptrCole;

public:
	

	Sala() {
		
	}
	void insertarSala(Coleccion* pCole, short pNum){
		ptrCole = pCole;
		numeroSala = pNum ;
		if (pNum < 2) {
			tipoSala = "VIP";
		}else{
			tipoSala ="normal";
		}
		
	}

	void setFuncion(Funcion* objFun) {
		ptrFun = objFun;

	}
	Funcion* retornarFuncion() {
		return ptrFun;
	}
	Coleccion* getCole() {
		return ptrCole;
	
	}
	
	void setNumSala(short pNum) {
		numeroSala = pNum;
	}
	void setTipoSala(string pTipo) {
		tipoSala = pTipo;
	}

	short getNumSala() {
		return numeroSala;

	}
	string getTipoSala() {
		return tipoSala;
	}




	string toString() {
		stringstream t;
		t << "Tanda: " << ptrFun->tanda << endl;
		t << "Hora de Funcion: " << getFuncion()->hora << endl;
		t << "Pelicula: " << endl;
		t << getFuncion()->objetoP->toString() << endl;
		t << getCole()->toString();


		return t.str();
	}
};
class Cinema{
private:
	Sala** ptrVector;
	short tamano;
public:
	Cinema() {
		tamano = 2;
		ptrVector = new Sala * [tamano];
		for (short i = 0; i < tamano; i++){
			ptrVector[i] = NULL;

		}
	}

	bool insertar(Sala* pVector, short pNum) {

		
		if (ptrVector[pNum-1] == NULL) {
			ptrVector[pNum-1] = pVector;
			return true;
		}
		return false;
	
	
	}
	void insertarFuncion(Funcion*ptr, short pNum) {
		ptrVector[pNum - 1]->setFuncion(ptr);
	}
		
	string toString(short pNum) {
		stringstream b;
		//for (short i = 0; i < 2; i++){
			b<< ptrVector[pNum] -> toString()<<endl;

		//}
		return b.str();
	}






};




