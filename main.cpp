// COMSC-210 | Lab 18: Movie Reviews| Aidan Woodcock | 2025-10-05
// IDE used: Visual Studio Code

#include <iostream>

using namespace std;

struct reviewNode
{
    string comment; 
    float rating;
    reviewNode* next;
};

// function prototypes
void addFront(reviewNode*& head, const string& comment, int rating);
void addTail(reviewNode*& head, const string& comment, int rating);

int main () {
reviewNode* head = nullptr;
int choice;
float rating;
string comment;
char ans;
cout << "Which linked list method should we use?";
cout << "\n [1] New nodes are added at the head of the linked list";
cout << "\n [2] New nodes are added at the tail of the linked list \n" << endl;
cin >> choice;
cin.ignore(); 
cout << "Choice: " << choice << endl;
if(choice != 1 && choice != 2) {
    cout << "Invalid choice. Please enter 1 or 2: ";
    cin >> choice;
    cin.ignore();
}
while(choice == 1 || choice == 2) {
    cout << "Enter review rating 0-5: "; 
    cin >> rating;
    cin.ignore();
    cout << "Enter review comment: ";
    getline(cin, comment);
    cin.ignore();
        if(choice == 1) {
            addFront(head, comment, rating);
        }else if(choice == 2) {
            addTail(head, comment, rating);
        }
    cout << "Enter another review? Y/N: ";
    cin >> ans;
    cin.ignore();
    if(ans == 'N' || ans == 'n') {
        break;  
    }else if(ans == 'Y' || ans == 'y') {
        continue; 
        }
}
cout << "\nOutputting all reviews:\n" << endl;
reviewNode* current = head;
while(current) {
    cout << "Rating: " << current->rating << endl;
    cout << "Comment: " << current->comment << endl;
    cout << "Average: " << (current->rating / 5) * 100 << endl;

    current = current->next;
}
// Free allocated memory
current = head;
while (current) {
    reviewNode* temp = current;
    current = current->next;
    delete temp;
}
head = nullptr;

return 0;
}
// function definitions
void addFront(reviewNode*& head, const string& comment, int rating) {
    reviewNode *n = new reviewNode;
    n->comment = comment;
    n->rating = rating;
    n->next = head;
    head = n;
}
void addTail(reviewNode*& head, const string& comment, int rating) {
    reviewNode *n = new reviewNode;
    n->comment = comment;
    n->rating = rating;
    n->next = nullptr;
    if (!head) {  // if the list is empty, add to front
        head = n;
        return;
    }
    reviewNode *current = head;
    while (current->next)  // traverse to the end of the list
        current = current->next;
    current->next = n;  // link the new node at the end
}