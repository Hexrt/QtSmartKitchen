#include "YQData.h"


YQData::YQData()
{
}

YQData::YQData(double _temperature, double _humidty, double _boomgas, double _smog, bool _theft, bool _lightOn)
{
    setTemperature(_temperature);
    setHumidity(_humidty);
    setBoomgas(_boomgas);
    setSmog(_smog);
    setTheft(_theft);
    setLightOn(_lightOn);
}

YQData::~YQData()
{
}

double YQData::getTemperature() const
{
    return temperature;
}

void YQData::setTemperature(double temperature)
{
    this->temperature = temperature;
}

double YQData::getHumidity() const
{
    return humidity;
}

void YQData::setHumidity(double humidity)
{
    this->humidity = humidity;
}

double YQData::getBoomgas() const
{
    return boomgas;
}

void YQData::setBoomgas(double boomgas)
{
    this->boomgas = boomgas;
}

double YQData::getSmog() const
{
    return smog;
}

void YQData::setSmog(double smog)
{
    this->smog = smog;
}

bool YQData::getTheft() const
{
    return theft;
}

void YQData::setTheft(bool theft)
{
    this->theft = theft;
}

bool YQData::getLightOn() const
{
    return lightOn;
}

void YQData::setLightOn(bool lightOn)
{
    this->lightOn = lightOn;
}
