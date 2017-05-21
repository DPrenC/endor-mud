/* Fichero: /d/akallab/comun/pnj/akallab/gaddaro/faust.c
Autor: Yalin
Fecha: 24/10/2007 18:17:39
Descripción: Tendero de Narad.
*/
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Faust","orco",10,GENERO_MASCULINO);
    SetName("Faust");
    SetShort("Faust, el tendero");
    SetLong("Faust es un viejo orco que se estableció en el pueblo de Gaddaro donde abrió una "
        "pequeña tienda en la que se gana la vida comerciando con productos de uso general. "
        "las cicatrices que marcan algunas partes de su cuerpo dan fé de que su vida no fué "
        "siempre tan sosegada.\n");
    AddId(({"Faust","faust","tendero","orco"}));
    Set(P_CANT_LURE,1);
}
