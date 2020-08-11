#include<iostream>
#include<cstdlib>
using namespace std;

struct Trie{
    struct Trie * children[10];
    bool end;
    string name;
    string email;
};

Trie *root=NULL;

Trie* createNode(){
    Trie * x = new Trie();
    for(int i=0;i<10;i++)
    {
        x->children[i]=NULL;
    }
    x->end=false;
    return x;
}

bool check(string s){
    if(root==NULL){
        cout<<"\tcontact not found , database empty\n ";
        return false;
    }

    Trie * curr=root;
    for(int i=0;i<s.length();i++){
        int val = s[i]-'0';
        if(curr->children[val]==NULL){
            cout<<"\tcontact not found\n ";
            return false;
        }
        curr= curr->children[val];
    }
    if(curr!=NULL && curr->end == true){
        cout<<" "<<curr->name<<endl;
        cout<<" "<<curr->email<<endl;
        return true;
    }
    else{
        cout<<"\tcontact not found\n ";
        return false;
    }
}

void insert(string s,string nam,string emal){
    if(root==NULL){
        root= createNode();
    }

    Trie * curr = root;
    for(int i=0;i<s.length();i++){
        int val = s[i] - '0';
        if(curr->children[val]==NULL){
            curr->children[val] = createNode();
        }
        curr=curr->children[val];
    }
    curr->end=true;
    curr->name = nam;
    curr->email = emal;
}

void update(string s,string nam,string emal){
    if(root==NULL){
        cout<<"\tcontact number not found\n";
        return;
    }

    Trie * curr = root;
    for(int i=0;i<s.length();i++){
        int val = s[i] - '0';
        if(curr->children[val]==NULL){
            cout<<"\tcontact number not found\n ";
            return;
        }
        curr=curr->children[val];
    }
    curr->end=true;
    curr->name = nam;
    curr->email=emal;
}

int main()
{
    string s;
    string name;
    string email;
    int ch;
    while(1){
        cout<<"\tEnter your choice\n\t1]add contact\n\t2]search contact\n\t3]update\n\t4]exit\n ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"\tEnter mobile number\n ";
                cin>>s;
                cout<<"\tEnter name\n ";
                cin>>name;
                cout<<"\tEnter email\n ";
                cin>>email;
                insert(s,name,email);
                cout<<endl;
                break;

            case 2:
                cout<<"\tEnter mobile number\n ";
                cin>>s;
                check(s);
                cout<<endl;
                break;

            case 3:
                cout<<"\tEnter mobile number, which is to be updated\n ";
                cin>>s;
                cout<<"\tEnter updated name\n ";
                cin>>name;
                cout<<"\tEnter updates email\n ";
                cin>>email;
                update(s,name,email);
                cout<<endl;
                break;

            case 4:
                exit(0);
        }
    }
return 0;
}
