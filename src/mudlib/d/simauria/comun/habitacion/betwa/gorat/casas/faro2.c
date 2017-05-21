// Creaci�n: Cheto
// Creaci�n de la cabecera: Nemesis (como siempre)
// Modificaciones: [n] Re-a�adido lo de que haga logs.
// NOTA: A partir de ahora se contar�n los trabajos hechos por firmas.
//       Si no lo has firmado, no lo has hecho...



#include "./path.h"

inherit SIM_ROOM;
hacer_reparar(string cad1)
{
string Quests,a ,b;
object ob;
object ob2;
Quests=TP->QueryQuests();
if (!Quests) Quests="hallo";
if (!cad1){
 write("Reparar... �qu�?\n");
}
if (cad1=="lente")
	{
	if (!ob=present("JK23-H",TP))
		{
		 write("Necesitas unos conocimientos especiales para esto.\n");
		}//present
	else if (!ob2=present("lenteq",TP))
               {
	        write("Es dudoso que puedas repararla... Lo mejor ser�a cambiarla por una nueva.\n");
	       }
		else
		{
		 tell_object(TP,"Tras un rato jugando con la lente consigues colocarla en su lugar.\n");
		 tell_object(TP,"De la alegr�a se te cae el impreso por la ventana.\n");
		 if (ob) destruct(ob);
		 if (ob2) destruct(ob2);
		 //rutinas para el quest
		 if (sscanf(Quests,"%saro_gora%s",a,b)!=2)
		 {
		  tell_object(TP,"\nLos pescadores de Gorat te estar�n eternamente agradecidos.\n");
		  QUESTMASTER->InformSolution(capitalize(TP->QueryName())+" ha arreglado el faro de Gorat");
		  QUESTMASTER->SetPlayerQuest("faro_gorat",TP);
		  write_file(LOGS "FAROGORAT",ctime(time())+" "+TP->QueryRealName()+" ["+
                             TP->QueryLevel()+"]   Ha reparado el faro de Gorat\n");
		 }

		}//else
	}//if cad1...
 return 25;
}

create () {
  ::create();
SetLocate("Gorat");
SetIntShort("el faro de Gorat");
SetIntLong(
"Est�s frente a la lente del faro de Gorat. Es una habitaci�n con unas "
"amplias ventanas en las que tienes una vista inmejorable de la bah�a de "
"Gorat, tambi�n tienes unas escaleras que te llevan al piso inferior.\n");
SetIndoors(1);
AddDetail("lente",
"La lente del faro de Gorat, est� estropeada, prueba a poner 'reparar lente'...\n");
SetIntBright(30);
AddExit("abajo","./faro1");
}
init()
{
add_action("hacer_reparar","reparar");
::init();
}