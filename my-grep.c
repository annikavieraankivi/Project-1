#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char muisti[256];
    FILE *tiedosto;
    if (argc <= 1) {
   	 printf("my-grep: searchterm [file ...]\n");
   	 exit(1);
    }
    else if (argc >= 3) { // Ohjelmalle annetaan avainsana sekä tiedosto
   	 for(int i=2; i<argc; i++) {
   		 tiedosto = fopen(argv[i], "r");
   		 if (tiedosto == NULL) {
   			 printf("my-grep: cannot open file.\n");
   			 exit(1);
   		 }
   		 while(fgets(muisti, sizeof(muisti), tiedosto) != NULL) {
   			 if ((strstr(muisti,argv[1]) != NULL)) { 
   				 printf("%s",muisti); // Tulostetaan rivi, jossa avainsana
   			 }    
   		 }
   		 fclose(tiedosto);
   	 }
    }
    else if (argc == 2) { // Ohjelmalle annetaan pelkkä avainsana
   	 while (1) {
   		 fgets(muisti, sizeof(muisti), stdin);
   		 if ((strstr(muisti,argv[1]) != NULL)) {
   			 printf("%s",muisti);
   		 }
   	 }
    }
    return 0;
}
