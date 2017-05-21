/***
Fichero: copa_arbol.c
Autor: kastwey@simauria
Descripci�n: Copa del �rbol del norte del bosque del pueblo de Siempreunidos.
Creaci�n: 18/12/2004
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_faeria");

int bajar_copa();

create()
{
    ::create();
    SetIntShort("la copa del �rbol");
    SetIntLong(W("Te encuentras en la copa del �rbol m�s alto del bosque de Siempreunidos.\n"
    "Desde aqu�, divisas unas magn�ficas vistas del bosque en su totalidad, al sur el peque�o pueblo de Siempreunidos, y m�s al sur, el bosque de Atbalnin.\n"
    "Sin duda, este es un buen sitio para estar en solitario, disfrutando de las grandiosas vistas que te ofrece la increible altura a la que te encuentras.\n"));
    SetIntNoise("Escuchas el susurro de las hojas del �rbol.\n");
    SetIntSmell("Huele a aire fresco.\n");
    SetLocate("bosque de Siempreunidos");
    AddDetail(({"siempreunidos","poblado","pueblo"}),W(
    "Al sur, observas el peque�o pueblo de Siempreunidos. Es un peque�o poblado, no m�s que unas pocas construcciones, rodeado de bosque por todas partes.\n"));
    AddDetail("atbalnin",W(
    "Hacia el sur, pasado el pueblo de Siempreunidos, observas el bosque de Atbalnin, que rodea a la capitad de los elfos.\n"));
    SetOutdoors(1);
    AddExit("bajar",SF(bajar_copa));
}

int bajar_copa()
{
    if (TP->move(HAB_BOSQUE_PUESTO("bosque_11"),M_SPECIAL,({
    W("comienza a descender por las ramas del �rbol hasta que l" + AO + " pierdes de vista"),
    "llega descendiendo por las ramas del �rbol",
    W("Comienzas a descender por las gruesas ramas del �rbol.\n"
    "Tras un interminable descenso en el que te planteas seriamente los motivos que te llevaron a subir hasta tan alto, consigues llegar al suelo del bosque, san" + AO + " y salv" + AO)
    })) != ME_OK) return write("Por alguna raz�n, no es posible descender del �rbol. Consulta con un wizard.\n"),1;
    return 1;
}