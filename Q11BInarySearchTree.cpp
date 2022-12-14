#include <iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
node* searchBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}
node* inorderSucc(node* root){
    node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
node* deleteBST(node* root,int key){
    if(key<root->data){
        root->left=deleteBST(root->left,key);
    }
    else if(key>root->data){
        root->right=deleteBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            free(root);
            return temp;
        }
        node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int heightBST(node* root){
    if(root==NULL) return 0;
    int lheight=heightBST(root->left);
    int rheight=heightBST(root->right);
    return max(lheight,rheight)+1;
}
int main(){
    int c,val,cho;
    node* root=NULL;
    int z=0;
    char ch='Y';
    do{
        cout << "1.Insert an element\n2.Delete an element\n3.search an element\n4.all order traversal\n";
        cout << "5.Print level order\n6.Height of BST\n";
        cout << "Enter your choice :";
        cin >> c;
        switch(c){
            case 1:
                cout << "enter an element to insert :";
                cin >> val;
                if(z==0){
                    root=insertBST(root,val);
                    z=1;
                }
                else{
                    insertBST(root,val);
                }
                cout << "\nelement added...\n\n";
                break;
            case 2:
                cout << "enter an element to delete :";
                cin >> val;
                if(val==root->data) z=0;
                deleteBST(root,val);
                cout << "element deleted...\n\n";
                break;
            case 3:
                cout << "enter element to search :";
                cin >> val;
                if(searchBST(root,val)!=NULL){
                    cout << val << " found in BST\n";
                    deleteBST(root,val);
                    cout << "Enter a element do you want to replace :";
                    cin >> val;
                    insertBST(root,val);
                    cout << val << " added in BST\n";
                }
                else cout << val << " not found in BST\n";
            case 4:
                cout << "1.PreOrder\n2.InOrder\n3.PostOrder\nEnter your choice";
                cin >> cho;
                switch(cho){
                    case 1:
                        cout << "pre order of BST is :";
                        preorder(root);
                        break;
                    case 2:
                        cout << "inorder of BST is :";
                        inorder(root);
                        break;
                    case 3:
                        cout << "postorder of BST is :";
                        postorder(root);
                        break;
                }
                break;
            case 6:
                cout << "height of BST is :" << heightBST(root) << "\n\n";
        }
    }while(ch=='Y' || ch=='y');

}