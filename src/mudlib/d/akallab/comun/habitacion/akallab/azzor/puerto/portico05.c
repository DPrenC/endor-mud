 /*
DESCRIPCION : bajo el portico de la taberna de Sally en el puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/portico05.c
MODIFICACION: 08-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <door.h>
#include <nightday.h>
inherit ROOM;

create(){
 ::create();
SetIntShort("el pórtico de la taberna de Sally");
 SetIntLong(
   "Te hallas bajo el pórtico del edificio donde se encuentra la "
   "conocida taberna de Sally la gorda, una orca con fama de descarada, "
   "pendenciera, juerguista, ladrona y muchas otras cosas más. Dicen las "
   "malas lenguas que cuando hace tiempo le ganó en el juego la taberna "
   "a su antiguo dueño hubo más trampa que suerte. Es una taberna "
   "bastante conocida y la bebida no esta muy aguada. La puerta de la "
   "taberna queda justo al oeste de aquí.\n");

#include "puerto_detail.h"

 AddDetail(({"puerta"}),
   "La puerta de la taberna queda justo al Oeste de aquí.\n");

 AddDetail(({"taberna","edificio"}),
  "Es un edificio bajo y de no muy buen aspecto. La "
  "taberna es una de las más conocidas de la ciudad, tanto por su bebida "
  "como por las peleas que continuamente se producen.\n");

   SetIndoors(1);
   SetIntBright(50);

   AddExit("este",AZ_PUERTO("muelle05"));
   AddExit("norte",AZ_PUERTO("portico04"));
   AddExit("oeste",AZ_TABERNA("sally/barra"));
   AddExit("sur",AZ_PUERTO("portico06"));
    AddDoor("oeste","la puerta de la taberna",
        "Es una gruesa puerta de madera, barnizada y decorada, elegante , pero resistente.\n",
        ({"puerta","puerta taberna","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_DAWN,ND_SUNRISE,ND_PRENOON,ND_DAY}),
            P_DOOR_CANT_OPEN_MSG:({({"La taberna cierra al alba, y abrirá por la tarde, espera "
                "un poco para emborracharte...\n","Buscas la puerta en la oscuridad, pero no "
                "logras encontrarla... Cuidado al moverte, no vayas a caerte al mar.\n"}),
                ({"@nombre@ pensaba meterse un lingotazo, pero la taberna está cerrada...\n",
                "Oyes a alguien rebuscar, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
}
