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
    struct Node  *p,*c,*n;
    n = malloc(sizeof(struct Node));
    strcpy(n->username,user);
    strcpy(n->password,pass);
    n->next = NULL;
    for(c = head,p = NULL;c != NULL;p = c,c = c->next);
        if(p == NULL){
            head = n;
        }else{
            p->next = n;
            n->next = NULL;
        }
}
void list_user(void){
    struct Node * p;
    int i = 1;
    for(p = head;p != NULL;p = p->next,i++){
        printf("\nUser n %d\nUsername: %s\nPassword: %s\n--------------------",i,p->username,p->password);
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

void save_db(void){
    FILE * file_handler = fopen("Db.txt","w");
    struct Node * c;
    int count = 1;
    for(c = head;c != NULL;c = c->next,count++){
        fprintf(file_handler,
        "User n %d\nUsername: %s\nPassword: %s\n\n",
        count,c->username,c->password);
    }
    fclose(file_handler);
}
/*
 *BROKEN FUNCTION.
 *ENDLESS LOOP.
void import_db(void){
    FILE * file_handler = fopen("Db.txt","r");
    struct Node *c,*n;
    int count;
    head = malloc(sizeof(struct Node));
    while(!feof(file_handler)){
        for(c = head;c != NULL;c = c->next){
            n = malloc(sizeof(struct Node));
            fscanf(file_handler,"Username: %s",c->username);
            fscanf(file_handler,"Password: %s",c->password);
            if(feof(file_handler) == 0){
                c->next = n;
            }else{
                c->next = NULL;
                break;
            }
        }

    }
}
*/

void main(void){
    char username[20],password[20];
    char choise;
    if(head == NULL){
        printf("\n*************************\n*\tP(ower)UserDB\t*\n*************************\n");
        //printf("\nFirst Run detected...searching for database...");
        //import_db();
    }
    do{
        printf("a)Add user.\nr)Remove user.\nl)List Database.\ns)Save database on file.\nq)Quit.\nType your choise: ");
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
            case 's':
                save_db();
            break;
            case 'q':
            break;
        }   
    }while(choise != 'q');
}

