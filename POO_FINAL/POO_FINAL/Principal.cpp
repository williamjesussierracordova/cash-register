#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<stdlib.h>
#include <conio.h>
#include"ClienteVector.h"
#include"ProductoVector.h"
#include"VendedorVector.h"
#include"FacturaDetalleVector.h"
#include"FacturaVector.h"
VendedorVector vendedorVector;
ClienteVector clienteVector;
ProductoVector productoVector;
FacturaDetalleVector facturadetalleVector;
FacturaVector facturaVector;

using namespace std;

int usr;

void InterfazPrincipal();
void Interfaz1();
void Interfaz2(int& usr);
void Interfaz3();
void Interfaz4();
void Interfaz5();
void SistemaGeneral();
void SistemaProducto();
void SistemaVentas();
void SistemaCliente();
void ModificarProductos();
void Sistema2(int usr);
void Sistema3();
void Sistema4();
void Sistema5();
void Sistema6();
void Busqueda_tipo();
void busqueda1();
void busqueda2();
void busqueda3();
void busqueda4();
void busqueda5();
void Cliente1();
void Cliente2();
void Cliente3();
void Cliente4();
void Ventas1();
void Ventas3();
void ModificarEstado();
void Ordenamiento_Precio();

int main() {
	InterfazPrincipal();
}

void InterfazPrincipal()
{
	int opc;

	cout << "     ¡BIENVENIDO AL SISTEMA!" << endl;
	cout << " [1] Vendedor" << endl;
	cout << " [2] Cliente" << endl;
	cout << " [3] Salir" << endl;
	cout << " \n";
	cout << " Ingrese una opcion(1-3): "; cin >> opc;

	switch (opc)
	{
	case 1: system("cls"); Interfaz1();
	case 2: system("cls"); Busqueda_tipo();
	case 3: cout << endl << "******Gracias por su visita******" << endl;
		break;
	}
}


void Interfaz1()
{
	int opcion = 0;

	cout << " 		BIENVENIDO			" << endl;
	cout << "[1]  Ingresar a la plataforma" << endl;
	cout << "[2]  Agregar un nuevo usuario" << endl;
	cout << "[3]  Eliminar un usuario existente" << endl;
	cout << "[4]  Listar los usuarios" << endl;
	cout << "[5]  Salir" << endl;
	cout << endl;
	cout << "Ingrese una de las opciones: ";
	cin >> opcion;

	switch (opcion) {
	case 1:system("cls"); Interfaz2(usr);
		break;
	case 2:system("cls"); Interfaz3();
		break;
	case 3:system("cls"); Interfaz4();
		break;
	case 4:system("cls"); Interfaz5();
	case 5:system("cls"); InterfazPrincipal();
		break;
	}
}

void Interfaz2(int& usr)
{
	int user;
	string password;

	cout << " 		BIENVENIDO			" << endl;

	cout << "Ingrese su usuario: ";
	cin >> user;

	cout << "Ingrese su clave: ";

	char caracter;
	caracter = _getch();
	password = "";

	while (caracter != 13) // Enter en ASCII
	{
		if (caracter != 8) // Backspace en ASCII
		{
			password.push_back(caracter);
			cout << "*";
		}
		else {
			if (password.length() > 0) {
				cout << "\b \b";
				password.pop_back(); // Borra el último caracter
			}

		}
		caracter = _getch();
	}

	Vendedor vende = vendedorVector.buscarPorUsuario(user);

	if (password == vende.getcontrasena())
	{
		cout << " " << endl;
		cout << "\n¡Bienvenido a esta plataforma!" << endl;
		usr = user;
		system("pause");
		system("cls");
		SistemaGeneral();
	}
	else
	{
		cout << "El usuario y/o password no son correctos" << endl;
		system("pause");
		Interfaz1();
	}
}

void Interfaz3()
{
	int user;
	int cod;
	string password;

	cout << "			Creacion de un nuevo usuario		" << endl;

	cod = vendedorVector.getCorrelativo();
	cout << " CODIGO ID --> " << cod << endl;

	cout << "Ingresa tu numero de usuario: ";
	cin >> user;
	cout << endl;

	cout << "Ingresa una clave(numeros y letras): ";
	cin.ignore();
	//getline(cin, password);

	char caracter;
	caracter = _getch();
	password = "";

	while (caracter != 13) // Enter en ASCII
	{
		if (caracter != 8) // Backspace en ASCII
		{
			password.push_back(caracter);
			cout << "*";
		}
		else {
			if (password.length() > 0) {
				cout << "\b \b";
				password.pop_back(); // Borra el último caracter
			}

		}
		caracter = _getch();
	}

	Vendedor vendedor1;
	vendedor1.setcodigo(cod);
	vendedor1.setusuario(user);
	vendedor1.setcontra(password);

	vendedorVector.agregar(vendedor1);
	vendedorVector.grabarEnArchivo(vendedor1);

	system("cls");
	Interfaz1();
}
void Interfaz4()
{
	int user;
	string rpta;

	cout << "			Eliminar usuario		" << endl;
	cout << " Numero del usuario a eliminar: ";
	cin >> user;

	Vendedor objeliminar = vendedorVector.buscarPorUsuario(user);

	if (objeliminar.getusuario() != 0)
	{
		vendedorVector.remove(objeliminar);
		vendedorVector.grabarModificarEliminarArchivo();
		cout << "¡Registro Eliminado Satisfactoriamente!" << endl;
	}
	else
	{
		cout << " No se encontro el registro!\n" << endl;
	}
	system("pause");
	system("cls");
	Interfaz1();
}

void Interfaz5()
{
	for (int i = 0; i < vendedorVector.rows(); i++)
	{
		cout << vendedorVector.get(i).getcodigo() << "-" << vendedorVector.get(i).getusuario() << "-" << vendedorVector.get(i).getcontrasena() << "\n";
	}
	system("pause");
	system("cls");
	Interfaz1();
}

void SistemaGeneral()
{
	int opc;
	cout << "   SISTEMA GENERAL" << endl;
	cout << "[1]  Productos" << endl;
	cout << "[2]  Ventas" << endl;
	cout << "[3]  Clientes" << endl;
	cout << "[4]  Salir" << endl;
	cout << " \n";
	cout << " Ingrese una opcion: ";	cin >> opc;
	switch (opc) {
	case 1:system("cls"); SistemaProducto(); break;
	case 2:system("cls"); SistemaVentas(); break;
	case 3:system("cls"); SistemaCliente(); break;
	case 4:system("cls"); InterfazPrincipal(); break;
	}
}
void SistemaProducto() {
	int opc;
	cout << "   SISTEMA DE PRODUCTOS" << endl;
	cout << " [1] Ingresar un nuevo producto" << endl;
	cout << " [2] Modificar producto" << endl;
	cout << " [3] Eliminar producto" << endl;
	cout << " [4] Buscar producto" << endl;
	cout << " [5] Listar productos" << endl;
	cout << " [6] Salir" << endl;
	cout << " \n";
	cout << " Ingrese una opcion: ";	cin >> opc;

	switch (opc) {
	case 1:system("cls"); Sistema3(); break;
	case 2:system("cls"); ModificarProductos(); break;
	case 3:system("cls"); Sistema4(); break;
	case 4:system("cls"); Sistema5(); break;
	case 5:system("cls"); Sistema6(); break;
	case 6:system("cls"); SistemaGeneral(); break;
	}
}

void SistemaVentas() {
	int opciones;
	cout << "			SISTEMA DE VENTAS 		" << endl;
	cout << "[1]  Realizar una venta " << endl;
	cout << "[2]  Buscar factura/boleta por codigo" << endl;
	cout << "[3]  Modificar estado de venta" << endl;
	cout << "[4]  Listar facturas/boletas emitadas" << endl;
	cout << "[5]  Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> opciones;
	switch (opciones) {
	case 1:system("cls"); Sistema2(usr); break;
	case 2:system("cls"); Ventas1(); break;
	case 3:system("cls"); ModificarEstado(); break;
	case 4:system("cls"); Ventas3(); break;
	case 5:system("cls"); SistemaGeneral(); break;
	}
}

void ModificarProductos()
{
	cout << "		MODIFICAR PRECIO - PRODUCTO" << endl;
	int cod;
	cout << "Ingresar el codigo del producto a modificar:";
	cin >> cod;
	cout << " " << endl;

	Producto objAModificar = productoVector.buscarPorCodigo(cod);

	cout << "Registro Encontrado\n";
	cout << "Codigo: " << objAModificar.getCodigo() << endl;
	cout << "Nombre: " << objAModificar.getNombre() << endl;
	cout << "Marca: " << objAModificar.getMarca() << endl;
	cout << "Tipo: " << objAModificar.getTipo() << endl;
	cout << "SubTipo: " << objAModificar.getSubtipo() << endl;
	cout << "Precio: S/." << objAModificar.getPrecio() << endl;
	cin.ignore();
	cout << " " << endl;

	float preModificado;
	cout << "    MODIFICAR CAMPOS" << endl;
	cout << "Precio a modificar: S/.";
	cin >> preModificado;

	bool estado = productoVector.modificarPrecio(objAModificar, preModificado);
	if (estado = true)
	{
		cout << "Registro Modificado Correctamente\n";
		productoVector.grabarModificarEliminarArchivo();
		cout << " " << endl;
		system("cls");
		SistemaProducto();
	}
	else {
		cout << "No se Edito el registro!\n";
		system("pause");
		SistemaProducto();
	}
}

void Sistema2(int usr) {
	int cod, cant, codvendedor;
	float precio, acumulador = 0, igva, igv, subtotal, total;
	int codc;
	string rpta, fecha;
	string estado = "completado";
	string tipodeventa;

	int codfactura = facturadetalleVector.getCorrelativo();

	cout << "			VENTA			" << endl;

	cout << "FECHA: ";
	cin >> fecha; cout << endl;

	cout << "Usuario_Cajero: " << usr << endl << endl;

	Vendedor vendedor1 = vendedorVector.buscarPorUsuario(usr);
	codvendedor = vendedor1.getcodigo();

	cout << "Ingrese Codigo_Cliente: ";
	cin >> codc; cout << endl;

	Cliente cliente1 = clienteVector.buscarPorCodigo(codc);

	if (cliente1.getdni() == 0 && cliente1.getruc() == 0) {
		cout << "No existe algun cliente con el codigo ingresado. Crear cliente o vuelva a intentarlo"<<endl<<endl;
		system("pause");
		system("cls");
		SistemaVentas();
	}
	else if (cliente1.getdni()==0) {
		tipodeventa = "factura";
	}
	else {
		tipodeventa = "boleta";
	}

	cout << "Ingrese IGV_Venta(%): ";
	cin >> igva; cout << endl;

	cout << "Codigo_Factura: " << codfactura << endl << endl;

	do {
		cout << "Codigo_Producto: ";
		cin >> cod; cout << endl;

		Producto producto1 = productoVector.buscarPorCodigo(cod);

		if (producto1.getCodigo() == cod) {

			precio = producto1.getPrecio();

			cout << "Nombre	  Marca	   Tipo	  Precio Unitario" << endl;
			cout << producto1.getNombre() << " " << producto1.getMarca() << " " << producto1.getTipo() << " " << producto1.getPrecio() << endl << endl;
			//cout << "Precio_Producto:" << precio << endl << endl;//

			cout << "Cantidad(unidades): ";
			cin >> cant; cout << endl;

			cout << "SubTotal:" << precio * cant << endl << endl;

			acumulador += precio * cant;

			FacturaDetalle facturadetalle1;
			facturadetalle1.setcodFactura(codfactura);
			facturadetalle1.setcodProducto(cod);
			facturadetalle1.setcantidad(cant);
			facturadetalle1.setprecioVenta(precio);
			facturadetalle1.setimporte(precio * cant);

			facturadetalleVector.agregar(facturadetalle1);
			facturadetalleVector.grabarEnArchivo(facturadetalle1);

			cout << "Seguir comprando (si o no):";
			cin >> rpta; cout << endl;
		}
		else {
			cout << "No se encontró registro del producto" << endl;
			cout << "Seguir comprando (si o no):";
			cin >> rpta; cout << endl;
		}
	} while (rpta == "si");

	igv = (igva / 100) * acumulador;
	subtotal = acumulador - igv;
	total = acumulador;

	Factura factura1;
	factura1.setcodigo(codfactura);
	factura1.setfecha(fecha);
	factura1.setsubtotal(subtotal);
	factura1.setigvfactura(igva);
	factura1.setigv(igv);
	factura1.settotal(total);
	factura1.setestado(estado);
	factura1.setcodCliente(codc);
	factura1.setcodVendedor(codvendedor);
	factura1.settipoVenta(tipodeventa);

	facturaVector.agregar(factura1);
	facturaVector.grabarEnArchivo(factura1);

	system("pause");
	system("cls");
	
	cout << "    DETALLES DE LA VENTA" << endl << endl;

	cout << "Productos adquiridos: " << endl;

	for (int i = 0; i < facturadetalleVector.rows(); i++) {

		if (facturadetalleVector.get(i).getcodFactura() == codfactura) {

			int codpr=facturadetalleVector.get(i).getcodProducto();

			Producto prodt = productoVector.buscarPorCodigo(codpr);

			cout << "El producto es: " << prodt.getNombre()<<endl;
			cout<<"La cantidad adquirida es:"<<facturadetalleVector.get(i).getcantidad()<<endl;
			cout << "El precio unitario del producto es: " << facturadetalleVector.get(i).getprecioVenta() << endl;
			cout << "El subtotal por este producto es: " << facturadetalleVector.get(i).getimporte() << endl;
			cout << endl;
		}
		else {
		}
		
	}

	cout << "SubTotal: " << factura1.getsubtotal() << endl;
	cout << "IGV: " << factura1.getigv() << endl;
	cout << "Total_Pagar: " << factura1.gettotal() << endl;

	system("pause");
	system("cls");
	SistemaVentas();
}

void Ventas1() {
	int cod;

	cout << "    BUSCAR FACTURA/BOLETA" << endl;
	cout << "Ingresar codigo de la factura/boleta: ";
	cin >> cod; cout << endl;

	Factura facturav = facturaVector.buscarPorCodigo(cod);

	if (facturav.getcodigo() == cod) {

		cout << "    DETALLES DE LA VENTA" << endl;
		cout << "Codigo de Factura/Boleta:     " << facturav.getcodigo() << endl;
		cout << "PRODUCTOS ADQUIRIDOS:" << endl;

		for (int i = 0; i < facturadetalleVector.rows(); i++) {
			if (facturadetalleVector.get(i).getcodFactura() == cod) {

				int codpr = facturadetalleVector.get(i).getcodProducto();

				Producto prodt = productoVector.buscarPorCodigo(codpr);

				cout << endl << "El producto es: " << prodt.getNombre() << endl;
				cout << "La cantidad adquirida es:" << facturadetalleVector.get(i).getcantidad() << endl;
				cout << "El precio unitario del producto es: " << facturadetalleVector.get(i).getprecioVenta() << endl;
				cout << "El subtotal por este producto es: " << facturadetalleVector.get(i).getimporte() << endl;
				cout << endl;
			}
			else {
			}
		}

		cout <<endl<< "Codigo_Vendedor:              " << facturav.getcodVendedor() << endl;
		cout << "Codigo_Cliente:               " << facturav.getcodCliente() << endl;
		cout << "Fecha_Venta:                  " << facturav.getfecha() << endl;
		cout << "Tipo de venta:                " << facturav.gettipoVenta() << endl;
		cout << "Estado de venta:              " << facturav.getestado() << endl;
		cout << "IGV Factura(porcentaje):      " << facturav.getigvFactura() << endl << endl;
		cout << "Subtotal:                     " << facturav.getsubtotal() << endl;
		cout << "IGV Venta:                    " << facturav.getigv() << endl;
		cout << "Total a pagar:                " << facturav.gettotal() << endl;
	}
	else {
		cout << "No tenemos registrada una factura/boleta con el codigo ingresado" << endl;
	}
	system("pause");
	system("cls");
	SistemaVentas();
}

void ModificarEstado()
{
	cout << "			MODIFICAR ESTADO " << endl;
	int cod;
	cout << "Codigo de Factura a modificar:";
	cin >> cod;
	cout << " " << endl;

	Factura objFacAModificar = facturaVector.buscarPorCodigo(cod);

	cout << "Factura encontrada\n";
	cout << "Codigo_Factura: " << objFacAModificar.getcodigo() << endl;
	cout << "Fecha: " << objFacAModificar.getfecha() << endl;
	cout << "SubTotal: " << objFacAModificar.getsubtotal() << endl;
	cout << "IGV_Factura: " << objFacAModificar.getigvFactura() << endl;
	cout << "IGV: " << objFacAModificar.getigv() << endl;
	cout << "Total_Pagar: " << objFacAModificar.gettotal() << endl;
	cout << "Estado: " << objFacAModificar.getestado() << endl;
	cout << "Codigo_Cliente: " << objFacAModificar.getcodCliente() << endl;
	cout << "Codigo_Vendedor: " << objFacAModificar.getcodVendedor() << endl;
	cout << "Tipo_Comprobante: " << objFacAModificar.gettipoVenta() << endl;

	cin.ignore();
	cout << " " << endl;

	string estadoModificado;
	cout << "     MODIFICAR ESTADO DE FACTURA" << endl;
	cout << "Estado: "; getline(cin, estadoModificado);

	bool estado = facturaVector.modificarEstado(objFacAModificar, estadoModificado);

	if (estado = true)
	{
		cout << "Registro Modificado Correctamente\n";
		facturaVector.grabarModificarEliminarArchivo();
		system("pause");
		system("cls");
		SistemaVentas();
	}
}


void Ventas3() {
	cout << "    FACTURAS/BOLETAS EMITIDAS" << endl;
	for (int i = 0; i < facturaVector.rows(); i++) {
		cout << "Codigo de la factura/boleta:	" << facturaVector.get(i).getcodigo() << endl;
		cout << "Codigo del vendedor:		" << facturaVector.get(i).getcodVendedor() << endl;
		cout << "Codigo del cliente:		" << facturaVector.get(i).getcodCliente() << endl;
		cout << "Fecha de la venta:		" << facturaVector.get(i).getfecha() << endl;
		cout << "Tipo de venta:			" << facturaVector.get(i).gettipoVenta() << endl;
		cout << "Estado de la venta:	        " << facturaVector.get(i).getestado() << endl;
		cout << "Igv(%) cobrado en esta venta:   " << facturaVector.get(i).getigvFactura() << endl << endl;
		cout << "Subtotal de la venta:	        " << facturaVector.get(i).getsubtotal() << endl;
		cout << "Igv de la venta:		" << facturaVector.get(i).getigv() << endl;
		cout << "Total de la venta:		" << facturaVector.get(i).gettotal() << endl << endl;

		cout << "*************************************************" << endl << endl;
	}
	system("pause");
	system("cls");
	SistemaVentas();
}

void Sistema3() {
	int cod;
	string nombre, marca, tipo, subtipo;
	float price;

	cod = productoVector.getCorrelativo();
	cout << "			AGREGAR PRODUCTO" << endl;
	cout << "Codigo: " << cod << endl;

	cout << "Nombre del producto: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "Marca del producto: ";
	cin.ignore();
	getline(cin, marca);

	cout << "Tipo de producto: ";
	cin.ignore();
	getline(cin, tipo);

	cout << "Subtipo del producto: ";
	cin.ignore();
	getline(cin, subtipo);

	cout << "Precio del producto: ";
	cin >> price;
	cout << endl;

	Producto producto1;
	producto1.setCodigo(cod);
	producto1.setNombre(nombre);
	producto1.setMarca(marca);
	producto1.setTipo(tipo);
	producto1.setSubtipo(subtipo);
	producto1.setPrecio(price);

	productoVector.agregar(producto1);
	productoVector.grabarEnArchivo(producto1);

	system("cls");

	SistemaGeneral();
}

void Sistema4()
{
	int cod;
	cout << "Codigo de producto a eliminar:";
	cin >> cod;
	Producto objAEliminar = productoVector.buscarPorCodigo(cod);
	if (objAEliminar.getCodigo() != 0)
	{
		productoVector.remove(objAEliminar);
		productoVector.grabarModificarEliminarArchivo();
		cout << "Registro Eliminado Satisfactoriamente" << endl;
		
	}
	else {
		cout << "El codigo del producto ingresado no existe." << endl;
	}
	system("pause");
	system("cls");
	SistemaProducto();
}

void Sistema5() {
	int code = 0;

	cout << "			BUSCAR POR CODIGO" << endl;
	cout << "Codigo: ";
	cin >> code;
	cout << endl;

	Producto objproducto = productoVector.buscarPorCodigo(code);

	if (code == objproducto.getCodigo()) {
		cout << "Nombre: " << objproducto.getNombre() << endl;
		cout << "Marca: " << objproducto.getMarca() << endl;
		cout << "Tipo: " << objproducto.getTipo() << endl;
		cout << "Subtipo: " << objproducto.getSubtipo() << endl;
		cout << "Precio: S/." << objproducto.getPrecio() << endl;
		system("pause");
		system("cls");
		SistemaProducto();
	}
	else {
		cout << "No existe un producto con el codigo ingresado" << endl;
		system("pause");
		system("cls");
		SistemaProducto();
	}
}

void Sistema6()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << "\n";
	}
	system("pause");
	system("cls");
	SistemaProducto();
}

void Busqueda_tipo()
{
	int opcion;
	cout << "			Busqueda por tipo de productos" << endl;
	cout << "[1]   electro" << endl;
	cout << "[2]   perecibles" << endl;
	cout << "[3]   bebidas" << endl;
	cout << "[4]   vestimenta" << endl;
	cout << "[5]   otros" << endl;
	cout << "[6]   salir" << endl;
	cout << "Ingrese una opcion valida (1-5): ";
	cin >> opcion;

	switch (opcion)
	{
	case 1:system("cls"); busqueda1(); break;
	case 2:system("cls"); busqueda2(); break;
	case 3:system("cls"); busqueda3(); break;
	case 4:system("cls"); busqueda4(); break;
	case 5:system("cls"); busqueda5(); break;
	case 6:system("cls"); InterfazPrincipal(); break;
	}

}

void busqueda1()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "electro")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda2()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "perecibles")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda3()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "bebidas")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda4()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "vestimenta")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void busqueda5()
{
	for (int i = 0; i < productoVector.rows(); i++)
	{
		if (productoVector.get(i).getTipo() == "otros")
		{
			cout << productoVector.get(i).getCodigo() << "-" << productoVector.get(i).getNombre() << "-" << productoVector.get(i).getMarca() << "-" << productoVector.get(i).getTipo() << "-" << productoVector.get(i).getSubtipo() << "-" << productoVector.get(i).getPrecio() << endl;
		}
	}
	system("pause");
	system("cls");
	Busqueda_tipo();
}

void SistemaCliente()
{
	int opt;
	cout << "    Interfaz Cliente" << endl;
	cout << "[1]  Buscar cliente" << endl;
	cout << "[2]  Crear un nuevo cliente" << endl;
	cout << "[3]  Eliminar cliente" << endl;
	cout << "[4]  Listar clientes" << endl;
	cout << "[5]  Salir" << endl;
	cout << "Ingrese la opcion que desee: ";
	cin >> opt;

	switch (opt)
	{
	case 1:system("cls"); Cliente1(); break;
	case 2:system("cls"); Cliente2(); break;
	case 3:system("cls"); Cliente3(); break;
	case 4:system("cls"); Cliente4(); break;
	case 5:system("cls"); SistemaGeneral(); break;
	}
}

void Cliente1()
{
	int cod = 0;
	cout << "    Buscar Cliente" << endl;
	cout << "Ingrese el codigo del cliente: ";
	cin >> cod;
	cout << endl;

	Cliente clientes1 = clienteVector.buscarPorCodigo(cod);

	if (clientes1.getcodigo() == cod)
	{
		cout << "Codigo: " << clientes1.getcodigo() << endl;
		cout << "Nombre y apellidos: " << clientes1.getnomape() << endl;
		cout << "Dni: " << clientes1.getdni() << endl;
		cout << "Ruc: " << clientes1.getruc() << endl;
		cout << "Direccion: " << clientes1.getdirec() << endl;

		system("pause");
		system("cls");
		SistemaCliente();
	}
	else
	{
		cout << "No se encontro un cliente registrado con el codigo ingresado"<<endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}

}

void Cliente2()
{
	int cod, ni, ru;
	string rp, nape, dir;

	Cliente cliente1;

	cout << "			Creacion de un nuevo cliente			" << endl;

	cod = clienteVector.getCorrelativo();

	cout << "El codigo del cliente es: " << cod << endl<<endl;

	cout << "Nombres y Apellidos del cliente: ";
	cin.ignore();
	getline(cin, nape);
	cout << endl;

	cout << "Ingrese que documento ingresara DNI o RUC: ";
	cin >> rp;
	cout << endl;

	if (rp == "DNI") {
		cout << "Ingrese el numero de DNI: ";
		cin >> ni;
		cout << endl;
		cliente1.setdni(ni);
		cliente1.setruc(00000000000);
	}
	else if (rp == "RUC") {
		cout << "Ingrese el RUC: ";
		cin >> ru; 
		cout << endl;
		cliente1.setruc(ru);
		cliente1.setdni(00000000);
	}
	else {
		cout << "Ingresar una opcion valida (DNI o RUC)." << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}

	cliente1.setcodigo(cod);
	cliente1.setnomape(nape);

	cout << "Ingrese su direccion: ";
	cin.ignore();
	getline(cin, dir);
	cliente1.setdirec(dir);

	clienteVector.agregar(cliente1);
	clienteVector.grabarEnArchivo(cliente1);

	system("pause");
	system("cls");
	SistemaCliente();
}

void Cliente3()
{
	int cod;

	cout << "    Eliminar cliente" << endl;
	cout << "Ingresar codigo del cliente: ";
	cin >> cod;
	cout << endl;

	Cliente objeliminar = clienteVector.buscarPorCodigo(cod);

	if (objeliminar.getcodigo() != 0)
	{
		clienteVector.remove(objeliminar);
		clienteVector.grabarModificarEliminarArchivo();
		cout << "¡Registro Eliminado Satisfactoriamente!" << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}
	else
	{
		cout << " No se encontro el registro!" << endl;
		system("pause");
		system("cls");
		SistemaCliente();
	}
}

void Cliente4()
{
	for (int i = 0; i < clienteVector.rows(); i++)
	{
		cout << clienteVector.get(i).getcodigo() << "-" << clienteVector.get(i).getnomape() << "-" << clienteVector.get(i).getdni() << "-" << clienteVector.get(i).getruc() << "-" << clienteVector.get(i).getdirec() << endl;
	}
	system("pause");
	system("cls");
	SistemaCliente();
}

void Ordenamiento_Precio()
{
	int p, j;
	float aux;
	float m, n;
	for (p = 1; p < productoVector.rows(); p++)
	{
		aux = productoVector.get(p).getPrecio();
		j = p - 1;

		while ((j >= 0) && (aux < productoVector.get(j).getPrecio())) {
			m = productoVector.get(j + 1).getPrecio();
			n = productoVector.get(j).getPrecio();
			m = n;
			j--;
		}
		m = aux;
	}
}