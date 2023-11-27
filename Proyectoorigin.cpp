#include<iostream>
#include<vector>
#include<string>
using namespace std;

string nombreClienteActual = "";
int codigoClienteActual = 0;

struct Cliente 
{
	int     cdCliente;
    string	nomCliente;
	string	contrCliente;
};

struct Producto
{
	int		codProducto;
	string	nomProducto;
	float	preProducto;
	int		stkProducto;
};

struct  Vendedor
{
    int     numVendedor;
    string  nomVendedor;
};

vector<Cliente> vecCliente;
vector<Vendedor> vecVendedor;
vector<Producto> vecProducto;

void   sisCliente();
void   regCliente();
int    codCliente();
void   valCliente();

void   sisVendedor();
void   regVendedor();
void   menVendedor();


void    regProducto();
void    addProducto();
int     getProducto();
void    buscarProducto();
void    listarProducto();
void    modificarProducto();
int     posicionProducto(int);
void    eliminarProducto();
float   generarVenta();
void    venta();


int main()
{
	int opcion;
    do
    {
        cout << "\t\t\t-----------------------------\n";
		cout << "\t\t\tSISTEMA DE VENTAS DE VICTOYS \n";
        cout << "\t\t\t-----------------------------\n";
        cin.ignore();
		cout << "\tSistema de Clientes______________[1]\n";
        cout << "\tSistema de Vendedores____________[2]\n";
		cout << "\tSalir____________________________[3]\n";
        cout << "\tIngrese una opcion[1-3]: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1: system("cls"); 
                sisCliente(); 
                system("pause");
                system("cls"); 
                break;
        case 2: system("cls"); 
                sisVendedor(); 
                system("pause");
                system("cls"); 
                break;
        case 3: system("cls");
                cout << "\t\t\tGRACIAS POR SU VISITA\n";
                system("pause");
                system("cls"); 
                break;
        default: cout << "\tIngrese una opcion correcta[1-3]\n";
        }
    } while (opcion!=3);
    
    
}

void   sisCliente()
{
    int opcion;
    do
    {
        cout << "\t\t\tSISTEMA DE CLIENTE\n";
		cout << "\tRegistro _______________________________[1]\n";
        cout << "\tLogin___________________________________[2]\n";
        cout << "\tFinalizar Registro De Clientes__________[3]\n";
        cout << "\tIngrese una opcion[1-3]: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: system("cls"); 
                    regCliente(); 
                    system("pause");
                    system("cls"); 
			        break;
	        case 2: system("cls"); 
                    valCliente(); 
                    system("pause");
                    system("cls"); 
                    break;
            case 3: system("cls"); 
                    main(); 
                    system("pause");
                    system("cls"); 
                    break;
            default: cout << "Ingrese una opcion correcta[1-3]\n";
        }
    } while (opcion!=3);
    
}

void   regCliente()
{
	int cod;
    string usu;
    string contr;
    cout << "\t\t\tREGISTRO DE CLIENTES\n";
    cout << "\t\t\t---------------------\n";
    cin.ignore();
    cod = codCliente();
    cout << "\tCodigo:" << cod << endl;
    cout << "\tIngrese nombre de usuario: "; getline(cin, usu);
    cout << "\tIngrese contraseña: "; getline(cin, contr);

    Cliente cliente;
    cliente.cdCliente = cod;
    cliente.nomCliente = usu;
    cliente.contrCliente = contr;

    vecCliente.push_back(cliente);

    // Almacena el cliente actual
    nombreClienteActual = usu;
    codigoClienteActual = cod;

    cout << "\tCliente registrado exitosamente.\n";
    cin.ignore();
}

void   valCliente()
{
    string nombreUsuario, contraseñaUsuario;
    int codigoDeUsuario;
    int opcion;
    bool flag = false;
    cout << "\t\t\tACCESO AL SISTEMA\n";
    cout << "\t\t\t-----------------\n";
    cin.ignore();
    cout << "\tCodigo: ";
    cin >> codigoDeUsuario;
    cin.ignore();
    cout << "\tUsuario: ";
    getline(cin, nombreUsuario);

    cout << "\tContraseña: ";
    cin >> contraseñaUsuario;

    for (int i = 0; i < vecCliente.size(); i++)
    {
        if (codigoDeUsuario == vecCliente[i].cdCliente && nombreUsuario == vecCliente[i].nomCliente &&
            contraseñaUsuario == vecCliente[i].contrCliente)
        {
            flag = true;
            nombreClienteActual = nombreUsuario;
            codigoClienteActual = codigoDeUsuario;
            break;
        }
    }

    if (flag == true)
    {
        cout << "\tAcceso al sistema correcto\n";
		system("pause");
		system("cls");
        do
        {
            cout << "\t\t\tSISTEMA DE VENTAS\n";
            cout << "\tMenu de Productos______________[1]\n";;
            cout << "\tSalir__________________________[2]\n";
            cout << "\tIngrese una opcion[1-2]: ";
            cin >> opcion;
            switch (opcion)
            {
            case 1: system("cls"); 
					regProducto(); 
					system("pause");
					system("cls"); 
					break;
            case 2: system("cls"); 
					sisCliente(); 
					system("pause");
					system("cls"); 
					break;
            default:cout << "Ingrese una opcion correcta[1-2]\n";
            }

        } while (opcion!=2);
        
    }
    else
    {
        cout << "Acceso denegado, usuario o contraseña incorrecta\n";
    }
}

int codCliente()
{
	if (vecCliente.size() == 0)
	{
		return 1;
	}
	else
	{
		return vecCliente[vecCliente.size()-1].cdCliente + 1;
	}
}

void  sisVendedor()
{
     int opcion;
    do
    {
        cout << "\t\t\tSISTEMA DEL CAJERO \n";
		cout << "\tRegistro De Personal ____________[1]\n";
        cout << "\tIniciar Operacion _______________[2]\n";
        cout << "\tFinalizar Operacion______________[3]\n";
        cout << "\tIngrese una opcion[1-3]: ";
        cin >> opcion;
        switch (opcion)
        {
            case 1: system("cls"); 
                    regVendedor(); 
                    system("pause");
                    system("cls"); 
			        break;
	        case 2: system("cls"); 
                    menVendedor(); 
                    system("pause");
                    system("cls"); 
                    break;
            case 3: system("cls"); 
                    main(); 
                    system("pause");
                    system("cls"); 
                    break;
            default: cout << "Ingrese una opcion correcta[1-3]\n";
        }
    } while (opcion!=3);
}

void   regVendedor()
{
	int cod;
    string usu;
    cout << "\t\t\tREGISTRO DE CAJA\n";
    cout << "\t\t\t---------------------\n";
    cin.ignore();
    cout << "\tNumero de Caja: "; cin >> cod;
    cin.ignore();
    cout << "\tIngrese nombre del cajero: "; getline (cin , usu);

    Vendedor vendedor;
    vendedor.numVendedor = cod;
    vendedor.nomVendedor = usu;

    vecVendedor.push_back(vendedor);

    cout << "\tCajero(a) registrado exitosamente.\n";
    cin.ignore();
}

void   menVendedor()
{
    string nombreCajero ;
	int codigoDeUsuario;
    int opcion;
	bool flag = false;
    bool ventaValida = false;
	cout << "\t\t\tACCESO AL SISTEMA\n";
    cout << "\t\t\t-----------------\n";
    cin.ignore();
	cout << "\tNumero De Caja: ";
	cin >> codigoDeUsuario;
    cin.ignore();
    cout << "\tUsuario: ";
	getline (cin , nombreCajero);
    

    for (int i = 0; i < vecVendedor.size(); i++)
	{
		if ( codigoDeUsuario == vecVendedor[i].numVendedor && nombreCajero == vecVendedor[i].nomVendedor )
		{
			flag = true;
			break;
		}
	}
    if (flag == true)
    {
        cout << "\tAcceso al sistema correcto\n";
		system("pause");
		system("cls");
        do
        {
            cout << "\t\t\tSISTEMA DE CAJA\n";
            cout << "\tReporte De La Compra _____________________[1]\n";
            cout << "\tModificacion De Producto__________________[2]\n";
            cout << "\tEliminacion De Producto___________________[3]\n";
            cout << "\tGenerar Venta_____________________________[4]\n";
            cout << "\tValidacion De La Venta____________________[5]\n";
            cout << "\tSalida De La Venta________________________[6]\n";
            cout << "\tConcluir Venta____________________________[7]\n";
            cout << "\tIngrese una opcion[1-7]: ";
            cin >> opcion;
            switch (opcion)
            {
                case 1: system("cls"); 
                        listarProducto(); 
                        system("pause");
                        system("cls"); 
                        break;
                case 2: system("cls"); 
                        modificarProducto(); 
                        system("pause");
                        system("cls"); 
                        break;
                case 3: system("cls"); 
                        eliminarProducto(); 
                        system("pause");
                        system("cls"); 
                        break;
                case 4: system("cls"); 
                        venta(); 
                        system("pause");
                        system("cls"); 
                        break;
                case 5: system("cls");
                        cout << "\t¿Desea validar la compra? (S/s para validar): ";
                        cin >> nombreCajero;
                        if (nombreCajero == "S" || nombreCajero == "s") {
                            ventaValida = true;
                            cout << "\tVenta validada correctamente\n";
                        } else {
                            ventaValida = false;
                            cout << "\tVenta cancelada\n";
                        }
                        system("pause");
                        system("cls");
                        break;
                case 6: system("cls");
                        if (ventaValida) {
                        cout << "\tEstado de la venta: VALIDA\n";
                        } else {
                         cout << "\tEstado de la venta: CANCELADA\n";
                        }
                        system("pause");
                        system("cls");
                        break;
				case 7: system("cls"); 
                        main(); 
                        system("pause");
                        system("cls"); 
                        break; 
                default:cout << "Ingrese una opcion correcta[1-7]\n";
            }

        } while (opcion!=7);
        
    }
    else
    {
        cout << "Acceso denegado, usuario  incorrecta\n";
    }
}



void    regProducto()
{
    int opcion;
    do
    {
        cout << "\t\t\tMENU DE REGISTRO DE PRODUCTOS DE VICTOYS\n";
		cout << "\tSeleccion de Productos__________[1]\n";
		cout << "\tBuscar Producto_________________[2]\n";
		cout << "\tListar Productos________________[3]\n";
		cout << "\tSalir___________________________[4]\n";
		cout << "\tIngrese una opcion[1-4]:";
		cin >> opcion;
        switch (opcion)
        {
        case 1: system("cls"); 
                addProducto(); 
                system("pause");
                system("cls"); 
                break;
        case 2: system("cls"); 
                buscarProducto(); 
                system("pause");
                system("cls"); 
                break;
        case 3: system("cls"); 
                listarProducto(); 
                system("pause");
                system("cls"); 
                break;
        case 4: system("cls"); 
                sisCliente(); 
                system("pause");
                system("cls"); 
                break;
        default: cout << "Ingrese una opcion correcta[1-4]\n";
        }
    } while (opcion!=4);
    
}

void addProducto()
{
     string nomPro , rpta;
     int stkPro, seleccion;
     float prePro;

    do
	{
		cout << " \t\t\tPRODUCTOS DISPONIBLES DE VICTOYS\n";
		cout << " \tMAX STEELL  - $25.30___________[1]\n";
		cout << " \tOSO TED     - $12.50___________[2]\n";
		cout << " \tBARBIE      - $28.70___________[3]\n";
		cout << " \tHOT WHEELS  - $10.00___________[4]\n";
		cout << " \tTRANSFORMER - $16.80___________[5]\n";
		cout << " \tCUBO MAGICO - $5.00____________[6]\n";
		cout << " \tGOGOS       - $3.40____________[7]\n";
		cout << " \tLEGO        - $100.00__________[8]\n";
		cout << " \tNERF        - $43.70___________[9]\n";
		cout << " \tPLAY DOH    - $30.00___________[10]\n";
		cout << " \tSeleccione un producto[1-10]: ";
		cin >> seleccion;

		switch (seleccion)
		{
			case 1:
				nomPro = "MAX STEELL";
				prePro = 25.30;
				break;
			case 2:
				nomPro = "OSO TED";
				prePro = 12.50;
				break;
			case 3:
				nomPro = "BARBIE ";
				prePro = 28.70;
				break;
			case 4:
				nomPro = "HOT WHEELS";
				prePro = 10.00;
				break;
			case 5:
				nomPro = "TRANSFORMER";
				prePro = 16.80;
				break;
			case 6:
				nomPro = "CUBO MAGICO";
				prePro = 5.00;
				break;
			case 7:
				nomPro = "GOGOS";
				prePro = 3.40;
				break;
			case 8:
				nomPro = "LEGO  ";
				prePro = 100.00;
				break;
			case 9:
				nomPro = "NERF ";
				prePro = 43.70;
				break;
			case 10:
				nomPro = "PLAY DOH ";
				prePro = 30.00;
				break;
			default:
				cout << "Ingrese una opcion correcta[1-10]\n";
				return;
		}

		int cod = getProducto();

		Producto producto;
		producto.codProducto = cod;
		producto.nomProducto = nomPro;
		producto.preProducto = prePro;

		cout << "\tCantidad: ";
		cin >> stkPro;
		producto.stkProducto = stkPro;

		vecProducto.push_back(producto);

		cout << "Deseas continuar registrando productos...(S/s):";
		cin >> rpta;

		system("cls");
	} while ( rpta == "S" || rpta == "s");
	
}

int getProducto()
{
    if (vecProducto.size() == 0)
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size()-1].codProducto + 1;
	}
}

void buscarProducto()
{
    int codigo;
	cout << "Ingrese el codigo a buscar:";
	cin >> codigo;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			cout << "Codigo:" << vecProducto[i].codProducto << endl;
			cout << "Nombre:" << vecProducto[i].nomProducto << endl;
			cout << "Precio:" << vecProducto[i].preProducto << endl;
			cout << "Cantidad:" << vecProducto[i].stkProducto << endl;
			break;
		}
	}
}

void    listarProducto()
{
    if (vecProducto.empty())
    {
        cout << "Carrito vacío\n";
    }
    else
    {
        cout << "Cliente: " << nombreClienteActual << " (Código: " << codigoClienteActual << ")\n";

        for (int i = 0; i < vecProducto.size(); i++)
        {
            cout << "-----------------------------------\n";
            cout << "Codigo:" << vecProducto[i].codProducto << endl;
            cout << "Nombre:" << vecProducto[i].nomProducto << endl;
            cout << "Precio:" << vecProducto[i].preProducto << endl;
            cout << "Cantidad:" << vecProducto[i].stkProducto << endl;
            cout << "-----------------------------------\n";
        }
    }
}

int     posicionProducto(int codigo)
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			return i;
		}
	}
	return -1;
}

void    modificarProducto()
{
	int cod;
    cout << "Ingrese el codigo del producto a modificar:";
    cin >> cod;
    int posEncontrada = posicionProducto(cod);

    if (posEncontrada == -1)
    {
        cout << "El codigo ingresado no existe en el carrito\n";
    }
    else
    {
        int opcion;
        int nuevaCantidad;

        cout << "Ver Producto a modificar\n";
        cout << "________________________\n";
        cout << "Codigo:" << vecProducto[posEncontrada].codProducto << endl;
        cout << "Nombre:" << vecProducto[posEncontrada].nomProducto << endl;
        cout << "Precio:" << vecProducto[posEncontrada].preProducto << endl;
        cout << "Cantidad:" << vecProducto[posEncontrada].stkProducto << endl;
        cout << "________________________\n";
        cout << "MINI MENU DE OPCIONES\n";
        cout << "*********************\n";
        cout << "Cantidad\t\t[1]\n";
        cout << "Seleccionar una opcion a modificar:";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                cout << "Nueva Cantidad:";
                cin >> nuevaCantidad;
                vecProducto[posEncontrada].stkProducto = nuevaCantidad;
                cout << "Cantidad modificada\n";
                break;
            default:
                cout << "Ingrese una opcion correcta[1]\n";
        }
    }
}

void    eliminarProducto()
{
	int cod;
    bool flag = false;
    cout << "Ingrese el codigo del producto a eliminar:";
    cin >> cod;
    for (int i = 0; i < vecProducto.size(); i++)
    {
        if (cod == vecProducto[i].codProducto)
        {
            vecProducto.erase(vecProducto.begin() + i);
            flag = true;
            break;
        }
    }

    if (flag == true)
    {
        cout << "Producto eliminado del carrito\n";
    }
    else
    {
        cout << "Producto no encontrado en el carrito\n";
    }
}

float generarVenta()
{
	float suma = 0;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		suma = suma + (vecProducto[i].preProducto * vecProducto[i].stkProducto );
	}
	return suma;

}

void venta()
{
    if (vecProducto.empty())
    {
        cout << "Carrito vacio\n";
    }
    else
    {
        cout << "Cliente: " << nombreClienteActual << " (Codigo: " << codigoClienteActual << ")\n";

        for (int i = 0; i < vecProducto.size(); i++)
        {
            cout << "-----------------------------------\n";
            cout << "Codigo:" << vecProducto[i].codProducto << endl;
            cout << "Nombre:" << vecProducto[i].nomProducto << endl;
            cout << "Precio:" << vecProducto[i].preProducto << endl;
            cout << "Cantidad:" << vecProducto[i].stkProducto << endl;
            cout << "-----------------------------------\n";
        }
        cout << "Precio Total: $" << generarVenta() << endl;
    }
    
}

