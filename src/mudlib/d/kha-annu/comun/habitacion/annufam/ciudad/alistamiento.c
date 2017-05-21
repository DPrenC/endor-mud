/****************************************************************************
Fichero: /d/kha-annu/comun/habitacion/annufam/ciudad/alistamiento.c
Autor: [T] Tagoras
Fecha: 28/03/2009
Descripci�n: Oficina de alistameinto
****************************************************************************/
#include "path.h"
#include <gremios.h>
#include <properties.h>
#include <materials.h>
#include <moving.h>
#include <sounds.h>

inherit BASE_CIUDAD_ANNUFAM;

public int cmd_alistarse(string str);

public void create()
{
    ::create();
    SetLocate("Annufam");
	SetIndoors(1);
	SetIntShort("la oficina de alistamiento");
	SetIntLong("Esta es la oficina de alistamiento del Centro de Adiestramiento de Guerreros de Annufam. Aqu� podr�s, si as� lo decides, alistarte al ej�rcito enano, siempre y cuando hayas tenido la fortuna de nacer enano, o en caso contrario, alistarte a la legi�n. Ves una mesa, unas sillas y un cartel en la pared.\n");
	SetIntBright(35);
	AddDetail("mesa", "Es una mesa de madera normalita, sobre la que hay algunas solicitudes de alistamiento al ej�rcito y a la legi�n. Un par de plumas y un tintero completan el conjunto.\n");
	AddDetail(({"silla", "sillas"}), "Son unas sillas de madera donde los j�venes conversan con Dhorin sobre los m�ltiples beneficios de alistarse.\n");
	AddDetail("cartel", "Es una pintura de un enano de barbas blancas con un dedo apuntando hacia fuera, como si se dirigiera hacia ti. Debajo hay una leyenda.\n");
	AddDetail(({"solicitud", "solicitudes"}), "D�jalas ah�, no vaya a ser que Dhorin se mosquee.\n");
	AddDetail(({"pluma", "plumas"}), "Son una plumas de ave, que se han afilado y una vez manchadas de titna sirven para escribir.\n");
	AddDetail("tintero", "Es un frasquito de cristal relleno de tinta negra.\n");
	AddReadMsg(({"cartel", "leyenda"}), "�nete al glorioso ej�rcito enano.\n");
	SetIntNoise("De tanto en cuando oyes a alguien rellenando una solicitud de alistamiento.\n");
	SetIntSmell("Huele a papel mohoso.\n");

    AddExit("norte",HAB_THUALIN_ANNUFAM("thualin_06"));

	AddItem(PNJ_CIUDAD_ANNUFAM("dhorin"), REFRESH_DESTRUCT, 1);

	AddRoomCmd("alistarse", "cmd_alistarse");
}

public int cmd_alistarse(string str)
{
	object placas;

	// No mujeres
	if (TP->QueryGender()==GENERO_FEMENINO)
		return notify_fail("Dhorin te dice: 'Lo siento hermosa, pero s�lo admitimos hombres. Si quieres te puedo buscar algo como cocinera o lavandera.'\n", NOTIFY_NOT_VALID);
	// S�lo guerrero
	if ((TP->QueryGuild()!=GC_GUERREROS) && (CAGE_TESTER != TP->QueryRealName()))
		return notify_fail("Dhorin te dice: 'Pues va a ser que no chaval. Aqu� s�lo queremos guerreros.'\n", NOTIFY_NOT_VALID);
	// S�lo guerrero  de nivel +5
	if (TP->QueryGuildLevel() < CAGE_MIN_LEVEL)
		return notify_fail("Dhorin te dice: 'Me gusta tu coraje peque�o, pero tendr�s que crecer un poco si quieres unirte a nosotros. Vuelve cuando seas mayor.'\n", NOTIFY_NOT_VALID);
	// Que no haya estado ya antes.
	if (TP->QueryAttribute(CAGE_LICENSED))
		return notify_fail("Dhorin te dice: 'Gracias camarada; pero t� ya has servido con nosotros.\n", NOTIFY_NOT_VALID);

	placas = clone_object(CAGE_PLACAS);
	placas->SetOwnerName(TP->QueryRealName());
	if (ME_OK != placas->move(TP, M_SILENT))
	{
		placas->remove();
		return ("Dhorin te dice: 'Tendr�as que hacer espacio para que te d� las placas indetificadoras.'\n", NOTIFY_NOT_VALID);
	}
	write ("Dhorin te dice: 'Lleva siempre contigo estas placas identificadores; te ser�n de gran utilidad. Ahora ya puedes ir al Centro de Adiestramiento y entrenarte con los maestros guerreros.\n");
	placas->Join();

	return 1;
}
