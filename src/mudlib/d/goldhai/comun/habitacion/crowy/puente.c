/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-11-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("un puente de Crowy");
 SetIntLong("\
Estás situado encima del puente que te permite cruzar el río que rodea la\n\
ciudad de Crowy. Puedes terminar de cruzar el puente en dirección a las\n\
puertas de la ciudad si vas hacia el Norte o bien llegar a un camino si\n\
decides ir hacia el Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el ruido del agua pasar por debajo de tus pies.\n");
 SetIntSmell("Hay un olor irrespirable proveniente del agua en el ambiete.\n");
 AddDetail(({"puente","pasarela"}),
"Un enorme puente de piedra que te permite cruzar el río que rodea Crowy.\n");
 AddDetail(({"río","arroyo","agua"}),
"Te arrimas a la orilla del puente y miras hacia abajo. Un terrible olor\n\
proveniente del agua te impide casi respirar, seguramente hará años que no\n\
se ha cambiado ese agua estancada. Toda clase de enseres y porqueria flota\n\
en la superficie de ese agua grasienta y de color amarillo.\n");

 AddExit("norte",CROWY("entrada"));
 AddExit("sur",BOSCURO("alrededor_crowy1"));

 SetLocate("crowy");
}

