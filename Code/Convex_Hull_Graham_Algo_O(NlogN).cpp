#include<bits/stdc++.h>
using namespace std;
#define nl '\n';

struct Point
{
    int x,y;
};

/*A global point needed for sorting points with reference
to the first point used in compare function of qsort()
*/
Point p0;

//A utility function to find next to top in the stack
Point nextToTop(stack<Point> &S){
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

//A utility function to swap two points
void swap(Point &p1,Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

//A utility function to return square of distance b/w p1 and p2
int disSq(Point p1,Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y); 
}

/*To find orientation of ordered triplet (p,q,r).
The function returns following values
0---> p,q and r are collinear
1 --> Clockwise
2 ---> Counterclockwise
*/
int orientation(Point p,Point q,Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0;//collinear
    return (val > 0)?1:2;
}

/*A cunction used to library function qsort() to sort an array of point
with respect to the first poin */
int compare(const void *vp1,const void *vp2){
    Point *p1 = (Point *)vp1;
    Point *p2 = (Point *)vp2;

    //fint orientation
    if(orientation(p0,*p1,*p2) == 0)
        return (disSq(p0,*p2) >= disSq(p0,*p1))? -1 : 1;
    return (orientation(p0,*p1,*p2) == 2)? -1 : 1;
}
//Prints convex hull of a set of n points.
void convexhull(Point points[],int n){
    //find the bottommost point
    int ymin = points[0].y,min = 0;
    for(int i = 1;i < n;i++){
        int y = points[i].y;

        //pick the bottom-most or choose the left most point in case of tie
        if((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y,min = i;
    }

    //Place the bottom-most point at first poisition
    swap(points[0],points[min]);

    //Sort n-1 point with respect to the first poin.
    //A point p1 comes before p2 in sorted output if p2
    //has larger polar angle(int counterclockwise direction) than p1
    p0 = points[0];
    qsort(&points[1],n-1,sizeof(Point),compare);

    /* If two or more points make same angle with p0, Remove all but the one that is farthest from p0
    remember that,in above sorting, our criteria was to keep the farthest poin at the end when more than one points have same angle.*/

    int m = 1;//Initialize size of modified array
    for(int i = 1;i < n;i++){
        //keep removing i while angle of i and i + 1 is same with respect to p0
        while(i < n-1 && orientation(p0,points[i],points[i+1])==0)
            i++;
        points[m] = points[i];
        m++;//update size of modified array
    }

    if(m < 3) return;

    //create an empty stack and push first three points to it.

    stack<Point>S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    //Process remaining n-1 points
    for(int i = 3;i < m;i++){
        //Keep removing top while the angle formed by 
        //points next to top,top, and points[i] makes a non-left turn
        while(S.size() > 1 && orientation( nextToTop(S),S.top(),points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    //Now stack has the output points , print contents of stack
    while(!S.empty()){
        Point p = S.top();
        cout << p.x << " " << p.y << nl;
        S.pop();
    }

}

int main()
{
    int n;
    cin >> n;
    Point points[n];
    for(int i = 0;i < n;i++){
        cin >> points[i].x >> points[i].y;
    }
    convexhull(points,n);
    return 0;
}