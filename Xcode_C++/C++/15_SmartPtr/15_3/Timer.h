//
//  Timer.h
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#ifndef Timer_h
#define Timer_h
#include <chrono>

class Timer {
public:
    // 생성자 (Constructor)
    // - 객체가 생성되는 시점의 시간을 기록한다.
    Timer()
    : start_time(std::chrono::high_resolution_clock::now())
    { }
    
    // elapsed() 함수:
    // - 생성 이후 경과한 시간을 초 단위(double)로 반환한다.
    // - const 멤버 함수로 선언되어 있으며, 객체 상태를 변경하지 않는다.
    double elapsed() const {
        // 현재 시간을 측정한다.
        auto end_time = std::chrono::high_resolution_clock::now();
        // 시작 시간과 현재 시간의 차이를 duration<double> 형식으로 계산한다.
        std::chrono::duration<double> diff = end_time - start_time;
        return diff.count();  // 경과 시간을 초 단위(double 값)로 반환
    }
    
    // reset() 함수 (선택사항)
    // - 타이머의 시작 시간을 현재 시각으로 재설정한다.
    void reset() {
        start_time = std::chrono::high_resolution_clock::now();
    }
    
private:
    // start_time: Timer 객체 생성 시 기록된 시작 시각
    std::chrono::high_resolution_clock::time_point start_time;
};

#endif /* Timer_h */
