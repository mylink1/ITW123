/*
1. It would be better if poly. expre. is sorted(descending)in order of their exponent.
2. created as :
    struct node{
        float coeff;
        int expo;
        struct node* link;
    };
3. each node represents a term of the expression.

*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    float coeff;
        int expo;
        struct node* link;
};

//FUNCTION TO INSERT AND LINK THE NODES
struct node* insertNode(struct node* head,int co,int ex){
    struct node* temp;
    struct node *newP=malloc(sizeof(struct node));
    newP->coeff=co;
    newP->expo=ex;
    newP->link=NULL;

    if(head ==NULL||ex>head->expo){
        newP->link=head;
        head=newP;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->expo>ex)
            temp=temp->link;
        newP->link=temp->link;
        temp->link=newP;
    }
    return head;

}

//FUNCTION TO CREATE A NODE
struct node* createNode(struct node* head){
    int n;
    float coeff;
    int expo;
    printf("Enter the number of terms");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the coeff for term %d:",i+1);
        scanf("%f",&coeff);

        printf("Enter the exponent of the term %d: ",i+1);
        scanf("%d",&expo);
        head=insertNode(head,coeff,expo);
    }
    return head;
}
void print(struct node* head){
    if (head==NULL){
        printf("NO polynomial.");
    }
    else{
        struct node* temp=head;
        while (temp!=NULL)
        {
            printf("(%.1fx^%d)",temp->coeff,temp->expo);
            temp=temp->link;
            if(temp!=NULL){
                printf(" + ");
            }
            else{
                printf("\n");
            }
        }
        
    }
}
void polyMul(struct node*h1,struct node *h2){
    struct node* ptr1=h1;
    struct node* ptr2=h2;
    int res1,res2;
    struct node* h3=NULL;
    while(ptr1!=NULL){
        ptr2=h2;
        while (ptr2!=NULL)
        {
            res1=ptr1->coeff*ptr2->coeff;
            res2=ptr1->expo+ptr2->expo;
            h3=insertNode(h3,res1,res2);
            ptr2=ptr2->link;

        }
        ptr1=ptr1->link;
        
    }
    

    printf("multiplied Polynomial is: ");
    print(h3);
}


int main()
{
    struct node* head1=NULL;
    struct node* head2=NULL;
    printf("Enter the polynomial 1:   ");
    head1=createNode(head1);
    printf("polynomial 1 is : ");
    print(head1);
    printf("\n");
    printf("Enter the polynomial 2:   ");
    head2=createNode(head2);
    printf("polynomial 2 is : ");
    print(head2);
    printf("\n");
    polyMul(head1,head2);
    return 0;
}


