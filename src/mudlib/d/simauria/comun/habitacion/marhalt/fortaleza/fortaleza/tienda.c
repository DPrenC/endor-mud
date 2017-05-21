/*=============================================================*
 |       << SIMAURIA:fortaleza  [m] Maler Creacion >>          |
 *=============================================================*
 |               Creacion............. 16-7-00                 |
 |    [z] Zomax 23-02-2003:                                    |
 |    Hago que no salude a invisibles ni si est�               |
 |    tamara viva puedan usarla como saco de pelea para        |
 |    entrenar habilidades.                                    |
 |                                                             |
 *=============================================================*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

object art1, art2, art3;

create(){

    ::create();

    SetIntShort("la tienda de Tamara");
    SetIntLong("Est�s en la tienda de Tamara, aqu� puedes comprar y vender art�culos. "
 	"La tienda est� muy ordenada, y en ella puedes ver a Tamara, una impresionante "
 	"humana pelirroja, que est�, como siempre, atareada colocando art�culos y limpiando "
 	"la tienda.\n");
    SetIntBright(35);
    SetIntSmell("Huele un poco raro, pero puedes distinguir claramente un fuerte olor a "
 	"resinas o algo as�.\n");
    SetDynamic(100);
    SetMinCash(100000);
    SetBuyFactor(400); // pagas el 400% del valor... mola ;)
    AddExit("sur",ROOMFF("patio05"));
    RemoveExit("almacen");
    AddDoor("sur", "la puerta de salida",
    "Es la puerta que sale al patio de la fortaleza.\n",
    ({"puerta", "puerta de salida", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./patio05");
    SetNotifyExits("sur");
    SetNotifyCloseMsg("@name@ sale de la tienda, y tras cerrar la puerta con llave, "
    "se va hacia el oeste.\n");
    SetNotifyOpenMsg("@name@ llega del oeste, abre la tienda y se mete dentro casi "
    "sin mirar.\n");
// creamos tres objetos directamente...

    art1=clone_object("/std/weapon");
    art1->SetStandard(WT_CUCHILLO, 1, P_SIZE_MEDIUM, M_ACERO);
    art1->SetShort("un cuchillo de cocina");
    art1->SetLong("Un cuchillo de cocina con empu�adura de madera.\n");
    art1->SetDamType(DT_PIERCE);

    art2=clone_object("/std/weapon");
    art2->SetStandard(WT_HACHA, 5, P_SIZE_MEDIUM, M_ACERO);
    art2->SetShort("un hacha de le�ador");
    art2->SetLong("Una simple hacha de le�ador, bien afilada, con la que puedes cortar �rboles.\n");

    art3=clone_object("/std/weapon");
   art3->SetStandard(WT_MAZA, 4, P_SIZE_MEDIUM, M_MADERA);
    art3->SetShort("una maza de madera");
    art3->SetLong("Una maza de madera, �til para clavar clavos.\n");

    AddArticle(OTRO("cuerda"), REFRESH_REMOVE,1);
    AddArticle("/obj/torch", REFRESH_REMOVE,d4());
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,d3());
    AddArticle("/obj/bcocina", REFRESH_REMOVE, 10);
    AddArticle("/obj/lighter", REFRESH_REMOVE, d2());
    AddArticle(art1, REFRESH_REMOVE, 1);
    AddArticle(art2, REFRESH_REMOVE,1);
    AddArticle(art3, REFRESH_REMOVE, 1);
    AddArticle(PROT("amuleto"), REFRESH_REMOVE, 1);
    AddArticle(ARMA("cadena"));
    AddArticle(ARMA("vara"));
    AddArticle(ARMA("latigo"));
    AddArticle(ARMA("espada"));
    AddArticle(ARMA("espada2"));
    AddArticle(ARMA("arma_rnd"),REFRESH_REMOVE,2);
    AddArticle(PROT("anillo"));
    AddArticle(PROT("guantes"), REFRESH_REMOVE, 1);
// [Nemesis] A�adido temporal hasta que est� abierta la zona de contrabandistas
    //AddArticle(OTRO("lente"), REFRESH_REMOVE, 1);
    AddArticle("/obj/candle", REFRESH_REMOVE,d4());
AddDetail(({"tienda","tienda de Nandor"}),
    "La tienda es como cualquier tienda, es una especie de "
    "supermercado en el que se vende casi de todo.\n");
    SetLocate("Cored");
    SetShopkeeper(QUEST+"/tamara/tamara");

    AddRoomCmd("matar","fmatar");
    AddRoomCmd("cegar","fmatar");
    AddRoomCmd("cortar","fmatar");
    AddRoomCmd("acuchillar","fmatar");
}

void init(){
  ::init();

  if(!TP->QueryInvis())
  	SkSay("Hola "+TNAME+", bienvenid"+(TP->QueryGenderEndString())+" a mi tienda.\n");
}

public int fmatar(string str)
{
	if (!str) return 0;
	else if ((strstr(lower_case(str),"tamara") != -1) || (strstr(lower_case(str),"tender") != -1) || (strstr(lower_case(str),"human") != -1))
 	{
 		tell_room(TO,W(capitalize(TP->QueryName())+" se abalanza sobre Tamara con intenciones "
		"hostiles pero de repente se detiene y se calma.\n"),(({TP})));
		tell_object(TP,W("Te abalanzas sobre Tamara con intenciones hostiles. De repente, Tamara te mira "
		"asustada. Ves el miedo en sus perfectos ojos azules, y, sin saber porqu�, detienes tu ataque y "
		"pides disculpas.\n"));
		return 1;
	}
}
