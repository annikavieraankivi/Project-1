#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char muisti[4096];
    char c;
    int l = 1;
    int s = 0;
    FILE *tiedosto;
    if (argc == 1) {
   	 printf("my-zip: file1 [file2 ...]\n");
   	 exit(1);
    }
    for (int i = 1; i<argc; i++) {
   	 tiedosto = fopen(argv[1], "r");
   	 if (tiedosto == NULL) {
   		 printf("my-zip: cannot open file.\n");
   		 exit(1);
   	 }
   	 fread(&c, 1, sizeof(c), tiedosto);
   	 while((s = fread(muisti, 1, sizeof(muisti), tiedosto)) > 0) {
   		 for (int i=0; i<s;i++) {
   			 if (muisti[i] == c) {
   				 l++;
   				 continue;
   			 }
   			 else {
   				 fwrite(&l, sizeof(int), 1, stdout);  // kuinka monta samaa kirjainta
   				 fwrite(&c, sizeof(char), 1, stdout);  // mikä kirjain
   				 l = 1;
   			 }
   			 c = muisti[i];
   		 }
   	 
   	 }
   	 fclose(tiedosto);
    }
    return 0;
}
