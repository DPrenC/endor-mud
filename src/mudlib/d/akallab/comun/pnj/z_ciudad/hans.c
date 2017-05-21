/********************
Fichero: /d/akallab/comun/pnj/z_ciudad/hans.c
Autor: Yalin.
Fecha: 31/10/2007 20:13:41
Descripci�n: Hans, el cart�grafo de la librer�a de Zarkam.
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
    SetShort("Hans el cart�grafo");
    SetLong("Hans es un elfo oscuro adulto. Hace tiempo que se asent� en este lugar y mont� "
        "esta librer�a que le sirve de sustento. Debido al poco inter�s por los libros de la "
        "gente en esta zona, ha ido reconvirtiendo poco a poco su negocio y ahora dedica la "
        "mayor parte del tiempo a dibujar mapas, muy demandados por los orcos que siempre "
        "andan enzarzados en alguna que otra disputa territorial.\n");
    AddId(({"hans","Hans","librero","cartografo","cart�grafo","elfo_oscuro"}));
}
