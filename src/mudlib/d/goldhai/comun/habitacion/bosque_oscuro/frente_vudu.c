/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 13-05-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    SetPreIntShort("frente a");
    SetIntShort("la tienda de vudú");
    SetIntLong("Estás en un pequeño claro del bosque, donde destaca una rústica cabaña hecha a "
        "base de troncos y ramas del bosque. En la puerta hay un gran cartel de madera en el "
        "cuál se puede leer 'Evah, la gran curandera'. Puedes entrar en la tienda de Evah si "
        "vas hacia el Sur, mientras que si vas al Este llegarás a otra parte de este bosque. "
        "Un poco más adelante, en el Oeste, parece ser que el bosque se corta por un "
        "acantilado.\n");
    AddDetail(({"cartel","letrero","tabla"}),"Puedes ver escrito en él: 'Evah, la gran "
        "curandera'. Al parecer se trata de una tienda de pócimas y cosas relacionadas con el "
        "vudú.\n");
    AddDetail(({"rocas","acantilado"}),"No es que se pueda ver mucho desde aquí, pero crees "
        "que se trata de los acantilados de la zona suroeste de Goldhai.\n");
    AddDetail(({"choza","cabanya","tienda","cabaña"}),"Toda fabricada de trozos de tronco y "
        "ramas que seguramente pertenecerán a este bosque. Su diseño es bastante simple, "
        "cuatro paredes con un pequeño techo de ramas acabado en punta.\n");
    AddExit("este",BOSCURO("bosque8"));
    AddExit("oeste",ACANTILADO("acantilado1"));
    AddExit("sur",BOSCURO("tienda_vudu"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
