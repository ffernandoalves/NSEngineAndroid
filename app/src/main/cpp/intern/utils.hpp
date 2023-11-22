//
// Created by ffernandoalves on 22/11/2023.
//

#ifndef NSENGINE_UTILS_HPP
#define NSENGINE_UTILS_HPP

#include <ctime>
#include <chrono>


namespace NSEngine {
    namespace Utils {
        class Clock {
        private:
            std::string timezone;
            std::time_t real_data;
            std::time_t start_clock_real_time;
        public:
            Clock() = default;
            ~Clock() = default;

            void setTimeZone(const std::string& tz) {
                timezone = tz;
            }

            const std::string& getTimeZone() const {
                return timezone;
            }

            std::time_t getStartRealTime() const {
                return start_clock_real_time;
            }

            std::time_t getStartDate() const {
                return real_data;
            }

            void setClock() {
                timespec real_t;
                clock_gettime(CLOCK_MONOTONIC, &real_t);
                start_clock_real_time = real_t.tv_sec;
                real_data = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            }

            double getEngineCurrentTime() const {
                timespec clockRealTime;
                clock_gettime(CLOCK_MONOTONIC, &clockRealTime);
                double curTimeInSeconds = static_cast<double>(clockRealTime.tv_sec - start_clock_real_time) + (static_cast<double>(clockRealTime.tv_nsec)/1e9);
                return curTimeInSeconds;
            }
        };
    }
}

#endif //NSENGINE_UTILS_HPP
