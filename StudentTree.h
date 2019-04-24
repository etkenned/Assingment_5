class StudentTree
{
  public:
    StudentTree();
    virtual ~StudentTree();

    void insert(int id);
    bool contains(int id);//aka search
    bool deleteNode(int id);
    bool isEmpty();
    bool deleteRec();
    /*
    StudentNode* getSuccessor(StudentNode* d);
    StudentNode* getMin();
    StudentNode* getMax();
    */
  private:
    StudentNode *root;
};
