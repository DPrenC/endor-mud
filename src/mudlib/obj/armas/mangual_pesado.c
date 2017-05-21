/* Fichero: mangual_pesado.c */

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANGUAL, 12, P_SIZE_GENERIC, M_HIERRO);
   SetShort("un mangual pesado");
   SetLong(
   "Es un mangual con mango metálico de algo más de un metro de largo, del que cuelgan "
   "un par de cadenas rematadas por  dos pesadas bolas de hierro.\n"
   "Es un arma pesada, difícil de manejar y poco precisa, pero sus golpes son "
   "demoledores y las cadenas pueden enrrollarse en torno a las armas del enemigo "
   "arrebatándoselas o estorbando sus ataques.\n"
   "Pocas son las razas que utilizan estas exóticas armas, aunque algunos clanes de "
   "Enanos orientales las tienen en gran estima.\n");
  }