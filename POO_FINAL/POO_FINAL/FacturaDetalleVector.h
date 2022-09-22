#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"FacturaDetalle.h"
#include<stdlib.h>
using namespace std;
using std::stoi;
class FacturaDetalleVector
{
private:
	vector<FacturaDetalle> vectorFacturaDetalle;

public:
	FacturaDetalleVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<FacturaDetalle> vectorFacturaDetalle;
	}

	int getCorrelativo()
	{
		if (vectorFacturaDetalle.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorFacturaDetalle[vectorFacturaDetalle.size() - 1].getcodFactura() + 1;
		}
	}

	FacturaDetalle get(int pos)
	{
		return vectorFacturaDetalle[pos];
	}

	int rows()
	{
		return vectorFacturaDetalle.size();
	}

	void agregar(FacturaDetalle obj)
	{
		vectorFacturaDetalle.push_back(obj);
	}

	FacturaDetalle buscarPorCodigo(int codigo)
	{
		FacturaDetalle objError;
		objError.setcodFactura(0);

		for (FacturaDetalle x : vectorFacturaDetalle)
		{
			if (codigo == x.getcodFactura())
			{
				return x;
			}
		}
	}

	int getPostArray(FacturaDetalle obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getcodFactura() == get(i).getcodFactura())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(FacturaDetalle obj)
	{
		vectorFacturaDetalle.erase(vectorFacturaDetalle.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(FacturaDetalle facturadetalle)
	{
		try
		{
			fstream archivoFacturaDetalle;
			archivoFacturaDetalle.open("facturadetalles.csv", ios::app);
			if (archivoFacturaDetalle.is_open())
			{
				archivoFacturaDetalle << facturadetalle.getcodFactura() << ";" << facturadetalle.getcodProducto() << ";" << facturadetalle.getcantidad() << ";" << facturadetalle.getprecioVenta() << ";" << facturadetalle.getimporte() << ";" << endl;
				archivoFacturaDetalle.close();
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
			string temporal[6];//Cantidad de columnas
			fstream archivoFacturaDetalle;
			archivoFacturaDetalle.open("facturadetalles.csv", ios::in);
			if (archivoFacturaDetalle.is_open())
			{
				while (!archivoFacturaDetalle.eof())
				{
					while (getline(archivoFacturaDetalle, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						//Asignando los valores al vector
						FacturaDetalle facturadetalle1;
						facturadetalle1.setcodFactura(std::stoi(temporal[0]));
						facturadetalle1.setcodProducto(std::stoi(temporal[1]));
						facturadetalle1.setcantidad(std::stoi(temporal[2]));
						facturadetalle1.setprecioVenta(std::stof(temporal[3]));
						facturadetalle1.setimporte(std::stof(temporal[4]));
						agregar(facturadetalle1);
					}
				}
			}
			archivoFacturaDetalle.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoFacturaDetalle;
			archivoFacturaDetalle.open("facturadetalles.csv", ios::out);
			if (archivoFacturaDetalle.is_open())
			{
				for (FacturaDetalle x : vectorFacturaDetalle)
				{
					archivoFacturaDetalle << x.getcodFactura() << ";" << x.getcodProducto() << ";" << x.getcantidad() << ";" << x.getprecioVenta() << ";" << x.getimporte() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}
};