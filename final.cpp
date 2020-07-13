#include <iostream>
#include <vector>

using namespace std;

const int longCad = 20;

struct articulo{
    char nombreArticul[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulo;
};

float obtenerTotal(int cantidad, float precioUnitario){
    //Obtener total multiplicando la cantidad de articulos por su precio
    return cantidad*precioUnitario;
}

articulo agregarArticulo(){
    //Se declara una variable de la estructura
    articulo arti;
    //Se agregan sus datos
    cout << "Ingrese el nombre del articulo" << endl;
    cin >> arti.nombreArticul;
    //Bucle para validar que la cantidad de productos sea mayor a 0
    do{
        
        cout << "Ingrese la cantidad" << endl;
        cin >> arti.cantidad;
        if((arti.cantidad < 1)){
            cout << "Ingrese un valor valido" << endl;
        }

    }while (arti.cantidad < 1);
    //Bucle para validar que el precio del producto sea mayor a 0
    do{

        cout << "Ingrese el precio unitario" << endl;
        cin >> arti.costoPorArticulo;
        if( arti.costoPorArticulo <= 0 ){
            cout << "Ingrese un valor valido" << endl << endl;
        }

    }while (arti.costoPorArticulo <= 0);
    
    
    //Llamada a la funcion para obtener el precio total
    arti.precio = obtenerTotal(arti.cantidad, arti.costoPorArticulo);

    return arti;
}

//Funcion que recorre el arreglo y muestra su contenido
void mostrarArticulos(vector<articulo> articulos){
    //Validacion para que el arreglo tenga por lo menos un elemento, de otro modo mostrar un mensaje
    if(articulos.size() > 0){
        cout << "Productos en el carrito: " << endl;
        //bucle para recorrer el arreglo
        for(articulo arti : articulos){
            cout << "Nombre del articulo.................. " << arti.nombreArticul << endl;
            cout << "Cantidad ............................ " << arti.cantidad << endl;
            cout << "Precio Unitario ..................... " << arti.costoPorArticulo << endl;
            cout << "Total ............................... " << arti.precio << endl << endl;
        }
    }else{
        cout << "Actualmente su carrito esta vacio" << endl;
    }

}

//Funcion para obtener el total de la compra
string totalDeCompra(vector<articulo> articulos){
    float total = 0;
    for(articulo arti : articulos){
        total += arti.precio;
    }
    return "El total a pagar es de: $"+to_string(total);
}

int main(){
    //Variables
    vector<articulo> articulos;
    int opcion;
    int cantidad;
    bool seguir = true;
    //Mensaje de bienvenida
    cout << "Bienvenido al programa para obtener el total de una compra" << endl;
    //La llamada a las funciones se maneja por medio de un menu por esto se utiliza un bucle
    while (seguir)
    {
        //Impresion del menu
        cout << "Ingrese el numero de la accion que desea realizar \n \n 1............................ Agregar Productos \n 2............................ Ver productos en el carrito \n 3............................ Obtener total de compra \n 4............................ Salir \n";
        cin >> opcion;
        //Switch que evalua la opcion que el usuario selecciono
        switch (opcion){

            //Si se ingresa 1 se agregan productos al arreglo
            case 1:
                int cantidad;
                //Funcion para limpiar la pantalla
                system ("CLS");
                //Bucle para validar que la cantidad ingresada sea mayor a cero
                do{
                    cout << "Cuantos productos desea ingresar?" << endl;
                    cin >> cantidad;
                    if(cantidad < 1){
                        cout << "Ingrese una cantidad valida \n\n" << endl;
                    }
                } while (cantidad < 1);
                
                cout << endl << endl;
                //bucle que hace llamada a la funcion para agregar productos y porsteriormente se agrega al arreglo
                for (size_t i = 0; i < cantidad; i++){
                    cout << "Ingrese los datos del Producto #" << i+1 << endl;
                    articulos.push_back(agregarArticulo());
                    cout << endl << endl;
                } 
                cout << "Productos Agregados exitosamente" << endl;
                break;
            
            //Si el usuario ingresa la opcion 2 se muestran los productos que estan en el arreglo
            case 2:
                system ("CLS");
                mostrarArticulos(articulos);
                system("PAUSE()");
                system("CLS()");
                break;

            //Si elige la opcion 3 devuelve el total de compra y el bucle termina
            case 3:
                cout << totalDeCompra(articulos) << endl;
                system("PAUSE()");
                seguir = false;
                break;

            //Si elige la opcion 4 el bucle termina
            default:
                seguir = false;
                break;
        }
    }
}
