class StudentNode {
  public:
    StudentNode();
    StudentNode(int key);
    virtual ~StudentNode();

    int studentID;
    String name;
    String level;
    String major;
    double GPA;
    int advisorID;
    StudentNode *left;
    StudentNode *right;
};
