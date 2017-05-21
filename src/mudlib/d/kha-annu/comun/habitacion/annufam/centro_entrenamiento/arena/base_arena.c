/* vi: set tabstop=4 */
/** @file base_arena.c
	@brief Archivo base para arena

Este es el código LPC del tipo de room base definido por el usuario arena
*/

#include "./path.h"

inherit BASE_ANNUFAM;

string escuchar();
string oler();
int cmd_coger();

create() {
	::create();
	SetIndoors(0);
	AddDetail(({"arma", "armas"}),"Son armas de todos los tipos y tamaños que los enanos emplean en su entrenamiento. Algunas se encuentran en mal estado pero la mayoría están apiladas perfectamente para poder ser utilizadas por los soldados en cualquier momento.\n");
	AddDetail(({"grada", "gradas"}), "Bordeando la Arena hay unas pequeñas gradas que los enanos emplean para descansar y contemplar los entrenamientos de sus compañeros. Están construidas en piedra oscura y apenas levantan tres metros del suelo.\n");
	AddDetail(({"muralla", "murallas"}),"Se trata de las murallas de la ciudad. Sobre ellas puedes ver a los arqueros, guardianes y  patrulleros que se ocupan de la defensa del recinto.\n");
	AddDetail(({"soldado", "soldados"}),"No muy alejados de ti observas grupos de soldados practicando todo tipo de habilidades guerreras.\n");
	AddDetail(({"suelo", "arena"}),"Ves armas y salpicaduras de sangre sobre una superficie de arena oscura.\n");
	AddDetail(({"vigia", "vigía", "vigias", "vigías", "arquero", "arqueros", "patrullero", "patrulleros"}),"Es uno de los tres cuerpos de guardia que custodian la ciudad de Anufam desde las murallas.\n");
	SetIntSmell(oler());
	SetIntNoise(escuchar());
	AddRoomCmd("coger","cmd_coger");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
}

int cmd_coger(string str)
{
	if (str == "todo")
	{
		write("Las armas apiladas mejor no las cojas.\n");
		return 0;
	}
	if (!str || member(({"arma","armas"}),str) <0) return 0;
	if (sizeof(filter(all_inventory(),(:$1->id("arma"):))))
	{
		return 0;
	}

	write("Mejor que no cojas esas armas, parece que las tienen muy controladas.\n");
	return 1;
}

string oler()
{
	string str;
	switch(random(3))
	{
		case 0:
			return "El olor a sudor y sangre se mezcla en un aroma agrio que te hiere al respirar.\n";
		case 1:
			return "Aspiras el aire de la Arena de Annufam y un olor a guerra y destrucción se apodera de ti.\n";
		case 2:
			return "Al oler el aire de la Arena te vienen a la memoria las historias de batallas que tantas veces has escuchado contar a viejos guerreros en las tabernas de Simauria.\n";
	}
	return "El olor a sudor y sangre se mezcla en un aroma agrio que te hiere al respirar.\n";
}

string escuchar()
{
	switch(random(3))
	{
		case 0:
			return "Escuchas los gritos de guerra de los reclutas de Annufam.\n";
		case 1:
			return "Por todas direcciones te llegan los gritos de guerra y el entrechocar de las armas.\n";
		case 2:
			return "Escuchas el grito desgarrador de algún enano herido.\n";
	}
	return "Escuchas los gritos de guerra de los reclutas de Annufam.\n";
}

/*
public void AddVentanas()
{
	AddDetail(({"ventana","ventanas"}),
				"Son las ventanas que dan a las habitaciones de la planta "
				"baja del Centro de Adiestramiento.\n");
	return ;
}
*/

public void AddParedLejos()
{
	AddDetail(({"ventana", "ventanas"}),
		   "Ves la pared del edificio y en ella algunas ventanas abiertas a "
		   "la Arena, aunque a esta distancia no alcanzas a ver lo que sucede "
		   "al otro lado.\n");
	return ;
}

public void AddLoma()
{
	AddDetail("loma", "Es un pequeño promontorio situado más o menos en el centro de la Arena y sobre el que ves entrenarse a los enanos.\n");
	return ;
}
