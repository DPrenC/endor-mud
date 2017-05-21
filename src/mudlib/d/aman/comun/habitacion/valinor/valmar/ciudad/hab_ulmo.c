/*
Fichero: ulmo.c
Autor: Aul�
Fecha: 21/07/2013
Descripci�n: workroom de Ulmo.
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
    "Se trata de una inmensa c�mara abovedada que reproduce el interior de una "
    "gigantesca caverna submarina.\n"
    "Las paredes de roca irregular, est�n recubiertas por los f�siles de extra�as "
    "criaturas abisales.\n" 
    "Enormes conchas  y caracolas retorcidas de gran tama�o se distribuyen a distintas "
    "alturas sobre los rocosos muros y el suelo h�medo.\n"
    "El techo, del color del agua profunda, es recorrido por infinidad de siluetas "
    "apenas entrevistas de peces de distintos tipos qque por alg�n misterioso poder "
    "parecen moverse a lo largo de la p�trea superficie.\n"
    "Intrincados pilares de coral vivo en continuo crecimiento ascienden desde el suelo "
    "cubierto por una capa de algas y peque�as conchas, arque�ndose y retorci�ndose "
    "caprichosamente hasta alcanzar en algunos casos el techo, otras las paredes de la "
    "caverna y en otras terminar en el aire.\n"
    "Presidiendo la estancia se adivina un alto trono sostenido por olas talladas en piedra.\n");
    AddDetail("suelo",
    "El suelo es irregular y una espesa alfombra de algas, arena y conchas de cientos de "
    "moluscos y crust�ceos lo recubren.\n");
    AddDetail(({"muros", "paredes"}),
    "Los muros de piedra son irregulares y se levantan a varios cientos de metros e "
    "altura, comb�ndose hacia adentro y  afuera.\n"
    "Miles de f�siles marinos los recubren junto con numerosas conchas y caracolas de "
    "gran tama�o.\n");
    AddDetail(({"conchas", "caracolas"}),
    "Situadas a diversas alturas sobre los muros y en el suelo entre los pilares de "
    "coral, enormes conchas de moluscos y crust�ceos gigantes con diversos pliegues y "
    "el interior nacarado se entremezclan con caracolas de varios metros de altura y "
    "tortuosas formas, salpicadas por p�as �seas.\n");
    AddDetail("techo",
    "Est� situado a cientos de metros de altura y se sostiene sobre  tortuosos pilares "
    "de coral vivo.\n"
    "El color de la piedra que lo forma, as� como las siluetas apenas entrevistas que "
    "lo recorren, dan la impresi�n de que sobre tu cabeza se encuentra todo un "
    "oc�ano y t� te hayas en el fondo de una fosa marina.\n");
    AddDetail(({"siluetas", "peces", "criaturas"}),
  "Crees ver toda una legi�n de criaturas marinas recorriendo el techo como si nadaran: "
 	"anguilas, peces de distintos tipos, pulpos, rayas, cet�ceos, medusas....\n");
 	AddDetail(({"pilares", "coral", "corales"}),
 	"Altos pilares retorcidos de coral vivo en continuo crecimiento llegan en algunos "
 	"casos al techo.\n");
 	AddDetail("algas",
 	"Una capa de diversas algas h�medas cubren el piso como si hiciera escasos minutos "
 	"que las aguas del oc�ano se hubieran retirado de esta estancia.\n");
 	AddDetail("olas",
 	"Surgiendo de la pared del fondo de la caverna y como si hubieran sido congeladas en "
 	"pleno movimiento, unas olas de suaves cumbres talladas en piedra verde oscuro "
 	"sostienen un alto sitial de piedra.\n");
 	AddDetail(({"trono", "asiento", "sitial"}),
 	"Este alto sitial est� tallado en una sola roca marina extra�da de los abismos m�s "
 	"insondables del oc�ano.\n"
 	"El alto respaldo incrustado de perlas imita la cresta espumosa de una ola y los "
 	"amplios brazos representan sendos peces cuyas innumerables y diminutas escamas, de "
 	"la primera a la �ltima, han sido cuidadosamente cinceladas en la m�s pura y "
 	"rutilante plata.\n"
 	"Sin duda un magn�fico asiento desde el que el Se�or de las Aguas puede presidir sus "
 	"salones.\n");
 	AddDetail(({"fosiles", "f�siles"}),
 	"Son f�siles de antiguos animales marinos.\n"
 	 "Los hay de criaturas serpentiformes, conchas de formas tubulares, semicirculares, "
 	 "con forma de abanico, crust�ceos de muchas patas...\n");
 	                  SetSoundEnvironment(SOUND_AMBIENTES("cueva_marina_gotas"), 45);

 	 	SetIntSmell("El penetrante aroma   de algas h�medas, llodo y agua salina inunda tus fosas nasales.\n");
 	SetIntNoise("Escuchas el susurro del lejano oleaje acariciando la orilla de distantes "
 	"playas desconocidas.\n");
 	//AddExit("trans", "./trans_endor");
 	SetIntBright(20);
 	AddExit("sur", "./gavenida4");
 	
 	}public void init(){
 		::init();

	write("Penetras en las cavernosas y umbr�as estancias de Ulmo, Se�or de las Aguas.\n");
}