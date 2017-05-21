/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 29-10-98              |
 |            Ultima Modificacion....... 29-10-98              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GACANTILADO;

create()
{
 ::create();
 SetIntLong("\
Est�s en la parte alta del acantilado. Ves y oyes como las olas golpean\n\
fuertemente sobre las rocas. Si miras hacia el este podr�s ver un peque�o\n\
camino que se adentra en el bosque y que quiz�s te lleve a alg�n sitio\n\
de interes. Puedes continuar por la orilla del acantilado en direcci�n\n\
Norte y Oeste.\n");

 AddExit("oeste",ACANTILADO("acantilado_norte4"));
 AddExit("norte",ACANTILADO("acantilado_norte6"));
 AddExit("este",BNORTE("bosque11"));

AddDetail(({"senda","camino","peque�o camino"}),
"Ves una peque�a senda que se adentra en el bosque.\n");

 SetLocate("acantilado del noroeste de Goldhai");
}
