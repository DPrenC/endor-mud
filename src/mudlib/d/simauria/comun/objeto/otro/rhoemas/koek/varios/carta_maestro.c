/***************************************************************************************
 ARCHIVO:	carta_maestro.c
 AUTOR:		[z] Zomax
 FECHA:		22-04-2003
 COMENTARIOS:	La carta del maestro de los presos.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("una carta");
  SetLong("Es una carta algo mal escrita en papel viejo y algo arrugado.\n");
  SetReadMsg("\n"
  	"   *------------------------------------------------------*\n"
	"   |                                                      |\n"
	"   |  Queridos aprendices:                                |\n"
	"   |                                                      |\n"
	"   |      Estoy muy bien aunque  os echo de menos.  Aquí  |\n"
	"   |  en el  poblado estoy  aprendiendo muchas  técnicas  |\n"
	"   |  nuevas,  estos seres tan  escurridizos tienen  más  |\n"
	"   |  de mil trucos para robarte la cartera... ¡qué digo  |\n"
	"   |  mil!,  ¡miles!,  ¡cientos de  miles!,   parezco un  |\n"
	"   |  novato  a  su  lado.  Tengo  ganas  de  volver   y  |\n"
	"   |  enseñaros  las  técnicas.  Espero   que  en   Koek  |\n"
	"   |  esteis haciendo  las  cosas  bien, cuando   vuelva  |\n"
	"   |  preguntaré  y como  me entere que el carcelero  os  |\n"
	"   |  ha pillado las horas de estudio de las técnicas no  |\n"
	"   |  os las quita ni el adalid del templo.               |\n"
	"   |                                                      |\n"
	"   |      PD:  No  creo  que  os  escriba   mucho, estos  |\n"
	"   |  kenders me están dejando  realmente tieso de tanto  |\n"
	"   |  robarme, cuando vuelva, que espero que sea pronto,  |\n"
	"   |  ya os  contaré todo con detalles.                   |\n"
	"   |                                                      |\n"
	"   *------------------------------------------------------*\n\n");
  SetIds(({"carta"}));
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(10);
  SetValue(0);

  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOBUY, 1);
  Set(P_CANT_STEAL,1);
}
