// Comando salvar
#include <sounds.h>

int main(string str) {
  if (!TP) return 0;
  write("Salvando...\n");
  TP->save();
  play_sound(TP, SND_SUCESOS("salvar"));
  write("ficha salvada.\n");
  return 1;
}
