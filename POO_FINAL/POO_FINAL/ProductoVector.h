#include<iostream>
#include<vector>
#include<fstream>
#include"Producto.h"
#include<stdlib.h>
using namespace std;
using std::stoi;
class ProductoVector
{
private:
	vector<Producto> vectorProducto;

public:
	ProductoVector()
	{
		cargarDatosDelArchivoAlVector();
		vector<Producto> vectorProducto;
	}

	int getCorrelativo()
	{
		if (vectorProducto.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorProducto[vectorProducto.size() - 1].getCodigo() + 1;
		}
	}

	Producto get(int pos)
	{
		return vectorProducto[pos];
	}

	int rows()
	{
		return vectorProducto.size();
	}

	void agregar(Producto obj)
	{
		vectorProducto.push_back(obj);
	}

	bool modificarPrecio(Producto obj, float precio)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getCodigo() == get(i).getCodigo())
			{
				vectorProducto[i].setPrecio(precio);
				return true;
			}
		} return false;
	}

	Producto buscarPorCodigo(int codigo)
	{
		Producto objError;
		objError.setCodigo(0);

		for (Producto x : vectorProducto)
		{
			if (codigo == x.getCodigo())
			{
				return x;
			}
		}
		return objError;
	}

	int getPostArray(Producto obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.getNombre() == get(i).getNombre())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(Producto obj)
	{
		vectorProducto.erase(vectorProducto.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Producto producto)
	{
		try
		{
			fstream archivoProducto;
			archivoProducto.open("producto.csv", ios::app);
			if (archivoProducto.is_open())
			{
				archivoProducto << producto.getCodigo() << ";" << producto.getNombre() << ";" << producto.getMarca() << ";" << producto.getTipo() << ";" << producto.getSubtipo() << ";" << producto.getPrecio() << ";" << endl;
				archivoProducto.close();
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
			fstream archivoProducto;
			archivoProducto.open("producto.csv", ios::in);
			if (archivoProducto.is_open())
			{
				while (!archivoProducto.eof())
				{
					while (getline(archivoProducto, linea))
					{
						i = 0;
						while ((posi = linea.find(";")) != string::npos)
						{
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						//Asignando los valores al vector
						Producto producto1;
						producto1.setCodigo(std::stoi(temporal[0]));
						producto1.setNombre(temporal[1]);
						producto1.setMarca(temporal[2]);
						producto1.setTipo(temporal[3]);
						producto1.setSubtipo(temporal[4]);
						producto1.setPrecio(std::stof(temporal[5]));
						agregar(producto1);
					}
				}
			}
			archivoProducto.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}
	void grabarModificarEliminarArchivo()
	{
		try {
			fstream archivoProductos;
			archivoProductos.open("producto.csv", ios::out);
			if (archivoProductos.is_open())
			{
				for (Producto x : vectorProducto)
				{
					archivoProductos << x.getCodigo() << ";" << x.getNombre() << ";" << x.getMarca() << ";" << x.getTipo() << ";" << x.getSubtipo() << ";" << x.getPrecio() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}
};