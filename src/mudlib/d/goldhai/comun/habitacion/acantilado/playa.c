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
  write("Te adentras en la cueva y empiezas a subir. Ves una antorcha y la coges. Despu�s de "
  	"un buen rato subiendo, agradeces de todo coraz�n que el camino de ascenso no se bifurque, "
  	"y despu�s de otro buen rato subiendo, llegas al fin a ver la luz al fondo del tunel. Sales "
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
 SetIntLong("Est�s en una playa en el fondo de un enorme acantilado. Paseas la vista por "
 	"la zona y ves una oscura cueva. La pared del precipicio es bastante lisa y, en las "
 	"alturas, ves un saliente. M�s arriba, bastante m�s arriba, ves el filo del acantilado.\n");

 AddDetail(({"acantilado","precipicio"}), "Es un enorme acantilado. Ves un saliente m�s o menos "
 	"hacia la mitad de su altura.\n.\n");
 AddDetail(({"mar","oceano","agua"}), "Desde aqu� ves c�mo las olas rompen r�tmicamente en la "
 	"playa.\n");
 AddDetail("saliente", "Ves un saliente rocoso en medio del acantilado.\n");

 AddExit("cueva", SF(cmd_cueva));
 SetSoundEnvironment(SND_AMBIENTES("olas"));
 SetLocate("playa del acantilado del suroeste de Goldhai");
}