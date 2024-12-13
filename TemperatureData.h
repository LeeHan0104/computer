#ifndef TEMPERATUREDATA_H
#define TEMPERATUREDATA_H

// WeatherData 추상 클래스를 상속받기 위해 포함
#include "WeatherData.h"
// 파일 입출력을 위한 헤더 포함
#include <fstream>
// 온도 데이터를 저장할 벡터 사용을 위한 헤더 포함
#include <vector>

// TemperatureData 클래스 정의: WeatherData를 상속받아 온도 데이터를 처리
class TemperatureData : public WeatherData {
protected:
//주석: 객체 배열로 데이터 저장
    std::vector<int> temperatures; // 온도 데이터를 저장하는 벡터 

public:
    // 소멸자: 기본 동작을 사용
    virtual ~TemperatureData() {}

    // 사용자로부터 7일치 온도 데이터를 입력받는 함수
    void inputData() override {
        int temp; // 온도 데이터를 임시 저장할 변수
        std::cout << "주간 온도 데이터를 입력하세요 (7일치): ";
        for (int i = 0; i < 7; ++i) {
            std::cin >> temp; // 사용자로부터 온도 입력
            temperatures.push_back(temp); // 벡터에 온도 추가
        }
    }

    // 저장된 온도 데이터를 화면에 출력하는 함수
    void displayData() const override {
        std::cout << "입력된 온도 데이터: ";
        for (int temp : temperatures) {
            std::cout << temp << " "; // 벡터의 각 값을 출력
        }
        std::cout << std::endl; // 출력 완료 후 줄바꿈
    }

    // 저장된 온도 데이터의 평균을 계산하여 출력하는 함수
    void calculatePrediction() const override {
        int sum = 0; // 온도의 합계를 저장할 변수
        for (int temp : temperatures) {
            sum += temp; // 벡터의 각 값을 합산
        }
        // 평균값을 계산하여 출력
        std::cout << "예상 평균 온도: " << sum / temperatures.size() << "도" << std::endl;
    }

    // 파일에서 온도 데이터를 읽어오는 함수
    void readFromFile(const std::string& filename) override {
        std::ifstream inFile(filename); // 입력 파일 스트림 생성
        int temp;
        // 파일 끝까지 온도 데이터를 읽어 벡터에 추가
        while (inFile >> temp) {
            temperatures.push_back(temp);
        }
    }

    // 온도 데이터를 파일에 저장하는 함수
    void saveToFile(const std::string& filename) const override {
        std::ofstream outFile(filename); // 출력 파일 스트림 생성
        // 벡터의 모든 값을 파일에 저장
        for (int temp : temperatures) {
            outFile << temp << std::endl;
        }
    }
};

#endif
