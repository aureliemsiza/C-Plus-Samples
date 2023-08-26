#include <iostream>
#include <ctime>

enum class WeatherType { Sunny, Cloudy, Rainy, Stormy };

class WeatherSystem {
public:
    WeatherSystem() : currentWeather(WeatherType::Sunny) {}

    void UpdateWeather() {
        // Simulate weather change over time based on game logic
        // For simplicity, let's just randomly change the weather here
        if (std::time(nullptr) % 120 == 0) { // Change every 2 minutes
            int randomWeather = rand() % static_cast<int>(WeatherType::Stormy) + 1;
            currentWeather = static_cast<WeatherType>(randomWeather);
        }
    }

    WeatherType GetCurrentWeather() const {
        return currentWeather;
    }

private:
    WeatherType currentWeather;
};

int main() {
    WeatherSystem weatherSystem;

    while (true) {
        weatherSystem.UpdateWeather();
        WeatherType currentWeather = weatherSystem.GetCurrentWeather();

        // Use the current weather for gameplay or visual effects
        // ...
        
        // Simulate time passing
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}
