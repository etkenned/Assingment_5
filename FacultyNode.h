class FacultyNode {
  public:
    FacultyNode();
    FacultyNode(int key);
    virtual ~FacultyNode();

    int facultyID;
    string name;
    string level;
    string department;
    int[] adviseesID;
    FacultyNode *left;
    FacultyNode *right;
};
