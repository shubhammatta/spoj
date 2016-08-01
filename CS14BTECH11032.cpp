#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
//class Myinteger
class MyInteger{
private:
	string value;
public:

	MyInteger(){
		value ="0";
	}
	MyInteger(int num,char s)
	{
		string init (num,48);
		value = init;
	}
	MyInteger(string S)
	{
		value = S;
	}
	string getValue()
	{
		return value;
	}
	int size()
	{
		return value.size();
	}
	//works perfectly
	MyInteger operator+(const MyInteger& X)
	{
		 // Two original strings of large integers
	    string str1 = this->value,
	           str2 = X.value;

	    // Zero-padd str1 and str2 to the same length
	    int n = max(str1.size(), str2.size());
	    if (n > str1.size())
	        str1 = string(n-str1.size(), '0') + str1;
	    if (n > str2.size())
	        str2 = string(n-str2.size(), '0') + str2;
	    string final(n+1, '0');

	    char carry = 0;

	    string::const_reverse_iterator it1 = str1.rbegin(), e = str1.rend(),
	                                   it2 = str2.rbegin();
	    string::reverse_iterator f = final.rbegin();
	    for (; it1 != e; ++it1, ++it2, ++f)
	    {
	        // Bracketing to avoid overflow
	        char tmp = (*it1-'0')+(*it2-'0') + carry;
	        if (tmp > 9)
	        {
	            carry = 1;
	            tmp -= 10;
	        }
	        else
	        {
	            carry = 0;
	        }
	        *f = tmp + '0';
	    }
	    final[0] = carry + '0';

	    // Remove leading zeros from result
	    n = final.find_first_not_of("0");
	    if (n != string::npos)
	    {
	        final = final.substr(n);
	    }
	    MyInteger fin(final);
	    //cout << "str1 = " << str1 << endl << "str2 = " << str2 << endl << "final = " << final << endl;
	    return fin;
 	}
 	//works perfectly
 	MyInteger operator*(const MyInteger& X)
 	{
 		string str1 = this->value,
	           str2 = X.value;
	           // cout << str1 <<  " " << str2 << endl;
	   // Zero-padd str1 and str2 to the same length
	    int n = str1.size() + str2.size();
	    // if (n > str1.size())
	    //     str1 = string(n-str1.size(), '0') + str1;
	    string final(n, '0');
	    MyInteger temp("0");
	    // The carry 
	    int  carry = 0;
	    // Iterators
	    string::const_reverse_iterator it1 = str1.rbegin(), e = str1.rend(),it2 = str2.rbegin(),e1 =e = str2.rend();
	    string::reverse_iterator f = final.rbegin();

	    int k=0;
	    // Conversion
	    for (k=0; it1 != e && k!=str1.size(); ++it1)
	    {   
	    	//string t(str1.size(),'0');
	    	string t(str2.size()+1,'0');
	    	string::reverse_iterator itemp = t.rbegin();
	    	//MyInteger here(t);
	        //Bracketing to avoid overflow
	        string::const_reverse_iterator it2 = str2.rbegin();
	    	carry = 0;
	    	while(it2!=e)
	    	{
	    		// cout << str1 << "str1 " <<  "str2 "<< str2 <<endl;
	    		// cout << *it1 << "  1  " << *it2 << " 2 " <<endl;
	    		int tmp = (*it1-'0')*(*it2-'0') + carry;
	    	    //cout << tmp << endl;
	    		if (tmp > 9)
		        {
		            carry = int(tmp/10);
		            tmp %= 10;
		        }
		        else
		        {
		            carry = 0;
		        }
		    	*itemp=(tmp+'0');
		    	++itemp;
		    	//cout << t << "  tmp" <<  int(carry) << " " <<endl;
		    	++it2;		
		    }
		    //cout << t << endl;
		    t[0] = carry + '0';
		    //t+= carry + '0';
		    //string c = carry+'0' + t;
		    //cout << t << "prett" <<endl;
		    t = t + string(k,'0');
		    // cout << t << "t"<<endl;
	        k++;
	        MyInteger X(t);
	        //cout << "pretep " << temp <<endl;
	        temp = temp + X;
	        // cout << temp << " temp" << endl;
	    }
	    //final[0] = carry + '0';
	    final = temp.value;
	    // Remove leading zeros from result
	    n = final.find_first_not_of("0");
	    if (n != string::npos)
	    {
	        final = final.substr(n);
	    }

	   // cout << "str1 = " << str1 << endl << "str2 = " << str2 << endl << "final = " << final << endl;
	    return final;
 	}
	friend ostream &operator<<( ostream &output, const MyInteger &D )
    {
        output << D.value;
        return output;            
    }
	
};


int main()
{
  int t;cin >> t;
  while(t--){
    string a, b;
    cin >> a >> b;
    MyInteger A(a);
    MyInteger B(b);
    cout << A*B << endl;
  }
	
	return 0;
}
// 2978757145184816692654114 
// 2978757145184594470431894
//