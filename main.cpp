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
    remove
   */

  void add(student* s){
    int index = indexinator(s->id);
    Node* node = new Node(s);
    node->next = table[index];
    table[index] = node;
  }

  void print(){
    cout << "List:"<<endl;
    for(int i=0;i<hashlen;i++){
      Node* node = table[i];
      while (node != NULL){
	cout << "      First Name: " << node->info->firstname << endl;
	cout << "      Last Name:  " << node->info->lastname << endl;
	cout << "      GPA:        " << node->info->gpa << endl;
	cout << "      ID:         " << node->info->id << endl << endl;

	node = node->next;
      
      }
    }
  }

  void remove(int delID){
    int index = indexinator(delID);
    cout << "An error has occured, you are unable to remove that...item" << endl;
  }
};

//defining functions

int main(){
  srand(time(NULL));
  Hash h(100);
  char command[20] = "";
  int listlen=20; //number of names there are in the lists
  
  //while the user hasn't quit the loop...
  while(strcmp(command, "quit") != 0){
    //figure out what they want to do
    cout<< endl << "What would you like to do? ";
    cin >> command;

    if(strcmp(command, "add") == 0){
      int copies;
      cout << "How many names? ";
      cin >> copies;

      for (int j=0;j<copies;j++){
	student* s = new student();
	s->firstname;
      
	//random GPA
	float r3 = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(4.00)));
	float randGPA = round(r3*100.0)/100.0;

	//random ID
	int randID=0;
	while (randID < 100000){
	  randID = rand() % 1000000;
	}

      
	//random first name
	fstream f("first.txt"); //open your word list
	//the location of the random firstname you are using
	int firstloc = rand() % listlen;
	char buffer[150];
	for(int i = 1; i<= firstloc; i++){
	  if(f){
	    f.getline(buffer, sizeof(buffer));
	  }
	}

	//random last name
	fstream l("last.txt"); //open your word list
	//the location of the random firstname you are using
	int lastloc = rand() % listlen;
	char otherbuffer[150];
	for(int i = 1; i<= lastloc; i++){
	  if(l){
	    l.getline(otherbuffer, sizeof(otherbuffer));
	  }
	}
	strcpy(s->firstname, buffer);
	strcpy(s->lastname, otherbuffer);
	s->gpa=randGPA;
	s->id=randID;
	//cout << randGPA << ", " << randID << ", " <<buffer << endl << " " << otherbuffer << endl;

	h.add(s);

      }
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
      
    }else if(strcmp(command, "delete") == 0){
      int delID;
      cout << "What is the ID of the student you would like to...delete? ";
      cin >> delID;
      h.remove(delID);
    }else if(strcmp(command, "quit") != 0) {
      cout << "That is not a valid command" << endl << "The valid commands are: add, manualAdd, delete, print, or quit" << endl;
    }
  }
  
  cout << "Bye bye!!!";
  
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
