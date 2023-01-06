/*178. Find Path in BST: Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.*/

/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    if (data > root->data)
    {
        vector<int> *rightOutput = getPath(root->right, data);
        if (rightOutput != NULL)
        {
            rightOutput->push_back(root->data);
            return rightOutput;
        }
    }

    else if (data < root->data)
    {
        vector<int> *leftOutput = getPath(root->left, data);
        if (leftOutput != NULL)
        {
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    }

    return NULL;
}