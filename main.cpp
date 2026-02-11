#include <iostream>
#include <cstring>    // For strcmp()
#include <random>
#include <fstream>

//#include <cmath>
//#include <vector>
//#include <iomanip>

using namespace std;

//Student info
struct student{
  char firstname[40];
  char lastname[40];
  int id;
  float gpa;
};

struct Node{
  student* info;
  Node* next;
  Node(student* s){
    info = s;
    next = NULL;
  }
};

//now put all student info into this hash
struct Hash{
  Node** table;
  int hashlen;

  Hash(int len){
    hashlen = len;
    table = new Node*[hashlen];

    //going thru and defining everything (as null)
    for (int i = 0; i<hashlen; i++){
      table[i] = NULL;
    }
  }
  ~Hash(){}

  indexinator(int id){
    return id % hashlen;
  }

  void add(student* s){
    int index = indexinator(s->id);
    Node* node = new Node(s);
    node->next = table[index];
    table[index] = node;
    }

  student* find(int studentid){
    int index = indexinator(studentid);
    while (table[index]->info != NULL){
      if(table[index]->info->id == studentid){
	return table[index]->info;
      }
      index = (index + 1)%hashlen;
    }
    return NULL;
  }
  /*need
    destructor
    find
    remove
   */
  void print(){
    cout << "List:"<<endl;
    for(int i=0;i<hashlen;i++){
      if (table[i] != NULL){
	cout << "      " << table[i]->info->firstname << ", " << table[i]->info->lastname << ", "  << table[i]->info->gpa << ", " << table[i]->info->id << endl;
      }
    }
  }
};

//defining functions

int main(){
  Hash h(100);
  char command[20] = "";

  //while the user hasn't quit the loop...
  while(strcmp(command, "quit") != 0){
    //figure out what they want to do
    cout<< endl << "What would you like to do? ";
    cin >> command;

    if(strcmp(command, "add") == 0){
      //student* s new student();
      //s->firstname;
      
      //random GPA
      float r3 = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4.00)));
      float randGPA = round(r3*100.0)/100.0;

      //random ID
      int randID=0;
      while (randID < 100000){
	randID = rand() % 1000000;
      }

      fstream f("first.txt"); //open your word list
      for(int i = 1; 1<= 6; i++){
      if(f){
      char buffer[150];
      f.getline(buffer, sizeof(buffer));
      cout <<buffer;
      //f.close();
      }
      }
      cout << randGPA << ", " << randID;
      //h.add(s);
    }
    else if(strcmp(command, "manualAdd") == 0){
      student* s = new student();
      cout << "     First Name: ";
      cin >> s->firstname;
      cout << "     Last Name: ";
      cin >> s->lastname;
      cout << "     GPA: ";
      cin >> s->gpa;
      cout << "     Student ID: ";
      cin >> s->id;
      h.add(s);
      
    }else if(strcmp(command, "print") == 0){
      h.print();
      
    }else if(strcmp(command, "quit") != 0) {
      cout << "That is not a valid command" << endl << "The valid commands are: ADD, DELETE, PRINT, or QUIT" << endl;
    }
  }
  
  cout << "Bye bye!!!";
  /*
  for (student* s : bigstruct){
    delete s;
  }
  bigstruct.clear();
  */
  return 0;
}


/*


void add(vector<student*>& bigstruct)
{
  cout << "You just added a student to the repository" << endl;
  
      student* littlestruct = new student();

      cout << "What is the student's first name?" << endl;
      cin >> littlestruct->firstname;

      cout << "What is the student's last name?" << endl;
      cin >> littlestruct->lastname;

      cout << "What is the student's ID?" << endl;
      cin >> littlestruct->id;

      cout << "What is the student's GPA?" << endl;
      cin >> littlestruct->gpa;

      bigstruct.push_back(littlestruct);

      //  return bigtest;
}

void print(vector<student*>& bigstruct)
{
  for (size_t i = 0; i < bigstruct.size(); ++i) {
    cout << "Name: " << bigstruct[i]->firstname << " " << bigstruct[i]->lastname << ", Student ID: " << bigstruct[i]->id << ", Student's GPA: " << fixed << setprecision(2) << bigstruct[i]->gpa << endl;
  }
}

void remove(vector<student*>& bigstruct)
{
        int studentid;
      cout << "What is the ID of the student you would like to delete?" << endl;
      cin >> studentid;
      auto it = bigstruct.begin();
    while (it != bigstruct.end()) {
      if ((*it)->id == studentid) {
	delete *it;
            it = bigstruct.erase(it); // Erase the element and get a new iterator
            break; // Assuming only one element needs to be removed
        } else {
            ++it;
        }
    }
}


*/
