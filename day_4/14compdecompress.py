#edit this comment line if you find any testcase which will fail for the below code.
from collections import deque
st=input("Enter a compressed string: ")
myStack=deque()
numstring=""
alphastring=""
for i in range(len(st)):
     ch=st[i]
     print(myStack)
     if ch.isdigit():
          numstring+=ch
          if alphastring!="":
               myStack.append(alphastring)
               alphastring=""
     elif ch=='[':
          myStack.append(numstring)
          numstring=""
     elif ch.isalpha():
          alphastring+=ch
     elif ch==']':
          top=myStack.pop()
          if top.isnumeric():
               check=""
               m=int(top)
               word=alphastring*m
               if len(myStack)>0:
                    check=myStack.pop()
                    if(check.isalpha()):
                         word=check+word
                    else:
                         myStack.append(check)
               myStack.append(word)
               alphastring=""
               
          else:
               m=int(myStack.pop())
               myStack.append((top+alphastring)*m)
               alphastring=""
solution=alphastring
while(len(myStack)>0):
     solution=myStack.pop()+solution
print("Decompressed : ",solution)

'''Your input is a compressed string of the format number[string] and the decompressed output form should be the string written number times. For example:

The input
3[abc]4[ab]c

Would be output as
abcabcabcababababc

Other rules
Number can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa

One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab

Characters allowed as input include digits, small English letters and brackets [ ].

Digits are only to represent amount of repetitions.

Letters are just letters.

Brackets are only part of syntax of writing repeated substring.

Input is always valid, so no need to check its validity.
input can be like 
2[3[f]b] output-> fffbfffb
2[b]akash2[sharma] output-> bbakashsharmasharma
2[3[ab]akash]sharma output-> abababakashabababakashsharma
2[a2[k]] output-> akkakk
'''