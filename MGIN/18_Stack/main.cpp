#include <QCoreApplication>
#include <memory>
#include <iostream>

using namespace std;
/*******************************************************************************
 * Definition * -> Pointer
 * Usage * -> Inhalt
 * Definition & -> Adresse
 * Usage & -> Reference Variable
 *******************************************************************************/

/*******************************************************************************
class Buffer
{
    // Pointer to Data
    int *data;
    // current position in stack
    int pos;

public:
    Buffer()
    {
        data = nullptr;
        pos = 0;
    }

    ~Buffer()
    {
        free(data);
    }

    void push(int value)
    {
        if (data == nullptr)
        {
            data = (int *)malloc(sizeof(int));
        }
        else
        {
            data = (int *)realloc(data, (pos + 1) * sizeof(int));
        }
        data[pos] = value;
        pos++;
    }

    int pull()
    {
        pos--;
        int value = data[0];
        data = (int *)realloc(data, pos * sizeof(int));
        return value;
    }

    bool isEmpty()
    {
        return (pos == 0);
    }
};
*******************************************************************************/
class Stack
{
public:
    // Pointer to Data
    int *data;
    // current position in stack
    int pos;

    Stack()
    {
        data = nullptr;
        pos = 0;
    }

    // Copy Constructor
    Stack(const Stack &s)
    {
        this->pos = s.pos;
        this->data = (int *)(malloc(sizeof(int) * pos));
        for (int i = 0; i < pos; i++)
        {
            data[i] = s.data[i];
        }
    }

    ~Stack()
    {
        free(data);
    }

    void push(int value)
    {
        if (data == nullptr)
        {
            data = (int *)malloc(sizeof(int));
        }
        else
        {
            data = (int *)realloc(data, (pos + 1) * sizeof(int));
        }
        data[pos] = value;
        pos++;
    }

    int pull()
    {
        pos--;
        int value = data[pos];
        data = (int *)realloc(data, pos * sizeof(int));
        return value;
    }

    bool isEmpty()
    {
        return (pos == 0);
    }

    Stack operator+(int num)
    {
        for (int i = 0; i < pos; i++)
        {
            data[i] += num;
        }
        return *this;
    }

    Stack operator=(const Stack &op2)
    {
        pos = op2.pos;
        data = (int *)(malloc(sizeof(int) * pos));
        for (int i = 0; i < pos; i++)
        {
            data[i] = op2.data[i];
        }
        return *this;
    }

    Stack &operator<<(int num)
    {
        push(num);
        return *this;
    }
};

ostream &operator<<(ostream &os, Stack &s)
{
    os << s.pull();
    return os;
}

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);

    s = s + 3;

    s << 666 << 555;

    while (!s.isEmpty())
    {
        cout << s << endl;
    }

    return 0;
}
