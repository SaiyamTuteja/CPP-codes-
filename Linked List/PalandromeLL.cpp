#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};
class List
{
public:
    bool arrayPlandrome(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    void palandrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        bool ispalandrome = arrayPlandrome(arr);
        if (ispalandrome)
        {
            cout << "Yes its a palandrome Linked list ";
        }
        else
        {
            cout << "NO its no a palandrome :";
        }
        return;
    }

    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void palandrome1(Node *head)
    {
        if (!head || !head->next)
        {
            cout << "Yes, it's a palindrome Linked List\n";
            return;
        }

        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node *secondHalf = reverse(slow);
        Node *firstHalf = head;
        Node *copySecondHalf = secondHalf; // To restore later

        // Compare both halves
        bool isPalindrome = true;
        while (secondHalf != NULL)
        {
            if (firstHalf->data != secondHalf->data)
            {
                isPalindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Restore the second half
        reverse(copySecondHalf);

        if (isPalindrome)
        {
            cout << "Yes, it's a palindrome Linked List\n";
        }
        else
        {
            cout << "No, it's not a palindrome Linked List\n";
        }
    }

    Node *createNode(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = NULL;
        newNode->data = data;
        return newNode;
    }
    Node *insertAtBegining(Node *head, int data)
    {
        Node *newNode = createNode(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    void print(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    List l;
    Node *head = nullptr;

    head = l.insertAtBegining(head, 10);
    head = l.insertAtBegining(head, 20);
    head = l.insertAtBegining(head, 30);
    head = l.insertAtBegining(head, 30);
    head = l.insertAtBegining(head, 20);
    head = l.insertAtBegining(head, 10);
    l.print(head);
    // l.palandrome(head);
    // head = l.reverse(head);
    l.palandrome1(head);
    l.print(head);
    return 0;
}