#include <iostream>
#include <vector>

using namespace std;

class Professor {
    private:
        string name;
        string surname;
        int age;
        float salary;
        string faculty;
        float loan;
    public:
        Professor(string name, string surname, int age, float salary, string faculty, float loan);
        ~Professor();
        virtual void getData();
        virtual void setData();
        string getName();
        string getSurname();
        int getAge();
        float getSalary();
        string getFaculty();
        float getLoan();
};

Professor :: Professor(string name = "", string surname = "", int age = 0, float salary = 0, string faculty = "", float loan = 0){
    this -> name = name;
    this -> surname = surname;
    this -> age = age;
    this -> salary = salary;
    this -> faculty = faculty;
    this -> loan = loan;
}

Professor :: ~Professor(){
    cout << "The program is over";
}

void Professor :: setData(){
    cout << "Name = ";
    string name;
    cin >> name;
    this -> name = name;
    cout << "Surname = ";
    string surname;
    cin >> surname;
    this -> surname = surname;
    cout << "Age = ";
    int age;
    cin >> age;
    this -> age = age;
    cout << "Salary = ";
    float salary;
    cin >> salary;
    this -> salary = salary;
    cout << "Faculty = ";
    string facultatea;
    cin >> facultatea;
    this -> faculty = facultatea;
    cout << "Loan = ";
    float loan;
    cin >> loan;
    this -> loan = loan;
}

void Professor :: getData(){
    cout << "\nName = " << name << "\nSurname = " << surname << "\nAge = " << age << "\nSalary = " << salary << "\nFaculty = " << faculty << "\nLoan = " << loan << '\n';
}

string Professor :: getName(){
    return name;
}

string Professor :: getSurname(){
    return surname;
}

int Professor :: getAge(){
    return age;
}

float Professor :: getSalary(){
    return salary;
}

string Professor :: getFaculty(){
    return faculty;
}

float Professor :: getLoan(){
    return loan;
}

class University : public Professor {
    private:
        int experience;
        string course;
    public:
        University(string name, string surname, int age, float salary, string faculty, float loan, int experience, string course);
        ~University();
        void setData();
        void getData();
        int getExperience();
        string getCourse();
};

University :: University(string name = "", string surname = "", int age = 0, float salary = 0, string faculty = "", float loan = 0, int experience = 0, string course = "") : Professor(name, surname, age, salary, faculty, loan){
    this -> experience = experience;
    this -> course = course;
}

University :: ~University(){
    cout << "The program is over";
}

void University :: setData(){
    Professor :: setData();
    cout << "Experience = ";
    int experience;
    cin >> experience;
    this -> experience = experience;
    cout << "Course = ";
    string course;
    cin >> course;
    this -> course = course;
}

void University :: getData(){
    Professor :: getData();
    cout << "Experience = " << experience << "\nCourse = " << course << '\n';
}

int University :: getExperience(){
    return experience;
}

string University :: getCourse(){
    return course;
}

class exProfessor : public Professor {
    private:
        int retirmentYear;
    public:
        exProfessor(string name, string surname, int age, float salary, string faculty, float loan, int retirmentYear);
        ~exProfessor();
        void setData();
        void getData();
        int getRetirmentYear();
};

exProfessor :: exProfessor(string name = "", string surname = "", int age = 0, float salary = 0, string faculty = "", float loan = 0, int retirmentYear = 0) : Professor(name, surname, age, salary, faculty, loan){
    this -> retirmentYear = retirmentYear;
}

exProfessor :: ~exProfessor(){
    cout << "The program is over";
}
void exProfessor :: setData(){
    Professor :: setData();
    cout << "Retirment year = ";
    int retirmentYear;
    cin >> retirmentYear;
    this -> retirmentYear = retirmentYear;
}

void exProfessor :: getData(){
    Professor :: getData();
    cout << "Retirment year = " << retirmentYear << '\n';
}

int exProfessor :: getRetirmentYear(){
    return retirmentYear;
}

class Assistant : public Professor {
    private:
        string professorName;
        int startYear;
        int endYear;
    public:
        Assistant(string name, string surname, int age, float salary, string faculty, float loan, string professorName, int startYear, int endYear);
        ~Assistant();
        void setData();
        void getData();
        string getProfessorName();
        int getStartYear();
        int getEndYear();
};

Assistant :: Assistant(string name = "", string surname = "", int age = 0, float salary = 0, string faculty = "", float loan = 0, string professorName = "", int startYear = 0, int endYear = 0) : Professor(name, surname, age, salary, faculty, loan){
    this -> professorName = professorName;
    this -> startYear = startYear;
    this -> endYear = endYear;
}

Assistant :: ~Assistant(){
    cout << "The program is over";
}

void Assistant :: setData(){
    Professor :: setData();
    cout << "Name of the University professor = ";
    string professorName;
    cin >> professorName;
    this -> professorName = professorName;
    cout << "The beginning of the period = ";
    int startYear;
    cin >> startYear;
    this -> startYear = startYear;
    cout << "The end of the period = ";
    int endYear;
    cin >> endYear;
    this -> endYear = endYear;
}

void Assistant :: getData(){
    Professor :: getData();
    cout << "Name of the University professor = " << professorName << "\nThe beginning of the period = " << startYear << "\nThe end of the period = " << endYear << '\n';
}

string Assistant :: getProfessorName(){
    return professorName;
}

int Assistant :: getStartYear(){
    return startYear;
}

int Assistant :: getEndYear(){
    return endYear;
}

class Menu{
    private:
        vector<Professor*> arr;
    public:
        void process();
        void database();
        void income();
        void under4000();
        void retirmentAge();
        void debt();
        void facultyTeachers();
        void retired5();
        void assistant2021();
};

void Menu :: process(){
    cout << "Number of objects = ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        Professor* p;
        string s;
        cout << "\nObject type " << i + 1 << " = ";
        cin >> s;
        if(s == "University"){
            p = new University;
            p -> setData();
            arr.push_back(p);
        }
        else
            if(s == "Ex-Professor"){
                p = new exProfessor;
                p -> setData();
                arr.push_back(p);
            }
            else
                if(s == "Assistant"){
                    p = new Assistant;
                    p -> setData();
                    arr.push_back(p);
                }
                else{
                    cout << "Wrong input! Try University, Ex-Professor or Assistant!";
                    i--;
                }
    }
}

void Menu :: database(){
    cout << "\n\nThe Database has the following objects :\n";
    for(auto it : arr)
        it -> getData();
}

void Menu :: income(){
    cout << "\n\nMonthly salary :\n";
    for(auto it : arr)
        cout << it -> getName() << " " << it -> getSurname() << " = " << it -> getSalary() << " RON\n";

}

void Menu :: under4000(){
    cout << "\n\nEmployees with a salary less thann 4000 RON :\n";
    for(auto it : arr)
        if(it -> getSalary() < 4000)
            cout << it -> getName() << " " << it -> getSurname() << " = " << it -> getSalary() << " RON\n";
}

void Menu :: retirmentAge(){
    cout << "\n\nTeachers of retirment age :\n";
    for(auto it : arr)
        if(it -> getAge() > 65)
            cout << it -> getName() << " " << it -> getSurname() << '\n';
}

void Menu :: debt(){
    cout << "\n\nPeople with loans and exact amounts :\n";
    for(auto it : arr)
        if(it -> getLoan() > 0)
            cout << it -> getName() << " " << it -> getSurname() << " = " << it -> getLoan() << " RON\n";
}

void Menu :: facultyTeachers(){
    cout << "\n\nTeachers at the Faculty of Mathematics and Computer Science, University of Bucharest : \n";
    for(auto it : arr)
        if(it -> getFaculty() == "Mathematics-ComputerScience")
            cout << it -> getName() << " " << it -> getSurname() << '\n';
}

void Menu :: retired5(){
    cout << "\n\nTeachers who have retired in the last 5 years : \n";
    for(auto it : arr)
        if(exProfessor *xp = dynamic_cast<exProfessor*>(it)){
            int an = xp -> getRetirmentYear();
            if(an >= 2015)
                cout << xp -> getName() << " " << xp -> getSurname() << '\n';
        }
}

void Menu :: assistant2021(){
    cout << "\n\nAssistants whose employments contract expires in 2021 : \n";
    for(auto it : arr)
        if(Assistant *a = dynamic_cast<Assistant*>(it)){
            int an = a -> getEndYear();
            if(an == 2021)
                cout << a -> getName() << " " << a -> getSurname() << '\n';
        }
}

int main(){
    Menu X;
    X.process();
    X.database();
    X.income();
    X.under4000();
    X.retirmentAge();
    X.debt();
    X.facultyTeachers();
    X.retired5();
    X.assistant2021();
    return 0;
}
