#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Factura
{
private:
    int codigo;
    string fecha;
    float subtotal;
    float igvFactura;
    float igv;
    float total;
    string estado;
    int codCliente;
    int codVendedor;
    string tipoVenta;//boleta o factura

public:
    Factura() {
    }

    void setcodigo(int cod)
    {
        codigo = cod;
    }
    void setfecha(string fe)
    {
        fecha = fe;
    }
    void setsubtotal(float sub)
    {
        subtotal = sub;
    }
    void setigvfactura(float igvf)
    {
        igvFactura = igvf;
    }
    void setigv(float igb)
    {
        igv = igb;
    }
    void settotal(float tot)
    {
        total = tot;
    }
    void setestado(string status)
    {
        estado = status;
    }
    void setcodCliente(int codi)
    {
        codCliente = codi;
    }
    void setcodVendedor(int codiv)
    {
        codVendedor = codiv;
    }
    void settipoVenta(string type)
    {
        tipoVenta = type;
    }

    int getcodigo() {
        return codigo;
    }
    string getfecha() {
        return fecha;
    }
    float getsubtotal() {
        return subtotal;
    }
    float getigvFactura() {
        return igvFactura;
    }
    float getigv() {
        return igv;
    }
    float gettotal() {
        return total;
    }
    string getestado() {
        return estado;
    }
    int getcodCliente() {
        return codCliente;
    }
    int getcodVendedor() {
        return codVendedor;
    }
    string gettipoVenta() {
        return tipoVenta;
    }
};