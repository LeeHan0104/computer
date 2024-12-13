/* [주석1
: oo의 미래. 미래의 oo을 주제로 날씨 데이터 분석 프로그램을 만들었습니다. 
과거의 온도, 강수량 데이터를 기반으로 간단한 예측을 할 수 있습니다. 
이러한 예측은 미래의 날씨를 예측하는 데 도움이 될 것입니다.
총 4개의 파일을 통해 프로그램을 만들었으며, 입력한 강수량과 온도 데이터는 파일에 저장되도록 하였습니다.]

컴퓨터 프로그래밍 및 실습 평가과제(배점 25점)
학과: 전자공학과
학번: 202204243
이름: 이한
과제 주제: 미래에 도움이 되는 날씨 데이터 분석 프로그램
*/



#include <iostream>
#include <memory> //주석: 객체 포인터를 사용하기 위해 포함
#include "WeatherData.h"
#include "TemperatureData.h"
#include "RainfallData.h"

int main() {
    try {
        // 객체 생성
        std::unique_ptr<WeatherData> temperatureData = std::make_unique<TemperatureData>(); //주석: 객체 포인터로 멤버 접근
        std::unique_ptr<WeatherData> rainfallData = std::make_unique<RainfallData>(); //주석: 다형성을 활용하여 객체 관리

        // 데이터 입력
        temperatureData->inputData(); //주석: 다형성을 통해 TemperatureData의 함수 호출
        rainfallData->inputData();

        // 데이터 출력
        std::cout << "\n온도 데이터 출력\n";
        temperatureData->displayData();

        std::cout << "\n강수량 데이터 출력\n";
        rainfallData->displayData();

        // 예측 계산
        std::cout << "\n온도 예측 계산\n";
        temperatureData->calculatePrediction();

        std::cout << "\n강수량 예측 계산\n";
        rainfallData->calculatePrediction();

        // 파일 저장
        temperatureData->saveToFile("temperature_data.txt"); //주석: 파일 출력 처리
        rainfallData->saveToFile("rainfall_data.txt");
        std::cout << "\n데이터가 파일에 저장되었습니다.\n";

        // 파일에서 데이터 읽기
        TemperatureData tempFromFile;
        tempFromFile.readFromFile("temperature_data.txt"); //주석: 파일 입력 처리
        std::cout << "\n파일에서 읽은 온도 데이터\n";
        tempFromFile.displayData();
        tempFromFile.calculatePrediction();

        RainfallData rainfallFromFile;
        rainfallFromFile.readFromFile("rainfall_data.txt");
        std::cout << "\n파일에서 읽은 강수량 데이터\n";
        rainfallFromFile.displayData();
        rainfallFromFile.calculatePrediction();

    } catch (const std::exception& e) { //주석: 예외 처리
        std::cerr << "오류 발생: " << e.what() << std::endl;
    }

    return 0;
}
