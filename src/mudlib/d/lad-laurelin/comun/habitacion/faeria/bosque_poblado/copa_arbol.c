/***
Fichero: copa_arbol.c
Autor: kastwey@simauria
Descripción: Copa del árbol del norte del bosque del pueblo de Siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_faeria");

int bajar_copa();

create()
{
    ::create();
    SetIntShort("la copa del árbol");
    SetIntLong(W("Te encuentras en la copa del árbol más alto del bosque de Siempreunidos.\n"
    "Desde aquí, divisas unas magníficas vistas del bosque en su totalidad, al sur el pequeño pueblo de Siempreunidos, y más al sur, el bosque de Atbalnin.\n"
    "Sin duda, este es un buen sitio para estar en solitario, disfrutando de las grandiosas vistas que te ofrece la increible altura a la que te encuentras.\n"));
    SetIntNoise("Escuchas el susurro de las hojas del árbol.\n");
    SetIntSmell("Huele a aire fresco.\n");
    SetLocate("bosque de Siempreunidos");
    AddDetail(({"siempreunidos","poblado","pueblo"}),W(
    "Al sur, observas el pequeño pueblo de Siempreunidos. Es un pequeño poblado, no más que unas pocas construcciones, rodeado de bosque por todas partes.\n"));
    AddDetail("atbalnin",W(
    "Hacia el sur, pasado el pueblo de Siempreunidos, observas el bosque de Atbalnin, que rodea a la capitad de los elfos.\n"));
    SetOutdoors(1);
    AddExit("bajar",SF(bajar_copa));
}

int bajar_copa()
{
    if (TP->move(HAB_BOSQUE_PUESTO("bosque_11"),M_SPECIAL,({
    W("comienza a descender por las ramas del árbol hasta que l" + AO + " pierdes de vista"),
    "llega descendiendo por las ramas del árbol",
    W("Comienzas a descender por las gruesas ramas del árbol.\n"
    "Tras un interminable descenso en el que te planteas seriamente los motivos que te llevaron a subir hasta tan alto, consigues llegar al suelo del bosque, san" + AO + " y salv" + AO)
    })) != ME_OK) return write("Por alguna razón, no es posible descender del árbol. Consulta con un wizard.\n"),1;
    return 1;
}