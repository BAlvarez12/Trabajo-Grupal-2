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
			
			case 6:{
		
				 unordered_map<string, string> diccionario = cargarDiccionario();

				    string codigoCpp;
				    cout << "Ingrese el codigo C++ a traducir:" << endl;
				    getline(cin, codigoCpp);
				
				    string codigoTraducido = traducirCodigo(codigoCpp, diccionario);
				
				    cout << "El código traducido es:" << endl;
				    cout << codigoTraducido << endl;
				
				    return 0;
			}
	    }
	}while (opcion != 5);
	        		
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
					cout<<id<<" |"<<palabra.codigo<<"     |"<<palabra.nombre<<"      |"<<palabra.traduccion<<"     |"<<palabra.funcionalidad<<endl;
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
						cin.getline(palabra.funcionalidad,1000);
						
					fwrite(&palabra,sizeof(Palabras),1,archivo);
						
					cout<<"Desea Ingresar otra palabra? S/N:";
						cin>>res;
						
					}while(res== 's'|| res == 'S');
						fclose(archivo);
							leer();
	
	}
	void actualizar(){
	char res;	

		
		leer();
		FILE* archivo= fopen(nombre_archivo,"r+b");
	Palabras palabra;
	int id=0;
		do{	
	cout<<"Ingrese el ID que desea modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Palabras),SEEK_SET);
		
		cout<<"Ingrese codigo:";
		cin>>palabra.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombre:";
		cin.getline(palabra.nombre,50);
		
		cout<<"Ingrese Traduccion:";
		cin.getline(palabra.traduccion,50);
		
		cout<<"Ingrese Funcionalidad:";
		cin.getline(palabra.funcionalidad,1000);
		fwrite(&palabra,sizeof(Palabras),1,archivo);
		cout<<"Desea Ingresar otra palabra? S/N:";
		cin>>res;
		}while(res== 's'|| res == 'S');
	fclose(archivo);
	leer();
}

	void borrar(){
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

