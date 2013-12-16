//
//  main.c
//  listConversingAccordingToWeb
//
//  Created by 孙培峰 on 1312/16/.
//  Copyright (c) 2013 孙培峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define ITEM_NUM 10
typedef struct tagNode {
    int e;
    struct tagNode *next;
}Node;

Node* LinkList_create();
void LinkList_destroy(Node* head);
void LinkList_print(Node* head);
Node* LinkList_reverse(Node* head);

int main(int argc,char* agrv[])
{
    Node* head = LinkList_create();
    Node* head_reversed;
    
    printf("The link list data is:\n");
    
    LinkList_print(head);
    
    head_reversed = LinkList_reverse(head);
    
    printf("After reversed,the link list data is:\n");
    
    LinkList_print(head_reversed);
    
//    system("Pause");
    
}

Node* LinkList_create()
{
    Node* nodes = (Node*)calloc(ITEM_NUM,sizeof(Node));
    
    int i;
    
    printf("Create link list...\n");
    for(i=0;i<ITEM_NUM;i++)
    {
        nodes[i].e = (i+1)*3;
        
        if(i< ITEM_NUM-1)
            nodes[i].next = &nodes[i+1];
        else
            nodes[i].next = NULL;
    }
    
    return nodes;
}

void LinkList_destroy(Node* head)
{
    printf("Destroy the link list...\n");
    if(head) free(head);
}

void LinkList_print(Node* head)
{
    if(head==NULL) return;
    
    while(head)
    {
        printf("%d\n",head->e);
        head = head->next;
    }
}

Node* LinkList_reverse(Node* head)
{
    Node *preNode,*curNode,*nextNode;
    
    if(head==NULL) return NULL;//空链表
    
    if(head->next == NULL) return head;//仅一个元素
    
    curNode = head;preNode=NULL;//初始化
    
    while(curNode)
    {
        nextNode = curNode->next;//先记录下一个结点
        curNode->next = preNode;//改变链表方向（逆置）
        preNode = curNode;//将当前结点作为下一次循环的前一个结点
        curNode = nextNode;//向后推移一个结点
    }
    
    return preNode;//当遍历完链表后curNode应该为空，此时preNode就是逆置后链表头(head)
    
}
//int main(int argc, const char * argv[])
//{
//
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}

