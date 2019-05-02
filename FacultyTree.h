#include "FacultyNode.h"
class FacultyTree
{
  public:
    FacultyTree();
    virtual ~FacultyTree();

    void insert(int f, string n, string l, string d, int[] a);
    void print();
    void recPrint(FacultyNode * node);
    void saveTree();
    void recSave(FacultyNode * node);
    bool contains(int id);
    bool isEmpty();
    bool deleteNode(FacultyNode * node);
    bool deleteRec(int id);


    FacultyNode* getSuccessor(FacultyNode* d);

  private:
    FacultyNode *root;
};
