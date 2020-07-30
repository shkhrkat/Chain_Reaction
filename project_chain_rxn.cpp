#include<simplecpp>
//for calculating the max no. of critical mass that a position can hold
int mass(int m,int n)
{
    if((m==1&&(n==1||n==6)) || (m==9&&(n==1||n==6))) return 2;
    if(((m>=2 || m<=8) && n==1) || (m==1 && (n<=5 || n>=2)) || (m==9 && (n<=5 || n>=2)) | (n==6 && (m<=8 || m<=2))) return 3;
    else return 4;
}

bool check(int x,int y,int p,int a[11][8])
{ if (p==-1) {if (a[x][y]>=0) return true;
              else return false;}
  if (p==1) {if (a[x][y]<=0) return true;
             else return false;}
}

void pad(int a[][8])
{
        for(int i=0;i<8;i++)
        {
            a[0][i]=0;
            a[10][i]=0;
        }
        for(int i=0;i<11;i++)
        {
            a[i][0]=0;
            a[i][7]=0;
        }
}

bool lose(int a[][8])
{int r=0,s=0;
for (int i=1;i<10;i++)
    {for(int j=1;j<7;j++)
     if(a[i][j]>=0) ++r;
    }
for (int i=1;i<10;i++)
    {for(int j=1;j<7;j++)
     if(a[i][j]<=0) ++s;
    }
if (r==54||s==54) return true;
else return false;
}

    void gameplay(int m,int n,int p,int a[][8])
{int tap;
 tap=mass(m,n);
 if(abs(a[m][n])<tap)
 {if(p==-1) --a[m][n];
 if(p==1) ++a[m][n];
 }
if(abs(a[m][n])==tap)
    {a[m][n]=0;
    if(check(m-1,n,p,a))
     a[m-1][n]=-a[m-1][n]+p;
            else
            a[m-1][n]=a[m-1][n]+p;
    if(check(m+1,n,p,a))
     a[m+1][n]=-a[m+1][n]+p;
            else
            a[m+1][n]=a[m+1][n]+p;
    if(check(m,n-1,p,a))
     a[m][n-1]=-a[m][n-1]+p;
            else
            a[m][n-1]=a[m][n-1]+p;
    if(check(m,n+1,p,a))
     a[m][n+1]=-a[m][n+1]+p;
            else
            a[m][n+1]=a[m][n+1]+p;

            if(abs(a[m+1][n])==mass(m+1,n))
        gameplay(m+1 , n, p ,a);

        if(abs(a[m-1][n])==mass(m-1,n))
        gameplay(m-1 , n, p ,a);

        if(abs(a[m][n+1])==mass(m,n+1))
        gameplay(m , n+1, p ,a);

        if(abs(a[m][n-1])==mass(m,n-1))
        gameplay(m , n-1, p ,a);
    }
 pad(a);
}

main_program{
            int game[11][8],c=0;
             //game is the game board with a one tile padding,stores value at array position
            for(int i=0;i<11;i++)
                for(int j=0;j<8;j++)
                    game[i][j]=0;
                    //initializing every element of array to zero
            int x,y,player=-1;
             //player represents which one is playing
            while(true)
                {player=-player;
                 cin>>x>>y;
                if (x==-1) break;
               if(player==1)
               {
                   if(game[x+1][y+1]<0 || x<0 || x>=9 || y<0 || y>=6)
                               {cout<<"Illegal move"<<endl;
                                 player=-player;
                                 continue;
                                   }
                }
                if(player==-1)
                {
                    if(game[x+1][y+1]>0 || x<0 || x>=9 || y<0 || y>=6)
                               {cout<<"Illegal move"<<endl;
                                 player=-player;
                                 continue;
                                   }
                }

                gameplay(x+1,y+1,player,game);
                //for displaying the current position of game after every move
                for(int i=1;i<10;i++)
                    {
                        for(int j=1;j<7;j++)
                        {
                         cout<<game[i][j]<<" ";}
                            cout<<endl;
		  } cout<<endl;
if(lose(game)&& c!=0) break;
++c;
}
}

