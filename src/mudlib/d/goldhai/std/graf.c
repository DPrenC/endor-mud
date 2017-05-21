/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 01-02-97                |
 |               Ultima Modificacion.. 18-02-97                |
 |                                                             |
 | NOTA: Sistema de Grafs de Goldhai.                          |
 |                                                             |
 | 18-02-97 [w] Totalmente independiente de habitacion.c y     |
 |              groom.c                                        |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"

private static mixed Pgraf_text;

// El primero de GrafPlaces es el que sale en impresion, por ejemplo
// SetGrafPlaces(({"la pared","pared","casa"}));
private static string *GrafPlaces=({});

public mixed QueryGraf() { return Pgraf_text; }
public mixed SetGraf(mixed text) { return  Pgraf_text = text; }
public mixed SetGrafPlaces(string *places) { return GrafPlaces = places; }

static add_graf_commands()
{
 add_action("cmd_paint","pintar");
 add_action("look_graf","mirar");
 add_action("look_graf","m");
 add_action("look_graf","examinar");
 add_action("look_graf","exa");
}

cmd_paint(string str)
{
 string where, what;

 if(!TP) return 0;
 if(!str)
   return write("Pintar Que en Donde??\n"),1;

 if(sscanf(str, "%s en %s", what, where) !=2)
   return write("Pintar Que en Donde??\n"),1;

 if(!GrafPlaces)
   return write("Estas loco?, te podrian ver!!\n"),1;

 if(member(GrafPlaces,where)==-1) return
   write("Donde?? creo que eso no esa aqui.\n"),1;

 if(Pgraf_text) return
   write("Ya hay algo pintado ahi, busca otro lugar.\n"),1;

 write("Has pintado '"+what+"' en "+GrafPlaces[0]+".\n");
 say(TNAME+" ha pintado '"+what+"' en "+GrafPlaces[0]+".\n");
 SetGraf(what);
 return 1;
}

look_graf(string str)
{
 if(!str) return 0;
 if(member(GrafPlaces,str)==-1) return 0;
 if(!Pgraf_text)
 {
  say(TNAME+" mira "+GrafPlaces[0]+" con detenimiento.\n");
  write("Miras "+GrafPlaces[0]+".. hmm.. todo parece normal.\n");
  return 1;
 }
 say(TNAME+" contempla una pintada que hay en "+GrafPlaces[0]+".\n");
 write("Puedes ver pintado en "+GrafPlaces[0]+" '"+Pgraf_text+"'.\n");
 return 1;
}
