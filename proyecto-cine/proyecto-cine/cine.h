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
	string sinopsis;
	string pais;
	short tipoPublico;
	short anio;
public:
	//constructor por defecto
	Pelicula() {
		nombre = " ";
		genero = " ";
		tipo = " ";
		dimension = " ";
		sinopsis = " ";
		pais = " ";
		tipoPublico = 0;
		anio = 0;
		

	}
	void insertarPelicula(string pNom, string pGenero, string pClasi, string pDimen, string pSinop, string pPais, short pAnio, short pTipo) {
		nombre = pNom;
		genero = pGenero;
		tipo = pClasi;
		dimension = pDimen;
		tipoPublico = pTipo;
		sinopsis = pSinop;
		pais = pPais;
		anio = pAnio;

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
	void setSinopsis(string Psinopsis) {
		sinopsis = Psinopsis;
	}
	void setPais(string pPa) {
		pais = pPa;
	}
	void setAnio(short pAno) {
		anio = pAno;
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
	string getSinopsis() {
		return sinopsis;
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
	short getTipoPublico() {
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
		s << " Sinopsis: " << this->sinopsis << endl;
		s << " Pais: " << this->pais << endl;
		s << " Anio: " << this->anio << endl;
		s << " Publico: " << this->tipoPublico << endl;
		s << "*********************************************" << endl;

		return s.str();
	}



};
class Asiento {
public:
	string estado;


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
	Asiento*** matriz;
	short filas;
	short columnas;
public:
	Coleccion() {
		filas = 6;
		columnas = 10;
		matriz = new Asiento * *[filas];
		for (short i = 0; i < filas; i++)
			matriz[i] = new Asiento * [columnas];
		for (short f = 0; f < filas; f++) {
			for (short c = 0; c < columnas; c++) {
				matriz[f][c] = NULL;
			}
		}
	}

	
	void insertarAsientos(Asiento* pAsiento) {
		
		
		for (short i = 0; i < filas; i++) {
			for (short j = 0; j < columnas; j++) {
				if (matriz[i][j] == NULL) {
					matriz[i][j] = pAsiento;
				}
			}
		}
	}
	string toString() {
		stringstream m;
		char letras[6];

		m << "---------------------Pantalla--------------------" << endl;
		m << endl;

		for (short i = 0; i < filas; i++) {
			letras[i] = i + 65;
			m << endl;
			m << "[" << letras[i] << "]" << "  ";
			for (short j = 0; j < columnas; j++) {
				m << "[" << matriz[i][j]->getEstado() << "]" << "  ";
			}
			m << endl;
		}
		return m.str();
	}

	bool reservar(short pFill, short pColumm) {

		if (matriz[pFill][pColumm]->getEstado() == "O") {
			matriz[pFill][pColumm]->setEstado("X");
			cout << "Reserva exitosa" << endl;
			return true;
		}
		else {
			cout << "El asiento ya esta reservado" << endl;
			return false;
		}
	}

	Asiento*** obtenerMatriz() {
		return matriz;
	}

};

class Sala {

private:
	short numeroSala;
	string tipoSala;
	Funcion* ptrFun;
	Coleccion* ptrCole;
public:

	Sala(short pnum, string pSala) {
		numeroSala = 0;
		tipoSala = "";
		ptrFun = NULL;
		ptrCole = NULL;
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





