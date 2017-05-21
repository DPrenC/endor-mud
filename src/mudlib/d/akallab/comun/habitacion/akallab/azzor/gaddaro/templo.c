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
   "hierbas arom�ticas que como ofrenda arden lentamente en peque�as piras "
   "inunda el ambiente. El templo en si es una construcci�n circular de mediano "
   "tama�o dedicada a la diosa Sinnae cuya estatua puedes ver en su centro. "
   "En la pared exterior hay excavadas peque�as capillas dedicadas a otros "
   "dioses.\n");

 AddDetail(({"pira","piras","hierbas"}),
 "En algunos lugares del templo hay varias peque�as piras humeantes. Son "
 "cuencos de arcilla en cuyo interior arden lentamente hierbas "
 "arom�ticas. Son un ofrenda de algun creyente a sus dioses.\n");

 AddDetail(({"altar"}),
 "El altar es una especie de gruesa plancha de piedra de forma circular y "
 "aproximadamente un metro de altura. Esa profusamente decorada con tallas "
 "que representan todo tipo de s�mbolos y figuras. Sobre el altar se encuentra "
 "una estatua que representa a Sinnae, diosa del Agua y la Tormenta.\n");

 AddDetail(({"estatua","sinnae","Sinnae"}),
 "La estatua que hay sobre el altar central del templo representa a la diosa "
 "Sinnae. Segun la mitolog�a orca, Sinnae es la diosa del Agua y la Tormenta."
 "Esta casada con Tanat, dios del Fuego. Suele ser venerada en pueblos que, "
 "como este, dependen de la agricultura para su subsistencia. La estatua que "
 "ves representa a una orca corpulenta que lleva en un brazo el martillo de "
 "la tormenta y en la otra un peque�o recipiente con agua.\n");

 AddDetail(({"capilla","capillas"}),
 "Excavadas en la pared exterior del templo hay varias peque�as capillas "
 "o huecos. En ellas se han colocado peque�as estatuas que representan a "
 "dioses menores o locales a los que los habitantes del pueblo prestan "
 "culto. Frente a algunas de las capillas observas ofrendas.\n");

 AddDetail(({"ofrendas"}),
 "Son objetos sin mas valor que el simb�lico que un creyente deja frente al "
 "altar del dios al que venera como muestra de una promesa o petici�n. "
 "Los orcos tienen la costumbre realizar ofrendas de sangre a los dioses "
 "si sus ruegos son escuchados. Estas ofrendas que ves frente a algunas "
 "capillas son el s�mbolo de esos compromisos.\n");

SetIntNoise("El silencio preside este lugar.\n");
SetIntSmell("Hmm.. huele a hierbas aromaticas.\n");
SetLocate("pueblo de Gaddaro");
SetIndoors(1);
SetIntBright(50);

AddExit("este",GADDARO("calle05"));
}
