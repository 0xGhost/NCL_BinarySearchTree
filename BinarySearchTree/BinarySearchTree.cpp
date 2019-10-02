// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct node
{
	int value;
	struct node* right;
	struct node* left;
};

struct node* root = NULL;

void insert_integer(struct node** tree, int value)
{
	//struct node** ptr = tree;
	if (tree == NULL)
	{
		cout << "tree pointer empty!" << endl;
		return;
	}
	if (*tree == NULL)
	{
		*tree = new struct node();
		(*tree)->value = value;
		(*tree)->right = NULL;
		(*tree)->left = NULL;
		return;
	}
	if (value > (*tree)->value)
	{
		//if ((*tree)->right != NULL)
			insert_integer(&(*tree)->right, value);
		/*
		else
		{
			ptr->right = new struct node();
			ptr->right->value = value;
			ptr->right->right = NULL;
			ptr->right->left = NULL;
		}*/

	}
	if (value <= (*tree)->value)
	{
		//if ((*tree)->left != NULL)
			insert_integer(&(*tree)->left, value);
		/*
		else
		{
			ptr->left = new struct node();
			ptr->left->value = value;
			ptr->left->right = NULL;
			ptr->left->left = NULL;
		}
		*/
	}
}

void print_tree(struct node* tree)
{
	if (tree == NULL)
	{
		cout << "tree is empty!" << endl;
		return;
	}

	if (tree->left != NULL)
	{
		print_tree(tree->left);
	}
	cout << tree->value << endl;
	if (tree->right != NULL)
	{
		print_tree(tree->right);
	}
}

void terminate_tree(struct node* tree)
{
	if (tree == NULL)
	{
		cout << "tree is terminated" << endl;
		return;
	}

	if (tree->left != NULL)
	{
		terminate_tree(tree->left);
	}
	if (tree->right != NULL)
	{
		terminate_tree(tree->right);
	}
	delete tree;
	tree = NULL;
}

int main()
{
	int option;
	bool flag = true;
	do 
	{
		cout << "1:insert integer \n2:print tree \n3: terminate tree" << endl;
		cin >> option;
		switch (option)
		{
		case 1: 
			cout << "enter an integer: ";
			int inputNumber;
			cin >> inputNumber;
			insert_integer(&root, inputNumber);
			break;
		case 2:
			print_tree(root);
			break;
		case 3:
			terminate_tree(root);
			flag = false;
			break;
		default:

			break;
		}

	} while (flag);
	
	return 0;
}

