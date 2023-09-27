#include <iostream>
using namespace std;
////////////////////////////////////////
// start from deletion
///////////////////////////////////////
class Node
{
public:
    // creating a node
    int data;   // data of node
    Node *next; // next node address

    // constructor to add data in node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << " memmory is freed  for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // create new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    // create new node
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    if (position == 1)
    { // inserting at start position
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;

        // solving the hw problem: fix tail
        if (cnt == position)
        {
            tail = prev;
        }

        delete curr;
    }
}

int main()
{

    // crating a node
    Node *node1 = new Node(22);
    // displaying its data
    cout << node1->data << endl;
    // displaying its next node address
    cout << node1->next << endl;

    // head pointed to node 1
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 52);
    print(head);

    insertAtTail(tail, 90);
    print(head);
    insertAtTail(tail, 91);
    print(head);

    insertAtPosition(tail, head, 3, 44);
    print(head);

    insertAtPosition(tail, head, 1, 666);
    print(head);

    insertAtPosition(tail, head, 8, 555);
    print(head);

    deleteNode(8, head, tail);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}
