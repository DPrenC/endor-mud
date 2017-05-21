/*
DESCRIPCION : templo del pueblo de Narad
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/narad/tienda.c
MODIFICACION: 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
 ::create();
 SetIntShort("el templo del pueblo de Narad");
 SetIntLong(
   "Te hallas en el interior del templo del pueblo de Narad. Este templo esta "
   "dedicado a la diosa madre Nabira, aunque dada la ocupacion agricola del "
   "pueblo a quien realmente veneran es a Sinnae, diosa del Agua y la Tormenta. "
   "El templo es una construccion circular de mediano tamanyo, en cuyo centro "
   "se halla el altar con una estatua de Nabira. En la pared exterior hay "
   "excavadas pequenyas capillas dedicadas a otros dioses.\n");

 AddDetail(({"altar"}),
 "El altar es una especie de gruesa plancha de piedra de forma circular y "
   "aproximadamente un metro de altura. Esa profusamente decorada con tallas "
   "que representan todo tipo de simbolos y figuras. Sobre el altar se encuentra "
   "una estatua que representa a Nabira, diosa de la Noche y madre de todos los "
   "orcos.\n");

 AddDetail(({"estatua","nabira","Nabira"}),
 "La estatua que hay sobre el altar central del templo representa a la diosa "
   "Nabira. Segun la mitologia orca, Nabira es la diosa de la Noche y esta "
   "casada con el gran dios Kavar. Se la considera la diosa madre de todos los "
   "orcos. La estatua que ves representa a una orca corpulenta cubierta por "
   "una oscura capa protectora que la cubre casi por completo. Su semblante es "
   "sereno y seco.\n");

 AddDetail(({"sinnae","Sinnae"}),
 "Sinnae es la diosa del Agua, la Tormenta y la Lluvia. Segun la mitologia "
   "esta casada Thanat, hijo de Kavar y Nabira. Como este pueblo vive de lo "
   "que producen sus campos, es la diosa mas venerada y por eso observas "
   "numerosas ofrendas frente a la capilla de la estatua que la representa.\n");

 AddDetail(({"capilla","capillas"}),
 "Excavadas en la pared exterior del templo hay varias pequenyas capillas "
   "o huecos. En ellas se han colocado pequenyas estatuas que representan a "
   "dioses menores o locales a los que los habitantes del pueblo prestan "
   "culto. Frente a algunas de las capillas observas algunas ofrendas.\n");

 AddDetail(({"ofrendas"}),
 "Son objetos sin mas valor que el simbolico que un creyente deja frente al "
   "altar del dios al que venera como muestra de una promesa o peticion. "
   "Los orcos tienen la costumbre realizar ofrendas de sangre a los dioses "
   "si sus ruegos son escuchados. Estas ofrendas que ves frente a algunas "
   "capillas son el simbolo de esos compromisos.\n");

SetIntNoise("El silencio preside este solitario lugar.\n");
SetIntSmell("Hmm.. el ambiente es seco y algo polvoriento.\n");
SetLocate("villa de Narad");
SetIndoors(1);
SetIntBright(50);

AddExit("norte",NARAD("calle03"));
}
