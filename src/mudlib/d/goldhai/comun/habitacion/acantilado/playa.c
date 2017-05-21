/*=============================================================*
 |           << GOLDHAI.Saliente [t] Theuzifan >>              |
 *=============================================================*
 |            Creacion.................. 23-03-00              |
 |            Ultima Modificacion....... 23-03-00              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <sounds.h>


inherit GROOM;


int cmd_cueva(string str)
{
  write("Te adentras en la cueva y empiezas a subir. Ves una antorcha y la coges. Después de "
  	"un buen rato subiendo, agradeces de todo corazón que el camino de ascenso no se bifurque, "
  	"y después de otro buen rato subiendo, llegas al fin a ver la luz al fondo del tunel. Sales "
  	"al exterior y dejas la antorcha.\n");

  if (!TP->QueryInvis())
  {
    say(TP->QueryName()+" se mete en la cueva.\n");
    TP->move(ACANTILADO("acantilado_norte6"), M_GO, "Por entre los arbustos ves aparecer a "+
  	TP->QueryName()+".\n");
  }
  else
    TP->move(ACANTILADO("acantilado_norte6"), M_SILENT);
  return 1;
}


create()
{
 ::create();
 SetIndoors(0);
 SetIntShort("la playa");
 SetIntLong("Estás en una playa en el fondo de un enorme acantilado. Paseas la vista por "
 	"la zona y ves una oscura cueva. La pared del precipicio es bastante lisa y, en las "
 	"alturas, ves un saliente. Más arriba, bastante más arriba, ves el filo del acantilado.\n");

 AddDetail(({"acantilado","precipicio"}), "Es un enorme acantilado. Ves un saliente más o menos "
 	"hacia la mitad de su altura.\n.\n");
 AddDetail(({"mar","oceano","agua"}), "Desde aquí ves cómo las olas rompen rítmicamente en la "
 	"playa.\n");
 AddDetail("saliente", "Ves un saliente rocoso en medio del acantilado.\n");

 AddExit("cueva", SF(cmd_cueva));
 SetSoundEnvironment(SND_AMBIENTES("olas"));
 SetLocate("playa del acantilado del suroeste de Goldhai");
}