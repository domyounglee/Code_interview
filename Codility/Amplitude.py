
from collections import deque

def solution(A):
    
    #make deque
    dq = deque([])
    
    #sort A
    A.sort()
   
    #initial max_len
    max_len=0
    
    for e in A:
        
        if(len(dq)==0):
            dq.append(e)
            continue
    
        first = dq[0]
        
        if(first==e or first+1==e):
            dq.append(e)
        else:
            if(max_len<len(dq)):
                max_len=len(dq)
                
            while(len(dq)!=0 and dq[0]==first ):
                dq.popleft()
            
            if(len(dq)!=0 and dq[0]+1==e):
                dq.append(e)
            else:
                dq.clear()
                dq.append(e)
                
        #print(dq)
        
    if(max_len<len(dq)):
        max_len=len(dq)
        
    return max_len
"""
#Another solution which has both time and space complexity of O(n) 
from collections import defaultdict

def solution(A):
    dic = defaultdict(int)
    for e in A:
        dic[e]+=1
        dic[e+1]+=1
    if(len(dic.values())!=0):
        return max(dic.values())
    else:
        return 0
"""