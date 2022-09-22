#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"Factura.h"
#include<stdlib.h>
using namespace std;
using std::stoi;
class FacturaVector
{
private:
	vector<Factura> vectorFactura;

public:
	FacturaVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<Factura> vectorFactura;
	}

	int getCorrelativo()
	{
		if (vectorFactura.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorFactura[vectorFactura.size() - 1].getcodigo() + 1;
		}
	}

	Factura get(int pos)
	{
		return vectorFactura[pos];
	}

	int rows()
	{
		return vectorFactura.size();
	}

	void agregar(Factura obj)
	{
		vectorFactura.push_back(obj);
	}

	Factura buscarPorCodigo(int codigo)
	{
		Factura objError;
		objError.setcodigo(0);

		for (Factura x : vectorFactura)
		{
			if (codigo == x.getcodigo())
			{
				return x;
			}
		}
	}

	int getPostArray(Factura obj)
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

	void remove(Factura obj)
	{
		vectorFactura.erase(vectorFactura.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Factura factura1)
	{
		try
		{
			fstream archivoFactura;
			archivoFactura.open("factura.csv", ios::app);
			if (archivoFactura.is_open())
			{
				archivoFactura << factura1.getcodigo() << ";" << factura1.getfecha() << ";" << factura1.getsubtotal() << ";" << factura1.getigvFactura() << ";" << factura1.getigv() << ";" << factura1.gettotal() << ";" << factura1.getestado() << ";" << factura1.getcodCliente() << ";" << factura1.getcodVendedor() << ";" << factura1.gettipoVenta() << ";" << endl;
				archivoFactura.close();
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
			string temporal[10];//Cantidad de columnas
			fstream archivoFactura;
			archivoFactura.open("factura.csv", ios::in);
			if (archivoFactura.is_open())
			{
				while (!archivoFactura.eof())
				{
					while (getline(archivoFactura, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						//Asignando los valores al vector
						Factura factura1;
						factura1.setcodigo(std::stoi(temporal[0]));
						factura1.setfecha(temporal[1]);
						factura1.setsubtotal(std::stof(temporal[2]));
						factura1.setigvfactura(std::stof(temporal[3]));
						factura1.setigv(std::stof(temporal[4]));
						factura1.settotal(std::stof(temporal[5]));
						factura1.setestado(temporal[6]);
						factura1.setcodCliente(std::stoi(temporal[7]));
						factura1.setcodVendedor(std::stoi(temporal[8]));
						factura1.settipoVenta(temporal[9]);
						agregar(factura1);
					}
				}
			}
			archivoFactura.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoFactura;
			archivoFactura.open("factura.csv", ios::out);
			if (archivoFactura.is_open())
			{
				for (Factura x : vectorFactura)
				{
					archivoFactura << x.getcodigo() << ";" << x.getfecha() << ";" << x.getsubtotal() << ";" << x.getigvFactura() << ";" << x.getigv() << ";" << x.gettotal() << ";" << x.getestado() << ";" << x.getcodCliente() << ";" << x.getcodVendedor() << ";" << x.gettipoVenta() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}

	bool modificarEstado(Factura obj, string est)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getcodigo() == get(i).getcodigo())
			{
				vectorFactura[i].setestado(est);
				return true;
			}
		}
	}

	void modificarestado()
	{
		try {
			fstream archivoFactura;
			archivoFactura.open("factura.csv", ios::trunc);
			if (archivoFactura.is_open())
			{
				for (Factura x : vectorFactura) {
					archivoFactura << x.getcodigo() << ";" << x.getfecha() << ";" << x.getsubtotal() << ";" << x.getigvFactura() << ";" << x.getigv() << ";" << x.gettotal() << ";" << x.getestado() << ";" << x.getcodCliente() << ";" << x.getcodVendedor() << ";" << x.gettipoVenta() << ";" << "\n";
					archivoFactura.close();
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}

};