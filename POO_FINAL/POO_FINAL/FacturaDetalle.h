#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class FacturaDetalle
{
private:
    int codFactura;
    int codProducto;
    int cantidad;
    float precioVenta;
    float importe;
public:
    FacturaDetalle() {
    }

    void setcodFactura(int codf) {
        codFactura = codf;
    }
    void setcodProducto(int codp) {
        codProducto = codp;
    }
    void setcantidad(int cant) {
        cantidad = cant;
    }
    void setprecioVenta(float precioV) {
        precioVenta = precioV;
    }
    void setimporte(float impor) {
        importe = impor;
    }

    int getcodFactura() {
        return codFactura;
    }
    int getcodProducto() {
        return codProducto;
    }
    int getcantidad() {
        return cantidad;
    }
    float getprecioVenta() {
        return precioVenta;
    }
    float getimporte() {
        return importe;
    }

};