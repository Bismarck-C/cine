
#include <iostream>
#include <sstream>
using namespace std;

// creacion de clase para crear objetos de tipo pelicula
class Pelicula {
private:
	// atributos
	string nombre; 
	string genero;
	string tipo;
	string dimension;
	string sala;
	short tipoPublico;

public:
	//constructor por defecto
	Pelicula() { 
		nombre = " ";
		genero = " ";
		tipo = " ";
		dimension = " ";
		sala = " ";
		tipoPublico = 0;
	
	}
	Pelicula(string pNom, string pGenero, string pClasi, string pDimen, string pSala, short pTipo ) { // constructor con parametros
		nombre = pNom;
		genero = pGenero;
		tipo = pClasi;
		dimension = pDimen;
		sala = pSala;
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
	//metodos get
	string getNombre() {
		return nombre;
	}
	string getGenero() {
		return genero;
	}
	string getClasi() {
		return clasificacion;
	}
	string getHora() {
		return horaPresentacion;
	}
	string toString() {
		stringstream s;
		s << "********************************************" << endl;
		s << "\n Nombre: "<< this -> nombre;
		s << "\n Genero: " << this -> genero;
		s << "\n clasificacion" << this ->  clasificacion;
		s << "\n Hora de funcion" << this->horaPresentacion;
		s << "*********************************************" << endl;
		
		return s.str();
	}

	

};

// CREACION DE LA CLASE CARTELERA PARA PODER MOSTRAR LAS PELICULAS
class Cartelera {
private:
	Pelicula ***matriz; // este vector tendra las listas de las peliculas;
	short filas;
	short columnas;
public:

	Cartelera(short pTamano) {
		filas = 40;
		collate40;
		
		matriz = new short**[filas]; // reservando memoria para filas
		for (short i = 0; i < fila; i++)
			matriz[i] = new short*[columnas];// reservando memoria para columnas
		
	}
	~Cartelera() {
		
	}

	bool insertar(Pelicula); // funcion para insertar los objetos a la lista
	string toString(); //mostramos los objetos mediante el toString
	void comprar();
	void buscar(short); // funcin para buscar

};

bool Cartelera::insertar(Pelicula pObj){
	if (){
	
	}
	else {
	}
		
	
}
string Cartelera::toString() {
	stringstream m;
	

}

// se recibe una opcion desde el main para saber porque filtro quiere buscar la pelicula;
void Cartelera::buscar(short pbusqueda) {
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
