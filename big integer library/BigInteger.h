#ifndef BigInteger_h
#define BigInteger_h

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct BigIntegerInteger {
    struct node *head;
}BigInteger;

int length(node *head);
void create(node **head,int x);
void reverse(node **head);
void display(BigInteger p);
node *sub_result(node *temp1, node *temp2);
BigInteger sub(BigInteger a, BigInteger b);
struct node *add_result(node *temp1,node *temp2);
struct BigIntegerInteger add(BigInteger a,BigInteger b);
struct BigIntegerInteger initialize(char *str);
#endif;