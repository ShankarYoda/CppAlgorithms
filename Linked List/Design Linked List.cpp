class MyLinkedList
{
    class Node
    {
    public:
        int val;
        Node *next, *prev;
        Node(int val)
        {
            this->val = val;
            next = prev = NULL;
        }
        Node(int val, Node *next, Node *prev)
        {
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };
    Node *HEAD, *TAIL;
    int size;

public:
    MyLinkedList()
    {
        HEAD = TAIL = NULL;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        else if (index == 0)
            return HEAD->val;
        else
        {
            Node *temp = HEAD;
            while (index--)
            {
                temp = temp->next;
            }
            return temp->val;
        }
    }

    void addAtHead(int val)
    {
        if (size == 0)
        {
            HEAD = new Node(val);
            TAIL = HEAD;
        }
        else
        {
            HEAD = new Node(val, HEAD, NULL);
            HEAD->next->prev = HEAD;
        }
        size++;
    }

    void addAtTail(int val)
    {
        if (size == 0)
        {
            HEAD = new Node(val);
            TAIL = HEAD;
        }
        else
        {
            TAIL = new Node(val, NULL, TAIL);
            TAIL->prev->next = TAIL;
        }
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        else if (index == 0)
            return addAtHead(val);
        else
        {
            Node *temp = HEAD;
            index--;
            while (index--)
                temp = temp->next;

            Node *temp2 = new Node(val, temp->next, temp);
            if (temp->next)
            {
                temp->next->prev = temp2;
            }
            temp->next = temp2;
            if (temp2->next == NULL)
            {
                TAIL = temp2;
            }
            if (temp2->prev == NULL)
            {
                HEAD = temp2;
            }
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        else if (size == 1)
        {
            delete HEAD;
            HEAD = TAIL = NULL;
            size--;
        }
        else
        {
            Node *temp = HEAD;
            while (index--)
                temp = temp->next;

            if (temp->prev)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                HEAD = temp->next;
            }
            if (temp->next)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                TAIL = temp->prev;
            }
            delete temp;
            size--;
        }
    }
};