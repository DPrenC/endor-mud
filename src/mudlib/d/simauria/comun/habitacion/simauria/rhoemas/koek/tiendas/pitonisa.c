/***************************************************************************************
 ARCHIVO:	pitonisa.c
 AUTOR:		[z] Zomax
 FECHA:		21-12-2001
 COMENTARIOS:	Pitonisa, planta baja.
 MODIFICACION:	21-03-2003 A�ado cosas para el quest de Draego.
 		09-04-2003 Sigo a�adiendo para el quest.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

inherit RHOESTD("shop");

create () {
 ::create();

  SetLocate("Koek");
  SetIntShort("la consulta de la pitonisa");
  SetIntSmell(W("Huele a incienso y otras cosas que la pitonisa suele prender para "
  	"'crear ambiente'.\n"));
  SetIntNoise("No oyes nada especial por aqu�.\n");
  SetIntLong(W("Est�s en la consulta de la pitonisa Fowla de Koek, famosa en todo "
  	"el reino de Simauria. La habitaci�n en la que te encuentras tiene un aire "
  	"bastante siniestro. Est� todo muy oscuro exceptuando una peque�a mesa "
  	"redonda sobre la cual hay una brillante bola que usa Fowla para poder "
  	"predecir el futuro de las personas que no tengan inconveniente en pagar "
  	"por conocerlo. En una de las paredes laterales observas una estanter�a "
  	"con peque�os frascos de distintos colores que la pitonisa usa para ayudar "
  	"a sus clientes.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "
  	"un poco gastados por el paso de los clientes.\n"));
  AddDetail(({"pared","paredes"}),W("No hay ning�n tipo de decoraci�n, solo ves "
  	"una estanter�a con frascos de distintos colores.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal, hecho de tablones de madera.\n");
  AddDetail(({"bola","mesa","mesa redonda","bola de cristal"}),W("Hay una gran bola "
  	"de cristal encima de la mesa. Parece que por momentos ves algo en su interior, "
  	"o solo ser� que el ambiente de este sitio te est� afectando.\n"));
  AddDetail(({"cartel","horario"}),W("Hay un peque�o cartel colgado en el que "
  	"pone el horario de consulta. Deber�as leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |    [36mTabla de Horarios de la Consulta de la Pitonisa[0m    |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la consulta es desde  |\n"
  "       |    las [52m7[0m de la ma�ana a las [52m12[0m de la noche todos      |\n"
  "       |    los d�as. Para recibir consulta escribe [52mconsulta[0m.  |\n"
  "       |                                                       |\n"
  "       |                                               [50mFowla[0m   |\n"
  "       *-------------------------------------------------------*\n"));
  AddExit("oeste",RHOEHAB("koek/calles/cendaf_00"));
  h1=7;
  h2=24;
  pnj="koek/tiendas/fowla";
  fcosas("pitonisa");
  carcel=(RHOEHAB("koek/calles/cendaf_00"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("consulta","fconsulta");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("dar","fdar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  AddRoomCmd("encontrar","fencontrar");
}

public int fdar(string str)
{
	string que, quien;
	object pitonisa=present("fowla",TO);
	object zafiro=present("zafiro lagrima",TP);
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (!str) return 0;
	else lower_case(str);

	if (sscanf(str,"%s a %s", que, quien) != 2) return 0;
	if (!pitonisa || !living(pitonisa) || !pitonisa->id(quien)) return 0;
	else if (!zafiro || !zafiro->id(que)) return 0;
        else if (quest && member(quest,"copa") && quest["copa",0]==6)
        {
        	write(W("Le das el zafiro a Fowla, que ilumina su mirada m�s a�n que cuando le compras "
        	"un pergamino.\nFowla dice: �Si! �este es!, sab�a que pod�a contar contigo, mis poderes "
        	"me dijeron que confiara en t�... espero que mi hermana no te haya lanzado ninguna maldici�n, "
        	"ya te dije que era muy poderosa... casi tanto como yo. Veamos... que te promet�... �ah si!, �la "
        	"copa!... Vaya pues al ratito de irte record� que Draego se la dej� aqu� mismo en una de sus "
        	"visitas... que curioso, �no?. Toma venga, te la doy.\nFowla sonr�e con picaresca.\n"));
        	zafiro->remove();
        	clone_object(RHOEVAR("koek/varios/copa"))->move(TP,M_NOCHECK);
        	quest+=(["copa":7]);
        	return 1;
        }
}

public int fcoger(string str)
{
	if (str=="bola" || str=="bola de cristal")
	{
		write(W("No puedes coger la bola de cristal, est� demasiado "
			"sujeta a la mesa.\n"));
		say(W(CATP+" ha intentado coger la bola de cristal sin �xito.\n"),TP);
		return 1;
	}
	else if (str=="frascos" || str=="frasco")
	{
		write(W("Piensas en coger los frascos de la estanter�a, pero mejor no. "
			"Adem�s, no sabr�as qu� contienen y pueden ser venenosos. Mejor "
			"compras como todo el mundo.\n"));
		say(W(CATP+" intenta coger un frasco de la estanter�a, pero retrocede "
			"a tiempo. Qui�n sabe qu� contendr�a. Parece que ahora piensa "
			"en comprarlo.\n"));
		return 1;
	}
}

public int fleer_pasado()
{
	if (present("pergamino del pasado",TP))
	{
		string proverbio;
		proverbio=read_file(RHOETXT("proverbios/pasado.t"),1+random(20),1);
		write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qu� tiene que ver esto con "
			"tu pasado.\n"));
		say(W("Fowla le lee el pasado a "+CATP+". Ahora se le ve m�s pensativ"+AO+".\n"),TP);
		present("pergamino del pasado",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla dice: Para que pueda entrar en trance debes comprarme "
		"el pergamino del pasado y d�rmelo en este momento. Ser� mejor que lo "
		"hagas, sino no conseguir� conectar con los esp�ritus del pasado.\n"));
		say(W("Fowla le dice a "+CATP+" que primero tiene que comprar el "
		"pergamino del pasado para poder concentrarse.\n"),TP);
		return 1;
	}
}

public int fleer_presente()
{
	if (present("pergamino del presente",TP))
	{
		string proverbio;
		proverbio=read_file(RHOETXT("proverbios/presente.t"),1+random(20),1);
		write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qu� tiene que ver esto contigo.\n"));
		say(W("Fowla le lee el presente a "+CATP+". Ahora se le ve m�s pensativ"+AO+".\n"),TP);
		present("pergamino del presente",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla dice: Para que pueda entrar en trance debes comprarme "
		"el pergamino del presente y d�rmelo en este momento. Ser� mejor que lo "
		"hagas, sino no conseguir� conectar con los esp�ritus.\n"));
		say(W("Fowla le dice a "+CATP+" que primero tiene que comprar el "
		"pergamino del presente para poder concentrarse.\n"),TP);
		return 1;
	}
}

int fleer_futuro()
{
	if (present("pergamino del futuro",TP))
	{
		string proverbio;
		proverbio=read_file(RHOETXT("proverbios/futuro.t"),1+random(20),1);
		write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qu� tiene que ver esto con "
			"tu futuro.\n"));
		say(W("Fowla le predice el futuro a "+CATP+". Ahora se le ve m�s pensativ"+AO+".\n"),TP);
		present("pergamino del futuro",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito m�s fuerza... c�mprame el pergamino "
		"del futuro y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del futuro para ver si as� "
		"se concentra mejor.\n"),TP);
		return 1;
	}
}

public int fleer_dinero()
{
	if (present("pergamino del dinero",TP))
	{
		string proverbio;
		proverbio=read_file(RHOETXT("proverbios/dinero.t"),1+random(20),1);
		write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qu� tiene que ver esto con "
			"el dinero.\n"));
		say(W("Fowla le predice su suerte con el dinero a "+CATP+". Ahora se le ve m�s pensativ"+AO+".\n"),TP);
		present("pergamino del dinero",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito m�s fuerza... c�mprame el pergamino "
		"del dinero y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del dinero para ver si as� "
		"se concentra mejor.\n"),TP);
		return 1;
	}
}

public int fleer_amor()
{
	if (present("pergamino del amor",TP))
	{
		string proverbio;
		proverbio=read_file(RHOETXT("proverbios/amor.t"),1+random(20),1);
		write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qu� tiene que ver esto con "
			"el amor.\n"));
		say(W("Fowla le predice su suerte en el amor a "+CATP+". Ahora se le ve m�s pensativ"+AO+".\n"),TP);
		present("pergamino del amor",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito m�s fuerza... c�mprame el pergamino "
		"del amor y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del amor para ver si as� "
		"se concentra mejor.\n"),TP);
		return 1;
	}
}

public int fconsulta(string str)
{
	if (present("Fowla",TO))
	{
		if (living(present("Fowla",TO)))
		{
			if (str=="pasado" || str=="presente" || str=="futuro" || str=="dinero" || str=="amor")
			{
				switch (str)
				{
					case "pasado":	write("Consultas a Fowla sobre tu pasado.\n");
							say(W(CATP+" consulta a Fowla sobre su pasado.\n"),TP);
							fleer_pasado();
							return 1;
							break;
					case "presente":write("Consultas a Fowla sobre tu presente.\n");
							say(W(CATP+" consulta a Fowla sobre su presente.\n"),TP);
							fleer_presente();
							return 1;
							break;
					case "futuro":	write("Consultas a Fowla sobre tu futuro.\n");
							say(W(CATP+" consulta a Fowla sobre su futuro.\n"),TP);
							fleer_futuro();
							return 1;
							break;
					case "dinero":  write("Consultas a Fowla sobre el dinero.\n");
							say(W(CATP+" consulta a Fowla sobre el dinero.\n"),TP);
							fleer_dinero();
							return 1;
							break;
					case "amor":    write("Consultas a Fowla sobre el amor.\n");
							say(W(CATP+" consulta a Fowla sobre el amor.\n"),TP);
							fleer_amor();
							return 1;
							break;
					default:	notify_fail(W("Espera... me siento un poco mal... "
							"lo dejamos para otro d�a.\n"));
							return 0; break;
				}
			}
			else
			{
				write(W(
				"Fowla te informa de los diferentes tipos de consultas "
				"que puede ofrecerte:\n"
				"\n"
				"[36mPasado:[0m Te puedo leer tu pasado. Te dir� cosas de tu pasado "
				"para que recuerdes quien eras y por qu� ahora eres quien "
				"eres. Para eso compra el pergamino del pasado y escribe "
				"[52mconsulta pasado[0m.\n"
				"\n"
				"[36mPresente:[0m Nadie como yo podr� decirte con tanta claridad "
				"quien eres y como te encuentras ahora exactamente. Ni "
				"siquiera t� mismo. Si quieres eso compra el pergamino del "
				"presente y escribe [52mconsulta presente[0m.\n"
				"\n"
				"[36mFuturo:[0m Ah... el futuro... qui�n sabe lo que te deparar�... "
				"si quieres saber m�s compra el pergamino del futuro y "
				"escribe [52mconsulta futuro[0m.\n"
				"\n"
				"[36mObjeto:[0m �Has perdido algo? Sin duda mis dotes m�gicas "
				"pueden encontrarlo. S�lo tienes que comprar el pergamino de objetos perdidos "
				"y escribe [52mencontrar <objeto>[0m.\n"
				"\n"
				"[36mDinero:[0m Ah... dinero dinero... la eterna pregunta. Si quieres "
				"saber m�s compra el pergamino del dinero y escribe [52mconsulta dinero[0m.\n"
				"\n"
				"[36mAmor:[0m Amor... amor... amor. Si quieres saber m�s compra el pergamino "
				"del amor y escribe [52mconsulta amor[0m.\n"));
				say(W("Fowla informa a "+CATP+" de los tipos de consultas que ofrece.\n"),TP);
				return 1;
			}
		}
		else
		{
			notify_fail(W("No hay nadie que est� en condiciones de "
			"pasar consulta aqu�.\n"));
			return 0;
		}
	}
	else
	{
		notify_fail("Aqu� no hay nadie que pueda pasar consulta.\n");
		return 0;
	}
}

public int fencontrar(string str)
{
	if (!str)
	{
		notify_fail("Encontrar <cosa>\n");
		return 0;
	}
	else if (present("Fowla",TO) && living(present("Fowla",TO)))
	{
		mapping quest=(TP->QueryAttribute("DraegoQuest"));

		str=lower_case(str);

		if (present("pergamino de objeto",TP) && present(str,TP))
		{
			write(W("Fowla entra en trance y despu�s de mirarte fijamente "
			"dice: Los grandes dioses de la adivinaci�n me han revelado que "
			"el objeto que buscas est� precisamente en tu inventario.\nAl momento "
			"vuelve en si y exclama: �Cada d�a se me da mejor esto!\n"));
			say(W("Fowla entra en trance y le dice algo a "+CATP+".\n"),TP);
			present("pergamino de objeto",TP)->remove();
			return 1;
		}
		else if (quest && member(quest,"copa") && present("pergamino de objeto",TP) && (str=="copa" || str=="copa de kaleband" || str=="copa ceremonial"))
		{
			if (!quest["copa",0])
			{
				present("pergamino de objeto",TP)->remove();
				write(W("Fowla entra en trance y se queda perpleja.\n\nAl momento "
				"despierta y dice: Vaya vaya... esto es bastante preciado, �no?. Vale "
				"m�s que las m�seras monedas que has pagado por el pergamino. Si quieres "
				"saber donde puedes encontrar esto me tendr�s que hacer un peque�o favor.\n\n"
				"Ver�s, hace mucho tiempo mi hermana se fue no sin antes llevarse "
				"consigo el �nico recuerdo que nos quedaba de nuestra madre, un zafiro con "
				"forma de gota de agua, que por cierto dej� a mi cuidado, por mucho que diga "
				"ella...pff.. El caso es que quiero que me lo devuelvas, que bien vale el favor "
				"que te har� si me lo traes. Como mi hermana es muy poderosa lo �nico que puedo "
				"ver a trav�s de mis magn�ficos poderes IN-FA-LI-BLES es que est� en un sitio "
				"oscuro con muy mal aura. Esta Shiran... cu�ndo aprender� que las reliquias "
				"familiares me las di� mam� a mi...\n"));
				quest+=(["copa":1]);
			}
			else
			{
				write(W("Ya te he dicho qu� ten�as que hacer para recuperar la copa. Traem� "
				"la joya que te ped� y ver� lo que mis poderes pueden hacer por t�.\n"));

			}
			return 1;
		}
		else if (present("pergamino de objeto",TP))
		{
			string proverbio;
			proverbio=read_file(RHOETXT("proverbios/objeto.t"),1+random(15),1);
			write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extra�a se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo as� como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qu� pensar, pero visto lo visto decides "
			"no replicar.\n\nFowla dice: Es una l�stima que no puedas comprobar que lo "
			"que digo es cierto, �no?\n"));
			say(W("Fowla entra en trance y le dice algo a "+CATP+". Ahora se le "
			"ve m�s pensativ"+AO+".\n"),TP);
			present("pergamino de objeto",TP)->remove();
			return 1;
		}
		else
		{
			write(W("Fowla se concentra... de repente suelta un grito y dice: "
			"No puedo, no puedo... necesito m�s fuerza... c�mprame el pergamino "
			"de objeto y lo intentamos de nuevo.\n"));
			say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
			"a "+CATP+" que le compre el pergamino de objeto para ver si as� "
			"se concentra mejor.\n"),TP);
			return 1;
		}
	}
	else
	{
		write("No hay nadie aqu� a quien puedas preguntar.\n");
		return 1;
	}
}
