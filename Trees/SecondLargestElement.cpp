/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
// int getmaxelement(TreeNode<int>* root,int maxele){

//     if(root->data>maxele){
//         maxele = root->data;
//     }
//     for(int i=0;i<root->children.size();i++){
//         return getmaxelement(root->children[i], maxele);
//     }
//     return maxele;
// }

// TreeNode<int>* getAns(TreeNode<int>* root,TreeNode<int>* ans,int maxele){
//     if(root==NULL) return NULL;

//     if(root->data > ans->data && root->data!=maxele){
//         ans=root;
//     }

//     for(int i=0;i<root->children.size();i++){
//         return getAns(root->children[i], ans, maxele);
//     }

//     return ans;

// }

// TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
//     int maxele=0;int seclarge = 0;
//     TreeNode<int>* ans=root;
//     maxele = getmaxelement(root,maxele);
//     ans = getAns(root,ans,maxele);
//     return ans;
// }

TreeNode<int> *helper(TreeNode<int> *root)
{
  TreeNode<int> *maxNode = root;
  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *newNode = helper(root->children[i]);
    if (newNode->data > maxNode->data)
    {
      maxNode = newNode;
    }
  }
  return maxNode;
}

TreeNode<int> *helperforSecondMax(TreeNode<int> *root, TreeNode<int> *maxele)
{
  TreeNode<int> *secMaxNode = root;
  for (int i = 0; i < root->children.size(); i++)
  {
    TreeNode<int> *newNode = helperforSecondMax(root->children[i], maxele);
    if (newNode->data > secMaxNode->data && newNode->data != maxele->data)
    {
      secMaxNode = newNode;
    }
  }
  return secMaxNode;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
  TreeNode<int> *maxele = helper(root);
  TreeNode<int> *secondmaxele = helperforSecondMax(root, maxele);
  return secondmaxele;
}

/*void getMaxEle(TreeNode<int>* root,int &maxele){
    if(root==NULL) return;
    maxele = max(root->data,maxele);
    for(int i=0;i<root->children.size();i++){
        getMaxEle(root->children[i], maxele);
    }
}

void getAns(TreeNode<int>* root, TreeNode<int>* &ansNode,int secmax,int maxele){
    if(root==NULL) return;
    if(root->data > secmax && root->data!=maxele){
        ansNode = root;
        secmax = root->data;
    }
    for(int i=0;i<root->children.size();i++){
        return getAns(root->children[i], ansNode, secmax, maxele);
    }
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    int maxele = 0, secmax = 0;
    TreeNode<int>* ansNode = NULL;
    getMaxEle(root,maxele);
    getAns(root,ansNode,secmax,maxele);
    return ansNode;
}*/