#ifndef drawing_hpp
#define drawing_hpp

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cfloat>
#include <cassert>

using namespace std;

struct Polygon
{
    string colour;
    vector<float> x;
    vector<float> y;
};

struct Drawing
{
    float min_x, max_x;
    float min_y, max_y;
    vector<Polygon> shapes;

    /* Construct a new drawing. */
    Drawing()
    {
        // Bounds are initialised to maximum/minimum possible.
        min_x=FLT_MAX;
        max_x=-FLT_MAX;
        min_y=FLT_MAX;
        max_y=-FLT_MAX;
    }

    void destroy()
    {
        // Currently there is nothing interesting to do here apart from deallocate the object.
    }

    // Add a copy of the given polygon instance to the drawing.
    void add_polygon(Polygon p)
    {
        int len=p.x.size(); // Number of points in the polygon

        // min_element finds the smallest element in a range of pointers
        float *pMin=min_element( &p.x[0], &p.x[len] );
        min_x = min( min_x, *pMin);

        // Contracted version of the above
        max_x = max( max_x, *max_element( &p.x[0], &p.x[len] ) );
        min_y = min( min_y, *min_element( &p.y[0], &p.y[len] ) );
        max_y = max( max_y, *max_element( &p.y[0], &p.y[len] ) );

        shapes.push_back(p);
    }

    // Adds a square with corners at (x1,y1) to (x2,y2)
    void add_square(string colour, float x1, float y1, float x2, float y2)
    {
        Polygon square={colour,
            {x1,x2,x2,x1},
            {y1,y1,y2,y2}
            };
        add_polygon(square);
    }

    // Adds a triangle with vertices at (x1,y1), (x2,y2), (x3,y3)
    void add_triangle(string colour, float x1, float y1, float x2, float y2, float x3, float y3)
    {
        Polygon square={colour,
            {x1,x2,x3},
            {y1,y2,y3}
            };
        add_polygon(square);
    }

    // Adds a circle centered at (x,y) with radius r
    void add_circle(string colour, float x, float y, float r)
    {
        Polygon circle;
        circle.colour=colour;
        int n=16; // Currently we don't implement a true circle, it is actually a polygon
        float PI2=6.2831853f;
        for(int i=0; i<n; i++){
            float fraction=i/float(n);
            circle.x.push_back( x + sin(fraction*PI2) * r );
            circle.y.push_back( y + cos(fraction*PI2) * r );
        }
        add_polygon(circle);
    }

    // This writes the current drawing out to cout in SVG format
    void write_svg()
    {
        assert(!shapes.empty());

        float off_x=min_x;
        float off_y=min_y;
        float width=max_x-min_x;
        float height=max_y-min_y;

        while(min(width,height) < 256){
            width=width*1.5;
            height=height*1.5;
        }

        while(max(width,height) > 1024){
            width=width/1.5;
            height=height/1.5;
        }

        cout<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
        cout<<"<svg xmlns='http://www.w3.org/2000/svg' height='"<<height<<"' width='"<<width<<"'"<<endl;
        cout<<"  viewBox='"<<min_x<<" "<<min_y<<" "<<max_x-min_x<<" "<<max_y-min_y<<"' >" << endl;
        for(unsigned i=0; i<shapes.size(); i++){
            cout<<"  <polygon style='fill:"<<shapes[i].colour<<"' points='";
            for(unsigned j=0; j<shapes[i].x.size(); j++){
                cout<<" "<<shapes[i].x[j]<<","<<shapes[i].y[j];
            }
            cout<<"' />"<<endl;
        }
        cout<<"</svg>"<<endl;
    }
};

#endif
