/*
Fichero: ulmo.c
Autor: Aulë
Fecha: 21/07/2013
Descripción: workroom de Ulmo.
*/
#include "./path.h"
#include <sounds.h>
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    SetIntShort("salones de Ulmo");
    SetIntLong("Te encuentras en las estancias de Ulmo, utilizadas por este vala  en las "
    "contadas ocasiones en que abandona su hogar en el mar Exterior para participar en "
    "los concilios de los Valar.\n"
    "Se trata de una inmensa cámara abovedada que reproduce el interior de una "
    "gigantesca caverna submarina.\n"
    "Las paredes de roca irregular, están recubiertas por los fósiles de extrañas "
    "criaturas abisales.\n" 
    "Enormes conchas  y caracolas retorcidas de gran tamaño se distribuyen a distintas "
    "alturas sobre los rocosos muros y el suelo húmedo.\n"
    "El techo, del color del agua profunda, es recorrido por infinidad de siluetas "
    "apenas entrevistas de peces de distintos tipos qque por algún misterioso poder "
    "parecen moverse a lo largo de la pétrea superficie.\n"
    "Intrincados pilares de coral vivo en continuo crecimiento ascienden desde el suelo "
    "cubierto por una capa de algas y pequeñas conchas, arqueándose y retorciéndose "
    "caprichosamente hasta alcanzar en algunos casos el techo, otras las paredes de la "
    "caverna y en otras terminar en el aire.\n"
    "Presidiendo la estancia se adivina un alto trono sostenido por olas talladas en piedra.\n");
    AddDetail("suelo",
    "El suelo es irregular y una espesa alfombra de algas, arena y conchas de cientos de "
    "moluscos y crustáceos lo recubren.\n");
    AddDetail(({"muros", "paredes"}),
    "Los muros de piedra son irregulares y se levantan a varios cientos de metros e "
    "altura, combándose hacia adentro y  afuera.\n"
    "Miles de fósiles marinos los recubren junto con numerosas conchas y caracolas de "
    "gran tamaño.\n");
    AddDetail(({"conchas", "caracolas"}),
    "Situadas a diversas alturas sobre los muros y en el suelo entre los pilares de "
    "coral, enormes conchas de moluscos y crustáceos gigantes con diversos pliegues y "
    "el interior nacarado se entremezclan con caracolas de varios metros de altura y "
    "tortuosas formas, salpicadas por púas óseas.\n");
    AddDetail("techo",
    "Está situado a cientos de metros de altura y se sostiene sobre  tortuosos pilares "
    "de coral vivo.\n"
    "El color de la piedra que lo forma, así como las siluetas apenas entrevistas que "
    "lo recorren, dan la impresión de que sobre tu cabeza se encuentra todo un "
    "océano y tú te hayas en el fondo de una fosa marina.\n");
    AddDetail(({"siluetas", "peces", "criaturas"}),
  "Crees ver toda una legión de criaturas marinas recorriendo el techo como si nadaran: "
 	"anguilas, peces de distintos tipos, pulpos, rayas, cetáceos, medusas....\n");
 	AddDetail(({"pilares", "coral", "corales"}),
 	"Altos pilares retorcidos de coral vivo en continuo crecimiento llegan en algunos "
 	"casos al techo.\n");
 	AddDetail("algas",
 	"Una capa de diversas algas húmedas cubren el piso como si hiciera escasos minutos "
 	"que las aguas del océano se hubieran retirado de esta estancia.\n");
 	AddDetail("olas",
 	"Surgiendo de la pared del fondo de la caverna y como si hubieran sido congeladas en "
 	"pleno movimiento, unas olas de suaves cumbres talladas en piedra verde oscuro "
 	"sostienen un alto sitial de piedra.\n");
 	AddDetail(({"trono", "asiento", "sitial"}),
 	"Este alto sitial está tallado en una sola roca marina extraída de los abismos más "
 	"insondables del océano.\n"
 	"El alto respaldo incrustado de perlas imita la cresta espumosa de una ola y los "
 	"amplios brazos representan sendos peces cuyas innumerables y diminutas escamas, de "
 	"la primera a la última, han sido cuidadosamente cinceladas en la más pura y "
 	"rutilante plata.\n"
 	"Sin duda un magnífico asiento desde el que el Señor de las Aguas puede presidir sus "
 	"salones.\n");
 	AddDetail(({"fosiles", "fósiles"}),
 	"Son fósiles de antiguos animales marinos.\n"
 	 "Los hay de criaturas serpentiformes, conchas de formas tubulares, semicirculares, "
 	 "con forma de abanico, crustáceos de muchas patas...\n");
 	                  SetSoundEnvironment(SOUND_AMBIENTES("cueva_marina_gotas"), 45);

 	 	SetIntSmell("El penetrante aroma   de algas húmedas, llodo y agua salina inunda tus fosas nasales.\n");
 	SetIntNoise("Escuchas el susurro del lejano oleaje acariciando la orilla de distantes "
 	"playas desconocidas.\n");
 	//AddExit("trans", "./trans_endor");
 	SetIntBright(20);
 	AddExit("sur", "./gavenida4");
 	
 	}public void init(){
 		::init();

	write("Penetras en las cavernosas y umbrías estancias de Ulmo, Señor de las Aguas.\n");
}