#ifndef svg_sink_hpp
#define svg_sink_hpp

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
      cout<<"<?xml version='1.0' encoding='UTF-8'?>"<<endl;
      cout<<"<svg xmlns='http://www.w3.org/2000/svg' "; // height='256' width='256'"<<endl;
      cout<<"  viewBox='-1.1 -1.1 2.2 2.2' >" << endl;
        float t=m_t0;
        while(t<m_t1){
          cout << "  <line x1 = '"<<t<<"' y1 = '"<<wave->evaluate(t)<<"' x2 = '"<<t+m_dt<<"' y2 = '"<<wave->evaluate(t+m_dt)<<"' stroke = 'black' stroke-width = '"<<0.001<<"'/>" << endl;
            t += m_dt;
        }
    }
};

#endif
