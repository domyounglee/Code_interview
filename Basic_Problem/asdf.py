def expressions(num):
    answer = 1
    for i in range(1,num//2+1):
        test_sum = i
        for j in range(i+1, num//2+2):
            test_sum += j
            if test_sum > num:
                continue
            if test_sum == num:
                answer += 1

    return answer


# 아래는 테스트로 출력해 보기 위한 코드입니다.
print(expressions(1500000));