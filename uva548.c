#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct TNode
{
    struct TNode* left;
    struct TNode* right;
    int v;
} Node;

Node* newnode()
{
   Node* u = (Node*)malloc(sizeof(Node));
   if (u != NULL)
   {
        u->v = 0;
        u->left = u->right = NULL;
    }
    return u;
}

void buildtree(int* inbeg, int* inend,int* postbeg,int* postend,Node** u)
{
    *u = newnode();
    (*u)->v = *postend;

    if (postbeg == postend) return;
    if (postbeg + 1 == postend)
    {
        if (memcmp(inbeg,postbeg,2*sizeof(int)) == 0)
        {
            (*u)->left  = newnode();
            (*u)->left->v = *postbeg;
        }
        else
        {
            (*u)->right = newnode();
            (*u)->right->v = *postbeg;
        }
        return;
    }
    int *noderoot= inbeg;
    for (; noderoot<= inend; noderoot++)
        if (*noderoot== *postend) break;
    if (noderoot> inbeg)
    {
        int *leftinend = noderoot - 1;
        int *leftinbeg = inbeg;
        int *leftpostbeg = postbeg;
        int *leftpostend = leftpostbeg + (leftinend - leftinbeg);
        buildtree(leftinbeg,leftinend,leftpostbeg,leftpostend,&((*u)->left));
    }
    if (noderoot< inend)
    {
        int *rightinbeg = noderoot + 1;
        int *rightinend = inend;
        int *rightpostend = postend -1;
        int *rightpostbeg = rightpostend - (rightinend - rightinbeg);

        buildtree(rightinbeg,rightinend,rightpostbeg,rightpostend,&((*u)->right));
    }
}

void dfsmin(Node* u,int& min)
{
    if (u)
    {
        if (u->left == NULL && u->right == NULL)
        {
            if (u->v < min) min = u->v;
            return;
        }
        dfsmin(u->left,min);
        dfsmin(u->right,min);
    }
}

void freenode(Node* u)
{
    if (u)
    {
        if (u->left) freenode(u->left);
        if (u->right) freenode(u->right);
        free(u);
    }
}
int main()
{
    char buf[40960];
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while (fgets(buf,sizeof(buf)-1,stdin) != NULL)
    {
        int in[10005] = {0};
        int post[10005] = {0};

        int n = 0;
        in[n++] = atoi(buf);
        char *str = buf;
        while (str = strstr(str," "))
        {
            in[n++] = atoi(str+1);
            str++;
        }
        fgets(buf,sizeof(buf)-1,stdin);
        n = 0;
        post[n++] = atoi(buf);
        str = buf;
        while (str = strstr(str," "))
        {
            post[n++] = atoi(str+1);
            str++;
        }
        Node *root;
        buildtree(in,in + n-1 ,post,post + n -1,&root);

        int min = 10000;
        dfsmin(root,min);
        freenode(root);
        printf("%d\n",min);
    }
}
