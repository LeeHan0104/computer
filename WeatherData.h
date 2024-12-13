#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdexcept>

// WeatherData 클래스: 날씨 데이터의 기본 추상 클래스
class WeatherData {
public:
    virtual ~WeatherData() {}

    // 데이터 입력 함수
    virtual void inputData() = 0; //주석: 추상 클래스에서 정의한 순수 가상 함수

    // 데이터 출력 함수
    virtual void displayData() const = 0; //주석: 다형성을 통해 각 클래서에서 구현

    // 예측 계산 함수
    virtual void calculatePrediction() const = 0; //주석: 상속받은 클래스에서 오버라이딩

    // 데이터 파일 읽기 (파일 입력 기능)
    virtual void readFromFile(const std::string& filename) = 0; //주석: 파일 입력 처리

    // 데이터 파일에 저장 (파일 출력 기능)
    virtual void saveToFile(const std::string& filename) const = 0; //주석: 파일 출력 처리

    // 객체 생성 (다형성 구현)
    static WeatherData* createData(const std::string& type); //주석: 다형성을 지원하는 함수
};

#endif
