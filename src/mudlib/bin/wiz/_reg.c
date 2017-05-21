#include <files.h>
#include "/secure/wizlevels.h"
#include <colours.h>

int show_use() {
	write("Utilidad del registro de Simauria.\n");
	write("uso:\n");
	write(TC_BOLD+"  reg "+TC_NORMAL+"<opciones> <registro>.\n");
	write("donde <opciones> es una de las siguientes:\n");
	write(TC_BOLD+"    list"+TC_NORMAL+": lista los registros\n");
	write(TC_BOLD+"    dump"+TC_NORMAL+" <registro> [excl <str>] [incl <str2>]: vuelca un registro,\n");
	write("        excluyendo o incluyendo un path específico.\n");
	if (IS_ARCH(TP)) {
		write(TC_BOLD+"    validate"+TC_NORMAL+" <registro>: elimina las entradas no válidas del registro.\n");
		write("        Se puede usar la llave 'all' para validar todos los registros\n");
		write("        simultáneamente.\n");
		write(TC_BOLD+"    call "+TC_NORMAL+"<registro>->función(parámetros) [excl <str>] [incl <str2>]: realiza\n");
		write("        una llamada a una función determinada de cada objeto del registro que\n");
		write("        concuerde con las reglas definidas de inclusión y exclusión.\n");
	}
	return 1;
}

int show_list() {
	int i, s;
	int count, num;
	string *reg, freg;

	reg = sort_array(get_dir("/log/register/*.o"), SF(>));
	s = sizeof(reg);
	count = 0;
	write("Registros disponibles: " + sizeof(reg) + ".\n");
	for (i=0; i<s; i++) {
		num = sizeof(m_indices("/obj/lib/register"->QueryRegister(reg[i])));
		write(sprintf("%3d) %s: %d entradas\n", i+1, TC_BOLD+lower_case(explode(reg[i], ".o")[0])+TC_NORMAL, num));
		count += num;
	}
	write("Total: " + count + " entradas.\n");
	return 1;
}

private int _get_matching_regs(string reg, mixed incl, mixed excl, mapping map) {
	string freg;
	mapping dump;
	string *val, *idx;
	int s, s2, i, j;
	string str1, str2;
	int filt;
		
	freg = upper_case(reg) + ".o";
	if (file_size("/log/register/"+freg) == FSIZE_NOFILE) {
		write("No existe el registro " + reg + ".\n");
		return 1;
	}
	dump = "/obj/lib/register"->QueryRegister(freg);
	idx = m_indices(dump);
	write("Número de objetos registrados: " + sizeof(idx) + "\n");
	val = ({});
	if (sizeof(incl)) {
		foreach(str1: idx) {
			foreach(str2: incl) {
				if (strstr(str1, str2) != -1) {
					val += ({ str1 });
				}
			}
		}
		idx = val;
	}
	val = ({});
	if (sizeof(excl)) {
		foreach(str1: idx) {
			foreach(str2: excl) {
				if (strstr(str1, str2) != -1) {
					val += ({ str1 });
				}
			}
		}
		idx -= val;
	}
	map = copy(dump);
	val = m_indices(map);
	
	foreach(str1: val) {
		if (member(idx, str1) == -1) {
			m_delete(map, str1);
		}
	}
	return sizeof(dump)-sizeof(map);
}

private mixed _runner(object obj, string fun, string args) {
/*
    file=LPC_FILE+".c";
    if(file_size(file)>0) rm(file);
    if(obj=find_object(LPC_FILE)) Destruct(obj);
    write_file(file,
    	"#pragma verbose_errors\n"
    	"#include <properties.h>\n"
	"object get(string str) {\n"
	"	return PO->XFindObj(str);\n"
	"}\n"
	"mixed eval(object obj, object me, object here){\n"
	"	if (!function_exists(\""+callfun+"\", obj)) {\n"
	"		raise_error(sprintf(\"La función %O->"+callfun+" no existe.\", obj));\n"
	"		return -1;\n"
	"	}\n"
	"	return obj->"+callfun+"("+callexpr+";\n"
	"}\n");
//		TP->command_me(sprintf("xcall %s->%s(%s)", idx[i], fun, args));
*/
	return call_other(obj, fun, args);
}

int call_reg(string reg, mixed incl, mixed excl) {
	mapping map;
	string *idx;
	int s2, s, i, j;
	int filt;
	string fun, treg;
	string args, err;
	object obj;
	mixed res;
	
	if (sscanf(reg, "%s->%s(%s", treg, fun, args) != 3) {
		printf("REG %s, FUN %s, ARGS %s\n", treg, fun, args);
		return show_use();
	}
	args = args[..<2];
	reg = treg;
	filt = _get_matching_regs(reg, incl, excl, &map);
	idx = m_indices(map);
	s = sizeof(idx);
	for (i=0; i<s; i++) {
		printf("%3d) %s->%s(%s):\n", i+1, TC_BOLD+idx[i]+TC_NORMAL, fun, args);
		if ((err = catch(obj = load_object(idx[i])))) {
			printf(TC_RED+TC_BOLD+"     - ERROR"+TC_NORMAL+": "+err+".\n");
			continue;
		}
		if (!function_exists(fun, obj)) {
			printf(TC_RED+TC_BOLD+"     - ERROR:"+TC_NORMAL+" La funcion '%s' no existe.\n", fun);
			continue;
		}
		res = _runner(obj, fun, args);
		printf("     - Result: "+TC_BOLD+TC_BLACK+"%O\n", res);
		printf(TC_NORMAL);
	}
	if (filt) {
		write("Objetos filtrados: " + filt + ".\n");
	}
	
	return 1;
}

int dump_reg(string reg, mixed incl, mixed excl) {
	mapping map;
	string *idx;
	int s2, s, i, j;
	int filt;
	
	filt = _get_matching_regs(reg, incl, excl, &map);
	idx = m_indices(map);
	s = sizeof(idx);
	for (i=0; i<s; i++) {
		write(sprintf("%3d) %s\n", i+1, idx[i]));
		if (pointerp(map[idx[i]])) {
			j=0;
			foreach(mixed m: map[idx[i]]) {
				write(sprintf("%5d.%d) %O\n", i+1, j+1, m));
				j++;
			}
		}
		else {
			write(sprintf("%5d.1) %O\n", i+1, map[idx[i]]));
		}
	}
	if (filt) {
		write("Objetos filtrados: " + filt + ".\n");
	}
	return 1;
}

/*	
int dump_reg(string reg, mixed incl, mixed excl) {
	string freg;
	mapping dump;
	string *idx, *val;
	int s, s2, s3, i, j;
	string str1, str2;
	int filt;
		
	freg = upper_case(reg) + ".o";
	if (file_size("/log/register/"+freg) == FSIZE_NOFILE) {
		write("No existe el registro " + reg + ".\n");
		return 1;
	}
	dump = "/obj/lib/register"->QueryRegister(freg);
	idx = m_indices(dump);
	write("Número de objetos registrados: " + sizeof(idx) + "\n");
	val = ({});
	s2 = sizeof(idx);
	if (sizeof(incl)) {
		foreach(str1: idx) {
			foreach(str2: incl) {
				if (strstr(str1, str2) != -1) {
					val += ({ str1 });
				}
			}
		}
		idx = val;
	}
	val = ({});
	if (sizeof(excl)) {
		foreach(str1: idx) {
			foreach(str2: excl) {
				if (strstr(str1, str2) != -1) {
					val += ({ str1 });
				}
			}
		}
		idx -= val;
	}
	s = sizeof(idx);
	for (i=0; i<s; i++) {
		write(sprintf("%3d) %s\n", i+1, idx[i]));
		if (pointerp(dump[idx[i]])) {
			s3 = sizeof(dump[idx[i]]);
			for (j=0; j<s3; j++) {
				write(sprintf("%5d.%d) %O\n", i+1, j+1, dump[idx[i]][j]));
			}
		}
		else {
			write(sprintf("%5d.1) %O\n", i+1, dump[idx[i]]));
		}
	}
	s=sizeof(idx);
	filt = s2-s;
	if (filt) {
		write("Objetos filtrados: " + filt + ".\n");
	}
	return 1;
}
*/	
int validate_reg(string reg) {
	string freg;
	string *entr;

	if (reg == "all") {
		string *regs = get_dir("/log/register/*.o");
		int t = 0;
		foreach (string f: regs) {
			entr = "/obj/lib/register"->ClearEntries(f);
			"/obj/lib/register"->SaveRegister(f);
			t += sizeof(entr);
		}
		if (t) {
			write("Eliminadas " + t + " entradas no válidas.\n");
		}
		else {
			write("No hay entradas no válidas a eliminar.\n");
		}
		return 1;
	}
			
	freg = upper_case(reg) + ".o";
	if (file_size("/log/register/"+freg) == FSIZE_NOFILE) {
		write("No existe el registro " + reg + ".\n");
		return 1;
	}
	entr = "/obj/lib/register"->ClearEntries(freg);
	write("Eliminadas " + sizeof(entr) + " entradas del registro '" + reg + "'.\n");
	return 1;
}

int reg(string what) {
	string *args;
	mixed excl, incl;
	if (!what) {
		return show_use();
	}
	
	args = explode(what, " ");
	switch(args[0]) {
	case "list":
		return show_list();
	case "validate":
		if (!IS_ARCH(TP)) {
			return show_use();
		}
		if (sizeof(args) < 2) {
			return show_use();
		}
		return validate_reg(args[1]);
	case "call":
		switch(sizeof(args)) {
		case 1: return show_use();
		case 2: return call_reg(args[1], ({}), ({}));
		case 6: if (args[4] == "excl") {
				excl = args[5];
			}
			else if (args[4] == "incl") {
				incl = args[5];
			}
		case 4: if (args[2] == "excl") {
				excl = args[3];
			}
			else if (args[2] == "incl") {
				incl = args[3];
			}
			if (stringp(excl)) excl = explode(excl, ":");
			if (stringp(incl)) incl = explode(incl, ":");
				
			return call_reg(args[1], incl, excl);
			break;
		}
		break;
	case "dump":
		switch(sizeof(args)) {
		case 1: return show_use();
		case 2: return dump_reg(args[1], ({}), ({}));
		case 6: if (args[4] == "excl") {
				excl = args[5];
			}
			else if (args[4] == "incl") {
				incl = args[5];
			}
		case 4: if (args[2] == "excl") {
				excl = args[3];
			}
			else if (args[2] == "incl") {
				incl = args[3];
			}
			if (stringp(excl)) excl = explode(excl, ":");
			if (stringp(incl)) incl = explode(incl, ":");
				
			return dump_reg(args[1], incl, excl);
			break;
		}
		break;
	}
	return show_use();	
}