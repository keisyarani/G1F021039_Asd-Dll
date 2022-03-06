#include<iostream>  
#include<stdlib.h>

using namespace std;  
struct node  
{  
	struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  
void insert_first();   
void insert_last();  
void insert_after();  
void delete_first();  
void delete_last();  
void delete_after();  
void display();  
void search(); 
int main ()  
{  
int pilih =0;  
    while(pilih != 9)  
    {  
        cout<<"\n*********MAIN MENU*********\n";    
        cout<<"\n===============================================\n";  
        cout<<"1.Insert First\n";
		cout<<"2.Insert Last\n";
		cout<<"3.Insert After\n";
		cout<<"4.Delete First\n";  
        cout<<"5.Delete Last\n";
		cout<<"6.Delete After\n";
		cout<<"7.Search (Sequential)\n";
		cout<<"8.Show\n";
		cout<<"9.Exit\n";  
        cout<<"\nMasukkan Pilihan\n";
		cin>>pilih; 
        switch(pilih)  
        {  
            case 1:  
            insert_first();      
            break;  
            case 2:  
            insert_last();         
            break;  
            case 3:  
            insert_after();       
            break;  
            case 4:  
            delete_first();       
            break;  
            case 5:  
            delete_last();        
            break;  
            case 6:  
            delete_after();          
            break;  
            case 7:  
            search();         
            break;  
            case 8:  
            display();        
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            cout<<"Silahkan Masukkan Pilihan yang Valid.."; 
    	}  
	}
}
void insert_first()
{  
	struct node *ptr;   
	int item;  
	ptr = (struct node *)malloc(sizeof(struct node));  
	if(ptr == NULL)  
	{  
    	cout<<"\nOVERFLOW";  
	}  
	else{  
    cout<<"\nMasukkan Nilai";
	cin>>item; 

	if(head==NULL)  
	{  
    	ptr->next = NULL;  
    	ptr->prev=NULL;  
    	ptr->data=item;  
    	head=ptr;  
	}  
	else{  
    	ptr->data=item;  
    	ptr->prev=NULL;  
    	ptr->next = head;  
		head->prev=ptr;  
    	head=ptr;  
	}  
	cout<<"\nNode inserted\n";  
	}  
}  
void insert_last()  
{  
	struct node *ptr,*temp;  
	int item;  	
	ptr = (struct node *) malloc(sizeof(struct node));  
	if(ptr == NULL)  
	{  
    	cout<<"\nOVERFLOW";  
	}  
	else{  
    	cout<<"\nMasukkan Nilai";  
    	cin>>item;
        ptr->data=item;  
    	if(head == NULL)  
    	{  
        	ptr->next = NULL;  
        	ptr->prev = NULL;  
        	head = ptr;  
    	}  
		else{  
        	temp = head;  
        	while(temp->next!=NULL){  
            	temp = temp->next;  
        	}  
        	temp->next = ptr;  
    		ptr ->prev=temp;  
        	ptr->next = NULL;  
        }       
    }  
    cout<<"\nnode inserted\n";  
}  
void insert_after()  
{  
	struct node *ptr,*temp;  
	int item,loc,i;  
	ptr = (struct node *)malloc(sizeof(struct node));  
	if(ptr == NULL)  
	{  
    	cout<<"\n OVERFLOW";  
	}  
	else{  
    	temp=head;  
    	cout<<"Masukkan Lokasi";
    	cin>>loc; 
    	for(i=0;i<loc;i++)  
    	{  
        	temp = temp->next;  
        	if(temp == NULL)  
        	{  
            	cout<<"\n Ada kurang dari "<<loc<<" elements"<<endl;  
            	return;  
        	}  
    	}  
    	cout<<"Masukkan Nilai";
    	cin>>item; 
    	ptr->data = item;  
    	ptr->next = temp->next;  
    	ptr -> prev = temp;  
    	temp->next = ptr;  
    	temp->next->prev=ptr;  
    	cout<<"\nnode inserted\n";  	
	}  
}  
void delete_first()  
{  
	struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\n UNDERFLOW";  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        cout<<"\nnode deleted\n";  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
    	cout<<"\nnode deleted\n";  
    }  
}  
void delete_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        cout<<"\n UNDERFLOW";  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        cout<<"\nnode deleted\n";  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        cout<<"\nnode deleted\n";  
    }  
}  
void delete_after()  
{  
    struct node *ptr, *temp;  
    int val;  
    cout<<"\n Enter the data after which the node is to be deleted : ";
	cin>>val;
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        cout<<"\nCan't delete\n";  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        cout<<"\nnode deleted\n";  
    }     
}  
void display()  
{  
    struct node *ptr;  
    cout<<"\n printing values...\n";  
    ptr = head;  
    while(ptr != NULL)  
    {  
        cout<<ptr->data<<endl;
        ptr=ptr->next;  
     }  
}   
void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        cout<<"\nEmpty List\n";  
    }  
    else  
    {   
        cout<<"\nMasukkan item yang ingin anda cari\n";
		cin>>item;   
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                cout<<"\nitem found at location "<<i+1<<endl;  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            cout<<"\nItem not found\n";  
        }  
    }
}
