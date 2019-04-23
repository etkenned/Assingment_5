class TreeNode {
  public:
    TreeNode();
    TreeNode(int key);
    virtual ~TreeNode();

    int key;
    TreeNode *left;
    TreeNode *right;
};
