// Bryann Alvarez
#include "CRUD.cpp"
#include "TRADUCCION.cpp"
#include <iostream>

using namespace std;


     main(){
 

   		int opcion;
		do{
	    cout<<"Que accion desea realizar"<<endl;
	  	  cout<<"_____________________________"<<endl;
	     	cout<<"1.Leer Archivo"<<endl;
	     	    cout<<"2.Crear Archivo"<<endl;
	      			cout<<"3.Actualizar datos del Archivo"<<endl;
	      	 			 cout<<"4.Borrar datos del Archivo"<<endl;
	      	  				 cout<<"5.Traduccir codigo"<<endl;
	      	  				   cout<<"6. salir"<<endl;
	      	  	 				cout<<"_______________________"<<endl;
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
				cout<<"_____Crear nuevo Archivo_______"<<endl;
				cout<<"Que nombre le colocara al archivo: ";
				cin>>nombre;
				nombre += ".dat";
				nombre_archivo = nombre.c_str();
			 	crear();
			 	return 0;
		}	
			case 3:{
				string nombre;
				cout<<"____Actualizar datos del Archivo_____"<<endl;
				cout<<"Coloca el nombre exacto del archivo y extencion .dat:  "<<endl;
				cin>>nombre;
				nombre_archivo = nombre.c_str();
			 	actualizar();
			 	return 0;
		}
	        case 4:{
	        	string nom;
	        	cout<<"_____Borrar datos del Archivo____"<<endl;
	        	cout<<"Coloca el nombre exacto del archivo y extencion .dat: "<<endl;
	        	cin>>nom;
	        	nombre_archivo = nom.c_str();
	        	borrar();
	        	return 0;// Bryann Alvarez	
			}
			case 5:{
				 traduccion();
				return 0;
			}
	    }
	}while (opcion != 6);
	        		
		system("pause"); // Creado por Bryann Alvarez
	}
