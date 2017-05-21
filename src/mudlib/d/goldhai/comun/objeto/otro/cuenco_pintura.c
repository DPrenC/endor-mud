/*=============================================================*
 |           << GOLDHAI.Crowy [w] Woo@simauria >>              |
 *=============================================================*
 |              Creacion............. 08-10-98                 |
 |              Ultima Modificacion...08-10-98                 |
 |                                                             |
 *=============================================================*/

#include "path.h"
#include <properties.h>

inherit THING;

int vacio;
public int vaciar();
public int rellenar();
public int QueryVacio();

create() {
  ::create();
 vacio=0;
 SetIds(({"cuenco","cuenco de pintura","cuenco pintura"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
}

QueryValue()
{
 if(!vacio) return 150;
 else return 0; // El cuenco por si no vale dinero
}

QueryWeight()
{
 if(!vacio) return 400;
 else return 150; // Vacio pesa menos.
}

QueryLong()
{
 return
"Se trata de un cuenco de madera especialmente disenyado para contener todo\n\
tipo de pinturas y liquidos colorantes. Tiene dos asas a los lados para poder\n\
sujetarlo asi como una pequenya tapadera tambien de madera para evitar que el\n\
liquido se derrame."+(vacio?" El cuenco no contiene nada ahora.\n":
" Miras en el interior y ves un extranyo liquido de color\n\
rojo y bastante espeso.\n");
}

QueryShort()
{
 return "un cuenco de pintura"+(vacio?" vacio":"");
}

public int QueryVacio()
{
 return vacio;
}

public int vaciar()
{
 return vacio++;
}

public int rellenar()
{
 return vacio=0;
}
