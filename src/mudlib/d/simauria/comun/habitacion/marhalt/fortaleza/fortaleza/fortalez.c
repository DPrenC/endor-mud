/*
DESCRIPCION  : Habitacion base de la fortaleza
FICHERO      : fortalez.c
MODIFICACION : 10-07-00 [Maler] Creacion
*/

#include "path.h"
inherit SIM_ROOM;

AnyadirPnjs(){
switch(random(90))
    {
        case 0..4:AddItem(PNJFF("bandido"),REFRESH_DESTRUCT,1);break;
        case 5..9:AddItem(PNJFF("bandorco"),REFRESH_DESTRUCT,1);break;
        case 10..14:AddItem(PNJFF("sargento"),REFRESH_DESTRUCT,1);break;
        case 15..29:AddItem(PNJFF("mercenar"),REFRESH_DESTRUCT,1);break;
        case 30..34:AddItem(PNJFF("conjurat"),REFRESH_DESTRUCT,1);break;
        case 35..39:AddItem(PNJFF("ladron"),REFRESH_DESTRUCT,1);break;
        case 40..44:AddItem(PNJFF("perro"),REFRESH_DESTRUCT,1);break;
        case 45..49:AddItem(PNJFF("soldado"),REFRESH_DESTRUCT,1);break;
        case 50..54:AddItem(PNJFF("capitan"),REFRESH_DESTRUCT,1);break;
        default:break;
    }
}

create()
{
    ::create();

    SetIntShort("la fortaleza de Cored");
    SetIntLong("Estás en la fortaleza de Cored. La fortaleza está en muy buen "
    "estado, pese a llevar mucho tiempo abandonada. Fruto de su abandono, un tupido "
    "bosque ha crecido alrededor de ella.\n");
    SetIntNoise("Oyes pisadas metálicas.\n");
    SetIntSmell("Huele bastante mal.\n");
    SetIndoors(0);
    AddDetail(({"bosque","bosque de la fortaleza"}),
    "Es un bosque de mediano tamaño que se extiende en la parte norte "
       "de Nandor. Es un bosque no muy denso habitado principalmente por "
  	   "bandidos e indeseables de este tipo. Si no fuera por la chusma que "
  	   "lo habita, sería un lugar muy agradable.\n");
    SetLocate("fortaleza de Cored");
}
