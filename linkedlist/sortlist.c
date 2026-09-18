#include <stdio.h>
#include <stdlib.h>

typedef struct test
{
    int data;
    struct test *next;
} t_test;

t_test      *fill_struct(int number,int value)
{
    t_test *cur = NULL;
    t_test *prev = NULL;

    int i = 0;
    while (i < number)
    {
        t_test  *node = malloc(sizeof(t_test));
        node->data = value;
        node->next = NULL;
        if(cur == NULL)
        {
            cur = node;
            prev = cur;
        }
        else
        {
            prev->next = node;
            prev = node;
        }
        i++;
        value += 12;
    }
    return cur;
}
void    sort_list(t_test *list)
{
    t_test  *cur = list;
    t_test  *prev;
    while(cur != NULL)
    {
        prev = cur->next;
        while (prev != NULL)
        {
            if (prev->data > cur->data)
            {
                int temp = prev->data;
                prev->data = cur->data;
                cur->data = temp;
            }
            prev = prev->next;
        }
        cur = cur->next;
    }
}
int main()
{
    t_test *list = fill_struct(7,5);
    //list = fill_struct(4,1);
    sort_list(list);
    t_test *cur = list;
    int i = 0;
    while(i < 7)
    {
        printf("%d\n",cur->data);
        cur = cur->next;
        i++;
    }
    return 0;
}