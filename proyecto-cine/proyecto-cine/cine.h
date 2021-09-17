
#include <iostream>
#include <sstream>
using namespace std;

// creacion de clase para crear objetos de tipo pelicula
class Pelicula {
private:
	// atributos
	string nombre; 
	string genero;
	string clasificacion;
	string horaPresentacion;
public:
	//constructor por defecto
	Pelicula() { 
		nombre = " ";
		genero = " ";
		clasificacion = " ";
		horaPresentacion = " ";
	
	}
	Pelicula(string pNom, string pGenero, string pClasi, string pHora) { // constructor con parametros
		nombre = pNom;
		genero = pGenero;
		clasificacion = pClasi;
		horaPresentacion = pHora;
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
	void setClasi(string pClasi) {
		clasificacion = pClasi;
	
	}
	void setHora(string pHora) {
		horaPresentacion = pHora;

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
	Pelicula *vector; // este vector tendra las listas de las peliculas;
	short tamano;
	short cantidad;
public:

	Cartelera(short pTamano) {
		tamano = pTamano;
		cantidad = 0;
		vector = new Pelicula[tamano];
		
	}
	~Cartelera() {
		delete[]vector; // se borra la lista
	
	}

	bool insertar(Pelicula); // funcion para insertar los objetos a la lista
	string toString(); //mostramos los objetos mediante el toString
	void buscar(short); // funcin para buscar

};

bool Cartelera::insertar(Pelicula pObj){
	if (cantidad < tamano) {
		vector[cantidad] = pObj;
		cantidad++;
		return true;
	
	}
	else
		return false;
	
}
string Cartelera::toString() {
	stringstream m;
	for (short i = 0; i < cantidad; i++) {
		m << vector[i].toString()<< endl;
	}
	return m.str();

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




};
