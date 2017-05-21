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
    SetIntShort("la tienda de vud�");
    SetIntLong("Est�s en un peque�o claro del bosque, donde destaca una r�stica caba�a hecha a "
        "base de troncos y ramas del bosque. En la puerta hay un gran cartel de madera en el "
        "cu�l se puede leer 'Evah, la gran curandera'. Puedes entrar en la tienda de Evah si "
        "vas hacia el Sur, mientras que si vas al Este llegar�s a otra parte de este bosque. "
        "Un poco m�s adelante, en el Oeste, parece ser que el bosque se corta por un "
        "acantilado.\n");
    AddDetail(({"cartel","letrero","tabla"}),"Puedes ver escrito en �l: 'Evah, la gran "
        "curandera'. Al parecer se trata de una tienda de p�cimas y cosas relacionadas con el "
        "vud�.\n");
    AddDetail(({"rocas","acantilado"}),"No es que se pueda ver mucho desde aqu�, pero crees "
        "que se trata de los acantilados de la zona suroeste de Goldhai.\n");
    AddDetail(({"choza","cabanya","tienda","caba�a"}),"Toda fabricada de trozos de tronco y "
        "ramas que seguramente pertenecer�n a este bosque. Su dise�o es bastante simple, "
        "cuatro paredes con un peque�o techo de ramas acabado en punta.\n");
    AddExit("este",BOSCURO("bosque8"));
    AddExit("oeste",ACANTILADO("acantilado1"));
    AddExit("sur",BOSCURO("tienda_vudu"));
    AddPnj();
    SetLocate("bosque oscuro de Goldhai");
}
