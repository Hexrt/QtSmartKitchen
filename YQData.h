#pragma once
/*
实时数据
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
    //温度
    double temperature;
    //湿度
    double humidity;
    //可燃气体
    double boomgas;
    //烟雾
    double smog;
    //有贼
    bool   theft;
    //开灯
    bool   lightOn;

};

