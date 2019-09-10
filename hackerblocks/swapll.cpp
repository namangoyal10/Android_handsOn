#include<iostream>
using namespace std;
class node{
public:
	node* next;
	int data;
node(int d=0){
	data=d;
	next=NULL;
	}
	friend class linkedlist;
};

class linkedlist{
	public:
	node* head;
	linkedlist(){head=NULL;}

	void insertatend(int d){
		if(head==NULL) {
			head=new node(d);
			return;
		}

		node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new node(d);
	}

	void print(){
		node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}

	void swapdata(int x,int y){
		node *temp1=NULL,*temp2=NULL,*temp=head;

		while(temp!=NULL){
			if(temp->data==x) temp1=temp;
			if(temp->data==y) temp2=temp;
			temp=temp->next;
		}
		swap(temp1->data,temp2->data);
		print();
	}


};

void givemeans(char* s,char* s1,int i,int j,int sum,int &tempsum,string &ans){
    if(s[i]=='\0'){
        s1[j]='\0';
        if(tempsum==sum) {ans="Yes";
        }
        return;
    }
    s1[j]=s[i];
    tempsum=tempsum+(s1[j]-'0');
    givemeans(s,s1,i+1,j+1,sum,tempsum,ans);
    tempsum=tempsum-(s1[j]-'0');

    givemeans(s,s1,i+1,j,sum,tempsum,ans);

}

int main() {

	int n,sum; cin>>n>>sum;
    char* s=new char[n+1];
    for(int i=0;i<n;i++) cin>>s[i];
    s[n]='\0';
	char s1[100];
    int temp=0;
    string ans="No";
    givemeans(s,s1,0,0,sum,temp,ans);
    cout<<ans;
}
