/***************************************************************************************
 ARCHIVO:	plaza.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Plaza Central de Koek
 MODIFICACIO:   08-03-2003 Cambio el gshout del quest resuelto por un SendEmote vía
 		           canal mud para que cuando esté invis pueda enterarme de
 			   quien ha resuelto el quest.
 		09-04-2003 Cambio el archivo de log del quest resuelto.
 		18-04-2003 Cambio el dar la espada para que pille la id en lugar de
 			   un string fijo.
 04/05/2007. [Y] (Yalin), suprimo función fbeber, e incluyo la fuente según
    el nuevo standard
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <sounds.h>
inherit RHOESTD("roome");

create () {
 ::create();

 SetLocate("Koek");
 SetIntShort("la plaza Zendak");
 carcel=(RHOEHAB("koek/calles/folker_07"));

 AddExit("norte",RHOEHAB("koek/calles/cendaf_03"));
 AddExit("sur",RHOEHAB("koek/calles/cendaf_04"));
 AddExit("este",RHOEHAB("koek/calles/folker_07"));
 AddExit("oeste",RHOEHAB("koek/calles/folker_06"));
 AddItem(RHOEVAR("koek/varios/fuente"));
    AddItem(RHOEPNJ("koek/varios/patrullero"),REFRESH_DESTRUCT);
    AddItem(RHOEPNJ("koek/varios/peregrino"),REFRESH_DESTRUCT,2);
    AddItem(RHOEPNJ("koek/ciudadanos/anciana2"),REFRESH_DESTRUCT);
 AddDetail(({"banco","bancos","banco de piedra","bancos de piedra"}),W("En la plaza "
 	"hay varios bancos de piedra donde la gente se sienta a conversar. Son muy "
 	"simples, pero muy funcionales.\n"));
 AddDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}),W(
	"Es una gran estatua de piedra de Zendak, el primer habitante reconocido "
	"que se instaló en este valle. Tiene un gran porte y la mirada desafiante "
	"hacia el norte, fijándola en el Templo de Seri-Solderteg o en el bosque de "
	"Cylin, más al norte. Las manos se ven anchas y fuertes. La verdad es que es "
	"la estatua más realista que has visto en tu vida, y si fijas la vista en ella "
	"da la sensación de que Zendak vaya a saltar del pedestal y dirigirse hacia "
	"el templo.\n"));
 AddDetail(({"pedestal","inscripcion"}),W("Miras un pedestal de piedra bastante grande "
 	"con la historia de Zendak grabada en una gran inscripción.\n"));
 AddDetail(({"bosque","bosque de Cylin","cylin","Cylin","bosque de cylin"}),W("Desde "
 	"aquí no lo puedes ver, pero sabes que está al norte, tras las puertas del templo.\n"));
 AddDetail(({"templo","seri-solderteg","Seri-Solderteg"}),W("El templo se alza al norte, "
 	"al final de la calle Cendaf.\n"));
 AddReadMsg(({"inscripcion","inscripción"}),"Zendak, fundador de Koek.\n");
AddDetail(({"agua","chorro de agua","chorro","surtidor","surtidor de agua"}),
     "Solo de ver el agua te entra sed.\n");
 AddRoomCmd("revivir","frevivir");
 AddRoomCmd("matar","fatacar");
 AddRoomCmd("magia","fatacar");
 AddRoomCmd("lanzar","fatacar");
 AddRoomCmd("dar","fdar");
 AddRoomCmd("devolver","fdar");
 map[neu,des]="Esta es la plaza de Zendak, el primer habitante del lugar, un "+
 	    "peregrino que se estableció aquí hace ya muchos años. Hay una "+
 	    "gran estatua de Zendak presidiendo la plaza situada sobre un gran "+
 	    "pedestal de piedra. A los lados ves algunos bancos de piedra donde "+
 	    "los ancianos del lugar se sientan a hablar durante todo el día. Justo "
 	    "a los pies de la estatua ves una fuente de la que sale un refrescante "
 	    "chorro de agua cristalina. ";
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));
}

int fatacar(string str)
{
	if (present("zendak",TO) && living(present("zendak",TO)))
	{
		write(W("Te sientes sobrecogido por la portentosa figura de Zendak y "
		"no te atreves a moverte.\n"));
		return 1;
	}
    return 0;
}

int fdar(string str)
{
	string cosa,quien;
	object espada=present("espada arreglada",TP);
	object espada_mala=present("espada de Zendak muy oxidada",TP);
	object zendak=present("zendak",TO);

	if (str) lower_case(str);
	else return 0;
	if (sscanf(str,"%s a %s", cosa,quien) != 2) return 0;
	if (!zendak || !living(zendak)) return 0;
	if (espada && espada->id(cosa) && espada && zendak->id(quien))
	{

		if (TP->QueryAttribute("KillGorgona") && !TP->QueryAttribute("EspadaZendak"))
		{
			TP->SetAttribute("EspadaZendak",1);
			write(W("Zendak se te queda mirando con ojos complacientes y "
				"sin decir ninguna palabra notas como con la mirada te "
				"da su aprobación y su gratitud al haberle devuelto la "
				"espada. Sin saber por qué te la devuelve. Quizás es que "
				"no la necesite más, pero parece que le ha hecho algo "
				"antes de devolvértela.\n"));
			say(W("Zendak se queda mirando a "+CATP+" con ojos complacientes "
				"y sin decir ninguna palabra le muestra con la mirada una "
				"inmensa gratitud por haberle devuelto su espada. Quizás "
				"sea que ya no la necesite pero el caso es que se la devuelve "
				"tras hacerle algo extraño.\n"),TP);
			espada->remove();
			espada=clone_object(RHOEWEA("koek/varios/espada_zendak"));
			espada->SetDuenyo(TP);
			espada->move(TP,M_NOCHECK);
			tell_room(TO,"[36mZendak se vuelve a convertir en estatua.[0m\n");
			QUESTMASTER->InformSolution("Zendak ha recuperado su espada gracias a "+TP->QueryName()+"");
       			QUESTMASTER->SetPlayerQuest("espada_zendak",TP);
       			write_file (LOGS"ZENDAK",ctime(time())+"   "+CATP+" ["+TP->QueryLevel()+"] le ha devuelto su espada a Zendak.\n");
			if (present("Zendak",TO)) present("Zendak",TO)->remove();
			AddDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}),
			"Es una gran estatua de piedra de Zendak, el primer habitante reconocido "
			"que se instaló en este valle. Tiene un gran porte y la mirada desafiante "
			"hacia el norte, fijándola en el Templo de Seri-Solderteg o en el bosque de "
			"Cylin, más al norte. Las manos se ven anchas y fuertes. La verdad es que es "
			"la estatua más realista que has visto en tu vida, y si fijas la vista en ella "
			"da la sensación de que Zendak vaya a saltar del pedestal y dirigirse hacia "
			"el templo.\n");
			return 1;
		}
		else if (!TP->QueryAttribute("KillGorgona"))
		{
			write("[52mZendak te mira y muestra su desaprobación. Piensas "
				"si realmente sabrá que no has conseguido esa cabeza de uno "
				"modo muy heróico y que quizás deberías matar TÚ a la gorgona "
				"para poder ganarte su respeto y atención.[0m\n");
			say("[52mZendak mira a "+CATP+" y muestra su desaprobación.[0m\n");
			tell_room(TO,"[36mZendak se vuelve a convertir en estatua.[0m\n");
			if (present("Zendak",TO)) present("Zendak",TO)->remove();
			AddDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}),W(
			"Es una gran estatua de piedra de Zendak, el primer habitante reconocido "
			"que se instaló en este valle. Tiene un gran porte y la mirada desafiante "
			"hacia el norte, fijándola en el Templo de Seri-Solderteg o en el bosque de "
			"Cylin, más al norte. Las manos se ven anchas y fuertes. La verdad es que es "
			"la estatua más realista que has visto en tu vida, y si fijas la vista en ella "
			"da la sensación de que Zendak vaya a saltar del pedestal y dirigirse hacia "
			"el templo.\n"));
			return 1;
		}
		else if (TP->QueryAttribute("EspadaZendak"))
		{
			write("[52mZendak te mira y muestra su desaprobación. Parece que "
				"te recuerda y no quiere que le molestes más.[0m\n");
			say("[52mZendak mira a "+CATP+" y muestra su desaprobación.[0m\n");
			tell_room(TO,"[36mZendak se vuelve a convertir en estatua.[0m\n");
			if (present("Zendak",TO)) present("Zendak",TO)->remove();
			return 1;
		}
		else
		{
			write("[52mZendak te mira y muestra su desaprobación.[0m\n");
			say("[52mZendak mira a "+CATP+" y muestra su desaprobación.[0m\n",TP);
			tell_room(TO,"[36mZendak se vuelve a convertir en estatua.[0m\n");
			if (present("Zendak",TO)) present("Zendak",TO)->remove();
			AddDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}),
			"Es una gran estatua de piedra de Zendak, el primer habitante reconocido "
			"que se instaló en este valle. Tiene un gran porte y la mirada desafiante "
			"hacia el norte, fijándola en el Templo de Seri-Solderteg o en el bosque de "
			"Cylin, más al norte. Las manos se ven anchas y fuertes. La verdad es que es "
			"la estatua más realista que has visto en tu vida, y si fijas la vista en ella "
			"da la sensación de que Zendak vaya a saltar del pedestal y dirigirse hacia "
			"el templo.\n");
			return 1;
		}
	}
	else if (espada_mala && espada_mala->id(cosa) && zendak->id(quien))
	{
		write("Esta espada está irreconocible. Primero deberías llevársela al "
			"herrero para que te la arreglara.\n");
		return 1;
	}
    return 0;
}

int fremove()
{
	if (present("zendak",TO))
	{
		if (present("Zendak",TO)) present("Zendak",TO)->remove();
		tell_room(TO,"Zendak desaparece de repente.\n");
		AddDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}),W(
		"Es una gran estatua de piedra de Zendak, el primer habitante reconocido "
		"que se instaló en este valle. Tiene un gran porte y la mirada desafiante "
		"hacia el norte, fijándola en el Templo de Seri-Solderteg o en el bosque de "
		"Cylin, más al norte. Las manos se ven anchas y fuertes. La verdad es que es "
		"la estatua más realista que has visto en tu vida, y si fijas la vista en ella "
		"da la sensación de que Zendak vaya a saltar del pedestal y dirigirse hacia "
		"el templo.\n"));
	}
	return 1;
}

int fzendak()
{
	object zendak;
	tell_room(TO,W("\n[52mDe repente la estatua de Zendak comienza a agrietarse "
		"hasta que una fina capa de roca y polvo salta poniendo al descubierto el "
		"cuerpo de un hombre, un musculoso guerrero de mirada confusa pero firme.[0m\n"));
	zendak=clone_object(RHOEPNJ("koek/varios/zendak"));
	zendak->move(TO,M_SILENT);
	call_out("fremove",100);
	return 1;
}

int frevivir(string str)
{
	object cabeza;
	cabeza=present("cabeza de gorgona",TP);
	if ((str=="estatua" || str=="zendak" || str=="Zendak") && cabeza)
	{
		if (present("Zendak",TO))
		{
			write("No puedes revivir a Zendak ahora, ya lo está.\n");
			return 1;
		}
		else
		{
			write("Frotas algo de sangre que queda en la cabeza de la "
				"gorgona contra la estatua de Zendak esperando "
				"un milagro.\n");
			say(CATP+" frota algo de sangre que queda en la cabeza de la "
				"gorgona contra la estatua de Zendak esperando "
				"un milagro.\n",TP);
			cabeza->SetSangre(cabeza->QuerySangre()+1);
			RemoveDetail(({"estatua","gran estatua","estatua de Zendak","gran estatua de Zendak"}));
			call_out("fzendak",4);
			return 1;
		}
	}
    return 0;
}

public int QueryPlaza()
{
	return 1;
}
