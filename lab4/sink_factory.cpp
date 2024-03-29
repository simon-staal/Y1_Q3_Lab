#include "sink_factory.hpp"

#include "csv_sink.hpp"
#include "svg_sink.hpp"

const Sink *sink_factory(const factory_parameters &spec)
{
    if(spec.verb=="csv"){
        return new CSVSink(spec);
    }else if(spec.verb=="svg"){
        return new SVGSink(spec);
    }else{
        cerr<<"Didn't understand sink spec verb '"<<spec.verb<<endl;
        exit(1);
    }
}
