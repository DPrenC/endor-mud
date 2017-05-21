//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   barracon.c                        *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 04.11.98                  *
//* Modificacion: 04.11.98              *
//* Agradecimientos: Guy Gates          *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
#include <properties.h>
#include <materials.h>
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("el barrracón de la puerta norte de Kha-annu");
 SetIntLong("Entras al barracon de la puertas del norte, de Kha-annu, "
 "no ves mas que un par de sillas, un par de camastros y una escupidera.\n"
 "La verdad es que no esta muy limpio, pero siendo un barracon te parece "
 "normal. Al fondo hay un pequenyo fogon donde un cazuela bulle algun tipo "
 "de caldo. Las paredes estan llenas de grabados y hay un par de faroles que.\n"
 "las iluminan.\n");

 SetIndoors(1);
 SetIntBright(50);
 SetIntNoise("No oyes nada fuera de lo normal.\n");
 SetIntSmell("Huele a sudor y a cerrado, normal con tanto hombreton.\n");
 SetLocate("Kha-annu");

 AddDetail(({"pared","grabado","paredes"}),
 "Hay un gran grabado en la pared que representa un grupo de enanos luchando "
 "nada mas y nada menos contra un dragon.\n");

  AddItem(MONS+"guardia2",REFRESH_DESTRUCT,2);
  AddItem(MONS+"guardia",REFRESH_DESTRUCT,1);

 AddDetail(({"farol","farolas"}),
 "Son un par de farolas colocadas estrategicamente a los lados para alumbrar "
 "toda la estancia.\n");
    AddExit("oeste","./hall3");
    AddDoor("oeste","la puerta del hall",
        "Es una puerta de hierro, que comunica el hall con la garita de vigilancia.\n",
        ({"puerta","puerta de hall","puerta del hall"}), GENDER_FEMALE,
        ([P_MATERIAL:M_HIERRO,P_DOOR_STATE:DOOR_CLOSED]));
}
