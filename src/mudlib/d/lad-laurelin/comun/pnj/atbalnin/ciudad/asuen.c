/*
	Asuen, Shopkeeper de la tienda de Atbalnin2
	Theuzifan, 13-03-99
	Zomax, 25-04-03 a�ado cosas... cosas malas... para un quest...
*/

#include "path.h"
#include <properties.h>
#include <moving.h>



inherit NPC;

public string fseda()
{
	mapping quest=TP->QueryAttribute("DraegoQuest");

	if (quest && member(quest,"tunica"))
	{
		if (quest["tunica",0]==1)
		{
			quest+=(["tunica":2]);
			return W("Asuen te dice: La seda es algo dificil de encontrar "
			"en estos d�as de caos pero casualmente tengo una pieza de bastante "
			"buena calidad. El problema es que no te resultar� muy barata "
			"porque ultimamente ando muy escaso de ese tipo de tela, de hecho "
			"creo que no podr�as pagarla ni aunque fueras mi esclavo por el resto "
			"de la eternidad. Si me consiguieras algo a cambio... d�jame pensar... "
			"�ya se!, �cons�gueme unos cuantos gusanos para criarlos y tener g�nero "
			"para los pr�ximos a�os y te doy el retal que me queda!. Ahora que "
			"lo pienso... creo recordar que alguien me coment� que vi� gusanos de "
			"los que hacen este tipo de seda por la zona humana, en un bosque cerca "
			"de una fortaleza...\n");
		}
		else if (quest["tunica",0]>1 && quest["tunica",0]<4)
		{
			return W("Asuen te dice: Tr�eme los gusanos y te dar� la seda que te "
			"promet�.\n");
		}
		else return "Asuen se encoge de hombros.\n";
	}

}

create()
{
  ::create();
  SetStandard("asuen", "elfo", 4, GENDER_MALE);
  SetShort("Asuen");
  SetLong(W("Asuen es un elfo bastante acorde con lo que se espera de "+
  	"los elfos. Es alto, con porte distinguido, rostro intemporal, "+
	"mirada altanera...\n"));

  SetIds(({"tendero", "elfo", "asuen", "Asuen"}));
  AddQuestion(({"seda"}),SF(fseda),1);
  InitChats(1,({
  	"Asuen pliega una camisa.\n",
  	"Ves c�mo Asuen ordena un estante.\n",
  	"Asuen se va a la trastienda y vuelve r�pidamente.\n",
	"Asuen te mira con desd�n.\n"}));
}

init(){
  ::init();

  add_action("fdar","dar");
}

public int fdar(string str)
{
	string que,quien;
	mapping quest=TP->QueryAttribute("DraegoQuest");
	object gusanos=present("gusanos de seda",TP);
	object seda;

	if (str) lower_case(str);
	if (!str || sscanf(str,"%s a %s", que, quien) != 2) return 0;
	else if (!TO || !living(TO) || !TO->id(quien)) return 0;
	else if (!gusanos || !gusanos->id(que)) return 0;
	else if (quest && member(quest,"tunica") && quest["tunica",0]==3)
	{
		quest+=(["tunica":4]);
		write(W("Asuen te dice: �Perfecto!, �con esto tendr� seda de sobra para "
		"varios a�os!. Toma, te lo has ganado.\n\nAsuen te da un gran retal de "
		"seda blanca.\n"));
		gusanos->remove();
		seda=clone_object("/d/simauria/comun/objeto/otro/rhoemas/koek/varios/seda");
		seda->move(TP,M_SILENT);
		return 1;
	}
}
