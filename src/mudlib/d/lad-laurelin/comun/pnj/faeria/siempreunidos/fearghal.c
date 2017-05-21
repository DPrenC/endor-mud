/***
Fichero: Fearghal.c
Autor: Kastwey@simauria
Descripción:
El tabernero de la taberna de siempreunidos.
***/

#include "path.h"

inherit STD_FAERIA("pnj_base_faeria");

create()
{
    ::create();
   SetStandard("Fearghal", "elfo", 15+random(6), 1);
    SetLong(W("Este es Fearghal, el tabernero.\n"
        "Es un elfo alto, aunque no tan delgado como suelen serlo los elfos. Su prominente barriga te hace sospechar que no sirve la cerveza únicamente a sus clientes.\n"
        "Tiene una cara risueña y unos ojos que te miran con viveza y curiosidad.\n"));
    SetLongDesprecio(W("Este es Fearghal, el tabernero.\n"
        "Es un elfo alto, aunque no tan delgado como suelen serlo los elfos. Su prominente barriga te hace sospechar que no sirve la cerveza únicamente a sus clientes.\n"
        "Te está mirando con cara de pocos amigos.\n"));
    AddId("tabernero");
    AddId("tabernero_faeria");
}
