#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Vendedor.h"
using namespace std;
using std::stoi;
class VendedorVector
{
private:
	vector<Vendedor> vectorVendedor;
public:
	VendedorVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<Vendedor> vectorVendedor;
	}

	int getCorrelativo()
	{
		if (vectorVendedor.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorVendedor[vectorVendedor.size() - 1].getcodigo() + 1;
		}
	}

	Vendedor get(int pos)/*entregar el objeto actual, según la posicion pasada como parámetro*/
	{
		return vectorVendedor[pos];
	}

	int rows()
	{
		return vectorVendedor.size();
	}

	void agregar(Vendedor obj)
	{
		vectorVendedor.push_back(obj);
	}

	Vendedor buscarPorUsuario(int usuario)
	{
		Vendedor objError;
		objError.setusuario(0);

		for (Vendedor x : vectorVendedor)
		{
			if (usuario == x.getusuario())
			{
				return x;
			}
		}
		return objError;
	}

	int getPostArray(Vendedor obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getusuario() == get(i).getusuario())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(Vendedor obj)
	{
		vectorVendedor.erase(vectorVendedor.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Vendedor vendedor)
	{
		try
		{
			fstream archivoVendedor;
			archivoVendedor.open("vendedor.csv", ios::app);
			if (archivoVendedor.is_open())
			{
				archivoVendedor << vendedor.getcodigo() << ";" << vendedor.getusuario() << ";" << vendedor.getcontrasena() << ";" << endl;
				archivoVendedor.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;//Cantidad maxima
			string linea;
			string temporal[3];//Cantidad de columnas
			fstream archivoVendedores;
			archivoVendedores.open("vendedor.csv", ios::in);
			if (archivoVendedores.is_open())
			{
				while (!archivoVendedores.eof())
				{
					while (getline(archivoVendedores, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{/*string::npos es -1, termina cuando llega a este punto*/
							temporal[i] = linea.substr(0, posi);/*posi = Es la cantidad de caracteres antes del ;*/
							linea.erase(0, posi + 1);//borra la palabra de la primera posición encontrada   y con el +1 incluye hasta el ; y luego borra ese elemento, para que en la siguiente iteracion iniciar con la siguiente palabra y de ese modo seguir el proceso , 
							i++;
						}
						//Asignando los valores al vector
						Vendedor vendedor;
						vendedor.setcodigo(std::stoi(temporal[0]));
						vendedor.setusuario(std::stoi(temporal[1]));
						vendedor.setcontra(temporal[2]);
						agregar(vendedor);
					}
				}
			}
			archivoVendedores.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoVendedores;
			archivoVendedores.open("vendedor.csv", ios::out);
			if (archivoVendedores.is_open())
			{
				for (Vendedor x : vectorVendedor)
				{
					archivoVendedores << x.getcodigo() << ";" << x.getusuario() << ";" << x.getcontrasena() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}

};