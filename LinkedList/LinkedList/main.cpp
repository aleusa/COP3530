#include <iostream>
#include <string>

using namespace std;

class LinkedList{
public:
    // Creating a Node class
    struct Node{
        // Variables
        string line;
        Node *next;
        Node *prev;
        // Constructors
        Node(string value){
            line = value;
            next = nullptr;
            prev = nullptr;
        }
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        //Function
        void changeData(string text){
            line = text;
        }
    };
    // Variables
    unsigned int count;
    Node *head;
    Node *tail;
    // Constructor
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // Destructor
    ~LinkedList(){
        Node* temp = head;
        while(temp){
            head = head->next;
            delete temp;
            temp = head;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // Functions
    void insertEnd(string text){
        if(head == nullptr){
            head = new Node(text);
            tail = head;
        }
        else{
            Node *temp = tail;
            tail = new Node(text);
            temp->next = tail;
            tail->prev = temp;
        }
        count++;
    }
    void insert(string text, unsigned int index){
        unsigned int tempIndex = 1;
        Node *temp;
        Node *temp2 = head;
        if(index > count + 1){}
        else if(index == 1){
            if(head == nullptr){
                head = new Node(text);
                tail = head;
            }
            else{
                temp = head;
                head = new Node(text);
                head->next = temp;
                temp->prev = head;
            }
            count++;
        }
        else{
            while(temp2->next != nullptr){
                tempIndex++;
                temp = temp2->next;
                if(tempIndex == index){
                    Node* newNode = new Node(text);
                    temp2->next = newNode;
                    temp->prev = newNode;
                    newNode->prev = temp2;
                    newNode->next = temp;
                    count++;
                    break;
                }
                temp2 = temp;
            }
            if(tempIndex + 1 == index){
                temp = tail;
                tail = new Node(text);
                temp->next = tail;
                tail->prev = temp;
                count++;
            }
        }
    }
    void deleteLine(unsigned int index){
        unsigned int tempIndex = 1;
        Node *temp;
        Node *temp2;
        if(index > count){}
        else if(index == 1){
            if(head->next != nullptr){
               temp = head->next;
               delete head;
               head = temp;
               head->prev = nullptr;
                count--;
            }
            else{
               head = nullptr;
               tail = nullptr;
            }
        }
        else{
            temp = head;
            while(head->next != nullptr){
                tempIndex++;
                temp2 = head->next;
                if(tempIndex == index){
                    Node *temp3 = temp2->next;
                    Node *temp4 = temp2->prev;
                    head = temp2;
                    delete head;
                    head = temp4;
                    if(temp3 != nullptr){
                        temp3->prev = head;
                        head->next = temp3;
                    }
                    else{
                        head->next = nullptr;
                    }
                }
                else{
                    head = temp2;
                }
                count--;
            }
        }
        head = temp;
    }
    void edit(string text, unsigned int index){
        unsigned int tempIndex = 1;
        Node *temp;
        Node *temp2 = head;
        if(index > count){}
        else if(index == 1){
            head->changeData(text);
        }
        else{
            while(temp2->next != nullptr){
                tempIndex++;
                temp = temp2->next;
                if(tempIndex == index){
                    temp->changeData(text);
                    break;
                }
                temp2 = temp;
            }
        }
    }
    void print(){
        if(head == nullptr){
            cout << "Empty" << endl;
        }
        else{
            int index = 1;
            Node *temp;
            Node *temp2 = head;
            cout << index << " " << head->line << endl;
            while(temp2->next != nullptr){
                index++;
                temp = temp2->next;
                cout << index << " " << temp->line << endl;
                temp2 = temp;
            }
        }
    }
    void search(string text){
        if(head == nullptr){
            cout << "not found" << endl;
        }
        else{
            Node *temp;
            Node *temp2 = head;
            int index = 1;
            if(temp2->line.find(text) != string::npos){
                cout << index << " " << head->line << endl;
            }
            while(temp2->next != nullptr){
                index++;
                temp = temp2->next;
                if(temp->line.find(text) != string::npos){
                    cout << index << " " << temp->line << endl;
                }
                temp2 = temp;
            }
        }
    }
    void quit(){
        exit(0);
    }
};
int main()
{
    LinkedList document;
    while(true){
        string input;
        unsigned int index;
        cin >> input;
        if(input == "insert"){
            getline(cin,input, ' ');
            getline(cin,input, ' ');
            index = stoi(input);
            getline(cin, input, '"');
            getline(cin, input, '"');
            document.insert(input,index);
            getline(cin, input, '\n');
        }
        else if(input == "insertEnd"){
            getline(cin, input, '"');
            getline(cin, input, '"');
            document.insertEnd(input);
            getline(cin, input, '\n');
        }
        else if(input == "print"){
            document.print();
        }
        else if(input == "quit"){
            document.quit();
        }
        else if(input == "edit"){
            getline(cin,input, ' ');
            getline(cin,input, ' ');
            index = stoi(input);
            getline(cin, input, '"');
            getline(cin, input, '"');
            document.edit(input, index);
            getline(cin, input, '\n');
        }
        else if(input == "delete"){
            getline(cin,input, ' ');
            getline(cin,input, '\n');
            index = stoi(input);
            document.deleteLine(index);
        }
        else if(input == "search"){
            getline(cin, input, '"');
            getline(cin, input, '"');
            document.search(input);
            getline(cin, input, '\n');
        }
        else{
            //cout << input;
            exit(0);
        }
    }
}
