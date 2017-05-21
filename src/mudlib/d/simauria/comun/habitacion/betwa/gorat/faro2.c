// Creaci�n: Cheto
// Creaci�n de la cabecera: Nemesis (como siempre)
// Modificaciones: [n] Re-a�adido lo de que haga logs.
// NOTA: A partir de ahora se contar�n los trabajos hechos por firmas.
// Si no lo has firmado, no lo has hecho...
// 03-06-08 [Angor] Rehecha, que esos faros del siglo XIX no pegan aqui...

#include "./path.h"
inherit GORAT("room_base.c");

//comando para reparar el faro
cmd_reparar(string cad1)
{
string Quests,a ,b;
object ob;
object ob2;
Quests=TP->QueryQuests();
if (!Quests) Quests="hallo";
if (!cad1){
 write("Reparar... �qu�?\n");
}
if (cad1=="lamina"){
	//if (!ob=present("JK23-H",TP))
	//	{
	//	 write("Necesitas unos conocimientos especiales para esto.\n");
	//	}//present
	//else
	if (!ob2=present("lenteq",TP)){
	        write("Es dudoso que puedas repararla... Deber�as conseguir una nueva y cambiarla.\n");
	       }
	else   {
	        tell_object(TP,"Reemplazas la l�mina rota por la nueva.\n");
		//tell_object(TP,"De la alegr�a se te cae el impreso por la ventana.\n");
		//if (ob) destruct(ob);
		if (ob2) destruct(ob2);
		//rutinas para el quest
		if (sscanf(Quests,"%saro_gora%s",a,b)!=2){
			tell_object(TP,"\nLos pescadores de Gorat te estar�n eternamente agradecidos.\n");
                	QUESTMASTER->InformSolution(capitalize(TP->QueryName())+" ha arreglado el faro de Gorat");
			QUESTMASTER->SetPlayerQuest("faro_gorat",TP);
			write_file(LOGS "FAROGORAT",ctime(time())+" "+TP->QueryRealName()+" ["+
                        TP->QueryLevel()+"]   Ha reparado el faro de Gorat\n");
		}

	}
}//if cad1...
 return 25;
}

create () {
  ::create();
  SetIntShort("el la parte superior del faro de Gorat");
  SetIntLong(
"La parte superior del faro de Gorat es una terraza protegida por una cubierta "
"y rodeada por un muro bajo de piedra a modo de barandilla exterior. La "
"cubierta est� hecha con gruesos pilares de madera que sostienen un tejado "
"c�nico cubierto por lajas de pizarra que protege de la lluvia. En su centro "
"se alza un pedestal de piedra sobre el que arde el fuego que da la luz al "
"faro. Desde aqu� se tiene una vista inmejorable del golfo de Betria. Las "
"escaleras que ves a trav�s de la trampilla del suelo conducen a la parte baja "
"del faro.\n");

  AddDetail(({"muro","barandilla"}),
"Debe tener como un metro de altura y el mismo grosor que el resto de la "
"pared del faro. Evita que caer al vac�o desde aqu� arriba.\n");

  AddDetail("pilares",
"Son seis gruesos troncos cuya su funci�n es la de sostener el tejado.\n");

  AddDetail(({"tejado","estructura","cubierta"}),
"El tejado del faro tiene forma c�nica y esta formado por una estructura "
"interna de madera sobre la que est�n fijas lajas de pizarra.\n");

  AddDetail(({"lajas","pizarra"}),
"El tejado esta formado por lajas de pizarra. Son planchas planas e "
"irregulares de mediano tama�o que est�n colocadas de tal manera que se "
"solapan impidiendo que la lluvia pase al interior.\n");

  AddDetail(({"pedestal"}),
"El pedestal es una plataforma de piedra del tama�o de una mesa com�n "
"redonda. Sobre �l se enciende el fuego que da la luz al faro. Unas "
"gruesas l�minas traslucidas de cristal de roca evitan que el viento "
"apague el fuego. Una de las l�minas esta rota y mientras no se repare "
"el faro no puede funcionar.\n");

  AddDetail(({"lamina","lamina rota"}),
"Una de las l�minas est� rota (prueba a poner 'reparar lamina')...\n");

  AddDetail(({"fuego"}),
"El fuego est� apagado por que el faro no puede funcionar mientras una "
"de las l�minas de cristal de roca est� rota...\n");

  AddDetail(({"escaleras","trampilla"}),
"Las escaleras que ves a trav�s de la trampilla del suelo conducen a la parte baja "
"del faro.\n");

  AddExit("abajo",GORAT("faro1") );
}

init()
{
add_action("cmd_reparar","reparar");
::init();
}