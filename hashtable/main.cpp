/*

 */

#include "student.h"
#include "node.h"
#include <fstream>
#include <random>

//add a student based on student id in ascending order
void addStudent(Node** hashTable) {
  //hash

  
}

//print all students in the list
void print() {
  
}

//delete a student given their student id
void deleteStudent() {
  
}

int hash(std::string name, int size) {
  unsigned int h = 0;
  int factor = 53;
  int factorpow = 1;
  int mod = 1e9 + 9;

  for (char c : name) {
    h = (h + (c - 'a' + 1)*factorpow) % mod;
    factorpow = (factorpow*factor) % mod;
  }
  std::cout << h % size << "\n";

}
//randomly generate the given number of students
void generate(int num, int id) {
  for (int i = 0; i < num; ++i) {
    char fname[20], lname[20];
    int line = (rand() % 10000);
    std::ifstream ifs;

    //get first name
    ifs.open("fnames.txt");
    for (int j = 0; j < line-1; ++j) {
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ifs >> fname;
    ifs.close();

    //get last name
    ifs.open("lnames.txt");
    for (int j = 0; j < line-1; ++j) {
      ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    ifs >> lname;
    ifs.close();
    //int gpa = std::uniform_real_distribution<> dis(0, 4);

    std::cout << fname << " " << lname << "\n";
    hash(fname, 200);
  }
}


  



int main() {
  srand(time(NULL));
  
  char input[10];
  Node* head = NULL;

  Node* hashTable[200];


  
  while (true) {
    std::cout << "Enter a command: (ADD, DELETE, PRINT, GEN, QUIT)\n";
    std::cin >> input;

    if (strncmp(input, "QUIT", 4) == 0) {
      //delete all remaining nodes if list isn't empty
      if (head != NULL) {
	Node* current = head;
	Node* prev;
	while (current->getNext() != NULL) {
	  prev = current;
	  current = current->getNext();
	  delete prev;
	}
	delete current;
      }
      
      break;
    }

    if (strncmp(input, "GEN", 3) == 0) {
      int num;
      std::cout << "Enter the number of students to be generated:\n";
      std::cin >> num;
      generate(num, 1);
    }
    
    /*if (strncmp(input, "ADD", 3) == 0) {
      //get student info
      char fname[10], lname[10];
      int id;
      float gpa;
      std::cout << "Enter the student's first name:\n";
      std::cin >> fname;
      std::cout << "Enter the student's last name:\n";
      std::cin >> lname;
      std::cout << "Enter the student's id number:\n";
      std::cin >> id;
      std::cout << "Enter the student's GPA:\n";
      std::cin >> gpa;

      //initialize student and node
      Student* news = new Student(fname, lname, id, gpa);
      Node* newn = new Node(news);
      
      //first node to be added
      if (head == NULL) head = newn;
      //add normally
      else addStudent(head, head, newn);
      std::cout << "Student " << id << " has been added to the list.\n";
    }
    else if (head == NULL) {
      std::cout << "No students could be found.\n";
      continue;
    }

    if (strncmp(input, "PRINT", 5) == 0) {
      print(head);
    }

    if (strncmp(input, "DELETE", 6) == 0) {
      int id;
      std::cout << "Enter the id of the student to be deleted:\n";
      std::cin >> id;
      deleteStudent(head, head, id);
      std::cout << "Student " << id << " has been removed from the list.\n";
    }

    if (strncmp(input, "AVERAGE", 7) == 0) { //to 2 decimals
      std::cout << "The average GPA is " << std::fixed << std::setprecision(2) << average(head, 0, 0) << "\n";
      }*/

  }
  
  return 0;
}
