/* Archivo tonto de 'comer' para que aunque no tengas un std/food puedas poner
	la orden comer
   Theuzifan, 12-03-99
*/
int main(string str)
{
  if (!str) return notify_fail("¿Qué quieres comer?\n");
  return notify_fail("No tienes "+str+" para comer.\n");
}