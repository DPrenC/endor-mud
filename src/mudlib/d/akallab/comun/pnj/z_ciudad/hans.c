/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/hans.c
Autor: Yalin.
Fecha: 31/10/2007 20:13:41
Descripción: Hans, el cartógrafo de la librería de Zarkam.
********************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Hans","elfo-oscuro",15,GENERO_MASCULINO);
    SetName("Hans");
    SetShort("Hans el cartógrafo");
    SetLong("Hans es un elfo oscuro adulto. Hace tiempo que se asentó en este lugar y montó "
        "esta librería que le sirve de sustento. Debido al poco interés por los libros de la "
        "gente en esta zona, ha ido reconvirtiendo poco a poco su negocio y ahora dedica la "
        "mayor parte del tiempo a dibujar mapas, muy demandados por los orcos que siempre "
        "andan enzarzados en alguna que otra disputa territorial.\n");
    AddId(({"hans","Hans","librero","cartografo","cartógrafo","elfo_oscuro"}));
}
