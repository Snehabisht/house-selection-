


#include<iostream>
#include<vector>
#include<unistd.h>
#include<bits/stdc++.h>
#define v 19

using namespace std;


vector<pair<float,int>>returning_vectt(float key[], int n)
{
    vector<pair<float,int>> vect;
    for(int i=0;i<n;++i)
       vect.push_back(make_pair(key[i],i));
       sort(vect.begin(),vect.end());

       return vect;
}


int minDistance(float dist[], bool sptSet[],int n )
{

float min = INT_MAX;
int min_index;

for (int i = 0; i < n; ++i)
	if (sptSet[i] == false && dist[i] <= min)
		min = dist[i], min_index = i;

return min_index;
}




vector<pair<float,int>> dijkstra( int n,float graph[v][v],int src)
{
	float dist[n];

	bool sptSet[n];

	for (int i = 0; i < n; i++)
		dist[i] = INT_MAX, sptSet[i] = false;


	dist[src] = 0;


	for (int count = 0; count < n-1; count++)
	{

	int u = minDistance(dist, sptSet,n);


	sptSet[u] = true;


	for (int i= 0; i < n; i++)


		if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX
									&& dist[u]+graph[u][i] < dist[i])
			dist[i] = dist[u] + graph[u][i];
	}
    return (returning_vectt(dist,n));


}




vector<float> offices()
{   vector<float> vect2;

     float graph [v][v] = {
        {0,40,8,0,8,0,0,0,0,0,0,0,8,0,0,0,2,0,0},
        {40,0,110,80,110,0,0,0,0,0,0,0,100,120,0,0,0,90,0},
        {8,110,0,0,1,2,6,2,0,0,11,0,8,0,0,3,0,0,0},
        {0,80,0,0,0,0,7,4,0,7,2,0,0,8,0,0,0,0,0},
        {0,110,1,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,6,7,7,0,0,0,0,0,0,9,0,0,0,0,0,0,0},
        {0,0,2,4,0,0,0,0,10,14,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,10,0,9,4,0,0,0,0,0,0,0,0},
        {0,0,0,7,0,0,0,14,9,0,1,0,0,0,0,0,0,0,0},
        {0,0,11,2,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,9,0,0,0,0,0,2,3,0,0,0,0,0},
        {8,100,8,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
        {0,120,0,8,0,0,0,0,0,0,0,3,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,9},
        {0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
        {0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,3,2,0}
    };
        for(int i=0;i<3;++i)
    {
    vector<pair<float, int>> vect = dijkstra(v,graph,i);
     for(int j=0;j<19;++j)
     {   if(vect[j].second==11||vect[j].second==12||vect[j].second==13||vect[j].second==14)

              {
                  //cout << "For house " << i+1 << " office " << vect[j].second-3 << " is at minimum distance of " << vect[j].first << "\n";
                vect2.push_back(vect[j].first);

                  break;
              }

     }
    }


return vect2;
}

vector<float> markets()
{   vector<float> vect2;



    float graph[v][v] = {
        {0,40,8,0,8,0,0,0,0,0,0,0,8,0,0,0,2,0,0},
        {40,0,110,80,110,0,0,0,0,0,0,0,100,120,0,0,0,90,0},
        {8,110,0,0,1,2,6,2,0,0,11,0,8,0,0,3,0,0,0},
        {0,80,0,0,0,0,7,4,0,7,2,0,0,8,0,0,0,0,0},
        {0,110,1,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,6,7,7,0,0,0,0,0,0,9,0,0,0,0,0,0,0},
        {0,0,2,4,0,0,0,0,10,14,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,10,0,9,4,0,0,0,0,0,0,0,0},
        {0,0,0,7,0,0,0,14,9,0,1,0,0,0,0,0,0,0,0},
        {0,0,11,2,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,9,0,0,0,0,0,2,3,0,0,0,0,0},
        {8,100,8,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
        {0,120,0,8,0,0,0,0,0,0,0,3,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,9},
        {0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
        {0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,3,2,0}};
    for(int i=0;i<3;++i)
    {
    vector<pair<float, int>> vect = dijkstra( v,graph,i);
     for(int j=0;j<19;++j)
     {   if(vect[j].second==7||vect[j].second==8||vect[j].second==9||vect[j].second==10)

              {
                  //cout << "For house " << i+1 << " market " << vect[j].second-3 << " is at minimum distance of " << vect[j].first << "\n";
                vect2.push_back(vect[j].first);

                  break;
              }

     }
    }


return vect2;
}

vector<float> hospitals()
{   vector<float> vect2;

    float graph[v][v] = {
        {0,40,8,0,8,0,0,0,0,0,0,0,8,0,0,0,2,0,0},
        {40,0,110,80,110,0,0,0,0,0,0,0,100,120,0,0,0,90,0},
        {8,110,0,0,1,2,6,2,0,0,11,0,8,0,0,3,0,0,0},
        {0,80,0,0,0,0,7,4,0,7,2,0,0,8,0,0,0,0,0},
        {0,110,1,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,6,7,7,0,0,0,0,0,0,9,0,0,0,0,0,0,0},
        {0,0,2,4,0,0,0,0,10,14,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,10,0,9,4,0,0,0,0,0,0,0,0},
        {0,0,0,7,0,0,0,14,9,0,1,0,0,0,0,0,0,0,0},
        {0,0,11,2,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,9,0,0,0,0,0,2,3,0,0,0,0,0},
        {8,100,8,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
        {0,120,0,8,0,0,0,0,0,0,0,3,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,9},
        {0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
        {0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,3,2,0}
    };
        for(int i=0;i<3;++i)
    {
    vector<pair<float, int>> vect = dijkstra(v,graph,i);
     for(float j=0;j<19;++j)
     {   if(vect[j].second==14||vect[j].second==15||vect[j].second==16||vect[j].second==17)

              {
                  //cout << "For house " << i+1 << " hospital " << vect[j].second-3 << " is at minimum distance of " << vect[j].first << "\n";
                vect2.push_back(vect[j].first);

                  break;
              }

     }
    }


return vect2;
}

vector<float> schools()
{   vector<float> vect2;



    float graph[][v] = {
        {0,40,8,0,8,0,0,0,0,0,0,0,8,0,0,0,2,0,0},
        {40,0,110,80,110,0,0,0,0,0,0,0,100,120,0,0,0,90,0},
        {8,110,0,0,1,2,6,2,0,0,11,0,8,0,0,3,0,0,0},
        {0,80,0,0,0,0,7,4,0,7,2,0,0,8,0,0,0,0,0},
        {0,110,1,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,6,7,7,0,0,0,0,0,0,9,0,0,0,0,0,0,0},
        {0,0,2,4,0,0,0,0,10,14,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,10,0,9,4,0,0,0,0,0,0,0,0},
        {0,0,0,7,0,0,0,14,9,0,1,0,0,0,0,0,0,0,0},
        {0,0,11,2,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,9,0,0,0,0,0,2,3,0,0,0,0,0},
        {8,100,8,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
        {0,120,0,8,0,0,0,0,0,0,0,3,2,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,9},
        {0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
        {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,3},
        {0,90,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,2},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0,3,2,0}
    };

    for(int i=0;i<3;++i)
    {
    vector<pair<float, int>> vect =  dijkstra( v,graph, i);
     for(float j=0;j<19;++j)
     {   if(vect[j].second==3||vect[j].second==4||vect[j].second==5||vect[j].second==6)
              {
                  //cout << "For house " << i+1 << " school " << vect[j].second-3 << " is at minimum distance of " << vect[j].first << "\n";
                vect2.push_back(vect[j].first);

                  break;
              }

     }
    }


return vect2;
}

float** distances()
{

    float **new_ptr = new float*[4];
    for (int i = 0; i < 4; i++) {
        new_ptr[i] = new float[3];
    }

    vector<vector<float>> p;
    p.push_back(schools());
    p.push_back(hospitals());
    p.push_back(markets());
    p.push_back(offices());
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < p[i].size(); j++) {
            new_ptr[i][j] = p[i][j];
        }
    }
    return new_ptr;
}


float **get_distance()
{
    float** vec=distances();
   /* for (int i = 0; i < vec.size(); i++)
{
    for (int j = 0; j < vec[i].size(); j++)
    {
        cout << vec[i][j];
    }
}*/
  //cout<<vect[2][0]<<" "<<vect[2][1]<<" "<<vect[2][2]<<" ";
  float** vect = new float*[3];
  for (int i = 0; i < 3; i++) {
      vect[i] = new float[4];
  }
  for (int i = 0; i <3 ; i++)
    {
        for (int j = 0; j < 4; j++)
            vect[i][j]=vec[j][i];
        //cout << "\n ";
    }

  return vect;
  //return 0;
}

struct comb
{
    int h;
    float p;
};

struct cp
{
    struct comb f[3][2];
    float checkpoint[3][3];

};
void combination(int arr[],struct cp point[4],float** h,int no_of_checkpoints);// function to compare the houses pairwise
void set_priority(int m,int n,int x,int y,float** h,struct cp point[4] ,int checkpoint_no);// compares the priorities pairwise and assign them in a table
void col_row(float col[4][3],float row[3][4],struct cp point[4]);
int final_priority(float row[3][4],int priority[4]);

int main()

{
  		system("dot -Tpng -O colour_graph.dot");
 system("xdg-open colour_graph.dot.png");

int no_of_checkpoints=4;
struct cp point[4];//array which stores the pairwise comparison tables of all the checkpoints
int priority[no_of_checkpoints];// array to store the priorities input by the user
cout<<"1=school"<<endl<<"2=office"<<endl<<"3=hospital"<<endl<<"4=market"<<endl;
cout<<"enter priority of checkpoints"<<endl;
for(int i=0;i<no_of_checkpoints;i++)
{
    cout<<"priority of "<<i<<"th checkpoint=";
    cin>>priority[i];
}
    int arr[3]={0,1,2};
//struct comb f[3][2];

    float** h= get_distance();

     /*{{100,300,200,400},
                {200,500,100,300},
                {200,100,400,300}};*/

    combination(arr,point,h,no_of_checkpoints);

    for(int z=0;z<4;z++)
    {//cout<<endl<<"first table of"<<z+1<<"th priority"<<endl;
        for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
           // cout<<point[z].f[i][j].h<<" "<<point[z].f[i][j].p<<"  ";
        }
        cout<<endl;
    }   }

for(int z=0;z<no_of_checkpoints;z++)
{
    for(int i=0,k=-1;i<3;i++)
{k++;
    for(int j=0;j<3;j++)
    {
        if(i==j)
        {
            point[z].checkpoint[i][j]=1;
        }
        if(i<j)
        {
            point[z].checkpoint[i][j]=(point[z].f[k][0].p/point[z].f[j-1][1].p);
            k++;
        }
        if(i>j)
        {
            point[z].checkpoint[i][j]=(1/point[z].checkpoint[j][i]);
            k--;
        }
    }
}
}

//cout<<endl<<"second table "<<endl;
for(int z=0;z<4;z++)
{// cout<<endl<<z<<"th priority"<<endl;
    for(int i=0,k=-1;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        //cout<<point[z].checkpoint[i][j]<<" ";
    }
   // cout<<endl;
}}

float col[4][3],row[3][4];
col_row (col , row,point );
//final_priority(row,priority);
cout<<endl<<"According to the priorities set by the user"<<endl<<" and the shortest distances calculated the house selected is "<<(final_priority(row,priority)+1)<<" (shown in grey)\n";

if(final_priority(row,priority)==0)
   { system("dot -Tpng -O colour_graph1.dot");
 system("xdg-open colour_graph1.dot.png");
   }
   if(final_priority(row,priority)==1)
   { system("dot -Tpng -O colour_graph2.dot");
 system("xdg-open colour_graph2.dot.png");
   }
   if(final_priority(row,priority)==2)
   { system("dot -Tpng -O colour_graph3.dot");
 system("xdg-open colour_graph3.dot.png");
   }
   return 0;
}
void set_priority(int m,int n,int x,int y,float** h,struct cp point[4],int checkpoint_no)
{
    if(h[m][checkpoint_no]==h[n][checkpoint_no])
    {
        point[checkpoint_no].f[x][y-1].p=1;
        point[checkpoint_no].f[x][y].p=1;
    }
    if(h[m][checkpoint_no]>h[n][checkpoint_no])
    {
        point[checkpoint_no].f[x][y-1].p=1;
        point[checkpoint_no].f[x][y].p=(h[m][checkpoint_no]/h[n][checkpoint_no]);
    }
    else if(h[m][checkpoint_no]<h[n][checkpoint_no])
    {
        point[checkpoint_no].f[x][y].p=1;
        point[checkpoint_no].f[x][y-1].p=(h[n][checkpoint_no]/h[m][checkpoint_no]);
    }
}

void combination(int arr[],struct cp point[4],float** h,int no_of_checkpoints)
{int x=0,y;
for(int z=0;z<no_of_checkpoints;z++)
        {x=0;
            for(int i = 0; i<2; i++)
            {for(int j = i+1; j<3; j++)
                {   y=0;
                    point[z].f[x][y].h=arr[i];
                    y++;
                    point[z].f[x][y].h=arr[j];
                    for(int k=0;k< no_of_checkpoints;k++ )
                    {set_priority(arr[i],arr[j],x,y,h,point,k);}
                    x++;
                    }
                        }
                            }
}

void col_row(float col[4][3],float row[3][4],struct cp point[4])//function to calculate sum of columns and weight criteria(i.e. (all values/col sum) and then avg of the rows
{

for(int z=0;z<4;z++)
{for(int i=0;i<4;i++)
{
    col[z][i]=0;
    row[i][z]=0;
}
}
for(int z=0;z<4;z++)
{for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        col[z][i]=col[z][i]+point[z].checkpoint[j][i];
    }

}}
//cout<<endl<<"col sum"<<endl;
for(int z=0;z<4;z++)
{//cout<<endl<<"col sum of"<<z<<"th priority"<<endl;
    for(int i=0;i<3;i++)
{
   // cout<<col[z][i]<<endl;
}}

for(int z=0;z<4;z++)
{for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        point[z].checkpoint[i][j]=(point[z].checkpoint[i][j]/col[z][j]);
        row[i][z]=row[i][z]+point[z].checkpoint[i][j];
    }
    row[i][z]=row[i][z]/3;
}}
for(int z=0;z<4;z++)
{//cout<<endl<<"third table of "<<z<<"th priority"<<endl;
    for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        //cout<<point[z].checkpoint[i][j]<<" ";
    }
   // cout<<endl;
}}
//cout<<endl<<"row sum average"<<endl;
for(int z=0;z<4;z++)
{//cout<<endl<<"row sum of"<<z<<"th priority"<<endl;
    for(int i=0;i<3;i++)
{
    //cout<<row[i][z]<<" ";
}
//cout<<endl;
}
}

int final_priority(float row[3][4],int priority[4])
{ float arr[3][4];
float sum[3]={0,0,0};
for(int z=0;z<4;z++)
{
    for(int i=0;i<3;i++)
    {
        arr[i][z]=priority[z]*row[i][z];
       //cout<<arr[i][z]<<" ";
    }

    //cout<<endl;
}

//cout<<endl<<"sum"<<endl;
float max_val=0,val=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            sum[i]=sum[i]+arr[i][j];

        }
        //cout<<sum[i]<<" ";
        if(sum[i]>max_val)
            {max_val=sum[i];
                val=i;}
    }
    //cout<<max_val;
  return (val);

}
