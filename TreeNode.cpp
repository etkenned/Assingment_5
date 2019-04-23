#include "TreeNode.h"

TreeNode::TreeNode()
{
  left = NULL;
  right = NULL;
}
TreeNode::TreeNode(int k)
{
  left = NULL;
  right = NULL;
  key = k;
}
TreeNode::~TreeNode()
{
  //run through and delete everything
}
