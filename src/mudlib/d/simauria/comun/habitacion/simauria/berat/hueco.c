/***************************************************************************************
 ARCHIVO:	hueco.c
 AUTOR:		[k] Karu
                [n] Nemesis
 [KT] Kastwey
 FECHA:		20-02-2002
 COMENTARIOS:	El hueco cerca del retablo
 MODIFICACIÓN;  7-07-2003 [n] Retocada la forma de pillar el caldero.
 		8-07-2003 [z] Añado el Reset para que vuelva a aparecer el caldero.
 			      Como ahora se descuelga el caldero lo quito del AddItem.
 			      Cambio QueryName() por QueryRealName() por si las moscas.
 			      Añado un cmd "coger caldero" que te dice que nain.
 			      Añado también comprobación de que lo puede llevar y
 			      mensaje en caso de que no pueda. (Creo que ya está todo).
 11/01/2004: [KT]: cambio M_GO y M_SILENT por special para que no se pueda seguir
 ***************************************************************************************/

#include <moving.h>
#include <skills.h>
#include "path.h"
#include <combat.h>
#include <sounds.h>
#include <properties.h>
#include <magia.h>
inherit SIM_ROOM;
public void snd_caida();
int pesta, hay_caldero;

public void SetCalderoPresent(int esta) { pesta = esta; }
public int QueryCalderoPresent() { return pesta; }

int fsaltar()
{

	if (TP->UseSkill(HAB_SALTAR)<5)
	{
		TP->move(SIMA("berat/ermita"),M_SPECIAL,({
			"salta hacia el retablo, pero no consigue llegar y cae al suelo",
			"cae al suelo desde el hueco que hay tras el retablo",
			"intentas saltar hacia el retablo, pero no llegas y caes al suelo"
		}));
		tell_room(SIMA("berat/retablo"), CAP(TNAME)+" intenta saltar del hueco hasta "
		"aquí, pero falla y cae para abajo hacia el suelo del templo.\n");
		TP->Defend(15,TD_APLASTAMIENTO,DEFEND_NOMSG);
		snd_caida();
		return 1;
	}
	else
	{
		TP->move(SIMA("berat/retablo"),M_SPECIAL,({
			"salta hacia el retablo y consigue alcanzarlo",
			"llega saltando desde el hueco",
			"saltas hacia el retablo y consigues alcanzarlo"
		}));
		tell_room(SIMA("berat/ermita"), CAP(TNAME)+
		" consigue saltar con éxito desde el hueco hasta el retablo.\n");
		return 1;
	}
}


public string QueryIntLong() {

    if (QueryCalderoPresent())
        return "Es una pequeña habitación justo detrás del retablo y la única "
  	   "luz existente en la sala es la que llega por encima de él. "
  	   "Tal vez la excavaron para esconder algo. Es circular y húmeda. Será "
	    "mejor que hagas lo que has venido a hacer y te vayas, es probable "
	    "que a los dioses no les guste que estés aquí. Hay un caldero colgado "
	    "en la pared.\n";
    else return "Es una pequeña habitación justo detrás del retablo y la única "
  	    "luz existente en la sala es la que llega por encima de él. "
  	    "Tal vez la excavaron para esconder algo. Es circular y húmeda. Será "
	    "mejor que hagas lo que has venido a hacer y te vayas, es probable "
	    "que a los dioses no les guste que estés aquí. Te llama la atención "
	    "un enorme clavo en la pared.\n";
}

string caldero_desc() {
    if(QueryCalderoPresent())
        return "Ves un caldero colgado de un clavo. No puedes cogerlo sin más, "
        "tendrás que hacerlo de otra forma.\n";
  else return "Parece que hubo recientemente un caldero colgado de un clavo en la pared,"
    " pues las marcas de polvo que se han quedado en la roca lo muestran.\n";
}

string clavo_desc() {
    if(QueryCalderoPresent())
        return "Ves un caldero colgado de un clavo. No puedes cogerlo sin más, "
        "tendrás que hacerlo de otra forma.\n";
  else return "Ves un clavo de hierro. Probablemente hubo algo ahí colgado alguna vez.\n";
}

int fdescolgar(string str) {
    object ob;
    if (!hay_caldero)
        return notify_fail("No hay ningún caldero, quizá alguien lo ha cogido antes.\n");
    if(str!="caldero") return 0;
    else {
        write("Descuelgas el caldero, ¡ya es tuyo!\n");
        hay_caldero=0;
        ob = clone_object("/d/simauria/comun/objeto/otro/caldero");
        ob->SetOwner(PO->QueryRealName());
        if(ob->move(TP,M_SILENT) != ME_OK) ob->move(TO, M_SPECIAL, "cae al suelo");
        SetCalderoPresent(0);
        return 1;
  }
}

reset(){
  ::reset();

  SetCalderoPresent(1);
}


create(){
    ::create();

    SetIntBright(20);
    SetLocate("berat");
    Set(P_TPORT,TPORT_NO);
      SetIntSmell("Huele a incienso.\n");
    SetCalderoPresent(1);
    hay_caldero=1;
    SetIntShort("un oscuro hueco");

        SetIntLong("Es una pequeña habitación justo detrás del retablo y la única "
  	"luz existente en la sala es la que llega por encima de él. "
  	"Tal vez la excavaron para esconder algo. Es circular y húmeda. Será "
	"mejor que hagas lo que has venido a hacer y te vayas, es probable "
	"que a los dioses no les guste que estés aquí. Te llama la atención "
	"un enorme clavo en la pared.\n");

    AddDetail("techo","Es un techo abovedado. Está excavado en la roca, "
  	"puedes ver las líneas de humedad.\n");
    AddDetail("suelo",
    "El suelo es de tierra, aunque puedes ver la roca en distintas paredes.\n");
    AddDetail(({"humedad","líneas de humedad","lineas de humedad"}),
        "Son manchas de humedad en la pared y en el techo.\n");
  AddDetail("retablo","Es la parte trasera del retablo: una pared lisa de "
  	"madera. En algunos puntos puedes ver cómo las termitas han empezado "
  	"a hacer su trabajo.\n");
  AddDetail(({"termitas","trabajo de las termitas"}),
        "Hay profundos agujeros y surcos en la madera. Estos animalitos son "
  	    "persistentes, sin duda.\n");

    AddDetail("clavo",SF(clavo_desc));
    AddDetail("caldero",SF(caldero_desc));

    AddExit("saltar",SF(fsaltar));
    AddRoomCmd("descolgar","fdescolgar");
    AddRoomCmd("coger","fcoger");
}

public int fcoger(string str)
{
	if (lower_case(str)=="caldero" && QueryCalderoPresent())
	{
		write("No puedes coger el caldero, está bien sujeto. Busca otra forma.\n");
		return 1;
	}
	else return 0;
}

public void snd_caida(){
    object templo = find_object(SIMA("berat/ermita"));
    object retablo = find_object(SIMA("berat/retablo"));
    play_sound(templo, SND_SUCESOS("caida_fuerte"));
    play_sound(({retablo, TO}), SND_SUCESOS("caida_fuerte"), 0, 60);
}
