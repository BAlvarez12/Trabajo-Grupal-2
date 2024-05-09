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

// metodo CRUD 
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
				
				cout<<"____Actualizar archivo____:"<<endl;
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
        				archivo = fopen(nombre_archivo, "w+b");
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

    void crear(){  
		FILE* archivo= fopen(nombre_archivo,"a+b");
		
			char res;
			cout<<"  "<<endl;
			cout<<"Ingrese los datos del archivo"<<endl;
			cout<<"  "<<endl;
			
				Palabras palabra;
				
				do{
		
					fflush(stdin);
		
					cout<<"Ingrese codigo:";
						cin>>palabra.codigo;
							cin.ignore();
						
					cout<<"Ingrese el nombre de la palabra:";
						cin.getline(palabra.nombre,50);
						
					cout<<"Ingrese la traduccion:";
						cin.getline(palabra.traduccion,50);
						
					cout<<"Ingrese su funcionalidad:";
						cin.getline(palabra.funcionalidad,1000);
						
				 	 string linea = to_string(palabra.codigo) + "|" + palabra.nombre + "|" + palabra.traduccion + "|" + (palabra.funcionalidad)+ "\n";
          			  fwrite(linea.c_str(), sizeof(char),linea.size(),archivo);
						
					cout<<"Desea Ingresar otra palabra? S/N:";
						cin>>res;
						
					}while(res== 's'||res=='S');
						fclose(archivo);
							leer();
	
	}

// opcion BORRAR  

void borrar() {
    	// Abre el archivo en modo de lectura y escritura
    	FILE* archivo = fopen(nombre_archivo, "r+b");
   	 if (!archivo) {
       	 cerr << "No se pudo abrir el archivo." << endl;
       	 return;
	    }
	
	    if (encontrado) {
	        cout << "La palabra fue eliminada" << endl;
	    } else {
	        cout << "No se encuentra ninguna palabra con este codigo " << endl;
	    }
}
