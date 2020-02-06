#ifndef sin_wave_hpp
#define sin_wave_hpp

#include "wave.hpp"

#include "factory_parameters.hpp"

#include <cmath>
#include <vector>
#include <string>

class SinWave
    : public Wave
{
private:
    float m_frequency;
    float m_amplitude;
    float m_phase;
public:
    SinWave(const factory_parameters &params)
    {
        m_frequency=params.get_float_arg(0, 1.0);
        m_amplitude=params.get_float_arg(1, 1.0);
        m_phase=params.get_float_arg(2, 0.0);
    }

    virtual float evaluate(float t) const override
    {
        return m_amplitude*sin(m_frequency*t - m_phase);
    }
};

#endif
