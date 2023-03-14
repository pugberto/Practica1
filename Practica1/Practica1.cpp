#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Nodo{
	Nodo *prev;
	string nombre;
	int cuarto;
	Nodo *sgte;
};

bool consultar(Nodo *frente){
	return (frente == NULL)? true : false;
}

void insertarhuesped(Nodo *&, string , int );

void mostrarhuespedes(Nodo *);

void buscarNombre(Nodo *, string );

void buscarCuarto(Nodo *, int );

void eliminarhuespedNombre(Nodo *&, string);

void eliminarhuespedCuarto(Nodo *&, int);

void guardar(Nodo *);

void cargar(Nodo *&);

void buscarVecinos(Nodo *, int);

void alfabetico(Nodo *);

void mostrarhuespedesOrden(Nodo *);

void insertarHuespedOrden(Nodo *&, string, int);

void mostrarhuespedesPorOrden(Nodo *);

void guardarOrden(Nodo *);

void cargarOrden(Nodo *&);

int main(){
	Nodo *lista = NULL;
	Nodo *lista2 = NULL;
	string n, nombre;
	int num, opc, num2;
	
	do {
		cout<<"[1] para ingresar un huespedes manualmente"<<endl;
		cout<<"[2] para mostrar todos los huespedes"<<endl;
		cout<<"[3] para buscar la habitacion de un huesped con su nombre"<<endl;
		cout<<"[4] para buscar el nombre de un huesped, por su habitacion"<<endl;
		cout<<"[5] para eliminar un huesped de la base de datos, por su nombre"<<endl;
		cout<<"[6] para eliminar un huesped de la base de datos, por su habitacion"<<endl;
		cout<<"[7] guardar archivo"<<endl;
		cout<<"[8] cargar archivo"<<endl;
		cout<<"[9] para consultar vecinos"<<endl;
		cout<<"[10] para ver los nombres ordenados alfabeticamente"<<endl;
		cout<<"[11] para ver los nombres ordenados por tiempo de llegadas"<<endl;
		cout<<"[12] para salir"<<endl;
		cout<<"Opcion: "; cin>>opc;
		system("cls");
		cout<<endl;
		
		switch(opc){
			case 1:
				cout<<"Ingrese el nombre del huesped: "; cin>>n;
				cout<<endl;
				cout<<"Ingrese la habitacion donde se alojara: "; cin>>num;
				cout<<endl;
				insertarhuesped(lista, n, num);
				cout<<endl;
				insertarHuespedOrden(lista2, n, num);
				cout<<endl;
				system("pause");
				system("cls");
				break;
			
			case 2:
				mostrarhuespedes(lista);
				cout<<endl;
				system("pause");
				system("cls");
				break;
				
			case 3:
				cout<<"Ingresa el nombre del huesped: "; cin>>nombre;
				buscarNombre(lista, nombre);
				system("pause");
				system("cls");
				break;
			
			case 4:
				cout<<"Ingresa la habitacion del huesped: "; cin>>num;
				buscarCuarto(lista, num);
				system("pause");
				system("cls");
				break;
				
			case 5:
				cout<<"Ingresa el nombre del huesped: "; cin>>nombre;
				eliminarhuespedNombre(lista, nombre);
				system("pause");
				system("cls");
				break;
			
			case 6:
				cout<<"Ingresa la habitacion del huesped: "; cin>>num;
				eliminarhuespedCuarto(lista, num);
				system("pause");
				system("cls");
				break;
				
			case 7:
				guardar(lista);
				guardarOrden(lista2);
				system("cls");
				break;
				
			case 8:
				cargar(lista);
				cargarOrden(lista2);
				system("pause");
				system("cls");
				break;
				
			case 9:
				cout<<"Ingresa el cuarta que quieras consultar: "; cin>>num2;
				buscarVecinos(lista, num2);
				system("pause");
				system("cls");
				break;
			
			case 10:
				alfabetico(lista);
				system("pause");
				system("cls");
				break;
				
			case 11:
				mostrarhuespedesPorOrden(lista2);
				system("pause");
				system("cls");
				break;
				
			case 12:
				guardar(lista);
				guardarOrden(lista2);
				cout<<"Fin del programa (Los archivos han sido guardados correctamente)"<<endl;
		}
		system("cls");
	}while(opc != 12);
	
	return 0;
}


void insertarhuesped(Nodo *&lista, string n, int c){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->nombre = n;
	nuevo_nodo->cuarto = c;
	Nodo *comprobante = lista;
	Nodo *comprobante2 = lista;
	bool comprobador = true;
	bool comprobador2 = false;
	bool comprobador3 = false;
	int opc1, nuevo_cuarto;
	int contador = 0;
	
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while(comprobante != NULL){
		
		while(comprobante2 != NULL){
			if(comprobante2->cuarto == c-1 || comprobante2->cuarto == c+1){
			contador++;
 			}
 			comprobante2 = comprobante2->sgte;
		}
		
		
		
		
		
		if(comprobante->cuarto == c-1){
			comprobador = false;
			comprobador2 = true;
		}
		
		if(contador == 2){
			comprobador = false;
			comprobador2 = false;
			comprobador3 = true;
 		}
 		
		
		
		if(comprobante->cuarto == c && comprobador){
			cout<<"Este cuarto ya ha sido tomado, puedes tomar el cuarto "<<c-1<<" o elegir un nuevo cuarto"<<endl;
			cout<<"[1] para elegir el cuarto "<<c-1<<endl;
			cout<<"[2] para elegir cualquier otro cuarto"<<endl;
			cout<<"Opcion: "; cin>>opc1;
			if(opc1 == 1){
				nuevo_nodo->cuarto = c-1;
				c = c-1;
				system("cls");
			}
			else if(opc1 == 3){
				cout<<contador;
				cout<<endl;
				system("pause");
			}
			else{
				cout<<"Elige un nuevo cuarto: "; cin>>nuevo_cuarto;
				nuevo_nodo->cuarto = nuevo_cuarto;
				c = nuevo_cuarto;
				system("cls");
			}
			system("cls");
		}
		
		if(comprobante->cuarto == c && comprobador2){
			cout<<"Este cuarto ya ha sido tomado, puedes tomar el cuarto "<<c+1<<" o elegir un nuevo cuarto"<<endl;
			cout<<"[1] para elegir el cuarto "<<c+1<<endl;
			cout<<"[2] para elegir cualquier otro cuarto"<<endl;
			cout<<"Opcion: "; cin>>opc1;
			if(opc1 == 1){
				nuevo_nodo->cuarto = c+1;
				c = c+1;
				system("cls");
			}
			else if(opc1 == 3){
				cout<<contador;
				cout<<endl;
				system("pause");
			}
			else{
				cout<<"Elige un nuevo cuarto: "; cin>>nuevo_cuarto;
				nuevo_nodo->cuarto = nuevo_cuarto;
				c = nuevo_cuarto;
				system("cls");
			}
			system("cls");
		}
		
		if(comprobante->cuarto == c && comprobador3){
			cout<<"Este cuarto ya ha sido tomado, debido a que los cuartos vecinos tambien estan ocupados, debes elegir un nuevo cuarto"<<endl;
			cout<<"Elige un nuevo cuarto: "; cin>>nuevo_cuarto;
			nuevo_nodo->cuarto = nuevo_cuarto;
			c = nuevo_cuarto;
			system("cls");
		}
		
		comprobante = comprobante->sgte;
		
			
	}
	
	while((aux1 != NULL) && (aux1->cuarto < c)){
		aux2 = aux1;
		aux1 = aux1->sgte;
	} 
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->sgte = nuevo_nodo;
	}
	
	nuevo_nodo->sgte = aux1;
	cout<<"El huesped "<<nuevo_nodo->nombre<<" ha sido alojado en la habitacion "<<nuevo_nodo->cuarto<<endl;
}

void insertarHuespedOrden(Nodo *&lista2, string n, int c){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->nombre = n;
	nuevo_nodo->cuarto = c;
	
	Nodo *aux1 = lista2;
	Nodo *aux2;
	
	
	while(aux1 != NULL){
		aux2 = aux1;
		aux1 = aux1->sgte;
	} 
	
	if(lista2 == aux1){
		lista2 = nuevo_nodo;
	}
	else{
		aux2->sgte = nuevo_nodo;
	}
	
	nuevo_nodo->sgte = aux1;
}


void mostrarhuespedes(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	
	while(actual != NULL){
		cout<<"Huesped: "<<actual->nombre<<" Habitacion: "<<actual->cuarto<<endl;
		actual = actual->sgte;
	}
	cout<<endl;
}

void buscarNombre(Nodo *lista, string n){
	bool comprobante = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	int aux;
	
	
	while(actual != NULL){
		if(actual->nombre == n){
			comprobante = true;
			aux = actual->cuarto;
		}
		actual = actual->sgte;
	}
	
	if(comprobante){
		cout<<"El huesped "<<n <<" esta en el cuarto: "<<aux<<endl;
	}
	else{
		cout<<"No hay ningun huesped con ese nombre :(" <<endl;
	}
}

void buscarCuarto(Nodo *lista, int c){
	bool comprobante = false;
	
	Nodo *actual = new Nodo();
	actual = lista;
	string aux;
	
	while(actual != NULL){
		if(actual->cuarto == c){
			comprobante = true;
			aux = actual->nombre;
		}
		actual = actual->sgte;
	}
	
	if(comprobante){
		cout<<"En el cuarto "<<c <<" esta alojado "<<aux<<endl;
	}
	else{
		cout<<"No hay ningun huesped en este cuarto"<<endl;
	}
}

void eliminarhuespedNombre(Nodo *&lista, string n){
	//Preguntar si la lista no esta vacia
	if(lista != NULL){
		Nodo *aux;
		Nodo *anterior = NULL;
		
		aux = lista;
		
		while((aux != NULL)&&(aux->nombre != n)){
			anterior = aux;
			aux = aux->sgte;
		}
		
		//El huesped no ha sido encontrado
		if(aux == NULL){
			cout<<"El huesped a eliminar no ha sido encontrado"<<endl;
		}
		//El primer huesped es el que vamos a eliminar
		else if (anterior ==NULL){
			lista = lista->sgte;
			cout<<"Se ha eliminado a " <<aux->nombre <<" ubicado en el cuarto: "<<aux->cuarto<<endl;
			delete aux;
		}
		//El elemento esta en la lista pero, no es el primer nodo
		else {
			anterior->sgte = aux->sgte;
			cout<<"Se ha eliminado a " <<aux->nombre <<" ubicado en el cuarto: "<<aux->cuarto<<endl;
			delete aux;
		}
	}
}

void eliminarhuespedCuarto(Nodo *&lista, int c){
	//Preguntar si la lista no esta vacia
	if(lista != NULL){
		Nodo *aux;
		Nodo *anterior = NULL;
		
		aux = lista;
		
		while((aux != NULL)&&(aux->cuarto != c)){
			anterior = aux;
			aux = aux->sgte;
		}
		
		//El huesped no ha sido encontrado
		if(aux == NULL){
			cout<<"El huesped a eliminar no ha sido encontrado"<<endl;
		}
		//El primer huesped es el que vamos a eliminar
		else if (anterior ==NULL){
			lista = lista->sgte;
			cout<<"Se ha eliminado a " <<aux->nombre <<" ubicado en el cuarto: "<<aux->cuarto<<endl;
			delete aux;
		}
		//El elemento esta en la lista pero, no es el primer nodo
		else {
			anterior->sgte = aux->sgte;
			cout<<"Se ha eliminado a " <<aux->nombre <<" ubicado en el cuarto: "<<aux->cuarto<<endl;
			delete aux;
		}
	}
}

void guardar(Nodo *lista){
	ofstream archivo;
	Nodo *actual = new Nodo();
	actual = lista;
	
	archivo.open("hotel.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	while(actual != NULL){
		archivo<<actual->nombre<<endl;
		archivo<<actual->cuarto<<endl;
		actual = actual->sgte;
	}
	cout<<endl;
}

void guardarOrden(Nodo *lista2){
	ofstream archivo;
	Nodo *actual = new Nodo();
	actual = lista2;
	
	archivo.open("hotel2.txt",ios::out);
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	while(actual != NULL){
		archivo<<actual->nombre<<endl;
		archivo<<actual->cuarto<<endl;
		actual = actual->sgte;
	}
	cout<<endl;
}

void cargar(Nodo *&lista){
	ifstream archivo;
	string texto;
	
	archivo.open("hotel.txt",ios::in); 
	
	if(archivo.fail()){
		cout<<"Ha habido un error a la hora de leer el archivo";
		exit(1);
	}
	
	while(getline(archivo,texto)){
		Nodo *nuevo_nodo = new Nodo();	
		
		nuevo_nodo->nombre = texto;
		getline(archivo, texto);
		
		
		int aux = stoi(texto, nullptr, 10);
		nuevo_nodo->cuarto = aux;
	

		
		
		
		Nodo *aux1 = lista;
		Nodo *aux2;
		
		while(aux1 != NULL){
			aux2 = aux1;
			aux1 = aux1->sgte;
		} 
		
		if(lista == aux1){
			lista = nuevo_nodo;
		}
		else{
			aux2->sgte = nuevo_nodo;
		}
		
		nuevo_nodo->sgte = aux1;
	}
}

void cargarOrden(Nodo *&lista2){
	ifstream archivo;
	string texto;
	
	archivo.open("hotel2.txt",ios::in); 
	
	if(archivo.fail()){
		cout<<"Ha habido un error a la hora de leer el archivo";
		exit(1);
	}
	
	while(getline(archivo,texto)){
		Nodo *nuevo_nodo = new Nodo();	
		
		nuevo_nodo->nombre = texto;
		getline(archivo, texto);
		
		
		int aux = stoi(texto, nullptr, 10);
		nuevo_nodo->cuarto = aux;
	

		
		
		
		Nodo *aux1 = lista2;
		Nodo *aux2;
		
		while(aux1 != NULL){
			aux2 = aux1;
			aux1 = aux1->sgte;
		} 
		
		if(lista2 == aux1){
			lista2 = nuevo_nodo;
		}
		else{
			aux2->sgte = nuevo_nodo;
		}
		
		nuevo_nodo->sgte = aux1;
	}
}


void buscarVecinos(Nodo *lista, int c) {
	Nodo *actual = new Nodo();
	actual = lista;
	string vecino1, vecino2;
	
	while(actual != NULL){
		if(actual->cuarto == c-1){
			vecino1 = actual->nombre;
		}
		else if(actual->cuarto == c+1){
			vecino2 = actual->nombre;
		}
		actual = actual->sgte;
	}
	
	cout<<"Los vecinos son: habitacion "<<c-1<<": "<<vecino1<<" y habitacion "<<c+1<<": "<<vecino2<<endl;	
}


void alfabetico(Nodo *lista){
	Nodo *actual = new Nodo();
	string nombres[50];
	actual = lista;
	int i = 0;
	int contador = 0;
	string aux;
	
	while(actual != NULL){
		aux = actual->nombre;
		nombres[i] = aux;
		actual = actual->sgte;
		i++;
		contador++;
	}
	
	for(int h = 0 ; h< contador;h++){
    	for(int k = h + 1;k < contador;k++){
        	if(nombres[h]>nombres[k]){ 
            	aux = nombres[k]; 
            	nombres[k] = nombres[h]; 
            	nombres[h] = aux; 
            }
        }
    }
	
	
	for(int j = 0; j <= contador; j++){
		cout<<nombres[j]<<endl;
	}
}

void mostrarhuespedesPorOrden(Nodo *lista2){
	Nodo *actual = new Nodo();
	actual = lista2;
	
	while(actual != NULL){
		cout<<"Huesped: "<<actual->nombre<<" Habitacion: "<<actual->cuarto<<endl;
		actual = actual->sgte;
	}
	cout<<endl;
}



