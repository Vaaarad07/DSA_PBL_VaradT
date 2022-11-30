#include "stdio.h"
#include "stdlib.h"
//#include "graph.c"
#include "linkedlistss.c"
#include "stackk.c"
#include "queuee.c"
#include "treee.c"

/*pizza store system where we store past orders in linked list,
                                    current orders in queue,
                                    menu card in trees,
                                    table status in graphs,
                                    total expenses in stacks.*/

/*typedef struct customer
{
    int id;
    int quantity;
    char name[20];
    char date[8];
    // char address[50];
} customer;*/

// DSA PBL

int main(){

    int option, trash, sale;
    int flag = 0;
    node *head = NULL;
    customer data1;
    BSTnode *root;
    stack *s;
    s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    //init(s);


    printf("Menu needs to be recorded once: \n");
    root = createTree();
    printf("\n\nPrinting menu: \n");
    inorder(root);
    
    do{
        printf("------------------------------------\n");
        printf("Select operation:\n1)Place order    |   2)Dispatch order\n3)print orders   |   4)Previous orders\n5)View menu      |   6)Total sale\n7)Quit  |  \n-> ");
        scanf("%d", &option);
        printf("------------------------------------\n");
        switch(option){
            case 1: printf("Printing menu to select dishes: \n");
                    inorder(root);
                    placeOrder();
                    break;
            case 2: data1 = dispatchOrder();
                    head = create(data1.id, data1.quantity, data1.name, data1.date, data1.price);
                    trash = push(s, data1.price);
                    break;
            case 3: printOrders();
                    break;
            case 4: print(head);
                    break;
            case 5: /*if(! flag){
                        //create menu
                        printf("Menu needs to be recorded once: \n");
                        root = createTree();
                        printf("Printing menu: \n");
                        inorder(root);
                        flag = 1;
                    }*/
                    //else if(flag){
                        printf("Printing menu: \n");
                        inorder(root);
                    //}
                    break;
            case 6: sale = popall(s);
                    printf("The total sale is:  %d\n", sale);
                    trash = push(s, sale);
                    break;
            //case 7:
                    break;
            case 7: printf("Counter closed!");
                    break;
        }
    }while(option != 7);

    printf("\n\n");
    return 0;
}
