#include <iostream>
using namespace std;
using ll = long long;
struct point
{
    ll x, y;
} p1, p2, p3, p4;
int ccw(const point &a, const point &b, const point &c)
{
    ll ret = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (ret < 0)
        return -1;
    else if (ret > 0)
        return 1;
    else
        return 0;
}
bool isLine(int a, int b, int c, int d)
{
    if (a > b) // b가 더 크게
    {
        swap(a, b);
    }
    if (c > d) // d가 더 크게
    {
        swap(c, d);
    }
    return (a <= d && b >= c) || (c <= b && d >= a); // 좌표의 대소 관계 확인
}
bool isCross()
{
    // ccw 구하기
    int z1 = ccw(p1, p2, p3);
    int z2 = ccw(p1, p2, p4);
    int z3 = ccw(p3, p4, p1);
    int z4 = ccw(p3, p4, p2);

    if (z1 * z2 == 0 && z3 * z4 == 0) // 같은 선상에 있는 경우
    {
        return isLine(p1.x, p2.x, p3.x, p4.x) && isLine(p1.y, p2.y, p3.y, p4.y);
    }

    return z1 * z2 <= 0 && z3 * z4 <= 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    cout << isCross();
    return 0;
}