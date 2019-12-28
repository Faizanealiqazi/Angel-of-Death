#include <iostream>
#include <string>
#include<fstream>
#include <queue>
#include <stack>
#include <vector>
#include<cctype>
#include<conio.h>
#include<cmath>
#include<ctype.h>
#include<windows.h>

int x_axis_1=80,x_axis_2=150,y_axis_1=10,y_axis_2=34; // For interface

using namespace std;


void gotoxy (int x, int y) 
{
    HANDLE Manipulator;
    
    COORD Coordinates;
    
    Manipulator = GetStdHandle (STD_OUTPUT_HANDLE);
    
    Coordinates.X = x;
    
    Coordinates.Y = y;
    
    SetConsoleCursorPosition (Manipulator, Coordinates);
}



struct Pointers
{
    string Family_Title;
    string Husband;
    string Wife;
    string Marriage_Date;
    char Children_Count;
    string *Children;
};



class Person 
{
    string Title;
    string Name;
    string Gender;
    string Birth_date;
    string Death_date;
    string Fptr;
    string FAMS;
    bool Marital_Status;
    int Children_Count;
    string Marriage_Date;

    Person *Partner;
    Person **Children;
    Person *Parent;
    

    public:
        Person()
        {
            Partner = NULL;
            Children = NULL;
            Parent = NULL;
        }

        



    
    friend void operator >> (ifstream &f, Person *p);
    friend ostream& operator << (ostream &f, Person *p);
    friend class Family_Tree;
    void operator = (const Person &p);


};


void Person::operator = (const Person &p)
{
    this->Title = p.Title;
    this->Name = p.Name;
    this->Gender = p.Gender;
    this->Birth_date = p.Birth_date;
    this->Death_date = p.Death_date;
    this->Fptr = p.Fptr;
    this->FAMS = p.FAMS;
    this->Marital_Status = p.Marital_Status;
    this->Children_Count = p.Children_Count;
    this->Marriage_Date = p.Marriage_Date;

}

void operator >> (ifstream &f, Person *p)
{
    string input;
    input = "";
    getline(f,input);
    input = "";
    getline(f,input);
    int i = 0;
    int size = input.size();
    p->Title = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Title += input[i++];
    }
    input = "";
    getline(f,input);
    i = 0;
    p->Name = "";
    size = input.size();
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Name += input[i++];
    }
    input = "";
    getline(f,input);
    i = 0;
    size = input.size();
    p->Gender = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Gender += input[i++];
    }
    input = "";
    getline(f,input);
    input = "";
    getline(f,input);
    i = 0;
    size = input.size();
    p->Birth_date = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Birth_date += input[i++];
    }


    input = "";
    getline(f,input);

    input = "";
    getline(f,input);
    i = 0;
    size = input.size();
    p->Death_date = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Death_date += input[i++];
    }

    input = "";
    getline(f,input);

    input = "";
    getline(f,input);

    i = 0;
    size = input.size();
    p->Fptr = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->Fptr += input[i++];
    }

    input = "";
    getline(f,input);

    i = 0;
    size = input.size();
    p->FAMS = "";
    while(input[i++] != ':' && i < size);
    while(i < size)
    {
        p->FAMS += input[i++];
    }

    if (p->FAMS == " -")
    {
        p->Marital_Status = false;
    }
	else
    {
        p->Marital_Status = true;
    }
    
}

ostream& operator << (ostream &f, Person *p)
{
    f << "Title : " << p->Title << endl
    << "Name : " << p->Name << endl
    << "Gender : " << p->Gender << endl
    << "Birth Date : " << p->Birth_date << endl
    << "Death Date : " << p->Death_date << endl;
    f << "Married : ";
    if (p->Marital_Status == true)
    {
        f << "Yes" << endl;
        f << "Marriage Date : " << p->Marriage_Date << endl;
        f << "Childrens : " << p->Children_Count << endl;
        if (p->Children_Count)
        {
            for(int i = 0; i < p->Children_Count; i++)
            {
                f << '\t' << i+1 << " . " << p->Children[i]->Name << endl;
            }

        }

    }
    else
    {
        f << "No" << endl;
    }
    return f;
}

Pointers* Pointers_Find(ifstream &f, Pointers *r)
{
    string input = "";
    getline(f, input);
    input = "";
    getline(f, input);
    int i = 0;
    int size = input.size();
    while(input[i++] != ':' && i < size);
    r->Family_Title = "";
    while(i < size)
    {
        r->Family_Title += input[i++];
    }
    
    input = "";
    getline(f, input);
    i = 0;
    size = input.size();
    while(input[i++] != ':' && i < size);
    r->Husband = "";
    while(i < size)
    {
        r->Husband += input[i++];
    }
    input = "";
    getline(f, input);
    i = 0;
    size = input.size();
    while(input[i++] != ':' && i < size);
    r->Wife = "";
    while(i < size)
    {
        r->Wife += input[i++];
    }
    input = "";
    getline(f, input);
    input = "";
    getline(f, input);
    i = 0;
    size = input.size();
    while(input[i++] != ':' && i < size);
    r->Marriage_Date = "";
    while(i < size)
    {
        r->Marriage_Date += input[i++];
    }
    if (r->Marriage_Date.size() == 0)
    {
        r->Marriage_Date = " -";
    }
    input = "";
    getline(f, input);
    i = 0;
    size = input.size();
    while(input[i++] != ':' && i < size);
    r->Children_Count = input[i];
	if (r->Children_Count != '-')
    {
        int ch =(int)r->Children_Count - (int)'0';
		r->Children = new string[ch];
        for(int j = 0; j < ch; j++)
        {
			input = "";
            getline(f, input);
            i = 0;
            size = input.size();
            while(input[i++] != '@' && i < size);
			r->Children[j] = "";
            i--;
            while(i < size)
            {
                r->Children[j] += input[i++];
            }
            
		}

    }
    else
    {
        r->Children = NULL;
    }
    return r;
}

class Family_Tree
{
    Person *Root;
    void Deleting(Person*);
    int counter;
    
    void checklevel(Person*,string,int);

    string generate_title();

    Person* find_father(string &);

    Person* input_spouse(string &);

    void update_partner(Person *,string &);

    Person* input_child(string &);

    void Construct_Tree();

    
    void insert_child_in_tree(Person*);

    int find_persons_with_marital_status();

    void Write_Pointer();

    void Write_Data();

    string Input_Gender();

    public: 
    
    Family_Tree()
    {
        counter = 0;
        Root = NULL;
        Construct_Tree();
    }

    void FindRelation(string,string);

    void Search(string);

    void All_Family_Members();

    bool DeletePerson(string);

    
    void insert_new_member();
	void Update(string);
    
    void Print();
    
    ~Family_Tree()
    {
        if (Root)
        {
            this->Write_Data();
            this->Write_Pointer();
            queue<Person*> Delete;
            Delete.push(Root);
            while(!Delete.empty())
            {
                Person* temp = Delete.front();
                Delete.pop();
                
                if (temp->Marital_Status)
                {
                    delete temp->Partner;

                    if (temp->Children_Count)
                    {
                        for(int i = 0; i < temp->Children_Count; i++)
                        {
                            Delete.push(temp->Children[i]);
                        }
                    }

                }
                

                delete temp;


            }

            Root = NULL;
        }

    }


};

void Family_Tree::All_Family_Members()
{
    queue<Person*> Traverse;
    Traverse.push(this->Root);
    while (!Traverse.empty())
    {
        Person *temp = Traverse.front();
        Traverse.pop();

        if(temp)
        {
            cout << temp->Title << '\t' << temp->Name << endl;
            if(temp->Marital_Status)
            {
                cout << temp->Partner->Title << '\t' << temp->Partner->Name << endl;
                if(temp->Children_Count)
                {
                    for(int i = 0; i < temp->Children_Count; i++)
                    {
                        Traverse.push(temp->Children[i]);
                    }
                }
            }
        }
    }
    cout << "Total Persons in the Family : " << this->counter << endl;
}

void Family_Tree::Write_Data()
{
    if (Root)
    {
        ofstream file("Dataset.txt");
        if (file.is_open())
        {
            queue<Person*> traverse;
            traverse.push(Root);
            while(!traverse.empty())
            {
                Person* temp = traverse.front();
                traverse.pop();

                file << endl;
                file << "Title:" << temp->Title << endl;
                file << "Name:" << temp->Name << endl;
                file << "Sex:" << temp->Gender << endl;
                file << "Birth:" << endl;
                file << '\t' << "Date:" << temp->Birth_date << endl ;
                file << "Death:" << endl;
                file << '\t' << "Date:" << temp->Death_date << endl ;
                file << "Family:" << endl;
                file << '\t' << "Fptr:" << temp->Fptr << endl ;
                file << '\t' << "FAMS:" << temp->FAMS << endl ;
                

                if (temp->Marital_Status)
                {
                    file << endl;
                    file << "Title:" << temp->Partner->Title << endl;
                    file << "Name:" << temp->Partner->Name << endl;
                    file << "Sex:" << temp->Partner->Gender << endl;
                    file << "Birth:" << endl;
                    file << '\t' << "Date:" << temp->Partner->Birth_date << endl ;
                    file << "Death:" << endl;
                    file << '\t' << "Date:" << temp->Partner->Death_date << endl ;
                    file << "Family:" << endl;
                    file << '\t' << "Fptr:" << temp->Partner->Fptr << endl ;
                    file << '\t' << "FAMS:" << temp->Partner->FAMS << endl ;
                    

                    if (temp->Children_Count)
                    {
                        for(int  i = 0; i < temp->Children_Count; i++)
                        {
                            traverse.push(temp->Children[i]);
                        }
                    }

                }
            }
            file.close();
        }
    }
}


void Family_Tree::Write_Pointer()
{
    ofstream file("Pointers.txt");
    if(file.is_open())
    {
        queue<Person*> traversing;
        traversing.push(Root);
        while (!traversing.empty())
        {
            Person* temp = traversing.front();
            traversing.pop();

            if( temp->Marital_Status )
            {
                file << endl;
                file << "Family Title:" << temp->FAMS << endl;
                if (temp->Gender == "Male")
                file << '\t' << "Husband:" << temp->Title << endl;
                else
                file << '\t' << "Husband:" << temp->Partner->Title << endl;
                
                if (temp->Gender == "Female")
                file << '\t' << "Wife:" << temp->Title << endl;
                else
                file << '\t' << "Wife:" << temp->Partner->Title << endl;
                
                file << '\t' << "Marriage:" << endl;
                file << "\t\tDate:" << temp->Marriage_Date << endl;

                file << "\tChildren:";
                if (temp->Children_Count)
                {
                    file << temp->Children_Count << endl;
                    for(int i = 0; i < temp->Children_Count; i++)
                    {
                        file << "\t\t" << temp->Children[i]->Title << endl;
                        traversing.push(temp->Children[i]);
                    }
                }
                else
                file << '-' << endl;
            }

        }
        file.close();
    }
    else
    {
        cout << "New Pointers File Error";
        exit(1);
    }
    
}


void Family_Tree::Search(string name)
{
    if (Root)
    {
        queue<Person*> traversing;
        vector<Person*> Searched_People;
        traversing.push(Root);
        int count = 1;
        while(!traversing.empty())
        {
            Person* temp = traversing.front();
            traversing.pop();
            int size = (int)temp->Name.size();
            for(int i = 0; i < size; i++)
            {
                if (name[0] == temp->Name[i])
                {
                    int j = 0, k = i;
                    while (name[j++] == temp->Name[k++] && (j < (int)name.size()) && (k < size) ){}
                    if(j >= name.size())
                    {
                        cout << count++ << " . " << temp->Name << endl;
                        Searched_People.push_back(temp);
                        break;
                    }
                }
            }


            if (temp->Marital_Status)
            {
                int psize = (int)temp->Partner->Name.size();
                for(int i = 0; i < psize; i++)
                {
                    if (name[0] == temp->Partner->Name[i])
                    {
                        
                        int j = 0;int k = i;
                        while ((name[j++] == temp->Partner->Name[k++]) && (j < (int)name.size()) && (k < psize) ){}
                        if(j >= name.size())
                        {
                            cout << count++ << " . " << temp->Partner->Name << endl;
                            Searched_People.push_back(temp->Partner);
                            break;
                        }
                    }
                }

                if (temp->Children_Count != 0)
                {
                    for(int i = 0; i < temp->Children_Count; i++)
                    {
                        traversing.push(temp->Children[i]);
                    }
                }


            }
        }
        if (count > 1)
        {
            if (count == 2)
            {
                system("cls");
                Person *temp = Searched_People[0];
                cout << temp;
            }
            else
            {
                cout << endl << "Enter Number To View Respective Profile : " ;
                int choice;
                cin >> choice;
                while (choice >= count)
                {
                    cout << "Invalid Input" << endl;
                    cin >> choice;
                }
                system("cls");
                Person *temp = Searched_People[choice - 1];
                cout << temp;
		
            }
            
        }
        else
        {
            cout << "No Data Found !! " << endl;
            return;
        }
        
    }

}


void Family_Tree::Print()
{
    if(Root)
    {
        cout << "Name : " << Root->Name << endl;
        cout << "Gender : " << Root->Gender << endl;
        cout << "Birth Date : " << Root->Birth_date << endl;
        cout << "Death Date : " << Root->Death_date << endl;
        cout << "Married : ";
        if(Root->Marital_Status)
        {
            cout << "Yes " << endl;
            cout << "Children : " << Root->Children_Count << endl;
            for(int i = 0; i < Root->Children_Count; i++)
            {
                cout << i+1 << " : " << Root->Children[i]->Name << endl;
                if(Root->Children[i]->Marital_Status)
                {
                    cout << "Partner  : " << Root->Children[i]->Partner->Name << endl;
                    if(Root->Children[i]->Children_Count!=0)
                    {
                        cout << endl << "Grand Children : "<< endl; 
                        for(int j = 0; j < Root->Children[i]->Children_Count; j++)
                        {
                        cout << '\t' << j+1 << " : " << Root->Children[i]->Partner->Children[j]->Name << endl;
                        }
                    }
                    
                }
                
                
                cout << endl << endl;
            }
            
        }
        else
        {
            cout << "No " << endl;
        }
        
    }
    else
    {
        cout<<"No Family Tree Found!"<<endl;
    }
}

void Family_Tree::Construct_Tree()
{
	Root = new Person;
    counter ++;
    ifstream file("Dataset.txt");
    if(file.is_open())
    {
        file >> Root;
        file.close();
    }
    else
    {
        cout << "Root file not open !!" << endl;
        exit(1);
    }
    queue<Person*> Tree;
    Tree.push(Root);

    while(!Tree.empty())
    {
        Person *temp = Tree.front();
        Tree.pop();
        int  child = 0;
        
        if (temp->Marital_Status)
        {
            file.open("Pointers.txt");
            bool found = 0;
            Pointers *Relations = new Pointers;
            if(file.is_open())
            {
                    
                while(!file.eof())
                {
                    Pointers_Find(file, Relations);
                    if(temp->FAMS == Relations->Family_Title)
                    {
                        found = 1;
                        break;
                    }
                        
                }
                file.close();
            }
            else
            {
                cout << "Pointers file could not be open " << endl;
                exit(1);
            }

            if (found)
            {
                file.open("Dataset.txt");
                if(file.is_open())
                {
                    Person *temp2 = new Person;
                    bool Done = false;
                    while(!file.eof())
                    {
                        if(Done) break;
                        file >> temp2;
                        if (temp->Partner == NULL && ((temp->Gender == "Male" && (temp2->Title == Relations->Wife)) || (temp->Gender == "Female" && (temp2->Title == Relations->Husband))))
                        {
                            temp->Partner = new Person;
                            *(temp->Partner) = *(temp2);
                            counter++;
                            temp->Partner->Partner = temp;
                            temp->Partner->Children = temp->Children;
                            temp->Marriage_Date = Relations->Marriage_Date;
                            temp->Partner->Marriage_Date = Relations->Marriage_Date;
                            temp->Marital_Status = 1;
                            temp->Partner->Marital_Status = 1;
                        }
                        else if(Relations->Children_Count != '-')
                        {
                            
                            int Child_Count = ((int)Relations->Children_Count - (int)'0');
                            
                            if(temp->Children == NULL)
                            {
                                temp->Children = new Person*[Child_Count];
                            }
                            if (Child_Count != child)
                            {
                                for(int i = 0; i < Child_Count; i++)
                                {
                                    if(Relations->Children[i] == temp2->Title)
                                    {
										temp->Children[child] = new Person;
                                        *(temp->Children[child]) = *temp2;
                                        counter++;
                                        temp->Children[child]->Parent = temp;
                                        Tree.push(temp->Children[child]);
                                        child++;
                                        break;

                                    }
                                }
                            }   
                                
                            temp->Children_Count = ((int)Relations->Children_Count - (int)'0');

                        }
                        if(temp->Partner != NULL)
                        {
                            temp->Partner->Children_Count = temp->Children_Count;
                        }
                        if (temp->Children_Count == child && temp->Partner != NULL)
                        {
                            break;
                        }
                    }
                    file.close();
                }   
                else
                {
                    cout << "Dataset File could not be open " << endl;
                } 
            }
                
                
        }
    }

}


bool Family_Tree::DeletePerson(string Title1)
{
	bool flag =false;
	bool flag2 = false;
	int idx=0;
	queue<Person*> queue1;
	Person *p = Root;
	Person *temp=NULL;
	if (p != 0)
	{
		if(!Title1.compare(Root->Title) || !Title1.compare(Root->Partner->Title))
		{
			cout<<"Sorry You cannot delete the head of the entire family-tree."<<endl;
		}
		else
		{
				queue1.push(p);
			while (!queue1.empty()) 
			{
				p=queue1.front();
				queue1.pop();
				//visit(p);
				//cout<<p->Name<<endl;
			//	cout<<"Children Count"<<p->Children_Count<<endl;
			
	//			cout<<p->Name<<endl;
	//			cout<<p->Children_Count<<endl;
				for(int i=0;i<p->Children_Count;i++)
				{
					if(!Title1.compare(p->Children[i]->Title))
					{
						flag=true;
						idx=i;
					}
					if(p->Children[i]->Marital_Status)
					{
						if(!Title1.compare(p->Children[i]->Partner->Title))
						{
							flag2=true;
							idx=i;
						}
					}
					queue1.push(p->Children[i]);
				}
				if(flag==true)
				{
					if(idx==p->Children_Count-1)
					{
						
						Deleting(p->Children[p->Children_Count-1]);
						p->Children[idx] = NULL;
					}
					else
					{
						temp=p->Children[p->Children_Count-1];
						p->Children[p->Children_Count-1]=p->Children[idx];
						p->Children[idx]=temp;
						Deleting(p->Children[p->Children_Count-1]);
						p->Children[p->Children_Count-1]=NULL;
					}
					p->Children_Count--;
				//	cout<<"DONE DELETING"<<endl;
					break;
				}
				
				
				if(flag2 == true)
				{
					
					Deleting(p->Children[idx]->Partner);
					
					for(int i=0;i<p->Children[idx]->Children_Count;i++)
					{
						p->Children[idx]->Children[i]=NULL;
					}
					p->Children[idx]->Children_Count=0;
					p->Children[idx]->FAMS=" -";
				//	cout<<"Here"<<endl;
					p->Children[idx]->Marital_Status=false;
					break;
				}
				
			}
				if(flag==false && flag2==false)
				{
					cout<<"Record Not Found!"<<endl;
				}

			
			
		}
		if(flag==false && flag2 == false)
		return(false);
		else
		return(true);
	}
	
	
}

void Family_Tree::Deleting(Person* Root1)
{
	string confirmation;
	Person *temp=NULL;
	queue<Person*> queue1;
	stack<Person*> s1;
	Person *p = Root1;
	//cout<<"Inside Deleting"<<endl;
	//cout<<p<<endl;
	//cout<<"ChildrenCount:"<<p->Children_Count<<endl; 
	if (p != 0)
	{
		queue1.push(p);
		s1.push(p);
		cout<<"People that are deleted."<<endl;
		while (!queue1.empty()) 
		{
			p=queue1.front();
			queue1.pop();
			cout<<p->Name<<endl;
            counter--;
			for(int i=0;i<p->Children_Count;i++)
			{
				queue1.push(p->Children[i]);
				s1.push(p->Children[i]);
			}
			
		}
		
			while(!s1.empty())
			{
				temp=s1.top();
			//	cout<<temp->Name<<endl;
				s1.pop();
				delete temp;
				
			}
			temp=NULL;
	
	}
}


string name()
    {
        char ch;
        string name;
        getline(cin,name);
        string real="";
        for(int i=0;i<name.size();i++)
        {
            ch=name[i];
            real+=toupper(ch);
        }
        return real;
    }

Person * Family_Tree::input_child(string &father) 
{   
    Person *p=new Person();fflush(stdin);
    cout<<"\n\tEnter The Name :: ";
    p->Name=name();
    fflush(stdin);
    cout<<",\n\tEnter The Father Name :: ";father=name();fflush(stdin);
    cout<<"\n\tEnter the DOB         :: ";getline(cin,p->Birth_date);fflush(stdin);

    cout<<"\n\tEnter the Sex         :: ";p->Gender=Input_Gender();fflush(stdin);
    cout<<"\n\tEnter the death date  :: ";getline(cin,p->Death_date);fflush(stdin);
    p->Children=0;
    p->Children_Count=0;
    p->Marital_Status=false;
    p->Marriage_Date="-";
    p->Partner=0;
    return p;

}

Person * Family_Tree::input_spouse(string &father)
{
    Person *p=new Person();
    cout<<"\n\tEnter The Name :: ";p->Name=name();fflush(stdin);
    cout<<",\n\tEnter The partner Name :: ";father=name();fflush(stdin);
    cout<<"\n\tEnter the DOB         :: ";getline(cin,p->Birth_date);fflush(stdin);
    cout<<"\n\tEnter the Sex         :: ";p->Gender=Input_Gender();fflush(stdin);
    cout<<"\n\tEnter the death date  :: ";getline(cin,p->Death_date);fflush(stdin);
    cout<<"\n\tEnter the Marriage date  :: ";getline(cin,p->Marriage_Date);fflush(stdin);
    p->Fptr=" -";
    p->Marital_Status=true;
    return p;
}

// string * Family_Tree::resizing(string *s,char x,string title)
// {
//     string *temp;
//     int size=(int )x-(int )'0';
//     temp=new string [size-1];
//     cout<<"size "<<size<<endl;
//     for(int i=0;i<size-1;i++)
//         temp[i]=s[i];
//     delete [] s;
//     s=new string [size];
//     for(int i=0;i<size-1;i++)
//         s[i]=temp[i];
//     s[size-1]=title;
//     return s;
// }

string Family_Tree::generate_title()
{
    int title=0;
    string t="";
    counter++;
    title=counter;
    int j = 0;
    int temp = title;
    while (temp)
    {
        temp /= 10;
        j++;
    }
    t="@";
    int k=4-j;
    while(k)
    {
        t+="0";
        k--;
    }
    char ch[j];

    for(int i=0;i<j;i++)
    {
        ch[i]=((title%10)+(int)'0');
        title=title/10;
    }
    for(int i=j-1;i>=0;i--)
    {
        t+=ch[i];
    }
    return t;
}

Person * Family_Tree::find_father(string &f)
{
    queue<Person*>q;
    q.push(Root);
    Person *temp;
    bool okay=false;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->Name==f)
        {
            okay=true;
            break;
        }
        for(int i=0;i<temp->Children_Count;i++)
        {
            q.push(temp->Children[i]);
        }
    }
    if(okay)
    {
        return temp;
    }
    cout<<"FATHER NOT FOUND" << endl;
    return 0;

}

void Family_Tree::insert_new_member()
{   
    /*
    #####   ATTENTION   #####
    ...THE VARIABLE  "FATHER "IS USED FOR BOTH CHILD AND PARTNER ONLY FOR FEASIBLITY.

    */
cout<<"\nIF NEW MEMBER IS CHILD PRESS (1) OR IS SPOUSE PRESS ANY KEY ";
char ch=getch();
string father;
Person *p;
if(ch=='1')
{
    p = input_child(father);
}
else{
    p = input_spouse(father);
}
Person *temp=new Person;//      temp hold the information of father or partner
    if(ch=='1')
    {
        temp=find_father(father);
        if(temp==0)
            return;
        if(!temp->Marital_Status)
        {
            cout<<"Error, Father is unmarried "<<endl;
            return;
        }
        else
        {
            p->Fptr=temp->FAMS;
            p->FAMS=" -";

            /*YAHAN TAK TO OKAY HA*/
            p->Title= generate_title();
            cout<<"p->title "<<p->Title<<endl;
            p->Partner=0;
            insert_child_in_tree(p);

            }
        }
    else
    {

        if(temp->Marital_Status )
        {
            cout<<"#####ERROR####\nTHE PARTNER IS ALLREADY MARRIED "<<endl;
            return;
        }
    else
        {
            p->Title=generate_title();
            update_partner(p,father);
        }
    }
    cout<<"\tinserted"<<endl;


}



void Family_Tree::update_partner(Person *p,string &f)
{
    queue<Person * >q;
    q.push(Root);
    Person *temp=0;
    bool okay=false;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->Name == f)
        {
            okay = true;
            break;
        }
        for(int i=0;i<temp->Children_Count;i++)
        {
            q.push(temp->Children[i]);
        }
    }
    if(!okay)
        {
            cout<<"PARTNER IS NOT FOUND IN THE FAMILY TREE "<<endl;
            return;
        }
    else
    {
        if(temp->Gender==p->Gender)
        {
            cout<<"#######ERROR#########\nSAME GENDER"<<endl;
            return;
        }

        temp->Partner=new Person;
        *(temp->Partner)=*p;
        temp->Partner->Partner=temp;
        if(temp->Marital_Status==false)
        {
            int c = find_persons_with_marital_status();
            c += 1;
            int u=c;
            int j=0;
            while(u)
            {
                u=u/10;
                j++;
            }
            string t="@F";
            int k=4-j;
            while(k)
            {
                t+="0";
                k--;
            }
            char ch[j];
            for(int i=0;i<j;i++)
            {
                ch[i]=((c%10)+(int)'0');
                c=c/10;
            }
            for(int i=j-1;i>=0;i--)
            {
                t+=ch[i];
            }
            cout<<"FAMSS TITLE "<<t<<endl;
            temp->FAMS=t;
            temp->Partner->FAMS=t;
        }
        temp->Partner->Children_Count=0;
        temp->Partner->Children=0;
        temp->Marital_Status=true;
    }

}

int Family_Tree::find_persons_with_marital_status()
{
    queue<Person*>q;
    q.push(Root);
    int c=0;
    while(!q.empty())
    {
        Person *temp=q.front();
        q.pop();
        if(temp->Marital_Status)
        {
            c++;
        }
        for(int i=0;i<temp->Children_Count;i++)
        {
            q.push(temp->Children[i]);
        }
    }
    return c;
}

void Family_Tree::insert_child_in_tree(Person *p)
{
    if(Root)
    {
        queue<Person*>q;
        q.push(Root);
        Person *temp=0;
        while(!q.empty())
        {
            temp=q.front();
            q.pop();
            if(temp->FAMS == p->Fptr)
                break;
            for(int i=0;i<temp->Children_Count;i++)
            {
                if(temp->Children_Count!=0)
                    q.push(temp->Children[i]);
            }
        }
        Person **hold =new Person*[temp->Children_Count];
        for(int i=0;i<temp->Children_Count;i++)
        {
            hold[i]=temp->Children[i];
            temp->Children[i]=0;
        }
        delete [] temp->Children;
        temp->Children=new Person*[++temp->Children_Count];
        for(int i=0;i<temp->Children_Count-1;i++)
        {
            temp->Children[i]=hold[i];
            hold[i]=0;
        }
        temp->Children[temp->Children_Count-1]=new Person;
        *(temp->Children[temp->Children_Count-1])=*p;
        temp->Children[temp->Children_Count-1]->Parent=temp;
        delete [] hold;
        return;

    }
}

string Family_Tree::Input_Gender()
{
    string gender;
    char ch;
    while(1)
    {
        getline(cin,gender);
        ch=gender[0];
        gender[0]=toupper(ch);
        if(gender=="Male"||gender=="Female" || gender=="MALE" || gender=="FEMALE")
        {
            break;
        }
        else{
            cout<<"gender not defined"<<endl;
        }
    }
    return gender;
}



void box()
{
	int i;
	gotoxy(x_axis_1,y_axis_1);	printf("%c",220);  //coordinates C(20,34),D(150,34)
    gotoxy(x_axis_2,y_axis_1);	printf("%c",220);
    gotoxy(x_axis_1,y_axis_2);	printf("%c",223);
    gotoxy(x_axis_2,y_axis_2);	printf("%c",223);

    for(i=(x_axis_1+1);i<=(x_axis_2-1);i++){
    gotoxy(i,y_axis_1);	printf("%c",220);}
    for(i=(x_axis_1+1);i<=(x_axis_2-1);i++){
    gotoxy(i,y_axis_2);	printf("%c",223);}
    for(i=(y_axis_1+1);i<=(y_axis_2-1);i++){
    gotoxy(x_axis_2,i);	printf("%c",222);}

    for(i=(y_axis_1+1);i<=(y_axis_2-1);i++){
    gotoxy(x_axis_1,i);	printf("%c",221);}

    
} 



int abc=0;
Person* Tempp=NULL;

void Family_Tree::FindRelation(string name1,string name2)
{
	Person *p1=NULL,*p2=NULL;
	int level1=0,level2=0;
	bool flag=true;
	
	if(!Root->Name.compare(name1))
	{
		level1=0;
		p1=Root;
	}
	else
	{
		checklevel(Root,name1,1);
		
		level1=abc;
		p1=Tempp;
		
	}
//		cout<<"Level1 "<<level1<<endl;
		if(!Root->Name.compare(name2))
	{
		level2=0;
		p2=Root;
	}
	else
	{
		checklevel(Root,name2,1);
		level2=abc;
		p2=Tempp;
		
	}
		
//		cout<<"Level2 "<<level2<<endl;
		//fam2=familycheck;
	if(p1!= NULL && p2 != NULL)
	{
		
		int difference=level1-level2;
		if(difference<0)
		{
			difference=difference* -1;
			flag = false;
		}
		
		if(difference==0)
		{
			if(!p1->Fptr.compare(p2->Fptr))
			{
				cout<<"siblings"<<endl;
			}
			else
			{
				if(!p1->FAMS.compare(p2->FAMS))
				{
					cout<<name1<<" is spouse of "<<name2<<endl;
				}
				else if(!p1->Fptr.compare(" -") && p2->Fptr.compare(" -"))
				{
					if(!p2->Gender.compare("Male"))
					{
						cout<<name2<<" is brother-in-law of "<< name1<<endl;
					
					}
					else
					{
						cout<<name2<<" is sister-in-law of "<< name1<<endl;
					
					}
				}
				else if( p1->Fptr.compare(" -") && !p2->Fptr.compare(" -"))
				{
					if(!p1->Gender.compare("Male"))
					{
						cout<<name1<<" is brother-in-law of "<< name2<<endl;
					
					}
					else
					{
						cout<<name1<<" is sister-in-law of "<< name2<<endl;
					
					}
				}
				else if( p1->Fptr.compare(" -") && p2->Fptr.compare(" -") )
				{
					if(!p1->Gender.compare("Male"))
					{
						cout<<name1<<" is brother-in-law of "<< name2<<endl;
					
					}
					else
					{
						cout<<name1<<" is sister-in-law of "<< name2<<endl;
					
					}
				}
				else
				{
							cout<<"cousins"<<endl;
		
				}
			}
			
		}
		else if(difference ==1)
		{
			if(!flag)
			{
				if(!p1->FAMS.compare(p2->Fptr))
				{
					cout<<name1<<" is Parent "<<name2<<endl;
	
				}
				else if(!p2->Fptr.compare(" -"))
				{
					if(!p1->Gender.compare("Male"))
					{
						cout<<name1<<" is Father-in-law of "<<name2<<endl;
		
					}
					else
					{
						cout<<name1<<" is Mother-in-law of "<<name2<<endl;
		
					}
				}
				else
				{
					if(!p1->Gender.compare("Male"))
					{
						cout<<name1<<" is Uncle of "<<name2<<endl;
		
					}
					else
					{
						cout<<name1<<" is Aunt of "<<name2<<endl;
		
					}
				}
				
			}
			else
			{
				if(!p2->FAMS.compare(p1->Fptr))
				{
					cout<<name2<<" is Parent "<<name1<<endl;
	
				}
				else if(!p1->Fptr.compare(" -"))
				{
					if(!p2->Gender.compare("Male"))
					{
						cout<<name2<<" is Father-in-law of "<<name1<<endl;
		
					}
					else
					{
						cout<<name2<<" is Mother-in-law of "<<name1<<endl;
		
					}
				}
				else
				{
					if(!p2->Gender.compare("Male"))
					{
						cout<<name2<<" is Uncle of "<<name1<<endl;
		
					}
					else
					{
						cout<<name2<<" is Aunt of "<<name1<<endl;
					//	cout<<"Yewala"<<endl;
		
					}
				}
			
			}
		}
		else if(difference == 2)
		{
			if(!flag)
			{
				cout<<name1<<" is GrandParent of "<<name2<<endl;
	
			}
			else
			{
				cout<<name2<<" is GrandParent of "<<name1<<endl;
	
			}
		}
		else
		{
			if(!flag)
			{
				cout<<name1<<" is Great-Grand-Parent of "<<name2<<endl;
	
			}
			else
			{
				cout<<name2<<" is Great-Grand-Parent of "<<name1<<endl;
	
			}
		}
	}
	else
	{
		cout<<"Person Not Found"<<endl;
	}
	
}


void Family_Tree::checklevel(Person* Root1,string name1,int level )
{	
	for(int i=0; i<Root1->Children_Count; i++)
	{
		if(!name1.compare(Root1->Children[i]->Name))
		{
		//	cout<<Root1->Children[i]->Name<<endl;
			abc=level;
			Tempp=Root1->Children[i];

			
		}
	else
	{
		checklevel(Root1->Children[i],name1,level+1);
		//		cout<<level<<endl;
		}	
	
	}
}




void menu()
{
    Family_Tree Family;
    while(1)
    {
        system("cls");
        box();
        gotoxy(x_axis_1+10,y_axis_1-2);cout << "Family Tree";
        gotoxy(x_axis_1+6,y_axis_1+2);cout << "Enter Number To Select Any Option : ";
        gotoxy(x_axis_1+4,y_axis_1+4);cout << "1. To See Every Family Members.";
        gotoxy(x_axis_1+4,y_axis_1+6);cout << "2. To Search For A Particular Family Member.";
        gotoxy(x_axis_1+4,y_axis_1+8);cout << "3. To Add A New Family Member.";
        gotoxy(x_axis_1+4,y_axis_1+10);cout << "4. To Delete A Family Member.";
        gotoxy(x_axis_1+4,y_axis_1+12);cout << "5. To Find Relationship.";
        gotoxy(x_axis_1+4,y_axis_1+14);cout << "6. To Print Family Tree.";
        gotoxy(x_axis_1+4,y_axis_1+16);cout << "7. TO Update A Particular Family Member.";
        gotoxy(x_axis_1+4,y_axis_1+18);cout << "8. Exit.";
        gotoxy(x_axis_1+4,y_axis_1+20);cout << "Enter your Choice :";
        int choice;
        cin >> choice;
        system("cls");
        fflush(stdin);
        if (choice == 1)
        {
            Family.All_Family_Members();
        }
        else if (choice == 2)
        {
            box();
            gotoxy(x_axis_1+4,y_axis_1+12);cout << "Enter Name To Search :";
            string search = name();
            system("cls");
            Family.Search(search);
        }
        else if (choice == 3)
        {
            Family.insert_new_member();
        }
        else if (choice == 4)
        {
            string ID;
            cout << "Enter Correct Title ID of the person to be Delete : \n ** Caution : Deleting The Head Of The Family Will Delete It's Every Descendents" << endl;
            cout << "ID : ";
            cin >> ID;
            if (Family.DeletePerson(ID))
            {
                cout << endl << "Deleted Successfully " << endl;
            }
            
        }
        else if(choice == 5)
        {
            cout << "Enter Complete Name of First Person : " << endl;
            string name1;
            name1 = name();
            cout << "Enter Complete Name of Second Person : " << endl;
            string name2;
            name2 = name();
            Family.FindRelation(name1, name2);
        }
        else if(choice == 6)
        {
            Family.Print();
        }
        else if (choice == 7)
        {
            box();
            gotoxy(x_axis_1+4,y_axis_1+12);cout << "Enter Name To Search :";
            string search = name();
            system("cls");
            Family.Update(search);
        }
        else if(choice == 8)
        {
        	break;
		}
        else
        {
            cout << "Invalid Input !!!!" << endl;
        }

        fflush(stdin);
        cout << endl << endl << "Press enter to continue " << endl;
        cin.ignore();
    }
    return;
}


void Family_Tree::Update(string n)
{
	if (Root)
    {
    	int choice=0;
        queue<Person*> traversing;
        traversing.push(Root);
        int count=0;
        while(!traversing.empty())
        {
            Person* temp = traversing.front();
            traversing.pop();
            if(!n.compare(temp->Name))
            {
               	count=1;
                cout<<temp->Name<<endl;
                while(1)
				{
					cout<<"What do you want to change?\n1)change Name\n2)Birth Date\n3)Death Date\n4)Gender\n5)Exit\n ";
					cin>>choice;
					if(choice>=1&&choice<=5)
								{
									fflush(stdin);
									if(choice==1)
									{
										
										cout<<"Enter New Name: ";
										temp->Name=name();
									//	string nam="";
									//	cin>>nam;
									//	temp->Name=nam;
										break;
									}
									else if(choice==2)
									{
										cout<<"Enter New Birth Date: ";
										string d;
										getline(cin,d);
										temp->Birth_date=d;
										break;
									}
									else if(choice==3)
									{
										cout<<"Enter new Date of Death: ";
										string d;
										getline(cin,d);
										temp->Death_date=d;
										break;
									}
									else if(choice==4)
									{
										cout<<"Enter new Gender: ";
										string g;
										getline(cin,g);
										temp->Gender=g;
										break;
									}
									else if(choice==5)
									{
										break;
									}
								}	else
								{
									cout<<"Invalid Choice!";
								}
								
							}	
                    }
					else
					{
            		if (temp->Marital_Status)
            		{
                        if(!n.compare(temp->Partner->Name))
                        {
                        	count=1;
                        	cout<<"Name : "<<temp->Partner->Name<<endl;
                            while(1)
							{
								
								
							//	system("cls");
								cout<<"What do you want to change?\n1)change Name\n2)Birth Date\n3)Death Date\n4)Gender\n5)Exit\nEnter Choice : ";
								cin>>choice;
								if(choice>=1&&choice<=5)
								{
									fflush(stdin);
							//		system("cls");
									if(choice==1)
									{
										
										cout<<"Enter New Name: ";
										temp->Partner->Name=name();
										break;
									}
									else if(choice==2)
									{
										cout<<"Enter New Birth Date: ";
										string d;
										getline(cin,d);
										temp->Partner->Birth_date=d;
										break;
									}
									else if(choice==3)
									{
										cout<<"Enter new Date of Death: ";
										string d;
										getline(cin,d);
										temp->Partner->Death_date=d;
										break;
									}
									else if(choice==4)
									{
										cout<<"Enter new Gender: ";
										string g;
										getline(cin,g);
										temp->Partner->Gender=g;
										break;
									}
									else if(choice==5)
									{
										break;
									}
								}
								else
								{
										cout<<"Invalid Choice!";
								}
								
							}
                    }
                }
			}
                if (temp->Children_Count != 0)
                {
                    for(int i = 0; i < temp->Children_Count; i++)
                    {
                        traversing.push(temp->Children[i]);
                    }
                }


            }
                  if(count==0)
        cout<<"Name Not Found.";
        }
  
    return;
}



int main()
{
	cin.ignore();
    menu();
//    Family_Tree Family;
}
