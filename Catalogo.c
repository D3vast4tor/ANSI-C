#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Oggetti{
    char name[20];
    char category[20];
    char prezzo[20];
}Oggetti;
int Add_items(){
    char c;
    do{
        FILE *file_handler = fopen("./Oggetti.txt","w");
        if(file_handler==NULL){
            printf("Errore durante l'apertura del file.\nIl programma sarà arrestato.");
            exit(1);
        }
        int n_items,i;
        printf("\nInserire quanti oggetti si vuole aggiungere: ");
        scanf(" %d",&n_items);
        do{
            struct Oggetti *ogg=(struct Oggetti*)malloc(sizeof(struct Oggetti));
            printf("Inserire il nome dell'oggetto: ");
            scanf(" %s",&ogg->name);
            printf("\nInserire la categoria dell'oggetto: ");
            scanf(" %s",&ogg->category);
            printf("\nInserire il prezzo dell'oggetto: ");
            scanf(" %s",&ogg->prezzo);
            fwrite(ogg,sizeof(struct Oggetti),1,file_handler);
            free(ogg);
            i++;
        }while(i == n_items);
        fclose(file_handler);
        printf("\nSi desidera continuare?(y/n): ");
        scanf(" %c",&c);
    }while(c != 'n');
    return 0;
}
int List_Items(){
    FILE *file_handler = fopen("./Oggetti.txt","r");
    float k=1;
    struct Oggetti *ogg = (struct Oggetti*)malloc(sizeof(struct Oggetti));
    while(fscanf(file_handler,"%s%s%s%s\n",ogg,ogg->name,ogg->category,ogg->prezzo) != EOF){k++;}
    printf("Sono stati trovati %.0f oggetti in catalogo.\n",&k);
    printf("##\nNome: %s\nCategoria: %s\nPrezzo: %s\n##",&ogg->name,&ogg->category,&ogg->prezzo);
    return 0;
}
int main(){
    char scelta='o';
    do{
        printf("Inserire l'operazione da eseguire:\n1)Aggiungere oggetti.(a)\n2)Esaminare gli oggetti in catalogo.(e)\n)Uscire.(q)\n-");
        scanf(" %c",&scelta);
            switch(scelta){
                case 'a':
                    Add_items();
                if(Add_items()==0){
                    printf("Il salvataggio è avvenuto con successo.\n");
                }
            break;
            case 'e':
                List_Items();
                if(List_Items() == 0){
                    printf("\n**Operazione eseguita con successo.**\n");
                }
            break;
            }
        }while(scelta != 'q');
}