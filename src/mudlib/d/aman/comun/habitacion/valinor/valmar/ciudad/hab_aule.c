/*
Fichero: aule.c
Autor: Aulë
Fecha: 15/10/2012
Descripción: mi workroom
*/
#include "./path.h"
inherit STD_VALINOR("hab_valinor");
create()
{
    ::create();
    	SetLocate("Valmar");
    	SetIntBright(35);
  SetIndoors(1);
   	
    SetIntShort("salones de Aulë");
    SetIntLong("Estos son los Salones que Aulë,  vala maestro en muchas ciencias y artes, "
    "utiliza cuando habita en la bella ciudad de Valmar.\n"
    "Son una serie de grandes salas abovedadas, soportadas por grandes columnas "
    "exquisitamente talladas y grabadas y cuyos suelos y muros están recubiertos por "
    "los más maravillosos materiales y cincelados.\n"
    "En el centro de la sala principal, se alza una gran fragua y un magnífico yunque "
    "dorado sobre el cual las obras concebidas por Aulë  llegan a ser reales por medio "
    "de sus manos de destreza  inigualable en toda Arda.\n"
    "Colgando de los muros, encerradas en cristalinas vitrinas y colocadas sobre "
    "largas mesas descansan una innumerable cantidad de los más bellos y diversos objetos:"
    "armas, armaduras, joyas, artilugios, pergaminos, libros de ciencia y todo aquello "
    "que una mente que se deleite con los trabajos manuales y la sabiduría pudiera imaginar o desear.\n");
     AddExit("trans", "./trans_endor");
    AddExit("sur", "./gavenida2");

    }public void init()
{
	::init();
		write("Penetras en los salones de Aulë.\n");
}