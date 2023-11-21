#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Producto
{
    int     codProducto;
    string  nomProducto;
    float   preProducto;
    int     stkProducto;
};

vector<Producto> vecProducto;

void addVector();
void listOfItems();
float getPrecioTotal();
int postDelPrecioAlto();
string productoConPrecioAlto();
int getCorrelativo();
void buscarPorCodigo();
void removeVector();
void modifyVector();
int obtenerPosicionDelRegistro(int);

int main()
{
    int opcion;
    do
    {
        cout << "MENU DE OPCIONES\n";
        cout << "Seleccionar Producto_______[1]\n";
        cout << "Ver Carrito y Precio Total__[2]\n";
        cout << "Eliminar Producto__________[3]\n";
        cout << "Modificar Producto_________[4]\n";
        cout << "Listar Productos___________[5]\n";
        cout << "Salir del Programa__________[6]\n";
        cout << "Ingrese una opcion[1-6]:";
        cin >> opcion;

        switch (opcion)
        {
            case 1: system("cls"); addVector(); break;
            case 2: system("cls"); listOfItems(); break;
            case 3: system("cls"); removeVector(); break;
            case 4: system("cls"); modifyVector(); break;
            case 5: system("cls"); listOfItems(); break;
            case 6: break;
            default: cout << "Ingrese una opcion correc+ta[1-6]\n";
        }

    } while (opcion != 6);

    return 0;
}

void addVector()
{
    string nomPro;
    int stkPro, seleccion;
    float prePro;

    cout << "PRODUCTOS DISPONIBLES\n";
    cout << "1. Producto A - $10.00\n";
    cout << "2. Producto B - $20.00\n";
    cout << "3. Producto C - $30.00\n";
    cout << "Seleccione un producto[1-3]: ";
    cin >> seleccion;

    switch (seleccion)
    {
        case 1:
            nomPro = "Producto A";
            prePro = 10.00;
            break;
        case 2:
            nomPro = "Producto B";
            prePro = 20.00;
            break;
        case 3:
            nomPro = "Producto C";
            prePro = 30.00;
            break;
        default:
            cout << "Opción no válida\n";
            return;
    }

    int cod = getCorrelativo();

    Producto producto;
    producto.codProducto = cod;
    producto.nomProducto = nomPro;
    producto.preProducto = prePro;

    cout << "Cantidad: ";
    cin >> stkPro;
    producto.stkProducto = stkPro;

    vecProducto.push_back(producto);

    cout << "Producto agregado al carrito\n";
}

void listOfItems()
{
    if (vecProducto.empty())
    {
        cout << "Carrito vacío\n";
    }
    else
    {
        for (int i = 0; i < vecProducto.size(); i++)
        {
            cout << "-----------------------------------\n";
            cout << "Codigo:" << vecProducto[i].codProducto << endl;
            cout << "Nombre:" << vecProducto[i].nomProducto << endl;
            cout << "Precio:" << vecProducto[i].preProducto << endl;
            cout << "Cantidad:" << vecProducto[i].stkProducto << endl;
            cout << "-----------------------------------\n";
        }
        cout << "Precio Total: $" << getPrecioTotal() << endl;
        cout << "Producto con precio más alto: " << productoConPrecioAlto() << endl;
    }
}

float getPrecioTotal()
{
    float suma = 0;
    for (int i = 0; i < vecProducto.size(); i++)
    {
        suma += vecProducto[i].preProducto * vecProducto[i].stkProducto;
    }
    return suma;
}

int postDelPrecioAlto()
{
    int pos = 0;
    float maximo = vecProducto[0].preProducto;
    for (int i = 0; i < vecProducto.size(); i++)
    {
        if (vecProducto[i].preProducto > maximo)
        {
            maximo = vecProducto[i].preProducto;
            pos = i;
        }
    }
    return pos;
}

string productoConPrecioAlto()
{
    return vecProducto[postDelPrecioAlto()].nomProducto;
}

int getCorrelativo()
{
    if (vecProducto.empty())
    {
        return 1;
    }
    else
    {
        return vecProducto[vecProducto.size() - 1].codProducto + 1;
    }
}

void buscarPorCodigo()
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
            cout << "Stock:" << vecProducto[i].stkProducto << endl;
            break;
        }
    }
}

void removeVector()
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

void modifyVector()
{
    int cod;
    cout << "Ingrese el codigo del producto a modificar:";
    cin >> cod;
    int posEncontrada = obtenerPosicionDelRegistro(cod);

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

int obtenerPosicionDelRegistro(int codigo)
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
