#include<bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

bool prime(int k)
{
    bool is_prime = true;

    // 0 and 1 are not prime numbers
    if (k == 0 || k == 1)
    {
        is_prime = false;
    }


    for (int i = 2; i <= sqrt(k); ++i)
    {
        if (k % i == 0)
        {
            is_prime = false;
            break;
        }
    }

    return is_prime;
}


int main()

{
    //fast;
    cout << "\t\t\t\t\t******* RSA project *******\n";

    //key genration
    long long p,q,i,n,m,e,d,j;
    string x;
    cout << "Enter your message : ";
    getline(cin, x);
    cout << endl;
    start:
    cout << "Enter two prime numbers : ";
    cin >> p >> q;

    if (prime(p) == 0 || prime(q) == 0 || p <= 5 || q <= 5)
    {
        cout << "you have entered wrong prime numbers please try again.\n";
        goto start;
    }

    n = p * q;
    m = (p - 1) * (q - 1);

    for (e = 2; e < m; e++)
    {
        for (i = e; i > 0; i--)
        {
            if (m % i == 0 && e % i == 0)
                break;
        }
        if (i == 1)
            break;
    }

    for (d = 2; d < m; d++)
    {
        if ((e * d) % m == 1)
        {
            break;
        }
    }

    char temp,text;
    long long cipher,ascii[9999],result;

    cout << "The cipher message is : ";

    //Encyption
    for (i = 0; i < x.size(); i++)
    {
        temp = x[i];
        result = (int)temp;
        cipher = 1;
        for (j = 0; j < e; j++)
        {
            cipher = (cipher * result) % n;
        }
        ascii[i] = cipher;
        text = (char)cipher;
        cout << text;

    }
    cout << endl;

    //decryption.

    cout << "the original message is : ";

    for (i = 0; i < x.size(); i++)
    {
        result = ascii[i];
        cipher = 1;
        for (int j = 1; j <= d; j++)
        {
            cipher = (cipher * result) % n;
        }

        text = (char)cipher;
        cout << text;
    }
    cout << endl;
    return 0;
}
