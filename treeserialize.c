#include <stdio.h>

typedef struct BinaryNode
{
    struct BinaryNode *left;
    struct BinaryNode *right;
    int data;
} BinaryNode;

typedef struct SaveNode
{
    int data;
    int childindexbeg;
    int childindexend;
} SaveNode;

void serial(BinaryNode *root)
{
    BinaryNode* q[256];
    SaveNode saveq[356] = {0};

    int head = 0;
    int tail = 1;
    q[head] = root;

    while (head < tail)
    {
        if (q[head]->left)
        {
            saveq[head].childindexbeg = tail;
            q[tail++] = q[head]->left;
        }
        if (q[head]->right)
        {
            saveq[head].childindexend = tail;
            q[tail++] = q[head]->right;
        }
        saveq[head].data = q[head++]->data;
    }
    FILE *fp = fopen("tree.log","w");
    fwrite(&tail,1,sizeof(int),fp);
    fwrite(saveq,tail,sizeof(SaveNode),fp);
    fclose(fp);
}

BinaryNode* unserial(char* treelog)
{
    size_t nodenum ;
    int i;
    SaveNode saveq[256];
    BinaryNode** basenode;

    FILE *fp = fopen(treelog,"r");
    fread(&nodenum,1,sizeof(int),fp);

    fread(saveq,nodenum,sizeof(SaveNode),fp);
    basenode = malloc(sizeof(BinaryNode*) * nodenum);
    for (i = 0;i < nodenum; ++i)
    {
        basenode[i] = malloc(sizeof(struct BinaryNode));
        basenode[i]->left = basenode[i]->right = NULL;
    }

    for (i = 0; i < nodenum; ++i)
    {
        basenode[i]->data = saveq[i].data;
        if (saveq[i].childindexbeg)
        {
            basenode[i]->left = basenode[saveq[i].childindexbeg];
        }
        if (saveq[i].childindexend)
        {
            basenode[i]->right = basenode[saveq[i].childindexend];
        }
    }
    return basenode[0];
}




    
int main()
{
}
