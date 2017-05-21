/***************************************************************************************
 ARCHIVO:		kenton.c
 AUTOR:		[k] Korsario
 FECHA:		02-04-1998
 COMENTARIOS:	Basada en la caravana de Gorthem.
 ***************************************************************************************/

#include "path.h"

inherit CARAVAN;

string *MensajesEntradaCaravana(string parada)
{
	if (parada == CAR_KHA)
		return ({
		"Un enano grita: ¡¡Hemos llegado a Kha-annu!!\n"
	        "                ¡¡ He llegado a casa !!\n",
	        "Llega la caravana Kenton procedente de @@FromParada@@.\n"});
	if (parada == CAR_FLE)
		return ({
		"Un kender grita: ¡¡Hemos llegado a Flenton !!\n"
		"                 ¿Es que no me dais la bienvenida?¿Y la fiesta?\n",
                "Llega la caravana Kenton procedente de @@FromParada@@.\n"});
	return ({
		"Alguien grita: Hemos llegado a @@Parada@@ !!\n",
                "La caravana Kenton para y baja un montón de gente.\n"});
}

string *MensajesSalidaCaravana(string parada)
{
	parada=FromParada();
	if (parada=="Kha-annu")
		return ({
		"Un enano grita: ¡Venga chavalotes que nos vamos!\n"
		"Alguien grita: ¡Por fin! Ya era hora.\n",
                "La caravana Kenton se pone en marcha.\n"});
	if (parada=="Flenton")
		return ({
		"Un kender grita: Al fin arrancamos! Que me esperan muchas aventuras! Mas prisa!\n"
		"Alguien grita: Venga que quiero llegar a mi casa.\n",
                "La caravana Kenton se pone en marcha.\n"});
	return ({
		"Alguien grita: acabamos de salir de @@FromParada@\n"
		"y nos vamos a @@Parada@@.\n",
                "La caravana Kenton huye y emigra.\n"});
}

create(){
  ::create();

  SetIds(({"caravana Kenton","Kenton","kenton","caravana"}));
  SetShort("La caravana Kenton");
  SetLong(W("Es la caravana Kenton, una caravana de traviesos kenders y "
  	"serios enanos que viaja incesantemente desde el dominio de Kenton, "
  	"reino de los kenders al dominio de Kha-annu, dominio enanil.\n"));
  SetEnterMsgs(({"se une a la caravana Kenton","se une a esta caravana","te unes a la caravana Kenton"}));
  SetLeaveMsgs(({"deja la caravana Kenton","Dejas esta caravana","Bajas de la caravana Kenton"}));
  SetCaravanaEnterMsgs(SF(MensajesEntradaCaravana));
  SetCaravanaLeaveMsgs(SF(MensajesSalidaCaravana));
  SetParadas(([0:CAR_FLE;"Flenton",1:CAR_KHA;"Kha-annu"]));

  //AddMoveMsg("La caravana avanza constantemente\n",10);
  AddMoveScene(CAR_FLE,CAR_KHA,"Atraviesas el bosque que une a Flenton con Kha-annu.\n",20);
  AddMoveScene(CAR_FLE,CAR_KHA,"Atraviesas las montañas de Kha-annu.\n",20);
  AddMoveScene(CAR_FLE,CAR_KHA,"Desde lejos entre las montañas divisas Kha-annu.\n",20);

  AddMoveScene(CAR_KHA,CAR_FLE,"Abandonas el dominio enanil y comienzas a cruzar las montañas.\n",20);
  AddMoveScene(CAR_KHA,CAR_FLE,"La caravana atraviesa un denso bosque.\n",20);
  AddMoveScene(CAR_KHA,CAR_FLE,"Atraviesas un pequeño claro en el bosque.\n",20);

  AddDeck(CAR_DEN);
  SetMsgCost("No te puedes permitir el lujo de viajar en esta caravana.\n");
}

QueryCaravanaCost()
{
  	if ((TP->QueryRace()=="kender") || (TP->QueryRace()=="enano"))
  		return 40;
  	else return 60;
}
