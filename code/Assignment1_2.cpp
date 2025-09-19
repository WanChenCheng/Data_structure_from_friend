#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    long data;
    Node *prev;
    Node *next;
};

void insert(Node *Nd_prev, long i)
{
    Node *nd = new Node;
    Node *Nd_next = Nd_prev->next;

    nd->data = i;
    nd->next = Nd_prev->next;
    nd->prev = Nd_prev;
    Nd_prev->next = nd;
    Nd_next->prev = nd;
}

bool compare(Node *n1, Node *n2)
{
    return n1->data < n2->data;
}

void output(Node *cur, Node *tail)
{
    while (cur != tail)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n, q;
        cin >> n >> q;
        Node *head = new Node;
        Node *tail = new Node;
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;

        for (long i = 1; i <= n; i++)
        {
            insert(tail->prev, i);
        }

        Node *cur = head;
        vector<Node *> v(n + 2);
        for (int i = 0; cur != tail->next; i++)
        {
            v[i] = cur;
            cur = cur->next;
        }
        delete cur;

        while (q--)
        {
            char c;
            long k;
            cin >> c >> k;

            if (c == 'H')
            {
                v[k]->prev->next = v[k]->next;
                v[k]->next->prev = v[k]->prev;
                v[k]->prev = head;
                v[k]->next = head->next;
                head->next->prev = v[k];
                head->next = v[k];
            }
            else if (c == 'T')
            {
                v[k]->prev->next = v[k]->next;
                v[k]->next->prev = v[k]->prev;
                v[k]->next = tail;
                v[k]->prev = tail->prev;
                tail->prev->next = v[k];
                tail->prev = v[k];
            }
        }
        output(head->next, tail);
    }
    return 0;
}