#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* left;
	struct node* right;
}node;
node* root;

void addToBST(int _v) {
	struct node* new_one = (node*)malloc(sizeof(node));
	new_one->i = _v;
	new_one->left = new_one->right = 0;

	if (root == 0) {
		root = new_one;
	}
	else {
		node* temp = root;
		while (1) {
			//왼쪽
			if (new_one->i < temp->i) {
				if (temp->left == 0) {
					temp->left = new_one;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == 0) {
					temp->right = new_one;
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
}
void searchBST(int _v) {

}
node* inorderTraversal(node* node) {//스택으로 구현가능
	if (node == 0) {
		return 0;
	}
	inorderTraversal(node->left);
	printf("%d ", node->i);
	inorderTraversal(node->right);
}
node* findLeast(node* node) {
	struct node* cur = node;
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur;
}
node* remove_node(node* node, int _v) {
	if (node == 0) {
		return 0;
	}
	if (_v == node->i) {
		if (node->left == 0 && node->right == 0) {
			free(node);
			return 0;
		}
		else if (node->left == 0) {
			struct node* ret = node->right;
			free(node);
			return ret;
		}
		else if (node->right == 0) {
			struct node* ret = node->left;
			free(node);
			return ret;
		}
		else {
			struct node* toReplace = findLeast(node->right);
			node->i = toReplace->i;
			node->right = remove_node(node->right, toReplace->i);
			return node;
		}
	}
	else if (_v < node->i) {
		node->left = remove_node(node->left, _v);
		return node;
	}
	else {
		node->right = remove_node(node->right, _v);
		return node;
	}
}


int main() {
	addToBST(20);
	addToBST(10);
	addToBST(15);
	addToBST(40);

	addToBST(60);
	addToBST(35);

	addToBST(55);
	addToBST(65);

	inorderTraversal(root);
	printf("\n");
	remove_node(root, 40);
	inorderTraversal(root);

}