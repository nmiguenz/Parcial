#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    float cuit;
    //------------
    int idCliente;
    int isEmpty;
}Cliente;


int cliente_init(Cliente* array,int limite);
int cliente_mostrar(Cliente* cliente,int LEN_CLIENTE);
//int cliente_mostrar(Cliente* array,int limite);
int cliente_mostrarDebug(Cliente* array,int limite);
int cliente_alta(Cliente* array,int limite);
int cliente_baja(Cliente* array,int limite, int id);
int cliente_baja_prof(Cliente* array,int limite, int id); //como la pasaron en el template
int cliente_modificacion(Cliente* array,int limite, int id);
int cliente_ordenar(Cliente* array,int limite, int orden);
int cliente_buscarPorId(Cliente* array,int limite, int id);
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, float cuit);
int cliente_mostrarPorIdPublicacion(Cliente* array, int limite, int idPublicacion);



#endif // CLIENTE_H_INCLUDED
