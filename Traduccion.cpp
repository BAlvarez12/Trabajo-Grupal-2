#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>

using namespace std; 


const char *nombre_archivo;

// Estructura del archivo (Columnas)
struct Palabras{
	int codigo;
		char nombre[50];
			char traduccion[50];
				char funcionalidad[1000];
	
	};

	// Estructura para llamar los VOID Bryann
	void leer();
	void crear();
	void actualizar ();
	void borrar ();
	

	main (){
			int opcion;
		do{
		
	
	    cout<<"Que accion desea realizar"<<endl;
	     cout<<"1.Leer Archivo"<<endl;
	      cout<<"2.Crear Archivo"<<endl;
	      	cout<<"3.Actualizar datos del Archivo"<<endl;
	      	  cout<<"4.Borrar datos del Archivo"<<endl;
	      	   cout<<"5.Salir"<<endl;
	      		cin>>opcion;
	    switch (opcion){
	    	
	    	case 1:{
			
	    		
	    		string nom;
				
				cout<<"_____Abriendo Archivo_______"<<endl;
				cout<<"Coloca el nombre exacto del archivo y extencion .dat:"<<endl;
            	cin>>nom;
            	nombre_archivo = nom.c_str();
            	leer();
			 	return 0;
			
		}
			case 2:{
		
			
				string nombre;	
				
				cout<<"_____Crear Archivo_______"<<endl;
				cout<<"Que nombre le colocara al archivo: ";
				cin>>nombre;
				nombre += ".dat";
				nombre_archivo = nombre.c_str();
			 	crear();
			 	return 0;
		}	
			case 3:{
				
				string nombre;
				
				cout<<"____Actualizar Archivos_____"<<endl;
				cout<<"Coloca el nombre exacto del archivo y extencion .dat:  "<<endl;
				cin>>nombre;
				nombre_archivo = nombre.c_str();
			 	actualizar();
			 	return 0;
			
		}
	        case 4:{
	        	
	        	string nom;
	        	cout<<"_____Borrar Archivo____"<<endl;
	        	cout<<"Coloca el nombre exacto del archivo y extencion .dat: "<<endl;
	        	cin>>nom;
	        	nombre_archivo = nom.c_str();
	        	borrar();
	        	return 0;
	        	
			}
	    }
	}while (opcion != 5);
	        		
		system("pause");
	}
	void leer(){  // Leer el archivo Traduccion Bryann
		system("cls");
			FILE* archivo= fopen(nombre_archivo,"rb");
				if(!archivo){
					archivo= fopen(nombre_archivo,"w+b");
			}
			Palabras palabra;
				int id=0;
					fread(&palabra,sizeof(Palabras),1,archivo);
						cout<<"________________________________"<<endl;
							cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Traduccion"<<"|"<<"Funcionalidad"<<endl;
				do{
					cout<<id<<" |"<<palabra.codigo<<"     |"<<palabra.nombre<<"      |"<<palabra.traduccion<<"     |"<<palabra.funcionalidad<<endl;
						fread(&palabra,sizeof(Palabras),1,archivo);
							id+=1;
								}while(feof(archivo)==0);
									fclose(archivo);
		
		
	}

