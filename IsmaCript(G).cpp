//Version 1.0 - GitHub

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

//Definir funciones de la app.
string encriptar(string texto, int clave);
string dencriptar(string texto, int clave);
string leerFile(string path);
int saveFile(string texto, int opc, string name);

//1 = Encriptar.
//2 = Desenceiptar.

/* El algoritmo de encriptación esta mas sinplificado para conservar la seguridad de mis propios archivos, 
si deseas mejorarla estas en tu derecho, te recomiendo no publicar la formula que uses por sefuridad. */

int main(){
	
	//Declarar variables para la ruta, contraseña, nombre final y la accion a ejecutar.
	string path;
	int pass;
	string opc;
	string fileName;
	
	cout << "\tEncriptar y Desencriptar archivos de texto" << endl;
	cout << "1.- Encriptar\n2.- Desencriptar" << endl;
	cout << "Opcion:";
	getline(cin, opc); //Seleccionar accion a realizar.
	cout << "Ruta: ";
	getline(cin, path); //Seleccionar la ruta relativa del archivo.
	cout << "Nombre del archivo final: ";
	getline(cin, fileName); //Ingresar nombre para el archivo final.
	printf("Contrase%ca (numero): ", 164);
	cin >> pass; //Ingresar contraseña a usar en el algoritmo.
	
	string s1;
	s1 = leerFile(path); //Leer el archivo en el que se ejecutara la accioin elegida.
	
	pass = pass / 5; //Hacer la contraseña mas corta (para evitar que el codigo ASCII sea demasiado grande).
	
	
	if (opc == "1"){
		//Si se elige encriptar, hacerlo en base al archivo leido anteriormente.
		string enc = encriptar(s1, pass);
		saveFile(enc, 1, fileName);
	}else if (opc == "2"){
		//Si se elige desencriptar, hacerlo en base al archivo leido anteriormente.
		string dec = dencriptar(s1, pass);
		saveFile(dec, 2, fileName);
	}
    
    cout << "\nProceso terminado con exito :-)" << endl;
    system("pause");
    return 0;
}


string encriptar(string texto, int clave){
	
	int ascChar[texto.length()]; //Guardar el largo del texto en una variable.
	string ret;
	
	for (int i=0; i<texto.length(); i++){
		
        ascChar[i] = texto[i]; //Convertir cada caracter del texto a ASCII.
        ascChar[i] = ascChar[i] + clave; //Modificar el codigo ASCII con la contraseña.
        string value;
        value = (char) ascChar[i]; //Convertir ASCII a texto.
        ret = ret + value; //Agregar el caracter a la variable de texto.
    }
    
    return ret; //Devolver el texto encriptado.
}


string dencriptar(string texto, int clave){
	
	int ascChar[texto.length()]; //Guardar el largo del texto en una variable.
	string ret;
	
	for (int i=0; i<texto.length(); i++){
	       
        ascChar[i] = texto[i]; //Convertir cada caracter del texto a ASCII.
        ascChar[i] = ascChar[i] - clave; //Modificar el codigo ASCII con la contraseña.
        string value;
        value = (char) ascChar[i]; //Convertir ASCII a texto.
        ret = ret + value; //Agregar el caracter a la variable de texto.
    }
    
    return ret; //Devolver el texto desencriptado.
}


string leerFile(string path){
	
	//Definir variables.
	string ret;
	string myText;
	
	ifstream MyFile(path); //Abrir archivo para lectura.
	
	while (!MyFile.eof()) {
		getline (MyFile, myText); //Guardar 1 caracter del texto en una variable.
        ret = ret + myText; //Agregar dicho caracter a la variable del texto.
    }
    MyFile.close(); // Cerrar archivo.
	
	return ret; //Devolver textop leido.
}


int saveFile(string texto, int opc, string name){
	
	string ext;
	
	//Determinar el nombre y extension del archivo segun la accion a realizar.
	if (opc == 1){
		ext = name + ".iscg";
	}else if (opc == 2){
		ext = name + ".txt";
	}
	
	ofstream myFile(ext); //Crear y abrir archivo.
	
	myFile << texto; //Guardar texto en el archivo.
	
	myFile.close(); //Cerrar archivo.
	
	return 0;
}
