#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
  string str;
  deque<char> dq;

  cout << "Enter a string: ";
  cin >> str;

  // Insert characters into deque
  for (int i = 0; i < str.length(); i++)
  {
     dq.push_back(str[i]);
  }

  bool isPalindrome = true;

  // Compare characters from both ends
  while (dq.size() > 1)
  {
     char front = dq.front();
     char rear = dq.back();

       if (front != rear)
       {
          isPalindrome = false;
          break;
       }

        dq.pop_front();
        dq.pop_back();
    }

    if (isPalindrome)
    {
       cout << str << " is a Palindrome." << endl;
    }
    else
    {
       cout << str << " is NOT a Palindrome." << endl;
    }

    return 0;
}
