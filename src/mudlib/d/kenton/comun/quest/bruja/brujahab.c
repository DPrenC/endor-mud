/*
DESCRIPCION  : habitacion de la bruja, te convierte en rana, aqui se guarda tu inv
FICHERO      : /d/kenton/comun/quest/bruja/brujahab.c
MODIFICACION : 18-9-00 [Maler] Creacion.
COMENTARIOS  :	Tengo la misma sensacion q cuando empece a codear el arco, la
				sensacion de ke me voy a pegar la kurrada padre con esto.
--------------------------------------------------------------------------------
*/

inherit ROOM;
#include "path.h"
#include <properties.h>
mapping inv;

public int Guardar_Obs(string str)
{
object *obs,pl;
string name;
int i;
pl=find_object(lower_case(str));
restore_object((string)TO);
if(!pl){write("Has fallado al guardar tus objetos, contacta con algun wiz.\n");
		return 1;
	   }
name=pl->QueryName();

obs=deep_inventory(pl);
if(!obs) write("No tienes nada!!.\n");
for(i=0;i<sizeof(obs);i++)
{
if (!inv)
	inv=([]);
if (!inv[name])
	inv[name]=({(string)obs[i]});

inv[name]+=({(string)obs[i]});
}
save_object((string)TO);
for(i=0;i<sizeof(obs);i++)
{
obs[i]->remove();
}
write("Guardas tus objetos.\n");
say(name+" le deja todos sus objetos a la bruja para que se los guarde.\n");
return 1;
}


public int Retirar_Obs()
{
object ob,ob2,pl;
string name,*obs,nomb,nom;
int i,j;
pl=TP;
restore_object((string)TO);
if(!pl){write("Has fallado a recuperar tus objetos, contacta con algun wiz.\n");
		return 1;
	   }
name=pl->QueryName();
obs=inv[name];
if(!sizeof(obs)) write("La bruja te dice: Tu no me has dado nada.\n");
for(i=1;i<sizeof(obs);i++)
{
nomb=obs[i];
if (sscanf(nomb,"%s#%d",nom)!=1)
write("Ha habido un error al recuperar tus objetos, contacta con algun wiz.\n");
tell_object(find_object("maler"),sprintf("nom es %O\n",nom));
ob=clone_object(nom);
if (!ob)
	return 1;
ob->move(TP);
}
m_delete(inv,name);
write("La bruja te devuelve tus cosas.\n");
save_object((string)TO);
return 1;
}


create() {
  ::create();
  SetIntShort("una choza");
  SetIntLong("Una puta choza.\n");
  AddExit("noroeste","/players/maler/workroom");
  AddItem("./yasmin",REFRESH_REMOVE);
}

init()
{
::init();
add_action("Guardar_Obs","guardar");
add_action("Retirar_Obs","retirar");
}
