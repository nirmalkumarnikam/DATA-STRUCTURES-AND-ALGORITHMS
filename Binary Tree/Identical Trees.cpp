/*
    Algo:
    1) go to each node and check if both nodes are (    NULL NULL return 1
                                                        Node NULL return 0
                                                        NULL Node return 0
                                                        Node1data = Node2data return 1   )
    2) move to next nodes ie left and right;
*/

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL)return 1;
        if(r1!=NULL && r2==NULL)return 0;
        if(r1==NULL && r2!=NULL)return 0;
        if(r1->data != r2->data)return 0;
        
        
        if(r1->data == r2->data){
            return isIdentical(r1->left , r2->left) && 
                    isIdentical(r1->right, r2->right) ;
        }else{
            return 0;
        }
    }
};
