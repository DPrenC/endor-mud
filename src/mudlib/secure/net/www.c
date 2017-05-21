/* SIMAURIA
 * Archivo: /secure/net/www.c
 * Utilidad: Se encarga de controlar todos los servicios web on-line
 *      del mud, es decir de las fichas de los dominios, de la
 *      de los personajes, etc... Tambien del arbol genealogico
 *      y de parte de las news.
 *
 * [d] Deepthought
 * [m] Mirill
 * ========
 * ??/??/??  [d] Creacion.
 * 16/09/97  [m] Traducido y adaptado a Silvia.
 * 30/09/97  [m] Modificado en modo tabla con la foto de cada wizard.
 * 01/11/97  [m] Vuelto a modificar por razones varias y por que lo
 *           modifique por que era mio.
 * 23/01/98  [m] Modificado para que salga texto en la StatusBar del
 *           Netscape en todos los links.
 * 11/02/98  [m] Creado el sistema de orla. Este sistema saca una tabla
 *           con la foto de cada wizard, con su nombre y un link a su
 *           ficha.
 * 13/02/98  [m] Mejorado el sistema de orla. Ahora sale separado los dioses,
 *           archs y wizs, y estos ultimos tienen gradacion de color segun su
 *           nivel dentro de un dominio.
 * 01/05/98  [m] Desactivado la parte de los players, debido a la gran cantidad
 *           que hay y que hacen que mandar la variable sea muy costoso.
 * 06/05/98  [m] Adaptado al nuevo country.c (woo) y ademas asi sale separados
 *           los players y los wizards conectados.
 * 10/06/98  [m] Incluida la posibilidad de poner la historia del personaje
 *           en la web.
 * 28/09/98  [m] Comienza el cambio de todo el sistema para adaptarlo a la
 *           nueva web.
 * 21/10/98  [m] Implantacion definitiva.
 * 22/10/98  [m] Implementada la leyenda, el formulario para pedir la ficha de
 *           jugadores que no aparecen y conectada la parte de JANs.
 * 04/02/99  [m] Corregido el formato de la tabla a 8 para que se vea mejor
 * 16/03/99  [m] Correciones varias
 * 24/03/99  [m] Anyadidas ciertas funciones para comprobar el ultimo mensaje
 *           escrito en los tablones
 * 28/03/99  [m] Anyadida otra funcion para ver los tablones solo de wizys y
 *           adaptado todo el sistema al pasar el por el mud.cgi. Ademas
 *           anyadido el sistema de proteccion por IP para impedir acceder
 *           directamente al mud.
 * 04/04/99  [m] Creacion de un nuevo sistema, integrando el mud.cgi en los cgis
 *           existentes para facilitar la actualizacion.
 * 12/04/99  [m] Diversos arreglos derivados del nuevo sistema de consulta.
 * 30/04/99  [m] Arreglada la orla. Petaba por tener que generar la pagina con demasiada
 *           información. Cambiado el sistema de consulta de dominios en la ficha.
 * 26/05/99  [m] Cambiada parte de la orla, para no utilizar el file_size y
 *           evitar asi los bonitos "Too long evaluation" que salian". Ahora
 *           practicamente todo se resuelve con member_arrays.
 *
 */
#include "/secure/config.h"
#include "/secure/wizlevels.h"
inherit "/secure/mdt_std_funcs.c";
inherit "/lib/country.c";
inherit "/obj/lib/mdtqs";


#define NOPROMPT set_prompt("")
#define PREWWW ("http://www.simauria.upv.es/cgi-bin/main.cgi?tipo=cns&pagina=")
#define WEB_PORT 4250

QueryPresay() { return "Simauria "; }
QueryName() { return "Gopher"; }
QueryTitle() { return "Dimoni de servicios (deaf)"; }
QueryShort() { return (QueryPresay()+" "+QueryName()+" "+QueryTitle()); }
QueryRealName() { return "Gopher"; }
QueryPlayer() { return 1; }
IsServiceDemon() { return 1; }

query_prevent_shadow() { return 1; }

string getstring;
string *addstrings;
string pre;
string html;
string html1;
string nivel;
int extra;
string cabecera;

#define TZSECS (-60*60)
string gmtime(int tim)
{
  string ctim;
  string gmtim;

  ctim = ctime(tim+TZSECS);
  switch (ctim[0..2]) {
    case "Mon":
      gmtim = "Lunes";
      break;
    case "Tue":
      gmtim = "Martes";
      break;
    case "Wed":
      gmtim = "Miércoles";
      break;
    case "Thu":
      gmtim = "Jueves";
      break;
    case "Fri":
      gmtim = "Viernes";
      break;
    case "Sat":
      gmtim = "Sábado";
      break;
    case "Sun":
      gmtim = "Domingo";
      break;
  }
  return gmtim + ", "+ctim[8..9]+"-"+ctim[4..6]+"-"+ctim[22..23]+" "+
    ctim[11..18]+" GMT";
}
void send_html(string ht)
{
//  string ht2;
//  ht2 = "<HTML>\n"+ht+"</HTML>\n";
  if (extra) {
   write("HTTP/1.1 200 OK\n"+
   "Date: "+gmtime(time())+"\n"+
    "Server: Simauria/1.0\n"+
    "MIME-version: 1.0\n"+
    "Content-type: text/text\n"+
    "Last-modified: "+gmtime(time())+"\n"+
    "Expires: "+gmtime(time()+10)+"\n"+
//    "Content-length: "+strlen(ht2)+"\n"+
    "\n");
  }
  ht += "<font color=#000000>\n";
  write(ht);
}

void destruct_me()
{
  destruct(this_object());
}

int get_input(string str)
{
  log_file("www.ext","-->"+str+"<---\n");
  return 1;
}
/*
 * This is the function that gets called by /secure/login after name and
 * password is verified and this object is loaded.
 */
start_player(str) {
  string color;
  object p;
  string file;
  string str1, str2, fro_ip, mud_ip, aux;
  string *strs, *orlastr, *players, *l_players, *orlastr2;
  int *sizes;
  int i, orla, j, k;
  mapping orlmap;

  NOPROMPT;
  add_action("get_input", "", 1);

  fro_ip = query_ip_number(this_object());
//  mud_ip = query_ip_number();
//  if (fro_ip != mud_ip) {
    if (fro_ip != "158.42.96.118") {
    html = "Lo siento pero no esta permitido el acceso a esta pagina";
    send_html(html);
    call_out("destruct_me", 5);
    return 1;
    }
/*
  if (p=find_object("mirill")) {
    tell_object(p,"www: ["+str+"]("+query_ip_name()+" "+query_mud_port()+" )\n");
    log_file("www","["+str+"] ("+query_ip_name()+" "+query_mud_port()+" )\n");
  }
*/
  extra = 0;
  if (sscanf(str, "%s %s", str1, str2) == 2) {
    str = str1;
    extra = 1;
  }
  pre = "";
  html = "";
  cabecera = "";
  switch (str) {
      case "/":
        str = "/index.html";
        break;
      case "/quien":
        who_list();
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      case "/quientxt":
        who_list();
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      case "/arbol":
        list_tree();
        send_html(html);
        call_out("destruct_me", 5);
        return 1;
      case "/razas":
    html += ("<center><H2>Razas en Simauria</H2></center>\n");
    strs = (string *) RACEMASTER->AllRaceNames() - ({"visitante","vampiro","esclavo","visitor","vampire","slave"});
    html += ("<DL>");
    for (i = 0; i < sizeof(strs); i++) {
    html += ("<br><br>");
    html += ("<DT><A NAME=\""+strs[i]+"\" ><b>"+capitalize(strs[i])+"</b></A><br>");
    html += ("<br><dd>"+RACEMASTER->RaceDescr(strs[i])+"\n");
    }
    html += ("</DT></DL>\n");
    send_html(html);
    call_out("destruct_me", 5);
    return 1;

// Orla. Crea una tabla con las fotos de todos los wizs y sus nombres.

      case "/orla":
    call_out("destruct_me", 15);
    html += ("<script Language=\"JavaScript\">\n");
    html += ("document.write('<!-- Begin Hiding Script -->')\n");
    html += ("function cargaficha(){\n");
    html += ("var f = document.ficha.jugador.value.toLowerCase()\n");
    html += ("document.location.href=\"http://www.simauria.upv.es/cgi-bin/main.cgi?tipo=cns&pagina=w/\" + f + \"/\"\n");
    html += ("}\n");
    html += ("document.write('<!-- End Hiding Script -->')\n");
    html += ("</script>\n");
    html += ("<br><br>\n");
    html += ("<center><TABLE width=550 border=0 bordercolor=#000000>\n");

    orlastr = get_dir("/players/???*");
    orlmap = ([ ]);
    orlastr2 = get_dir("/fotos/*.jpg");
      for (i = 0; i < sizeof(orlastr2); i++) {
//       tell_object( find_object("mirill"), ">"+orlastr2[i]+"\n" );

//       if (MASTER->find_userinfo(orlastr2[i][<4])){
          aux = orlastr2[i];
          aux = aux[0..strlen(aux)-5];
          orlastr2[i] = aux;

//         tell_object( find_object("mirill"), "<"+orlastr2[i]+"\n" );
//    }
    }
    players = get_dir("/save/*");
    orla=0;

// Crea la primera parte de la tabla, mirando los Gods.

    html += ("<tr align=center height=40><td colspan=11><font size=+2 color=#FFFFFF>Los Gods de Simauria</font><br></td></tr><tr>");
     for (i = 0; i < sizeof(orlastr); i++) {
      if (IS_GOD(orlastr[i]) == 1) {
        html += ("<td align=center width=70 height=100 bgcolor=#FFFCC6>");
//      tell_object( find_object("mirill"), ">"+orlastr2[i]+"!!\n" );
       if( member(orlastr2, orlastr[i]) == -1 )
          html += ("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" onmouseover"+
                   "=\"window.status=' Ver la ficha de "+ capitalize(orlastr[i]) +" '"+
                   ";return true;\" onmouseout=\"window.status=' Página de Simauria '"+
                   ";return true;\" border=0>"+
                   "<img src=http://www.simauria.upv.es/fotos/foto.jpg width=50 border=0>"+
                   "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
        else
          html +=("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" onmouseover"+
                  "=\"window.status=' Ver la ficha de "+ capitalize(orlastr[i]) +" '"+
                  ";return true;\" onmouseout=\"window.status=' Página de Simauria '"+
                  ";return true;\">"+
                  "<img src=http://www.simauria.upv.es/fotos/"+orlastr[i]+".jpg width=50 border=0>"+
                  "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
      orla++;
      if (orla % 8 == 0) html +=("</tr><tr>");
    }
  }
html += ("</tr>");
html += ("<tr><td><br></td></tr>");

// Crea la tabla correspondiente a los Arch

    orla=0;
    html += ("<tr align=center heigth=40><td colspan=11><font size=+2 color=#FFFFFF>Los Archwizs de Simauria</font><br></td></tr><tr>");
    for (i = 0; i < sizeof(orlastr); i++) {
      if (IS_GOD(orlastr[i]) == 1) { }
         else {
      if (IS_ARCH(orlastr[i]) == 1) {
       html += ("<td align=center width=70 height=100 bgcolor=#C5FED1>");

       if( member(orlastr2, orlastr[i]) == -1 )

          html += ("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" onmouseover"+
                   "=\"window.status=' Ver la ficha de "+ capitalize(orlastr[i]) +" '"+
                   ";return true;\" onmouseout=\"window.status=' Página de Simauria '"+
                   ";return true;\" border=0>"+
                   "<img src=http://www.simauria.upv.es/fotos/foto.jpg width=50 border=0>"+
                   "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
        else
          html +=("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" onmouseover"+
                  "=\"window.status=' Ver la ficha de "+ capitalize(orlastr[i]) +" '"+
                   ";return true;\" onmouseout=\"window.status=' Página de Simauria '"+
                   ";return true;\">"+
                   "<img src=http://www.simauria.upv.es/fotos/"+orlastr[i]+".jpg width=50 border=0>"+
                   "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
      orla++;
        if (orla % 8 == 0) html += ("</tr><tr>");
      }
    }
   }
html += ("</tr>");
html += ("<tr><td><br></td></tr>");

// Crea la tabla de los Wizs normales
    orla=0;
    html += ("</tr><tr align=center height=40><td colspan=11><font size=+2 color=#FFFFFF><center>Los Wizards de Simauria</font><br></td></tr><tr>");
    for (i = 0; i < sizeof(orlastr); i++)
    {
//      tell_object( find_object("mirill"), ">>>> " + orlastr[i] + ", " + file_size( "/players/" + orlastr[i] ) + "\n" );
      html += ("<td align=center width=70 height=100");
      if( !IS_ARCH( orlastr[i] ) )
       {
          if (IS_LORD(orlastr[i]))
             html += (" bgcolor=#4545FF>");
          else
            if (IS_VICE(orlastr[i]))
               html += (" bgcolor=#7575FF>");
            else
               html +=(" bgcolor=#B0B0FF>");
//          tell_object( find_object("mirill"), ">>>" +orlastr[i]+ ", "+ file_size( "/fotos/" +orlastr[i]+".jpg" )+ "\n");
//          if(file_size("/fotos/"+ orlastr[i] +".jpg") <= 0)
//          tell_object( find_object("mirill"), ">>>" +orlmap[orlastr[i]]+ "\n");
            if( member(orlastr2, orlastr[i]) == -1 ) {

//           tell_object( find_object("mirill"), ">"+orlastr[i]+">"+orlastr2[i][<4]+">" +member(orlastr2, orlastr[i])+ "\n");
             html += ("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" border=0>"+
                  "<img src=http://www.simauria.upv.es/fotos/foto.jpg width=50 border=0>"+
                  "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
            }
            else
               html +=("<A HREF=\""+PREWWW+"w/"+orlastr[i]+"/\" border=0>"+
                    "<img src=http://www.simauria.upv.es/fotos/"+orlastr[i]+".jpg width=50 border=0>"+
                    "<br><font color=#000000 face=Arial size=0>"+capitalize(orlastr[i])+"</td>\n");
          orla++;
          if (orla % 8 == 0)
             html += ("</tr>");
       }
      }
    html += ("<tr><td colspan=11 align=center>");
    html += ("<table border=0 width=60%>");
    html += ("<tr><td align=center colspan=3>");
    html += ("<font face=Arial color=#FFFFFF><b>Leyenda</b></td></tr>");
    html += ("<tr><td bgcolor=#4545FF align=center width=20%><font color=#000000 face=Arial><b>Lord/Lady</font></b></td>");
    html += ("<td bgcolor=#7575FF align=center width=20%><font color=#000000 face=Arial><b>Vicelord/ViceLady</font></b></td>");
    html += ("<td bgcolor=#B0B0FF align=center width=20%><font color=#000000 face=Arial><b>Member</font></b></td>");
    html += ("</table></td></tr><tr>");

// Crea la parte de la tabla para los players. Solo para JAN.
/*
    orla=0;
    html += ("</tr><tr align=center><td colspan=11><font size=+2><center>Los Jugadores de Alto Nivel de Simauria</font></td></tr><tr>");
    for (i=2; i<sizeof(players); i++)
    {
     l_players=get_dir("/save/"+players[i]+"/??*");
     for (j=2; j<sizeof(l_players); j++)
     {
      if (l_players[j][strlen(l_players[j])-1] == 'o')
      {
      if (!(IS_LEARNER(l_players[j][0..<3])==1))
      {
//       if (IS_JAN(l_players[j][0..<3])==1)
//       {
      html += ("<td align=center valign=center");
      html += (" bgcolor=#FFB5B5>");
      html += ("<A HREF=\""+PREWWW+"w/"+l_players[j][0..<3]+"/\" \n onmouseover"+
      "=\"window.status=' Ver la ficha de "+ capitalize(l_players[j][0..<3]) +" '"+
      ";return true;\" \n onmouseout=\"window.status=' Página de Simauria '"+
      ";return true;\">"+
      " \n <font color=#000000 face=Arial size=0>"+capitalize(l_players[j][0..<3])+"</td>\n");
     orla++;
     if (orla % 8 == 0)
      html +=("</tr><tr>");
        }
       }
      }
     }
    }
*/
    html += ("<td colspan=8 align=center>");
    html += ("<hr align=center size=1 width=85%><font face=Arial color=#FFFFFF>");
    html += ("<p align=justify>");
    html += ("Para evitar que la orla sea demasiado grande, sólo incluimos ");
    html += ("a los Jugadores de Alto Nivel (JAN). ");
    html += ("Si tu nombre no aparece, ponlo aquí para ver tu ficha.</font></p>");
    html += ("<form name=ficha><font size=+2 color=#FFFFFF><b>");
    html += ("Nombre del jugador: </font></b><input type=text name=jugador>");
    html += ("<input type=button value=\"Ver ficha\" onClick=\"cargaficha()\">");
    html += ("</form></td>");
    html += ("</tr></TABLE>");
    send_html(html);
//    call_out("destruct_me", 2);
    return 1;

      case "/dominios":
    html += ("<center><H2>Los Dominios de Simauria</H2></center>\n");
    html += ("<UL>");
    strs = get_dir("/d/???*");
    for (i = 0; i < sizeof(strs); i++) {
      if (file_size("/d/"+strs[i]) == -2) {
        html += ("<body text=#FFFFFF link=#FF8080 vlink=#FF8080 bgcolor=#0000000>\n");
        html += ("<LI><A HREF=\""+PREWWW+"d/"+strs[i]+"/\" onmouseover=\"window.status=' Ver la ficha del dominio "+ capitalize(strs[i]) +" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><b><font color=#FF8080>"
        +capitalize(strs[i])+"</font></b></A>\n");
      }
    }
    html += ("<body text=#FFFFFF link=#FF8080 vlink=#FF8080 bgcolor=#0000000>\n");
    html += ("</UL>");
    send_html(html);
    call_out("destruct_me", 2);
    return 1;
      default:
    sscanf(str,"%s=%s",str1,str2);
    if (str1 && str2 == "/plook?str2") {
      if (str2) {
        str = "/w/"+str2+"/";
      }
      else {
        call_out("destruct_me", 5);
        return 1;
      }
    }
    break;
  }
  strs = explode(str,"/");
  switch (strs[1]) {
    case "w":
      if (sizeof(strs) < 4) {
    call_out("destruct_me", 5);
    return 1;
      }
      if (strs[3] == "") {
    finger_info(lower_case(strs[2]));
    str = "/players/"+lower_case(strs[2])+"/www/index.html";
      }
      else {
    str =
    "/players/"+lower_case(strs[2])+"/www"+MASTER->make_path_absolute(implode(
    strs[3..],"/"),0);
      }
      break;
    case "d":
      if (sizeof(strs) < 4) {
    call_out("destruct_me", 5);
    return 1;
      }
      if (strs[3] == "") {
    domain_info(strs[2]);
    str = "/d/"+strs[2]+"/www/index.html";
      }
      else {
    str =
    "/d/"+strs[2]+"/www"+MASTER->make_path_absolute(implode(strs[3..],"/"),0);
      }
      break;
    case "jformen":
      catch(str = "/secure/net/wwwnews"->formen(0));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    case "wformen":
      catch(str = "/secure/net/wwwnews"->formen(1));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    case "escmen":
      catch(str = "/secure/net/wwwnews"->escribir(strs));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
/*    case "ultima":
      catch(str = "/secure/net/wwwnews"->ultima());
      write_file("/log/news/unoticia", str);
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;*/
    case "jnoticias":
      catch(str = "/secure/net/wwwnews"->show(strs,0));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    case "wnoticias":
      catch(str = "/secure/net/wwwnews"->show(strs,1));
      html += (str);
      send_html(html);
      call_out("destruct_me", 5);
      return 1;
    default:
      str = "/www"+MASTER->make_path_absolute(str,0);
      break;
  }

  catfile(str);
  send_html(html);
  call_out("destruct_me", 5);
  return 1;
}

/*
 * where() is a function which returns the physical country from
 * which the player is logged in. The simul-efun country() is
 * used to return a best guess of the country name from the
 * ip name (usually the top level domain is quite descriptive).
 */
where(ob) { return resolve_ip_number(lower_case(query_ip_number(ob))); }

/*
 * This function provides a list of players.
 */
who_list() {
    string a, b;
    int i, nu, nw, nt;
    string *lines, sh;
    object *list;
    string presay, name, title, files;

    list = users() - ({ this_object() });
    html+=  ("<center><H2>Gente conectada</H2></center>\n");

// Crea la parte para los players
    html += ("<br><br><dd><h3>Jugadores:</h3><ul>");
    html += ("<font size=-1>");
    nu = 0;
    for (i = 0; i < sizeof(list); i++) {
    name = list[i]->QueryRealName();
    if (!(IS_LEARNER(lower_case(name)))) {
    sh = list[i]->QueryShort();
    if (sh && !list[i]->QueryInvis()) {
      presay = list[i]->QueryPresay();
      if (!presay)
        presay = "";
      if (!name)
        continue;
      title = list[i]->Query("MosaicTitle");
      if (!title) {
        title = list[i]->QueryTitle();
        if (!title)
          title = "";
      }
      html += ("<font size=-1>");
      html += ("<LI>"+presay+" <A HREF=\""+PREWWW+"w/"+lower_case(name)+"/\" onmouseover=\"window.status=' Ver la ficha de "+ capitalize(name) +" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><b>"+capitalize(name)+"</b></A> "+title+" [" +where(list[i])+"]\n");
      nu++;
    }
    }
    }
    if (nu) {
     if (nu == 1)
      html += ("</UL><b>Hay "+nu+" jugador conectado.</b><p>\n");
     else
      html += ("</UL><b>Hay "+nu+" jugadores conectados.</b><p>\n");
    }
    else
    html += ("</ul><b>No hay jugadores conectados.</b><p>\n");
    html += ("</font>");
//crea la parte de Wizards:
    html += ("<dd><h3>Wizards:</h3><ul>");
    html += ("<font size=-1>");
    nw = 0;
    for (i = 0; i < sizeof(list); i++) {
    name = list[i]->QueryRealName();
    if (IS_LEARNER(lower_case(name))) {
    sh = list[i]->QueryShort();
    if (sh && !list[i]->QueryInvis()) {
      presay = list[i]->QueryPresay();
      if (!presay)
        presay = "";
      if (!name)
        continue;
      title = list[i]->Query("MosaicTitle");
      if (!title) {
        title = list[i]->QueryTitle();
        if (!title)
          title = "";
      if (IS_ARCH(lower_case(name)))
      html += ("<LI>"+presay+" <A HREF=\""+PREWWW+"w/"+lower_case(name)+"/\" onmouseover=\"window.status=' Ver la ficha de "+ capitalize(name) +" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><b>"+capitalize(name)+"</b></A> "+title+" [" +where(list[i])+"]  - "+query_wiz_tag(list[i])+" -\n");
      else {
      html += ("<LI>"+presay+" <A HREF=\""+PREWWW+"w/"+lower_case(name)+"/\" onmouseover=\"window.status=' Ver la ficha de "+ capitalize(name) +" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><b>"+capitalize(name)+"</b></A> "+title+" [" +where(list[i])+"]\n");
      }
     nw++;
    }
    }
    }
    }
    if (nw) {
     if (nw == 1)
      html += ("</UL><b>Hay "+nw+" wizard conectado.</b><p>\n");
     else
      html += ("</UL><b>Hay "+nw+" wizards conectados.</b><p>\n");
    }
    else
    html += ("</ul><b>No hay wizards conectados.</b><p>\n");




    nt = nu+nw;
    html += ("<br><br><center>\n");
    html += ("<h4>En total hay "+nt+" "+(nt==1 ? "conectado" : "conectados")+", "+
    " "+nw+" "+(nu==1 ? "wizards" : "wizard")+"  y"+
    " "+nu+" "+(nw==1 ? "jugadores" : "jugador")+"</h4>");
    return 1;



}
/*
 * This function generates a tree of wizard sponsorship by querying
 * a 'genealogy tree' object.
 */
list_tree() {
  string *tree;
  int i;
//  html += ("<TITLE>Servicios WWW de Simauria</TITLE>");
  html += ("<center><H2>El Arbol Genealogico de Simauria</H2></center><pre>");
  tree = explode("/players/suamor/mytree"->PrintTree("bigtree",({""})),"\n");
  for (i=0;i<sizeof(tree);i++) {
    html += (tree[i]+"<br>");
  }
  html += ("</pre>");
}

#include <config.h>
#include <living.h>
#include <properties.h>
#include <wizlevels.h>

#define HBINT         2   /* interval between two heart_beats in
seconds    */
#define MINIDLE      60   /* minimum idle time in seconds to be
stated idle */
#define LORDSTR(g)  (g==MALE ? "Lord" : "Lady")
/* We HAVE female Lords !!! */

string dtime(int time);


/*
 * This function generates finger info for a specific player.
 */
finger_info(str)
{
  string filename, *data;
  int    pos, char;
  object player;
  mixed  *userinfo;
  string ip, presay, name, title, race, guild, mailaddr, ipn, ipn2;
  int    ipnum, idle, gender, age, ghost, wizlevel, i;

  ipn = ipn2 = "";

  if (!str || str == "") {
    html += ("<b>Jugador inexistente!</b>\n");
    return;
  }

  /* does this player exist? */
  userinfo=MASTER->find_userinfo(str);
  filename="/save/"+str[0..0]+"/"+str+".o";
  if(!userinfo && file_size(filename)<0) {
    html += ("<b>Este jugador no existe en Simauria.</b>\n");
    return;
  }

  /* is it logged in? */
  player=find_object(lower_case(str));
  if(player) {
    /* the player is logged in: query information directly */
    ipnum=query_ip_number(player);
    if(ipnum) {
      ip=query_ip_name(player);
      if((idle=query_idle(player))<MINIDLE)
      ipn2 = ipnum;
    idle=0;
    } else {
      if(file_size(filename)<0) {
    html += ("<b>Lo sentimos, no se puede mostrar informacion sobre "+ capitalize(str) +".</b>\n");
    return 0;
      }
      data=explode(read_file(filename),"\n");
      ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
      ipn2=(regexp(data,"^llamada_desde")+({""}))[0][15..<2];
    }
    presay=player->QueryPresay();
    ip=player->QueryName();
    name=player->QueryName();
    title=player->QueryTitle();
    race=player->QueryRace();
    guild=player->QueryGuild();
    mailaddr=player->QueryMailaddr();
    gender=player->QueryGender();
    age=HBINT*player->QueryAge();
    ghost=player->QueryGhost();
    if(!(wizlevel=query_wiz_level(player)))
      wizlevel=-player->QueryLevel();

    } else {

    /* the player is not logged in: query the information from the
    savefile */
    if(file_size(filename)<0) {
      notify_fail("<b>Lo sentimos, no se puede mostrar informacion sobre "+ capitalize(str) +".</b>\n");
      return 0;
    }
    data=explode(read_file(filename),"\n");
    idle=file_date(filename);
    ipn2=(regexp(data,"^llamada_desde")+({""}))[0][15..<2];
    ip=(regexp(data,"^called_from_ip")+({""}))[0][16..<2];
    presay=(regexp(data,"^presay")+({""}))[0][8..<2];
    name=capitalize(str);
    title=(regexp(data,"^title")+({""}))[0][7..<2];
    race=(regexp(data,"^aRace")+({""}))[0][7..<2];
    guild=(regexp(data,"^guild")+({""}))[0][7..<2];
    mailaddr=(regexp(data,"^mailaddr")+({""}))[0][10..<2];
    gender=to_int((regexp(data,"^aGender")+({""}))[0][7..]);
    age=HBINT*to_int((regexp(data,"^age")+({""}))[0][4..]);
    ghost=to_int((regexp(data,"^ghost")+({""}))[0][6..]);
    if(!(wizlevel=query_wiz_level(str)))
      wizlevel=-to_int((regexp(data,"^aLevel")+({""}))[0][6..]);

  }


  html += ("<br><br>");
  html += ("<center><font color=#FFFFFF><table width=500 border=0>\n");
  if (file_size("/fotos/"+str+".jpg")<0)
    html += ("<tr><td align=center rowspan=4><img src=http://www.simauria.upv.es/fotos/foto.jpg width=100></td>\n");
  else
    html += ("<tr><td align=center rowspan=4><img src=http://www.simauria.upv.es/fotos/"+str+".jpg width=100></td>\n");
    if(ghost)
    html += (" <td bgcolor=#FFFFFF align=center colspan=3><font face=Arial size=+2 color=#0000FF>"+capitalize(str)+" es un fantasma </font></td></tr>");
    else
    html += (" <td bgcolor=#FFFFFF align=center colspan=3><font face=Arial size=+2 color=#0000FF>"+capitalize(str)+", "+title+"</font></td></tr>\n");

  /* switch to lower case */
  str=lower_case(str);

  /* format some strings */
//  ipn2 = "158.42.96.118";
  if(!race || race=="") race="ninguna";
  if(!guild || guild=="") guild="ninguno";
  if(gender<0 || gender>3) gender=3;
  if(!mailaddr || mailaddr=="") mailaddr="no tiene";
  if(!ipn2 || ipn2 == "") {
    ipn = "Desconocida";
//    ipn = ipn2;
     }
    else
    {
//    ipn = ipn2;
    ipn = "/lib/country"->resolve_ip_number(ipn2);
//    write("hola");
    }
  /* output routine for learners and wizards
   * html += ("<H2>"+presay+name+" "+title+"</H2><p>\n");
   * html += ("<UL>");
   */
//  if(player) {
//    if(ipnum) {
//      html += ("<LI>"+capitalize(str)+" llama desde "+country(ip)+".\n");
//      if(idle)
//  html += ("<LI>Tiempo idle: "+dtime(idle)+"\n");
//      } else
//  html += ("<LI>"+capitalize(str)+" esta desconectado.\n");
//  } else {
//      html += ("<LI>"+capitalize(str)+" no esta conectado.\n"+
//      "<LI>El ultimo login lo hizo desde "+country(ip)+".\n"+
//      "<LI>El ultimo logout lo hizo desde "+ctime(idle)+" ("+dtime(time()-idle)+")\n");
//  }

  if (race == "none")
    html += ("<tr><td bgcolor=#8000FF align=center width=25%><font face=Arial color=#FFFFFF size=+1> Raza: ninguna </font></td>\n");
  else
    html += ("<tr><td bgcolor=#8000FF align=center width~=25%><font face=Arial color=#FFFFFF size=+1> Raza: </font><A HREF=\""+PREWWW+"razas#"+lower_case(race)+"\" onmouseover=\"window.status=' Ver la raza "+capitalize(race)+" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><font face=Arial color=#FF8080 size=+1>"+race+"</a></font></td>\n");
//    html += ("<td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>Gremio: "+guild+" </font></td>\n");
    html += ("<td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>&Uacute;ltima conexión desde: "+ipn+" </font></td>\n");
    html += ("<td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>Sexo: "+ ({"Neutro","Masculino","Femenino", "<ilegal>"})[gender] +"</font></td></tr>\n");
    html += ("<tr><td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>Edad: "+dtime(age)+" </font></td>\n");
    html += ("<td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>E-mail: <a href=mailto:"+mailaddr+" onmouseover=\"window.status=' Escribir a "+ capitalize(str) +" ("+mailaddr+") ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><font face=Arial color=#FF8080 size=+1> "+mailaddr+" </a></font></td>\n");
  if (IS_LEARNER(str)){
    html += ("<td bgcolor=#8000FF align=center><font face=Arial color=#FFFFFF size=+1>Nivel de wizard: "+(wizlevel)+"</font></td></tr>\n");

  data=get_wizard_info(str);
  html += ("<tr><td align=center bgcolor=#8000FF colspan=3><font face=Arial color=#FFFFFF size=+1>Dominios: \n");

  if (gender != 2)
    for (i=0; i<sizeof(data); i++)
    {
      if (i > 0) html += (", ");
      if (data[i][0..0]=="-") html += ("Member de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
      if (data[i][0..0]=="+") html += ("Vicelord de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
      if (data[i][0..0]=="*") html += ("Lord de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
    }
  else
    for (i=0; i<sizeof(data); i++)
    {
      if (i > 0 ) html += (", ");
      if (data[i][0..0]=="-") html += ("Member de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
      if (data[i][0..0]=="+") html += ("Vicelady de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
      if (data[i][0..0]=="*") html += ("Lady de <a href="+PREWWW+"d/"+data[i][1..]+"/>"+capitalize(data[i][1..])+"</a>");
    }


  html +=("</td></tr>");

/*
  data=userinfo[3];
  if(sizeof(data)) {
    html += ("<tr><td align=center bgcolor=#8000FF colspan=3><font face=Arial size=+1>Dominios: \n");
    for(pos=0; pos<sizeof(data); pos++) {
    if(pos)
      html += (", ");
    switch(data[pos][0]) {
    case '+': html += ("Vice ");
    case '*': html += (LORDSTR(gender)+" de <A HREF=\"http://"+PREWWW+"/d/"+data[pos][1..]+"/\"><b>"+capitalize(data[pos][1..])+"</b></A>");
      break;
    default: html += ("Miembro de <A HREF=\"http://"+PREWWW+"/d/"+data[pos]+"/\"><b>"+capitalize(data[pos])+"</b></A></font></td></tr>");
        }
    }
  }

/*   html += ("<tr><td align=center><font face=Arial size=+1>Proyecto:</font></td>\n");
   filename="/players/"+str+"/.project";
  if(file_size(filename)>=0)
    html += ("<td colspan=3><font face=Arial><pre>"+read_file(filename)+"</pre></font></td></tr>\n");
   else
    html += ("<td colspan=3><font face=Arial>Sin proyecto actualmente</font></td></tr>\n");

-- Comprueba si existe plan y si existe lo pone

  filename="/players/"+str+"/.plan";
  html += ("<tr><td bgcolor=#CBFAFC valign=top align=center><font face=Arial size=+1 color=#000000>Plan:</font></td>\n");
  if(file_size(filename)>=0)
    html += ("<td bgcolor=#CBFAFC colspan=3><font face=Arial color=#000000>"+read_file(filename)+"</font></td></tr>\n");
  else {
    html += ("<td bgcolor=#CBFAFC colspan=3><font face=Arial color=#000000>Sin plan actualmente</font></td></tr>\n");
  }
-- Comprueba si existe historia y si existe la pone

  html += ("<tr><td align=center valign=top bgcolor=#CBFAFC><font face=Arial size=+1 color=#000000>Historia:</font></td>\n");
   filename="/players/"+str+"/.historia";
  if(file_size(filename)>=0)
    html += ("<td bgcolor=#CBFAFC colspan=3><font face=Arial color=#000000>"+read_file(filename)+"</font></td></tr></TABLE>\n");
   else {
    html += ("<td bgcolor=#CBFAFC colspan=3><font face=Arial color=#000000>Sin historia actualmente.</font></td></tr></TABLE>\n");
   }
   */
    html += ("</table>");
  return 1;
}
  else
    html += ("<td bgcolor=#8000FF align=center><font face=Arial size=+1 color=#FFFFFF>Nivel: "+(-wizlevel)+"</font></td></tr>\n");
    html += ("</table><br>\n");
  return 1;
}



/*
 * This function provides a time span as days, hours, minutes and seconds.
  */
string dtime(int time)
{
  string ret;

  ret="";
  if(time>=86400) {
    ret+=time/86400+"d ";
    time%=86400;
  }
  if(time<36000) ret+="0";
  ret+=time/3600+":";
  time%=3600;
  if(time<600) ret+="0";
  ret+=time/60+":";
  time%=60;
  if(time<10) ret+="0";
  ret+=time+"";
  return ret;
}


/*
 * This function shows a http page for a specific domain.
 */
domain_info(string str)
{
  string rc, wname;
  mixed *ddata, *dd;
  int state, size, i, j, iv, what;
  string domainsubdir;

  if (!str || str == "")
  {
    html += ("<b>Dominio inexistente!</b>\n");
    return;
  }
  str=lower_case(str);
  ddata=GetDomainInfo(str);

  html += ("<CENTER><H2>Información del dominio "+capitalize(str)+"</H2></CENTER>\n");

  if (sizeof(ddata)>0)
  for (i=0; i<sizeof(ddata); i++)
  {
    dd=explode(ddata[i], ",");
    if (sizeof(dd)>1)
    {
      if (dd[1] == "nadie")
        html+=("<br>Este dominio no tiene ningun "+capitalize(dd[0])+".<p>\n");
      else
      {
        html+=("</UL></ul></ul></ul>");
        html+=("<UL>"+capitalize(dd[0])+": <br><br>");
        for (j=1; j<sizeof(dd); j++)
        {
          html+=("<font size=-1>");
          html+=("<ul><A HREF=\""+PREWWW+"w/"+dd[j]+"/\" onmouseover=\"window.status=' Ver la ficha de "+ capitalize(dd[j]) +" ';return true;\" onmouseout=\"window.status=' Página de Simauria ';return true;\"><b><font color=#FF8080>"+capitalize (dd[j])+"</font></b></A>\n");
          if (find_object(lower_case(dd[j]))) html+=(", conectado.</ul></font>");
          else html+=("</ul></font>");
  //        html+=("</UL>");
        }
      }
    }
  }
  return(1);
}



/*
 * type a file as it is, without reaching the maximum of read_file().
 */
catfile(str)
{
  int siz1,pos1;
  siz1 = file_size(str);
  if (siz1 > 0) {
    for (pos1 = 0; pos1 < siz1; pos1 += 200)
      html += (read_bytes(str,pos1,200));
  }
}


