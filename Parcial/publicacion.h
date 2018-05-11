#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "cliente.h"

typedef struct
{
    char aviso[50];
    int idCliente;
    int rubro;
    int estado; //[1] Activo - [2]pausado
    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;


int publicacion_init(Publicacion* array,int limite);
int publicacion_mostrar(Publicacion* array, Cliente* cliente,int limite, int limite_cliente);
int publicacion_mostrarDebug(Publicacion* array, Cliente* cliente,int limite, int limite_cliente);
int publicacion_mostrarPorIdCliente(Publicacion* array, int limite, int idCliente);
int publicacion_alta(Publicacion* array, Cliente* cliente,int limite, int limiteClientes);
int publicacion_baja(Publicacion* array,int limite, int id);
int publicacion_baja_prof(Publicacion* array,int limite, int id);
int publicacion_modificacion(Publicacion* array,int limite, int id);
int publicacion_ordenar(Publicacion* array,int limite, int orden);
int publicacion_buscarPorId(Publicacion* array,int limite, int id);
int publicacion_bajaPorIdCliente(Publicacion* array, int limite, int idCliente);
int publicacion_comprar(Publicacion* publicaciones, Cliente* cliente, int limite_pub, int limite_user, int idPublicacion);
int publicacion_altaForzada(Publicacion* array,int limite,int idCliente,char* aviso,int rubro, int estado);
int publicacion_cambiarEstado(Publicacion* array,int limite, int id);
#endif // PUBLICACION_H_INCLUDED
