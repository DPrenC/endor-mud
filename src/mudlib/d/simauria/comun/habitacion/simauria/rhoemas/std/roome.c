/***************************************************************************************
 ARCHIVO:	roome.c
 AUTOR:		[z] Zomax
 FECHA:		07-11-2001
 COMENTARIOS:	Habitacion Standard Exterior.
 MODIFICACION:  24-04-2003 Repaso de c�digo.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

mapping map;

public int QueryEntrarPatrullero()	{return 1;}
public int QueryEntrarGato() 		{return 1;}

create () {
  ::create();

  SetIndoors(0);
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("coger","fcoger");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
  map = ([]);
  map += ([neu:des;sme;noi]);
  map += ([inv:des;sme;noi]);
  map += ([pri:des;sme;noi]);
  map += ([ver:des;sme;noi]);
  map += ([oto:des;sme;noi]);

  map[neu,sme]="No hueles nada en especial.\n";
  map[inv,sme]="Tienes la nariz tan fr�a que no hueles nada.\n";
  map[pri,sme]="Las plantas de toda la zona aromatizan el ambiente.\n";
  map[ver,sme]="Aspiras el aire... demasiado caliente para tu gusto.\n";
  map[oto,sme]="El olor a tierra mojada invade el ambiente.\n";

  map[neu,noi]="Te concentras... No oyes nada en especial.\n";
  map[inv,noi]="Oyes los silbidos del aire g�lido al chocar con tus orejas.\n";
  map[pri,noi]="Apenas oyes el sonido del viento acariciando cuanto toca.\n";
  map[ver,noi]="El aire est� tan parado que no oyes nada en absoluto.\n";
  map[oto,noi]="Oyes el sonido del viento que empieza a soplar con algo de fuerza.\n";

  switch(random(10))
  {
 	case 0: map[inv,des]="Ahora mismo est� todo nevado.\n";
 		map[pri,des]="Hay un agradable ambiente de primavera.\n";
 		map[ver,des]="Hace bastante calor.\n";
 		map[oto,des]="Las lluvias han dejado el suelo muy resbaladizo.\n";
 		break;

 	case 1: map[inv,des]="Hace bastante fr�o y hay una gran capa de nieve en el suelo.\n";
 		map[pri,des]="La nieve ya se derriti� hace tiempo, dejando al descubierto el suelo.\n";
 		map[ver,des]="Con este calor la calle se hace agobiantemente larga.\n";
 		map[oto,des]="Las lluvias han dejado la calle muy resbaladiza.\n";
 		break;

 	case 2: map[inv,des]="Toda la calle est� cubierta por la nieve.\n";
 		map[pri,des]="Ahora que ya hace mejor tiempo, la nieve ha dejado paso a los grises adoquines.\n";
 		map[ver,des]="Con este tiempo el suelo est� m�s caliente que nunca.\n";
 		map[oto,des]="La lluvia entorpece el caminar, haciendo muy resbaladizo el suelo.\n";
 		break;

 	case 3: map[inv,des]="La nieve lo ha cubierto todo de blanco.\n";
 		map[pri,des]="Algunas peque�as hierbas renacen en el suelo.\n";
 		map[ver,des]="El suelo est� muy caliente debido al sol.\n";
 		map[oto,des]="Las lluvias de estos d�as han dejado alg�n charco.\n";
 		break;

 	case 4: map[inv,des]="Est� todo nevado y te cuesta andar.\n";
 		map[pri,des]="La nieve ya se ha derretido y notas una suave brisa en la cara.\n";
 		map[ver,des]="El aire se ha parado de golpe y tienes mucho calor.\n";
 		map[oto,des]="Las lluvias han dejado el suelo brillante y resbaladizo.\n";
 		break;

 	case 5: map[inv,des]="Agolpada a los lados hay una gran cantidad de nieve.\n";
 		map[pri,des]="Se respira un ambiente muy bueno.\n";
 		map[ver,des]="Hace bastante calor, algo l�gico en esta �poca del a�o.\n";
 		map[oto,des]="Ves alg�n charco que otro en el suelo.\n";
 		break;

 	case 6: map[inv,des]="En este momento la nieve ha invadido casi todo.\n";
 		map[pri,des]="Al derretirse la nieve se descrubre el suelo.\n";
 		map[ver,des]="Hace mucho calor.\n";
 		map[oto,des]="Andas con cuidado para no caerte de un resbal�n.\n";
 		break;

 	case 7: map[inv,des]="Ahora mismo la nieve ti�e de blanco toda la calle.\n";
 		map[pri,des]="La brisa acaricia todo lo que toca.\n";
 		map[ver,des]="Hace bastante calor y no corre un pelo de aire.\n";
 		map[oto,des]="Intentas con cuidado no pisar los charcos de la calle.\n";
 		break;

 	case 8: map[inv,des]="El fr�o invierno ha llenado la calle de nieve.\n";
 		map[pri,des]="Con la llegada de la primavera la nieve ha dejado paso a un agradable clima.\n";
 		map[ver,des]="Hace mucho calor. Demasiado.\n";
 		map[oto,des]="Ves alg�n que otro charco.\n";
 		break;

 	case 9: map[inv,des]="Hace bastante fr�o y la nieve lo cubre todo.\n";
 		map[pri,des]="Notas una agradable brisa.\n";
 		map[ver,des]="El calor es abrasador.\n";
 		map[oto,des]="Ves algunos charcos de la lluvia que ha ca�do.\n";
 		break;

 	default:map[inv,des]="Hace bastante fr�o y todo est� cubierto por la nieve.\n";
 		map[pri,des]="Se est� muy bien aqu�.\n";
 		map[ver,des]="Notas un agobiante calor.\n";
 		map[oto,des]="El suelo est� brillante y resbaladizo por la lluvia.\n";
 		break;
  }
}

init(){
  ::init();

  switch (CHRONOS->QueryEstacion())
  {
 	case 1:	SetIntLong(W(to_string(map[neu,des])+to_string(map[inv,des])));
 		SetIntSmell(W(to_string(map[inv,sme])));
 		SetIntNoise(W(to_string(map[inv,noi])));
 		AddDetail(({"nieve"}),W(
		"El duro invierno del valle de Rhoemas hace que la nieve se amontone "+
		"sin cesar por donde cae, formando todo un manto nevado que cubre "+
		"pr�cticamente todo a su paso.\n"));
		AddDetail(({"suelo","adoquin","adoqu�n","adoquines"}),W(
		"La nieve tapa casi por completo los adoquines del suelo.\n"));
 		break;

 	case 2:	SetIntLong(W(to_string(map[neu,des])+to_string(map[pri,des])));
 		SetIntSmell(W(to_string(map[pri,sme])));
 		SetIntNoise(W(to_string(map[pri,noi])));
 		AddDetail(({"suelo","adoquin","adoqu�n","adoquines"}),W(
		"El suelo est� hecho de adoquines grises que evitan que se embarre.\n"));
		break;

 	case 3: SetIntLong(W(to_string(map[neu,des])+to_string(map[ver,des])));
 		SetIntSmell(W(to_string(map[ver,sme])));
 		SetIntNoise(W(to_string(map[ver,noi])));
 		AddDetail(({"suelo","adoquin","adoqu�n","adoquines"}),W(
		"El suelo est� hecho de adoquines grises. Ahora est�n muy calientes.\n"));
		break;

 	case 4:	SetIntLong(W(to_string(map[neu,des])+to_string(map[oto,des])));
 		SetIntSmell(W(to_string(map[oto,sme])));
 		SetIntNoise(W(to_string(map[oto,noi])));
 		AddDetail(({"suelo","adoquin","adoqu�n","adoquines"}),W(
		"El suelo est� hecho de adoquines grises que evitan que se embarre.\n"));
		break;

 	default:SetIntLong(W(to_string(map[neu,des])));
 		SetIntSmell(W(to_string(map[neu,sme])));
 		SetIntNoise(W(to_string(map[neu,noi])));
 		break;
  }
}

public int fcoger(string str)
{
	object cosa;
	if(str=="nieve" && CHRONOS->QueryEstacion()==1)
	{
		cosa=clone_object(RHOEVAR("cylin/nieve"));
		cosa->move(TP,M_SILENT);
		write("Coges algo de nieve del suelo.\n");
		say(W(CATP+" coge un poco de nieve.\n"),TP);
		return 1;
	}
    return 0;
}
