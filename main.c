//  main.c
//  CSI 333
//  Spring 2019
//  Project3
//  ZR1702
//  2017215126
//  Qin Weiwei
//
//  Created by 秦玮蔚 on 2019/4/19.
//  Copyright © 2019 Qin Weiwei. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 4
#define NUM 255

/*
 Creat a linked list.
 */
struct node{
    int index;
    char member[255];
    struct node *next;
};
int size = 0;
struct node *head = NULL;

/*
 Command Insert After.
 */
int ina(int num,char str[]){
    if(size == 0){
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p -> index = 1;
        strcpy(p -> member,str);
        p -> next = head;
        head = p;
        size ++;
        
        printf("Text inserted at the end.\n");fflush(stdout);
        return 0;
    }
    
    if(ifexists(str) == 1){
        printf("Such text exists already.\n");fflush(stdout);
        return 0;
    }
    
    else if(num > size){
        struct node *p = head;
        int i = 1;
        while (i != size){
            p = p -> next;
            i ++;
        }
        struct node *a = (struct node *)malloc(sizeof(struct node));
        a -> index = size + 1;
        strcpy(a -> member,str);
        p -> next = a;
        size ++;
        
        printf("Text inserted at the end.\n");fflush(stdout);
    }
    
    else{
        struct node *p = head;
        struct node *pnext = p -> next;
        struct node *a = (struct node *)malloc(sizeof(struct node));
        int i = 1;
        a -> index = num + 1;
        strcpy(a -> member,str);
        
        while(i < num){
            p = p -> next;
            i ++;
        }
        p -> next = a;
        a -> next = pnext;
        size ++;
        
        order();
        
        printf("ok\n");fflush(stdout);
    }
    return 0;
}

/*
 Command Insert Before.
 */
int inb(int num,char str[]){
    if(size == 0){
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p -> index = 1;
        strcpy(p -> member,str);
        p -> next = head;
        head = p;
        size ++;
        
        printf("Text inserted at the beginning.\n");fflush(stdout);
        return 0;
    }
    
    if(ifexists(str) == 1){
        printf("Such text exists already.\n");fflush(stdout);
        return 0;
    }
    
    else if(num > size){
        struct node *a = (struct node *)malloc(sizeof(struct node));
        a -> index = 1;
        strcpy(a -> member,str);
        a -> next = head;
        head = a;
        size ++;
        
        order();
        
        printf("Text inserted at the beginning.\n");fflush(stdout);
    }
    
    else{
        struct node *p = head;
        struct node *pnext = p -> next;
        struct node *a = (struct node *)malloc(sizeof(struct node));
        int i = 1;
        a -> index = num - 1;
        strcpy(a -> member,str);
        
        while(i < num - 1){
            p = p -> next;
            i ++;
        }
        p -> next = a;
        a -> next = pnext;
        size ++;
        
        order();
        
        printf("ok\n");fflush(stdout);
    }
    return 0;
}

/*
 Command Delete.
 */
int del(int num){
    int i = 1;
    if(num > size){
        printf("No such index.\n");fflush(stdout);
        return 0;
    }
    
    else{
        struct node *p = head;
        while(i < num - 1){
            p = p -> next;
            i ++;
        }
        if(p -> next -> next != NULL){
            struct node *a = p -> next -> next;
            p -> next = a;
        }
        p -> next = NULL;
        size --;
        
        order();
        
        printf("Deleted.\n");fflush(stdout);
    }
    return 0;
}

/*
 Command Replace.
 */
int rep(int num,char str[]){
    if(num > size){
        printf("No such index.\n");fflush(stdout);
        return 0;
    }
    
    else{
        int i = 1;
        struct node *p = head;
        while(i < num){
            p = p -> next;
            i ++;
        }
        strcpy(p -> member,str);
        printf("Replaced.\n");fflush(stdout);
    }
    return 0;
}

/*
 Print List Command.
 */
int prn(){
    if(size == 0){
        printf("The list is empty.\n");fflush(stdout);
    }
    int i = 0;
    struct node *p = head;
    while(i != size){
        printf("%d %s\n",p -> index,p -> member);fflush(stdout);
        p = p -> next;
        i ++;
    }
    return 0;
}

/*
 End Command.
 */
int end(){
    exit(0);
    return 0;
}

/*
 Check if the text exists already.
 */
int ifexists(char str[]){
    struct node *p = head;
    int i = 0;
    while(i != size){
        if(strcmp(str,p -> member) == 0){
            return 1;
        }
        p = p -> next;
        i ++;
    }
    return 0;
}

/*
 Indexes of the list should be changed to keep increasing order.
 */
int order(){
    int i = 1;
    struct node *p = head;
    while(i != size + 1){
        p -> index = i;
        i ++;
        p = p -> next;
    }
    return 0;
}

int main(int argc,const char *argv[]){
    //Loop while 1,when it is 0,end the loop.
    while(1){
    char input[NUM];
    char com[MAX];
    int num;
    char str[NUM];
    
    printf("Command? ");fflush(stdout);
    fgets(input,NUM,stdin);
    sscanf(input,"%s %d %s",com,&num,str);
    
    //Call command ina
    if(strcmp(com,"ina") == 0){
        ina(num,str);
    }
    
    //Call command inb
    else if(strcmp(com,"inb") == 0){
        inb(num,str);
    }
    
    //Call command del
    else if(strcmp(com,"del") == 0){
        del(num);
    }
    
    //Call command rep
    else if(strcmp(com,"rep") == 0){
        rep(num,str);
    }
    
    //Call command prn
    else if(strcmp(com,"prn") == 0){
        prn();
    }
    
    //Call command end
    else if(strcmp(com,"end") == 0){
        end();
    }
    }
    return 0;
}






/*
pNode creatList(){
    int i;
    int len;
    int val;
    pNode head = (pNode)malloc(sizeof(Node));
    pNode tail = head;
    tail -> next = NULL;
    
    
}

void intoarray(char *input,char array[MAX]){
    char *c;
    int i = 0;
    while(input != ' '){
        if(input == '\0'){
            return;
        }
        input ++;
    }
    c = input + 1;
    while(*c == ' '){
        c ++;
    }
    while(*c != '\0'){
        if(*c != ' '){
            array[i] = *c;
            *c = ' ';
            i ++;
        }
        c ++;
    }
    array[MAX] = '\0';
    return;
}

void printList(pNode head){
    pNode p = head -> next;
    while(p != NULL){
        printf("%d",p -> member);
        p = p -> next;
        printf("\n");
    }
}

int main(){
    pNode head = NULL;
    //head = creatList();
    
    char array[MAX];
    char input[MAX];
    char com;
    
    int i = 0;
    
    printf("Command?");
    scanf("%s",&input);
    intoarray(input[MAX],&array[MAX]);
    
    for(int i = 0;i < 0;i ++){
        printf(array[i]);
    }
    
    
    return 0;
}
*/

/*
 //
 //  main.c
 //  CSI 333
 //  Spring 2019
 //  Project3
 //  ZR1702
 //  2017215126
 //  Qin Weiwei
 //
 //  Created by 秦玮蔚 on 2019/4/19.
 //  Copyright © 2019 Qin Weiwei. All rights reserved.
 //
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <sys/malloc.h>
 
 #define MAX 255
 
 typedef struct node
 {
 int member;
 struct node *pNext;
 }Node,*pNode;
 
 pNode CreateList();
 void TraverseList(pNode );
 bool Insert_Node(pNode ,int ,int);
 int Del_Node(pNode,int );
 
 int main()
 {
 pNode pHead = NULL;                //  定义初始化头节点，等价于 struct Node *pHead == NULL
 int data;                        // 作为Insert_Node函数的第三个参数
 int num;                        //    作为Inset_Node函数第二个参数
 int value;
 int len;
 char choose[] = "";
 //char temp[] = "";
 
 pHead = CreateList();            //  创建一个非循环单链表，并将该链表的头结点的地址付给pHead
 
 //printf("你输入的数据是：");
 
 
 
 //printf("是否还要进行如下操作：\n");
 //printf("1.插入数据      2.删除数据\n");
 //printf("请输入：");
 /*
 scanf("%s",&choose);
 len = strlen(choose);
 while(len >= 0){
 for(int i = 0;i < len;i ++){
 temp[i] = gets(choose);
 }
 choose = temp[0];
 }
 
scanf("%s",choose[0]);
while(choose[0] != '\n'){
    scanf("%s",choose[1]);
    while(choose[1] != '\n'){
        scanf("%s",choose[2]);
    }
}

TraverseList(pHead);

char ina[] = "ina";
char inb[] = "inb";
char del[] = "del";
char rep[] = "rep";
char prn[] = "prn";
char end[] = "end";

if(choose == "ina"){
    num = 1;
}

if(strcmp(choose,inb) == 0){
    num = 2;
}

if(strcmp(choose,del) == 0){
    num = 3;
}

switch (num)
{
    case 1:
    {
         printf("node：");
         scanf("%d",&num);
        printf("insert");
        scanf("%d",&data);
        if(Insert_Node(pHead,num,data) == TRUE)
        {
            printf("after insert：\n");
            TraverseList(pHead);
        }
        else
        {
            printf("False.\n");
        }
        printf("after insert：");
        TraverseList(pHead);
        break;
    }
    case 2:
    {
        printf("delete：");
        scanf("%d",&num);
        value = Del_Node(pHead,num);
        if (value == 0)
        {
            printf("false\n");
        }
        else
        {
            printf("success：%d\n",value);
        }
        printf("after：");
        TraverseList(pHead);
    }
}
return 0;
}

pNode CreateList()
{
     int i;
     int len;
     int val;
    int len;
    
    pNode pHead = (pNode)malloc(sizeof(Node));
    pNode pTail = pHead;
    pTail -> pNext = NULL;
    
    char com[] = "";
    char ok[] = "ok";
    
    printf("Command? \n");
    scanf("%s",com);
    while(strcmp(com,ok) != 0){
        printf("Command? \n");
        scanf("%s",com);
        len ++;
    }
    //scanf("%d",&len);
    
     for(i = 0; i < len; i++)
     {
     printf("：",i+1);
     scanf("%d",&val);
     pNode pNew = (pNode)malloc(sizeof(Node));
     pNew -> member = val;
     pTail -> pNext = pNew;
     pNew -> pNext = NULL;
     pTail = pNew;
     }
    return pHead;
    
}

void TraverseList(pNode pHead)
{
    pNode p = pHead->pNext;
    while(NULL != p)
    {
        printf("%d ",p -> member);
        p = p -> pNext;
    }
    printf("\n");
    return ;
}


bool Insert_Node(pNode pHead, int front,int data)
{
    int i = 0;
    pNode _node = pHead;
    pNode pSwap;
    if ((front < 1) && (NULL != _node))
    {
        return false;
    }
    while (i < front - 1)
    {
        _node = _node -> pNext;
        ++i;
    }
    pNode pNew = (pNode)malloc(sizeof(Node));
    //    把输入的数据赋给要插入的节点
    pSwap = _node -> pNext;
    _node -> pNext = pNew;
    pNew -> pNext = pSwap;
    return true;
    
}


int Del_Node(pNode pHead,int back)
{
    int i = 0;
    int data;
    pNode _node = pHead;
    pNode pSwap;
    if ((back < 1) && (NULL == _node -> pNext))
    {
        printf("false！\n");
        return 0;
    }
    while(i < back-1)
    {
        _node = _node -> pNext;
        ++i;
    }
    pSwap = _node -> pNext;
    data = pSwap -> member;
    _node -> pNext = _node -> pNext -> pNext;
    free(pSwap);
    return data;
    
}


/*
 #include <stdio.h>
 
 typedef struct linklist{
 int command;
 struct linklist *next;
 } LinkList;
 
 LinkList *creat(int n){
 LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
 head = (LinkList*)malloc(sizeof(LinkList));//分配地址
 end = head;         //若是空链表则头尾节点一样
 for (int i = 0; i < n; i++) {
 node = (LinkList*)malloc(sizeof(LinkList));
 scanf("%d", &node -> command);
 end -> next = node;
 end = node;
 }
 end -> next = NULL;//结束创建
 return head;
 }
 
 void change(LinkList *list,int n) {//n为第n个节点
 LinkList *t = list;
 int i = 0;
 while (i < n && t != NULL) {
 t = t -> next;
 i++;
 }
 if (t != NULL) {
 puts("Enter the value you want to change : ");
 scanf("%d", &t -> command);
 }
 else {
 puts("节点不存在");
 }
 }
 
 void delet(LinkList *list, int n) {
 LinkList *t = list, *in;
 int i = 0;
 while (i < n && t != NULL) {
 in = t;
 t = t -> next;
 i++;
 }
 if (t != NULL) {
 in -> next = t -> next;
 free(t);
 }
 else {
 puts("节点不存在");
 }
 }
 
 void insert(LinkList *list, int n) {
 LinkList *t = list, *in;
 int i = 0;
 while (i < n && t != NULL) {
 t = t -> next;
 i++;
 }
 if (t != NULL) {
 in = (LinkList*)malloc(sizeof(LinkList));
 puts("输入要插入的值");
 scanf("%d", &in -> command);
 in -> next = t -> next;//填充in节点的指针域，也就是说把in的指针域指向t的下一个节点
 t -> next = in;//填充t节点的指针域，把t的指针域重新指向in
 }
 else {
 puts("节点不存在");
 }
 }
 
 
 void main(){
 char com = NULL;
 
 printf("Command?");
 scanf(com);
 
 
 while (h -> next != NULL) {
 h = h -> next;
 printf("%d  ", h -> command);
 }
 }
 
 */
