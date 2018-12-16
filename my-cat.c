int main(int argc, char *argv[]) {
    char muisti[256];
    FILE *tiedosto;
    for(int i=1; i<argc; i++) {
   	 tiedosto = fopen(argv[i], "r");
   	 if (tiedosto == NULL) {
   		 printf("my-cat: cannot open file.\n");
   		 exit(1);
   	 }
   	 while(fgets(muisti, sizeof(muisti), tiedosto) != NULL) {
   		 printf("%s",muisti); // Tulostus tiedoston rivi kerrallaan
   	 }
   	 fclose(tiedosto);
    }
    return 0;
}
