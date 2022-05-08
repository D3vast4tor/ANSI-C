#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1)Aggiungere o rimuovere utenti a scelta
2)Cicia scema



*/

struct student{
    char name[20];
    char surname[20];
    int id;
};
struct node{
    struct student * data;
    struct node * next;
};
struct node * head = NULL;
struct node * __init__(struct node * head,char * name,char * surname,int idd){
    head = malloc(sizeof(struct node));
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