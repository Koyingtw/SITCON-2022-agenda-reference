#include "testlib.h"

using namespace std;

int mp[15][15];

int new_mp[15][15];

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
    
    int n = inf.readInt();
    
    int q = inf.readInt();
    
    for(int i=0;i<q;i++)
    {
        int x = inf.readInt();
        
        int y = inf.readInt();
        
        mp[x][y]++;    
    }

    string s = ouf.readString();
    
    for(int i=0;i<s.size();i++)
    {
        if( s[i] >= '1' && s[i] <= '4' ) continue;
        
        quitf(_wa,"you used illegal operations.");
    }
    
    if( s.size() > 4 * n ) quitf(_wa,"you used too many operations.");
    
    int move_x[4] = {-1,1,0,0};
    
    int move_y[4] = {0,0,-1,1};
    
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            if( mp[i][k] != 0 )
            {
                int x = i,y = k;
                
                bool start = false;
                
                for(int j=0;j<s.size();j++)
                {
                    int index = s[j] - '0' - 1;
                    
                    int u1 = x + move_x[index];
                    
                    int u2 = y + move_y[index];
                    
                    if( u1 <= 0 || u2 <= 0 || u1 > n || u2 > n ) continue;
                    
                    x = u1;
                    
                    y = u2;
                    
                    if( x == 1 && y == 1 && start == false )
                    {    
                        start = true;
                    }
                }
                
                if( start == false || x != n || y != n ) quitf(_wa,"mission failed :(");
            }
        }
    }
    
    quitf(_ok,"well done!");
    
    return 0;
}