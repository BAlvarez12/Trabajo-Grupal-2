#include <iostream>
using namespace std; 


const char *nombre_archivo;

// Estructura del archivo (Columnas)
struct Palabras{
	int codigo;
		char nombre[50];
			char traduccion[50];
				char funcionalidad[100];
	
	};

	// Estructura para llamar los VOID Bryann
	void leer();
		void crear();

	main (){
		
		int opcion;
	    cout<<"Que accion desea realizar"<<endl;
	     cout<<"1.Leer Archivo"<<endl;
	      cout<<"2.Crear Archivo"<<endl;
	      	cin>>opcion;
	    switch (opcion){
	    	
	    	case 1:
				cout<<"_____Abriendo Archivo_______"<<endl;
				cout<<"Archivos disponibles en la carpeta actual:"<<endl;
				
			 	leer();
			 	return 0;
			case 2:
			
				string nombre;	
				
				cout<<"_____Crear Archivo_______"<<endl;
				cout<<"Que nombre le colocara al archivo: ";
				cin>>nombre;
				nombre_archivo = nombre.c_str();
			 	crear();
			 	return 0;
		}	
	  
		
		system("pause");
    }

	void leer(){  // Leer el archivo Traduccion
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
					cout<<id<<"|"<<palabra.codigo<<"|"<<palabra.nombre<<"|"<<palabra.traduccion<<"|"<<palabra.funcionalidad<<endl;
						fread(&palabra,sizeof(Palabras),1,archivo);
							id+=1;
								}while(feof(archivo)==0);
									fclose(archivo);
		
		
	}
	void crear(){  //Crear archivo
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
						cin>>palabra.funcionalidad,50;
						
					fwrite(&palabra,sizeof(Palabras),1,archivo);
						
					cout<<"Desea Ingresar otra palabra? S/N:";
						cin>>res;
						
					}while(res== 's'|| res == 'S');
						fclose(archivo);
							leer();
	
	}
