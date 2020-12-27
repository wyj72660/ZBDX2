#include <stdio.h>													/*需要用到的头文件*/
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <malloc.h>
/*****************************************************************************
File name:   binary_sort_tree.cpp
Description: 建立一个由多种化妆品品牌价格组成的二叉排序树,
             并按照价格从低到高的顺序打印输出。 
Author:      19060141班 第十组成员 
Version:     1.0
Date:        2020/12/16
*****************************************************************************/
#define MAXSIZE 100
/*创建化妆品信息的结构体*/
typedef struct {
	char brand[MAXSIZE];											/*化妆品品牌名字*/
	int price;														/*化妆品品牌价格*/
}nodeData;
/*定义二叉排序树链表的结点结构*/
typedef struct node {
	nodeData data;													/*二叉排序树的结点信息*/
	struct node* lchild, * rchild;									/*左右孩子指针*/
}bnode,*bsnode;
/*函数声明*/
void Menu();														//显示主菜单
void InsertBst(bsnode *t,int key,char *brand);						//二叉排序树的插入
void CreatBstree(bsnode *t);										//二叉排序树的建立
void InOrderSearch(bsnode t,char ch[MAXSIZE]);						//中序遍历查找
void Search(bsnode t);												//以名称查找化妆品信息 
void FindX(bsnode t, int x);										//以价格为索引查找化妆品的信息
void InOrder(bsnode t);												//二叉排序树的中序遍历输出
int CountNode(bsnode t);											//统计二叉排序树的结点个数
int CountTreeDeep(bsnode t);										//统计二叉排序树的深度 
void Exit();														//退出程序的函数 
/*主菜单函数*/
void Menu(){
	printf("\t\t ***************************************************** \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *           欢迎使用YES I CAN化妆品管理系统         * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t ***************************************************** \n"); 
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             1.建立化妆品信息二叉排序树.           * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             2.以名称查找化妆品信息.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             3.以价格查找化妆品信息.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             4.中序遍历输出.                       * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             5.统计二叉排序树中结点个数.           * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             6.统计二叉排序树的深度.               * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t *             7.退出化妆品管理系统.                 * \n");
 	printf("\t\t *                                                   * \n");
 	printf("\t\t ***************************************************** \n");
}
/*二叉排序树的插入算法(递归方法)*/
void InsertBst(bsnode *t, int key,char *brand) {
	if ((*t) == NULL) {												//当树为空时 
		(*t) = (bsnode)malloc(sizeof(bnode));						//生成新结点 
		strcpy((*t)->data.brand,brand);								//将brand字符串复制到结构体中的brand 
		(*t)->data.price = key;										//将结构体中的价格赋值给形参key 
		(*t)->lchild = (*t)->rchild = NULL;							//将左右孩子初始化为NULL 
	}else if (key < (*t)->data.price) {								/*当前key小于结构体中的price
	                                              					  递归方法插入到左子树中*/  
		InsertBst(&(*t)->lchild, key,brand);
	}else {
		InsertBst(&(*t)->rchild, key,brand);						//递归方法插入到右子树种 
	}
}
/*二叉排序树的建立算法*/
void CreatBstree(bsnode *t) {
	int num;														//化妆品总个数的变量 
	int x;															//化妆品价格的变量 
	char brand[MAXSIZE];
	printf("请你输入化妆品的总个数:\n");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		printf("请输入第%d个化妆品的名称:\n",i);
		scanf("%s",&brand);
		printf("请输入第%d个化妆品的价格:\n",i);
		scanf("%d", &x);
		InsertBst(t, x,brand);
	}
}
/*中序遍历二叉排序树,以名称来查找化妆品信息*/
void InOrderSearch(bsnode t,char ch[MAXSIZE]) {
	if (t != NULL) {												//当树为非空时 
		InOrderSearch(t->lchild,ch);
		if(strcmp(ch,t->data.brand) == 0){
			printf("\n---------分界线------------\n");
			printf("化妆品名称:%s 化妆品价格:%d\n", t->data.brand, t->data.price);
			return ;
		}
		InOrderSearch(t->rchild,ch);
	}
}/*以名称为索引进行查找化妆品信息*/
void Search(bsnode t){
	char ch[MAXSIZE];
	scanf("%s",&ch);
	InOrderSearch(t,ch);
} 
/*以价格为索引进行查找化妆品信息*/
void FindX(bsnode t, int x){
	while(t){	     												//当树不为空时
		if( x < t->data.price ){
			 t = t->lchild; 										//沿左子树继续查找 
		}else if( x > t->data.price ){
			t = t->rchild;       									//沿右子树继续查找 
		}else{
			printf("该化妆品的名称为:%s\n",t->data.brand);          //找到了
			break;
		}
	}         
}
/*中序遍历输出*/
void InOrder(bsnode t) {
	if (t != NULL) {												//当树为非空时 
		InOrder(t->lchild);
		printf("\n---------分界线------------\n");
		printf("化妆品名称:%s 化妆品价格:%d\n", t->data.brand, t->data.price);
		InOrder(t->rchild);
	}
}
/*统计二叉排序树中的结点个数*/
int CountNode(bsnode t){										     
	if(t == NULL){												    //当树为空时 
		return 0;
	}else{
		return CountNode(t->lchild) + CountNode(t->rchild) + 1;		//遍历左子树 + 右子树 + 根结点 
	}	
}
/*统计二叉排序树的深度*/
int CountTreeDeep(bsnode t){
	int deep = 0;
	if(t){
		int leftdeep = CountTreeDeep(t->lchild);					//求左子树的高度 
		int rightdeep = CountTreeDeep(t->rchild);					//求右子树的高度 
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;//总高度 
	}
	return deep;
} 
/*退出函数*/
void Exit(){
 	for (int i = 5; i >= 1; i--) {
		printf("程序正在退出,倒计时：%d秒\n", i);
		Sleep(1000);											    //执行挂起一段时间 
	}
	exit(0);
 }
/*主函数*/
int main() {
	bsnode t = NULL;												//初始化 
	int x;															//即将输入的化妆品总个数 
	int choice;														//进行的操作 
	while(1){
		Menu(); 													//显示菜单
		printf("请选择您要进行的操作: ");
		flag:scanf("%d",&choice);
		if(choice < 1 || choice > 7){
			printf("您输入的操作数不正确,请重新输入！\n");
			goto flag; 
		}
		switch(choice){
			case 1 :
				CreatBstree(&t);
				break;
			case 2 :
				printf("请输入你要查找的化妆品名称:\n");	
				Search(t);
				break;
			case 3 :
				printf("请输入你要查找的化妆品价格:\n");
				scanf("%d",&x);
				FindX(t,x);
				break;
			case 4 :
				printf("中序遍历二叉树的结果为:\n");
				InOrder(t);
				break;
			case 5 :
				printf("二叉排序树中结点总个数为:%d\n",CountNode(t));
				break; 
			case 6 :
				printf("二叉排序树的深度为:%d\n",CountTreeDeep(t));
				break; 
			case 7 :
				Exit();
				break;
			default :
				break;
		}
		system("pause");											//暂停,等待用户信号 
		system("cls"); 												//清屏 
	}	
	return 0;
}
