/*
  Esta es la oficina estandar para ser heredada
  para las oficinas especiales de los archwizards.

  En una oficina normal se encuentra el tablon para discutir temas del dpto.
  Tambien hay reglas o listas en algunas de las oficinas. Una escalera lleva
  hacia abajo donde se describen algunos ejemplos relacionados con la oficina.

  Llama a las siguientes funciones en el create() de tu oficina, tras
  llamar a '::create' para configurarla:

  - SetNombreOficina(string name)

  - SetDescOficina(string desc)

  - SetArchwiz(string *nombrewizards)
    Vector de archwizards y vices, el primero es el archwizard,
    (despues de cada nombre puede estar la fecha de la ultima vez que el
     wizard visito esta habitacion)


  [c] Cadra
  [I] Izet@Simauria, Traduccion.
  [w] Retocado...
*/

inherit ROOM;

#include <wizlevels.h>


string 	*visits;

static  string  office_name, office_desc, *nombrewizards;


void SetNombreOficina(string name)  { office_name = name; }


void SetDescOficina(string desc)  { office_desc = desc; }


void SetArchwiz(string *wizzes) {
  int 	iw, iv, ok;

  nombrewizards = wizzes;

  /* Compara los nombres con las visitas.             */
  /* Los nuevos Arch seran anyadidos, los viejos no seran borrados */

  if(!visits) visits = ({ });
  for(iw = 0; iw < sizeof(nombrewizards); iw++) {
    ok = 0;
    for(iv = 0; !ok && iv < sizeof(visits); iv += 2) {
      if(lower_case(visits[iv]) == lower_case(nombrewizards[iw])) ok = 1;
    }
    if(!ok) {
      visits = ({ lower_case(nombrewizards[iw]), "" }) + visits;
    }
  }
}

string QueryIntShort() { return("Oficina de " + office_name); }


string lformat(string str, int len) {
  return sprintf("%-*s", len, str);
}


varargs string QueryIntLong(string arg) {
  string 	desc, wizzes;
  int 	ind, iv;

  if (!nombrewizards || !sizeof(nombrewizards)) {
    wizzes = "No hay ningun Archwizard reponsable para este departamento!\n";
  }
  else {
    if(sizeof(nombrewizards) > 1)
      wizzes = "Los siguientes Archwizards son responsables de este Departamento:\n";
    else
      wizzes = "El siguiente Archwizard es responsable de este Departamento:\n";
    for(ind = 0; ind < sizeof(nombrewizards); ind++) {
      if(ind == 0)
        wizzes += "Archwizard ";
      else
        wizzes += "Vice       ";
      wizzes += lformat(capitalize(nombrewizards[ind]) + " ", 15);
      for(iv = 0; iv < sizeof(visits); iv += 2) {
        if(lower_case(nombrewizards[ind]) == visits[iv]) {
	  wizzes += "[" + visits[iv + 1] + "]";
	}
      }
      wizzes += "\n";
    }
  }
  desc = "Te encuentras en la Oficina de " +office_name+ ".\n" +office_desc+
      wizzes;
  return process_string(desc);
}


void init() {
  int 	i;
  ::init();
  if(TP &&
     query_ip_name(TP) &&    /* Check on player */
     IS_ARCH(TP)) {
    for(i = 0; i < sizeof(visits); i += 2) {
      if(lower_case((string)TP->QueryRealName()) ==
	 lower_case(visits[i])) {
	visits[i+1] = ctime(time())[0..9];
	save_object(object_name(TO));
      }
    }
  }
}


create() {
  ::create();
  restore_object(object_name(TO));
  if(!visits) visits = ({ });
}
