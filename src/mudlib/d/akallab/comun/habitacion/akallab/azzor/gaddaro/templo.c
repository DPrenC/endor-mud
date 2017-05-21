/*
DESCRIPCION : templo del pueblo de Gaddaro
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/templo.c
MODIFICACION: 24-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
 ::create();
 SetIntShort("el templo del pueblo de Gaddaro");
 SetIntLong(
   "Te hallas en el interior del templo del pueblo de Gaddaro. El olor de las "
   "hierbas aromáticas que como ofrenda arden lentamente en pequeñas piras "
   "inunda el ambiente. El templo en si es una construcción circular de mediano "
   "tamaño dedicada a la diosa Sinnae cuya estatua puedes ver en su centro. "
   "En la pared exterior hay excavadas pequeñas capillas dedicadas a otros "
   "dioses.\n");

 AddDetail(({"pira","piras","hierbas"}),
 "En algunos lugares del templo hay varias pequeñas piras humeantes. Son "
 "cuencos de arcilla en cuyo interior arden lentamente hierbas "
 "aromáticas. Son un ofrenda de algun creyente a sus dioses.\n");

 AddDetail(({"altar"}),
 "El altar es una especie de gruesa plancha de piedra de forma circular y "
 "aproximadamente un metro de altura. Esa profusamente decorada con tallas "
 "que representan todo tipo de símbolos y figuras. Sobre el altar se encuentra "
 "una estatua que representa a Sinnae, diosa del Agua y la Tormenta.\n");

 AddDetail(({"estatua","sinnae","Sinnae"}),
 "La estatua que hay sobre el altar central del templo representa a la diosa "
 "Sinnae. Segun la mitología orca, Sinnae es la diosa del Agua y la Tormenta."
 "Esta casada con Tanat, dios del Fuego. Suele ser venerada en pueblos que, "
 "como este, dependen de la agricultura para su subsistencia. La estatua que "
 "ves representa a una orca corpulenta que lleva en un brazo el martillo de "
 "la tormenta y en la otra un pequeño recipiente con agua.\n");

 AddDetail(({"capilla","capillas"}),
 "Excavadas en la pared exterior del templo hay varias pequeñas capillas "
 "o huecos. En ellas se han colocado pequeñas estatuas que representan a "
 "dioses menores o locales a los que los habitantes del pueblo prestan "
 "culto. Frente a algunas de las capillas observas ofrendas.\n");

 AddDetail(({"ofrendas"}),
 "Son objetos sin mas valor que el simbólico que un creyente deja frente al "
 "altar del dios al que venera como muestra de una promesa o petición. "
 "Los orcos tienen la costumbre realizar ofrendas de sangre a los dioses "
 "si sus ruegos son escuchados. Estas ofrendas que ves frente a algunas "
 "capillas son el símbolo de esos compromisos.\n");

SetIntNoise("El silencio preside este lugar.\n");
SetIntSmell("Hmm.. huele a hierbas aromaticas.\n");
SetLocate("pueblo de Gaddaro");
SetIndoors(1);
SetIntBright(50);

AddExit("este",GADDARO("calle05"));
}
