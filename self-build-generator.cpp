#include <bits/stdc++.h>
#define ll long long

using namespace std;

ifstream ifs;
ofstream file;
string dir_name = "../testdata/03_";//path

int fileId = 0;

void make_file() { // 建立檔案
    int sum = 0, cnt = 0;
    while (1) {
        string filename;
        if (fileId < 10) 
            filename += "0";
        filename += to_string(fileId);
        cerr << filename << endl;
        ifs.open(dir_name + filename + ".in");
        if (!ifs.is_open()) {
            file.open(dir_name + filename + ".in");
            fileId++;
            break;
        }
        
        ifs.close();
        fileId++;
    }
}
random_device rd;
auto tt = chrono::high_resolution_clock::now();
std::mt19937_64 gen = std::mt19937_64(tt.time_since_epoch().count());
std::uniform_int_distribution<> dis_int(1, 2000000000);
auto randint = bind(dis_int, gen);

std::uniform_real_distribution<> dis_float(0, 1);
auto randfloat = bind(dis_float, gen);

#define MAXN 100000
#define MAXM 100000
#define MAXXY 1000000001

#define MAKE 1
#if MAKE
#define cout file
#endif

int n, m, a, b, x, y;
int w[MAXN];

void make() {
    n = MAXN, m = MAXM;
    vector<int> choise;
    for (int i = 1; i <= n; i++)
        choise.push_back(i);
    a = randint() % (n + 1);
    b = randint() % (n + 1);
    x = randint() % MAXXY;
    y = randint() % MAXXY;
    cout << n << " " << m << " " << a << " " << b << " " << x << " " << y << endl;

    random_shuffle(choise.begin(), choise.end());
    for (int i = 0; i < a; i++)
        cout << choise[i] << " ";
    cout << endl;

    random_shuffle(choise.begin(), choise.end());
    for (int i = 0; i < b; i++)
        cout << choise[i] << " ";
    cout << endl;

    for (int i = 0; i < m; i++) {
        w[i] = randint() % n + 1;
        cout << w[i] << " ";
    }
    cout << endl;
}

int main()
{
    int N = 30;
    while (N--) {
        make_file();
        int t = 1;
        while (t--)
            make();
        file.close();
    }
    return 0;
}
