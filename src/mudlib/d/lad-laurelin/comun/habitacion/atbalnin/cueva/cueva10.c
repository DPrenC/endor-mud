#include "path.h"
#include <moving.h>
#include <colours.h>

inherit ATB_C("std_cueva");

private static int t, shocked, das_boot;
private static string tname;
private static object ob;


int cmd_subir_barca(string str)
{
  if (das_boot==0)
    return(0);
  if (str != "barca" && str != "bote" && str != "a la barca" &&
	str != "al bote")
    return notify_fail("Subir donde?\n");

  if (tname != TP->QueryRealName())
  {
    write(W("Una fuerza te impide ir a la barca. Al parecer no esta "
	"destinada a ti.\n"));
    say(capitalize(TP->QueryRealName())+" intenta subirse a la "
	"barca pero algo se lo impide.\n");
    return(1);
  }
  write("Te subes a la barca.\n");
  say(capitalize(TP->QueryRealName())+" se sube a la barca.\n");
  return TP->move(ATB_C("barca"), M_SILENT);
}


la_barca()
{
  object barca;

  write(W("Una barca aparece por el este y se para cerca de la "
	"orilla. Quizas podrias subirte en ella.\n"));
  say("Una barca aparece por el este y se acerca a la orilla.\n");
  barca=clone_object(OTRO("obj_barca"));
  if (barca) barca->move(TO);
  das_boot=1;
}



cmd_incons()
{
  switch(t) {
    case 0:
	write(W("\nTodo esta oscuro, muy oscuro. No sientes ninguna "
		"parte de tu cuerpo, ni siquiera el dolor del principio, "
		"cuando recibiste la descarga.\n"
		"Una hermosa y triste mujer aparece ante ti.\n\n"));
	t++;
	call_out(SF(cmd_incons), 10);
	break;
    case 1:
	write(W("La mujer abre los ojos. Puedes escuchar su magica "
		"voz, aunque sus labios permanecen cerrados.\n\n"));
	t++;
	call_out(SF(cmd_incons), 10);
	break;
    case 2:
	write(W("La mujer te dice: '"+TC_BOLD+"Hola "+
		capitalize(TP->QueryRealName())+TC_BOLD+". He estado "
		"mucho tiempo esperando a alguien. Una visita, una visita "
		"poco grata."+TC_NORMAL+TC_CNORMAL+"'\n\n"));
	t++;
	call_out(SF(cmd_incons), 10);
	break;
    case 3:
	write(W("Ves como un destello de miedo cubre su rostro. Sin "
		"embargo la mujer sigue con su relato. Intentas levantarte "
		"en vano.\n\n"));
	t++;
	call_out(SF(cmd_incons), 5);
	break;
    case 4:
	write(W("La mujer dice: '"+TC_BOLD+"Sin embargo eres tu "
		"el que ha venido. Te ruego pues que me perdones por haberte "
		"atacado. Creia que mi hora habia llegado. Ven a mi, al "
		"Corazon del Bosque, ven a mi, ayudame y te ayudare."+
		TC_NORMAL+TC_CNORMAL+"'\n\n"));
	t++;
	call_out(SF(cmd_incons), 15);
	break;
    case 5:
	write(W("Intentas articular alguna que otra palabra pero "
		"nada sale de tu boca. La mujer te acerca sus manos, y sin "
		"saber por que el miedo te invade.\n\n"));
	t++;
	call_out(SF(cmd_incons), 10);
	break;
    case 6:
	write(W("La mujer posa delicadamente sus manos "
		"sobre tu pecho, y sientes como el calor y la paz invaden "
		"tu cuerpo. Te sientes como un estupido por haberte "
		"aterrorizado de esa manera.\n\n"));
	t++;
	call_out(SF(cmd_incons), 15);
	break;
    case 7:
	write(W("La mujer se inclina y te besa en la frente. Te "
		"dice: '"+TC_BOLD+"No te preocupes, mortal, nada te "
		"pasara. Ahora ven hasta mi."+TC_NORMAL+TC_CNORMAL+
		"'\n\n"));
	t++;
	call_out(SF(cmd_incons), 15);
	break;
    case 8:
	write(W("Poco a poco abres los ojos. Estas tumbado en la "
		"arena. Miras a tu alrededor. La mujer no esta. Te preguntas "
		"si la has visto realmente.\n\n"));
	say(W(TP->QueryRealName()+" se despierta, mira alrededor y "
		"se levanta.\n"));
	shocked=2;
	call_out("la_barca", 40);
	if (ob) destruct(ob);
	else log_file("QUEST_ERRORS", ctime()+" - El silence-o-matic no esta "
		"en el inventario de "+capitalize(tname)+".\n");
	break;
  }
}



int cmd_coger(string str)
{
  int i;

  if (str != "vara" && str != "palo")
    return(PLAYER->ftake(str));

  if (shocked==1)
  {
    if (tname != TP->QueryRealName())
    {
      write("Mejor no. Al pie del palo ves a "+capitalize(tname)+
	  " inconsciente.\n");
      return(1);
    }
  }
  if (shocked==2)
  {
    write("Coges el palo. Nada ocurre.\n");
    return(1);
  }

  write(W("Cuando vas a coger el palo, un enceguecedor rayo sale de "
	"la parte que no esta enterrada y te da de lleno!\nCaes la suelo "
	"inconsciente.\n"));
  ob=clone_object(OTRO("silencer"));
  if (ob) ob->move(TP);

  t=0;
  shocked=1;
  tname=TP->QueryRealName();

  say(W("Ves como un rayo alcanza a "+tname+" en el pecho y lo deja "
	"inconsciente.\n"));

  call_out(SF(cmd_incons), 10);
  return(1);
}


create(){
  ::create();

  SetIntLong(W("Estas al pie de una pequenya cala natural. Clavado "
	"en el suelo parece que hay una vara de madera milagrosamente bien "
	"conservada, a saber con que proposito...\n"));
  SetIntShort("la orilla del lago");
  AddDetail(({"suelo", "arena"}), W("Alguna que otra roca sobresale "
	"timidamente por sobre la arena.\n"));
  AddDetail(({"vara", "palo"}), W("Es un palo de madera ricamente "
	"ornamentado. Quizas tenga algo magico por que no es muy normal que "
	"lleve tanto tiempo ahi sin que se pudra la madera. O quizas es que "
	"no lleva tanto tiempo ahi como parece.\n"));
  AddDetail(({"lago","agua"}), "Es un inmenso y oscuro lago.\n");
  AddDetail("orilla", "Solo ves esta orilla, la otra esta demasiado "
	"lejana.\n");
  SetNoise("Escuchas el rumor del oleaje.\n");
  SetSmell("Curiosamente el olor a humedo deja paso al olor de "
	"vegetacion.\n");
  AddRoomCmd("coger", SF(cmd_coger));
  AddRoomCmd("subir", SF(cmd_subir_barca));
  AddExit("sur", ATB_C("cueva08"));
  AddExit("suroeste", ATB_C("cueva05"));
  AddExit("oeste", ATB_C("cueva06"));
  AddExit("norte", ATB_C("cueva10"));
}

reset()
{
  ::reset();
  shocked=0;
  das_boot=0;
}


