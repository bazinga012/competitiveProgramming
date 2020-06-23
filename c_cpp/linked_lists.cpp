struct node
{
    int val;
    node *next;
};

node *newNode = (node *)malloc(sizeof(node));
newNode->val = 10;
newNode->next = NULL;