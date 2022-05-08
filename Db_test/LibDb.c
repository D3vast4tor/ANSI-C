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
    char username[20],password[20]conf_passwrd[20];
    char choise;
    do{
        switch(choise){
            case 'a':
                printf("\nType the username: ");
                scanf(" %s",%username);
                printf("\nType the password: ");
                scanf(" %s",%password);
                printf("\nRetype the password: ");
                scanf(" %s",&conf_passwrd);
                if(password == conf_passwrd){
                    if(head == null){
                        head = __init__(head,username,password);
                    }else{
                        head = add_user(head,username,password);
                    }
                }
            break;
            case 'r':
            
            break;
            case 'q';

            break;
        }
    }while(choise != 'q')
    
    

    head = 
    
}