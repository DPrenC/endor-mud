/****************************************************************************
Fichero: tienda_varios.c
Autor: Riberales
		[T] Tagoras
Creación: 29/09/2005
Descripción: La tienda de varios productos.
[T] 10/03/2009: Añado puerta
				Bajo el brillo a 30, estaba en 75
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

string mostrador();
int cmd_subir();
int QueryTienda();

public void create()
{
    ::create();

    SetIntShort("la tienda de Alibrilla");
    SetLocate("Annufam");
    SetIntLong("Has entrado en la tienda perteneciente a la enana "
               "Alibrilla. Aquí encontrarás gran variedad de "
               "productos, casi todos útiles para cualquier imprevisto. "
               "Observas el mostrador donde Alibrilla recibe a los clientes,"
               "y una escalera para subir al almacén.\n");

    AddDetail("mostrador",SF(mostrador));

    AddDetail(({"escalera","escaleras"}),
              "Es una escalera de madera que comunica la tienda con el almacén que está arriba.\n");

    SetShopkeeper(PNJ_CIUDAD_ANNUFAM("alibrilla"));
    SetIndoors(1);
    SetIntBright(30);
    SetIntSmell("Parece que la tendera le echa algún tipo de ambientador al local, porque huele a incienso.\n");
    AddRoomCmd("subir","cmd_subir");
    AddExit("norte",HAB_UNGRIM_ANNUFAM("ungrim_05"));
	RemoveExit("almacen");
	SetNotifyExits("norte");
	SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_05"));
	AddDoor("norte", "la puerta de la calle", "Es la puerta que da a la calle\n",
		({"puerta de la calle", "puerta del sur", "puerta"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));

    AddArticle("/obj/torch",REFRESH_REMOVE,4);
    AddArticle("/obj/vialv",REFRESH_REMOVE,7);
    AddArticle("/obj/sunglasses",REFRESH_REMOVE,4);
    AddArticle("/obj/bandage",REFRESH_REMOVE,20);
    AddArticle("/obj/bcocina",REFRESH_REMOVE,5);
    //AddArticle(OTRO_ANNUFAM("mochilac"),REFRESH_REMOVE,3);
    AddArticle("/obj/mochila",REFRESH_REMOVE,3);
    AddArticle("/obj/mochila",REFRESH_REMOVE,3);
    AddArticle("/obj/cuerda",REFRESH_REMOVE,4);
}

int cmd_subir(string str)
{
    if (!str) return notify_fail("¿Subir dónde?\n",NOTIFY_NOT_VALID);
    if (member(({"escalera","escaleras","almacen"}),str)<= -1)
    {
        return notify_fail("Subir qué?\n",NOTIFY_NOT_VALID);
    }
    return go_store();
}

string mostrador()
{
    string generico = "Es un mostrador de madera oscura, con algunas notas ininteligibles. ";
    if (QueryShopkeeper())
        return generico + "Tras él observas a la enana Alibrilla.\n";
    return generico+ " No hay nadie detrás de él para poder atenderte.\n";
}
