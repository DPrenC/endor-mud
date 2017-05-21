/*
DESCRIPCION : destileria del pueblo de Narad
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/narad/destil00.c
MODIFICACION: 16-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include AK_MACRO
#include <colours.h>
#include <properties.h>



inherit SHOP;

create(){
  ::create();
 SetIntShort("la destilería del pueblo de Narad");
  SetIntLong(
    "Estas en la destilería del pueblo. Es un amplio cobertizo de madera situado "
    "a las afueras donde se fabrica el vino y la cerveza que se fabrica en este "
    "pueblo. A tu alrededor puedes ver grandes estanterias llenas de polvorientos "
    "barriles de diversos tamanyos donde se almacena y madura la bebida, desde "
    "pequenyos barriletes hasta grandes tones de mas de dos metros. Si te interesa, "
    "aqui puedes comprar bebida y llevartela. Al oeste de aqui hay otro cobertizo "
    "en el que se encuentra toda la maquinaria empleada en la fabricacion.\n");

 AddDetail(({"tienda","destileria"}),QueryIntLong());

 AddDetail(({"barriles","toneles"}),
 "Toda la destileria esta llena de ellos. En las estanterias hay fijos algunos "
   "inmensos toneles en los que se realiza la fermentacion del vino.\n");

 AddDetail(({"estanterias","productos"}),
 "Las estanterias ocupan gran parte de las paredes. Estan formadas por gruesas "
   "vigas de madera sobre las que se colocan los pesados barriles con la bebida. "
   "Usa "+TC_BOLD+"lista"+TC_NORMAL+" para sabes que productos estan a la venta.\n");

SetIntNoise("Oyes el ruido del alambique operando.\n");
SetIntSmell("Huele a vino y cerveza... Podrias vivir aqui.\n");
SetLocate("villa de Narad");
SetIndoors(1);
SetIntBright(50);

AddExit("este",NARAD("calle05"));
AddExit("oeste",NARAD("destil01"));

CanSell(0);     //El cliente no puede vender a la tienda
CanAppraise(0); //No se valoran objetos
CanIdentify(0); //No se identifican objetos

RemoveDustbin();

SetShopkeeper(0,([P_SHORT:"Foeker el tendero",
P_LONG: "Foeker es un joven orco. Es el encargado de la destileria del pueblo. "
"Tras la cosecha, el es el encargado de hacer el vino y la cerveza empleando "
"para ello el gran alambique de la destileria. El resto del anyo se encarga "
"de vender la bebida fabricada como si de una tienda se tratara.\n",
P_IDS:({NOMBRE,lower_case(NOMBRE),"tendero","orco"}),
P_LEVEL:20,
P_STR:20,
P_CON:25,
P_DEX:4,
P_INT:2
]));

//AddArticle(BEBIDA("botella_vino", REFRESH_REMOVE,4);
//AddArticle(BEBIDA("botella_cerveza", REFRESH_REMOVE,4);
//AddArticle(BEBIDA("barrilete_cerveza", REFRESH_REMOVE,3);
//AddArticle(BEBIDA("barrilete_vino", REFRESH_REMOVE,3);
//AddArticle(BEBIDA("barril_cerveza", REFRESH_REMOVE,1);
//AddArticle(BEBIDA("barril_vino", REFRESH_REMOVE,1);
}

