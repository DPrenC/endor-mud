// Comando cls

int main() {
  int i;

  if (!TP) return 0;

  for (i = TP->QueryConsoleHeight()+1; i--; ) printf("\n");
  return 1;
}
