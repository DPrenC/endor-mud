/***************************************************************************************
 ARCHIVO:	animales.c
 AUTOR:		[z] Zomax
 FECHA:		19-11-2001
 COMENTARIOS:	Animales del bosque Cylin.
 MODIFICACIÓN:  19-03-2003 ¡Vivan las Fallas! Digo... cambio el agresivo de los animales
 		para no cargar el combat. Ahora además de no haber agresivos 2 algunos
 		(los mas tiennos) no son agresivos en absoluto.
 		09-04-2003 Cambio el switch random 9 por 8
 ***************************************************************************************/

#include "path.h"
#include <moving.h>

#define nor	0	//Normal
#define est	1	//Estatua
#define dec	0	//Descripcion Corta
#define del	1	//Descripcion Larga
#define gen	2	//Gender
#define rac	3	//Race
#define ids	4	//Ids
#define goc	5	//GoChance
#define cor	6	//Corpse
#define agr	7	//Aggressive

inherit NPC;

int estatua;
mapping map;

create () {
 ::create();
map = ([]);
 map += ([nor:dec;del;gen;rac;ids;goc;cor;agr]);
 map += ([est:dec;del;gen;rac;ids;goc;cor;agr]);

 switch(random(8))
 {
 	case 0:	/***** COMUN LOBO *****/
 		estatua=(random(2));
 		SetHands(({({"una garra",1,8}),({"una garra",1,8}),({"una dentellada",1,10})}));
 		SetWeight(25000);
 		SetAlign(-100);
 		SetSize(2);
 		SetHP(200);
 		SetMaxHP(200);
 		SetLevel(13);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="lobo";
 		map[nor,ids]=({"lobo"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=(random(2));
 		map[nor,dec]="un lobo";
 		map[nor,del]="Es un lobo, una criatura de grandes y amenazadores "
 			     "colmillos y garras que te mira con ganas de algo "
 			     "que no sabes muy bien, pero sin duda nada bueno. "
 			     "Tiene el pelo negro como un pozo sin fin y algo "
 			     "brillante. Parece que tiene hambre, y no estás "
 			     "seguro de qué es lo que comen los lobos aquí... o "
 			     "a quien...\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un lobo","la estatua de un lobo"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un lobo";
 		map[est,del]="Es la estatua de un lobo, algo no muy corriente en "
 			     "medio de un bosque, y menos aún cuando es una tan "
 			     "real que parece que vaya a saltar y abalanzarse "
 			     "sobre ti. Tiene una expresión entre agresividad y "
 			     "miedo que nunca habías visto, pero sin duda te resulta "
 			     "de lo más extraño.\n";
 		break;
 	case 1:	/***** COMUN ZORRO *****/
 		estatua=(random(2));
 		SetHands(({({"una garra",1,8}),({"una garra",1,8}),({"una dentellada",1,10})}));
 		SetWeight(15000);
 		SetAlign(-100);
 		SetSize(2);
 		SetHP(175);
 		SetMaxHP(175);
 		SetLevel(12);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="zorro";
 		map[nor,ids]=({"zorro"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=(random(2));
 		map[nor,dec]="un zorro";
 		map[nor,del]="Es un zorro, uno de los muchos que hay en este "
 			     "bosque, famosos por atraer a los incautos que se adentran "
 			     "en él y perderlos hasta que les inunda la desesperación, "
 			     "momento en el que atacan. Tiene un suave pelaje rojizo y cola "
 			     "blanca, pero también unos poderosos colmillos con los que "
 			     "podría dar a cualquiera un verdadero disgusto.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un zorro","la estatua de un zorro"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un zorro";
 		map[est,del]="Es una estatua de piedra de un zorro, algo muy extraño, "
 			     "porque no te parece éste el lugar indicado para encontrarte "
 			     "esto. Su mirada refleja mucha ansiedad, y parece tan real "
 			     "que por un instante parece que se mueve. El artista ha captado "
 			     "sin duda el movimiento y la expresión de este zorro.\n";
 		break;
 	case 2:	/***** COMUN BÚHO *****/
 		estatua=(random(2));
 		SetHands(({({"una garra",1,5}),({"una garra",1,5}),({"un pico",1,6}),({"un ala",1,5}),({"un ala",1,5})}));
 		SetWeight(5000);
 		SetAlign(-100);
 		SetSize(1);
 		SetHP(150);
 		SetMaxHP(150);
 		SetLevel(8);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="búho";
 		map[nor,ids]=({"buho","búho"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=0;
 		map[nor,dec]="un búho";
 		map[nor,del]="Es un un búho, uno de los animales más inteligentes "
 			     "de este bosque, que al ser tan tupido sale tanto de noche como "
 			     "dedía. Tiene unas alas enormes, que junto con sus garras te hacen "
 			     "temer lo peor si te atacara. Sus plumas son marrones brillantes, con "
 			     "algún reflejo blanco.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un buho","la estatua de un buho","estatua de un búho","la estatua de un búho"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un búho";
 		map[est,del]="Es una estatua de piedra de un búho, si no fuera porque parece "
 			     "algo pesada dirías que va a salir volando en este preciso momento. "
 			     "Quien hizo esta estatua llegó ha plasmar en ella todos los detalles "
 			     "de un búho de verdad, incluso las plumas... Esto empieza a ser sospechoso.\n";
 		break;
 	case 3:	/***** CIERVO *****/
 		estatua=(random(2));
 		SetHands(({({"una pata",1,7}),({"una pata",1,7}),({"un mordisco",1,9})}));
 		SetWeight(25000);
 		SetAlign(100);
 		SetSize(2);
 		SetHP(160);
 		SetMaxHP(160);
 		SetLevel(11);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="ciervo";
 		map[nor,ids]=({"ciervo"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=0;
 		map[nor,dec]="un ciervo";
 		map[nor,del]="Es un un ciervo, una animal de cuatro patas y "
 			     "pelaje marrón con algunas manchitas blancas que resulta muy "
 			     "reconfortante mirar. Parece inofensivo, pero seguro que una "
 			     "coz suya duele... y mucho.\n";
		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un ciervo","la estatua de un ciervo"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un ciervo";
 		map[est,del]="Es una estatua de piedra de un ciervo, tiene los ojos "
 			     "tan reales, llenos de tristeza, que te hacen un nudo en la "
 			     "garganta. Parece que vaya a saltar de un lado a otro... pero "
 			     "es solo una estatua.\n";
 		break;
 	case 4:	/***** OSO *****/
 		estatua=(random(2));
 		SetHands(({({"una garra",1,14}),({"una garra",1,14}),({"un mordisco",1,16})}));
 		SetWeight(100000);
 		SetAlign(100);
 		SetSize(3);
 		SetHP(300);
 		SetMaxHP(300);
 		SetLevel(18);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="oso";
 		map[nor,ids]=({"oso"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=(random(2));
 		map[nor,dec]="un oso";
 		map[nor,del]="Estás ante la imponente figura de un oso, uno "
 			     "de los más grandes que has visto en tu vida. Al observarle "
 			     "con detenimiento puedes ver que no está por la labor de "
 			     "dejarte escapar... con vida.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un oso","la estatua de un oso"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un oso";
 		map[est,del]="Una enorme estatua de un oso se alza ante ti. "
 			     "Está en una posición de ataque, sobre sus dos patas traseras, "
 			     "y te preguntas como es posible que alguien pueda haber tallado "
 			     "algo así en roca de memoria, porque no crees que el oso se "
 			     "ofreciera a colaborar.\n";
 		break;
 	case 5:	/***** PÁJARO *****/
 		estatua=(random(2));
 		SetHands(({({"un ala",1,5}),({"un ala",1,5}),({"el pico",1,6})}));
 		SetWeight(200);
 		SetAlign(100);
 		SetSize(1);
 		SetHP(100);
 		SetMaxHP(100);
 		SetLevel(6);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="pájaro";
 		map[nor,ids]=({"pajaro","pájaro"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=0;
 		map[nor,dec]="un pájaro";
 		map[nor,del]="Un delicado pájaro te mira con curiosidad. "
 			     "Parece que tiene hambre, y está algo nervioso. Tiene "
 			     "unas pequeñas manchas en las alas que le dan un toque "
 			     "especial, debe ser una raza autóctona.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un pajaro","la estatua de un pajaro","estatua de un pájaro","la estatua de un pájaro"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un pájaro";
 		map[est,del]="Es absolutamente extraño, pero te acabas de "
 			     "encontrar una delicada figura de un pájaro. Por los "
 			     "detalles que tiene en las alas parece que es una "
 			     "reproducción prácticamente exacta a los pájaros que "
 			     "viven en el bosque Cylin.\n";
 		break;
 	case 6:	/***** ARDILLA *****/
 		estatua=(random(2));
 		SetHands(({({"una pata",1,6}),({"una pata",1,6}),({"una dentellada",1,7})}));
 		SetWeight(5000);
 		SetAlign(100);
 		SetSize(1);
 		SetHP(200);
 		SetMaxHP(200);
 		SetLevel(9);
 		/***** NORMAL *****/
 		map[nor,gen]=2;
 		map[nor,rac]="ardilla";
 		map[nor,ids]=({"ardilla"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=0;
 		map[nor,dec]="una ardilla";
 		map[nor,del]="Ante ti una revoltosa ardilla corretea sin cesar. "
 			     "Tiene unos grandes ojos marrones que te miran con curiosidad "
 			     "y te incomodan. El pelaje marrón y la rapidez con que se "
 			     "mueve te hace dificil seguirle la pista.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de una ardilla","la estatua de una ardilla"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de una ardilla";
 		map[est,del]="Es una ardilla... no... espera... es una estatua... "
 			     "pero parece tan real...\n";
 		break;
 	case 7:	/********** SERPIENTE **********/
 		estatua=(random(2));
 		SetHands(({({"un colmillo",1,15}),({"un colmillo",1,15})}));
 		SetWeight(5000);
 		SetAlign(100);
 		SetSize(1);
 		SetHP(200);
 		SetMaxHP(200);
 		SetLevel(10);
 		/***** NORMAL *****/
 		map[nor,gen]=2;
 		map[nor,rac]="serpiente";
 		map[nor,ids]=({"serpiente"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=(random(2));
 		map[nor,dec]="una serpiente";
 		map[nor,del]="Una serpiente se escurre por tus pies... Es "
 			     "verde, con manchas marrones y dos colmillos que recordarás "
 			     "toda tu vida...\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de una serpiente","la estatua de una serpiente"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de una serpiente";
 		map[est,del]="Es un palo de piedra... lo miras bien y descubres... "
 			     "¡que tiene colmillos!... um... parece que es mas una serpiente "
 			     "de piedra...\n";
 		break;
 	default:/********** HALCÓN **********/
 		estatua=(random(2));
 		SetHands(({({"una garra",1,7}),({"una garra",1,7}),({"el pico",1,9})}));
 		SetWeight(7000);
 		SetAlign(100);
 		SetSize(1);
 		SetHP(200);
 		SetMaxHP(200);
 		SetLevel(10);
 		/***** NORMAL *****/
 		map[nor,gen]=1;
 		map[nor,rac]="halcón";
 		map[nor,ids]=({"halcon","halcón"});
 		map[nor,goc]=20;
 		map[nor,cor]="std/corpse";
 		map[nor,agr]=(random(2));
 		map[nor,dec]="un halcón";
 		map[nor,del]="Puedes ver un precioso halcón mirando a todas "
 			     "partes. Tiene las plumas más grandes que has visto nunca "
 			     "y un pico que te da muy mala espina.\n";
 		/***** ESTATUA *****/
 		map[est,gen]=2;
 		map[est,rac]="estatua";
 		map[est,ids]=({"estatua","estatua de un halcon","la estatua de un halcon","estatua de un halcón","la estatua de un halcón"});
 		map[est,goc]=0;
 		map[est,cor]=RHOEVAR("cylin/escombros");
 		map[est,agr]=0;
 		map[est,dec]="la estatua de un halcón";
 		map[est,del]="Puedes ver la estatua más realista de un halcón "
 			     "que has visto en la vida. Lástima que sólo sea eso... ¿o no?\n";
 		break;
 	}
}

DoDamage(int dmg)
{
	if (estatua) TO->StopAttack();
	return ::DoDamage(dmg);
}

public varargs void Die(mixed silent)
{
	if (estatua)
	{
		object restos;
		SetIds(({}));
		write(W("Golpeas la estatua hasta reducirla a escombros, no parece que haya "
		"servido de mucho, solo te sientes más cansad"+AO+".\n"));
		say(W(CATP+" ha golpeado la estatua "
		"hasta convertirla en escombros, pero no parece que haya servido de "
		"mucho.\n"),TP);
		restos=clone_object(RHOEVAR("cylin/escombros"));
		restos->move(environment(TO),M_SILENT);
		TO->remove();
	}
	else
	{
		SetIds(({}));
		::Die(silent);
	}
}

public string HealthMsg(int health, int stunned, int paralyzed, int blind)
{
  string str;
  if (estatua)
  {
	switch(health)
	{
  		case  0..10:	str = "destrozada";	 	 break;
  		case 11..20:	str = "casi destrozada"; 	 break;
  		case 21..50:	str = "muy deteriorada";	 break;
  		case 51..80:	str = "algo deteriorada";	 break;
  		case 81..90:	str = "ligeramente deteriorada"; break;
  		case 91..99:	str = "en buen estado"; 	 break;
  		default:	if (health < 0)	str = "completamente destrozada";
  				else str = "en perfecto estado";
  	}
  	if (stunned)
  	{
    		str +=  (health > 90 ? " pero " : " y ");
    		if (stunned > 10)	str += "inherte";
    		else if (stunned > 5)	str += "inherte";
    		else			str += "inherte";
  	}
  	return str;
  }
  else
  {
  	switch(health)
  	{
  		case  0..10: str = "muy malherid"+QueryGenderEndString(); 	   break;
  		case 11..20: str = "malherid"+QueryGenderEndString(); 	   break;
  		case 21..50: str = "gravemente herid"+QueryGenderEndString();  break;
  		case 51..80: str = "herid"+QueryGenderEndString(); 		   break;
  		case 81..90: str = "ligeramente herid"+QueryGenderEndString(); break;
  		case 91..99: str = "en buen estado"; 				   break;
  		default:  if (health < 0)  str = "muerto";
  		  	  else	str = "en perfecto estado";
  	}
  	if (stunned)
  	{
    		str +=  (health > 90 ? " pero " : " y ");
    		if (stunned > 10)  str += "totalmente inconsciente";
    		else if (stunned > 5)  str += "inconsciente";
    		else  str += "aturdid"+QueryGenderEndString();
  	}
  	return str;
  }
}

int SetEstatua(int es)
{
	estatua=es;
	return 1;
}

int QueryEstatua()
{
	return estatua;
}

void init(){
  ::init();
  if (!estatua)
  {
  	SetGender(map[nor,gen]);
  	SetRace(map[nor,rac]);
  	SetShort(map[nor,dec]);
  	SetName(map[nor,dec]);
  	SetLong(W(to_string(map[nor,del])));
  	SetIds(map[nor,ids]);
  	SetGoChance(map[nor,goc]);
  	SetCorpse(map[nor,cor]);
  	SetAggressive(map[nor,agr]);
  }
  else
  {
  	SetGender(map[est,gen]);
  	SetRace(map[est,rac]);
  	SetShort(map[est,dec]);
  	SetName(map[est,dec]);
  	SetLong(W(to_string(map[est,del])));
  	SetIds(map[est,ids]);
  	SetGoChance(map[est,goc]);
  	SetCorpse(map[est,cor]);
  	SetAggressive(map[est,agr]);
   }
}

move(dest,method,stuff)
{
	if(method==M_GO && dest->QueryLocate()!="Bosque de Cylin")
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
