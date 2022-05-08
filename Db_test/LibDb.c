#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1)Aggiungere o rimuovere utenti a scelta
2)Cicia scema



*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct User{
    char username[20];
    char password[20];
};
struct Node{
    struct User * data;
    struct Node * next;
};
struct Node * head = NULL;

struct Node * __init__(struct Node * head,char * username,char * password){
    head = malloc(sizeof(struct Node));
    strcpy(head->data->username,username);
    strcpy(head->data->password,password);
    head->next = NULL;
    return head;
    
}

struct Node * add_user(struct Node * head,char * username,char * password){
    struct Node * cur,new_node;
    new_node = malloc(sizeof(struct Node));
    strcpy(new_node->data->username,username);
    strcpy(new_node->data->password,password);
    new_node->next == NULL;
    for(cur = head;;cur = cur->next){
        if(cur->next == NULL){
            cur->next = new_node;
            break;
        }
    }
    return head;
}

struct Node * rm_user(struct Node * head,char * username){
    struct Node * prec,cur,succ;
    for(cur = head;;cur = cur->next){
        if(cur->data->username != username){
            prec = cur;
        }else if(cur->data->username == username){
            succ = cur->next;
            prec->next = succ;
            cur = NULL;
            break;
        }
    }
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