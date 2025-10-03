// COMSC-210 | Lab 18: Movie Reviews| Aidan Woodcock | 2025-10-05
// IDE used: Visual Studio Code

#include <iostream>

using namespace std;

struct reviewNode
{
    string comment; 
    int rating;
    reviewNode* next;
};

// function prototypes
void addFront(reviewNode*& head, const string& comment, int rating);
void addTail(reviewNode*& head, const string& comment, int rating);

int main () {
reviewNode* head = nullptr;
cout << "Which linked list method should we use?";
cout << "\n [1] New nodes are added at the head of the linked list";
cout << "\n [2] New nodes are added at the tail of the linked list \n" << endl;



    return 0;
}
