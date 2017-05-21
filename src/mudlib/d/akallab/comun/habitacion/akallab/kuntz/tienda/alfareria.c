/*
DESCRIPCION : cueva del alfarero troll
FICHERO     : /d/akallab/comun/habitacion/akallab/kuntz/tienda/alfareria.c
MODIFICACION: 23-11-99 [Angor@Simauria] Creacion
*/

#include "./path.h"
#include AK_MACRO
#include <properties.h>



inherit SHOP;

//#define NOMBRE          (TP->QueryName())
//#define NOMBRE_MAY      (capitalize NOMBRE)
//#define SUF             (TP->QueryGender()==GENDER_FEMALE?"a":"o")

create()
{
 ::create();
 SetIntShort("la cueva del alfarero");
 SetIntLong(
   "En esta cueva habita un alfarero troll. En el centro de la cueva se "
     "encuentra una pequenya fogata en cuyas cenizas el alfarero entierra "
	 "los objetos de ceramica que fabrica para que se endurezcan con el "
	 "calor. Junto a la fogata se halla un pequenyo y tosco torno de "
	 "madera donde trabaja el alfarero.\n");

AddDetail(({"cueva"}),QueryIntLong());

AddDetail(({"fogata","fuego"}),
  "Una pequenya fogata se encuentra en el centro de la cueva. Ademas de "
    "caldear el ambiente sirve para que el alfarero entierre en sus "
	"calientes cenizas las piezas de ceramica que realiza para que se "
	"endurezcan con el calor.\n");

AddDetail(({"torno","eje","plataformas","plataforma"}),
  "El torno es un pequenyo y tosco aparato de madera que utiliza el "
    "para relizar su trabajo. Esta compuesto por dos pequenyas "
	"plataformas circulares de madera unidas por un eje. Una de ellas "
	"se apoya en el suelo, mientras que la otra gira sobre la primera "
	"gracias al eje.\n");

SetIntNoise("Oyes el crepitar de las brasas.\n");
SetIntSmell("Huele.... a troll!!.\n");
SetLocate("cavernas Troll en Kuntz");
SetIndoors(1);
SetIntBright(30);

AddExit("sudeste",K_CUEVA("caverna14"));

//AddItem(PNJ("k_cueva/guardia"), REFRESH_DESTRUCT);
AddArticle(OTRO("cuenco"),REFRESH_REMOVE,3);
AddArticle(OTRO("tinaja"),REFRESH_REMOVE,1);

CanSell(0);     //El cliente no puede vender a la tienda
CanAppraise(0); //No se valoran objetos
CanIdentify(0); //No se identifican objetos

//ForbidShopkeeper();  // 1 & elimina tendero
//AllowShopkeeper();  // 0 & tendero automatico

RemoveDustbin();
SetShopkeeper(0,([P_SHORT:"Narg el alfarero",
P_LONG:  "Narg es un viejo troll. Su cuerpo esta surcado de feas cicatrices "
         "producto de una juventud muy activa a la que consiguio sobrevivir. "
		 "Se gana la vida y un puesto en la tribu realizando toscos pero "
		 "utiles objetos de ceramica.\n",
P_IDS:({"narg","Narg","alfarero","tendero","troll"}),
P_LEVEL:10,
P_STR:10,
P_CON:10,
P_DEX:2,
P_INT:1,
P_GENDER:GENDER_MALE
]));

}
