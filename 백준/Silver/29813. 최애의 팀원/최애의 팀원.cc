# include <iostream>
# include <vector>
# include <queue>
# include <string>
using namespace std;

struct Student{
    string name;
    int code;
    Student(string n, int c){
        name = n;
        code = c;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    
    int n;  cin >> n;
    queue<Student> q;
    for (int i=0; i<n; i++){
        string name;
        int code;
        cin >> name >> code;
        Student s(name, code);
        q.push(s);
    }

    while (q.size() > 1){
        Student s = q.front();  q.pop();

        for (int i=0; i<s.code-1; i++){
            Student t = q.front();  q.pop();
            q.push(t);
        }
        q.pop();
    }
    cout << q.front().name << '\n';
}