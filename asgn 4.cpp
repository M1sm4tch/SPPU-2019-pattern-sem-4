#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        traversal(root->left);
        traversal(root->right);
    }
}
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}
void postorder(Node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
Node* insert(Node* &root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }
    else if (x >= root->data)
    {
        root->right = insert(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    return root;
}

int height(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left_subtree = 1+height(root->left);
    int right_subtree = 1+height(root->right);
    return max(left_subtree, right_subtree);
}

int minimum(Node* root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    return min(minimum(root->left), root->data);
}

void search(Node* root, int key, bool &present)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == key)
    {
        present = true;
    }
    else if (root->data > key)
    {
        search(root->left, key, present);
    }
    else if (root->data <= key)
    {
        search(root->right, key, present);
    }
}

void mirror(Node* &root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main()
{
    Node *root = NULL;
    int n;
    char ch;
    int c;
    while(c!=6)
    {
        cout<<"\n1. Create bst.";
        cout<<"\n2. Display.";
        cout<<"\n3. Height.";
        cout<<"\n4. Minimum.";
        cout<<"\n5. Search.";
        cout<<"\n6. Exit.";
        cin>>c;
        switch(c)
        {
        case 1:
            cout << "Enter the number of nodes to be inserted in the BST-\n";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int element;
                cout << "Enter the data value to be inserted-\n";
                cin >> element;
                insert(root, element);
            }
        break;
        case 2:
            cout << "Displaying the elements of the BST-\n";
            traversal(root);
            cout << endl;
            break;
        case 3:
        {
            cout << "Height of the tree is " << height(root) << endl;
            break;
        }
        case 4:
        {
            cout << "Minimum value in the BST is " << minimum(root) << endl;
            break;
        }
        case 5:
        {
            int key;
            cout << "Enter the data value to be searched in the BST-\n";
            cin >> key;
            bool present = false;
            search(root, key, present);
            if (present == true)
            {
                cout << "Key is present in the BST!" << endl;
            }
            else
            {
                cout << "Key is not present in the BST!" << endl;
            }
            break;
        }
        case 6:
            break;
        default:
        {
            cout<<"Invalid choice. Try again."<<endl;
        }
        }
    }
    return 0;
}
