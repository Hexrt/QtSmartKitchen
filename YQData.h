#pragma once
/*
ʵʱ����
*/
class YQData
{

public:
    YQData();
    YQData(double _temperature, double _humidty, double _boomgas, double _smog, bool _theft, bool _lightOn);
    ~YQData();
public:
    double getTemperature() const;
    void setTemperature(double temperature);

    double getHumidity() const;
    void setHumidity(double humidity);

    double getBoomgas() const;
    void setBoomgas(double boomgas);

    double getSmog() const;
    void setSmog(double smog);

    bool getTheft() const;
    void setTheft(bool theft);

    bool getLightOn() const;
    void setLightOn(bool lightOn);

private:
    //�¶�
    double temperature;
    //ʪ��
    double humidity;
    //��ȼ����
    double boomgas;
    //����
    double smog;
    //����
    bool   theft;
    //����
    bool   lightOn;

};

