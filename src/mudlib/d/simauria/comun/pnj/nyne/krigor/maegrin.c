/* **************************************************************************
[Chs] Chaos@Simauria.upv.es
[n] Nemesis@simauria.upv.es
   ARCHIVO:		Maegrin.c
   DESCRIPCION:		El enfermo al ke hay ke dar el medicamento
   MODIFICACIONES:
   [Chs] 19-04-00 Creacion
   [n] Abr'02 Repasa y castellaniza la descripción.
              Por cierto, sé que es "reúma", pero reuma le da un
	      cierto "color" que le va bien al pnj...
	      (no rompáis el diptongo al pronunciarlo y entenderéis lo que digo)
*/

#include <properties.h>

#include <colours.h>
#include "./path.h"

inherit NPC;

create(){
    ::create();

    SetStandard("maegrin","humano",11,GENERO_MASCULINO);
    SetShort("Maegrin");
    SetLong("Maegrin es un pobre viejecito que está enfermo. Es un hombre de "
	    "constitución enclenque, es muy delgado y está encorvado. Tiene las manos muy "
	    "huesudas y de vez en cuando se las frota.\n");

    AddQuestion(({"medicamento","quest",}),
	    "Necesito un calmante, para mitigar el dolor. Pero ya soy "
	    "demasiado viejo y estoy bastante dolorido como para ir a buscarla "
	    "yo mismo. Además el camino es demasiado peligroso.\n",1);
    AddQuestion(({"manos"}),
	    "Mis viejas manos cada vez estan más inutiles, este maldito reuma "
	    "me está matando no sé si aguantare un invierno más.\n");

    InitChats(5,({"Maegrin dice: Este reuma me esta matando.\n",
	    "Maegrin se frota las manos poniendo mala cara.\n",
	    "Maegrin dice: Soy demasiado viejo para ir a por el remedio.\n"}));
    InitAChats(10,
	({"Maegrin dice: Que sea viejo no indica que no sepa defenderme.\n"}));

}

notify_enter(mixed oldenv, int method, mixed extra) {
object medicamento;

::notify_enter(oldenv,method,extra);

medicamento=PO;
if (medicamento->id("medicina")) {
  medicamento->remove();
   if (QUESTMASTER->QueryQuestSolved("Contrabando", TP))
 {
  tell_object(TP,"¡Ya has resuelto este quest! Maegrin no te olvida.\n");
   write_file (LOGS "CONTRABANDO",ctime(time())+TP->QueryRealName()+" ["+
            TP->QueryLevel()+"]   Ha conseguido mitigar el dolor de reuma de Maegrin.\n");

   return 42;
 }
 QUESTMASTER->SetPlayerQuest("Contrabando",TP);
 tell_object(TP,"¡Muchas gracias. Maegrin calma su reuma.\n");
 CHMASTER->SendMsg("info", "¡¡Maegrin agradece  a "+TP->QueryName()+"su alivio del reuma!!\n");
 tell_object(TP,"Has mitigado el dolor de Maegrin,  Felicidades!\n");
 write_file (LOGS "CONTRABANDO",ctime(time())+" "+TP->QueryRealName()+" ["+
 TP->QueryLevel()+"]  ha mitigado el dolor de reuma de Maegrin.\n");
 write_file (LOGS "CONTRABANDO",ctime(time())+TP->QueryRealName()+" ["+
            TP->QueryLevel()+"] ha mitigado el dolor de reuma de Maegrin.\n");
 return 42;
}

}
