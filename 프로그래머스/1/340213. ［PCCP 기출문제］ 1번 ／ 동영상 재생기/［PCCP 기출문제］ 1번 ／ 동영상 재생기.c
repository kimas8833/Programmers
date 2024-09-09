#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.

int convert_to_seconds(const char* time_str)
{
    int minute, second;
    sscanf(time_str,"%d:%d", &minute, &second);
    return minute*60 + second;
}

char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int video_sec, pos_sec, op_start_sec, op_end_sec;
    video_sec = convert_to_seconds(video_len);
    pos_sec = convert_to_seconds(pos);
    op_start_sec = convert_to_seconds(op_start);
    op_end_sec = convert_to_seconds(op_end);
    
   
    
    for (size_t i = 0; i < commands_len; i++)
    {
        if(pos_sec>=op_start_sec && pos_sec<=op_end_sec)
            pos_sec = op_end_sec;
    
        if (strcmp(commands[i], "next") == 0)
        {
            pos_sec += 10;  // 10초 앞으로
        }
        else if (strcmp(commands[i], "prev") == 0)
        {
            pos_sec -= 10;  // 10초 뒤로
        }
        if(pos_sec>video_sec)
            pos_sec=video_sec;
        else if(pos_sec<0)
            pos_sec=0;
        
        if(pos_sec>=op_start_sec && pos_sec<=op_end_sec)
            pos_sec = op_end_sec;
    }
    
        
    char* answer = (char*)malloc(6);
    int minute = pos_sec/60;
    int second = pos_sec%60;
    sprintf(answer, "%02d:%02d", minute, second);
    
    return answer;
}