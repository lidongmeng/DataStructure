#include <cstdio>
int A[200010], n, q, type, a, b, x, y;

struct Node
{
    int left, right;
    long long sum, val;
};
Node nodes[800010];

void buildTree(int i, int l, int r)
{
    nodes[i].left = l;
    nodes[i].right = r;
    if (l == r)
        nodes[i].sum = A[l];
    else
    {
        int mid = (l + r)>>1;
        buildTree(i<<1, l, mid);
        buildTree(i<<1|1, mid+1, r);
        nodes[i].sum = nodes[i<<1].sum + nodes[i<<1|1].sum;
    }
}

void updateTree(int i, int l, int r, int v)
{
    int left = nodes[i].left;
    int right = nodes[i].right;
    nodes[i].sum += (r-l+1)*v;
    if (l == left &&  r == right)
    {
        nodes[i].val += x;
        return ;
    }
    if (nodes[i].val)
    {
        nodes[i<<1].sum += nodes[i].val*(nodes[i<<1].right - nodes[i<<1].left + 1);
        nodes[i<<1|1].sum += nodes[i].val*(nodes[i<<1|1].right - nodes[i<<1|1].left + 1);
        nodes[i<<1|1].val += nodes[i].val;
        nodes[i<<1].val += nodes[i].val;
        nodes[i].val = 0;
    }
    int mid = (left+right)>>1;
    if (r <= mid)
    {
        updateTree(i<<1, l, r, v);
        return;
    }
    if (l >= mid + 1)
    {
        updateTree(i<<1|1, l, r, v);
        return ;
    }
    updateTree(i<<1, l, mid, v);
    updateTree(i<<1|1, mid+1, r, v);

}

long long queryTree(int i, int l, int r)
{
    int mid = (nodes[i].left + nodes[i].right)>>1;
    if (nodes[i].left == l && nodes[i].right == r)
        return nodes[i].sum;
    if (nodes[i].val)
    {
        nodes[i<<1].sum += nodes[i].val*(nodes[i<<1].right - nodes[i<<1].left + 1);
        nodes[i<<1].val += nodes[i].val;
        nodes[i<<1|1].sum += nodes[i].val*(nodes[i<<1|1].right - nodes[i<<1|1].left + 1);
        nodes[i<<1|1].val += nodes[i].val;
        nodes[i].val = 0;
    }
    if (r <= mid)
        return queryTree(i<<1, l, r);
    if (l >= mid + 1)
        return queryTree(i<<1|1, l, r);
    return queryTree(i<<1, l, mid)+queryTree(i<<1|1, mid+1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    buildTree(1, 1, n);
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d%d%d", &a, &b, &x);
            updateTree(1, a, b, x);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%d\n", queryTree(1, x, y));
        }
    }
    return 0;
}
