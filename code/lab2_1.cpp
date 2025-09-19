#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insert(Node *Nd_prev, int i)
{
    Node *nd = new Node;
    Node *Nd_next = Nd_prev->next;

    nd->data = i;
    nd->next = Nd_next;
    nd->prev = Nd_prev;

    Nd_prev->next = nd;
    Nd_next->prev = nd;
}

void remove(Node *nd)
{
    Node *Nd_prev = nd->prev;
    Node *Nd_next = nd->next;

    Nd_prev->next = Nd_next;
    Nd_next->prev = Nd_prev;

    delete nd;
}

void search(Node *now, Node *end, int i)
{
    while (now != end)
    {
        if (now->data == i)
        {
            cout << "Y\n";
            return;
        }
        else
        {
            now = now->next;
        }
    }
    cout << "N\n";
    return;
}

void output(Node *now, Node *tail)
{
    while (now != tail)
    {
        cout << now->data << " ";
        now = now->next;
    }
    cout << "\n";
    return;
}

int main()
{
    int n, i;
    string str;
    cin >> n;
    Node *head = new Node;
    Node *tail = new Node;
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;

    for (int k = 0; k < n; k++)
    {
        cin >> str;
        if (str == "IH")
        {
            cin >> i;
            insert(head, i);
        }
        else if (str == "IT")
        {
            cin >> i;
            insert(tail->prev, i);
        }
        else if (str == "RH")
        {
            if (head->next != tail)
            {
                remove(head->next);
            }
        }
        else if (str == "RT")
        {
            if (tail->prev != head)
            {
                remove(tail->prev);
            }
        }
        else if (str == "S")
        {
            cin >> i;
            if (head->next != tail)
            {
                search(head->next, tail, i);
            }
            else
            {
                cout << "E\n";
            }
        }
        else if (str == "O")
        {
            if (head->next != tail)
            {
                output(head->next, tail);
            }
            else
            {
                cout << "E\n";
            }
        }
    }

    return 0;
}