#include "./path.h"


//Creacion del comando luz.
luz_cmd(object cay,object own)
{
object *ob;
int i,j;
j=0;
if (cay->QueryLight()!=0) {write("Ya est� encendido.\n");return 1;}
//[m] chequeo q el palo esta empunyao
ob=own->QueryWeapons();
for(i=0;i<sizeof(ob);i++)
{
if(ob[i]==cay)j++;
}

if(j!=0)
{
	cay->SetLight(20);
	tell_object(own,"Gritas en alto la palabra luz, y pocos instantes despu�s, "
	"la gema de cristal en la punta\n"
	"de tu cayado reacciona, ilumin�ndo suavemente a su alrededor.\n"
	"Para apagar el cayado pon 'apagar'.\n");
	tell_room(environment(own),capitalize(own->QueryName())+" grita 'luz'. Acto seguido, "
	"la punta del cayado que empu�a se ilumina levemente.\n",(({own})));
	return 1;
}
else
{
tell_object(own,"Gritas en alto la palabra luz, pero nada pasa. "
	"quiz� debas empu�ar el cayado para hacer eso.\n");
	tell_room(environment(own),capitalize(own->QueryName())+" grita 'luz'.\n "
	"Aparentemente nada pasa, y ves como mira a su alrededor consternado.\n",(({QueryObjectOwner()})));
return 1;
}
}

//Creacion del comando apagar.
apagar_cmd(object cay,object own)
{
object *ob;
int i,j;
j=0;
if(cay->QueryLight()==0)
{
tell_object(own,"Quiz� deber�as encenderlo antes, para ello pon 'luz'.\n");
return 1;
}
//[m] chequeo q el palo esta empunyao
ob=own->QueryWeapons();
for(i=0;i<sizeof(ob);i++)
{
if(ob[i]==cay)j++;
}
if(j==0)
{
cay->SetLight(0);
tell_object(own,"Tu cayado se apaga.\n");
	tell_room(environment(own),capitalize("El cayado de "+own->QueryName())+" se apaga.\n",(({own})));
	return 1;
}
if(j!=0)
{
	cay->SetLight(0);
	tell_object(own,"Gritas en alto la palabra oscuridad.\n"
	"Al instante, el extremo de tu cayado vacila un momento y se apaga lentamente.\n"
	"Para encender el cayado pon 'luz'.\n");
	tell_room(environment(own),capitalize(own->QueryName())+" grita 'oscuridad'.\n"
	"Acto seguido, la punta del cayado que empu�a oscila y se apaga.\n",(({own})));
	return 1;
}
else
{
tell_object(own,"Gritas en alto la palabra oscuridad, pero nada pasa. "
	"quiz� debas empu�ar el cayado para hacer eso.\n");
	tell_room(environment(own),capitalize(own->QueryName())+" grita 'oscuridad'.\n "
	"Aparentemente nada pasa, y ves como mira a su alrededor consternado.\n",(({own})));
return 1;
}
}
//[m]funcion para apagar el cayado al desempu�ar
apagarenc_cmd(object cay,object own)
{
cay->SetLight(0);
tell_object(own,"Al desempu�ar tu cayado ves como la luz oscila y se apaga al perder poder.\n");
	tell_room(environment(own),"La luz en el extremo del cayado de "+capitalize(own->QueryName())+" oscila y se apaga.\n",(({own})));
return 1;
}



