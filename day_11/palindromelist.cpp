/*
https://practice.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1
Given a linked list of strings having n nodes check to see whether the combined string formed is palindrome or not. 

Input:
You have to complete the method which takes one argument: the head of the linked list . You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return True if the combined string is pallindrome else it should return False.

User Task:
The task is to complete the function compute() which returns true or false.

Constraints:
1 <=T<= 103
1 <=n<= 103

Example:
Input :
2
5
a bc d dcb a
4
a bc d ba

Output :
True
False

Explanation:
case 1 : as String "abcddcba" is palindrome the function should return true
case 2 : as String "abcdba" is not palindrome the function should return false
*/
bool compute(Node* root)
{
   Node* temp=root;
   string st;
   while(temp!=NULL){
       st=st+temp->data;
       temp=temp->next;
   }
   for(int i=0,j=st.length()-1;i<j;i++,j--){
       if(st[i]!=st[j]){
           return false;
       }
   }
   return true;
}