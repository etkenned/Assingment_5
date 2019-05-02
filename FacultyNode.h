class FacultyNode {
  public:
    FacultyNode();
    FacultyNode(int f, string n, string l, string d, int[] a);
    virtual ~FacultyNode();

    int facultyID;
    string name;
    string level;
    string department;
    int[] adviseesID;
    FacultyNode *left;
    FacultyNode *right;
};
