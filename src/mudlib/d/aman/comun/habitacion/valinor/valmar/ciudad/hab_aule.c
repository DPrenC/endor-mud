/*
Fichero: aule.c
Autor: Aul�
Fecha: 15/10/2012
Descripci�n: mi workroom
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    	SetIntBright(35);
  SetIndoors(1);
   	
    SetIntShort("salones de Aul�");
    SetIntLong("Estos son los Salones que Aul�,  vala maestro en muchas ciencias y artes, "
    "utiliza cuando habita en la bella ciudad de Valmar.\n"
    "Son una serie de grandes salas abovedadas, soportadas por grandes columnas "
    "exquisitamente talladas y grabadas y cuyos suelos y muros est�n recubiertos por "
    "los m�s maravillosos materiales y cincelados.\n"
    "En el centro de la sala principal, se alza una gran fragua y un magn�fico yunque "
    "dorado sobre el cual las obras concebidas por Aul�  llegan a ser reales por medio "
    "de sus manos de destreza  inigualable en toda Arda.\n"
    "Colgando de los muros, encerradas en cristalinas vitrinas y colocadas sobre "
    "largas mesas descansan una innumerable cantidad de los m�s bellos y diversos objetos:"
    "armas, armaduras, joyas, artilugios, pergaminos, libros de ciencia y todo aquello "
    "que una mente que se deleite con los trabajos manuales y la sabidur�a pudiera imaginar o desear.\n");
     AddExit("trans", "./trans_endor");
    AddExit("sur", "./gavenida2");

    }public void init()
{
	::init();
		write("Penetras en los salones de Aul�.\n");
}