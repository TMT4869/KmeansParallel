#include <iostream>
#include <fstream>
#include "Point.h"
#include "Cluster.h"
using namespace std;

int num_pt = 100000;
int  num_cl = 20;
int iterations = 20;
double max_value = 100000;
int num_threads = 0;

vector<Point> create_point(int num_pt);
void create_file(vector<Point>& points);

int main() {
    vector<Point> vec = create_point(num_pt);
    create_file(vec);

	return 0;
}

// create number of points equal to num_py
vector<Point> create_point(int num_pt) {
    vector<Point>pts(num_pt);
    Point* ptr = &pts[0];
    for (int i = 0; i < num_pt; ++i) {
        Point* point = new Point(rand() % (int)max_value, rand() % (int)max_value);
        // assign the value of *point to ptr[i] that points to &pts
        ptr[i] = *point;
    }
    return pts;
}

void create_file(vector<Point>& points) {
    ofstream Myfile("data.txt");
    Myfile << num_pt << endl;
    Myfile << num_cl << endl;
    Myfile << iterations << endl;
    Myfile << max_value << endl;
    Myfile << num_threads << endl;

    for (int i = 0; i < points.size(); i++) {

        Point point = points[i];
        Myfile << point.get_x() << ", " << point.get_y() << endl;
    }

    Myfile.close();
}
