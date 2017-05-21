/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 08-02-99              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GACANTILADO;

create()
{
 ::create();
 SetIntLong("\
Est�s en una pendiente muy pronunciada que une la parte alta del acantilado\n\
con la playa situada al Norte. Los �rboles y la frondosa vegetaci�n del\n\
bosque te impiden ir hacia otras direcciones.\n");

 AddExit("oeste",ACANTILADO("acantilado_norte7"));
 AddExit("norte",PLAYA("playa1"));

 SetLocate("acantilado del noroeste de Goldhai");
}
