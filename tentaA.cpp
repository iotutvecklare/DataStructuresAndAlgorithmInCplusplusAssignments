#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class SensorType
{
    Altitude,
    SpeedInKmh,
    FuelConsumption
};

class SensorData
{
    float value;
    SensorType sensorType;
    time_t time;

public:
    SensorType GetSensorType() { return sensorType; }
    float GetValue() { return value; }
    void SetValue(float v) { value = v; } // Added setter for value
    time_t GetTime() { return time; }
    SensorData(SensorType sensorType, float value, time_t time)
    {
        this->value = value;
        this->sensorType = sensorType;
        this->time = time;
    }
};

void FillData(vector<SensorData> &v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);

int main()
{
    vector<SensorData> sensorData;
    FillData(sensorData);



/*

    //Skriv kod som räknar hur många sensordataregistreringar som gjorts för Altitude - den 2012-01-02.
    // Using std::count_if to count the number of registrations for Altitude on 2012-01-02
    time_t specificTime = CreateTime(2012, 1, 2, 0, 0, 0);
    int findAltitude = count_if(sensorData.begin(), sensorData.end(), [specificTime](SensorData &data) {

        // Get the time
        time_t timestamp = data.GetTime();
        struct tm *timeinfo = localtime(&timestamp);

        // Print the time separately
        std::cout << "Year: " << 1900 + timeinfo->tm_year << std::endl;
        std::cout << "Month: " << 1 + timeinfo->tm_mon << std::endl;
        std::cout << "Day: " << timeinfo->tm_mday << std::endl;
        std::cout << "Hour: " << timeinfo->tm_hour << std::endl;
        std::cout << "Minute: " << timeinfo->tm_min << std::endl;
        std::cout << "Second: " << timeinfo->tm_sec << std::endl;

        return (data.GetSensorType() == SensorType::Altitude && data.GetTime() >= specificTime && data.GetTime() <= specificTime + 24 * 3600);
    });
    cout << "Number of sensor data registrations for Altitude on 2012-01-02: " << findAltitude << endl;*/


    //Skriv kod som räknar hur många sensordataregistreringar som gjorts för Altitude - den 2012-01-02.
    // Using std::count_if to count the number of registrations for Altitude on 2012-01-02
    time_t specificTime = CreateTime(2012, 1, 2, 0, 0, 0);
    int findAltitude = count_if(sensorData.begin(), sensorData.end(), [specificTime](SensorData &data) {

        // By using data.GetTime() >= specificTime && data.GetTime() < specificTime + 24 * 3600,
        // we're effectively checking for all timestamps that fall within the entire day of "2012-01-02".
        // This ensures that we capture all sensor data recorded throughout the day, not just a single timestamp.
        return (data.GetSensorType() == SensorType::Altitude && data.GetTime() >= specificTime && data.GetTime() < specificTime + 24 * 3600);
    });
    cout << "Number of sensor data registrations for Altitude on 2012-01-02: " << findAltitude << endl;


/*    //Finns det nån SpeedInKmh-registrering med hastighet över 99.9 så skriv till consolen "Maxhastighet uppnådd"
    //- annars skriv "Ingen maxhastighet uppnådd"
    // Check if there is any SpeedInKmh registration with a speed over 99.9
    bool maxSpeedReached = any_of(sensorData.begin(), sensorData.end(), [](SensorData data) {
        return (data.GetSensorType() == SensorType::SpeedInKmh && data.GetValue() > 99.9);
    });
    std::cout << "Is there is any SpeedInKmh registration with a speed over 99.9 ? " << (maxSpeedReached ? "Yes" : "No") << std::endl;*/


/*
    //Det har uppdagats att fabriken mixrat med FuelConsumption-sensorn.
    //Skriv kod som uppdaterar alla såna poster så att FuelConsumption ökas med 75%.
    // Update all entries where the SensorType is FuelConsumption using 'for loop'
    for (SensorData &data : sensorData)
    {
        if (data.GetSensorType() == SensorType::FuelConsumption)
        {
            float oldValue = data.GetValue();
            float newValue = oldValue * 1.75; // Increase the value by 75%
            data.SetValue(newValue);
        }
    }

    // Printing the updated values for demonstration purposes
    cout << "Updated FuelConsumption values:" << endl;
    for (SensorData data : sensorData)
    {
        if (data.GetSensorType() == SensorType::FuelConsumption)
        {
            cout << "Value: " << data.GetValue() << endl;
        }
    }
*/

/*
    //Det har uppdagats att fabriken mixrat med FuelConsumption-sensorn.
    //Skriv kod som uppdaterar alla såna poster så att FuelConsumption ökas med 75%.
    // Update all entries where the SensorType is FuelConsumption using std::transform <algorithm>
    std::transform(sensorData.begin(), sensorData.end(), sensorData.begin(), [](SensorData &data) {
        if (data.GetSensorType() == SensorType::FuelConsumption) {
            float oldValue = data.GetValue();
            float increaseValue = oldValue * 0.75; // Increase the value by 75%
            float newValue = oldValue +  increaseValue;
            data.SetValue(newValue);
        }
        return data;
    });

    // Sort the updated values in ascending order
    std::sort(sensorData.begin(), sensorData.end(), [](SensorData &a, SensorData &b) {
        return a.GetValue() < b.GetValue();
    });

    // Printing the updated values with a maximum limit
    const int maxValuesToPrint = 20; // Maximum number of values to print
    cout << "Updated FuelConsumption values (ascending order):" << endl;
    int count = 0;
    for (SensorData data : sensorData)
    {
        if (data.GetSensorType() == SensorType::FuelConsumption)
        {
            cout << "Value: " << data.GetValue() << endl;
            count++;
            if (count >= maxValuesToPrint)
                break;
        }
    }*/


/*
// Create a new vector to store updated values
    vector<SensorData> updatedSensorData;

// Update all entries where the SensorType is FuelConsumption using std::transform
    std::transform(sensorData.begin(), sensorData.end(), std::back_inserter(updatedSensorData), [](SensorData &data) {
        if (data.GetSensorType() == SensorType::FuelConsumption) {
            float oldValue = data.GetValue();
            float newValue = oldValue * 0.75; // Increase the value by 75%
            data.SetValue(newValue);
        }
        return data;
    });

// Printing the updated values for demonstration purposes
    cout << "Updated FuelConsumption values:" << endl;
    for (SensorData data : updatedSensorData) {
        if (data.GetSensorType() == SensorType::FuelConsumption) {
            cout << "Value: " << data.GetValue() << endl;
        }
    }
*/

    return 0;
}

void FillData(vector<SensorData> &v)
{
    srand(time(NULL));

    time_t tid = CreateTime(2012, 1, 1, 1, 1, 1);
    for (int i = 0; i < 100000; i++)
    {
        SensorType type = static_cast<SensorType>(rand() % 3);
        float value = 0.0f;
        if (type == SensorType::Altitude)
            value = rand() % 1000;
        else if (type == SensorType::FuelConsumption)
            value = rand() * 3.0f;
        else if (type == SensorType::SpeedInKmh)
            value = rand() % 110;
        else
        {
            value = 99;
        }
        v.push_back(SensorData(type, value, tid));
        tid = tid + rand() % 10 + 1;
    }
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second)
{
    struct tm tid = {0};
    tid.tm_year = year - 1900;
    tid.tm_mon = month - 1;
    tid.tm_mday = day;
    tid.tm_hour = hour;
    tid.tm_min = minute;
    tid.tm_sec = second;
    return mktime(&tid);
}
