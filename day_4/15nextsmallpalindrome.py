#code isnt working for some testcase by geeksforgeeks problem name next smallest palindrome. the input array is of size 808 try to solve in java
T=int(input())
while T!=0:
    T-=1
    N=int(input())
    left=""
    right=""
    mid=""
    k=0
    x=[x for x in input().split()]
    #print(x)
    if(N%2==0):
        leftsize=N//2-1
        rightsize=leftsize
        for i in range(leftsize):
            left+=x[k]
            k+=1
        mid+=x[k]
        k+=1
        mid+=x[k]
        k+=1
        for i in range(rightsize):
            right+=x[k]
            k+=1
        if(mid!="99"):
            r=left[::-1]
            if right>r:
                mid=""+str(int(mid)+11)
                right=r
            else:
                right=r
        else:
            if right<(left[::-1]):
                right=left[::-1]
            else:
                mid="00"
                half=left[:leftsize-4]
                half2=left[leftsize-4:]
                lala=half+str(int(half2)+1)
                left=""+lala
                right=left[::-1]
    else:
        leftsize=N//2
        rightsize=leftsize
        for i in range(leftsize):
            left+=x[k]
            k+=1
        mid+=x[k]
        k+=1
        for i in range(rightsize):
            right+=x[k]
            k+=1
        if(mid!="9"):
            r=left[::-1]
            # print(r)
            # print(right)
            if right>r:
                mid=""+str(int(mid)+1)
                right=r
            else:
                right=r
        else:
            if right<(left[::-1]):
                right=left[::-1]
            else:
                mid="0"
                half=left[:leftsize-4]
                half2=left[leftsize-4:]
                lala=half+str(int(half2)+1)
                left=""+lala
                #left=""+str(int(left)+1)
                right=left[::-1]
    for ch in left:
        print(ch,end=" ")
    for ch in mid:
        print(ch,end=" ")
    for ch in right:
        print(ch,end=" ")

"""Given a number, in the form of an array a[] containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome larger than this number.

Input :
The first line is number of test cases T. Every testcase contains two lines. The first line contains the size of the array, second line contains the digits of the number separated by space.

Output:
In each separate line print the digits of palindrome with spaces in between.

Constraints:
1<=T<=100
1<=n<=1000
1<=a[i]<=9

Example:
Input:
1
11
9 4 1 8 7 9 7 8 3 2 2

Output:
9 4 1 8 8 0 8 8 1 4 9"""