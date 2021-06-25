#include <QCoreApplication>

#include <iostream>

#include "gtest/gtest.h"

/*
 * @Author      : Atish Patange
 * @Description : Implementation of LRU Cache
 * @Source      : https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
 *
 * */
struct Node
{
    Node* tail = nullptr;
    Node* head = nullptr;
    int value  = 0;
}; typedef Node* Key;

class DoubleLinkedList
{
public:
    DoubleLinkedList()
    {

    }

    virtual ~DoubleLinkedList()
    {

    }

    /* Function  : insertValue(const int& a_value)
     * @input    :
     * @output   :
     * @return   :
     * @parameter:
     *
     * */
    void insertValue(const int& a_value)
    {
        if(m_key)
        {
            Key key = new Node;
            key->value = a_value;

            m_key->head = key;
            key->tail   = m_key;

            m_key       = key;
        }
        else
        {
            m_key       = new Node;
            m_key->tail = nullptr;
            m_key->head = nullptr;
            m_key->value= a_value;

            m_start     = m_key;
        }
    }

    void iterateFromTop()
    {
        std::cout << "#Iterate from top " << std::endl;
        Key temp = m_key;
        while(temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->tail;
        }
    }

    void iterateFromStart()
    {
        std::cout << "#Iterate from start " << std::endl;
        Key temp = m_start;

        while(temp)
        {
            std::cout << temp->value << std::endl;
            temp = temp->head;
        }
    }

    void deleteValue(int a_value)
    {
        Key temp = m_start;
        while(temp)
        {
            if(temp->value == a_value)
            {
                std::cout << "#Value found " << std::endl;

                // is it a first key
                if(temp->tail)
                {
                    temp->tail->head = temp->head;
                }

                if(temp->head)
                {
                    temp->head->tail = temp->tail;
                }

                if(!temp->head)
                {
                    m_key = temp->tail;
                }

                if(!temp->tail)
                {
                    m_start = temp->head;
                }
            }
            temp = temp->head;
        }
    }

private:
    Key m_key   = nullptr;
    Key m_start = nullptr;
};

TEST(AssertTest, FirstTest)
{
    DoubleLinkedList list;
    ASSERT_EQ(1, 1);
}

int main(int argc, char *argv[])
{
   DoubleLinkedList linkedList;

   linkedList.insertValue(10);
   linkedList.insertValue(20);
   linkedList.insertValue(30);
   linkedList.insertValue(40);
   linkedList.insertValue(50);

   linkedList.iterateFromTop();
   linkedList.iterateFromStart();

   linkedList.deleteValue(50);

   linkedList.iterateFromTop();
   linkedList.iterateFromStart();

   linkedList.deleteValue(10);

   linkedList.iterateFromTop();
   linkedList.iterateFromStart();

   linkedList.deleteValue(20);

   linkedList.iterateFromTop();
   linkedList.iterateFromStart();

   ::testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();
}
