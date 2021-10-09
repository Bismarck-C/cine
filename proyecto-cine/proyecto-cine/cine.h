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
	int anio;
	short tipoPublico;
public:
	//constructor por defecto
	Pelicula() {
		nombre = " ";
		genero = " ";
		tipo = " ";
		dimension = " ";
		sinopsis = " ";
		pais = " ";
		anio = 0;
		tipoPublico = 0;

	}
	Pelicula(string pNom, string pGenero, string pClasi, string pDimen, string pSinop, string pPais, int pAnio, short pTipo) {
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
	void setAnio(int pAno) {
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
	int getAnio() {
		return anio;
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


		cout << "\nDigite el nombre de la Pelicula: "; cin >> (nom);
		cout << "Digite el genero de la pelicula: "; cin >> gene;
		cout << "Digite el Tipo: "; cin >> tipo;
		cout << "Digite el la dimension de la pelicula: "; cin >> dimen;
		cout << "Digite la sinopsis de la pelicula: "; cin >> sinopsis;
		cout << "Digite el pais de la pelicula: "; cin >> pais;
		cout << "Digite el anio de la pelicula: "; cin >> anio;
		cout << "Digite el nuemero de tipo de publico 1 =*adulto* o 2 = *ninos*: "; cin >> tipoPublico;

		setNombre(nom);
		setGenero(gene);
		setTipo(tipo);
		setDimension(dimen);
		setSinopsis(sinopsis);
		setPais(pais);
		setAnio(anio);
		setTipoPublico(tipoPublico);



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

class Funcion {
public:
	Pelicula* objetoP;
	string hora;
	string dia;
	string tanda;

	Funcion(Pelicula* ptrObj, string pHora, string pTanda, string pDia) {
		objetoP = ptrObj;
		hora = pHora;
		tanda = pTanda;
		dia = pDia;
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
		a << this->estado << endl;
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

	short filas, id = 0;
	short columnas;
public:
	Asiento*** matriz;
	Coleccion(Asiento* pAsiento) {
		ptr = NULL;
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
				//if (matriz[i][j] != NULL)

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

};

class Sala {

private:
	short numeroSala;
	string tipoSala;
	Funcion* ptrFun;
	Coleccion* ptrCole;
public:

	Sala() {
		numeroSala = 0;
	}
	void insertarSala(Coleccion* pCole, short pNum) {
		ptrCole = pCole;
		numeroSala = pNum;
		if (pNum < 2) {
			tipoSala = "VIP";
		}
		else {
			tipoSala = "normal";
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
		t << "Funcion: " << endl;
		t << "\nTanda: " << ptrFun->tanda << endl;
		t << "Hora de la Funcion: " << ptrFun->hora << endl;
		t << "Dia de la Funcion: " << ptrFun->dia << endl;

		t << ptrFun->objetoP->toString() << endl;
		t << getCole()->toString();


		return t.str();
	}
};

class Cinema {
private:

	short tamano;
public:
	Sala** ptrVector;

	Cinema() {
		tamano = 2;
		ptrVector = new Sala * [tamano];
		for (short i = 0; i < tamano; i++) {
			ptrVector[i] = NULL;

		}
	}

	bool insertar(Sala* pVector, short pNum) {


		if (ptrVector[pNum - 1] == NULL) {
			ptrVector[pNum - 1] = pVector;
			return true;
		}
		return false;


	}
	void insertarFuncion(Funcion* ptr, short pNum) {
		ptrVector[pNum - 1]->setFuncion(ptr);
	}

	string toString(short pNum) {
		stringstream b;
		//for (short i = 0; i < 2; i++){
		b << ptrVector[pNum]->toString() << endl;

		//}
		return b.str();
	}


	bool ValidarSala(short pNuum)
	{
		for (short i = 0; i < 2; i++) {
			if (ptrVector[i]->getNumSala() == pNuum) {
				return true;
			}
			else {
				return false;
			}
		}
	}



};





