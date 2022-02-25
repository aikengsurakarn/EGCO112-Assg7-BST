// An integer binary search tree

typedef struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}TreeNode; // end structure treeNode 
        
typedef TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size,depth;
	TreeNodePtr root;
}BST;

// prototypes
void insertNode( BST *, int );

int depth = 0;
int i;

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0;
  
	new_node =(TreeNodePtr) malloc(sizeof( TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(!b->root)	b->root=new_node;
		else {
      depth = 0;
      while(!inserted){
        if(value <= t->data){
          if(t->leftPtr ==NULL){
            t->leftPtr=new_node;
            inserted=1;
          }
          else t=t->leftPtr;
        }
	     else{
           if(t->rightPtr ==NULL){
            t->rightPtr=new_node;
            inserted=1;
          }
          else t=t->rightPtr;
       }
        depth++;
      }//end while		
     }//end else;
     b->size++;
    }
  
}//end function
void preOrder( TreeNodePtr treePtr )
{ 

  // C- L -R
  // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      printf("%3d", treePtr->data) ;  //print the value 
     preOrder( treePtr->leftPtr ); //Recursion to the left
       preOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if 
}


void postOrder( TreeNodePtr treePtr )
{

  //  L -R -C
  // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      postOrder( treePtr->leftPtr ); //Recursion to the left
       postOrder( treePtr->rightPtr ); //Recursion to the right
     printf("%3d", treePtr->data) ;  //print the value 
   } // end if 
}


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
       printf("%3d", treePtr->data) ;  //print the value 
       inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void tree( TreeNodePtr treePtr, int x )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {   
     x = x+1;
  tree( treePtr->rightPtr, x ); //Recursion to the right
  for (i=0;i<x-1;i++)
    {
      printf("\t");
    }
  printf("%3d\n", treePtr->data) ;  //print the value 
  tree( treePtr->leftPtr, x ); //Recursion to the left
   } // end if                          
} // end


void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   (*t)=(TreeNodePtr) malloc(sizeof( TreeNode));
	 if(t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
	(*t)->data=value;
   }
  }
  else{
     if((*t)->data>=value){ /* left*/
       insertNode_R(&(*t)->leftPtr,value);
     }
     else {/*right*/
      insertNode_R(&(*t)->rightPtr,value);
   }
  }
}