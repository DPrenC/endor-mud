// Creación: Cheto
// Creación de la cabecera: Nemesis (como siempre)
// Modificaciones: [n] Re-añadido lo de que haga logs.
// NOTA: A partir de ahora se contarán los trabajos hechos por firmas.
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
 write("Reparar... ¿qué?\n");
}
if (cad1=="lamina"){
	//if (!ob=present("JK23-H",TP))
	//	{
	//	 write("Necesitas unos conocimientos especiales para esto.\n");
	//	}//present
	//else
	if (!ob2=present("lenteq",TP)){
	        write("Es dudoso que puedas repararla... Deberías conseguir una nueva y cambiarla.\n");
	       }
	else   {
	        tell_object(TP,"Reemplazas la lámina rota por la nueva.\n");
		//tell_object(TP,"De la alegría se te cae el impreso por la ventana.\n");
		//if (ob) destruct(ob);
		if (ob2) destruct(ob2);
		//rutinas para el quest
		if (sscanf(Quests,"%saro_gora%s",a,b)!=2){
			tell_object(TP,"\nLos pescadores de Gorat te estarán eternamente agradecidos.\n");
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
"cubierta está hecha con gruesos pilares de madera que sostienen un tejado "
"cónico cubierto por lajas de pizarra que protege de la lluvia. En su centro "
"se alza un pedestal de piedra sobre el que arde el fuego que da la luz al "
"faro. Desde aquí se tiene una vista inmejorable del golfo de Betria. Las "
"escaleras que ves a través de la trampilla del suelo conducen a la parte baja "
"del faro.\n");

  AddDetail(({"muro","barandilla"}),
"Debe tener como un metro de altura y el mismo grosor que el resto de la "
"pared del faro. Evita que caer al vacío desde aquí arriba.\n");

  AddDetail("pilares",
"Son seis gruesos troncos cuya su función es la de sostener el tejado.\n");

  AddDetail(({"tejado","estructura","cubierta"}),
"El tejado del faro tiene forma cónica y esta formado por una estructura "
"interna de madera sobre la que están fijas lajas de pizarra.\n");

  AddDetail(({"lajas","pizarra"}),
"El tejado esta formado por lajas de pizarra. Son planchas planas e "
"irregulares de mediano tamaño que están colocadas de tal manera que se "
"solapan impidiendo que la lluvia pase al interior.\n");

  AddDetail(({"pedestal"}),
"El pedestal es una plataforma de piedra del tamaño de una mesa común "
"redonda. Sobre él se enciende el fuego que da la luz al faro. Unas "
"gruesas láminas traslucidas de cristal de roca evitan que el viento "
"apague el fuego. Una de las láminas esta rota y mientras no se repare "
"el faro no puede funcionar.\n");

  AddDetail(({"lamina","lamina rota"}),
"Una de las láminas está rota (prueba a poner 'reparar lamina')...\n");

  AddDetail(({"fuego"}),
"El fuego está apagado por que el faro no puede funcionar mientras una "
"de las láminas de cristal de roca está rota...\n");

  AddDetail(({"escaleras","trampilla"}),
"Las escaleras que ves a través de la trampilla del suelo conducen a la parte baja "
"del faro.\n");

  AddExit("abajo",GORAT("faro1") );
}

init()
{
add_action("cmd_reparar","reparar");
::init();
}