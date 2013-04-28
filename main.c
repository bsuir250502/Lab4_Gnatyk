#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#define N 150
#define input_buf_size 80
#define SIZE( x ) (sizeof( x )/sizeof( *x ))
    struct tree{
        char* data;
        struct tree * left;
        struct tree * ringht;
        int n;
    };

    void clear_screen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    char*gets_s(char *s, size_t buf_size)
    {
        char *result;
        result = fgets(s, buf_size, stdin);
        result[strlen(s) - 1] = '\0';
        return result;
    }

    tree* create_a_tree( struct tree* tree)
    {
        int size_data = SIZE(tree->data);
        if(tree){
            return(tree);
        }
        if(!(tree = (struct tree *)calloc(1,sizeof(struct tree)))){
            puts("There is no free memory");
            return NULL;
        }
        puts("enter the information");
        tree->data = (char*)calloc(1,sizeof(char)*N);
        gets_s(tree->data,size_data);
        tree->n = 1;
        return tree;
    }

    void add_nodes_to_the_tree(struct tree* tree)
    {
        struct tree *tr1, *tr2;
        char * st;
        int k;
        int flag;
        int st_size = SIZE(st);
        if(!tree){
            puts("Нет корня дерева\n");
            return;
        }
        do{
            puts("enter the informationfor the end of write- ex");
            st = (char*)calloc(1,sizeof(char)*N);
            gets_s(st,st_size);
            if(!strcmp(st,"ex")){
                return;
            }
            if(!*st)return;
            tr1 = tree;
            flag = 0;
            do{
                if(!(k = strcmp(st,tr1->data))){
                    tr1->n++;
                    flag = 1;
                }
                else{
                    if(k < 0){
                        if(tr1->left){
                            tr1 = tr1->left;
                        }
                        else flag = 1;
                    }
                    else{
                        if(tr1->ringht){
                            tr1= tr1->ringht;
                        }
                        else flag = 1;
                    }
                }
            }
            while( flag == 0);
            if(k)
            {
                if(!(tr2 = (struct tree *)calloc(1,sizeof(struct tree)))){
                    puts("There is no free memory\n");
                    return;
                }
                if(k < 0){
                    tr1->left = tr2;
                }
                else{
                    tr1->ringht = tr2;
                }
                tr2->data = (char*)calloc(1,sizeof(char)*N);
                strcpy(tr2->data,st);
                tr2->n = 1;
            }
            free(st);
        }while(1);
    }

    void checkHelp(void)
    {
        printf
            ("=============================================================================================================\n"
            "MANUAL:\n"
            "Enter information about the students: last name, \n"
            "=================================OPTIONS=====================================================================\n"
            "1. add a node in the tree\n"
            "2. If you want to move out of the hostel\n"
            "3. If you want to view a list of students living in a hostel\n"
            "4. Help\n"
            "5. Exit\n"
            "=============================================================================================================\n");
        exit(0);

    }

    int menu_select()
    {
        char s[input_buf_size];
        int c;
        puts("1. add information");
        puts("2. delete information ");
        puts("3. see details");
        puts("4. Help"); 
        puts("5. to exit");
        do{
            printf("\nEnter the number of the desired item\n");
            gets_s(s, input_buf_size);
            c = atoi(s);
        }
        while (c < 0 || c > 5);
        clear_screen();
        return c;
    }

    void see_tree (struct tree * tr1)
    {
        if(tr1){
            printf("node contains a: %s,number of meetings%d\n",tr1->data,tr1->n);
            if(tr1->left) see_tree(tr1->left);
            if(tr1->ringht) see_tree(tr1->ringht);
        }
    }

    int main()
    {
        struct tree* tree = NULL ;
        tree = create_a_tree(tree);
        char choice;
        while(1){
            choice = menu_select();
            switch (choice){
            case 1 : 
                add_nodes_to_the_tree( tree);
                break;
            case 2 : 
                see_tree(tree);break;
            case 3 :
                checkHelp();break;
            case 4 :
                exit(0);break;
            }
        }
    }


#ifdef __cplusplus
}
#endif
