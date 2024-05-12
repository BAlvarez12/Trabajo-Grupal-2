#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

	unordered_map<string,string>traduccion(const string&&archivo_){
    	unordered_map<string,string>traducciones;
    		ifstream archivo(archivo_);

    if (archivo.is_open()){
        string linea;
        while(getline(archivo,linea)){
            size_t pos_pipe1=linea.find('|');
            size_t pos_pipe2=linea.find('|',pos_pipe1 + 1);
            size_t pos_pipe3=linea.find('|',pos_pipe2 + 1);

            if (pos_pipe1!=string::npos&pos_pipe2!=string::npos&&pos_pipe3!=string::npos){
                string palabra=linea.substr(pos_pipe1+1,pos_pipe2-pos_pipe1-1);
                string traduccion=linea.substr(pos_pipe2+1,pos_pipe3-pos_pipe2-1);
                traducciones[palabra]=traduccion;
            } 
        }
    
        }else{
        cerr<<"No se pudo abrir el archivo"<<endl;
    	}
  		 return traducciones;
		}
