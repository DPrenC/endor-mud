/*
DESCRIPCION  : campos de trigo de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/campo00.c
MODIFICACION : 
20-02-99 [Angor] Creacion
16-09-07 [Angor] Partes comunes a includes
*/

#include "path.h"
#include AK_MACRO
#include <messages.h>
inherit ROOM;


public int coger_cmd(string str){
 object ob;
 if ((str=="trigo")||(str=="espigas")||(str=="espiga"))
    {
    ob=present(str,TP);
    if (ob) return notify_fail("Tu ya tienes un manojo de espigas de trigo. "
            "Si coges mas seguro que te ve alguien.\n",NOTIFY_NOT_VALID);
    write("Discretamente arrancas un manojo de espigas de trigo.\n");
    tell_room(TO, ({ MSG_SEE, NOMBRE+" arranca un manojo de espigas de trigo.\n"}), ({ TP }));
    ob=clone_object(QUEST+"curandera/espigas");
    ob->move(TP);
    return 1;
    }
    else return 0;
 return 0;
}


create() {
  ::create();
  SetIntShort("los campos de la vega de Gaddaro");
  SetIntLong(
  "Estas en medio de los campos de trigo de la fértil vega de Gaddaro. A tu "
  "alrededor se extiende una gran extension de terreno bien cuidada en la que "
  "los orcos cultivan, probablemente con esclavos, el trigo que sus ciudades "
  "necesitan. Al nordeste de los campo se halla el lago Darum y al suroeste "
  "el inmenso bosque de Talek.\n");

  AddDetail(({"trigo"}),
  "Las plantas de trigo se doblan bajo el peso de sus maduras y doradas "
  "espigas. No crees que tarden ya mucho en recoger la cosecha.\n");

#include "../camino/geografia.ic"
#include "../camino/ambiente.ic"

 SetIntNoise("Oyes a los pajaros cantar.\n");

 AddExit("sur",AZ_CAMINO("camino15"));
 AddExit("este",AZ_CAMINO("camino14"));

 AddRoomCmd("coger","coger_cmd");
}

