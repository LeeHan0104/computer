#ifndef RAINFALLDATA_H
#define RAINFALLDATA_H

// WeatherData 추상 클래스를 상속받기 위해 포함
#include "WeatherData.h"
// 파일 입출력을 위한 헤더 포함
#include <fstream>
// 강수량 데이터를 저장할 벡터 사용을 위한 헤더 포함
#include <vector>

// RainfallData 클래스 정의: WeatherData를 상속받아 강수량 데이터를 처리
class RainfallData : public WeatherData {
protected:
//주석: 강수량 데이터를 저장하는 객체 배열
    std::vector<int> rainfallAmounts; // 강수량 데이터를 저장하는 벡터

public:
    // 소멸자: 기본 동작을 사용
    virtual ~RainfallData() {}

    // 사용자로부터 7일치 강수량 데이터를 입력받는 함수
    void inputData() override {
        int rainfall; // 강수량 데이터를 임시 저장할 변수
        std::cout << "주간 강수량 데이터를 입력하세요 (7일치): ";
        for (int i = 0; i < 7; ++i) {
            std::cin >> rainfall; // 사용자로부터 강수량 입력
            rainfallAmounts.push_back(rainfall); // 벡터에 강수량 추가
        }
    }

    // 저장된 강수량 데이터를 화면에 출력하는 함수
    void displayData() const override {
        std::cout << "입력된 강수량 데이터: ";
        for (int rainfall : rainfallAmounts) {
            std::cout << rainfall << " "; // 벡터의 각 값을 출력
        }
        std::cout << std::endl; // 출력 완료 후 줄바꿈
    }

    // 저장된 강수량 데이터의 평균을 계산하여 출력하는 함수
    void calculatePrediction() const override {
        int sum = 0; // 강수량의 합계를 저장할 변수
        for (int rainfall : rainfallAmounts) {
            sum += rainfall; // 벡터의 각 값을 합산
        }
        // 평균값을 계산하여 출력
        std::cout << "예상 평균 강수량: " << sum / rainfallAmounts.size() << "mm" << std::endl;
    }

    // 파일에서 강수량 데이터를 읽어오는 함수
    void readFromFile(const std::string& filename) override {
        std::ifstream inFile(filename); // 입력 파일 스트림 생성
        int rainfall;
        // 파일 끝까지 강수량 데이터를 읽어 벡터에 추가
        while (inFile >> rainfall) {
            rainfallAmounts.push_back(rainfall);
        }
    }

    // 강수량 데이터를 파일에 저장하는 함수
    void saveToFile(const std::string& filename) const override {
        std::ofstream outFile(filename); // 출력 파일 스트림 생성
        // 벡터의 모든 값을 파일에 저장
        for (int rainfall : rainfallAmounts) {
            outFile << rainfall << std::endl;
        }
    }
};

#endif
