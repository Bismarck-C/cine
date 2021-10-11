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
	string pais;
	string tipoPublico;
	short anio;
public:
	//constructor por defecto
	Pelicula() {
		nombre = "";
		genero = "";
		tipo = "";
		dimension = "";
		pais = " ";
		tipoPublico = "";
		anio = 0;
		

	}
	void insertarPelicula(string pNom, string pGenero, string pClasi, string pDimen, string pPais, short pAnio, short pTipo) {
		nombre = pNom;
		genero = pGenero;
		tipo = pClasi;
		dimension = pDimen;
		pais = pPais;
		anio = pAnio;
		if (pTipo == 1) {
			tipoPublico = "adultos";
			
		}
		else {
			tipoPublico = "ninos";
		}

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
	void setPais(string pPa) {
		pais = pPa;
	}
	void setAnio(short pAno) {
		anio = pAno;
	}
	void setTipoPublico(string pTipoP) {
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
	string getPais() {
		return pais;
	}
	short getAnio() {
		return anio;
	}
	string getDimension() {
		return dimension;
	}
	string getTipoPublico() {
		return tipoPublico;
	}
	string toString() {
		stringstream s;
		s << "********************************************" << endl;
		s << "Pelicula: " << endl;
		s << "\n Nombre: " << this->nombre << endl;
		s << " Genero: " << this->genero << endl;
		s << " Tipo: " << this->tipo << endl;
		s << " Dimension: " << this->dimension << endl;
		s << " Pais: " << this->pais << endl;
		s << " Anio: " << this->anio << endl;
		s << " Publico: " << this->tipoPublico << endl;
		s << "*********************************************" << endl;

		return s.str();
	}



};
class Asiento {
	string estado;
public:
	Asiento() {
		estado = "O";
	}
	~Asiento() {
	};
	void setEstado(string pEstado) {
		estado = pEstado;
	}

	string getEstado() {
		return estado;
	}
	string toString() {
		stringstream a;
		a << estado;
		return a.str();
	}

};

class Funcion {
private:
	Pelicula* objetoP;
	string hora;
	string dia;
	string tanda;

public:
	Funcion() {
		objetoP = NULL;
		hora = "";
		dia = "";
		tanda = "";
	}

	~Funcion() {
		delete objetoP;
	}

	void insertarFuncion(string pHora, string pTanda, string pDia) {
		
		hora = pHora;
		tanda = pTanda;
		dia = pDia;
	}
	void insertarPelicula(Pelicula* pObj) {
		objetoP = pObj;
	}

	Pelicula* ObtenerPelicula() {
		return objetoP;
	
	}
	void setHora(string pHora) {
		hora = pHora;
	
	}
	void setTanda(string pTanda) {
		tanda = pTanda;

	}
	void setDia(string pDia) {
		dia = pDia;

	}
	string getHora() {
		return hora;
	
	}
	string getTanda() {
		return tanda;

	}
	string getDia() {
		return dia;

	}
};

class Coleccion {
private:
	Asiento matriz[10][10];
	short filas;
	short columnas;
public:
	Coleccion() {
		filas = 6;
		columnas = 10;
	}
	
	~Coleccion() {

	}

	void insertarAsientos(Asiento pAsiento) {
		
		
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; j++) {
				matriz[i][j] = pAsiento;
				
			}
		}
	}
	string toString() {
		stringstream m;
		char letras[6];

		m << "------------------------Pantalla-----------------------" << endl;
		m << endl;
		m << "     " << "(1)  " << "(2)  " << "(3)  " << "(4)  " << "(5)  " << "(6)  " << "(7)  " << "(8)  " << "(9)  " << "(10)  " << endl;
		
		
		for (short i = 0; i < filas; i++) {
			letras[i] = i + 65;
			m << endl;
			m << "[" << letras[i] << "]" << "  ";
			for (short j = 0; j < columnas; j++) {
				m << "[" << matriz[i][j].toString() << "]" << "  ";
			}
			m << endl;

		}
		m << "**************************************************************" << endl;
		return m.str();
	}

	bool reservar(short pFill, short pColumm) {
		pColumm = pColumm - 1;
		if (matriz[pFill][pColumm].getEstado() == "O") {
			matriz[pFill][pColumm].setEstado("X");
			return true;

		}
		else {
			return false;
		}
	}

};

class Sala {

private:
	short numeroSala;
	string tipoSala;
	Funcion* ptrFun;
	Coleccion* ptrCole;
public:

	Sala(short pNum, short pSala) {
		numeroSala = pNum;
		if (pSala == 1) {
			tipoSala = "VIP";
		}
		else {
			tipoSala = "normal";
		}
		
		ptrFun = NULL;
		ptrCole = NULL;
	}

	~Sala() {
		delete ptrFun;
		delete ptrCole;
	}

	void insertarCole(Coleccion* pCole) {
		ptrCole = pCole;
		
	}

	void insertarFuncion(Funcion* objFun) {
		ptrFun = objFun;

	}
	Funcion* obtenerFuncion() {
		return ptrFun;
	}
	Coleccion* obtenerCole() {
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
		t << "Numero de sala: " << numeroSala << endl;
		t << "Tipo de sala: " << tipoSala << endl;
		t << "Funcion: "<<obtenerFuncion()->getTanda()<<endl;
		t << "Hora de la Funcion: " << obtenerFuncion()->getHora() << endl;
		t << "Dia de la Funcion: " << obtenerFuncion()->getDia() << endl;
		t << obtenerFuncion()->ObtenerPelicula()->toString()<<endl;
		t << "Sala: " << endl;
		t << obtenerCole()->toString() << endl;


		return t.str();
	}
	
};

class Cinema {
private:
	Sala* sala1;
	Sala* sala2;
public:
	

	Cinema() {
		sala1 = NULL;
		sala2 = NULL;

	}

	~Cinema() {
		delete sala1;
		delete sala2;
	}

	bool insertar(Sala* ObjSala, short pNUm) {
		if (pNUm == 1) {
			sala1 = ObjSala;
			return true;
		}
		else if(pNUm == 2){
			sala2 = ObjSala;
			return true;
		}
		else {
			return false;
		}

	}

	string toString() {
		stringstream b;
		if(sala1 != NULL)
			b << sala1->toString() << endl;
		if (sala2 != NULL)
			b << sala2->toString() << endl;



		return b.str();
	}


	Sala* obtnerElemento(short pNum) {
		if (pNum == 1) {
			return sala1;
		}else
			return sala2;
		
	}



};





