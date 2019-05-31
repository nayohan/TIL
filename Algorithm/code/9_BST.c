#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int i;
	struct node* left;
	struct node* right;
}node;
node* root;
node* createNewNode(int _v) {
	struct node* new_node = (node*)malloc(sizeof(node));
	new_node->i = _v;
	new_node->left = new_node->right = NULL;
	return new_node;
}
void addToBST(int _v) {
	node* new_node = createNewNode(_v);

	if (root == 0) {
		root = new_node;
	}
	else {
		struct node* cur = root;
		while (1) {
			if (new_node->i > cur->i) {
				if (cur->right == NULL) {
					cur->right = new_node;
					return;
				}
				else {
					cur = cur->right;
				}
			}
			else {
				if (cur->left == NULL) {
					cur->left = new_node;
					return;
				}
				else {
					cur = cur->left;
				}
			}
		}
	}
}

void inorder(node* node) {
	if (node == NULL) {
		return;
	}
	inorder(node->left);
	printf("%d ", node->i);
	inorder(node->right);
}
int serachBST(int _v) {
	struct node* cur = root;
	while (1) {
		if (cur == NULL) {
			return NULL;
		}
		if (_v == cur->i) {
			return 1;
		}
		if (_v > cur->i) {
			cur = cur->right;
		}
		else {
			cur = cur->left;
		}
	}
}
node* findLeast(node* node) {
	struct node* cur = node;
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur;
}
node* removeNode(node* node, int _v) {
	if (node == NULL) {
		return NULL;
	}
	if (_v == node->i) {
		if ((node->left == 0) && (node->right == 0)) {
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
			struct node* replace = findLeast(node->right);
			node->i = replace->i;
			node->right = removeNode(node->right, replace->i);
			return node;
		}
	}
	if (_v > node->i) {
		node->right = removeNode(node->right, _v);
		return node;
	}
	else {
		node->left = removeNode(node->left, _v);
		return node;
	}
}
int main() {
	addToBST(10);
	addToBST(5);
	addToBST(30);
	addToBST(20);
	addToBST(40);
	addToBST(35);
	addToBST(50);
	inorder(root);
	printf("\n");
	removeNode(root, 30);
	inorder(root);
}