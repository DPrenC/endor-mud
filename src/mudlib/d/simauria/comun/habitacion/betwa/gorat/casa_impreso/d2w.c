
#include "./path.h"

inherit SIM_ROOM;
//cu�ar el papelejo,
hacer_cunyar(){
object ob, ob2;
string str,str2;
if (!ob=present("impresot",TP)){
	write("Pide el impreso temporal en el despacho d1a.\n");}
	else
		{if (ob->destino()!="d2w"){
			str="Lo siento tienes que ir al despacho ";
			str2=ob->destino();
			str=str+str2;
			write(str);
			write(".\n");}
		else if (ob->consultar_contador()<60)
			{
			ob->siguiente_destino();
			str="Ok, cu�ado.\n Ahora necesitas que te lo sellen en el despacho: ";
			str2=ob->destino()+"\n";
			str=str+str2;
			write(str);
			}// cu�o;
		else 	{
			write("El funcionario dice:mmm.. vale est� en regla toma el impreso\n");
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
SetIntShort("el despacho 2W");
SetIntLong(
"En este despacho te pueden cu�ar o sellar el impreso para obtener el JK-23H "
"El despacho tiene una mesa llena de papeles y un archivador con 8 cajones. "
"solo tienes una salida, al pasillo.\n");
SetIndoors(1);
SetIntBright(30);

AddItem("/d/simauria/comun/pnj/marhalt/funcionario2",REFRESH_ALWAYS,1);
AddExit("pasillo","./pasillo212");
}


init(){
add_action("hacer_cunyar","cu�ar");
add_action("hacer_cunyar","cunyar");
add_action("hacer_cunyar","sellar");
::init();}
