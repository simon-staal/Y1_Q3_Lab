#ifndef svg_sink_hpp
#define svg_sink_hpp

#include <algorithm>
#include "sink.hpp"

#include "factory_parameters.hpp"

/* Represents something that consumes or outputs a wave
*/
class SVGSink
    : public Sink
{
public:
    float m_t0;
    float m_t1;
    float m_dt;

public:
    SVGSink(const factory_parameters &p)
    {
        m_t0=p.get_float_arg(0, -10.0);
        m_t1=p.get_float_arg(1, 10.0);
        m_dt=p.get_float_arg(2, 0.1);
    }

    void output(const Wave *wave) const
    {
      float t=m_t0;
      vector<float> y;
      while(t<m_t1){
        y.push_back(wave->evaluate(t));
        t += m_dt;
      }
      float min = *min_element(y.begin(), y.end());
      float max = *max_element(y.begin(), y.end());
      float k = 1.25;
      float width = k*(m_t1 - m_t0);
      float height = k*(max - min);
      float x_min = m_t0 - 0.5*(width - (m_t1 - m_t0));
      float y_min = min - 0.5*(height - (max - min));
      cout<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
      cout<<"<svg xmlns='http://www.w3.org/2000/svg' "; // height='256' width='256'"<<endl;
      cout<<"  viewBox='"<<x_min<<" "<<y_min<<" "<<width<<" "<<height<<"' >" << endl;
        t=m_t0;
        for(int i = 0; i<y.size(); i++){
          cout << "  <line x1 = '"<<t<<"' y1 = '"<<y[i]<<"' x2 = '"<<t+m_dt<<"' y2 = '"<<y[i+1]<<"' stroke = 'black' stroke-width = '"<<0.01<<"'/>" << endl;
          t += m_dt;
        }
        cout<<"</svg>"<<endl;
    }
};

#endif
