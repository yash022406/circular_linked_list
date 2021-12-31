// circular linked list program 

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node * next;
};
struct node * head = NULL;
struct node * temp = NULL;
void add_data(){
    int i;
    
    printf("Enter the number of elements to add: ");
    scanf("%d",&i);
    while(i--){
        int data;
        
        printf("Enter the data: ");
        scanf("%d",&data);
        
        if(head == NULL){
            head=(struct node *)malloc(sizeof(struct node));
            temp=(struct node *)malloc(sizeof(struct node));

            head -> data = data;
            head -> next = head;
            temp = head;

        }
        else{
            struct node * new = (struct node *)malloc(sizeof(struct node));

            new->data = data;
            new->next=head;
            temp->next = new;
            temp = new;

        }
        

    }
    temp -> next = head;
}
void display(){

    // displaying the circular linked list
    struct node * yo = head;

    do{
        printf("%d\t",yo->data);
        yo=yo->next;
    }while(yo!=head);
}
void delete(){
    struct node * tem = (struct node *)malloc(sizeof(struct node));
    struct node * temp1 = head;
    struct node * temp2 = (struct node *)malloc(sizeof(struct node));
    int d;
    printf("Enter the data to be deleted: ");
    scanf("%d",&d);
    while(tem->data!=d){
        tem=temp1;
        temp1=temp1->next;
    }
    temp2=temp1->next;
    tem->next=temp2;
    free(temp1);

}

int main(){


    int n;
    while(n!=4){
        printf("1. Add data\n2. Display data\n3. Delete\n4. Exit\n");
        scanf("%d",&n);
        if(n==1){

            // adding data 
            int d;
            add_data();

        }
        else if (n==2){
            display();
        }
        else if(n==3){
            delete();
        }
    }


}