#include<iostream>
using namespace std;
struct comb
{
    int h;
    float p;
};
void combination(int arr[],struct comb f[3][2],int h[3][4],int no_of_checkpoints);// function to compare the houses pairwise
void set_priority(int m,int n,int x,int y,int h[3][4],struct comb f[3][2],int checkpoint_no);// compares the priorities pairwise and assign them in a table

int main()
{int no_of_checkpoints=4;
int priority[no_of_checkpoints];
cout<<"1=school"<<endl<<"2=office"<<endl<<"3=hospital"<<endl<<"4=market"<<endl;
cout<<"enter priority of checkpoints";
for(int i=0;i<no_of_checkpoints;i++)
{
    cout<<"priority of "<<i<<"th checkpoint=";
    cin>>priority[i];
}
    int arr[3]={0,1,2};
struct comb f[3][2];

    int h[3][4]={{100,300,200,400},
                {200,500,100,300},
                {200,100,400,300}};
        combination(arr,f,h,no_of_checkpoints);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<f[i][j].h<<" "<<f[i][j].p<<"  ";
        }
        cout<<endl;
    }
float school[3][3];
for(int i=0,k=-1;i<3;i++)
{ k++;
    for(int j=0;j<3;j++)
    {
        if(i==j)
        {
            school[i][j]=1;
        }
        if(i<j)
        {
            school[i][j]=(f[k][0].p/f[j-1][1].p);
            k++;
        }
        if(i>j)
        {
            school[i][j]=(1/school[j][i]);
            k--;
        }
    }
}
cout<<"school"<<endl;
float col[3];
for(int i=0;i<3;i++)
{
    col[i]=0;
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<school[i][j]<<" ";
        col[j]=col[j]+school[i][j];
    }
    cout<<endl;
}
cout<<endl<<"col sum"<<endl;
for(int i=0;i<3;i++)
{
    cout<<col[i]<<endl;
}
float row[3];
for(int i=0;i<3;i++)
{
    row[i]=0;
}
cout<<endl<<"new school"<<endl;
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        school[i][j]=(school[i][j]/col[j]);
        row[i]=row[i]+school[i][j];
    }
    row[i]=row[i]/3;
}
for(int i=0;i<3;i++)
{
    for(int j=0;j<3;j++)
    {
        cout<<school[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl<<"row sum"<<endl;
for(int i=0;i<3;i++)
{
    cout<<row[i]<<endl;
}


}

void set_priority(int m,int n,int x,int y,int h[3][4],struct comb f[3][2],int checkpoint_no)
{
    if(h[m][0]==h[n][0])
    {
        f[x][y-1].p=1;
        f[x][y].p=1;
    }
    if(h[m][0]>h[n][0])
    {
        f[x][y-1].p=1;
        f[x][y].p=(h[m][0]/h[n][0]);
    }
    else if(h[m][0]<h[n][0])
    {
        f[x][y].p=1;
        f[x][y-1].p=(h[n][0]/h[m][0]);
    }
}

void combination(int arr[],struct comb f[3][2],int h[3][4],int no_of_checkpoints)
{int x=0,y;
        for(int i = 0; i<2; i++)
            {for(int j = i+1; j<3; j++)
                {   y=0;
                    f[x][y].h=arr[i];
                    y++;
                    f[x][y].h=arr[j];
                    for(int k=0;k< no_of_checkpoints;k++ )
                    {set_priority(arr[i],arr[j],x,y,h,f,k);}
                    x++;
                    }
                        }
                            }

