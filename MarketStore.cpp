#include<iostream>
#include<sstream>
#include<cstdlib>
using namespace std;
void beg();//Start when node is null
void delPro();// Delete specific node
void buy();//Buy Products
int search(int);//   declarations of functions
int display();
string check(int);     
struct node  //   node using structure 
{
	int ID; //product id
	string proName; //product Name
	double prePrice;//product price
	int quantity; //product quantity
struct    node* next; //node pointer next
};
 struct node *head=NULL;// defining head as a NULL
 void beg() //for entering1st record in list
{
	system("cls");
	int id,quant;      
	string name;
	double pre;   
	struct node *t=new node; //defining new node by malloc function
	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
	t->next=head;
	head=t;
	system("cls");
		cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
	}
	void end()// for entering 2nd and onward records in list
	{
	system("cls");
	int id,quant;      //   quant for quantity
	string name;
	double pre;            //  pre for price
	struct node *t=new node;
	struct node *p=head;
	cout<<"\t\t\tEnter product ID:-";
	cin>>id;
	t->ID=id;
	cout<<"\t\t\tEnter product Name:-";
	cin>>name;
	t->proName=name;
	cout<<"\t\t\tEnter product price:-";
	cin>>pre;
	t->prePrice=pre;
	cout<<"\t\t\tEnter product quantity:-";
	cin>>quant;
	t->quantity=quant;
		while(p->next!=NULL)
		{
		p=p->next;
		}
			p->next=t;
			t->next=NULL;
		system("cls");
		cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";
	}
	void delPro()
	{
	
		int id;
		struct node *cur=head;
		struct node *pre=head;
	if (head == NULL)
    {
        cout<<"List is empty\n\n\n\n"<<endl;
    }
	int pos=0;
	if(head!=NULL)
	{
		display();
		cout<<"\n\nEnter ID to delete that product:\n\n";
		cin>>id;
	int count=display();               //   for load no of nodes 
	pos=search(id);                        //   for check weather desire node is exist or not    
	if(pos<=count){
		
		while(cur->ID!=id){                //  for delete middle area products
			pre=cur;
			cur=cur->next;
}
		pre->next=cur->next;
		system("cls");
		cout<<"\n<<item is deleted>>\n";
	}else{
		cout<<"\n<<<Not found>>\n\n";
	}
	}	
}
int display(){
		system("cls");
		int c=0;             //   c for count products
		struct node *p=head;
		cout<<"Existing products are:\n";
		cout<<"ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
		while(p!=NULL)
		{
			cout<<p->ID<<"\t\t"<<p->proName<<"\t\t\t\t"<<p->prePrice<<"\t\t"<<check(p->quantity)<<"\n"; //    call   check func and pass quantity
			p=p->next;
			c=c+1;
		}
		cout<<"\nTotal products in our store is : "<<c<<"\n\n\n";
		return c;
	    }
	    string check(int quant){              //        check function  
	    int a = quant;
       stringstream ss;
       ss << a;
       string quantity = ss.str();
       
	    	if(quant<=0)
	    	return "out of stock!";
	    	else
	    	return quantity;
		}
	    

	void buy(){
		system("cls");
		string products[20]; //   for display sold items
		int pay=0,no,c=0,price,id,i=1;
		if(head==NULL) {
	cout<<"\n<<<<There is no items to buy>>>>\n\n";	
	}
	else{
		cout<<"How many items you wanna to buy!\n";
		cin>>no;
			int count=display();           //   for store no of nodes  in c
		while (i<=no){
			struct node *cur=head;
				
		int quant,cho;              //   quant   for quantity  and cho for choice
	cout<<"Enter id of item that you want to buy: ";
int id,pos=0;
	cin>>id;
	pos=search(id);
	if(pos<=count){  
	                        //     item is available in store
		while(cur->ID!=id){
			cur=cur->next;
		}
        
	cout<<"How many quantities you want:";
	cin>>quant;
	products[c]=cur->proName; c++;
	pay=pay+(cur->prePrice*quant);         //     calculate Bill	
	cur->quantity=cur->quantity-quant;           //    change quantity
	i++;	
	}
	else{
		cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
	    }
}

	system("cls");	 
cout<<"\n\n\n\n\t\t\tYou have bought : ";
for(int i=0;i<no;i++){              //    show that item you have bought
	cout<<products[i]<<",";
}	
	cout<<"\n\nOriginal price : "<<pay;
    cout<<"\nThank you! for the shopping\n\n";
}
}
	
	int search(int id)                     //    for search item in list
 {
 	int count=1;
 	struct node *p=head;
 	while(p!=NULL)
 	{
 		if(p->ID==id)
 			break;              
 		else
 			count++;
 			p=p->next;
	}
 	return count;
 }
	                        //        Main function 
int main(){	
	system("color f0");
	cout<<"\t\t\t\t\t  ** Point OF SALE SOFTWARE **   \n\n"; 		
	int temp=1;
	while(true){
	int ch;                     //            choice for below message
	cout<<"\t\t\t\t\t\tEnter 1 for ADD a new product \n\n"; 
	cout<<"\t\t\t\t\t\tEnter 2 for Delete a particular product item\n\n\t\t\t\t\t\tEnter 3 for Buy something\n\n\t\t\t\t\t\tEnter 0 for exit\n\n";
	cout<<"\t\t\t\t\t\t__________\n";  
	cin>>ch;  //ch=1   
	switch(ch){
	case 1:
	if (temp==0){              //    Second time and on ward this is only executed 
	end();	
	}
	if(temp==1){             //    this will be executed only one time
	beg();	
	temp=0;
	}
	break;
case 2:
	delPro();
	break;
case 3:
	buy();
	break;		
 case 0:
    cout << "Exiting... Goodbye!" << endl;
    return 0; // Exit the program
default: 
	cout<<"\t\t<<<Wrong choice>>>\n\n";
    system("cls");
	}
}	
}
