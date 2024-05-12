Dary: Crear el void de borrar 

Geovanny Martinez: Crear void leer

Carlos CU: Crear Void Borrar

Cristian: Crear el void de Actualizar


Fase I

1. Crear un programa que permita agregar palabras en un archivo, con su
respectiva traducción y funcionalidad ejemplo:

Ingrese Palabras: if
Ingrese Traducción: si
Ingrese Funcionalidad: es una estructura de control que valida una condición
y nos permiten determinar qué acciones tomar dada o no cierta condición.

Dicho archivo deberá de contener un listado mínimo de estas palabras

asm, auto, bool, break, case, catch, char, class, const, const_cast, continue,
default, delete, do, double, dynamic_cast, else, enum, explicit, extern, false,
float, for, friend, goto, if, inline, int, long, mutable, namespace, new, operator,
private, protected, public, register, reinterpret_cast, return, short, signed, sizeof,
static, static_cast, struct, switch, template, this, throw, true, try, typedef, typeid,
typename, union, unsigned, using, virtual, void, volatile, while

3. El programa me debe permitir hacer un CRUD (Crear, Leer, Actualizar
y Borrar) del listado de palabras que estoy elaborando en el archivo.

4.Crear un programa que me permita ingresar texto multilíneas y me
permita traducir una porción de código escrito en c++ , tomando como
base las palabras que definimos en la Fase I, con la salvedad que las llaves
{} serán tomadas como inicio y fin concatenadas con el nombre de su
respectiva estructura de control, a excepción de que si fuera un método
y/o función en ese caso no se traducirá las llaves


EJEMPLO


nt main(){

string continuar;

cout<<"Desea continuar si/no :";

cin>>continuar;

if (continuar=="si"){

cout<<"Gracias.."<<endl;

}else{

exit(1);

}

return 0;

}

Traducir

entero principal (){

cadena continuar;

cout<<"Desea continuar si/no :";

cin>>continuar;

si (continuar=="si") inicio si

cout<<"Gracias.."<<finalizar;

fin si

entonces inicio entonces

salir(1);

fin entonces

retorno 0;

}
