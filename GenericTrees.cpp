#include "boiler.h"
#include "reference.h"
TreeNode<int> *takeInputLevelwise()
{
    cout << "Enter Root data" << endl;
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    //printing level wise requires a queue
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop(); //removes the element but doesnot return
        cout << "Enter the no. of children of " << front->data << endl;
        int nchild;
        cin >> nchild;
        for (int i = 0; i < nchild; i++)
        {
            int chilData;
            cout << "Enter the " << i << " child of " << front->data << endl;
            cin >> chilData;
            TreeNode<int> *child = new TreeNode<int>(chilData);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
void PrintLevelwise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}
void PrintTree(TreeNode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        PrintTree(root->children[i]);
    }
}
TreeNode<int> *takeInput()
{

    cout << "ENter data" << endl;
    int data;
    cin >> data;
    TreeNode<int> *child = new TreeNode<int>(data);
    cout << "Enter the number of children" << endl;
    int children;
    cin >> children;
    for (int i = 0; i < children; i++)
    {
        TreeNode<int> *childAddress = takeInput();
        child->children.push_back(childAddress);
    }
    return child;
}
int Height(TreeNode<int> *root)
{

    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int subheight = Height(root->children[i]);
        maxHeight = max(subheight, maxHeight);
    }
    return maxHeight + 1;
}
void depth(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        depth(root->children[i], k - 1);
    }
}
int countLeaf(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeaf(root->children[i]);
    }
    return count;
}

void Preorder(TreeNode<int> *root)
{
    //first root and then children
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        Preorder(root->children[i]);
    }
}
void Postorder(TreeNode<int> *root)
{
    //first children then root
    for (int i = 0; i < root->children.size(); i++)
    {
        Postorder(root->children[i]);
    }
    cout << root->data << " ";
}
void deleteTree(TreeNode<int> *root)
{
    //first children then the root

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

int main()
{

    TreeNode<int> *root = takeInputLevelwise();
    cout << endl;
    // PrintLevelwise(root);
    // cout << endl;
    // int height = Height(root);
    // cout << "Height of the Tree=" << height << endl;
    // cout << "Depth at level:" << endl;
    // depth(root, 1);
    Preorder(root);
    cout << endl;
    Postorder(root);
    cout << endl;
    cout << countLeaf(root) << endl;
}