/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-02-97                |
 |               Ultima Modificacion.. 25-01-99                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>


inherit GROOM;
inherit GRAF;

int este_();

create()
{
 ::create();
 SetIntShort("un callejón");
 SetIntLong(
"Te encuentras en uno de los callejones de la ciudad de Crowy. La luz es\n\
tenue y no se ve mucho. Unas ratas corretean de un lado para otro sin saber\n\
muy bien a donde ir, mientras, los gatos contemplan siempre al acecho. Unas\n\
enormes cajas de madera te impiden seguir más hacia el Este, aunque de todas\n\
formas no hay nada de interés que te infunda ir en esa dirección. Si vas hacia\n\
el Oeste llegarás a una gran calle llena de gente. Una enorme pared blanca te\n\
inspira a pintar algo ahí.\n");
 SetIndoors(0);
 SetIntNoise(
"Solo oyes el ruido que hacen las ratas al corretear.\n");
 SetIntSmell(
"Hace un olor bastante fuerte, pero eres incapaz de saber que es.\n");
 AddDetail(({"rata","ratas"}),
"Hay decenas de ellas por todas partes, y si no tienes cuidado seguro que\n\
tarde o temprano pisarás una de ellas.\n");
 AddDetail(({"caja","cajas","cajones"}),
"Unas grandes cajas de madera te impiden ir hacia el este.\n");
 AddExit("oeste",CROWY("calle1"));
 AddExit("este",SF(este_));
 AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT: "una espada de hojalata",
      P_LONG:  "Es una espada normal de hojalata. No creo que te sirva de mucho.\n",
      P_IDS: ({"espada","espada de hojalata"}),
      P_WC: 2,
      P_WEIGHT: 1000,
      P_GENDER: GENERO_FEMENINO,
      P_NUMBER: NUMERO_SINGULAR,
      P_WEAPON_TYPE:WT_ESPADA,
      P_DAM_TYPE:DT_SLASH]));
 HideExit("este",1);
 SetGrafPlaces(({"la pared","pared"}));
 SetLocate("crowy");
}

void init()
{
 ::init();
 add_graf_commands();
}

int este_()
{
 write("No puedes ir en esa dirección, las cajas te lo impiden.\n");
 say(CAP(TNREAL)+" intenta ir hacia el Este, pero unas cajas se lo impiden.\n");
 return 1;
}