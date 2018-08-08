#수학을 공부하던 민지는 재미있는 사실을 발견하였습니다. 그 사실은 바로 연속된 자연수의 합으로 어떤 숫자를 표현하는 방법이 여러 가지라는 것입니다. 예를 들어, 15를 표현하는 방법은 (1+2+3+4+5) (4+5+6) (7+8) (15) 로 총 4가지가 존재합니다. 숫자를 입력받아 연속된 수로 표현하는 방법을 반환하는 expressions 함수를 만들어 민지를 도와주세요. 예를 들어 15가 입력된다면 4를 반환해 주면 됩니다.


from queue import Queue


def expression(N):
	count =0 
	q = Queue(N//2+1)

	num = 1
	sum_ = 0

	#처음 연속합이 sum_  이하되게 설정하고 시작한다. 
	while(sum_ < N):
		
		sum_+=num
		q.put(num)
		num+=1

	
	#queue를  이동시킨다. N//2+2 이상 갈필요없다. 
	while(num<= N//2+2):
		#N이면 count 추가
		if sum_ == N:
			count+=1
			#print("count",num-1)
			

		#하나 추가하고 
		q.put(num)
		sum_ +=num


		#하나씩 비워내기 : sum 이 N 보다 작아질때까지 get 한다. 
		while(sum_ >N ):

			a = q.get()
			sum_ -= a
			#print("popit",a)
	
	
		num+=1

	return count


print(expression(1500000))


