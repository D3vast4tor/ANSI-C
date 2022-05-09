#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char username[20];
    char password[20];
    struct Node * next;
};
struct Node * head = NULL;

void add_user(const char * user,const char * pass){
    struct Node  *prev,*cur,*new_node;
    new_node = malloc(sizeof(struct Node));
    strcpy(new_node->username,user);
    strcpy(new_node->password,pass);
    new_node->next = NULL;
    for(cur = head,prev = NULL;cur != NULL;prev = cur,cur = cur->next);
        if(prev == NULL){
            head = new_node;
        }else{
            prev->next = new_node;
            new_node->next = NULL;
        }
}
void list_user(void){
    struct Node * p;
    for(p = head;p != NULL;p = p->next){
        printf("\nUsername: %s\nPassword: %s\n--------------------",p->username,p->password);
    }
}

void rm_user(const char * user){
    struct Node *p,*c,*s;
    for(c = head,p = NULL,s = c->next;c != NULL;p = c,c = c->next,s = c->next){
        if(strcmp(c->username,user) == 0){
            if(p == NULL){
                head = s;
                c = NULL;
                break;
            }else{
            p->next = s;
            c = NULL;
            break;
            }
        }
    }
}

int main(){
    char username[20],password[20];
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
                    add_user(username,password); 
            break;
            case 'r':
                printf("\nType the username of the user to remove: ");
                scanf(" %s",&username);
                rm_user(username);
            break;
            case 'l':
                list_user();
            break;
            case 'q':
            break;
        }   
    }while(choise != 'q');
}

