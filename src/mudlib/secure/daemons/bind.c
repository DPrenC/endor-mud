/**
 * bind.c   BINary Daemon
 */

#include "/secure/wizlevels.h"
#include <gremios.h>

private string *path;

int exists(string str) {
    string s1, s2;
    if(strstr(str, "..") != -1) return 0;
    if(file_size(str) < 0) return 0;
    else return 1;
}

private add_path (string p) {
   if (member(path, p)==-1) path += ({ p });
}

int bin_cmd(string str) {
    string verb, rest, bar;
    int i, foo;
    string s1, s2;
    string file;
    string tmp_path;
    string *og;

    if (sscanf(str, "%s %s", verb, rest) != 2) verb = str;
    if (   environment(TP)
        && function_exists(verb,environment(TP)))
        return 0;  // Si la funcion existe en el entorno, ejecutarla

    /* [k] Es necesario el seteuid para permitir que el bind carge el magicd
           debido a que objetos con el euid=0 no pueden hacerlo              */

    seteuid(getuid(TO));

    path = TP->QueryPath() || ({});
    if (!sizeof(path)) {
      add_path("/bin/mortal");
      add_path("/bin/mortal/tiflo");
      if (IS_LEARNER(TP)) {
        add_path("/bin/wiz");
      }
      if (IS_ARCH(TP)) {
        add_path("/secure/bin");
      }
      if (bar=TP->QueryGuild()) add_path(GUILD_PATH[bar]+"bin/");

      og = m_indices(TP->QueryOldGuilds());
      i = sizeof(og);

      while (i--) {
        add_path(GUILD_PATH[og[i]]+"bin/");
      }

      TP->SetPath(path);
    }

    file = "_" + verb; // + ".c";
    for ( i=sizeof(path); i--; ) {
        tmp_path = path[i] + "/" + file;
        if ( exists( tmp_path+".c" ) )
            if ( foo = ( call_other(tmp_path, verb, rest) || call_other(tmp_path, "main", rest) ) )
                return foo;
    }

    /* Anteriormente este camino de busqueda de comandos era tratado conjuntamente
       con el resto de paths de wizs para permitir lanzar los conjuros base a traves
       de la linea de comandos. Cambios posteriores en MAGICD han hecho que se separe
       debido a que la llamada a conjuros incluye el objeto lanzador, y este formato
       difiere del usado en el BIND, que solo maneja la cadena de entrada de la linea
       de comandos     [k]         							*/

    if( IS_WIZARD( TP)) {
        tmp_path = "/bin/spells/base/" + file;
        if(exists( (tmp_path+".c") ))
            if( foo=call_other(tmp_path,"main",TP,rest))
              return foo;
    }

    return 0;
}
