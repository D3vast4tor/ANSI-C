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
    struct Node *cur,*new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *prec,*cur,*succ;
    for(cur = head;;cur = cur->next){
        if(cur->data->username != username){
            prec = cur;
        }else if(cur->data->username == username){
            succ = cur->next;
            prec->next = succ;
            break;
        }
    }
    return head;
}
void list_user(void){
    struct Node * cur;
    int i = 0;
    for(cur = head;cur->next != NULL;cur = cur->next){
        printf("\nUser n°%d\nUsername: %s",++i,cur->data->username);

    }
}
int main(){
    char username[20],password[20],conf_passwrd[20];
    char choise;
    do{
        printf("\n*************\nADMIN PANEL\n*************\na)Add user.\nr)Remove user.\nl)List Database.\nq)Quit.\nType your choise: ");
        scanf(" %c",&choise);
        switch(choise){
            case 'a':
                printf("\nType the username: ");
                scanf(" %s",&username);
                printf("\nType the password: ");
                scanf(" %s",&password);
                printf("\nRetype the password: ");
                scanf(" %s",&conf_passwrd);
                if(strcpm(password,conf_passwrd) == 0){
                    if(head == NULL){
                        head = __init__(head,username,password);
                    }else{
                        head = add_user(head,username,password);
                    }
                }
            break;
            case 'r':
            
            break;
            case 'l':
                list_user();
            case 'q':

            break;
        }
    }while(choise != 'q');
}