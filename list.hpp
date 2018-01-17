#pragma once

template<typename T>
class list
{
public:
    list();
    list(const list& other);
    list& operator=(const list& other);
    ~list();
    void append(T elem); // tail insertion
    void insert(T elem); // head insertion
    void remove(T elem);
    int length() const;
private:
    int len;

    struct node
    {
        T value;
        node* next;
    };

    node* dummy;
};
