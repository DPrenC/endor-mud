// Comando fecha
int main (string arg) {
  string rc, cdate;
  string dia, mes;
  mixed * uptime;

  seteuid(getuid());

  cdate = ctime(time());
  switch(cdate[0..2])
  {
   case "Mon": dia="Lunes"; break;
   case "Tue": dia="Martes"; break;
   case "Wed": dia="Miércoles"; break;
   case "Thu": dia="Jueves"; break;
   case "Fri": dia="Viernes"; break;
   case "Sat": dia="Sabado"; break;
   case "Sun": dia="Domingo"; break;
   default: dia="Npi";
  }
  switch(cdate[4..6])
  {
   case "Jan": mes="Enero"; break;
   case "Feb": mes="Febrero"; break;
   case "Mar": mes="Marzo"; break;
   case "Apr": mes="Abril"; break;
   case "May": mes="Mayo"; break;
   case "Jun": mes="Junio"; break;
   case "Jul": mes="Julio"; break;
   case "Aug": mes="Agosto"; break;
   case "Sep": mes="Septiembre"; break;
   case "Oct": mes="Octubre"; break;
   case "Nov": mes="Noviembre"; break;
   case "Dec": mes="Diciembre"; break;
   default: mes="Npi";
  }

  rc = "  -- "+dia+", "+cdate[8..9]+"-"+mes+"-"+cdate[22..23]+" "+cdate[11..18]+" --\n";

  uptime = (mixed *)GAMECLOCK->QueryUptime();
  rc += "  Arda ha sido destruída y reconstruida por última vez hace ";
  if (!pointerp(uptime)) rc += " demasiado";
  else rc += ": "+implode(map(uptime, SF(to_string)), " ");
  rc += "\n";

  // [w] Anyadido para que resalte ciertos dias
  if (mes=="Enero" && cdate[8..9]==" 6")
     rc += "Nacimiento de Tolkien.\n";
                    if (mes=="Enero" && cdate[8..9]==" 1")
     rc += "  NOTICIAS: ¡FELIZ AÑO NUEVO!\n";
  if (mes=="Diciembre" && (cdate[8..9]=="25"||cdate[8..9]=="26"||cdate[8..9]=="27"
                         ||cdate[8..9]=="29"||cdate[8..9]=="30"||cdate[8..9]=="31"))
     rc += "  NOTICIAS: ¡NAVIDAD, NAVIDAD, DULCE NAVIDAD!\n";
  if (mes=="Diciembre" && cdate[8..9]=="28")
     rc += "  NOTICIAS: En cuanto salgas del mud tu personaje se borrará.\n";

  write(rc);
  return 1;
}
