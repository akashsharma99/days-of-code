
def numConcat(num1,num2):
     # find number of digits in num2
     digits = len(str(num2))

     #add zeroes to the end of num1
     num1 = num1 * (10**digits)

     #add num2 to num1
     num1 += num2

     return num1


#input the two numbers
a = int(input())
b = int(input())
new_number = numConcat(a,b)

print(new_number)