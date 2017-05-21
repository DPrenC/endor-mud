/*=============================================================*
 |            << GOLDHAI.batalla [w] Woo@simauria >>           |
 *=============================================================*
 |               Creacion............... 27-08-98              |
 |               Ultima Modificacion.... 06-09-99              |
 |                                                             |
 | 28-10-98 [w] Aumentado PROB a 10 en vez de 4. Ahora en el   |
 |              init se comprueba que TP sea un jugador.       |
 | 07-02-99 [w] Castellanizado, con e�es y acentos.            |
 | 06-09-99 [w] He toqueteado un poco aqu� y all�.             |
 *=============================================================*/

#include "../sys/goldhai.h"
#include <colours.h>
inherit GROOM;

#define PROB    10 // Probabilidad de que te caiga una flecha o piedra.
#define F_PIEDRA (12+random(60)-(TP->QueryCon()+TP->QueryInt()+TP->QueryStr())/3)
#define F_FLECHA (5+random(50)-(TP->QueryCon()+TP->QueryInt()+TP->QueryStr())/3)

string rtipo;


create() {
 ::create();

 SetIntShort("la llanura de Orkath");

 switch(random(4))
 {
  case 0:
 SetIntLong("\
Te encuentras en la llanura de Orkath, un sitio de destrucci�n y terror. Los\n\
cadaveres yacen a tus pies y empiezan a oler bastante mal as� que ser� mejor\n\
que te vayas rapidamente. Adem�s, dado que est�s en medio de un campo de\n\
batalla tu integridad f�sica corre gran peligro.\n");
  break;

  case 1:
 SetIntLong("\
Est�s en medio del campo de batalla, en la llanura de Orkath. Quiz�s algun d�a\n\
hubo en este lugar alg�n tipo de vegetaci�n, pero en estos momentos no queda\n\
mucho m�s a parte de piedras, arena y cadaveres descompuestos.\n");
   break;

  case 2:
 SetIntLong("\
La llanura de Orkath, un lugar lleno de peligros y amenazas. Est�s en medio\n\
de un enorme campo de batalla sembrado de caos y destrucci�n, un paisaje\n\
casi des�rtico sin nada de inter�s.\n");
  break;

  case 3:
 SetIntLong("\
No ves nada a tu alrededor, excepto una inmensa llanura des�rtica y poblada\n\
de cad�veres y restos de las crueles batallas que aqu� se desarrollan.\n");
  break;

  default:
 SetIntLong("\
Te encuentras en la llanura de Orkath, un sitio de destrucci�n y terror. Los\n\
cadaveres yacen a tus pies y empiezan a oler bastante mal as� que ser� mejor\n\
que te vayas rapidamente. Adem�s, dado que est�s en medio de un campo de\n\
batalla tu integridad f�sica corre gran peligro.\n");
 }

 SetIntSmell("\
Los cad�veres en descomposici�n producen un olor bastante nauseabundo.\n");

 AddDetail("restos","El suelo est� lleno de restos de la batalla y de cad�veres.\n");
 AddDetail(({"cad�veres","cadaveres"}),"Hay por todos lados, debi� ser una cruel batalla.\n");
 AddDetail(({"piedra","piedras","roca","rocas"}),
"Son peque�as piedras puntiagudas que cubren el suelo.\n");
 AddDetail(({"tierra","arena"}),
"Una fina arena forma peque�os monticulos producidos por el viento.\n");

 SetIndoors(0); // A descubierto
}

void init(){
string str;
::init();

 if (!TP->QueryIsPlayer()) return;
 if (rtipo)
  if(sscanf(rtipo,"campamento%s",str)==1)
   return; // [w] En los campamentos no caen piedras ni flechas.

 if (random(PROB)==PROB-3)
  switch(random(2))
  {
   case 0:
      write(TC_YELLOW"Una enorme piedra cae del cielo y te da de lleno.\n"TC_NORMAL);
      say("Una enorme piedra cae del cielo e impacta en el cuerpo de "+
          CAP(TNREAL)+".\n");
      TP->Defend(F_PIEDRA);
   break;
   case 1:
      write("Oyes un extra�o silbido en el aire.\n");
      say("Oyes un extra�o silbido en el aire.\n");
      write(TC_YELLOW"Una flecha atraviesa el cielo y se te clava en el cuerpo.\n"TC_NORMAL);
      say("Una flecha atraviesa el cielo y se clava en el cuerpo de "+
          CAP(TNREAL)+".\n");
      TP->Defend(F_FLECHA);
      write("Te extraes la flecha con cuidado y te sientes algo m�s aliviado.\n");
      say(CAP(TNREAL)+" se extrae la flecha con sumo cuidado.\n");
   break;
   default:
      write(TC_YELLOW"Una enorme piedra cae del cielo y te da de lleno.\n"TC_NORMAL);
      say("Una enorme piedra cae del cielo e impacta en el cuerpo de "+
          CAP(TNREAL)+".\n");
      TP->Defend(F_PIEDRA);
  }
 return;
}


int Orkath(string tipo)
{
 if(!tipo) return 1;
 rtipo = tipo;

 if(tipo=="elfos-oscuros")
  AddItem(PNJ("zona_batalla/elfo-oscuro"),REFRESH_DESTRUCT,random(3)+1);

 // [w] Los humanos ayudan a los medio elfos contra los elfos oscuros.
 if(tipo=="medio-elfos") {
  AddItem(PNJ("zona_batalla/medio-elfo"),REFRESH_DESTRUCT,random(3)+1);
  AddItem(PNJ("zona_batalla/humano"),REFRESH_DESTRUCT,random(1)+1);
 }

 return 1;
}
