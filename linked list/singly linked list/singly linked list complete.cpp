#include <iostream>
#include <cstdlib>
using namespace std;

#define new_line cout<<'\n';

class node
{
public:
    int info;
    node * next;
};

class linked_list
{
private:
    node * start;

    node * createNode();
    node * findNode(int data);
public:
    linked_list()
    {
        start = NULL;
    }

    void push();

    void display();

    void pop();

    void unshift();

    void shift();

    void findKey();

    void deleteKey();

    void addKey();
};

node * linked_list::createNode()
{
    //create a node
    node * temp;
    temp = new node;
    return temp;
}

void linked_list::push()
{
    //add node at the last

    node * ptr;
    ptr = createNode();
    if(ptr == NULL)
    {
        cout<<"\nLinked List full...";
    }
    else
    {
        int n;
        cout<<"\nEnter the number : ";
        cin>>n;
        ptr->info = n;
        ptr->next = NULL;
        if(start == NULL)
        {
            start = ptr;
        }
        else
        {
            node * temp;
            temp = start;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
}

void linked_list::display()
{
    //traverse and display all nodes
    cout<<"\n\nDisplaying list :";
    node * temp;
    temp = start;
    cout<<'\n';
    if(temp == NULL)
    {
        cout<<"\nLinked List Empty...";
    }
    while(temp !=  NULL)
    {
        cout<<temp->info<<" -> ";
        temp = temp->next;
    }
    new_line
}

void linked_list::pop()
{
    //delete the last node

    node * temp, *last;
    temp = start;
    if(temp == NULL)
    {
        cout<<"\nLinked List Empty";
    }
    else {
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    last = temp->next;
    temp->next = NULL;
    cout<<"\ndeleting "<<last->info<<"...";
    delete [] last;
    }
}

void linked_list::unshift()
{
    //add node at front

    node * ptr;
    ptr = createNode();
    if(ptr == NULL)
    {
        cout<<"\nLinked List full...";
    }
    else
    {
        int n;
        cout<<"\nEnter the number : ";
        cin>>n;
        ptr->info = n;
        ptr->next = start;
        start = ptr;
    }
}

void linked_list::shift()
{
    //delete node from the front

    node * ptr;
    ptr = start;
    if(ptr == NULL)
    {
        cout<<"\nLinked List Empty...";
    }
    else
    {
        start = start->next;
        cout<<"\ndeleting "<<ptr->info<<"...";
        delete [] ptr;
    }
}

node * linked_list::findNode(int data)
{
    node * ptr;
    ptr = start;

    if(ptr == NULL)
    {
        cout<<"\nLinked List empty...";
    }
    else
    {
        while(ptr != NULL)
        {
            if(ptr->info == data)
            {
                return ptr;
            }
            ptr = ptr->next;
        }
    }

    return ptr;
}

void linked_list::findKey()
{
    int n;
    cout<<"\n\nEnter the number to find...";
    cin>>n;
    node * ptr;
    ptr = findNode(n);
    if(ptr!=NULL)
    {
        cout<<"\n"<<ptr->info<<" found...";
    }
    else
    {
        cout<<"\nValue not found";
    }
}

void linked_list::deleteKey()
{
    node * ptr;
    ptr = start;
    if(ptr == NULL)
    {
        cout<<"\nLinked List is empty...";
    }
    else
    {
        int n;
        cout<<"\nEnter number to be deleted...";
        cin>>n;
        node * prev;
        if(ptr->info == n)
        {
             start = ptr->next;
             delete [] ptr;
             return;
        }

        while(ptr!=NULL && ptr->info != n)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if(ptr == NULL)
        {
            return;
        }

        prev->next = ptr->next;
        cout<<"\ndeleting "<<ptr->info<<"...";
        delete [] ptr;

    }
}

void linked_list::addKey()
{
    int prvKey;
    cout<<"\nEnter the key after which new key is to be added...";
    cin>>prvKey;
    node * prv;
    prv = findNode(prvKey);
    if(prv == NULL)
    {
        cout<<"\nSuch key does not exist...";
    }
    else
    {
        int n;
        cout<<"\nEnter key to be inserted...";
        cin>>n;
        node * insNode;
        insNode = createNode();
        insNode->info = n;
        insNode->next = prv->next;
        prv->next =  insNode;
    }
}

void main_menu()
{
    new_line
    new_line
    new_line
    cout<<"LINKED LIST main menu....";
    new_line
    new_line
    cout<<"PRESS 1 to insert Data";
    new_line
    cout<<"PRESS 2 to delete Data";
    new_line
    cout<<"PRESS 3 to find Data";
    new_line
    cout<<"PRESS 4 to display current list";
    new_line
    cout<<"PRESS 5 to clear screen";
    new_line
    cout<<"PRESS 0 to exit the program";
    new_line
    new_line
    cout<<"please enter your choice:  ";
}

void ins_submenu(linked_list &ll)
{
    int choice;
    new_line
    cout<<"__INSERTION__";
    new_line
    cout<<"PRESS 1 to insert at last";
    new_line
    cout<<"PRESS 2 to insert at front";
    new_line
    cout<<"PRESS 3 to insert after given Data";
    new_line
    cout<<"PRESS 9 to return to previous menu";
    new_line
    cout<<"PRESS 0 to exit the program";
    new_line
    new_line
    cout<<"please enter your choice:  ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        ll.push();
        break;
    case 2:
        ll.unshift();
        break;
    case 3:
        ll.addKey();
        break;
    case 9:
        return;
        break;
    case 0:
        cout<<"\n\t\t*****  THANK YOU *****";
        exit(0);
        break;
    }

}

void del_submenu(linked_list &ll)
{
    int choice;
    new_line
    cout<<"__DELETION__";
    new_line
    cout<<"PRESS 1 to delete last node";
    new_line
    cout<<"PRESS 2 to delete first node";
    new_line
    cout<<"PRESS 3 to delete a specific node";
    new_line
    cout<<"PRESS 9 to return to previous menu";
    new_line
    cout<<"PRESS 0 to exit the program";
    new_line
    new_line
    cout<<"please enter your choice:  ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        ll.pop();
        break;
    case 2:
        ll.shift();
        break;
    case 3:
        ll.deleteKey();
        break;
    case 9:
        return;
        break;
    case 0:
        cout<<"\n\t\t*****  THANK YOU *****";
        exit(0);
        break;
    }
}



int main()
{
    cout<<"\n\t\t\t\t **********  WELCOME  **********";
    cout<<"\n\t\t\t  linked list program made by Mr. Rupesh Garhwal";
    new_line
    new_line
    new_line
    linked_list ll;
    int choice;
    while(1)
    {
        main_menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            ins_submenu(ll);
            break;
        case 2:
            del_submenu(ll);
            break;
        case 3:
            ll.findKey();
            break;
        case 4:
            ll.display();
            break;
        case 5:
            system("cls");
            break;
        case 0:
            cout<<"\n\t\t*****  THANK YOU *****";
            exit(0);
            break;
        }
    }

    return 0;
}
