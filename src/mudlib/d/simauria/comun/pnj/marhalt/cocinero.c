/* Cocinero del Castillo de Nandor.
   (c) Cheto@Simauria.
   Revisado por Nemesis.
  16-11-98 (c) anyadido lo necesario para el quest del cocinero, falta que
  identifique dos objetos en lugar de uno.. pero no se como hacerlo
  [woo] Modificado para que no de el error en el putget.c
  [woo] Modificao otra ves.. pa poner acentillos y eso, ya que nadie lo
        hace.
  [k]	19-02-02 Karu a�ade AddQuestions para el quest del sobrino de Leyma y la
	funci�n para darle los ingredientes.
  [n]   Una preguntilla, Karu, si no te sirve de molestia... �"curanderandera"
        lo has puesto as� a posta o es que metiste la gamba? Por si acaso,
	te lo cambio a curandera. Lo que no entiendo es por qu� habla en verso
	como si fuera un personaje de Calder�n...
  [z]   Cambio QueryName() por RealName() en la comprobaci�n del Quest de Leyma.
*/

#include <colours.h>
#include <rooms.h>

#include <properties.h>
#include "./path.h"
#include <combat.h>
#include <moving.h>

inherit NPC;

object arma, armadura;

string fingredientes()
{
	if (!QUESTMASTER->QueryQuestSolved("Cocinero_nandor", TP))
	return "Nattan te dice: 'D�jame, tengo demasiados problemas como para atender tambi�n los tuyos.'\n";
	else return "Nattan te dice: 'Para que los ingredientes de la papilla puedas saber, "
	  "a la curandera tendr�s que ver. Y cuando los ingredientes tengas ya, a mi me los "
		"tendr�s que dar.'\n";
}

create()
{
  ::create();
SetStandard("Nattan", "humano", 15, GENDER_MALE);
SetCitizenship("nandor");
SetShort("Nattan, el cocinero");
SetLong("Nattan es un cocinero realmente bueno, aunque su aspecto f�sico deja un poco "
"que desear: es un hombre gordo y bastante grande, a juego con la enorme "
"cocina donde trabaja.\n");
AddId(({"cocinero", "hombre", "gordo"}));
AddQuestion(({"pescado","cocinar", "problema", "problemas"}),
"El cocinero te dice: 'El se�or de la villa me ha  pedido at�n asado para "
"cenar, pero en la despensa tengo de todo menos pescado, as� que no podr� prepararlo y me "
"expulsar� de su cuerpo de sirvientes. Si me trajeras un at�n salvar�as mi "
"puesto de trabajo...'\n",1);
AddQuestion(({"atun", "at�n"}), 
    "El cocinero te dice: s�, s�, un at�n bien fresquito es lo que necesito para "
    "solucionar mi problema, �me har�as el favor de ir a pescar uno para m�?\n",1);
    AddQuestion("despensa",
    "Nattan te dice: 'La despensa la puedes encontrar a la entrada de la zona de "
    "servidumbre, por cierto que necesito un at�n para mi se�or, pues la despensa est� "
    "llena de todo tipo de cosas menos pescado.'\n");
    AddQuestion(({"pescar", "pescar at�n", "pescar atun"}), 
    "El cocinero te dice: los atunes se pescan en el mar, ve a la zona de pesca m�s "
    "cercana y no pierdas tiempo que todav�a tengo que cocinarlo.\n",1);
    AddQuestion(({"ingrediente","ingredientes","lista de ingredientes","curandera", 
    "papilla", "receta"}), SF(fingredientes),1);
InitChats(5,({
"El cocinero dice: 'No s� c�mo voy a cocinar el pescado para salvar mi "
"puesto como cocinero....'\n",
"El cocinero llora amargamente.\n",
"El cocinero tiene cara de amargura.\n"}));
InitAChats(10,({"El cocinero dice: '�Te he dicho que no me molestes!'\n"}));

arma=clone_object("/std/weapon");
arma->SetStandard(WT_CUCHILLO, 3, P_SIZE_MEDIUM, M_HIERRO);
arma->Set(P_SHORT, "un cuchillo de cocina");
arma->Set(P_LONG, "Un gran cuchillo de cocina, muy afilado.\n");
AddItem(arma,REFRESH_REMOVE,SF(wieldme));

armadura=clone_object("/std/armour");
armadura->SetStandard(AT_TUNICA, 0, P_SIZE_MEDIUM, M_CUERO);
armadura->Set(P_GENDER, GENDER_MALE);
armadura->Set(P_SHORT, "un delantal de cuero");
armadura->Set(P_LONG, "Un delantal de cuero con manchas de grasa y sangre.\n");
armadura->SetResetQuality(85);
armadura->SetQuality(85);
armadura->SetIds(({"delantal", "delantal de cuero"}));
AddItem(armadura,REFRESH_REMOVE,SF(wearme));

}

// Funciones para el quest (por cierto, peta)


void destruir_atun(object at)
{
	if (at) at->remove();
	return;
}


notify_enter(mixed oldenv, int method, mixed extra)
{
	object p;
	::notify_enter(oldenv,method,extra);

	p=PO;
	if (p->QueryIds())
		if ((p->id("atun")) && !(p->id("qatun")))
		{
			write ("El cocinero dice: 'Lo siento, el at�n que me has traido no est� fresco, tendr�s que pescarme uno.'\n");
			p->move(TI);
			return 42;
		}
	if (p->id("qatun"))
	{
		call_out("destruir_atun",5,p);
		if (QUESTMASTER->QueryQuestSolved("Cocinero_nandor", TP))
		{
			tell_object(TP,"�Ya has resuelto este quest! El cocinero no te olvida.\n");
			write_file (LOGS "COCINERO",ctime(time())+TP->QueryRealName()+" ["+
			TP->QueryLevel()+"]   Le ha llenado la despensa otra vez al cocinero.\n");
			return 42;
		}
		QUESTMASTER->SetPlayerQuest("Cocinero_nandor",TP);
		tell_object(TP,
		             "Nattan te dice: �Mil gracias! �Nunca te olvidar�!\n");
		QUESTMASTER->InformSolution("��El cocinero Nattan estar� eternamente agradecido a "+
    		TP->QueryName()+"!!\n");
		tell_object(TP,"Has salvado al cocinero,  Felicidades!\n");
		write_file (LOGS "COCINERO",ctime(time())+" "+TP->QueryRealName()+" ["+
		TP->QueryLevel()+"] ha llenado la despensa del cocinero.\n");
		return 42;
	}
}

init(){
  ::init();

  add_action("fdar","dar");
}

int fdar(string str)
{
	string cosa,quien;
	if (!str || (sscanf(str,"%s a %s", cosa, quien) != 2))
	{
		write("�Dar <qu�> a <qui�n>?\n");
		return 1;
	}
	if (present(cosa,TP) && TO->id(quien) && (present(cosa,TP)->id("caldero de la ermita") || present(cosa,TP)->id("agua del darmaii") || present(cosa,TP)->id("musgo de flenton") || present(cosa,TP)->id("lenguaron")))
	{
		int *attr;
		object p,papilla;
		p=present(cosa,TP);

		if (!QUESTMASTER->QueryQuestSolved("Cocinero_nandor", TP))
		{
			write("Nattan dice: 'No tengo tiempo para cocinar... tengo demasiados "
			"problemas como para perder el tiempo.'\n");
			return 1;
		}
		if(p->QueryOwner()!=TP->QueryRealName())
		{
			write("No me gusta ese objeto... Tra�me otro, y esta vez aseg�rate PERSONALMENTE de que est� bien.\n");
	          	return 1;
		}
		attr=TP->QueryAttribute("Alimentar_sobrino_Leyma");
		if (!attr || !sizeof(attr) || sizeof(attr)!=4)
			attr=allocate(4);
		if (attr[0]==1 && attr[1]==1 && attr[2]==1 && attr[3]==1)
		{
			write("Nattan te dice: 'Ya te he cocinado la papilla, �qu� m�s quieres?'\n");
			return 1;
		}
		if (p->id("caldero de la ermita"))
		{
			if (attr[0])
			{
				write("Nattan dice: 'Esto ya me lo hab�as dado antes, necesito "
				"el resto de los ingredientes.'\nNattan dice: Se lo a�adir� de todas "
				"formas.'\n");
				say(TP->QueryName()+" le da algo a Nattan.\n",TP);
				p->remove();
				return 1;
			}
			else attr[0]=1;
			p->remove();
		}
		else if (p->id("agua del darmaii"))
		{
			if (attr[1])
			{
				write("Nattan dice: 'Esto ya me lo hab�as dado antes, necesito "
				"el resto de los ingredientes.'\nNattan dice: 'En fin, un poco m�s "
				"tampoco creo que le haga ning�n mal...'\n");
				say(TP->QueryName()+" le da algo a Nattan.\n",TP);
				p->remove();
				return 1;
			}
			else attr[1]=1;
			p->remove();
		}
		else if (p->id("lenguaron"))
		{
			if (attr[2])
			{
				write("Nattan dice: 'Esto ya me lo hab�as dado antes, necesito "
				"el resto de los ingredientes.'\nNattan dice: 'Se lo a�adir� de todas "
				"formas.'\n");
				say(TP->QueryName()+" le da algo a Nattan.\n",TP);
				p->remove();
				return 1;
			}
			else attr[2]=1;
			p->remove();
		}
		else
		{
			if (attr[3])
			{
				write("Nattan dice: 'Esto ya me lo hab�as dado antes, necesito "
				"el resto de los ingredientes.'\nNattan dice: 'Se lo a�adir� de todas "
				"formas.'\n");
				say(TP->QueryName()+" le da algo a Nattan.\n",TP);
				p->remove();
				return 1;
			}
			else attr[3]=1;
			p->remove();
		}
		if (attr[0] && attr[1] && attr[2] && attr[3])
		{
			if (environment(TO))
			tell_room(environment(TO),"Nattan dice: 'Bien bien... "
			"esto est� casi listo... ahora mismo lo preparo.'\n");
			write("Nattan te da una extra�a papilla.\n");
			say("Nattan le da algo a "+capitalize(TP->QueryRealName())+".\n",TP);
			papilla=clone_object("/d/simauria/comun/objeto/otro/papilla");
			papilla->SetOwner(TP->QueryRealName());
			if (papilla->move(TP,M_SILENT)!=ME_OK)
				papilla->move(TO,M_SPECIAL,"cae al suelo");
			return 1;
		}
		else
		{
			write(W("Nattan dice: 'Vas por buen camino... tr�eme el "
			"resto de los ingredientes y lo cocinar�.'\n"));
			TP->SetAttribute("Alimentar_sobrino_Leyma",attr);
			return 1;
		}
	}
}
