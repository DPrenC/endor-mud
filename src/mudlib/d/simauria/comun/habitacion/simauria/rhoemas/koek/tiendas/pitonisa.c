/***************************************************************************************
 ARCHIVO:	pitonisa.c
 AUTOR:		[z] Zomax
 FECHA:		21-12-2001
 COMENTARIOS:	Pitonisa, planta baja.
 MODIFICACION:	21-03-2003 Añado cosas para el quest de Draego.
 		09-04-2003 Sigo añadiendo para el quest.
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
  SetIntNoise("No oyes nada especial por aquí.\n");
  SetIntLong(W("Estás en la consulta de la pitonisa Fowla de Koek, famosa en todo "
  	"el reino de Simauria. La habitación en la que te encuentras tiene un aire "
  	"bastante siniestro. Está todo muy oscuro exceptuando una pequeña mesa "
  	"redonda sobre la cual hay una brillante bola que usa Fowla para poder "
  	"predecir el futuro de las personas que no tengan inconveniente en pagar "
  	"por conocerlo. En una de las paredes laterales observas una estantería "
  	"con pequeños frascos de distintos colores que la pitonisa usa para ayudar "
  	"a sus clientes.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy normal, hecho con tablones de madera "
  	"un poco gastados por el paso de los clientes.\n"));
  AddDetail(({"pared","paredes"}),W("No hay ningún tipo de decoración, solo ves "
  	"una estantería con frascos de distintos colores.\n"));
  AddDetail(({"techo"}),"Un techo de lo más normal, hecho de tablones de madera.\n");
  AddDetail(({"bola","mesa","mesa redonda","bola de cristal"}),W("Hay una gran bola "
  	"de cristal encima de la mesa. Parece que por momentos ves algo en su interior, "
  	"o solo será que el ambiente de este sitio te está afectando.\n"));
  AddDetail(({"cartel","horario"}),W("Hay un pequeño cartel colgado en el que "
  	"pone el horario de consulta. Deberías leerlo.\n"));
  AddReadMsg(({"cartel","horario"}),("\n"
  "       *-------------------------------------------------------*\n"
  "       |                                                       |\n"
  "       |    [36mTabla de Horarios de la Consulta de la Pitonisa[0m    |\n"
  "       |                                                       |\n"
  "       |    El horario de la apertura de la consulta es desde  |\n"
  "       |    las [52m7[0m de la mañana a las [52m12[0m de la noche todos      |\n"
  "       |    los días. Para recibir consulta escribe [52mconsulta[0m.  |\n"
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
        	write(W("Le das el zafiro a Fowla, que ilumina su mirada más aún que cuando le compras "
        	"un pergamino.\nFowla dice: ¡Si! ¡este es!, sabía que podía contar contigo, mis poderes "
        	"me dijeron que confiara en tí... espero que mi hermana no te haya lanzado ninguna maldición, "
        	"ya te dije que era muy poderosa... casi tanto como yo. Veamos... que te prometí... ¡ah si!, ¡la "
        	"copa!... Vaya pues al ratito de irte recordé que Draego se la dejó aquí mismo en una de sus "
        	"visitas... que curioso, ¿no?. Toma venga, te la doy.\nFowla sonríe con picaresca.\n"));
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
		write(W("No puedes coger la bola de cristal, está demasiado "
			"sujeta a la mesa.\n"));
		say(W(CATP+" ha intentado coger la bola de cristal sin éxito.\n"),TP);
		return 1;
	}
	else if (str=="frascos" || str=="frasco")
	{
		write(W("Piensas en coger los frascos de la estantería, pero mejor no. "
			"Además, no sabrías qué contienen y pueden ser venenosos. Mejor "
			"compras como todo el mundo.\n"));
		say(W(CATP+" intenta coger un frasco de la estantería, pero retrocede "
			"a tiempo. Quién sabe qué contendría. Parece que ahora piensa "
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
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qué tiene que ver esto con "
			"tu pasado.\n"));
		say(W("Fowla le lee el pasado a "+CATP+". Ahora se le ve más pensativ"+AO+".\n"),TP);
		present("pergamino del pasado",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla dice: Para que pueda entrar en trance debes comprarme "
		"el pergamino del pasado y dármelo en este momento. Será mejor que lo "
		"hagas, sino no conseguiré conectar con los espíritus del pasado.\n"));
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
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qué tiene que ver esto contigo.\n"));
		say(W("Fowla le lee el presente a "+CATP+". Ahora se le ve más pensativ"+AO+".\n"),TP);
		present("pergamino del presente",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla dice: Para que pueda entrar en trance debes comprarme "
		"el pergamino del presente y dármelo en este momento. Será mejor que lo "
		"hagas, sino no conseguiré conectar con los espíritus.\n"));
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
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qué tiene que ver esto con "
			"tu futuro.\n"));
		say(W("Fowla le predice el futuro a "+CATP+". Ahora se le ve más pensativ"+AO+".\n"),TP);
		present("pergamino del futuro",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito más fuerza... cómprame el pergamino "
		"del futuro y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del futuro para ver si así "
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
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qué tiene que ver esto con "
			"el dinero.\n"));
		say(W("Fowla le predice su suerte con el dinero a "+CATP+". Ahora se le ve más pensativ"+AO+".\n"),TP);
		present("pergamino del dinero",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito más fuerza... cómprame el pergamino "
		"del dinero y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del dinero para ver si así "
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
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar. Empiezas a pensar qué tiene que ver esto con "
			"el amor.\n"));
		say(W("Fowla le predice su suerte en el amor a "+CATP+". Ahora se le ve más pensativ"+AO+".\n"),TP);
		present("pergamino del amor",TP)->remove();
		return 1;
	}
	else
	{
		write(W("Fowla se concentra... de repente suelta un grito y dice: "
		"No puedo, no puedo... necesito más fuerza... cómprame el pergamino "
		"del amor y lo intentamos de nuevo.\n"));
		say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
		"a "+CATP+" que le compre el pergamino del amor para ver si así "
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
							"lo dejamos para otro día.\n"));
							return 0; break;
				}
			}
			else
			{
				write(W(
				"Fowla te informa de los diferentes tipos de consultas "
				"que puede ofrecerte:\n"
				"\n"
				"[36mPasado:[0m Te puedo leer tu pasado. Te diré cosas de tu pasado "
				"para que recuerdes quien eras y por qué ahora eres quien "
				"eres. Para eso compra el pergamino del pasado y escribe "
				"[52mconsulta pasado[0m.\n"
				"\n"
				"[36mPresente:[0m Nadie como yo podrá decirte con tanta claridad "
				"quien eres y como te encuentras ahora exactamente. Ni "
				"siquiera tú mismo. Si quieres eso compra el pergamino del "
				"presente y escribe [52mconsulta presente[0m.\n"
				"\n"
				"[36mFuturo:[0m Ah... el futuro... quién sabe lo que te deparará... "
				"si quieres saber más compra el pergamino del futuro y "
				"escribe [52mconsulta futuro[0m.\n"
				"\n"
				"[36mObjeto:[0m ¿Has perdido algo? Sin duda mis dotes mágicas "
				"pueden encontrarlo. Sólo tienes que comprar el pergamino de objetos perdidos "
				"y escribe [52mencontrar <objeto>[0m.\n"
				"\n"
				"[36mDinero:[0m Ah... dinero dinero... la eterna pregunta. Si quieres "
				"saber más compra el pergamino del dinero y escribe [52mconsulta dinero[0m.\n"
				"\n"
				"[36mAmor:[0m Amor... amor... amor. Si quieres saber más compra el pergamino "
				"del amor y escribe [52mconsulta amor[0m.\n"));
				say(W("Fowla informa a "+CATP+" de los tipos de consultas que ofrece.\n"),TP);
				return 1;
			}
		}
		else
		{
			notify_fail(W("No hay nadie que esté en condiciones de "
			"pasar consulta aquí.\n"));
			return 0;
		}
	}
	else
	{
		notify_fail("Aquí no hay nadie que pueda pasar consulta.\n");
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
			write(W("Fowla entra en trance y después de mirarte fijamente "
			"dice: Los grandes dioses de la adivinación me han revelado que "
			"el objeto que buscas está precisamente en tu inventario.\nAl momento "
			"vuelve en si y exclama: ¡Cada día se me da mejor esto!\n"));
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
				"despierta y dice: Vaya vaya... esto es bastante preciado, ¿no?. Vale "
				"más que las míseras monedas que has pagado por el pergamino. Si quieres "
				"saber donde puedes encontrar esto me tendrás que hacer un pequeño favor.\n\n"
				"Verás, hace mucho tiempo mi hermana se fue no sin antes llevarse "
				"consigo el único recuerdo que nos quedaba de nuestra madre, un zafiro con "
				"forma de gota de agua, que por cierto dejó a mi cuidado, por mucho que diga "
				"ella...pff.. El caso es que quiero que me lo devuelvas, que bien vale el favor "
				"que te haré si me lo traes. Como mi hermana es muy poderosa lo único que puedo "
				"ver a través de mis magníficos poderes IN-FA-LI-BLES es que está en un sitio "
				"oscuro con muy mal aura. Esta Shiran... cuándo aprenderá que las reliquias "
				"familiares me las dió mamá a mi...\n"));
				quest+=(["copa":1]);
			}
			else
			{
				write(W("Ya te he dicho qué tenías que hacer para recuperar la copa. Traemé "
				"la joya que te pedí y veré lo que mis poderes pueden hacer por tí.\n"));

			}
			return 1;
		}
		else if (present("pergamino de objeto",TP))
		{
			string proverbio;
			proverbio=read_file(RHOETXT("proverbios/objeto.t"),1+random(15),1);
			write(W("Fowla se concentra. De repente sus ojos se vuelven blancos "
			"y un aura extraña se apodera del lugar. Sus labios empiezan "
			"a moverse y logras descifrar una sola frase de todo lo que "
			"dice. Es algo así como:\n\n"
			"[36m"+capitalize(proverbio)+"[0m\n"
			"No sabes muy bien qué pensar, pero visto lo visto decides "
			"no replicar.\n\nFowla dice: Es una lástima que no puedas comprobar que lo "
			"que digo es cierto, ¿no?\n"));
			say(W("Fowla entra en trance y le dice algo a "+CATP+". Ahora se le "
			"ve más pensativ"+AO+".\n"),TP);
			present("pergamino de objeto",TP)->remove();
			return 1;
		}
		else
		{
			write(W("Fowla se concentra... de repente suelta un grito y dice: "
			"No puedo, no puedo... necesito más fuerza... cómprame el pergamino "
			"de objeto y lo intentamos de nuevo.\n"));
			say(W("Fowla intenta concentrarse, pero no lo consigue. Le pide "
			"a "+CATP+" que le compre el pergamino de objeto para ver si así "
			"se concentra mejor.\n"),TP);
			return 1;
		}
	}
	else
	{
		write("No hay nadie aquí a quien puedas preguntar.\n");
		return 1;
	}
}
