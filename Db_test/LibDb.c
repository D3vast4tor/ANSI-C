#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1)Aggiungere o rimuovere utenti a scelta
2)Cicia scema



*/

struct User{
    char username[20];
    char password[20];
    int count;
};
struct Node{
    struct Student * data;
    struct Node * next;
};
struct Node * head = NULL;
struct Node * __init__(struct Node * head,char * name,char * surname,int idd){
    head = malloc(sizeof(struct Node));
    strcpy(head->data->name,name);
    strcpy(head->data->surname,surname);
    head->data->id = idd;
    head->next = NULL;
    return head;
    
}
int main(){
    char name[20],surname[20];
    printf("\nInserire il nome: ");
    scanf(" %s",&name);
    printf("\nInserire il cognome: ");
    scanf(" %s",&surname);
    int id = 123123;
    head = __init__(head,name,surname,id);
    printf("Name: %s\nSurname: %s\nID: %d\n",head->data->name,head->data->surname,head->data->id);
    
}