#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "publicacion.h"
#include "utn.h"
#define LEN_CLIENTE 100
#define LEN_PUB 1000



int main()
{
    Cliente cliente[LEN_CLIENTE];
    Publicacion publicaciones[LEN_PUB];

    int menu;
    int auxiliarId;

    publicacion_init(publicaciones, LEN_PUB);
    cliente_init(cliente,LEN_CLIENTE);

    cliente_altaForzada(cliente, LEN_CLIENTE,"Osvaldo","Mig",20318223824);
    cliente_altaForzada(cliente, LEN_CLIENTE,"Jorge","Sanl",27318223824);
    cliente_altaForzada(cliente, LEN_CLIENTE,"Magda","Lan",30318223824);
    cliente_altaForzada(cliente, LEN_CLIENTE,"Vero","87",20318223824);

    publicacion_altaForzada(publicaciones,LEN_PUB,0,"motores",1,1);
    publicacion_altaForzada(publicaciones,LEN_PUB,1,"electro",2,1);
    publicacion_altaForzada(publicaciones,LEN_PUB,0,"hogar",3,1);


    do
    {
        getValidInt("1.Alta Cliente\n2.Modificar usuario\n3.Baja Cliente\n4.Publicar Producto\n5.Modificar Publicacion\n6.Cancelar Publicacion\n7.Comprar Producto\n8.Listar Publicaciones de usuario\n9.Listar publicaciones\n10.Listar Clientes\n11.Salir\n","\nNo valida\n",&menu,1,11,1);
        switch(menu)
        {
            case 1:
                cliente_alta(cliente,LEN_CLIENTE);
                break;
            case 2:
                cliente_mostrar(cliente,LEN_CLIENTE);
                getValidInt("ID? \n","\nNumero valida\n",&auxiliarId,0,2000,2);
                cliente_modificacion(cliente,LEN_CLIENTE,auxiliarId);
                break;
            case 3: //
                cliente_mostrar(cliente,LEN_CLIENTE);
                getValidInt("ID?\n","\nNumero valida\n",&auxiliarId,0,2000,2);
                cliente_baja(cliente,LEN_CLIENTE,auxiliarId);
                publicacion_bajaPorIdCliente(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 4:
                publicacion_alta(publicaciones, cliente, LEN_PUB, LEN_CLIENTE);
                publicacion_mostrar(publicaciones,cliente,LEN_PUB,LEN_CLIENTE);
                break;
            case 5:
                getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                cliente_mostrar_idPublicacion(cliente,LEN_CLIENTE,auxiliarId);
                publicacion_cambiarEstado(publicaciones,LEN_CLIENTE, auxiliarId);
                break;
            case 6:
                //getValidInt("idCliente?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                //publicacion_mostrarPorIdCliente(publicaciones, LEN_PUB, auxiliarId);
                //getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                //publicacion_baja_prof(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 7:
                //getValidInt("idPublicacion?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                //publicacion_comprar(publicaciones, cliente, LEN_PUB, LEN_CLIENTE, auxiliarId);
                break;
            case 8:
                //getValidInt("idCliente?\n","\nNo es un id\n", &auxiliarId, 0, 1000,2);
                //publicacion_mostrarPorIdCliente(publicaciones, LEN_PUB, auxiliarId);
                break;
            case 9:
                //publicacion_mostrar(publicaciones, cliente, LEN_PUB, LEN_CLIENTE);
                break;
            case 10:
                //usuario_mostrar(cliente, LEN_CLIENTE);
                break;
        }

    }while(menu != 11);

    return 0;
}
