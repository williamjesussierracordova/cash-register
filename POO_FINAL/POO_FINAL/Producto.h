#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Producto
{
private:
    int    Codigo_producto;
    string Nombre_producto;
    string Marca_Producto;
    string Tipo_Producto;
    string Subtipo_Producto;
    float  Precio_producto;

public:
    Producto() {
    }
    //set
    void setCodigo(int Codigo)
    {
        Codigo_producto = Codigo;
    }
    void setNombre(string Nombre)
    {
        Nombre_producto = Nombre;
    }
    void setMarca(string Marca)
    {
        Marca_Producto = Marca;
    }
    void setTipo(string tipo)
    {
        Tipo_Producto = tipo;
    }
    void setSubtipo(string sub)
    {
        Subtipo_Producto = sub;
    }
    void setPrecio(float Precio)
    {
        Precio_producto = Precio;
    }

    //Get
    int getCodigo()
    {
        return Codigo_producto;
    }
    string getNombre()
    {
        return Nombre_producto;
    }
    string getMarca()
    {
        return Marca_Producto;
    }
    string getTipo()
    {
        return Tipo_Producto;
    }
    string getSubtipo()
    {
        return Subtipo_Producto;
    }
    float getPrecio()
    {
        return Precio_producto;
    }
};