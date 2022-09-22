#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Vendedor
{
private:
	int codigo;
	int usuario;
	string contrasena;

public:
	Vendedor() {
		
	}

	void setcodigo(int cod) {
		codigo = cod;
	}
	void setusuario(int user) {
		usuario = user;
	}
	void setcontra(string password) {
		contrasena = password;
	}

	int getcodigo() {
		return codigo;
	}
	int getusuario() {
		return usuario;
	}
	string getcontrasena() {
		return contrasena;
	}
};
