#include<bits/stdc++.h>
using namespace std;


void displayPoint(pair<double,double> P)
{
    cout << "(" << P.first << "," << P.second << ")" << endl;
}

pair<double,double> lineLineIntersection(pair<double,double> A,pair<double,double>B,pair<double,double>C,pair<double,double>D)
{
    //Line AB represented as a1x + b1y = c1
    double a1 = (B.second - A.second);
    double b1 = (A.first - B.first);
    double c1 = a1*(A.first) + b1*(A.second);

    //Line CD represented as a2x + b2y = c2
    double a2 = (D.second - C.second);
    double b2 = (C.first - D.first);
    double c2 = a2*(C.first) + b2*(C.second);

    double determinant = a1*b2 - a2*b1;

    if(determinant == 0)
    {
        return make_pair(FLT_MAX,FLT_MAX);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x,y);
    }
}

int main()
{
    pair<double,double>A = make_pair(1,1);
    pair<double,double>B = make_pair(4,4);
    pair<double,double>C = make_pair(1,8);
    pair<double,double>D = make_pair(2,4);

    pair<double,double> intersection = lineLineIntersection(A,B,C,D);

    if(intersection.first == FLT_MAX && intersection.second == FLT_MAX)
    {
        cout << "The given lines AB and CD are parallel.\n";
    }
    else
    {
        cout << "The intersection of the given lines AB and CD is : ";
        displayPoint(intersection);
    }
    return 0;
}