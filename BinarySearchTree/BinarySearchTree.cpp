// BinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

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
		insert_integer(&(*tree)->right, value);
	}
	if (value <= (*tree)->value)
	{
		insert_integer(&(*tree)->left, value);
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
	cout << tree->value << " ";
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
	int value = tree->value;
	delete tree;
	tree = NULL;
}

int main()
{
	int option;
	bool flag = true;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	do 
	{
		cout << "\n1:insert integer \n2:print tree \n3: terminate tree" << endl;
		cin >> option;
		switch (option)
		{
		case 1: 
			cout << "enter an integer: ";
			int inputNumber;
			cin >> inputNumber;
			if (cin.fail())
			{
				cout << "Please enter a valid integer." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				insert_integer(&root, inputNumber);
			break;
		case 2:
			cout << endl;
			print_tree(root);
			cout << endl;
			break;
		case 3:
			terminate_tree(root);
			
			_CrtDumpMemoryLeaks();
			flag = false;
			break;
		default:
			cout << "Invalid input! Please input again." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

	} while (flag);
	
	return 0;
}

