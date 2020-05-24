#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义一个结构体节点
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}NODE;

//定义一个树
typedef struct{
	NODE* root;
}Tree;

//往一颗树里面插入一个数字 值为value  先将value打包成一个节点  （节点里面包含左右孩子）
void insert(Tree* tree, int value){
	NODE* node =(NODE* ) malloc(sizeof(NODE));
	assert(node != NULL); 
	node->data = value;
	node->left = NULL;//因为是一个新的节点  所以新节点的左右孩子为空
	node->right = NULL;

	//如果这个树本来是空的 那么tree->root 就是node
	if (tree->root == NULL){
		tree->root = node;
	}

	//如果树不为空 则需要很左右进行比较
	else{
		NODE* temp = tree->root;//temp为当前比较的节点
		while (temp != NULL){
			if (value < temp->data){//忽略相等的数字	
				//走左边有两种情况 1左边为空
				if (temp->left == NULL){
					temp->left = node;
					return;
				}
				else{//左边不为空
					temp = temp->left;
				}
			}
			
			if (value > temp->data){
				if (temp->right == NULL){
					temp->right = node;
					return;
				}
				else{
					temp = temp->right;
				}
			}
		}
	}
}


void PreOrder(NODE* node){
	if (node != NULL){
		printf("%d ", node->data);
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void InOrder(NODE* node){
	if (node != NULL){
		InOrder(node->left);
		printf("%d ", node->data);
		InOrder(node->right);
	}
}

void PostOrder(NODE* node){
	if (node != NULL){
		PostOrder(node->left);
		PostOrder(node->right);
		printf("%d ", node->data);
	}
}

int GetHight(NODE* node){
	if (node == NULL){
		return 0;
	}
	else{
		int leftH = GetHight(node->left);
		int rightH = GetHight(node->right);
		int max = leftH;
		if (rightH > max){
			max = rightH;
		}
		return max + 1; 
	}
}

int GetMaxNum(NODE* node){
	if (node == NULL){
		return -1;
	}
	else{
		int leftM = GetMaxNum(node->left);
		int rightM = GetMaxNum(node->right);
		int My = node->data;
		int Max = leftM;
		if (rightM > Max){
			Max = rightM;
		}
		if (My > Max){
			Max = My;
		}
		return Max;
	}
}
int main(){
	int arr[7] = { 6, 3, 8, 2, 5, 1, 7 };
	Tree  tree;
	tree.root = NULL;
	int i;
	for (i = 0; i < 7; ++i){
		insert(&tree, arr[i]);
	}
	PreOrder(tree.root);
	printf("\n");
	InOrder(tree.root);
	printf("\n");
	PostOrder(tree.root);
	printf("\n");
	printf("H = %d\n",GetHight(tree.root));
	printf("MaxNum = %d\n", GetMaxNum(tree.root));
	return 0;
}