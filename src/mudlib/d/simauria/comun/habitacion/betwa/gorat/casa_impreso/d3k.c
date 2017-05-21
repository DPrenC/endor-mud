
#include "./path.h"

inherit SIM_ROOM;
//cuñar el papelejo,
hacer_cunyar(){
object ob, ob2;
string str,str2;
if (!ob=present("impresot",TP)){
	write("Pide el impreso temporal en el despacho d1a.\n");}
	else
		{if (ob->destino()!="d3k"){
			str="Lo siento tienes que ir al despacho ";
			str2=ob->destino();
			str=str+str2;
			write(str);
			write(".\n");}
		else if (ob->consultar_contador()<60)
			{
			ob->siguiente_destino();
			str="Ok, cuñado.\n Ahora necesitas que te lo sellen en el despacho: ";
			str2=ob->destino()+"\n";
			str=str+str2;
			write(str);
			}// cuño;
		else 	{
			write("El funcionario dice:mmm.. vale está en regla toma el impreso\n");
			if (ob) destruct(ob);
			ob2=clone_object("/d/simauria/comun/objeto/otro/impresof");
			ob2->move(TP);
			write("El funcionario te da el impreso JK23-H.\n");
			}
	}
return 60;
}

create () {
  ::create();
SetLocate("Gorat");
SetIntShort("el despacho 3K");
SetIntLong(
"En este despacho te pueden cuñar o sellar el impreso para obtener el JK-23H "
"El despacho tiene una mesa llena de papeles y un archivador con 8 cajones. "
"solo tienes una salida, al pasillo.\n");
SetIndoors(1);
SetIntBright(30);

AddItem("/d/simauria/comun/pnj/marhalt/funcionario2",REFRESH_ALWAYS,1);
AddExit("pasillo","./pasillo36");
}


init(){
add_action("hacer_cunyar","cuñar");
add_action("hacer_cunyar","cunyar");
add_action("hacer_cunyar","sellar");
::init();}
