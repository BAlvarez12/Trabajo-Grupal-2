
// Grupo  NO# 6
// Creado por Bryann Alvarez
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std; 


const char *nombre_archivo;


struct Palabras{
	int codigo;
		char nombre[50];
			char traduccion[50];
				char funcionalidad[1000];
	};
			
		void leer() { // Creado por GEOVANNY MARTINEZ 
    
    		system("cls");
    			FILE* archivo = fopen(nombre_archivo, "r");
   					 if (!archivo) {
        				archivo = fopen(nombre_archivo, "w+b");
    }

		    if (archivo) {
		        cout<<"________________________________"<<endl;
		        cout<<"id"<<"|"<<"Codigo"<<"|"<<"Nombre"<<"|"<<"Traduccion"<<"|"<<"Funcionalidad"<<endl;
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




	void crear(){  // Creado por CARLOS CU
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
	
	
	
	void actualizar() { // Creado por CRISTIAN BARILLAS
    system("cls");
		leer();
	    FILE* archivo=fopen(nombre_archivo,"r");
	    FILE* archivo_temp=fopen("temp.dat","w");
	    if(!archivo||!archivo_temp){
	        cerr<<"Error al abrir el archivo."<<endl;
	        return;
	    }
    int id_borrar;
	    cout<<"Ingrese el ID que desea actualizar: ";
	    cin>>id_borrar;

    bool encontrado=false;
    char linea[1200];
    int id=0;

    while(fgets(linea,sizeof(linea),archivo)){
        stringstream ss(linea);
        string token;
        int contador =0;
        while(getline(ss,token,'|')){
            if(contador==0){
                if (id==id_borrar){
                    encontrado=true;
                    Palabras palabra;

                    cout<<"Ingrese el nuevo codigo: ";
                    cin>>palabra.codigo;
                    cin.ignore();

	                    cout<<"Ingrese el nuevo nombre de la palabra: ";
	                    cin.getline(palabra.nombre,50);

		                    cout<<"Ingrese la nueva traduccion: ";
		                    cin.getline(palabra.traduccion,50);

			                    cout<<"Ingrese la nueva funcionalidad: ";
			                    cin.getline(palabra.funcionalidad,1000);
                    string nueva_linea=to_string(palabra.codigo)+"|"+palabra.nombre+"|" +palabra.traduccion+"|" +palabra.funcionalidad+ "\n";
                    fputs(nueva_linea.c_str(),archivo_temp);
                }else{
                    fputs(linea,archivo_temp);
                }
            }
            contador++;
        }
        id++;
    }
	    fclose(archivo);
	    fclose(archivo_temp);
	
	    remove(nombre_archivo);
	    rename("temp.dat", nombre_archivo);
	
	    if (!encontrado) {
	        cout<<"ID no encontrado"<<endl;
	    } else {
	        cout<<"Actualizacion completada"<<endl;
	        leer();
	    }
	}
	
	
	
	
	void borrar(){ // Creado por DARY PEREZ
			
		    system("cls");
			leer();
		    FILE* archivo=fopen(nombre_archivo,"r");
		    FILE* archivo_temp=fopen("temp.dat","w");
    if (!archivo || !archivo_temp){
        	cerr<<"Error al abrir el archivo."<<endl;
        		return;
    }
    int id_borrar;
    cout<<"Ingrese el ID que desea borrar: ";
    cin>>id_borrar;

    	bool encontrado = false;
    	char linea[1200];
    	int id = 0;

		    while(fgets(linea,sizeof(linea),archivo)){
		        stringstream ss(linea);
		        string token;
		        int contador=0;
		        while (getline(ss,token,'|')){
		            if(contador == 0){
		                if(id==id_borrar){
		                    encontrado=true;
		                }else{
		                    fputs(linea,archivo_temp);
		                }
            }
            contador++;
        }
        id++;
    }
    fclose(archivo);
    fclose(archivo_temp);

    		remove(nombre_archivo);
   			 rename("temp.dat", nombre_archivo);

		    if (!encontrado) {
		        cout << "ID no encontrado." << endl;
		    } else {
		        cout << "Borrado completado." << endl;
		        leer();
		    }
		}
