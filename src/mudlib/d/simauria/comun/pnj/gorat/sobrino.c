/***************************************************************************************
 ARCHIVO:	sobrino.c
 AUTOR:		[z] Zomax
 FECHA:		25-03-2002
 COMENTARIOS:	El sobrino de Leyma
 MODIFICACIÓN:  Añado un Owner
 ***************************************************************************************/

#include "./path.h"
#include <moving.h>
#include <properties.h>
#include <races.h>
inherit NPC;


int alimentado,cogido,i;
string powner;
object *cosas;

public void SetOwner(string name) { powner = name; }

public string QueryOwner() { return powner; }

create(){
    ::create();
    SetStandard("un niño", "humano",1,GENERO_MASCULINO);
    SetAlign(300);
    SetWeight(11000);

    SetIds(({"humano","niño","ninyo","sobrino de leyma","sobrino de Leyma","bebe",
        "bebé","sobrino"}));
    SetShort("un niño pequeño");
    SetLong("Es el sobrino de Leyma, el parecido con su tía es excepcional. \n "
        " No tiene buena cara, algo le debe de ocurrir, se le nota muy nervioso y "
        "No cesa de lloriquear.\n");
    Set(P_CANT_LURE,1);
    InitChats(4,({"El niño llora: Buuuuaaaahhhhhhh\n",
		"El niño dice: ¡Teno hambre!\n",
		"El niño berrea: ¡Teno fíooo!\n",
	    "El niño está inquieto.\n", "El niño parece enfermo.\n",
	    "El niño lloriquea.\n",
		"El niño se queja: Buaa, ¡hip!, ¡Buaaahhhhhh!n"}));
    alimentado=0;
}

init(){
    ::init();
    add_action("fdar","curar");
    add_action("fdar","alimentar");
    add_action("fdar","dar");
    add_action("fcoger","coger");
    if (environment() && living(environment()) && environment(TO)->id("ladron"))
  	  TO->remove();
    if (!environment(TO)->QueryIsPlayer() && cogido)
  	cogido=0;
}

int fdar(string str)
{
	if (cogido) return 0;
	if (query_verb()=="alimentar" && (!str || strlen(str)<3))
	{
		write("¿Alimentar a <quién>?\n");
		return 1;
	}
	if (query_verb()=="dar" && (!str || strlen(str)<10))
	{
		write("¿Dar <qué> a <quién>?\n");
		return 1;
	}
	str=lower_case(str);
	if ((query_verb()=="alimentar" && (str[0..1]=="a " && id(str[2..]))) || (query_verb()=="dar" && (str[0..9]=="papilla a " && id(str[10..]))))
	{
		if (present("papilla de lenguaron",TP) && !alimentado)
		{
			write("Después de forcejear con el bebé consigues que se coma la papilla.\n"
			" notas como eructa y poco a poco se va quedando dormido. Lo coges en brazos.\n");
			say(TP->QueryName()+" le da de comer al bebé con mucha dificultad.\nEl"
			" niño se queda dormido y lo coge en brazos.\n",TP);
			present("papilla de lenguaron",TP)->remove();
			InitChats(0,({}));
			alimentado=1;
			cosas=all_inventory(TP);
			for(i=0;i<sizeof(cosas);i++)
			// por cortesía y coherencia le dejo los objetos de quest, lo que use para iluminarse, 
			//lo que lleve de vestimenta y el dinero
        if (!(cosas[i]->QueryGuild() || cosas[i]->id("dinero") || cosas[i]->QueryBurning()
           || (cosas[i]->QueryEquipped() && cosas[i]->QueryArmourType())))
				cosas[i]->move(environment(TP),M_SILENT);
			write("Con la poca experiencia que tienes en coger niños te da la impresión que "
			"se te han caído algunas cosas.\n");
			say(CAP(TNAME)+ " no parece que se aclare mucho con el niño y no puede evitar "
			"que se le caigan algunas cosas.\n",TP);
			cogido=1;
			TO->SetOwner(TP->QueryRealName());
			TO->move(TP,M_SILENT);
			return 1;
		}
		else if (present("papilla de lenguaron",TP) && alimentado)
		{
			write("No deberías despertarle... está profundamente dormido.\n");
			return 1;
		}
		else
		{
			write("El bebé se enfada porque no tienes nada de comer que le guste y te "
			"escupe a la cara. De paso te pega un bocado en la mano como recuerdo.\n");
			say("El bebé se enfada cuando "+TP->QueryName()+" intenta "
				"darle de comer algo que no le gusta.\n"),TP;
			return 1;
		}
	}
}

int fcoger(string str)
{
	if (TO->id(str) && !alimentado && !cogido)
	{
		write("El niño está demasiado inquieto para que lo puedas coger.\n");
		return 1;
	}
	else if (TO->id(str) && TO->QueryOwner() && TO->QueryOwner()!=TP->QueryRealName())
	{
		write("El bebé no te reconoce y te escupe en la cara.\n");
		say("El bebé no reconoce a "+TP->QueryName()+" y le escupe en la cara.\n",TP);
		return 1;
	}
	else if (cogido)
	{
		write("No puedes coger nada. Ya tienes suficiente con el bebé y no "
		"quieres que se despierte.\n");
		return 1;
	}
}

public varargs int move(mixed destino,int metodo,mixed extra)
{
	if (environment(TO) && environment(TO)->QueryIsPlayer())
	{
		tell_object(environment(TO),"Suavemente lo coges, lo meces y vuelve a dormirse.\n");
		return ME_NO_ENTER;
	}
	else	return ::move(destino,metodo,extra);
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras){
    object guarda;
 	guarda = present("guarda");
    if (guarda && living(guarda)) guarda->Kill(TP);
    return ::Defend(dam, dam_type, flags, &xtras);
}

