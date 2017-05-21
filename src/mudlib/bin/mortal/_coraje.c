/* SIMAURIA '/bin/mortal/_coraje.c'
   ================================
   [w] Woo@simauria

   31-03-99 [w] Traspaso desde el player.c.
*/

int main( string arg )
{
  int w;

  if (arg && (!sscanf(arg, "%d", w) || w < 0))
     return notify_fail("uso: coraje <n�mero positivo>\n"),0;

  if (arg)
    TP->SetWhimpy(w);
  if ((w = TP->QueryWhimpy()) > 0)
    write("Intentar�s emprender la huida cuando alcances los  "+w+" puntos de vida.\n");
  else
    write("Decides luchar hasta la muerte.\n"
    "Nada ni nadie te har� retroceder.\n");
  return 1;
}
