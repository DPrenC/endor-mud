
#include <colours.h>

int _color_use() {
	write("Sintaxis: " TC_BOLD "color" TC_NORMAL " <directiva> [argumentos]\n"
		"Las directivas de configuración son:\n"
		"  color " TC_BOLD "canal" TC_NORMAL " <canal> <color> [<color de›texto>]\n"
		"	Cambia el color de un canal determinado. Se permite usar color y tipo\n"
		"	de letra tanto en el color de fondo como en el de los canales,\n"
		"	combinándolos con el carácter +.\n"
		"	" TC_BOLD "ejemplo" TC_NORMAL ": color canal general verde amarillo+resaltado\n"
		"	" TC_BOLD "NOTA" TC_NORMAL ": se puede usar la clave " TC_BOLD "todos" TC_NORMAL " para cambiar el color de todos\n"
		"	los canales.\n"
//Nyh empieza
		"  color " TC_BOLD "combate" TC_NORMAL " <tipo> <color>\n"
		"	Cambia el color de los mensajes de combate. Los tipos son:\n"
		"	  ataco: Cambia el color de los ataques realizados por ti.\n"
		"	  defiendo: Cambia el color de los ataques realizados contra ti.\n"
		"	  otros: Cambia el color del resto de mensajes.\n"
//Nyh acaba
		"  color " TC_BOLD "tel" TC_NORMAL " <color> [<color de texto>]\n"
		"	Cambia el color de los mensajes hablados entre los jugadores\n"
		"	mediante el comando \"tel\" y \"decir\". Se permite usar color y tipo\n"
		"	de letra tanto en el color de fondo como en el de los canales,\n"
		"	combinándolos con el carácter +.\n"
		"  color " TC_BOLD "salidas" TC_NORMAL " <color>\n"
		"	cambia el color de las salidas al color <color>.\n"
		"  color " TC_BOLD "lista" TC_NORMAL "\n"
		"	lista los colores y tipos de letra disponibles.\n"
		"  color " TC_BOLD "estado" TC_NORMAL "\n"
		"	Muestra los colores elegidos tanto para canales como para salidas.\n");
	return 1;
}

int _check_color(string *mcolor) {
	if (!member(ANSI_REP, mcolor[0])) {
		return notify_fail("El color " + mcolor[0] + " no existe.\n");
	}
	if (!member(ANSI_TYPE, mcolor[1])) {
		return notify_fail("El tipo de letra " + mcolor[1] + " no existe.\n");
	}
	if (mcolor[0] == mcolor[1] && mcolor[0] != STR_ANSI_NONE) {
		return notify_fail("El tipo de letra y color deben ser distintos.\n");
	}
	return 1;
}

string *_explode_color(string color) {
	string *mcolor;
	if ((color||"") == "") {
		color = "ninguno";
	}
	mcolor = explode(lower_case(color), "+");
	if (sizeof(mcolor) == 1) {
		mcolor += ({"ninguno"});
	}
	return mcolor;
}

int _tel_color(string color, string txtcolor) {
	string *tcolor, *ttcolor;
	string out;

	tcolor = _explode_color(color);
	if (!_check_color(tcolor)) return 0;
	ttcolor = _explode_color(txtcolor);
	if (!_check_color(ttcolor)) return 0;

    TP->SetColour(TC_KEY_TEL_WHO, ANSI_REP[tcolor[0]]  + ANSI_REP[tcolor[1]]  );
    TP->SetColour(TC_KEY_TEL_MSG, ANSI_REP[ttcolor[0]] + ANSI_REP[ttcolor[1]] );

	out = "Cambiando el color de los mensajes a ";
	out += implode(explode(color, "+"), " ");
	if (txtcolor != ANSI_NONE) {
		out += ", con el color del texto puesto a " + implode(explode(txtcolor, "+"), " ");
	}
	out += ".\n";
	write(out);
	return 1;
}

int _channel_color(string channel, string color, string txtcolor) {
	string *mcolor, *mtcolor;
	string out;

	if ((channel||"") == "" || (color||"") == "") {
		return _color_use();
	}
	if (member(TP->QueryChannels(), channel) == -1 && channel != "todos") {
		return notify_fail("No tienes activado el canal " + channel + ".\n");
	}
	mcolor = _explode_color(color);
	if (!_check_color(mcolor)) return 0;
	mtcolor = _explode_color(txtcolor);
	if (!_check_color(mtcolor)) return 0;

	if (channel == "todos") {
		int i;
		string *ch;

		i = sizeof(ch = TP->QueryChannels());
		while (i--) {
            TP->SetColour(capitalize(ch[i]) + "Who", ANSI_REP[mcolor[0]]  + ANSI_REP[mcolor[1]]  );
            TP->SetColour(capitalize(ch[i]) + "Msg", ANSI_REP[mtcolor[0]] + ANSI_REP[mtcolor[1]] );
		}
	}
	else {
        TP->SetColour(capitalize(channel) + "Who", ANSI_REP[mcolor[0]]  + ANSI_REP[mcolor[1]]  );
        TP->SetColour(capitalize(channel) + "Msg", ANSI_REP[mtcolor[0]] + ANSI_REP[mtcolor[1]] );
	}
	if (channel == "todos") {
		out = "Cambiando el color de los canales a ";
	}
	else {
		out = "Cambiado el color del canal '"+channel+"' a ";
	}
	out += implode(explode(color, "+"), " ");
	if (txtcolor != "ninguno") {
		out += ", con el color del texto puesto a " + implode(explode(txtcolor, "+"), " ");
	}
	out += ".\n";
	write(out);
	return 1;
}


int _color_list() {
	write( "Lista de colores disponibles:\n"
		"   negro       " TC_BLACK  "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_BLACK  TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   rojo        " TC_RED    "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_RED    TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   verde       " TC_GREEN  "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_GREEN  TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   amarillo    " TC_YELLOW "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_YELLOW TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   azul        " TC_BLUE   "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_BLUE   TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   púrpura     " TC_PURPLE "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_PURPLE TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   cian        " TC_CYAN   "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_CYAN   TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   blanco      " TC_WHITE  "== AaEeIiOoUu --" TC_NORMAL "  resaltado " TC_WHITE  TC_BOLD "== AaEeIiOoUu --" TC_NORMAL "\n"
		"\n"
		"Lista de tipos disponibles:\n"
		"   resaltado   " TC_BOLD   "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   subrayado   " TC_UNDERL "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   parpadeante " TC_BLINK  "== AaEeIiOoUu --" TC_NORMAL "\n"
		"   cursiva     " TC_ITALIC "== AaEeIiOoUu --" TC_NORMAL "\n"
		"\n"
		"NOTA: para ciertos tipos de letra es necesario disponer de un "
		"cliente telnet que los soporte, habitualmente bajo entorno gráfico.\n");
	return 1;
}

int _color_exits(string color) {
	string *mcolor;

	if ((color||"") == "") {
		return _color_use();
	}
	mcolor = _explode_color(color);
	if (!_check_color(mcolor)) return 0;

    TP->SetColour(TC_KEY_EXIT, ANSI_REP[mcolor[0]] + ANSI_REP[mcolor[1]]  );

	write("Cambiando el color de las salidas a " + implode(explode(color, "+"), " ") + ".\n");
	return 1;
}

int _color_status() {
	int s, i;
	string *ch, *mcolor;

	ch = TP->QueryChannels();
	s = sizeof(ch);
	if (s) {
		write("Estos son los colores de tus canales:\n");
	}
	for (i=0; i<s; i++) {
		write(sprintf("  %s", TC_KEY + capitalize(ch[i]) + "Who" + TC_KEY + "[" + ch[i] + "]" TC_NORMAL
		                    + TC_KEY + capitalize(ch[i]) + "Msg" + TC_KEY + " texto" TC_NORMAL) +"\n");
	}
	write("\n");
	write("El color de las salidas es:\n");
	write(TC_EXIT "  Ves varias salidas: salida, salida2.\n" TC_NORMAL);
	write("\n");
	write("El color de los tel es:\n");
	write(TC_TEL_WHO + "  Alguien te dice" TC_NORMAL ": " + TC_TEL_MSG + "este es un mensaje.\n" TC_NORMAL);
//Nyh empieza
	write("\n");
	write("El color de los mensajes de combate es:\n");
	write(TP->QueryColorAtaco() + "  Atacas a Pepe pero fallas." TC_NORMAL);
	write("\n");
	write(TP->QueryColorAtacado() + "  Pepe te ataca pero falla." TC_NORMAL);
	write("\n");
	write(TP->QueryColorAjeno() + "  Juan ataca a Pepe pero falla." TC_NORMAL);
	write("\n");
//Nyh acaba
	return 1;
}

//Nyh empieza
int _color_combate(string tipo, string color) {
	string *tcolor;
	string out;

	if ((tipo||"") == "" || (color||"") == "") {
		return _color_use();
	}
	tcolor = _explode_color(color);
	if (!_check_color(tcolor)) return 0;

	switch (tipo) {
		case "ataco":
			TP->SetColorAtaco(ANSI_REP[tcolor[0]]+ANSI_REP[tcolor[1]]);
			out = "Cambiado el color de los ataques realizados a ";
			break;
		case "defiendo":
			TP->SetColorAtacado(ANSI_REP[tcolor[0]]+ANSI_REP[tcolor[1]]);
			out = "Cambiado el color de los ataques recibidos a ";
			break;
		case "otros":
			TP->SetColorAjeno(ANSI_REP[tcolor[0]]+ANSI_REP[tcolor[1]]);
			out = "Cambiado el color de los ataques entre los demas a ";
			break;
		default:
			return _color_use();
	}
	out +=implode(explode(color, "+"), " ");
	out += ".\n";
	write(out);
	return 1;
}
//Nyh acaba

int main(string str) {
	string *args;
	string txtcolor;
	if ((str||"") == "") {
		return _color_use();
	}
	str = lower_case(str);
	args = explode(str, " ") - ({""});
	switch(args[0]) {
		case "canal":
			if (sizeof(args) < 3) {
				return _color_use();
			}
			else if (sizeof(args) == 3) {
				txtcolor = "ninguno";
			}
			else {
				txtcolor = args[3];
			}
			return _channel_color(args[1], args[2], txtcolor);
		case "tel":
			if (sizeof(args) < 2) {
				return _color_use();
			}
			else if (sizeof(args) == 2) {
				txtcolor = ANSI_NONE;
			}
			else {
				txtcolor = args[2];
			}
			return _tel_color(args[1], txtcolor);
		case "lista":
			return _color_list();
		case "salidas":
			if (sizeof(args) < 2) {
				return _color_use();
			}
			return _color_exits(args[1]);
		case "estado":
			return _color_status();
//Nyh empieza
		case "combate":
			if (sizeof(args) != 3) {
				return _color_use();
			}
			return _color_combate(args[1],args[2]);
//Nyh acaba
		default:
	}
	return _color_use();
}
