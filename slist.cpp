#include <stdio.h>
#include "slist.h"

/*

Class Library File

*/

    Node::Node(void* new_data) {
        data = new_data;
        next = nullptr;
    }


// Constructor
    Slist::Slist() {
        head = nullptr;
        current = head;
        length = 1;
    }

    Slist::Slist(void* data) {
        head =  new Node(data);
        current = head;
        length = 1;
    }
// Destructor
    Slist::~Slist(){
        Node* temp = head->next;
        while(temp != nullptr) {
            delete head;
            head = temp;
            temp = head->next;
        }
    }
// add(value) //Adds a new value to the end of this list.
    void Slist::add(void* value) {
        Node* created = new Node(value);
        if(head == nullptr) {
            head = (created);
            current = head;
        } else {
        current->next = (created);
        current = current->next;
        }
        length++;
    }
// clear() //Removes all elements from this list.
    void Slist::clear() {
        Node* temp = head;
        int c = 0;
        while(temp != nullptr) {
            Node* temp2 = temp;
            temp = temp2->next;
            remove(c);
            c++;
        }
    }
// equals(list) //Returns true if the two lists contain the same elements in the same order.
    bool Slist::equals(Slist list) {
        Node* temp = head;
        Node* temp2 = list.head;
        if(length != list.length) {
            return false;
        }
        while(temp != nullptr && temp2 != nullptr) {
            if(temp->data != temp2->data) {
                return false;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        return true;
    }
//get(index) //Returns the element at the specified index in this list.
    void* Slist::get(int index) {
        Node* temp = head;
        if (index < length) {
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp;
        }
        return NULL;
    }
//insert(index, value) //Inserts the element into this list before the specified index.
    void Slist::insert(int index, void* value) {
        Node* temp = head;
        if (index < length) {
            for(int i = 0; i < index-1; i++) {
                temp = temp->next;
            }
            Node created = new Node(value) ;
            Node* tempAdd = temp->next;
            temp->next = &(created);
            created.next = tempAdd;
            length++;
           
        }
    }
//exchg(index1, index2) //Switches the payload data of specified indexex.
    void Slist::exchg(int index1, int index2) {
        Node* temp = head;
        Node* temp26354758 = head;
        if (index1 < length) {
            for(int i = 0; i < index1; i++) {
                temp = temp->next;
            }
        }
        if (index2 < length) {
            for(int i = 0; i < index2; i++) {
                temp26354758 = temp26354758->next;
            }
        }
        void* temp0 = temp26354758->data;
        temp26354758->data = temp->data;
        temp->data = temp0;
    }

//swap(index1,index2) //Swaps node located at index1 with node at index2
    void Slist::swap(int index1,int index2) {
        Node* temp = (Node*) get(index1);
        Node* pointer1;
        Node* temp2 = (Node*) get(index2);
        Node* pointer2;
        if(index1 == 0) {
            pointer1 = head;
        } else {
            pointer1 = ((Node*)get(index1-1))->next;
        }
        if(index2 == 0) {
            pointer2 = head;
        } else {
            pointer2 = ((Node*)get(index1-1))->next;
        }
        if(index1-1 < 0) {
            if(index1+1 < length) {
                *temp2->next = get(index1+1);
            } else {
                *temp2->next = nullptr;
            }
            head = pointer2;
        } else {
            if(index1+1 < length) {
                *temp2->next = get(index1+1);
            } else {
                *temp2->next = nullptr;
            }
            (Node)get(index1-1) = pointer2;
        }
       
        if(index2-1 < 0) {
            if(index2+1 < length) {
                *temp->next = get(index2+1);
            } else {
                *temp->next = nullptr;
            }
            head = pointer1;
        } else {
            if(index2+1 < length) {
                *temp2->next = get(index2+1);
            } else {
                *temp->next = nullptr;
            }
            (Node)get(index2-1) = pointer2;
        }
    }
// isEmpty() //Returns true if this list contains no elements.
    bool Slist::isEmpty() {
        if(head == nullptr) {
            return true;
        }
        return false;
    }
// remove(index) //Removes the element at the specified index from this list.
    void Slist::remove(int index) {
        Node* temp = head;
        if (index < length) {
            for(int i = 0; i < index; i++) {
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            delete temp;
            if(index = 0) {
                head = temp2;
            } else {
                ((Node*)get(index-1))->next = temp2;
            }
        }
    }
// set(index, value) //Replaces the element at the specified index in this list with a new value.
    void Slist::set(int index, void* value) {
        ((Node*)get(index))->data = value;
    }
// size() //Returns the number of elements in this list.
int Slist::size() {

return length;

}
// subList(start, length) //Returns a new list containing elements from a sub-range of this list.
Slist Slist::subList(int start, int length) {
    Slist rtr = new Slist(get(0));
    for(int i = 1; i<(length-start); i++) {
        rtr.add(get(i));
    }
    return rtr;
}


// toString() //Converts the list to a printable string representation.
std::string Slist::toString() {

    std::string rtr = "";

    for(int i = 0; i<length; i++) {
    rtr += i+":"+*(char*)(((Node*)get(i))->data);
    }

return rtr;

}