#include "StudentNode.h"
class StudentTree
{
  public:
    StudentTree();
    virtual ~StudentTree();

    void insert(int s, string n, string l, string m, double g, int a);
    void print();
    void recPrint(StudentNode * node);
    void saveTree();
    void recSave(StudentNode * node);
    bool contains(int id);
    bool isEmpty();
    bool deleteNode(StudentNode * node);
    bool deleteRec(int id);
    void changeAdvisor(int sid, int fid);


    StudentNode* getSuccessor(StudentNode* d);

  private:
    StudentNode *root;
};
