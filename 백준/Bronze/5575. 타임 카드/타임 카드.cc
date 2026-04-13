# include <iostream>
using namespace std;

struct Time{
    int time;

    Time(int& h, int& m, int& s){
        this->time = (60*h + m) * 60 + s;
    }

    Time operator-(Time& time){
        Time res = *this;
        res.time -= time.time;

        return res;
    }

    void print(){
        int time = this->time;
        int h, m, s;
        s = time%60;    time /= 60;
        m = time%60;    time /= 60;
        h = time;
        cout << h << ' ' << m << ' ' << s << '\n';
    }
};

int main(void){
    for (int i=0; i<3; i++){
        int h1, m1, s1, h2, m2, s2; cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
        Time in = Time(h1, m1, s1), out = Time(h2, m2, s2);
        (out-in).print();
    }
}