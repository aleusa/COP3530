#include <iostream>
#include <string>

using namespace std;

//
class LinkedList{
public:
    // Creating a Node class
    struct Node
    {
        // Variables
        string data;
        Node *next;
        Node *prev;
        // Constructors
        Node(string value)
        {
            data = value;
            next = nullptr;
            prev = nullptr;
        }
        Node()
        {
            next = nullptr;
            prev = nullptr;
        }
        //Function
        void changeData(string text)
        {
            data = text;
        }
    };
    // Variables
    unsigned int count;
    Node *head;
    Node *tail;
    // Constructor
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // Destructor
    ~LinkedList()
    {
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
    // Add node at the end of the linked list
    void addTail(string data)
    {
        if(head == nullptr){
            head = new Node(data);
            tail = head;
        }
        else{
            Node *temp = tail;
            tail = new Node(data);
            temp->next = tail;
            tail->prev = temp;
        }
        count++;
    }
    // Add node at the specific index
    void insertAt(string data, unsigned int index)
    {
        unsigned int tempIndex = 1;
        Node *temp;
        Node *temp2 = head;
        if(index > count + 1){}
        else if(index == 1){
            if(head == nullptr){
                head = new Node(data);
                tail = head;
            }
            else{
                temp = head;
                head = new Node(data);
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
                    Node* newNode = new Node(data);
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
                tail = new Node(data);
                temp->next = tail;
                tail->prev = temp;
                count++;
            }
        }
    }
    // Remove the node located in that index
    void removeAt(unsigned int index)
    {
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
    // Change the data of the node in the index location by a new one
    void edit(string data, unsigned int index)
    {
        unsigned int tempIndex = 1;
        Node *temp;
        Node *temp2 = head;
        if(index > count){}
        else if(index == 1){
            head->changeData(data);
        }
        else{
            while(temp2->next != nullptr){
                tempIndex++;
                temp = temp2->next;
                if(tempIndex == index){
                    temp->changeData(data);
                    break;
                }
                temp2 = temp;
            }
        }
    }
    // Print the data of all the nodes in the linked list
    void printAll()
    {
        if(head == nullptr){
            cout << "Empty" << endl;
        }
        else{
            int index = 1;
            Node *temp;
            Node *temp2 = head;
            cout << index << " " << head->data << endl;
            while(temp2->next != nullptr){
                index++;
                temp = temp2->next;
                cout << index << " " << temp->data << endl;
                temp2 = temp;
            }
        }
    }
    // Find all the nodes containing the specific data
    void findAll(string data)
    {
        if(head == nullptr){
            cout << "not found" << endl;
        }
        else{
            Node *temp;
            Node *temp2 = head;
            bool found = false;
            int index = 1;
            if(temp2->data.find(data) != string::npos){
                cout << index << " " << head->data << endl;
//                if(temp2->data.length() == 80 && temp2->next != nullptr){
//                    cout << index + 1 << " " << temp2->next->data << endl;
//                }
                found = true;
            }
            while(temp2->next != nullptr){
                index++;
                temp = temp2->next;
                if(temp->data.find(data) != string::npos){
                    cout << index << " " << temp->data << endl;
//                    if(temp->data.length() == 80 && temp->next != nullptr){
//                        cout << index + 1 << " " << temp->next->data << endl;
//                    }
                    found = true;
                }
                temp2 = temp;
            }
            if(!found){
                cout << "not found" << endl;
            }
        }
    }
};
// Line editor class
class LineEditor{
    LinkedList list;
public:
    // insert a line at the end of the document
    void insertEnd(string text){
        if(text.length() <= 80){
            list.addTail(text);
        }
        else{
            int count = 1;
            while (count <= text.length() / 80){
                if(count == 1){
                    list.addTail(text.substr(0, 80));
                }
                if(text.length() - (80 * count) <= 80){
                    list.addTail(text.substr(80 * count, text.length() - (80 * count)));
                }
                else{
                    list.addTail(text.substr(80 * count, 80));
                }
                count++;
            }
        }
    }
    // insert a line in the specific index of the document
    void insert(string text, unsigned int index)
    {
        if(text.length() <= 80){
            list.insertAt(text, index);
        }
        else{
            int count = 1;
            while (count <= text.length() / 80){
                if(count == 1){
                    list.insertAt(text.substr(0, 80), index);
                }
                if(text.length() - (80 * count) <= 80){
                    list.insertAt(text.substr(80 * count, text.length() - (80 * count)), index + count);
                }
                else{
                    list.insertAt(text.substr(80 * count, 80), index + count);
                }
                count++;
            }
        }
    }
    // delete a line in the document at the specific index
    void deleteLine(unsigned int index){
        list.removeAt(index);
    }
    // change the line in the index by a new line
    void editLine(string text, unsigned int index)
    {
        if(text.length() <= 80){
            list.edit(text, index);
        }
        else{
            int count = 1;
            while (count <= text.length() / 80){
                if(count == 1){
                    list.edit(text.substr(0, 80), index);
                }
                if(text.length() - (80 * count) <= 80){
                    list.insertAt(text.substr(80 * count, text.length() - (80 * count)), index + count);
                }
                else{
                    list.insertAt(text.substr(80 * count, 80), index + count);
                }
                count++;
            }
        }
    }
    // print all the lines in the document
    void print(){
        list.printAll();
    }
    // search in all the documents for lines containing the text
    void search(string text){
        list.findAll(text);
    }
    // quit the program
    void quit(){
        exit(0);
    }
};
int main()
{
    LineEditor document;
    while(true)
    {
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
        else if(input == "edit"){
            getline(cin,input, ' ');
            getline(cin,input, ' ');
            index = stoi(input);
            getline(cin, input, '"');
            getline(cin, input, '"');
            document.editLine(input, index);
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
        else if(input == "print"){
            document.print();
        }
        else if(input == "quit"){
            document.quit();
        }
        else{
            exit(0);
        }
    }
}
