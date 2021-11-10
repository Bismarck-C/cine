#pragma once
#include <iostream>
#include <sstream>
using namespace std;

// creacion de clase para crear objetos de tipo pelicula
class Pelicula {

private: //atributos
	string nombre;
	string genero;
	string tipo;
	string dimension;
	string pais;
	string tipoPublico;
	short anio;
public:
	//constructor por defecto
	Pelicula() {//defecto
		nombre = "";
		genero = "";
		tipo = "";
		dimension = "";
		pais = " ";
		tipoPublico = "";
		anio = 0;


	}
	void insertarPelicula(string pNom, string pGenero, string pClasi, string pDimen, string pPais, short pAnio, short pTipo) {//por parametros
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
		//se mustran los atributos
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
	class Asiento {
		string estado;
	public:
		Asiento() {
			estado = "O";
		}
		~Asiento() {

		}
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



};
class Asiento {
	string estado;
public:
	Asiento() {
		estado = "O";
	}
	~Asiento() {

	}
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
	Pelicula* objetoP; //puntero a peliculas
	string hora;
	string dia;
	string tanda;

public:
	Funcion() {
		hora = "";
		dia = "";
		tanda = "";
	}

	~Funcion() {

	}

	void insertarFuncion() {
		string auxTanda, auxHora, auxDia;
		short tan;
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
		setTanda(auxTanda);
		setDia(auxDia);
		setHora(auxHora);
		cout << endl;


	}

	Pelicula* getPelicula() {// retorna la posicion de memoria del objeto de pelicula
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
	void insertarPeli(Pelicula* objPeli) {
		objetoP = objPeli;

	}
	string toString() {
		stringstream s;
		s << getPelicula()->toString() << endl;
		s << "Funcion:" << endl;
		s << "Hora: " << getHora() << endl;
		s << "Dia: " << getDia() << endl;
		s << "Tanda: " << getTanda() << endl;
		s << endl;
		return s.str();
	}
};
class Coleccion {
private:
	Asiento*** matriz;//matriz estatica
public:
	Coleccion() {
		matriz = new Asiento * *[6];
		for (short i = 0; i < 6; i++) {
			matriz[i] = new Asiento * [10];

		}
		for (short i = 0; i < 6; i++) {
			for (short j = 0; j < 10; j++) {
				matriz[i][j] = new Asiento;

			}
		}

	}

	~Coleccion() {
		for (short i = 0; i < 2; i++) {
			for (short j = 0; j < 6; j++) {
				delete matriz[i][j];//apartamentos
			}
			delete matriz[i];//columnas


		}
		delete[] matriz;
	}
	string toString() {
		stringstream m;
		char letras[6]; // se crea un char para mostrar las columnas

		m << "------------------------Pantalla-----------------------" << endl;
		m << endl;
		m << "     " << "(1)  " << "(2)  " << "(3)  " << "(4)  " << "(5)  " << "(6)  " << "(7)  " << "(8)  " << "(9)  " << "(10)  " << endl;


		for (short i = 0; i < 6; i++) {
			letras[i] = i + 65; // en este valor se muestran las letras A, B, C...
			m << endl;
			m << "[" << letras[i] << "]" << "  ";
			for (short j = 0; j < 10; j++) {
				m << "[" << matriz[i][j]->toString() << "]" << "  ";
			}
			m << endl;

		}
		m << "**************************************************************" << endl;
		return m.str();
	}

	bool reservar(short pFill, short pColumm) {
		pColumm = pColumm - 1;
		if (matriz[pFill][pColumm]->getEstado() == "O") {
			matriz[pFill][pColumm]->setEstado("X");
			return true;

		}
		else {
			return false;
		}
	}
	void reiniciarMatriz() {
		for (short i = 0; i < 6; i++) {
			for (short j = 0; j < 10; j++) {
				if (matriz[i][j]->getEstado() == "X") {
					matriz[i][j]->setEstado("O");

				}


			}
		}
	}

};

class Sala {

private:
	short numeroSala;
	string tipoSala;
	Funcion** ptrFun;
	Coleccion* ptrCole;
public:

	Sala() {
		ptrFun = new Funcion * [3];
		for (short i = 0; i < 3; i++) {
			ptrFun[i] = NULL;

		}

		ptrCole = new Coleccion;
	}

	~Sala() {
		for (short i = 0; i < 3; i++) {
			delete ptrFun[i];
		}
		delete[] ptrFun;

		delete ptrCole;
	}

	void insertarFuncion(Funcion* objFun) {
		short cantidad;

		cout << "Digite el numero de funcion: "; cin >> cantidad;
		if (cantidad < 4 && ptrFun[cantidad - 1] == NULL) {
			ptrFun[cantidad - 1] = objFun;
			

		}
		else {
			cout << "El espacio ya esta en uso o no se permiten mas funciones" << endl;
		}




	}

	Funcion* getFuncion(short num) {//se retorna el puntero de funcion

		if (ptrFun[num] != NULL) {
			return ptrFun[num];
		}
		return NULL;

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
	bool insertarSala(short pNum) {
		short opc;
		string tipoSala;

		cout << "Digite el tipo de sala: " << endl;
		cout << "[1]............VIP" << endl;
		cout << "[2]............Normal" << endl;
		cout << "Opcion: ";  cin >> opc;
		if (opc == 1) {
			tipoSala = "VIP";
		}
		else {
			tipoSala = "normal";
		}

		if (pNum == 1) {
			setNumSala(pNum);
			setTipoSala(tipoSala);
			return true;
		}
		else if (pNum == 2) {
			setNumSala(pNum);
			setTipoSala(tipoSala);
			return true;
		}
		else {
			return false;
		}

	}

	string toString() {
		stringstream t;

		for (short i = 0; i < 3; i++) {
			if (getFuncion(i)) {
				t << "******************************************************" << endl;
				t << "Numero de sala: " << numeroSala << endl;
				t << "Tipo de sala: " << tipoSala << endl;
				t << "Funcion numero " << i + 1 << endl;
				t << getFuncion(i)->toString();
				t << getCole()->toString() << endl;
				t << endl;
			}
			else {
				cout << " ";
			}


		}
		return t.str();
	}
	void mostrarFuncion(short pNum) {
		cout << "******************************************************" << endl;
		cout << "Numero de sala: " << numeroSala << endl;
		cout << "Tipo de sala: " << tipoSala << endl;
		cout << "Funcion numero " << pNum + 1 << endl;
		cout << getFuncion(pNum)->toString();
		cout << getCole()->toString() << endl;
		cout << endl;

	}

};

class Cinema {
private:
	Sala* sala1;
	Sala* sala2;
public:


	Cinema() {
		sala1 = new Sala;
		sala2 = new Sala;

	}

	~Cinema() {
		delete sala1;
		delete sala2;
	}


	string toString() {
		stringstream b;
		if (sala1 != NULL) {
			b << sala1->toString() << endl;
		}
		else {
			b << "Sala 1 no deponible por el momento o no se han insertado funciones!" << endl;
		}

		if (sala2 != NULL) {
			b << sala2->toString() << endl;
		}
		else {
			b << "Sala 2 no deponible por el momento o no se han insertado funciones!" << endl;
		}




		return b.str();
	}


	Sala* getSalas(short pNum) {

		if (pNum == 1 && sala1 != NULL) {
			return sala1;
		}
		else
			if (pNum == 2 && sala2 != NULL) {
				return sala2;
			}
			else {
				return NULL;
			}

	}
	Sala* getSala1() {
		if (sala1 != NULL) {
			return sala1;
		}
		else {
			return NULL;
		}


	}
	Sala* getSala2() {
		if (sala2 != NULL) {
			return sala2;
		}
		else {
			return NULL;
		}
	}



};



