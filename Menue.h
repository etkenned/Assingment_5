#include "FacultyTree"
#include "StudentTree"

class Menue
{
  public:
    Menue();
    ~Menue();

    void printStudents();
    void printFaculty();
    void findStudent(int id);
    void findFaculty(int id);
    void studentAdvisor(int id);
    void facultyAdvisee(int id);
    void addStudent();
    void deleteStudent(int id);
    void addFaculty();
    void deleteFaculty(int id);
    void changeStudentAdvisor(int sid, int fid);
    void removeFacultyAdvisee(int fid, int sid);
    void rollback();

  private:
    StudentTree sTree;
    FacultyTree fTree;
};
