/***************************************************************************************
 [n] nemesis@simauria
 [kt] kastwey@simauria
 ARCHIVO:	retablo.c
 AUTOR:		[k] Karu@simauria
 FECHA:		20-02-2002
 COMENTARIOS:	La parte de arriba del retablo en la ermita de berat
 MODIFICADO: 31-May-02 [n] Cambiadas las descripciones para eliminar las
             referencias a Mirill, Jorus y Maler. Juro por algo que como
             pille a los responsables les voy a patear los pelendengues...
11/01/2005: [KT]: Pongo los movimientos en M_SPECIAL para que no
se pueda seguir al trepar o bajar, ETC...
*/

#include <moving.h>
#include <skills.h>
#include <combat.h>
#include "./path.h"
#include <sounds.h>

inherit SIM_ROOM;
public void snd_caida();
int fabajo()
{

	if (TP->UseSkill(HAB_TREPAR)<5)
	{
      	TP->move(SIMA("berat/ermita"),M_SPECIAL,({
  		    "intenta bajar con cuidado del retablo... pero pierde el equilibrio "
    		"y se pega contra el suelo.\n",
			"cae al suelo desde el retablo",
			"Intentas bajar con cuidado del retablo pero pierdes pie y te pegas contra el suelo"
		}));
		tell_room(SIMA("berat/hueco"), CAP(TNAME)+" se cae del retablo al intentar bajar.\n");
		TP->Defend(15,TD_APLASTAMIENTO,DEFEND_NOMSG);
		snd_caida();
		return 1;
	}
	else
	{
		TP->move(SIMA("berat/ermita"),M_SPECIAL,({
			"baja del retablo con cuidado",
			"llega desde el retablo",
			"Bajas del retablo con cuidado"
		}));
		tell_room(SIMA("berat/hueco"), CAP(TNAME)+
		" baja del retablo al suelo del templo sin problemas.\n");
		return 1;
	}
}

int fsaltar()
{
	if (TP->UseSkill(HAB_SALTAR)<5)
	{
		TP->move(SIMA("berat/ermita"),M_SPECIAL,({
			"pega un salto para alcanzar el hueco, pero no lo consigue y cae al suelo",
			"cae desde lo alto del retablo",
  		"Intentas saltar hacia el hueco, pero no consigues llegar y caes al suelo"
  	}));
		tell_room(SIMA("berat/hueco"), CAP(TNAME)+" da un salto desde el retablo para "
		"llegar hasta aquí, pero no llega y se cae para abajo.\n");
		TP->Defend(15,TD_APLASTAMIENTO,DEFEND_NOMSG);
		snd_caida();
		return 1;
	}
	else
	{
		TP->move(SIMA("berat/hueco"),M_SPECIAL,({
			"salta hacia el hueco y consigue alcanzarlo",
			"llega de un salto desde el retablo",
			"saltas hacia el hueco y consigues alcanzarlo"
		}));
		tell_room(SIMA("berat/ermita"), CAP(TNAME)+
		" da un salto desde el retablo hasta el hueco y consigue alcanzarlo.\n");
		return 1;
	}
}

create(){
    ::create();

    SetIntBright(40);
    SetLocate("berat");
    SetIntSmell("Huele a incienso.\n");

    SetIntShort("lo alto del retablo");
    SetIntLong("Te encuentras en lo alto del retablo del templo dedicado a Toolam. "
    "Desde aquí tienes una vista privilegiada del templo.\n");

    AddDetail("templo",
    "Sendas hileras de columnas flanquean el pasillo que conduce hasta el altar "
   "del dios, situado bajo una cúpula sostenida por cuatro estatuas a guisa de "
   "columnas. Tras el altar puedes ver una enorme estatua del dios, y tras ésta un gran "
   "retablo que sin duda representa algunos de sus proezas. El templo "
   "se encuentra bien iluminado, gracias a la luz que entra por unas hermosas "
   "vidrieras y también a la multitud de lámparas encendidas en honor del dios.\n");
    AddDetail(({"lámparas","lamparas"}),
    "Han sido encendidas en honor del dios. Debe ser una divinidad muy querida.\n");
    AddDetail("vidrieras","Representan algunos pasajes de la vida del dios Toolam.\n");
    AddDetail(({"cúpula","bóveda", "boveda", "cupula"}),
    "Parece representar un cielo cuajado de estrellas.\n");
    AddDetail("estatua", "Hay varias estatuas: la del dios y otras cuatro.\n");
    AddDetail(({"estatua del dios","estatua enorme","enorme estatua","estatua de Toolam"}),
    "Es la estatua de Toolam, el dios del viento. Es un dios al que las gentes "
    "de Berat tienen en gran estima.\n");
    AddDetail(({"cuatro estatuas", "4 estatuas"}),
    "Son las estatuas de los cuatro hijos de Toolam, los gigantes de los vientos: "
    "Gormoth, Tanuk, Guirin y Domin.\n");
    AddDetail(({"pared","paredes"}),
    "Están adornadas con hermosos relieves y tapices.\n");
    AddDetail("relieves",
    "Son hermosos relieves que representan al dios en distintos pasajes de su vida.\n");
    AddDetail("tapices",
    "Sin duda son ofrendas de las familias acomodadas de la ciudad al dios, "
    "ya que en muchos de ellos puedes ver divisas y escudos familiares.\n");
    AddDetail("tapizes",
    "A ver... repite conmigo... Antes de 'e' e 'i' se escribe 'c' y no 'z'. ¿Vale? "
    "Pues a ver si es verdad...\n");
    AddDetail("retablo","Te encuentras sobre él.\n");
    AddDetail(({"hueco","hueco oculto"}), "Hay un misterioso hueco al que quizás "
    "llegarías si saltaras.\n");

    AddExit("abajo",SF(fabajo));
    AddExit("saltar",SF(fsaltar));
}

public void snd_caida(){
    object templo = find_object(SIMA("berat/ermita"));
    object hueco = find_object(SIMA("berat/hueco"));
    play_sound(({TO, hueco}), SND_SUCESOS("caida_fuerte"), 0, 60);
	play_sound(templo, SND_SUCESOS("caida_fuerte"));
}
