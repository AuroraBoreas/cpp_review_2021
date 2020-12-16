#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Parcel
{
private:
    unsigned int prio;
    string info;
public:
    Parcel(unsigned int n, const string& s)
    : prio(n), info(s) {}
    // op ol
    friend bool operator<(const Parcel& x, const Parcel& y)
    {
        return (x.prio < y.prio);
    }
    friend ostream& operator<<(ostream& os, const Parcel& x)
    {
        os << x.prio << " " << x.info << endl;
        return os;
    }
};

int main()
{
    priority_queue<Parcel> pq;
    pq.push(Parcel(7, "Bob"));
    pq.push(Parcel(1, "ZL"));
    pq.push(Parcel(4, "Susan"));

    while(!pq.empty())
    {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}
