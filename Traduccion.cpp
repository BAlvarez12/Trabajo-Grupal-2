#include <iostream>
#include <string>
#include <sstream>

using namespace std; 


const char *nombre_archivo;


struct Palabras{ // Estructura de las palabras
	int codigo;
		char nombre[50];
			char traduccion[50];
				char funcionalidad[1000];
	
	};


	void leer();
	void crear();
	void actualizar ();
	void borrar ();
	

	main (){
			int opcion;
		do{
		// switch para poder tener opciones multiples
	
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
	
	
		void leer() {
    
    		system("cls");
    			FILE* archivo = fopen(nombre_archivo, "r");
   					 if (!archivo) {
        				archivo = fopen;
    }

		    if (archivo) {
		        cout<<"________________________________"<<endl;
		        cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Traduccion"<<"|"<<"Funcionalidad"<< endl;
		        cout<<"________________________________" << endl;

			        char linea[1200]; //tamano para leer una linea de codigo
			        int id = 0;
			        while (fgets(linea, sizeof(linea), archivo)) {
        	
		            // Dividir la línea usando el delimitador "|"
		            stringstream ss(linea);
		            string token;
		            int contador =0;
		            while(getline(ss, token,'|')){
		                if(contador ==0){
		                    cout<<id++<<"|";
		                }
		                cout<<token<<"|"; 
		                contador++;
		            }
		            cout << endl;
		        }

		        fclose(archivo);
		    } else {
		        cerr << "No se pudo abrir el archivo." << endl;
		    }
}
