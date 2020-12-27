#include <stdio.h>													/*��Ҫ�õ���ͷ�ļ�*/
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <malloc.h>
/*****************************************************************************
File name:   binary_sort_tree.cpp
Description: ����һ���ɶ��ֻ�ױƷƷ�Ƽ۸���ɵĶ���������,
             �����ռ۸�ӵ͵��ߵ�˳���ӡ����� 
Author:      19060141�� ��ʮ���Ա 
Version:     1.0
Date:        2020/12/16
*****************************************************************************/
#define MAXSIZE 100
/*������ױƷ��Ϣ�Ľṹ��*/
typedef struct {
	char brand[MAXSIZE];											/*��ױƷƷ������*/
	int price;														/*��ױƷƷ�Ƽ۸�*/
}nodeData;
/*�����������������Ľ��ṹ*/
typedef struct node {
	nodeData data;													/*�����������Ľ����Ϣ*/
	struct node* lchild, * rchild;									/*���Һ���ָ��*/
}bnode,*bsnode;
/*��������*/
void Menu();														//��ʾ���˵�
void InsertBst(bsnode *t,int key,char *brand);						//�����������Ĳ���
void CreatBstree(bsnode *t);										//�����������Ľ���
void InOrderSearch(bsnode t,char ch[MAXSIZE]);						//�����������
void Search(bsnode t);												//�����Ʋ��һ�ױƷ��Ϣ 
void FindX(bsnode t, int x);										//�Լ۸�Ϊ�������һ�ױƷ����Ϣ
void InOrder(bsnode t);												//����������������������
int CountNode(bsnode t);											//ͳ�ƶ����������Ľ�����
int CountTreeDeep(bsnode t);										//ͳ�ƶ�������������� 
void Exit();														//�˳�����ĺ��� 
/*���˵�����*/
void Menu(){
	printf("\t\t ***************************************************** \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *           ��ӭʹ��YES I CAN��ױƷ����ϵͳ         * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t ***************************************************** \n"); 
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             1.������ױƷ��Ϣ����������.           * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             2.�����Ʋ��һ�ױƷ��Ϣ.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             3.�Լ۸���һ�ױƷ��Ϣ.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             4.����������.                       * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             5.ͳ�ƶ����������н�����.           * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             6.ͳ�ƶ��������������.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             7.�˳���ױƷ����ϵͳ.                 * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t ***************************************************** \n");
}
/*�����������Ĳ����㷨(�ݹ鷽��)*/
void InsertBst(bsnode *t, int key,char *brand) {
	if ((*t) == NULL) {												//����Ϊ��ʱ 
		(*t) = (bsnode)malloc(sizeof(bnode));						//�����½�� 
		strcpy((*t)->data.brand,brand);								//��brand�ַ������Ƶ��ṹ���е�brand 
		(*t)->data.price = key;										//���ṹ���еļ۸�ֵ���β�key 
		(*t)->lchild = (*t)->rchild = NULL;							//�����Һ��ӳ�ʼ��ΪNULL 
	}else if (key < (*t)->data.price) {								/*��ǰkeyС�ڽṹ���е�price
	                                              					  �ݹ鷽�����뵽��������*/  
		InsertBst(&(*t)->lchild, key,brand);
	}else {
		InsertBst(&(*t)->rchild, key,brand);						//�ݹ鷽�����뵽�������� 
	}
}
/*�����������Ľ����㷨*/
void CreatBstree(bsnode *t) {
	int num;														//��ױƷ�ܸ����ı��� 
	int x;															//��ױƷ�۸�ı��� 
	char brand[MAXSIZE];
	printf("�������뻯ױƷ���ܸ���:\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		printf("�������%d����ױƷ������:\n",i);
		scanf("%s",&brand);
		printf("�������%d����ױƷ�ļ۸�:\n",i);
		scanf("%d", &x);
		InsertBst(t, x,brand);
	}
}
/*�����������������,�����������һ�ױƷ��Ϣ*/
void InOrderSearch(bsnode t,char ch[MAXSIZE]) {
	if (t != NULL) {												//����Ϊ�ǿ�ʱ 
		InOrderSearch(t->lchild,ch);
		if(strcmp(ch,t->data.brand) == 0){
			printf("\n---------�ֽ���------------\n");
			printf("��ױƷ����:%s ��ױƷ�۸�:%d\n", t->data.brand, t->data.price);
			return ;
		}
		InOrderSearch(t->rchild,ch);
	}
}/*������Ϊ�������в��һ�ױƷ��Ϣ*/
void Search(bsnode t){
	char ch[MAXSIZE];
	scanf("%s",&ch);
	InOrderSearch(t,ch);
} 
/*�Լ۸�Ϊ�������в��һ�ױƷ��Ϣ*/
void FindX(bsnode t, int x){
	while(t){	     												//������Ϊ��ʱ
		if( x < t->data.price ){
			 t = t->lchild; 										//���������������� 
		}else if( x > t->data.price ){
			t = t->rchild;       									//���������������� 
		}else{
			printf("�û�ױƷ������Ϊ:%s\n",t->data.brand);          //�ҵ���
			break;
		}
	}         
}
/*����������*/
void InOrder(bsnode t) {
	if (t != NULL) {												//����Ϊ�ǿ�ʱ 
		InOrder(t->lchild);
		printf("\n---------�ֽ���------------\n");
		printf("��ױƷ����:%s ��ױƷ�۸�:%d\n", t->data.brand, t->data.price);
		InOrder(t->rchild);
	}
}
/*ͳ�ƶ����������еĽ�����*/
int CountNode(bsnode t){										     
	if(t == NULL){												    //����Ϊ��ʱ 
		return 0;
	}else{
		return CountNode(t->lchild) + CountNode(t->rchild) + 1;		//���������� + ������ + ����� 
	}	
}
/*ͳ�ƶ��������������*/
int CountTreeDeep(bsnode t){
	int deep = 0;
	if(t){
		int leftdeep = CountTreeDeep(t->lchild);					//���������ĸ߶� 
		int rightdeep = CountTreeDeep(t->rchild);					//���������ĸ߶� 
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;//�ܸ߶� 
	}
	return deep;
} 
/*�˳�����*/
void Exit(){
 	for (int i = 5; i >= 1; i--) {
		printf("���������˳�,����ʱ��%d��\n", i);
		Sleep(1000);											    //ִ�й���һ��ʱ�� 
	}
	exit(0);
 }
/*������*/
int main() {
	bsnode t = NULL;												//��ʼ�� 
	int x;															//��������Ļ�ױƷ�ܸ��� 
	int choice;														//���еĲ��� 
	while(1){
		Menu(); 													//��ʾ�˵�
		printf("��ѡ����Ҫ���еĲ���: ");
		flag:scanf("%d",&choice);
		if(choice < 1 || choice > 7){
			printf("������Ĳ���������ȷ,���������룡\n");
			goto flag; 
		}
		switch(choice){
			case 1 :
				CreatBstree(&t);
				break;
			case 2 :
				printf("��������Ҫ���ҵĻ�ױƷ����:\n");	
				Search(t);
				break;
			case 3 :
				printf("��������Ҫ���ҵĻ�ױƷ�۸�:\n");
				scanf("%d",&x);
				FindX(t,x);
				break;
			case 4 :
				printf("��������������Ľ��Ϊ:\n");
				InOrder(t);
				break;
			case 5 :
				printf("�����������н���ܸ���Ϊ:%d\n",CountNode(t));
				break; 
			case 6 :
				printf("���������������Ϊ:%d\n",CountTreeDeep(t));
				break; 
			case 7 :
				Exit();
				break;
			default :
				break;
		}
		system("pause");											//��ͣ,�ȴ��û��ź� 
		system("cls"); 												//���� 
	}	
	return 0;
}
