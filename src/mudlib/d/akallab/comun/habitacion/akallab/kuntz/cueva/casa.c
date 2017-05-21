/*
DESCRIPCION  : (modelo) casa-cueva en la Gran Caverna Troll
FICHERO      : /d/akallab/comun/rooms/akallab/kuntz/cueva/casa.c
MODIFICACIOna N :
21-10-98 [Angor@Simauria] Creacion
11-12-99 [Angor@Simauria] Anyadidos los frutos
*/

#include "path.h"
inherit ROOM;

int gente;  //hay gente en la casa: no[0], si[1]

create() {
  ::create();
  SetIntShort("una casa en una cueva");
  SetIntLong(
     "Te encuentras en una pequenya cueva que algun troll ha habilitado como su casa. "
     "La cueva esta practicamente vacia excepto por un camastro que hay en un rincon "
     "hecho con un monton de hierba seca. Unas marcas en la pared indentifican al "
     "propietario de esta cueva. El olor a troll es bastante fuerte.\n");

  AddDetail(({"cueva"}), QueryIntLong());

  AddDetail(({"camastro","monton","cama"}),
     "Es un monton de hierba seca que se halla en un rincon de la cueva. Es el lugar "
     "donde duerme el propietario de la cueva.\n");

  AddDetail(({"marcas"}),
     "Junto a la entrada de la cueva hay unas extranyas marcas talladas en la pared. "
     "Son la marca personal que identifica a un troll dado entre el resto de la tribu "
     "y aqui sirven para identificar al propietario de la cueva.\n");

 SetIntNoise("Oyes el goteo del agua.\n");
 SetIntSmell("Huele.... a troll!!.\n");
 SetLocate("cavernas Troll en Kuntz");
 SetIndoors(1);
 SetIntBright(0);

 if (gente==1){
    AddItem(PNJ("std/troll"), REFRESH_DESTRUCT, random(4));
    }

 if (random(2)==0){//50%
    AddItem(COMIDA("frutos_bosque"), REFRESH_DESTRUCT,1);
    }

}