#include <conio.h>
#include <stdio.h> 
#include <limits.h> 
#include <iostream>
using namespace std;
  
#define V 9

int menu();
void clearList1();
void clearList2();
void clearList3();
int record(int);
void display();
struct Hospital{
    string name;
    int age;
    int degree;
    Hospital*next = NULL;
};

int len1 = 10, len2 = 6, len3 = 3;
int A = 0, B = 0, C = 0;
struct Camp1{
    string name;
    int age;
    int degree;
    int exit;
    Camp1*next = NULL;
};
Camp1* head1 = NULL, *tail1 = NULL;

struct Camp2{
    string name;
    int age;
    int degree;
    int exit;
    Camp2*next = NULL;
};
Camp2* head2 = NULL, *tail2 = NULL;

struct Camp3{
    string name;
    int age;
    int degree;
    int exit;
    Camp3*next = NULL;
};
Camp3* head3 = NULL, *tail3 = NULL;

int minDistance(int dist[], bool sptSet[]) 
{ 
      
    
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 

void printPath(int parent[], int j) 
{ 
      
    
    if (parent[j] == - 1) 
        return; 
  
    printPath(parent, parent[j]); 
  
    if(j<6){
    cout<<" to Room "<<j; 
   }
   else{
   	cout<<" to Exit "<<j; 
   }
} 
int printSolution(int dist[], int n,  
                      int parent[],int src) 
{   int index=6;
    int min=dist[6]; 
    cout<<"\n";
    printf("Path\t\t\t Distance\t\t\tPath"); 
    for (int i = 6; i < V; i++) 
    {
	    if(dist[i]<min && dist[i]>0){
	    	min=dist[i];
	    	index=i;
	    } 
        printf("\n Room %d -> Exit %d \t %d\t\t Room %d", 
                      src, i, dist[i], src); 
        printPath(parent, i); 
    } 
    cout<<"\n\n";
    cout<<"You should follow path from Room "<<src<<" -> Exit "<< index;
    cout<<"\n";
    return index;
} 
int dijkstra(int graph[V][V], int src) 
{ 
    int dist[V];  
    bool sptSet[V]; 
    int parent[V]; 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = -1; 
        dist[i] = INT_MAX; 
        sptSet[i] = false; 
    } 
    dist[src] = 0; 
  
    for (int count = 0; count < V - 1; count++) 
    { 
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true; 
        for (int v = 0; v < V; v++)  
            if (!sptSet[v] && graph[u][v] && 
                dist[u] + graph[u][v] < dist[v]) 
            { 
                parent[v] = u; 
                dist[v] = dist[u] + graph[u][v]; 
            }  
    }  
   int index = printSolution(dist, V, parent,src); 
   return index;
} 

int main() 
{  
    int exitTaken = 0;
    int opt = 0;
    while(true){
        cout<<"\n\t\t----------------------------------";
        cout<<"\n\n\t\tEnter:\n\t\t1. GENERATE ESCAPE ROUTE\n\t\t2. MEDICAL CAMP DATA\n\t\t3. TRANSPORT PATIENTS\n\t\t4. EXIT";
    
        cout<<"\n\t\t----------------------------------"<<endl;
        cout<<"\n\t\t-->";
        cin>>opt;

        
        if(opt == 1){
            exitTaken = menu();
            if(record(exitTaken) == 0){
                cout<<"\nPatient Added!";
            }
            else if(record(exitTaken) == 1){
                cout<<"\nInsufficient space in MEDICAL CAMP.1.";
                cout<<"\nTransport patients to the hospital from MEDICAL CAMP.1.";
            }else if(record(exitTaken) == 2){
                cout<<"\nInsufficient space in MEDICAL CAMP.2.";
                cout<<"\nTransport patients to the hospital from MEDICAL CAMP.2.";
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
            }else if(record(exitTaken) == 3){
                cout<<"\nInsufficient space in MEDICAL CAMP.3.";
                cout<<"\nTransport patients to the hospital from MEDICAL CAMP.3.";

            }
        }
        else if(opt == 2){
            display();
        }
        else if(opt == 3){
            int x = 0;
            cout<<"\nEnter your option:\n1. TRANSPORT MEDICAL CAMP.1 PATIENTS\n2. TRANSPORT MEDICAL CAMP.2 PATIENTS\n3. TRANSPORT MEDICAL CAMP.3 PATIENTS\n-->";
            cin>>x;
            if(x == 1){
                clearList1();
            }
            else if(x == 2){
                clearList2();
            }
            else if(x == 3){
                clearList3();
            }
            else{
                cout<<"\nINVALID INPUT!!";
            }
        }
        else if(opt == 4){
            exit(0);
        }
        else{
            cout<<"\nINVALID INPUT!!";
        }

    }
    return 0; 
} 
int menu(){
    int graph[V][V] =  {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                        {4, 0, 8, 0, 0, 0, 6, 11, 0}, 
                        {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                        {0, 0, 7, 0, 9, 14, 5, 0, 7}, 
                        {0, 0, 0, 9, 0, 10, 0, 8, 0}, 
                        {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                        {0, 6, 0, 5, 0, 2, 0, 0, 0}, 
                        {8, 11, 0, 0, 8, 0, 0, 0, 0}, 
                        {0, 0, 2, 7, 0, 0, 0, 0, 0}}; 

    
	cout<<"There are 6 rooms: \nRoom 0\nRoom 1\nRoom 2\nRoom 3\nRoom 4\nRoom 5\n\n";
    cout<<"\nThere are 3 exits \nExit 6\nExit 7\nExit 8\n\n";
    
    cout<<"\nEnter the room in which fire occured\n";
	int a;
	cin>>a;
	while(a<0 || a>5)
	{
		cout<<"\nWrong input\n";
		cout<<"\nEnter the room in which fire occured?\n";
		cin>>a;
		
	}

	for(int i=0;i<=8;i++)
	{
		graph[i][a]=0;
		graph[a][i]=0;
		
	}
	cout<<"\nIn which room you are present?\n";
	int b;
	cin>>b;
	while(b<0 || b>5)
	{
		cout<<"\nwrong input\n";
		cout<<"\n In which room you are present?\n";
		cin>>b;
		
	}
	                
  
    int index = dijkstra(graph, b);
    return index; 
}

int record(int exitTaken){
    string n;
    int x, y;
    if(A >= len1){
        return 1;
    }
    if(B >= len2){
        return 2;
    }
    if(C >= len3){
        return 3;
    }
    else{
        cout<<"\n\nEnter your name: ";
    cin>>n;
    cout<<"\n\nEnter your age: ";
    cin>>x;
    cout<<"\n\nEnter your degree of burn: ";
    cin>>y;

    if(y == 1){
        cout<<"\nFIRST DEGREE BURN PATIENTS ARE SENT TO MEDICAL CAMP.1.";
        Camp1*newP = new Camp1;
        newP->name = n;
        newP->age = x;
        newP->degree = y;
        newP->exit = exitTaken;
    
        if(head1 == NULL){
            head1 = tail1 = newP;
        }else{
            if(head1->age <= newP->age ){
                newP->next = head1;
                head1 = newP;
            }else{
                Camp1*temp = head1;
                Camp1*prev = NULL;
                while(temp !=NULL && temp->age >= newP->age){
                    prev = temp;
                    temp = temp->next;
                }
                Camp1*t = prev->next;
                prev->next = newP;
                newP->next = t;
            }
        }
        A = A + 1;

    }else if(y == 2){
        cout<<"\nSECOND DEGREE BURN PATIENTS ARE SENT TO MEDICAL CAMP.2.";
        Camp2*newP = new Camp2;
        newP->name = n;
        newP->age = x;
        newP->degree = y;
        newP->exit = exitTaken;
        if(head2 == NULL){
            head2 = tail2 = newP;
        }else{
            if(head2->age <= newP->age ){
                newP->next = head2;
                head2 = newP;
            }else{
                Camp2*temp = head2;
                Camp2*prev = NULL;
                while(temp !=NULL && temp->age >= newP->age){
                    prev = temp;
                    temp = temp->next;
                }
                Camp2*t = prev->next;
                prev->next = newP;
                newP->next = t;
            }
        }
        B = B + 1;

    }else if(y == 3){
        cout<<"\nTHIRD DEGREE BURN PATIENTS ARE SENT TO MEDICAL CAMP.3.";
        Camp3*newP = new Camp3;
        newP->name = n;
        newP->age = x;
        newP->degree = y;
        newP->exit = exitTaken;
        if(head3 == NULL){
            head3 = tail3 = newP;
        }else{
            if(head3->age <= newP->age ){
                newP->next = head3;
                head3 = newP;
            }else{
                Camp3*temp = head3;
                Camp3*prev = NULL;
                while(temp !=NULL && temp->age >= newP->age){
                    prev = temp;
                    temp = temp->next;
                }
                Camp3*t = prev->next;
                prev->next = newP;
                newP->next = t;
            }
        }

        C = C + 1;
    }
    else{
        cout<<"\nINVALID INPUT!!";
    }
        return 0;
    }
    
    


}
void display(){
    int opt = 0;
    
    Camp1 * temp1 = head1;
    Camp2 * temp2 = head2;
    Camp3 * temp3 = head3;

    cout<<"\n\nMEDICAL CAMP.1 ---------------------------------------------- ";
    if(temp1 == NULL){
        cout<<"\nNO PATIENTS IN MEDICAL CAMP.1";
    }else{
        while(temp1 != NULL){
        cout<<"\n\nPATIENT NAME: "<<temp1->name;
        cout<<"\nAGE: "<<temp1->age;
        cout<<"\nBURN DEGREE: "<<temp1->degree;
        cout<<"\nThis patient left from exit no."<<temp1->exit;

        temp1 = temp1->next;
    }
    }
    cout<<"\n\nMEDICAL CAMP.2 ---------------------------------------------- ";
    if(temp2 == NULL){
        cout<<"\nNO PATIENTS IN MEDICAL CAMP.2";
    }
    else{
        while(temp2 != NULL){
        cout<<"\n\nPATIENT NAME: "<<temp2->name;
        cout<<"\nAGE: "<<temp2->age;
        cout<<"\nBURN DEGREE: "<<temp2->degree;
        cout<<"\nThis patient left from exit no."<<temp2->exit;

        temp2 = temp2->next;
    }
    }
    cout<<"\n\nMEDICAL CAMP.3 ---------------------------------------------- ";
    if(temp3 == NULL){
        cout<<"\nNO PATIENTS IN MEDICAL CAMP.3";
    }
    else{
        while(temp3 != NULL){
        cout<<"\n\nPATIENT NAME: "<<temp3->name;
        cout<<"\nAGE: "<<temp3->age;
        cout<<"\nBURN DEGREE: "<<temp3->degree;
        cout<<"\nThis patient left from exit no."<<temp3->exit;

        temp3 = temp3->next;
    }
    }

}
void clearList1(){
    if(head1 != NULL){
        Camp1*p = NULL;
    while(head1 != NULL){
        p = head1;
        head1 = head1->next;
        delete p;
    }
    A = 0;
    cout<<"\nPatients transported to the hospital.";
    }
    else{
         cout<<"\nMedical camp.1 is already empty.";
    }
}
void clearList2(){
    if(head2 != NULL){
        Camp2*p = NULL;
    while(head2 != NULL){
        p = head2;
        head2 = head2->next;
        delete p;
    }
    B = 0;
    cout<<"\nPatients transported to the hospital.";
    }else{
         cout<<"\nMedical camp.2 is already empty.";
    }
}
void clearList3(){
    if(head3 != NULL){
        Camp3*p = NULL;
    while(head3 != NULL){
        p = head3;
        head3 = head3->next;
        delete p;
    }
    C = 0;
    cout<<"\nPatients transported to the hospital.";
    }
    else{
        cout<<"\nMedical camp.3 is already empty.";
    }
}


