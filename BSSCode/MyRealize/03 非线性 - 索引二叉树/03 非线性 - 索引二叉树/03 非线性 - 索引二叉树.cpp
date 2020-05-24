#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//����һ���ṹ��ڵ�
typedef struct Node{
	int data;
	struct Node* left;
	struct Node* right;
}NODE;

//����һ����
typedef struct{
	NODE* root;
}Tree;

//��һ�����������һ������ ֵΪvalue  �Ƚ�value�����һ���ڵ�  ���ڵ�����������Һ��ӣ�
void insert(Tree* tree, int value){
	NODE* node =(NODE* ) malloc(sizeof(NODE));
	assert(node != NULL); 
	node->data = value;
	node->left = NULL;//��Ϊ��һ���µĽڵ�  �����½ڵ�����Һ���Ϊ��
	node->right = NULL;

	//�������������ǿյ� ��ôtree->root ����node
	if (tree->root == NULL){
		tree->root = node;
	}

	//�������Ϊ�� ����Ҫ�����ҽ��бȽ�
	else{
		NODE* temp = tree->root;//tempΪ��ǰ�ȽϵĽڵ�
		while (temp != NULL){
			if (value < temp->data){//������ȵ�����	
				//�������������� 1���Ϊ��
				if (temp->left == NULL){
					temp->left = node;
					return;
				}
				else{//��߲�Ϊ��
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