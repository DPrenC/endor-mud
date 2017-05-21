/***************************************************************************************
 ARCHIVO:	arik.c
 AUTOR:		[z] Zomax
 FECHA:		02-03-2003
 COMENTARIOS:	Arik el bibliotecario.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 		24-04-2003 Cambio estructura de ifs, que me habia quedado demasiado rara.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit NPC;
#include RHOEDANYO

public string flibros(string str)
{
	string *indice,libro;
	mapping libros;
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"copa"))
	{
		if (quest["copa",0]==2) quest+=(["copa":3]);
		if (quest["copa",0]==3)
		{
			if (environment() && libros=environment()->QueryBooks())
			{
				indice=m_indices(environment()->QueryBooks());
				libro=indice[random(sizeof(indice))];
				quest+=(["libro":to_string(libro)]);
				TP->SetAttribute("DraegoQuest",quest);
				return W("Arik te dice: Veamos... un libro interesante... El "
				"libro más interesante que ha caído en mis manos hasta el momento "
				"ha sido "+to_string(libros[libro,0])+"\n");
			}
			else
				return W("Arik te dice: Pues no se qué recomendarte... déjame que "
				"lo piense un rato.\n");
		}
	}
	else if (quest && member(quest,"libro"))
	{
		if (quest["libro",0]==0) quest+=(["libro":1]);
		if (quest["libro",0]==1)
		{
			return W("Le cuentas a Arik el problema de Draego y le preguntas si puede "
			"conseguir un libro igual al que usan en la ceremonia.\n\nArik te dice: "
			"¡Vaya! este Draego... ya sabía yo que no se podía confiar algo tan preciado "
			"como un libro a ese viejo olvidadizo. La verdad es que no es fácil lo que me "
			"pides, tendría que mover muchos contactos para conseguir uno igual. En los "
			"tiempos que corren es dificil que los enanos vuelvan a forjar la cubierta de "
			"oro y que los elfos lo vuelvan a escribir pero quizás hubiera una posibilidad "
			"si hicieras algo por mi...\n\nVerás... hace muchos años hubo un gran incendio "
			"en la biblioteca del templo. Basicamente es por eso que ya no quedan casi "
			"libros allí salvo los que han reescrito en el poco tiempo que no dedican a "
			"entrenarse. El caso es que se perdieron tres grandes manuscritos entre el "
			"tumulto de la gente. Esos manuscritos estaban protegidos por fuertes hechizos "
			"así que alguien se los debió llevar porque te puedo asegurar que no hubieran "
			"podido perecer en las llamas. Durante estos años en colaboración con el templo "
			"hemos conseguido recuperar dos de ellos, pero el tercero y más poderoso aún no "
			"ha aparecido. Traeme ese manuscrito y haré lo imposible para que tengas el libro "
			"ceremonial. Lo único que puedo decirte es que quien lo robara sabía lo que se "
			"hacía, debió ser un profesional del gremio. Quizás debieras hablar con alguien "
			"que hubiera estado en contacto con ese tipo de gente.\n");
		}
		else return "Arik te dice: ¿Qué, tienes buenas noticias para mi?\n";
	}
	else
	{
		return W("Arik te dice: Todos los libros que ves los he leido. Tengo de "
		"casi todo. Lástima que a la gente de por aquí no le guste mucho visitar "
		"la biblioteca. Si no fuera por el templo casi ni tendría clientes.\n");
	}
}

create(){
  ::create();
  SetStandard("Arik el bibliotecario","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Arik");
  SetIds(({"humano","arik","Arik","bibliotecario"}));
  SetShort("Arik el bibliotecario");
  SetLong(W("Arik es un viejecillo simpático que se encarga de cuidar los libros en la biblioteca "
  	"de Koek. Tiene unas pequeñas lentes para poder leer mejor sus preciados libros mientras "
  	"que los va catalogando y distribuyendo. Se diría que sabe cual es el libro perfecto para "
  	"cada habitante de esta región.\n"));
  AddQuestion(({"guardia","guardias","patrullero","patrulleros"}),W("Arik te dice: Um... esos tipos no son "
  	"muy dados a la lectura. Mejor no te acerques a ellos.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Arik te dice: Es una lástima que no se fomente la lectura en Koek, tengo muy poco trabajo aunque por "
	"otra parte me permite tener tiempo libre para poder disfrutar de un buen sillón y un "
	"mejor libro.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Arik te dice: Tengo por aqui un libro que explicaba... espera a ver si lo encuentro.\nArik se frota el "
	"mentón pensativo.\nArik te dice: Juraría que lo dejé por aquí.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Arik te dice: Encontrarás una pequeña biblioteca en el templo. También soy el encargado de su gestión. "
	"Me paso a arreglarla cada cierto tiempo.\n"),1);
  AddQuestion(({"libro","libros"}),SF(flibros),1);

  InitChats(5,({"Arik se pone las gafas y canturrea mientras ordena los libros.\n",
  		"Arik te mira y dice: ¿Quería algo? ¿Alguna petición especial?.\n",
		"Arik ojea un par de libros pero sientes que te vigila.\n",
		"Arik dice: ¿Ya te has decidido por algo?.\n",
		"Arik dice: Procura devolver los libros o te cobraré recargo.\n",
		"Arik se sienta y lee tranquilamente.\n"}));
  InitAChats(5,({"Arik grita: [52m ¡Guardias! ¡Guardias![0m.\n"}));
}

init(){
  ::init();

  add_action("fdar","dar");
}

public int fdar(string str)
{
	string que,quien;
	object manuscrito=present("brillante manuscrito",TP);
	object arik=TO;
	object libro;
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (str) lower_case(str);
	if (!str || sscanf(str,"%s a %s", que, quien) != 2) return 0;
	else if (!arik || !living(arik) || !arik->id(quien)) return 0;
	else if (!manuscrito || !manuscrito->id(que)) return 0;
        else if (quest && member(quest,"libro"))
        {
        	if (quest["libro",0]==7) quest+=(["libro":8]);
		if (quest["libro",0]==8)
		{
			write(W("Arik te dice: ¡Vaya!, ¡Nunca pensé que conseguirías "
			"encontrarlo!, ¡enhorabuena!. Mira el libro que me pediste "
			"está aquí mismo, ha llegado justo hoy en la diligencia. Al final "
			"resulta que todos vamos a salir ganando... ¡verás lo contento "
			"que se pone Kaleband cuando se entere de que ya tenemos el tercer "
			"manuscrito!... tengo que hacer los preparativos, toma y muchas gracias. "
			"\nArik te da el libro ceremonial.\n"));
			manuscrito->remove();
			libro=clone_object(RHOEVAR("koek/varios/libro_ceremonial"));
			libro->move(TP,M_NOCHECK);
			return 1;
		}
	}
}
