#include <QCoreApplication>
#include <memory>
#include <iostream>

using namespace std;

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

class Stack
{
    // Pointer to Data
    int *data;
    // current position in stack
    int pos;

public:
    Stack()
    {
        data = nullptr;
        pos = 0;
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
};

int main(int argc, char *argv[])
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

    while (!s.isEmpty())
    {
        cout << s.pull() << endl;
    }

    return 0;
}
