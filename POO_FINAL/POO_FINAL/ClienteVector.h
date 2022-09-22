#pragma once
#include<iostream>
#include<vector>
#include<fstream>       
#include"Cliente.h"
using namespace std;
using std::stoi;
class ClienteVector {
private:
	vector<Cliente> vectorCliente;

public:
	ClienteVector() {
		cargarDatosDelArchivoAlVector();
		vector<Cliente> vectorCliente;
	}

	void agregar(Cliente obj) {
		vectorCliente.push_back(obj);
	}

	int getCorrelativo()
	{
		if (vectorCliente.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorCliente[vectorCliente.size() - 1].getcodigo() + 1;
		}
	}

	Cliente buscarPorCodigo(int codigo)
	{
		Cliente objError;
		objError.setdni(0);
		objError.setruc(0);
		objError.setcodigo(0);

		for (Cliente x : vectorCliente)
		{
			if (codigo == x.getcodigo())
			{
				return x;
			}
		}
		return objError;
	}

	Cliente get(int pos)
	{
		return vectorCliente[pos];
	}

	int rows()
	{
		return vectorCliente.size();
	}

	int getPostArray(Cliente obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getcodigo() == get(i).getcodigo())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(Cliente obj)
	{
		vectorCliente.erase(vectorCliente.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Cliente cliente)
	{
		try
		{
			fstream archivoCliente;
			archivoCliente.open("cliente.csv", ios::app);
			if (archivoCliente.is_open())
			{
				archivoCliente << cliente.getcodigo() << ";" << cliente.getnomape() << ";" << cliente.getdni() << ";" << cliente.getruc() << ";" << cliente.getdirec() << ";" << endl;
				archivoCliente.close();
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
			string temporal[5];//Cantidad de columnas
			fstream archivoCliente;
			archivoCliente.open("cliente.csv", ios::in);
			if (archivoCliente.is_open())
			{
				while (!archivoCliente.eof())
				{
					while (getline(archivoCliente, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						//Asignando los valores al vector
						Cliente cliente;
						cliente.setcodigo(std::stoi(temporal[0]));
						cliente.setnomape(temporal[1]);
						cliente.setdni(std::stoi(temporal[2]));
						cliente.setruc(std::stoi(temporal[3]));
						cliente.setdirec(temporal[4]);
						agregar(cliente);
					}
				}
			}
			archivoCliente.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoCliente;
			archivoCliente.open("cliente.csv", ios::out);
			if (archivoCliente.is_open())
			{
				for (Cliente x : vectorCliente)
				{
					archivoCliente << x.getcodigo() << ";" << x.getnomape() << ";" << x.getdni() << ";" << x.getruc() << ";" << x.getdirec() << ";"  << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}
};
