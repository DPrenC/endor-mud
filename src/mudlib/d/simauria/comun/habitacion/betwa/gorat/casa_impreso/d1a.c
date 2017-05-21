

#include "./path.h"
#include <moving.h>

inherit SIM_ROOM;
hacer_pedir(string cad1){
object ob;
string donde;
string str;
if (!cad1) {
write("uso pedir <que> para <que>\n");
return 1;}
if (cad1=="impreso"){
ob=clone_object("/d/simauria/comun/objeto/otro/impresot");
ob->inicializa(); //inicia el vector pa que no de errores
ob->siguiente_destino();
donde=ob->destino();
ob->move(TP);
write("El funcionario te da el impreso temporal\n");
str= "El funcionario te dice que te tienen que cuñar el impreso en: ";
str=str+donde+".\n";
write(str);
}
else
write("pedir <que> para <que>\n");
return 1;
}

//cuñar el papelejo
hacer_cunyar(){
object ob, ob2;
string str,str2;
if (!ob=present("impresot",TP)){
	write("Pide el impreso temporal en el despacho d1a.\n");}
	else
		{if (ob) destruct(ob);
		ob=clone_object("/d/simauria/comun/objeto/otro/impresot");
		if ( ob->move(TP,M_SILENT)!=ME_OK )
                ob->move(environment(TP), M_TELEPORT, "Un impreso cae al suelo");
		if (ob->destino()!="d1a"){
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
SetIntShort("el despacho 1A");
SetIntLong("Estas en el primer despacho de la casa del registro de Gorat "
"aqui puedes pedir el impreso que necesitas para conseguir el JK23-H "
"y te dirán dónde puedes ir para conseguirlo. "
"El despacho tiene una mesa llena de papeles y un archivador con 8 cajones. "
"solo tienes una salida, al pasillo.\n");
SetIndoors(1);
SetIntBright(30);

AddItem("/d/simauria/comun/pnj/marhalt/funcionario",REFRESH_ALWAYS,1);
AddExit("pasillo","./pasillo11");
}


init(){
add_action("hacer_pedir","pedir");
add_action("hacer_cunyar","cuñar");
add_action("hacer_cunyar","cunyar");
add_action("hacer_cunyar","sellar");
::init();}
