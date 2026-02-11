#include <iostream>
#include <cstring>    // For strcmp()
#include <cmath>
#include <vector>
#include <iomanip>

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
  student** table;
  int hashlen;

  Hash(int len){
    hashlen = len;
    table = new student*[hashlen];

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
    s=table[index];
    cout << table[index]<< endl << index << endl;
  }

  student* find(int studentid){
    int index = indexinator(studentid);
    while (table[index] != NULL){
      if(table[index]->id == studentid){
	return table[index];
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
    for(int i=0;i++;i<hashlen){
      cout<<table[i]<<endl;
    }
  }
};

//defining functions
void add(vector<student*>& bigtest);
void print(vector<student*>& bigtest);
void remove(vector<student*>& bigtest);

int main(){
  Hash h(100);
  //student s;
  char command[20] = "";

  //define vector
  //  vector<student*> bigstruct;
  
  //while the user hasn't quit the loop...
  
  while(strcmp(command, "QUIT") != 0){
    //figure out what they want to do
    cout<< endl << "What would you like to do?" << endl;
    cin >> command;
    
    if(strcmp(command, "ADD") == 0){
      student* s = new student();
      strcpy(s->firstname, "fds");
      //cout << "lastname: ";
      strcpy(s->lastname, "ghs");
      s->gpa = 3.6;
      cin >> s->id;
      h.add(s);
      
    }else if(strcmp(command, "PRINT") == 0){
      h.print();
      
      //    }else if(strcmp(command, "DELETE") == 0){
      //remove(bigstruct);
      
    }else if(strcmp(command, "QUIT") != 0) {
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
