#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct BigInteger {
    struct node *head;
}BigInteger;

int length(node *head){
    node*temp=head;
    int l=1;
    while(temp->next!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

void create(node **head,int x){
    node *temp=*head;
    node *newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=x;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}

void reverse(node **head)
{
    node *temp=*head;
    if (*head == NULL ||(*head)->next == NULL)
        return;
    node *prevnode = NULL;
    node *nextnode = NULL;
    node *currnode = *head;
    while (currnode!=NULL)
    {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    *head = prevnode;
}

void display(BigInteger p){
    node *temp=p.head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

node *sub_result(node *temp1, node *temp2)
{
    node *head1 = NULL;
    node *tempA = temp1;
    node *tempB = temp2;
    while(tempA != 0 && tempB != 0)
    {
        if(tempA->data >= tempB->data)
            create(&head1, (tempA->data - tempB->data));
        else
        {
            create(&head1, (tempA->data + 10) - tempB->data);
            --tempA->next->data;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    while(tempA != 0)
    {
        create(&head1, tempA->data);
        tempA = tempA->next;
    }
    reverse(&head1);
    return head1;
}

BigInteger sub(BigInteger a, BigInteger b){
    BigInteger res;
    res.head=sub_result(a.head,b.head);
    return res;
}

struct node *add_result(node *temp1,node *temp2){
    node *head1=NULL;
    int carry=0,ans,sum,l1,l2,i=1;
    node *ptr=temp1,*itr=temp2;
    l1=length(ptr);
    l2=length(itr);
    if(l1>l2){
        int x=l1-l2;
        while(i<=x){
            create(&itr,0);
            i++;
        }
    }
    int c=1;
    if(l2>l1){
        int x=l2-l1;
        while(c<=x){
            create(&ptr,0);
            c++;
        }
    }
    while(temp1!=NULL&&temp2!=NULL){
        sum=temp1->data+temp2->data+carry;
        carry=sum/10;
        ans=sum%10;
        create(&head1,ans);
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(carry!=0){
        create(&head1,carry);
    }
    reverse(&head1);
    return head1;
}
struct BigInteger add(BigInteger a,BigInteger b){
    BigInteger res;
    res.head=add_result(a.head,b.head);
    return res;
}

BigInteger mul(BigInteger a, BigInteger b)
{
    BigInteger MulAns ;
    MulAns.head = 0;
    struct node *headMain = 0;
    struct node *tempA = a.head;
    struct node *tempB = b.head;
    int iter = 1;
    while(tempB != 0)
    {
        struct node *headNew = 0;
        tempA = a.head;
        while(tempA != 0)
        {
            create(&headNew, (tempA->data*tempB->data));
            tempA = tempA->next;
        }
        if(iter > 1)
        {
            int x = 1;
            while(x < iter)
            {
                struct node* new = (struct node*)malloc(sizeof(struct node));
                new->data = 0;
                new->next = headNew;
                headNew = new;
                x++;
            }
        }
        BigInteger NewAns;
        NewAns.head = headNew;
        MulAns = add(MulAns, NewAns);
        reverse(&MulAns.head);
        tempB = tempB->next;
        iter++;
    }
    reverse(&MulAns.head);
    return MulAns;
}

struct BigInteger initialize(char *str){
    BigInteger p;
    p.head=NULL;
    node *temp=NULL;
    for(int i=0;str[i]!='\0';i++){
        int x=(int)(str[i]-48);
        node *newnode=(node*)malloc(sizeof(node));
        newnode->next=NULL;
        newnode->data=x;
        if(temp==NULL){
            p.head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    reverse(&p.head);
    return p;
}
