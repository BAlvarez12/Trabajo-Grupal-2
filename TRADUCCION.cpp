#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

	unordered_map<string,string>traduccion(const string&archivo_){
    	unordered_map<string,string>traducciones;
    		ifstream archivo(archivo_);

    if (archivo.is_open()){
        string linea;
        while(getline(archivo,linea)){
            size_t pos_pipe1=linea.find('|');
            size_t pos_pipe2=linea.find('|',pos_pipe1 + 1);
            size_t pos_pipe3=linea.find('|',pos_pipe2 + 1);

            if (pos_pipe1!=string::npos&&pos_pipe2!=string::npos&&pos_pipe3!=string::npos){
                string palabra=linea.substr(pos_pipe1+1,pos_pipe2-pos_pipe1-1);
                string traduccion=linea.substr(pos_pipe2+1,pos_pipe3-pos_pipe2-1);
                traducciones[palabra]=traduccion;
            }
        }
        archivo.close();
        }else{
        cerr<<"No se pudo abrir el archivo"<<endl;
    	}
  		 return traducciones;
		}

    	string tcodigo(const string&codigo,const unordered_map<string,string>&traducciones){
   			string codigo_traducido;
    			string palabra;
    				size_t inicio=0;
    					size_t fin=codigo.find_first_of(" \n\t.,;:?!", inicio);

    	while(fin!=string::npos){
        	palabra=codigo.substr(inicio,fin-inicio);
        		auto iterador=traducciones.find(palabra);
        			if (iterador!=traducciones.end()){
            			codigo_traducido+=iterador->second+" ";
       		}else{
            codigo_traducido+=palabra+" ";
        	}
        inicio=fin+1;
        	fin=codigo.find_first_of(" \n\t.,;:?!", inicio);
    	}
    	
    	palabra=codigo.substr(inicio);
    		auto iterador=traducciones.find(palabra);
    			if (iterador!=traducciones.end()){
        			codigo_traducido+=iterador->second;
    		}else{
        codigo_traducido += palabra;
    	}
   		 return codigo_traducido;
		}
		

	void traduccion(){
   		string archivo_="original.dat";
    		unordered_map<string,string>traducciones=traduccion(archivo_);
    	string codigo;
   			string terminacion="FIN"; 

    	cout<<"Ingrese su codigo.... Para salir coloque FIN"<<endl;
   	 		while (true) {
       			 string linea;
       				 getline(cin, linea);
        if(linea==terminacion){
            break;
        }
        codigo+=linea+"\n";
    }
    cout<<"El codigo que ingresaste es: "<<endl;
    cout<<codigo<<endl;

    string codigo_traducido=tcodigo(codigo,traducciones);
    cout<<"El codigo traducido es: "<<endl;
    cout<<codigo_traducido<<endl;

    return ;
}

