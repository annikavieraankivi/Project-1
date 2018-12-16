#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char c;
    int lkm;
    FILE *tiedosto;
    if (argc == 1) {
   	 printf("my-unzip: file1 [file2 ...]\n");
   	 exit(1);
    }
    for (int i = 1; i<argc; i++) {
   	 tiedosto = fopen(argv[i], "r");

   	 if (tiedosto == NULL) {
   		 printf("my-unzip: cannot open file.\n");
   		 exit(1);
   	 } 
   	 while ((fread(&lkm, 1, sizeof(lkm), tiedosto)) > 0 && (fread(&c, 1, sizeof(c), tiedosto)) > 0) {
   		 for (int i = 0; i < lkm; i++) {   // Tässä loopissa tulostetaan kirjain niin monta kertaa 
   			 printf("%c", c);         // kuin lkm osoittaa
   		 }
   	 }
    }
    printf("\n");
    fclose(tiedosto);
    return 0;
}
