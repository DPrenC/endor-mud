/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"La ciudad parece distinta desde este punto. Contemplas como guerreros de\n\
cualquier raza entran en la taberna situada al Este. No es muy recomendable\n\
que entres si tu nivel no es alto ya que sin quererlo te puedes ver envuelto\n\
en una batalla que no deseas. Por el contrario, puedes ver a unos viejos que\n\
juegan con sus nietos en el parque que esta al Oeste. Es un lugar de relax en\n\
una ciudad en la que es dificil encontrarlo. La calle continua en dirección\n\
Norte y Sur.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"pub","taberna","garito"}),
"Es un sitio maloliente y lleno de suciedad. El antro preferido de toda los\n\
guerreros que llegan a la ciudad. Allí, éstos, cuentan sus hazañas mientras\n\
beben alcohol en cantidades desmesuradas.\n");
 AddDetail(({"jardin","parque","zona relax"}),
"El mejor lugar para pasar la tarde sin ser molestado. Una zona de hierba con\n\
arboles que durante los dias de sol te dan una agradable sombra.\n");
 AddExit("este",CROWY("pub_guerreros"));
 AddExit("oeste",CROWY("jardin"));
 AddExit("sur",CROWY("calle10"));
 AddExit("norte",CROWY("calle14"));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2)+3);

 SetLocate("Crowy");
}

void init()
{
 ::init();
}