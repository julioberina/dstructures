#include "list.hpp"

template<typename T>
list::list()
{
    dummy = nullptr;
    len = 0;
}

template<typename T>
list::list(const list& other)
{
    if (this != other && other.dummy != nullptr)
    {
        node* otherTrav = nullptr;
        node* thisTrav = nullptr;
        node* newNode = new node;
        newNode->value = other.dummy->value;
        dummy = newNode;
        dummy->next = nullptr;
        
        if (other.dummy->next == dummy)
            newNode->next = newNode;
        else
        {
            otherTrav = other.dummy->next;
            thisTrav = dummy->next;

            while (otherTrav->next != other.dummy)
            {
                node* cNode = new node;
                cNode->value = otherTrav->value;
                cNode->next = otherTrav->next;
                
                if (thisTrav == nullptr)
                    dummy->next = cNode;
                else
                    thisTrav->next = cNode;

                thisTrav = cNode;
                otherTrav = otherTrav->next;
            }

            thisTrav->next = dummy;
        }
    }
}
