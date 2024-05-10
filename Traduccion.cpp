#include <iostream>
#include <string>
#include <sstream>

using namespace std; 


const char *nombre_archivo;


struct Palabras{
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
        				archivo = fopen(nombre_archivo, "w+b");
    }

		    if (archivo) {
		        cout<<"________________________________"<<endl;
		        cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Traduccion"<<"|"<<"Funcionalidad"<< endl;
		        cout<<"________________________________" << endl;

			        char linea[1200];
			        int id = 0;
			        while (fgets(linea, sizeof(linea), archivo)) {
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

	void crear(){  // Creado por GEOVANNY MARTINEZ 
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
	void actualizar() { // Creado por CARLOS CU
			    leer();
			    FILE* archivo = fopen(nombre_archivo, "r+b");
			    if (!archivo) {
			        cerr<<"No se pudo abrir el archivo"<<endl;
			        return;
    }

		    Palabras palabra;
		    int id;
		    char res;
		    do {
		        cout<<"Ingrese el ID que desea modificar: ";
		        cin>>id;

      
	        fseek(archivo, id*sizeof(Palabras),SEEK_SET);
	        fread(&palabra, sizeof(Palabras),1,archivo);
	        cout<<"ID: "<<id<<", Codigo: "<<palabra.codigo<<", Nombre: "<<palabra.nombre<<", Traducción: "<<palabra.traduccion<<", Funcionalidad: "<<palabra.funcionalidad<<endl;

        
	        cout<<"Ingrese nuevo codigo: ";
	        cin>>palabra.codigo;
		        cout<<"Ingrese nuevo nombre: ";
		        cin.ignore();
			        cin.getline(palabra.nombre, 50);
			        cout<<"Ingrese nueva traduccion: ";
				        cin.getline(palabra.traduccion, 50);
				        cout<<"Ingrese nueva funcionalidad: ";
	       					 cin.getline(palabra.funcionalidad, 1000);
		        stringstream linea;
		        linea<<palabra.codigo<<"|"<<palabra.nombre<<"|"<<palabra.traduccion<<"|"<<palabra.funcionalidad<<"|";

		     
		        string lineaStr = linea.str();
		        int longitudLinea = lineaStr.length();

		      
		        if(longitudLinea<1200){
		            linea<<string(1200 -longitudLinea, ' '); 
		        }

       
		        fseek(archivo, id*1200,SEEK_SET); 
		        fwrite(linea.str().c_str(),sizeof(char),1200,archivo); 
		
		        cout<<"Desea modificar otro registro (S/N): ";
		        cin>>res;
		    } while (res =='s'||res=='S');

		    fclose(archivo);
		    leer(); 
}

	void borrar(){// Creado por DARY PEREZ
			leer();
			const char * nombre_archivo_temp = "archivo_temp.dat";
			FILE* archivo= fopen(nombre_archivo,"rb");
			FILE* archivo_temp= fopen(nombre_archivo_temp,"w+b");
			Palabras palabra;
				int id=0,id_n=0;
				cout<<"Ingrese el ID que desea borar:";
				cin>>id;
				while(fread(&palabra,sizeof(Palabras),1,archivo)){
					if(id_n!= id){
						fwrite(&palabra,sizeof(Palabras),1,archivo_temp);
					}
					id_n++;
				}
		
				fclose(archivo);
					fclose(archivo_temp);
						archivo_temp= fopen(nombre_archivo_temp,"rb");
							archivo= fopen(nombre_archivo,"wb");
			   					 while(fread(&palabra,sizeof(Palabras),1,archivo_temp)){
			    					fwrite(&palabra,sizeof(Palabras),1,archivo);
			}
				fclose(archivo);
					fclose(archivo_temp);
						leer();
			}

