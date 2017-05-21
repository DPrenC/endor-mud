//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   khandor.c                         *
//* Archivo de: Gorthem, El forjador    *

#include "./path.h"
#define SIM "/d/simauria/comun/habitacion/marhalt/nandor/calle0"
#define KHA PUERTANOR + "hall2"

inherit CARAVAN;

string *MensajesEntradaCaravana(string parada)
	{
	if (parada == KHA)
		return ({
		"Un enano grita: !!Hemos llegado a Kha-annu!!\n"
	        "                !! He llegado a casa !!\n",
	        "Llega la caravana Khandor procedente de @@FromParada@@.\n"});
	if (parada == SIM)
		return ({
		"Un humano grita: !!Hemos llegado a Nandor !!\n"
		"                 !! Por fin en Casa !!\n",
                "Llega la caravana Khandor procedente de @@FromParada@@.\n"});
	return ({
		"Alguien grita: Hemos llegado a @@Parada@@ !!\n",
                "La caravana Khandor para y baja un monton de gente.\n"});
	}

string *MensajesSalidaCaravana(string parada)
	{

	parada=FromParada();
	if (parada=="Kha-annu")
		return ({
		"Un enano grita: Venga chavalotes que nos vamos.\n"
		"Alguien grita: !Por fin! Ya era hora.\n",
                "La caravana Khandor se pone en marcha.\n"});
	if (parada=="Nandor")
		return ({
		"Un humano grita: Vamos que nos vamos.\n"
		"Alguien grita: Venga que quiero llegar a mi casa.\n",
                "La caravana Khandor se pone en marcha.\n"});
	return ({
		"Alguien grita: acabamos de salir de @@FromParada@\n"
		"y nos vamos a @@Parada@@.\n",
                "La caravana Khandor huye y emigra.\n"});
	}

create() {
 ::create();
 SetIds(({"caravana khandor","caravana humana y enana","khandor","caravana"}));

 SetShort("La caravana Khandor");
 SetLong(" Es la caravana Khandor, una caravana de emigrantes humanos y enanos que viaja\n"
 "incesantemente desde el dominio de Kha-annu, reino de los enanos en este mundo, al dominio\n"
 "de Simauria, capital del mundo, y dominio humano.\n"
 "La caravana parte de la puerta norte de la ciudad enana de Kha-annu hasta el puerto de Nandor\n"
 "donde puedes encontrar tranportes a otras partes del mundo.\n");
AddMoveMsg("La caravana avanza constantemente.\n");
 SetEnterMsgs(
 ({"Se une a la caravana Khandor", //se ve en la parada
 "Se une a esta caravana", //se ve dentro de la caravana
 "Te unes a la caravana Khandor"})); //ve el jodio player
 SetLeaveMsgs(({"deja la caravana Khandor",
 "deja esta caravana",
 "Bajas de la caravana Khandor"}));
 SetCaravanaEnterMsgs(SF(MensajesEntradaCaravana));
 SetCaravanaLeaveMsgs(SF(MensajesSalidaCaravana));

SetParadas(([0:KHA;"Kha-annu",1:SIM;"Nandor"]));

 AddMoveScene(KHA, SIM,
              "Atraviesas las montanyas que rodean Kha-annu\n",20);
 AddMoveScene(KHA, SIM,
              "Entras en el dominio humano de Simauria\n",20);
AddMoveScene(KHA, SIM,
              "Cruzas un caudaloso río y a lo lejos ves Nandor\n",20);

 AddMoveScene(SIM, KHA,
              "Cruzas un caudaloso río\n",20);
 AddMoveScene(SIM, KHA,
              "Abandonas el dominio humano y entras en el enano\n",20);
 AddMoveScene(SIM, KHA,
              "Atraviesas las montanyas de Kha-annu\n",20);



 AddDeck(KHANDOR("dentro"));

 SetMsgCost("No te puedes permitir el lujo de viajar en esta caravana.\n");

    }

QueryCaravanaCost()
{
  	string raza = TP->QueryRace();
  	if (raza == "enano" || raza == "humano") return 40;
  	return 60;
}
