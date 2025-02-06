#include<bits/stdc++.h>

using namespace std;

//高精度的乘法，类似于竖式相乘
string multiple(string a,string b)
{
    int n = a.size();
    int m = b.size();
    vector<int> result(n+m,0);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = (a[i]-'0')*(b[j]-'0');//计算出最后一位相乘
            result[i+j] += sum;
            result[i+j+1] += result[i+j]/10;
            result[i+j] %= 10;
        }
    }
    while (result.size() > 1 && result.back() == 0)
    {
        result.pop_back();
    }
    string answer;
    for (int i = result.size() - 1; i >= 0; i--)
        answer += result[i] + '0';

    return answer;
}

string addLargeNumbers(string num1, string num2) {
    if (num1.length() < num2.length())
        swap(num1, num2);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string result = "";
    int carry = 0; // 进位

    for (size_t i = 0; i < num1.length(); ++i) {
        int digit1 = num1[i] - '0';  // 转换字符为整数
        int digit2 = (i < num2.length()) ? num2[i] - '0' : 0;  // num2可能较短，超出部分用0补齐

        int sum = digit1 + digit2 + carry;  // 当前位相加
        carry = sum / 10;  // 更新进位
        result += (sum % 10) + '0';  // 当前位的结果
    }

    // 如果最后还有进位
    if (carry) {
        result += carry + '0';
    }

    // 最后结果需要反转回来
    reverse(result.begin(), result.end());
    return result;
}

vector<string> result;

int main()
{
    string ans = "0";
    string n;
    cin>>n;
    int l = stol(n);//将n从字符串转化为整数类型
    for (int i = 1; i <= l; i++)
    {
        string mul = "1";
        for (int j = 2; j <= i; j++)
        {
            mul = multiple(mul,to_string(j));
        }
        ans = addLargeNumbers(ans,mul);
    }
    cout<<ans<<endl;
    return 0;
}